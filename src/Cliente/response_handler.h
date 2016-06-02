#ifndef _RESPONSE_HANDLER_H
#define _RESPONSE_HANDLER_H

#include "Renderer.h"
#include "../Comun/mutex.h"

class ResponseHandler{
    private:
        Renderer &renderer;
        Mutex &mutex;
    public:
        ResponseHandler(Renderer &renderer, Mutex &mutex);
        int execute(int command, int option, std::pair<int,int> coord);
        ~ResponseHandler();
};

#endif // _RESPONSE_HANDLER_H
