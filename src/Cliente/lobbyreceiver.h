#ifndef LOBBYRECEIVER_H
#define LOBBYRECEIVER_H

#include "../Comun/hilo.h"
#include "../Comun/socket.h"
#include "../Comun/mutex.h"
#include "Renderer.h"
#include <queue>

class LobbyReceiver: public Hilo{
    private:
        Socket* skt;
        Renderer *renderer;
        Mutex *mutex;
        bool stop;
    public:
        std::queue<int> r_queue;
        ///Crea un receiver recibiendo como parametro un socket ya conectado.
        LobbyReceiver(Socket* conexion, Renderer *renderer,
                    Mutex *mutex);
        ///"Ciclo" del receiver, recibe informacion del servidor hasta que el mismo
        ///le indica el fin de la ejecucion.
        void ejecutar();
        ~LobbyReceiver();
};

#endif //RECEIVER_H

