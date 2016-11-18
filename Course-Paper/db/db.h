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
	 * Book is Database contains all staff about books.
	 */
	std::string type;
	std::string name;

public:
	DataBase(std::string type,std::string name);
	std::vector<User> readUsersDb();
	std::vector<Book> readBookDb();
    bool writeUserDb(std::vector<User> whatsWrite);

};
#endif // DB_H
