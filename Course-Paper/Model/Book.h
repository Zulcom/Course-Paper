#ifndef BOOK_H
#define BOOK_H
#include<string>

//
class Book
{
public:
	Book(const int id,
	     const std::string& title,
	     const std::string& author,
	     const int pagecount,
	     const int price,
	     const std::string& date);
	// getters
	std::string getTitle() const;
	std::string getAuthor() const;
	int getpageCount() const;
	int getPrice() const;
	int getid() const;
	std::string getDate() const;
	void setTitle(const std::string title) { this->title = title; }

	void setAuthor(const std::string author) { this->author = author; }

	void setPageCount(const int pagecount) { this->pagecount = pagecount; }

	void setPrice(const int price) { this->price = price; }

	void setDate(const std::string date) { this->date = date; }

	void setId(const int id) { this->id = id; }

	enum // столбцы таблицы
	{
		TITLE,
		AUTHOR,
		PAGESCOUNT,
		PRICE,
		DATE
	};

private:
	std::string title;
	std::string author;
	int pagecount;
	int price;
	std::string date;
	int id;
};
#endif // BOOK_H
