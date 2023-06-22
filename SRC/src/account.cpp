#include "account.h"
#include "db_helper.h"
#include "ui_account.h"

Account::Account(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Account)
{
	ui->setupUi(this);
}

Account::~Account()
{
	delete ui;
}

void Account::on_buttonBox_accepted()
{
    save_account(15.6);
}

void Account::save_account(float amount) {
    qDebug() << "Saving account";
//    QString name = ui->nameLineEdit->text();
//    QString city = ui->cityLineEdit->text();
//    QString details = ui->detailsTextEdit->toPlainText();
//    QString type = ui->typeComboBox->currentText();
//    QString group_id = e_search_enterprisegroup->get_selected_id();
//    if (name == "") return;
//    add_to_db_table("enterprise", {"name", "city", "details", "type", "group_id"}, {name, city, details, type, group_id});
}
