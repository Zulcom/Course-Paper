#include "adduser.h"
#include "ui_adduser.h"
#include "Model/User.h"
#include <QMessageBox>
#include <sha256/sha256.h>
#include <db/db.h>

addUser::addUser(QWidget* parent) :
	QDialog(parent),
	ui(new Ui::addUser) {
	ui->setupUi(this);
	ui->username->setValidator(new QRegExpValidator(QRegExp("^\\S*$"), this));
	ui->password->setValidator(new QRegExpValidator(QRegExp("^\\S*$"), this));
	setWindowTitle(boxtitile);
	ui->status->addItem("Администратор");
	ui->status->addItem("Библиотекарь");
	ui->status->addItem("Читатель");
	/* connect(ui->addUserButton,
	         SIGNAL(clicked(bool)),
	         this,
	         SLOT(on_addUserButton_clicked())
	         );
   */
}

//перегружаем функцию, чтобы окно не закрывалось при добавлении
void addUser::accept() {}

addUser::~addUser() {
	delete ui;
}

void addUser::on_addUserButton_clicked() {

	if (ui->username->text().isEmpty() || ui->password->text().isEmpty())
	{
		QMessageBox::warning(this, boxtitile,
		                     "Нельзя создавать пользователя с пустым именем или паролем");
		return;
	}
	User* user = new User(
	                      ui->username->text().toStdString(),
	                      sha256(ui->password->text().toStdString()),
	                      ui->status->currentIndex());
   DataBase::addUser(user);
		QMessageBox::information(this, boxtitile,
                                 "Пользователь успешно добавлен!");
}
