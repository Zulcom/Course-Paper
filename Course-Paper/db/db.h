#ifndef DB_H
#define DB_H

#include <string>
#include <vector>
#include<Model/User.h>
#include<Model/Book.h>

class DataBase
{
private:
	/**
	 * @brief type Datasase type.
	 * User is Database contains user data.
	 * Book is Database contains all staff abouЫt books.
	 */
    static int BookCounter;
public:
    DataBase();
    static int thisUserStatus;
    static int getCounter();
    static void saveAll();
    static std::vector<User> readUsersDb();
    static std::vector<Book> readBookDb();
    static bool writeUserDb(std::vector<User>& whatsWrite);
    static bool writeBookDb(std::vector<Book>& whatsWrite);
    static void addUser(User* toAdd);
    static void addBook(Book* book);
    static bool removeUser(std::string username);
    static std::vector<Book> books;
    static std::vector<User> users;
    static void loadAll();
};
#endif // DB_H
