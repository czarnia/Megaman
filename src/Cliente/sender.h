#ifndef _SENDER_H_
#define _SENDER_H_

#include "../Comun/socket.h"
#include <map>
#include <string>

class Sender{
    private:
        Socket *skt;
    public:
        Sender(Socket *socket);
        std::map<std::string,int> commands;
        int send(std::string command, std::string option, std::string state);
};


#endif // _SENDER_H_
