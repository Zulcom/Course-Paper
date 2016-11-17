#include <string>
#include <Model/User.h>
#include <db/db.h>
#include <algorithm>
#include "sha256/sha256.h"
#include <fstream>
int User::getStatus(){
	return this->status;
}
void User::setStatus(int status){
	this->status=status;
}

User::User(std::string login,std::string password){
	this->login=login;
	this->password=password;
}
int User::auth(std::string login, std::string pass){
	DataBase * usersdb = new DataBase("User","Users");
	std::vector<User> users = usersdb->readUsersDb();
    /*
     Поиск ползователя в векторе по лямбда-выражению
    */
	std::vector<User>::iterator it =
			std::find_if(users.begin(), users.end(),
	[login,pass](User const &n){ return n.login == login && n.password.compare(sha256(pass)) == 0;});
	if(it != users.end() )
		return 1;
	else
        return 0;
}
