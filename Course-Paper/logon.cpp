#include "logon.h"
#include "ui_logon.h"
#include "Model/User.h"
#include "search.h"
#include <fstream>
#include <QMessageBox>
#include <db/db.h>
#include <sha256/sha256.h>
Logon::Logon(QWidget* parent) :
	QDialog(parent),
	ui(new Ui::Logon) {
	ui->setupUi(this);
	ui->forgotpassword->setVisible(false); // спрятать кнопку "забыли пароль"
	QPixmap pix("user.png");
	ui->logonImg->setPixmap(pix); // загрузить картинку
	//   connect(ui->loginButton,SIGNAL(clicked()),this,SLOT(on_loginButton_clicked()));
}

Logon::~Logon() { delete ui; }

void Logon::on_loginButton_clicked() // слот нажатия на кнопку логина
{
    std::ifstream input("user.txt",std::ios::binary);
    if (!input.is_open())
    {
        QMessageBox::warning(this,"Авторизация","Пользователей не найдено, текуший логин будет добавлен как администратор.");
         DataBase::addUser(*new User(ui->username->text().toStdString(),sha256(ui->password->text().toStdString()),0));
         search* sh = new search(this);
         emit close(); // закрыть окно логина
         sh->show(); // показать главное окно программы
         sh->setFixedSize(800, 500);
    }
	User* user = new User(ui->username->text().toStdString(), ui->password->text().toStdString());
	if (user->auth())
	{
		// если аутентификация успешна
		search* sh = new search(this);
		emit close(); // закрыть окно логина
		sh->show(); // показать главное окно программы
		sh->setFixedSize(800, 500);
	}
	else //иначе показать кнопку "забыли пароль?"
        ui->forgotpassword->setVisible(true);
}
