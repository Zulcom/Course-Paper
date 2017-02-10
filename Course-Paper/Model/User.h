#ifndef USER_H
#define USER_H

#include<string>
#include "Book.h"
#include <vector>

class User
{
public:
	bool auth();
	User();
	User(std::string login, std::string password, int status);
	User(std::string login, std::string password);

	int getStatus() const;
	void setStatus(int status);
	std::string getPassword() const;
	std::string getLogin() const;

	std::vector<Book> getDoljen() const { return doljen; }
	void setDoljen(std::vector<Book> doljen) { this->doljen = doljen; }
private:
	std::string login;
	std::string password;
	/**
	* @brief status of user.
	* 0 is Administrator
	* 1 is Librian
	* 2 is Reader
	*/
	int status;
	// книги, которые должен пользователь
	std::vector<Book> doljen;
};
#endif // USER_H
