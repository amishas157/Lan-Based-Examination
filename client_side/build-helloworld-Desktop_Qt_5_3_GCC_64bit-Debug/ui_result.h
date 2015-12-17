/********************************************************************************
** Form generated from reading UI file 'result.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULT_H
#define UI_RESULT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_result
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QWidget *result)
    {
        if (result->objectName().isEmpty())
            result->setObjectName(QStringLiteral("result"));
        result->resize(538, 366);
        label = new QLabel(result);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(230, 130, 41, 31));
        label_2 = new QLabel(result);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(190, 80, 151, 51));
        QFont font;
        font.setFamily(QStringLiteral("Liberation Sans"));
        font.setPointSize(22);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        label_3 = new QLabel(result);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(210, 180, 67, 21));
        label_4 = new QLabel(result);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(210, 210, 67, 21));
        label_5 = new QLabel(result);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(170, 240, 391, 51));
        QFont font1;
        font1.setPointSize(15);
        label_5->setFont(font1);

        retranslateUi(result);

        QMetaObject::connectSlotsByName(result);
    } // setupUi

    void retranslateUi(QWidget *result)
    {
        result->setWindowTitle(QApplication::translate("result", "Performance", 0));
        label->setText(QApplication::translate("result", "TextLabel", 0));
        label_2->setText(QApplication::translate("result", "RESULT", 0));
        label_3->setText(QApplication::translate("result", "       /", 0));
        label_4->setText(QApplication::translate("result", "     10", 0));
        label_5->setText(QApplication::translate("result", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class result: public Ui_result {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULT_H
