// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include "stickman.h"
#include "node.h"

#include <QPainter>
#include <QtMath>

static constexpr qreal Coords[NodeCount * 2] = {
    0.0, -150.0, // head, #0

    0.0, -100.0, // body pentagon, top->bottom, left->right, #1 - 5
    -50.0, -50.0,
    50.0, -50.0,
    -25.0, 50.0,
    25.0, 50.0,

    -100.0, 0.0, // right arm, #6 - 7
    -125.0, 50.0,

    100.0, 0.0, // left arm, #8 - 9
    125.0, 50.0,

    -35.0, 75.0, // lower body, #10 - 11
    35.0, 75.0,

    -25.0, 200.0, // right leg, #12 - 13
    -30.0, 300.0,

    25.0, 200.0, // left leg, #14 - 15
    30.0, 300.0

};

static constexpr int Bones[BoneCount * 2] = {
    0, 1, // neck

    1, 2, // body
    1, 3,
    1, 4,
    1, 5,
    2, 3,
    2, 4,
    2, 5,
    3, 4,
    3, 5,
    4, 5,

    2, 6, // right arm
    6, 7,

    3, 8, // left arm
    8, 9,

    4, 10, // lower body
    4, 11,
    5, 10,
    5, 11,
    10, 11,

    10, 12, // right leg
    12, 13,

    11, 14, // left leg
    14, 15

};

StickMan::StickMan()
{
    // Set up start position of limbs
    for (int i = 0; i < NodeCount; ++i) {
        m_nodes[i] = new Node(QPointF(Coords[i * 2], Coords[i * 2 + 1]), this);
        connect(m_nodes[i], &Node::positionChanged, this, &StickMan::childPositionChanged);
    }

    for (int i = 0; i < BoneCount; ++i) {
        int n1 = Bones[i * 2];
        int n2 = Bones[i * 2 + 1];

        Node *node1 = m_nodes[n1];
        Node *node2 = m_nodes[n2];

        QPointF dist = node1->pos() - node2->pos();
        m_perfectBoneLengths[i] = sqrt(pow(dist.x(), 2) + pow(dist.y(), 2));
    }

    startTimer(10);
}

void StickMan::childPositionChanged()
{
    prepareGeometryChange();
}

void StickMan::setDrawSticks(bool on)
{
    m_sticks = on;
    for (int i = 0; i < nodeCount(); ++i) {
        Node *node = m_nodes[i];
        node->setVisible(on);
    }
}

QRectF StickMan::boundingRect() const
{
    // account for head radius=50.0 plus pen which is 5.0
    return childrenBoundingRect().adjusted(-55.0, -55.0, 55.0, 55.0);
}

int StickMan::nodeCount() const
{
    return NodeCount;
}

Node *StickMan::node(int idx) const
{
    if (idx >= 0 && idx < NodeCount)
        return m_nodes[idx];
    return nullptr;
}

void StickMan::timerEvent(QTimerEvent *)
{
    update();
}

void StickMan::stabilize()
{
    static const qreal threshold = 0.001;

    for (int i = 0; i < BoneCount; ++i) {
        int n1 = Bones[i * 2];
        int n2 = Bones[i * 2 + 1];

        Node *node1 = m_nodes[n1];
        Node *node2 = m_nodes[n2];

        QPointF pos1 = node1->pos();
        QPointF pos2 = node2->pos();

        QPointF dist = pos1 - pos2;
        qreal length = sqrt(pow(dist.x(),2) + pow(dist.y(),2));
        qreal diff = (length - m_perfectBoneLengths[i]) / length;

        QPointF p = dist * (0.5 * diff);
        if (p.x() > threshold && p.y() > threshold) {
            pos1 -= p;
            pos2 += p;

            node1->setPos(pos1);
            node2->setPos(pos2);
        }
    }
}

QPointF StickMan::posFor(int idx) const
{
    return m_nodes[idx]->pos();
}

