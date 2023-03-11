// MIT License
//
// Copyright (c) 2023 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
//

#include "oskb.h"
#include "qnamespace.h"

#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    oskb w;
    w.setWindowFlags(Qt::WindowStaysOnTopHint
                     | Qt::NoDropShadowWindowHint
                     | Qt::WindowDoesNotAcceptFocus);
    w.setAttribute(Qt::WA_ShowWithoutActivating);
    w.show();
    return a.exec();
}
