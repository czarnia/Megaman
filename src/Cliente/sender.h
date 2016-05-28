#ifndef _SENDER_H_
#define _SENDER_H_

#include "../Comun/socket.h"
#include <map>
#include <string>

class Sender{
    private:
        Socket *skt;
        std::map<std::string,int> commands;
    public:
        Sender(Socket *socket);
        int send(std::string command, std::string option);
};


#endif // _SENDER_H_
