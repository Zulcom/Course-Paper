#include <string>
#include <Model/User.h>
#include <db/db.h>
#include <algorithm>
#include "sha256/sha256.h"
#include <fstream>

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
    DataBase::loadAll();
	/*
	 Поиск ползователя в векторе по лямбда-выражению
	*/
	std::string thisLogin = login, thisPassword = password;
	std::vector<User>::iterator it =
            std::find_if(DataBase::users.begin(), DataBase::users.end(),
			             [thisLogin,thisPassword](User const& n) { return n.login == thisLogin && n.password.compare(sha256(thisPassword)) == 0; });
    DataBase::thisUserStatus = (*it).status;
    return (it != DataBase::users.end());

}




// Getters & Setters
std::string User::getPassword() const { return password; }
std::string User::getLogin() const { return login; }
int User::getStatus() const { return this->status; }

void User::setStatus(int status) {
	this->status = status;
}
