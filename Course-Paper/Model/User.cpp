#include <string>
#include <Model/User.h>
#include <db/db.h>
#include <algorithm>
#include "sha256/sha256.h"
#include <fstream>
int User::thisStatus = 2;

User::User(std::string login, std::string password, int status) {
	this->login = login;
	this->password = password;
	this->status = status;
}

User::User(std::string login, std::string password) {
	this->login = login;
	this->password = password;
	this->status = 2;
}

User::User() {
	this->login = "NULL";
	this->password = "NULL";
	this->status = 2;
}

bool User::auth() {
	DataBase* usersdb = new DataBase("User", "Users");
	std::vector<User> users = usersdb->readUsersDb();
	/*
	 Поиск ползователя в векторе по лямбда-выражению
	*/
	std::string thisLogin = login, thisPassword = password;
	std::vector<User>::iterator it =
			std::find_if(users.begin(), users.end(),
			             [thisLogin,thisPassword](User const& n) { return n.login == thisLogin && n.password.compare(sha256(thisPassword)) == 0; });
	this->thisStatus = (*it).status;
	return (it != users.end());

}

bool User::addUser(User toAdd) {
	DataBase* usersdb = new DataBase("User", "Users");
	std::vector<User> users = usersdb->readUsersDb();
	users.push_back(toAdd);
	bool res = usersdb->writeUserDb(users);
	return res;
}

bool User::remove(std::string username) {
	DataBase* usersdb = new DataBase("User", "Users");
	std::vector<User> users = usersdb->readUsersDb();
	std::vector<User>::iterator it =
			std::find_if(users.begin(), users.end(),
			             [username](User const& n) { return n.login == username; });
	if (it != users.end())
	{
		users.erase(it);
		return usersdb->writeUserDb(users);
	}
	// данный юзер не найден
	else return false;
}

// Getters & Setters
std::string User::getPassword() const { return password; }
std::string User::getLogin() const { return login; }
int User::getStatus() const { return this->status; }

void User::setStatus(int status) {
	this->status = status;
}
