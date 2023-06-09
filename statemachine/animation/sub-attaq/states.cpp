// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

//Own
#include "states.h"
#include "graphicsscene.h"
#include "boat.h"
#include "submarine.h"
#include "torpedo.h"
#include "animationmanager.h"
#include "progressitem.h"
#include "textinformationitem.h"

//Qt
#include <QFinalState>
#include <QGraphicsView>
#include <QKeyEventTransition>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QStateMachine>

PlayState::PlayState(GraphicsScene *scene, QState *parent)
    : QState(parent), scene(scene), machine(nullptr),
      currentLevel(0), score(0)
{
}

PlayState::~PlayState()
{
    delete machine;
}

void PlayState::onEntry(QEvent *)
{
    //We are now playing?
    if (machine) {
        machine->stop();
        //we hide the information
        scene->textInformationItem->hide();
        scene->clearScene();
        currentLevel = 0;
        score = 0;
        delete machine;
    }

//![4]
    machine = new QStateMachine;

    //This state is active when the player is playing
    LevelState *levelState = new LevelState(scene, this, machine);

    //This state is active when the player is actually playing but the game is not paused
    QState *playingState = new QState(levelState);
    levelState->setInitialState(playingState);

    //This state is active when the game is paused
    PauseState *pauseState = new PauseState(scene, levelState);

    //We have one view, it receives the key press events
    QKeyEventTransition *pressPplay = new QKeyEventTransition(scene->views().at(0), QEvent::KeyPress, Qt::Key_P);
    pressPplay->setTargetState(pauseState);
    QKeyEventTransition *pressPpause = new QKeyEventTransition(scene->views().at(0), QEvent::KeyPress, Qt::Key_P);
    pressPpause->setTargetState(playingState);

    //Pause "P" is triggered, when the player pauses the game
    playingState->addTransition(pressPplay);

    //To get back to playing when the game has been paused
    pauseState->addTransition(pressPpause);

    //This state is active when player has lost
    LostState *lostState = new LostState(scene, this, machine);

    //This state is active when player has won
    WinState *winState = new WinState(scene, this, machine);

    //If boat has been destroyed then the game is finished
    levelState->addTransition(scene->boat, &Boat::boatExecutionFinished,lostState);

    //This transition checks if we have won or not
    WinTransition *winTransition = new WinTransition(scene, this, winState);

    //If boat has been destroyed then the game is finished
    levelState->addTransition(winTransition);

    //This state is for an animation when the score changes
    UpdateScoreState *scoreState = new UpdateScoreState(levelState);

    //This transition updates the score when a submarine is destroyed
    UpdateScoreTransition *scoreTransition = new UpdateScoreTransition(scene, this, levelState);
    scoreTransition->setTargetState(scoreState);

    //If the boat has been destroyed then the game is finished
    playingState->addTransition(scoreTransition);

    //We go back to play state
    scoreState->addTransition(playingState);

    //We start playing!!!
    machine->setInitialState(levelState);

    //Final state
    QFinalState *finalState = new QFinalState(machine);

    //This transition is triggered when the player presses space after completing a level
    CustomSpaceTransition *spaceTransition = new CustomSpaceTransition(scene->views().at(0), this, QEvent::KeyPress, Qt::Key_Space);
    spaceTransition->setTargetState(levelState);
    winState->addTransition(spaceTransition);

    //We lost so we should reach the final state
    lostState->addTransition(lostState, &QState::finished, finalState);

    scene->textInformationItem->hide();
    machine->start();
//![4]

}

LevelState::LevelState(GraphicsScene *scene, PlayState *game, QState *parent) : QState(parent), scene(scene), game(game)
{
}
void LevelState::onEntry(QEvent *)
{
    initializeLevel();
}

//![5]
void LevelState::initializeLevel()
{
    //we re-init the boat
    scene->boat->setPos(scene->width()/2, scene->sealLevel() - scene->boat->size().height());
    scene->boat->setCurrentSpeed(0);
    scene->boat->setCurrentDirection(Boat::None);
    scene->boat->setBombsLaunched(0);
    scene->boat->show();
    scene->setFocusItem(scene->boat, Qt::OtherFocusReason);
    scene->boat->run();

    scene->progressItem->setScore(game->score);
    scene->progressItem->setLevel(game->currentLevel + 1);

    const GraphicsScene::LevelDescription currentLevelDescription = scene->levelsData.value(game->currentLevel);
    for (const QPair<int,int> &subContent : currentLevelDescription.submarines) {

        GraphicsScene::SubmarineDescription submarineDesc = scene->submarinesData.at(subContent.first);

        for (int j = 0; j < subContent.second; ++j ) {
            SubMarine *sub = new SubMarine(submarineDesc.type, submarineDesc.name, submarineDesc.points);
            scene->addItem(sub);
            int random = QRandomGenerator::global()->bounded(15) + 1;
            qreal x = random == 13 || random == 5 ? 0 : scene->width() - sub->size().width();
            qreal y = scene->height() -(QRandomGenerator::global()->bounded(150) + 1) - sub->size().height();
            sub->setPos(x,y);
            sub->setCurrentDirection(x == 0 ? SubMarine::Right : SubMarine::Left);
            sub->setCurrentSpeed(QRandomGenerator::global()->bounded(3) + 1);
        }
    }
}
//![5]

