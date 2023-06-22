#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "transaction.h"
#include "account.h"
#include "account_category.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void handleButton();
    void on_open_form_button_clicked();
    void on_add_account_button_clicked();
    void on_add_account_category_clicked();

private:
    Ui::MainWindow *ui;
    Transaction transaction_form;
    Account account_form;
    Account_Category account_category_form;
};
#endif // MAINWINDOW_H
