/********************************************************************************
** Form generated from reading UI file 'waitfortheend.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAITFORTHEEND_H
#define UI_WAITFORTHEEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WaitForTheEnd
{
public:
    QGridLayout *gridLayout;

    void setupUi(QWidget *WaitForTheEnd)
    {
        if (WaitForTheEnd->objectName().isEmpty())
            WaitForTheEnd->setObjectName(QString::fromUtf8("WaitForTheEnd"));
        WaitForTheEnd->resize(852, 442);
        gridLayout = new QGridLayout(WaitForTheEnd);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        retranslateUi(WaitForTheEnd);

        QMetaObject::connectSlotsByName(WaitForTheEnd);
    } // setupUi

    void retranslateUi(QWidget *WaitForTheEnd)
    {
        WaitForTheEnd->setWindowTitle(QApplication::translate("WaitForTheEnd", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WaitForTheEnd: public Ui_WaitForTheEnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAITFORTHEEND_H
