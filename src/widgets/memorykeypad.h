/*
* Copyright (C) 2019 ~ 2020 Uniontech Software Technology Co.,Ltd.
*
* Author:     xiajing <xiajing@uniontech.com>
*
* Maintainer: jingzhou <jingzhou@uniontech.com>
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

#ifndef MEMORYKEYPAD_H
#define MEMORYKEYPAD_H

#include <QWidget>
#include <QGridLayout>
#include <QSignalMapper>
#include <DGuiApplicationHelper>
#include <DSuggestButton>

#include "textbutton.h"
#include "iconbutton.h"
#include "memorybutton.h"
#include "equalbutton.h"

DWIDGET_USE_NAMESPACE
DGUI_USE_NAMESPACE

/**
 * @brief 简易计算器内存按键栏
 */
class MemoryKeypad : public DWidget
{
    Q_OBJECT

public:
    /**
     * @brief 内存按键栏
     */
    enum Buttons {Key_MC = 20, Key_MR, Key_Mplus, Key_Mminus, Key_MS, Key_Mlist}; //MC, MR, M+, M-, MS, M^

    MemoryKeypad(QWidget *parent = nullptr);
    ~MemoryKeypad();

    DPushButton *button(Buttons key);
    void animate(Buttons key);
    void animate();

    static const struct KeyDescription {
        QString text;
        Buttons button;
        int row;
        int column;
        int rowcount;
        int columncount;
    } keyDescriptions[];
public slots:
    void initButtons();
    void buttonThemeChanged(int type);
signals:
    void buttonPressed(int);
    void equalPressed();
    void moveLeft();
    void moveRight();

private:
    QGridLayout *m_layout;
    QSignalMapper *m_mapper;
    QHash<Buttons, QPair<DPushButton *, const KeyDescription *>> m_keys;
    //DSuggestButton *m_equal;
    //EqualButton *m_equal;
};

#endif // MEMORYKEYPAD_H
