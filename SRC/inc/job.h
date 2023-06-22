#ifndef JOB_H
#define JOB_H

#include <QDialog>

namespace Ui {
class Job;
}

class Job : public QDialog
{
	Q_OBJECT

public:
	explicit Job(QWidget *parent = nullptr);
	~Job();

private:
	Ui::Job *ui;
};

#endif // JOB_H
