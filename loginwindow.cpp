#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "DashboardWindow.h"

#include <QSqlQuery>
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_btnLogin_clicked()
{
    QString username = ui->txtUsername->text().trimmed();
    QString password = ui->txtPassword->text();

    if (username.isEmpty() || password.isEmpty())
    {
        QMessageBox::warning(this,
                             "Login",
                             "Please enter both username and password.");
        return;
    }

    QSqlQuery query;

    query.prepare(
        "SELECT * FROM users "
        "WHERE username = :username "
        "AND password = :password"
        );

    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (query.exec() && query.next())
    {
        QMessageBox::information(this,
                                 "Success",
                                 "Login Successful!");

        DashboardWindow *dashboard = new DashboardWindow();
        dashboard->show();

        this->close();
    }
    else
    {
        QMessageBox::critical(this,
                              "Login Failed",
                              "Invalid username or password.");
    }
}
