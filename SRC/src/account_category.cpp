#include "account_category.h"
#include "ui_account_category.h"
#include "db_helper.h"

Account_Category::Account_Category(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Account_Category)
{
    ui->setupUi(this);
}

Account_Category::~Account_Category()
{
    delete ui;
}

void Account_Category::save_account_category(QString name) {
    add_to_db_table("account_category", {"name"}, {name});
}

void Account_Category::on_buttonBox_accepted()
{
    QString name = ui->nameLineEdit->text();
    if (name == "") {
        ui->error_message->setText("Le nom ne doit pas être vide");
            return;
    }
    save_account_category(name);
}

