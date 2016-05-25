#ifndef _SENDER_H_
#define _SENDER_H_

#include "../Comun/socket.h"
#include <map>

class Sender{
    private:
        Socket *skt;
        std::map<const char*,int> commands;
    public:
        Sender(Socket *socket);
        int send(const char* command,const char* option);
};


#endif // _SENDER_H_
