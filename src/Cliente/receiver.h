#ifndef RECEIVER_H
#define RECEIVER_H

#include "../Comun/hilo.h"
#include "../Comun/socket.h"
#include "../Comun/mutex.h"
#include "Renderer.h"

class Receiver: public Hilo{
    private:
        Socket* skt;
        Renderer &renderer;
        Mutex &mutex;
        bool *running;
        bool *victory;
        bool *ko;
    public:
        ///Crea un receiver recibiendo como parametro un socket ya conectado.
        Receiver(Socket* conexion, Renderer &renderer,
                    Mutex &mutex, bool *running,
                    bool *victory, bool *ko);
        /// Recibo bloques, minions, escaleras, puas etc...
        void receiveMap();
        /// Cuando empieza la partida se recibe el tamanio del mapa
        void receiveMapSize();
        ///"Ciclo" del receiver, recibe informacion del servidor hasta que el mismo
        ///le indica el fin de la ejecucion.
        virtual void ejecutar();
};

#endif //RECEIVER_H
