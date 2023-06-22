#include "job.h"
#include "ui_job.h"

Job::Job(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Job)
{
	ui->setupUi(this);
}

Job::~Job()
{
	delete ui;
}
