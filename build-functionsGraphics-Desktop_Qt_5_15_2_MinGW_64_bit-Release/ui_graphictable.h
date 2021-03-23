/********************************************************************************
** Form generated from reading UI file 'graphictable.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHICTABLE_H
#define UI_GRAPHICTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphicTable
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *saveButton;
    QPushButton *loadButton;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GraphicTable)
    {
        if (GraphicTable->objectName().isEmpty())
            GraphicTable->setObjectName(QString::fromUtf8("GraphicTable"));
        GraphicTable->setWindowModality(Qt::WindowModal);
        GraphicTable->setEnabled(true);
        GraphicTable->resize(203, 625);
        centralwidget = new QWidget(GraphicTable);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(7, 2, 191, 581));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        saveButton = new QPushButton(widget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        gridLayout->addWidget(saveButton, 1, 0, 1, 1);

        loadButton = new QPushButton(widget);
        loadButton->setObjectName(QString::fromUtf8("loadButton"));

        gridLayout->addWidget(loadButton, 1, 1, 1, 1);

        tableWidget = new QTableWidget(widget);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        if (tableWidget->rowCount() < 1)
            tableWidget->setRowCount(1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEnabled(true);
        tableWidget->setLayoutDirection(Qt::LeftToRight);
        tableWidget->setRowCount(1);
        tableWidget->setColumnCount(2);
        tableWidget->horizontalHeader()->setDefaultSectionSize(52);

        gridLayout->addWidget(tableWidget, 0, 0, 1, 2);

        GraphicTable->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GraphicTable);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 203, 21));
        GraphicTable->setMenuBar(menubar);
        statusbar = new QStatusBar(GraphicTable);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        GraphicTable->setStatusBar(statusbar);

        retranslateUi(GraphicTable);

        QMetaObject::connectSlotsByName(GraphicTable);
    } // setupUi

    void retranslateUi(QMainWindow *GraphicTable)
    {
        GraphicTable->setWindowTitle(QCoreApplication::translate("GraphicTable", "MainWindow", nullptr));
        saveButton->setText(QCoreApplication::translate("GraphicTable", "save", nullptr));
        loadButton->setText(QCoreApplication::translate("GraphicTable", "load", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        tableWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class GraphicTable: public Ui_GraphicTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHICTABLE_H
