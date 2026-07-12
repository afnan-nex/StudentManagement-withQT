#include "DashboardWindow.h"
#include "ui_DashboardWindow.h"
#include <QSqlError>
#include <QMessageBox>

DashboardWindow::DashboardWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DashboardWindow)
{
    ui->setupUi(this);

    // Set up the database model and bind it to the view layer
    setupStudentModel();
}

DashboardWindow::~DashboardWindow()
{
    delete ui;
}

void DashboardWindow::setupStudentModel()
{
    model = new QSqlTableModel(this);
    model->setTable("students");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    if (!model->select()) {
        QMessageBox::critical(this, "Database Error",
                              "Failed to load student data: " + model->lastError().text());
        return;
    }

    // Match these exactly to your database table columns:
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Name"));
    model->setHeaderData(2, Qt::Horizontal, tr("Age"));
    model->setHeaderData(3, Qt::Horizontal, tr("Phone"));
    model->setHeaderData(4, Qt::Horizontal, tr("Email"));

    ui->studentTableView->setModel(model);
    ui->studentTableView->setColumnHidden(0, true); // Keeps auto-increment ID hidden
}
void DashboardWindow::on_btn_add_clicked()
{
    // 1. Gather input data from your UI fields
    // Note: Make sure these objectNames match your line edits exactly!
    QString name = ui->txtName->text().trimmed();
    QString ageStr = ui->txtAge->text().trimmed();
    QString phone = ui->txtPhone->text().trimmed();
    QString email = ui->txtEmail->text().trimmed();

    // 2. Simple validation
    if (name.isEmpty() || ageStr.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Name and Age fields are required.");
        return;
    }

    // 3. Insert a new blank row at the very end of our table model
    int row = model->rowCount();
    model->insertRow(row);

    // 4. Populate each column index in that row
    // (Column 0 is the auto-increment ID, so we start mapping at Column 1)
    model->setData(model->index(row, 1), name);
    model->setData(model->index(row, 2), ageStr.toInt());
    model->setData(model->index(row, 3), phone);
    model->setData(model->index(row, 4), email);

    // 5. Submit the cached row directly to the SQLite database file
    if (model->submitAll()) {
        QMessageBox::information(this, "Success", "Student record added successfully!");

        // Clear out the input boxes so they are ready for the next entry
        ui->txtName->clear();
        ui->txtAge->clear();
        ui->txtPhone->clear();
        ui->txtEmail->clear();
    } else {
        // If it fails (e.g., database lock or constraint failure), notify and rollback the model cache
        QMessageBox::critical(this, "Database Error",
                              "Failed to save student: " + model->lastError().text());
        model->revertAll();
    }
}

void DashboardWindow::on_btn_delete_clicked()
{
    // 1. Get the selection model of the table view
    QItemSelectionModel *select = ui->studentTableView->selectionModel();

    // 2. Check if the user has actually selected a row
    if (!select->hasSelection()) {
        QMessageBox::warning(this, "Selection Error", "Please select a student row from the table to delete.");
        return;
    }

    // 3. Prompt the user with a confirmation dialog box
    int answer = QMessageBox::question(this, "Confirm Deletion",
                                       "Are you sure you want to delete the selected student record?",
                                       QMessageBox::Yes | QMessageBox::No);

    if (answer == QMessageBox::Yes) {
        // 4. Get the row index of the currently selected cell
        int row = select->currentIndex().row();

        // 5. Remove the row from the model cache
        model->removeRow(row);

        // 6. Submit the change to the permanent SQLite database file
        if (model->submitAll()) {
            QMessageBox::information(this, "Success", "Student record deleted successfully.");
        } else {
            QMessageBox::critical(this, "Database Error",
                                  "Failed to delete record: " + model->lastError().text());
            model->revertAll(); // Undo the cached deletion if the database write fails
        }
    }
}

void DashboardWindow::on_btn_update_clicked()
{
    // Point this to studentTableView to match your UI layout exactly
    QItemSelectionModel *select = ui->studentTableView->selectionModel();

    if (!select->hasSelection()) {
        QMessageBox::warning(this, "Selection Error", "Please select a student row from the table to update.");
        return;
    }

    int row = select->currentIndex().row();

    QString name = ui->txtName->text().trimmed();
    QString ageStr = ui->txtAge->text().trimmed();
    QString phone = ui->txtPhone->text().trimmed();
    QString email = ui->txtEmail->text().trimmed();

    if (name.isEmpty() || ageStr.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Name and Age fields are required to update the record.");
        return;
    }

    model->setData(model->index(row, 1), name);
    model->setData(model->index(row, 2), ageStr.toInt());
    model->setData(model->index(row, 3), phone);
    model->setData(model->index(row, 4), email);

    if (model->submitAll()) {
        QMessageBox::information(this, "Success", "Student record updated successfully!");
        ui->txtName->clear();
        ui->txtAge->clear();
        ui->txtPhone->clear();
        ui->txtEmail->clear();
    } else {
        QMessageBox::critical(this, "Database Error",
                              "Failed to save updates: " + model->lastError().text());
        model->revertAll();
    }
}