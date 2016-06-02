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
        /// Doble funcion, primero convierte la accion a el protocolo de
        /// comunicacion correspondiente y luego lo envia al servidor
        int send(std::string command, std::string option);
};


#endif // _SENDER_H_
