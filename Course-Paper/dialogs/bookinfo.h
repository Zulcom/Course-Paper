#ifndef BOOKINFO_H
#define BOOKINFO_H

#include <QDialog>
#include<QModelIndexList>
#include <Model/Book.h>
#include <string>
#include <Model/User.h>

namespace Ui
{
	class bookInfo;
}

class bookInfo : public QDialog
{
	Q_OBJECT

public:
	explicit bookInfo(QWidget* parent = 0);
	~bookInfo();
	void setData(Book book, std::string holder);

private slots:
	void on_returnBookButton_clicked();

	void on_buttons_rejected();

	void on_buttons_accepted();

private:
	Ui::bookInfo* ui;
	QModelIndexList selection;
	int bookid;
	User holder;
};

#endif // BOOKINFO_H
