#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Contactlist.h"
#include <QStringListModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();  // Slot for the "Add" button
    void on_removeButton_clicked();  // Slot for the "Remove" button
    void on_searchButton_clicked();  // Slot for the "Search" button

private:
    Ui::MainWindow *ui;
    ContactList contactList;
    QStringListModel *model;  // For updating the QListView

    void updateContactListView();  // Function to refresh the contact list view
};

#endif // MAINWINDOW_H
