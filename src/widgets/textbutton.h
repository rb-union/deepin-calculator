/*
 * Copyright (C) 2017 ~ 2018 Deepin Technology Co., Ltd.
 *
 * Author:     rekols <rekols@foxmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TEXTBUTTON_H
#define TEXTBUTTON_H

#include <DPushButton>
#include <DPalette>
#include <QGraphicsDropShadowEffect>
#include <QDebug>

#include "../dsettings.h"

DWIDGET_USE_NAMESPACE
DGUI_USE_NAMESPACE

class TextButton : public DPushButton
{
    Q_OBJECT

public:
    TextButton(const QString &text = QString(), bool page = false, QWidget *parent = nullptr);
    ~TextButton();


    void init();
    //void showShadow();
    //void hideShadow();
    void animate(int msec = 100);
    void setTextUnderLine(bool down);
    void setPageDown(bool down);
signals:
    void moveLeft();
    void moveRight();
    void updateInterface();

public:
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void keyPressEvent(QKeyEvent *);
    void paintEvent(QPaintEvent *e);
    void focusOutEvent(QFocusEvent *);
private:
    QGraphicsDropShadowEffect *m_effect;

    DPalette m_palette;
    DSettings *m_settings;
    bool m_isHover;
    bool m_isPress;
    QFont m_font;
    bool m_page;
    bool m_Pageisdown = false;
};

#endif