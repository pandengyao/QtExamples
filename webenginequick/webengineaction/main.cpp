// Copyright (C) 2018 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtWebEngineQuick/qtwebenginequickglobal.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("QtExamples");
    QtWebEngineQuick::initialize();

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
