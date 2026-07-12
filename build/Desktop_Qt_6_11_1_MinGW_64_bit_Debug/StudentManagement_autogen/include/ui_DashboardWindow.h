/********************************************************************************
** Form generated from reading UI file 'DashboardWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBOARDWINDOW_H
#define UI_DASHBOARDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DashboardWindow
{
public:
    QWidget *centralwidget;
    QTableView *studentTableView;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *txtName;
    QLineEdit *txtAge;
    QLabel *label_3;
    QLineEdit *txtPhone;
    QLineEdit *txtEmail;
    QLabel *label_4;
    QPushButton *btn_add;
    QPushButton *btn_update;
    QPushButton *btn_delete;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DashboardWindow)
    {
        if (DashboardWindow->objectName().isEmpty())
            DashboardWindow->setObjectName("DashboardWindow");
        DashboardWindow->resize(800, 600);
        centralwidget = new QWidget(DashboardWindow);
        centralwidget->setObjectName("centralwidget");
        studentTableView = new QTableView(centralwidget);
        studentTableView->setObjectName("studentTableView");
        studentTableView->setGeometry(QRect(20, 180, 621, 211));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 10, 111, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 40, 81, 16));
        txtName = new QLineEdit(centralwidget);
        txtName->setObjectName("txtName");
        txtName->setGeometry(QRect(130, 10, 113, 24));
        txtAge = new QLineEdit(centralwidget);
        txtAge->setObjectName("txtAge");
        txtAge->setGeometry(QRect(130, 40, 113, 24));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 70, 91, 16));
        txtPhone = new QLineEdit(centralwidget);
        txtPhone->setObjectName("txtPhone");
        txtPhone->setGeometry(QRect(130, 70, 113, 24));
        txtEmail = new QLineEdit(centralwidget);
        txtEmail->setObjectName("txtEmail");
        txtEmail->setGeometry(QRect(130, 100, 113, 24));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 100, 91, 16));
        btn_add = new QPushButton(centralwidget);
        btn_add->setObjectName("btn_add");
        btn_add->setGeometry(QRect(30, 140, 80, 24));
        btn_update = new QPushButton(centralwidget);
        btn_update->setObjectName("btn_update");
        btn_update->setGeometry(QRect(220, 140, 101, 24));
        btn_delete = new QPushButton(centralwidget);
        btn_delete->setObjectName("btn_delete");
        btn_delete->setGeometry(QRect(120, 140, 91, 24));
        DashboardWindow->setCentralWidget(centralwidget);
        studentTableView->raise();
        label_3->raise();
        txtEmail->raise();
        txtAge->raise();
        label_2->raise();
        txtName->raise();
        label->raise();
        label_4->raise();
        txtPhone->raise();
        btn_add->raise();
        btn_update->raise();
        btn_delete->raise();
        menubar = new QMenuBar(DashboardWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        DashboardWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(DashboardWindow);
        statusbar->setObjectName("statusbar");
        DashboardWindow->setStatusBar(statusbar);

        retranslateUi(DashboardWindow);

        QMetaObject::connectSlotsByName(DashboardWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DashboardWindow)
    {
        DashboardWindow->setWindowTitle(QCoreApplication::translate("DashboardWindow", "DashboardWindow", nullptr));
        label->setText(QCoreApplication::translate("DashboardWindow", "Student Name:", nullptr));
        label_2->setText(QCoreApplication::translate("DashboardWindow", "Age:", nullptr));
        label_3->setText(QCoreApplication::translate("DashboardWindow", "Phone Number:", nullptr));
        label_4->setText(QCoreApplication::translate("DashboardWindow", "Email Address:", nullptr));
        btn_add->setText(QCoreApplication::translate("DashboardWindow", "Add Student", nullptr));
        btn_update->setText(QCoreApplication::translate("DashboardWindow", "Update Student", nullptr));
        btn_delete->setText(QCoreApplication::translate("DashboardWindow", "Delete Student", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DashboardWindow: public Ui_DashboardWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARDWINDOW_H
