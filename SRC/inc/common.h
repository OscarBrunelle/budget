#ifndef COMMON_H
#define COMMON_H

#include "QListWidget"
#include "QString"

extern QString data_path;
QJsonArray readJsonArray(QString filename, QString data_index);
void writeJsonArray(QString filename, QJsonObject json_data);
void fill_list_from_json(QListWidget *list_widget, QString file_path, QString json_object_name, QString property_name);
void update_list(QString search, QListWidget* list_element, QString table, QString field, QList<QString> &list_indexes);

#endif // COMMON_H
