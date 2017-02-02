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
    static bool add(Book book);
	static void setCounter(int c);
	static int getCounter();
    enum // ������� �������
    {
        TITLE,
        AUTHOR,
        PAGESCOUNT,
        PRICE,
        DATE
    };

private:
	static int counter;
    std::string title;
    std::string author;
    int pagecount;
    int price;
    std::string date;
    int id;
};
#endif // BOOK_H
