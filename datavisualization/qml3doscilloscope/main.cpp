// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#include "datasource.h"

//! [2]
#include <QtDataVisualization/qutils.h>
//! [2]

#include <QtGui/QGuiApplication>
#include <QtCore/QDir>
#include <QtQml/QQmlContext>
#include <QtQuick/QQuickView>
#include <QtQml/QQmlEngine>

int main(int argc, char *argv[])
{
    qputenv("QSG_RHI_BACKEND", "opengl");
    QGuiApplication app(argc, argv);

    QQuickView viewer;

    // Enable antialiasing in direct rendering mode
    //! [1]
    viewer.setFormat(qDefaultSurfaceFormat(true));
    //! [1]

    // The following are needed to make examples run without having to install the module
    // in desktop environments.
#ifdef Q_OS_WIN
    QString extraImportPath(QStringLiteral("%1/../../../../%2"));
#else
    QString extraImportPath(QStringLiteral("%1/../../../%2"));
#endif
    viewer.engine()->addImportPath(extraImportPath.arg(QGuiApplication::applicationDirPath(),
                                      QString::fromLatin1("qml")));
    QObject::connect(viewer.engine(), &QQmlEngine::quit, &viewer, &QWindow::close);

    viewer.setTitle(QStringLiteral("Oscilloscope example"));

    //! [0]
    DataSource dataSource;
    viewer.rootContext()->setContextProperty("dataSource", &dataSource);
    //! [0]

    viewer.setSource(QUrl("qrc:/qml/qml3doscilloscope/main.qml"));
    viewer.setResizeMode(QQuickView::SizeRootObjectToView);
    viewer.show();

    return app.exec();
}
