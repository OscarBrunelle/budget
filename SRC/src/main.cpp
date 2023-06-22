#include "mainwindow.h"
#include "db_helper.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QApplication>
#include <QtWidgets/QMainWindow>

QT_USE_NAMESPACE

void add_tables_to_db() {
    create_table("account", {
        {"name", "nvarchar(255)", false},
        {"category", "int", false},
        {"note", "text", true},
        {"account_opened_date", "date", true}
    });
    create_table_update_trigger("account");
    create_table("account_category", {
        {"name", "nvarchar(255)", false}
    });
    create_table_update_trigger("account_category");
    create_table("transaction", {
		{"account_from_id", "int", false},
		{"account_to_id", "int", false},
        {"amount", "float", false},
        {"title", "nvarchar(255)", true},
        {"category", "int", true},
        {"transaction_datetime", "datetime", true},
        {"note", "text", true}
    });
    create_table_update_trigger("transaction");
    create_table("transaction_category", {
        {"name", "nvarchar(255)", false}
    });
    create_table_update_trigger("transaction_category");
}

void add_default_values_to_db() {
    qDebug() << "Ajout des valeurs par défaut dans la base de données";
	QList<QString> account_categories = {"Compte de rectification", "Compte bancaire personnel", "Compte commun", "Livret A", "Livret Jeune", "LEP (Livret Epargne Populaire)", "Assurance vie", "Cryptomonnaies", "PEE (Plan Epargne Entreprise)", "PER COL (Plan Epargne Retraite Collectif)", "PEA (Plan Epargne Actions)"}; // Actions
    foreach (QString account_category, account_categories) {
        add_to_db_table("account_category", {"name"}, {account_category});
    }
    QList<QString> transaction_categories = {"Rectification / Mise à jour"};
    foreach (QString transaction_category, transaction_categories) {
        add_to_db_table("transaction_category", {"name"}, {transaction_category});
    }
	add_to_db_table("account", {"name", "category", "note"}, {"Compte d'argent magique", "1", "Ce compte est destiné à corriger les erreurs entre les valeurs du logiciel et les valeurs réelles des comptes."});
    //, "account_opened_date"
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Qt App");
    w.show();
//	add_tables_to_db();
//	add_default_values_to_db();
    return a.exec();
}
