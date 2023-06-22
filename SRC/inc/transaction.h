#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QDialog>

namespace Ui {
class Transaction;
}

class Transaction : public QDialog
{
    Q_OBJECT

public:
    explicit Transaction(QWidget *parent = nullptr);
    ~Transaction();

private slots:
    void on_buttonBox_accepted();
    void save_transaction(QString, QString, QString, QString, QString, QString, QString);

private:
    Ui::Transaction *ui;
	QString data_folder = "C:/Users/oscar/Documents/GitHub/qt/budget/data/";
	QString data_filename_main = "data";
	QString data_filename_daily = "data-daily_save-xxx";
};

#endif // TRANSACTION_H
