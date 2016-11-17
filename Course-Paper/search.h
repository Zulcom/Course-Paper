#ifndef SEARCH_H
#define SEARCH_H

#include <QMainWindow>
#include <string>
namespace Ui {
class search;
}

class search : public QMainWindow
{
    Q_OBJECT

public:
    explicit search(QWidget *parent = 0);
    ~search();
private slots:
    void pullRows(int); // заполнение таблицы
private:
    Ui::search *ui;

};

#endif // SEARCH_H
