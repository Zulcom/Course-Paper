#include <string>
#include <db/db.h>
class User{
private:
    std::string login;
    std::string password;
    /**
     * @brief status Status of user.
     * 0 is Administrator
     * 1 is Librian
     * 2 is Reader
     */
    int status;
public:
    int auth(std::string login,std::string pass);
    User(std::string login, std::string password);
    int getStatus();
    void setStatus(int status);
};
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
    DataBase usersdb = new DataBase("User","Users");
    std::vector<User> users = usersdb.readUsersDb();
    std::vector<User>::iterator it =
            std::find_if(users.begin(), users.end(),
                         [password](User const &n){ return (n.login == login && n.password == pass;}
            );
    if(it != users.end() )
        return 1;
    else
        return 0;
}
