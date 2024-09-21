#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Initialize the model for the QListView
    model = new QStringListModel(this);
    ui->contactListView->setModel(model);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_addButton_clicked() {
    QString name = ui->nameEdit->text();
    QString phone = ui->phoneEdit->text();
    QString email = ui->emailEdit->text();

    // Ensure all fields are filled
    if (name.isEmpty() || phone.isEmpty() || email.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in all fields.");
        return;
    }

    // Add the contact
    Contact newContact(name, phone, email);
    contactList.addContact(newContact);

    // Refresh the contact list view
    updateContactListView();

    // Clear input fields
    ui->nameEdit->clear();
    ui->phoneEdit->clear();
    ui->emailEdit->clear();
}

void MainWindow::on_removeButton_clicked() {
    QModelIndex index = ui->contactListView->currentIndex();
    if (index.isValid()) {
        contactList.removeContact(index.row());
        updateContactListView();
    } else {
        QMessageBox::warning(this, "Selection Error", "Please select a contact to remove.");
    }
}

void MainWindow::on_searchButton_clicked() {
    QString name = ui->nameEdit->text();
    Contact contact = contactList.searchContact(name);

    if (!contact.getName().isEmpty()) {
        ui->phoneEdit->setText(contact.getPhone());
        ui->emailEdit->setText(contact.getEmail());
    } else {
        QMessageBox::warning(this, "Search Error", "Contact not found.");
        ui->phoneEdit->clear();
        ui->emailEdit->clear();
    }
}

void MainWindow::updateContactListView() {
    QStringList contactNames;
    for (const Contact &contact : contactList.getContacts()) {
        contactNames << contact.getName();
    }

    model->setStringList(contactNames);  // Update the QListView
}
