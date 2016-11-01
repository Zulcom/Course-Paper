#ifndef USER_H
#define USER_H
#include<string>
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
    static int auth(std::string login,std::string pass);
    User(std::string login, std::string password);
    int getStatus();
    void setStatus(int status);
};
#endif // USER_H

