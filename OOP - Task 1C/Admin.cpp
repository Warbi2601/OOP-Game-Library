#include "Admin.h"

Admin::Admin(const std::string& username, const std::string& password, const Date& created, double& credits, List<Player*>friends) : Player(username, password, created, credits, friends)
{
}

Admin::~Admin()
{
}