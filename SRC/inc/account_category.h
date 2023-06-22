#ifndef ACCOUNT_CATEGORY_H
#define ACCOUNT_CATEGORY_H

#include <QDialog>

namespace Ui {
class Account_Category;
}

class Account_Category : public QDialog
{
    Q_OBJECT

public:
    explicit Account_Category(QWidget *parent = nullptr);
    ~Account_Category();

private slots:
    void save_account_category(QString);
    void on_buttonBox_accepted();

private:
    Ui::Account_Category *ui;
};

#endif // ACCOUNT_CATEGORY_H
