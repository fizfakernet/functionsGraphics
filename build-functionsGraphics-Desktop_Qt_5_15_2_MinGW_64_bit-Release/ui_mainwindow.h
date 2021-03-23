/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *line_2;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QComboBox *selectFunction;
    QLabel *label;
    QLineEdit *inputA;
    QFrame *line;
    QLabel *label_4;
    QLineEdit *inputFrom;
    QLabel *label_2;
    QLineEdit *inputB;
    QLabel *label_5;
    QLineEdit *inputTo;
    QLabel *label_3;
    QLineEdit *inputC;
    QLabel *label_6;
    QLineEdit *inputStep;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QPushButton *startButton;
    QPushButton *pauseButton;
    QPushButton *breakButton;
    QWidget *ploterSpace;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(465, 195);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(250, 0, 20, 901));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 11, 241, 100));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        selectFunction = new QComboBox(layoutWidget);
        selectFunction->addItem(QString());
        selectFunction->addItem(QString());
        selectFunction->addItem(QString());
        selectFunction->addItem(QString());
        selectFunction->setObjectName(QString::fromUtf8("selectFunction"));

        gridLayout->addWidget(selectFunction, 0, 0, 1, 5);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        inputA = new QLineEdit(layoutWidget);
        inputA->setObjectName(QString::fromUtf8("inputA"));

        gridLayout->addWidget(inputA, 1, 1, 1, 1);

        line = new QFrame(layoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 1, 2, 3, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 3, 1, 1);

        inputFrom = new QLineEdit(layoutWidget);
        inputFrom->setObjectName(QString::fromUtf8("inputFrom"));

        gridLayout->addWidget(inputFrom, 1, 4, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        inputB = new QLineEdit(layoutWidget);
        inputB->setObjectName(QString::fromUtf8("inputB"));

        gridLayout->addWidget(inputB, 2, 1, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 3, 1, 1);

        inputTo = new QLineEdit(layoutWidget);
        inputTo->setObjectName(QString::fromUtf8("inputTo"));

        gridLayout->addWidget(inputTo, 2, 4, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        inputC = new QLineEdit(layoutWidget);
        inputC->setObjectName(QString::fromUtf8("inputC"));

        gridLayout->addWidget(inputC, 3, 1, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(label_6, 3, 3, 1, 1);

        inputStep = new QLineEdit(layoutWidget);
        inputStep->setObjectName(QString::fromUtf8("inputStep"));

        gridLayout->addWidget(inputStep, 3, 4, 1, 1);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(11, 120, 239, 25));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        startButton = new QPushButton(layoutWidget1);
        startButton->setObjectName(QString::fromUtf8("startButton"));

        gridLayout_2->addWidget(startButton, 0, 0, 1, 1);

        pauseButton = new QPushButton(layoutWidget1);
        pauseButton->setObjectName(QString::fromUtf8("pauseButton"));

        gridLayout_2->addWidget(pauseButton, 0, 1, 1, 1);

        breakButton = new QPushButton(layoutWidget1);
        breakButton->setObjectName(QString::fromUtf8("breakButton"));

        gridLayout_2->addWidget(breakButton, 0, 2, 1, 1);

        ploterSpace = new QWidget(centralwidget);
        ploterSpace->setObjectName(QString::fromUtf8("ploterSpace"));
        ploterSpace->setGeometry(QRect(270, 10, 181, 131));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 465, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        selectFunction->setItemText(0, QCoreApplication::translate("MainWindow", "f(x) = A*(x*x) + B*x + C", nullptr));
        selectFunction->setItemText(1, QCoreApplication::translate("MainWindow", "f(x) = A * sin(x) + B * cos( C*x )", nullptr));
        selectFunction->setItemText(2, QCoreApplication::translate("MainWindow", "f(x) = A*log( B*x )", nullptr));
        selectFunction->setItemText(3, QCoreApplication::translate("MainWindow", "f(x) = A / ( sin(x*x) * B )", nullptr));

        label->setText(QCoreApplication::translate("MainWindow", "A = ", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "FROM", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "B = ", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "TO", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "C = ", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "STEP", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        pauseButton->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        breakButton->setText(QCoreApplication::translate("MainWindow", "Break", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
