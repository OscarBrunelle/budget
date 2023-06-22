#include "transaction.h"
#include "ui_transaction.h"
#include "db_helper.h"
#include "customsearchwidget.h"
#include <QFile>
#include <QTextStream>
#include <QDateTime>

CustomSearchWidget *e_emitter;
CustomSearchWidget *e_recipient;
CustomSearchWidget *e_category;

Transaction::Transaction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Transaction)
{
    ui->setupUi(this);
    e_emitter = new CustomSearchWidget("account", "Emetteur", "name", ui->formLayout);
    e_recipient = new CustomSearchWidget("account", "Destinataire", "name", ui->formLayout);
    e_category = new CustomSearchWidget("transaction_category", "Type de transaction", "name", ui->formLayout);
}

Transaction::~Transaction()
{
    delete ui;
}

void Transaction::save_transaction(QString account_from_id, QString account_to_id, QString amount, QString title, QString category, QString transaction_datetime, QString note) {
	add_to_db_table("transaction", {"account_from_id", "account_to_id", "amount", "title", "category", "transaction_datetime", "note"}, {account_from_id, account_to_id, amount, title, category, transaction_datetime, note});
}

void Transaction::on_buttonBox_accepted()
{
	QString account_from_id = e_emitter->get_selected_id();
	QString account_to_id = e_recipient->get_selected_id();
    QString amount = ui->amountLineEdit->text();
    QString title = ui->titleLineEdit->text();
    QString category = e_category->get_selected_id();
    QDate date = ui->calendarWidget->selectedDate();
    QTime time = ui->timeEdit->time();
    QString dt_string = QString("%1-%2-%3 %4").arg(date.year()).arg(date.month()).arg(date.day()).arg(time.toString());
    QString note = ui->notePlainTextEdit->toPlainText();
	save_transaction(account_from_id, account_to_id, amount, title, category, dt_string, note);
}


