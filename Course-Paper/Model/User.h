#ifndef USER_H
#define USER_H

#include<string>

class User
{
public:
	bool auth();
	User(std::string login, std::string password, int status);
	User(std::string login, std::string password);
	static bool addUser(User toAdd);
	static bool remove(std::string username);
	int getStatus() const;
	void setStatus(int status);
	std::string getPassword() const;
	std::string getLogin() const;

        static int thisStatus;
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
};
#endif // USER_H
