// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include "qmlgruesensor.h"


QMLGrueSensor::QMLGrueSensor():QSensor("GrueSensor") //  QLightSensor
{
    connectToBackend();
    start();
}
