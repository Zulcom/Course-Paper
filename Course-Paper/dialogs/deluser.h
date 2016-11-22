#ifndef DELUSER_H
#define DELUSER_H

#include <QDialog>

namespace Ui {
class delUser;
}

class delUser : public QDialog
{
    Q_OBJECT

public:
    explicit delUser(QWidget *parent = 0);
    ~delUser();
    void accept();
private slots:

    void on_delUserButton_clicked();

private:
     QString boxtitile = "Удаление пользователя";
    Ui::delUser *ui;
};

#endif // DELUSER_H
