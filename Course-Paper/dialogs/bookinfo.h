#ifndef BOOKINFO_H
#define BOOKINFO_H

#include <QDialog>
#include<QModelIndexList>

namespace Ui {
class bookInfo;
}

class bookInfo : public QDialog
{
    Q_OBJECT

public:
    explicit bookInfo(QWidget *parent = 0);
    ~bookInfo();

private:
    Ui::bookInfo *ui;
    QModelIndexList selection;
};

#endif // BOOKINFO_H
