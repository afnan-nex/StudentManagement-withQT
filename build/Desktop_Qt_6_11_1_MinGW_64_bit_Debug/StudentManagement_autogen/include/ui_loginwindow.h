/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QFrame *frame;
    QFormLayout *formLayout;
    QLabel *lblTitle;
    QLabel *lblUsername;
    QLineEdit *txtUsername;
    QLabel *lblPassword;
    QLineEdit *txtPassword;
    QPushButton *btnLogin;

    void setupUi(QWidget *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(349, 140);
        LoginWindow->setMaximumSize(QSize(500, 16777215));
        frame = new QFrame(LoginWindow);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 350, 141));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        formLayout = new QFormLayout(frame);
        formLayout->setObjectName("formLayout");
        lblTitle = new QLabel(frame);
        lblTitle->setObjectName("lblTitle");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, lblTitle);

        lblUsername = new QLabel(frame);
        lblUsername->setObjectName("lblUsername");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, lblUsername);

        txtUsername = new QLineEdit(frame);
        txtUsername->setObjectName("txtUsername");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, txtUsername);

        lblPassword = new QLabel(frame);
        lblPassword->setObjectName("lblPassword");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, lblPassword);

        txtPassword = new QLineEdit(frame);
        txtPassword->setObjectName("txtPassword");
        txtPassword->setEchoMode(QLineEdit::EchoMode::Password);

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, txtPassword);

        btnLogin = new QPushButton(frame);
        btnLogin->setObjectName("btnLogin");
        btnLogin->setMinimumSize(QSize(0, 40));
        btnLogin->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, btnLogin);


        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QWidget *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "Form", nullptr));
        lblTitle->setText(QCoreApplication::translate("LoginWindow", "Student Mangement System", nullptr));
        lblUsername->setText(QCoreApplication::translate("LoginWindow", "username", nullptr));
        txtUsername->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Enter your username", nullptr));
        lblPassword->setText(QCoreApplication::translate("LoginWindow", "Password", nullptr));
        txtPassword->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Enter your password", nullptr));
        btnLogin->setText(QCoreApplication::translate("LoginWindow", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
