#ifndef _RESPONSE_HANDLER_H
#define _RESPONSE_HANDLER_H

#include "Renderer.h"
#include "../Comun/mutex.h"

class ResponseHandler{
    private:
        Renderer *renderer;
    public:
        ResponseHandler(Renderer *renderer);
        /// Ejecuta la accion que recibe desde el servidor
        int execute(int command, int objectType, int objectID, std::pair<int,int> coord);
        ~ResponseHandler();
};

#endif // _RESPONSE_HANDLER_H