//#include <QTime>
void StickMan::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
  /*  static int frames = 0;
    static QTime time;
    if (frames++ % 100 == 0) {
        frames = 1;
        time.restart();
    }

    if (time.elapsed() > 0) {
        painter->setPen(Qt::white);
        painter->drawText(0, 0, QString::number(frames / (time.elapsed() / 1000.0)));
    }*/

    stabilize();
    if (m_sticks) {
        painter->setPen(Qt::white);
        for (int i = 0; i < BoneCount; ++i) {
            int n1 = Bones[i * 2];
            int n2 = Bones[i * 2 + 1];

            Node *node1 = m_nodes[n1];
            Node *node2 = m_nodes[n2];

            painter->drawLine(node1->pos(), node2->pos());
        }
    } else {
        // first bone is neck and will be used for head

        QPainterPath path;
        path.moveTo(posFor(0));
        path.lineTo(posFor(1));

        // right arm
        path.lineTo(posFor(2));
        path.lineTo(posFor(6));
        path.lineTo(posFor(7));

        // left arm
        path.moveTo(posFor(3));
        path.lineTo(posFor(8));
        path.lineTo(posFor(9));

        // body
        path.moveTo(posFor(2));
        path.lineTo(posFor(4));
        path.lineTo(posFor(10));
        path.lineTo(posFor(11));
        path.lineTo(posFor(5));
        path.lineTo(posFor(3));
        path.lineTo(posFor(1));

        // right leg
        path.moveTo(posFor(10));
        path.lineTo(posFor(12));
        path.lineTo(posFor(13));

        // left leg
        path.moveTo(posFor(11));
        path.lineTo(posFor(14));
        path.lineTo(posFor(15));

        painter->setPen(QPen(m_penColor, 5.0, Qt::SolidLine, Qt::RoundCap));
        painter->drawPath(path);

        {
            int n1 = Bones[0];
            int n2 = Bones[1];
            Node *node1 = m_nodes[n1];
            Node *node2 = m_nodes[n2];

            QPointF dist = node2->pos() - node1->pos();

            qreal sinAngle = dist.x() / sqrt(pow(dist.x(), 2) + pow(dist.y(), 2));
            qreal angle = qRadiansToDegrees(asin(sinAngle));

            QPointF headPos = node1->pos();
            painter->translate(headPos);
            painter->rotate(-angle);

            painter->setBrush(m_fillColor);
            painter->drawEllipse(QPointF(0,0), 50.0, 50.0);

            painter->setBrush(m_penColor);
            painter->setPen(QPen(m_penColor, 2.5, Qt::SolidLine, Qt::RoundCap));

            // eyes
            if (m_isDead) {
                painter->drawLine(-30.0, -30.0, -20.0, -20.0);
                painter->drawLine(-20.0, -30.0, -30.0, -20.0);

                painter->drawLine(20.0, -30.0, 30.0, -20.0);
                painter->drawLine(30.0, -30.0, 20.0, -20.0);
            } else {
                painter->drawChord(QRectF(-30.0, -30.0, 25.0, 70.0), 30.0*16, 120.0*16);
                painter->drawChord(QRectF(5.0, -30.0, 25.0, 70.0), 30.0*16, 120.0*16);
            }

            // mouth
            if (m_isDead) {
                painter->drawLine(-28.0, 2.0, 29.0, 2.0);
            } else {
                painter->setBrush(QColor(128, 0, 64 ));
                painter->drawChord(QRectF(-28.0, 2.0-55.0/2.0, 57.0, 55.0), 0.0, -180.0*16);
            }

            // pupils
            if (!m_isDead) {
                painter->setPen(QPen(m_fillColor, 1.0, Qt::SolidLine, Qt::RoundCap));
                painter->setBrush(m_fillColor);
                painter->drawEllipse(QPointF(-12.0, -25.0), 5.0, 5.0);
                painter->drawEllipse(QPointF(22.0, -25.0), 5.0, 5.0);
            }
        }
    }
}



