/********************************************************************************
** Form generated from reading UI file 'test.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_H
#define UI_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Test
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QRadioButton *option1;
    QRadioButton *option2;
    QRadioButton *option3;
    QRadioButton *option4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QRadioButton *radioButton;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Test)
    {
        if (Test->objectName().isEmpty())
            Test->setObjectName(QStringLiteral("Test"));
        Test->resize(800, 600);
        centralwidget = new QWidget(Test);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 60, 661, 21));
        option1 = new QRadioButton(centralwidget);
        option1->setObjectName(QStringLiteral("option1"));
        option1->setGeometry(QRect(30, 100, 110, 26));
        option2 = new QRadioButton(centralwidget);
        option2->setObjectName(QStringLiteral("option2"));
        option2->setGeometry(QRect(30, 140, 110, 26));
        option3 = new QRadioButton(centralwidget);
        option3->setObjectName(QStringLiteral("option3"));
        option3->setGeometry(QRect(30, 180, 110, 26));
        option4 = new QRadioButton(centralwidget);
        option4->setObjectName(QStringLiteral("option4"));
        option4->setEnabled(true);
        option4->setGeometry(QRect(30, 220, 110, 26));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(510, 250, 61, 31));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(600, 250, 71, 31));
        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(30, 260, 110, 26));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(490, 10, 51, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(400, 10, 67, 21));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(540, 10, 67, 21));
        Test->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Test);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 27));
        Test->setMenuBar(menubar);
        statusbar = new QStatusBar(Test);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Test->setStatusBar(statusbar);

        retranslateUi(Test);

        QMetaObject::connectSlotsByName(Test);
    } // setupUi

    void retranslateUi(QMainWindow *Test)
    {
        Test->setWindowTitle(QApplication::translate("Test", "Test", 0));
        label->setText(QApplication::translate("Test", "This is sample question", 0));
        option1->setText(QApplication::translate("Test", "option 1", 0));
        option2->setText(QApplication::translate("Test", "option 2", 0));
        option3->setText(QApplication::translate("Test", "option 3", 0));
        option4->setText(QApplication::translate("Test", "option 4", 0));
        pushButton->setText(QApplication::translate("Test", "next", 0));
        pushButton_2->setText(QApplication::translate("Test", "submit", 0));
        radioButton->setText(QApplication::translate("Test", "Don't know", 0));
        label_2->setText(QApplication::translate("Test", "10", 0));
        label_3->setText(QApplication::translate("Test", "Time Left", 0));
        label_4->setText(QApplication::translate("Test", "seconds", 0));
    } // retranslateUi

};

namespace Ui {
    class Test: public Ui_Test {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_H
