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
	std::string type;
	std::string name;

public:
	DataBase(std::string type, std::string name);
	static std::vector<User> readUsersDb();
	static std::vector<Book> readBookDb();
	static bool writeUserDb(std::vector<User> whatsWrite);
	static bool writeBookDb(std::vector<Book> whatsWrite);
};
#endif // DB_H
