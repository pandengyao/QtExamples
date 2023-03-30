// Copyright (C) 2017 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include <QtWidgets>

#include "audiodevices.h"

int main(int argv, char **args)
{
    QApplication app(argv, args);
    app.setApplicationName("Audio Device Test");

    AudioTest audio;
    audio.show();

    return app.exec();
}
