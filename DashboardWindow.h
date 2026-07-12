#ifndef DASHBOARDWINDOW_H
#define DASHBOARDWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel> // Included for database modeling

QT_BEGIN_NAMESPACE
namespace Ui { class DashboardWindow; }
QT_END_NAMESPACE

class DashboardWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DashboardWindow(QWidget *parent = nullptr);
    ~DashboardWindow();

private slots:
    void on_btn_add_clicked();

    void on_btn_delete_clicked();

    void on_btn_update_clicked();

private:
    Ui::DashboardWindow *ui;
    QSqlTableModel *model; // Pointer to manage student records

    void setupStudentModel(); // Helper to configure the database model
};

#endif // DASHBOARDWINDOW_H