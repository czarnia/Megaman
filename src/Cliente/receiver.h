#ifndef RECEIVER_H
#define RECEIVER_H

#include "../Comun/hilo.h"
#include "../Comun/socket.h"
#include "../Comun/mutex.h"
#include "event.h"
#include "Renderer.h"
#include <queue>

class Receiver: public Hilo{
    private:
        Socket* skt;
        Renderer *renderer;


        Mutex *mutex;
    public:
        std::queue<Event*> r_queue;
        ///Crea un receiver recibiendo como parametro un socket ya conectado.
        Receiver(Socket* conexion, Renderer *renderer,
                    Mutex *mutex);
        /// Recibo bloques, minions, escaleras, puas etc...
        void receiveMap();
        /// Cuando empieza la partida se recibe el tamanio del mapa
        void receiveMapSize();
        ///"Ciclo" del receiver, recibe informacion del servidor hasta que el mismo
        ///le indica el fin de la ejecucion.
        void ejecutar();
        ~Receiver();
};

#endif //RECEIVER_H