/** Pause State */
PauseState::PauseState(GraphicsScene *scene, QState *parent) : QState(parent), scene(scene)
{
}

void PauseState::onEntry(QEvent *)
{
    AnimationManager::self()->pauseAll();
    scene->boat->setEnabled(false);
}
void PauseState::onExit(QEvent *)
{
    AnimationManager::self()->resumeAll();
    scene->boat->setEnabled(true);
    scene->boat->setFocus();
}

/** Lost State */
LostState::LostState(GraphicsScene *scene, PlayState *game, QState *parent) : QState(parent), scene(scene), game(game)
{
}

void LostState::onEntry(QEvent *)
{
    //The message to display
    QString message = QString("You lost on level %1. Your score is %2.").arg(game->currentLevel+1).arg(game->score);

    //We set the level back to 0
    game->currentLevel = 0;

    //We set the score back to 0
    game->score = 0;

    //We clear the scene
    scene->clearScene();

    //We inform the player
    scene->textInformationItem->setMessage(message);
    scene->textInformationItem->show();
}

void LostState::onExit(QEvent *)
{
    //we hide the information
    scene->textInformationItem->hide();
}

/** Win State */
WinState::WinState(GraphicsScene *scene, PlayState *game, QState *parent) : QState(parent), scene(scene), game(game)
{
}

void WinState::onEntry(QEvent *)
{
    //We clear the scene
    scene->clearScene();

    QString message;
    if (scene->levelsData.size() - 1 != game->currentLevel) {
        message = QString("You won level %1. Your score is %2.\nPress Space to continue.").arg(game->currentLevel+1).arg(game->score);
        //We increment the level number
        game->currentLevel++;
    } else {
        message = QString("You finished the game on level %1. Your score is %2.").arg(game->currentLevel+1).arg(game->score);
        //We set the level back to 0
        game->currentLevel = 0;
        //We set the score back to 0
        game->score = 0;
    }

    //We inform the player
    scene->textInformationItem->setMessage(message);
    scene->textInformationItem->show();
}

void WinState::onExit(QEvent *)
{
    //we hide the information
    scene->textInformationItem->hide();
}

/** UpdateScore State */
UpdateScoreState::UpdateScoreState(QState *parent) : QState(parent)
{
}

/** Win transition */
UpdateScoreTransition::UpdateScoreTransition(GraphicsScene *scene, PlayState *game, QAbstractState *target)
    : QSignalTransition(scene, &GraphicsScene::subMarineDestroyed),
      game(game), scene(scene)
{
    setTargetState(target);
}

bool UpdateScoreTransition::eventTest(QEvent *event)
{
    if (!QSignalTransition::eventTest(event))
        return false;
    QStateMachine::SignalEvent *se = static_cast<QStateMachine::SignalEvent*>(event);
    game->score += se->arguments().at(0).toInt();
    scene->progressItem->setScore(game->score);
    return true;
}

/** Win transition */
WinTransition::WinTransition(GraphicsScene *scene, PlayState *game, QAbstractState *target)
    : QSignalTransition(scene, &GraphicsScene::allSubMarineDestroyed),
      game(game), scene(scene)
{
    setTargetState(target);
}

bool WinTransition::eventTest(QEvent *event)
{
    if (!QSignalTransition::eventTest(event))
        return false;
    QStateMachine::SignalEvent *se = static_cast<QStateMachine::SignalEvent*>(event);
    game->score += se->arguments().at(0).toInt();
    scene->progressItem->setScore(game->score);
    return true;
}

/** Space transition */
CustomSpaceTransition::CustomSpaceTransition(QWidget *widget, PlayState *game, QEvent::Type type, int key)
    : QKeyEventTransition(widget, type, key), game(game)
{
}

bool CustomSpaceTransition::eventTest(QEvent *event)
{
    if (!QKeyEventTransition::eventTest(event))
        return false;
    return (game->currentLevel != 0);
}
