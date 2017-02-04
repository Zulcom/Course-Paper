#include "deluser.h"
#include "ui_deluser.h"
#include <QMessageBox>
#include <Model/User.h>
#include <db/db.h>
delUser::delUser(QWidget* parent) :
	QDialog(parent),
	ui(new Ui::delUser) {
	ui->setupUi(this);
	ui->username->setValidator(new QRegExpValidator(QRegExp("^\\S*$"), this));
	setWindowTitle(boxtitile);
}

//перегружаем функцию, чтобы окно не закрывалось при добавлении
void delUser::accept() {}

delUser::~delUser() {
	delete ui;
}

void delUser::on_delUserButton_clicked() {
	if (ui->username->text().isEmpty())
	{
		QMessageBox::warning(this, boxtitile, "Вы не ввели имя пользователя!");
		return;
	}
    bool res = DataBase::removeUser(ui->username->text().toStdString());
	if (res) QMessageBox::information(this, boxtitile, "Пользователь успешно удлаён!");
	else QMessageBox::warning(this, boxtitile, "Пользователь не был удалён!");
}
