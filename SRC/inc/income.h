#ifndef INCOME_H
#define INCOME_H

#include <QDialog>

namespace Ui {
class Income;
}

class Income : public QDialog
{
	Q_OBJECT

public:
	explicit Income(QWidget *parent = nullptr);
	~Income();

private:
	Ui::Income *ui;
};

#endif // INCOME_H
