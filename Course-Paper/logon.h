#ifndef LOGON_H
#define LOGON_H

#include <QDialog>

namespace Ui {
class Logon;
}

class Logon : public QDialog
{
    Q_OBJECT

public:
    /*
    Explisit запрещает явно преобразовывать аргумент к конструктору.
    К примеру, при такой записи Класс имяобъекта = число; Explisit запретит вызов конструктора с типом int.
    Это введено для запрета преобразований наследуемых классов при вызове конструктора.
    */
    explicit Logon(QWidget *parent = 0);
    ~Logon();

private slots:
    void on_loginButton_clicked(); // слот нажатия на кнопку логин

private:
    Ui::Logon *ui;
};

#endif // LOGON_H
