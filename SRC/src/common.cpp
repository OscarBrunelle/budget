#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QListWidget>
#include <QList>
#include "db_helper.h"

QString data_path = "C:/Users/oscar/Documents/GitHub/qt/jobs/data/";

void writeJsonArray(QString filename, QJsonObject json_data) {
	QJsonDocument doc(json_data);
	QString data_string = doc.toJson(QJsonDocument::Indented); // or QJsonDocument::Compact

	QFile file(filename);
	if (file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text)) {
		QTextStream stream( & file);
		stream << data_string;
	}
}

QJsonArray readJsonArray(QString filename, QString data_index)
{
	QString val;
	QFile file;
	file.setFileName(filename);
	file.open(QIODevice::ReadOnly | QIODevice::Text);
	val = file.readAll();
	file.close();
	QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
	QJsonObject jObj = d.object();
	QJsonArray array = jObj[data_index].toArray();
//	QJsonObject object = jObj[data_index].toObject();
	return array;
}

void fill_list_from_json(QListWidget *list_widget, QString file_path, QString json_object_name, QString property_name) {
	QJsonArray arr = readJsonArray(file_path, json_object_name);
	for(int i = 0; i < arr.count(); ++i)
	{
		QString value = arr.at(i).toObject()[property_name].toString();
		list_widget->addItem(value);
	}
}

void update_list(QString search, QListWidget* list_element, QString table, QString field, QList<QString> &list_indexes) {
	while(list_element->count()>0) {
		list_element->takeItem(0);
	}
	list_indexes = {};
	QList<QMap<QString, QString>> records = get_records(table);
	if (records.size() <= 0) return;
	for (int i = 0; i < records.size(); i++) {
		QString value = records[i][field];
		if (value.contains(search, Qt::CaseInsensitive)) {
			list_indexes.append(records[i]["id"]);
			list_element->addItem(value);
		}
	}
}
