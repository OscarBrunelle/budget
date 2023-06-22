#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QDialog>

namespace Ui {
class Account;
}

class Account : public QDialog
{
	Q_OBJECT

public:
	explicit Account(QWidget *parent = nullptr);
	~Account();

private slots:
    void on_buttonBox_accepted();
    void save_account(float);

private:
	Ui::Account *ui;
};

#endif // ACCOUNT_H
