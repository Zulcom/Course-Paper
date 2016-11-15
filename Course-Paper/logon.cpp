#include "logon.h"
#include "ui_logon.h"
#include "algorithm/User.h"
#include "search.h"
Logon::Logon(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Logon){
    ui->setupUi(this);
    ui->forgotpassword->setVisible(false);
   QPixmap pix("img/user.png");
   ui->logonImg->setPixmap(pix);
   connect(ui->loginButton,SIGNAL(clicked()),this,SLOT(on_loginButton_clicked()));
}

Logon::~Logon()
{
    delete ui;
}

void Logon::on_loginButton_clicked() // слот нажатия на кнопку логина
{
    if(User::auth(ui->username->text().toStdString(),ui->password->text().toStdString())){
        search *sh = new search(this);
        emit close();
        sh->show();
    }
    else ui->forgotpassword->setVisible(true); ;
}
