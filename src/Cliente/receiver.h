#ifndef RECEIVER_H
#define RECEIVER_H

#include "../Comun/socket.h"
#include "Renderer.h"

class Receiver{
    private:
        Socket* skt;
        Renderer *renderer;
        bool *victory;
        bool *ko;
    public:
        ///Crea un receiver recibiendo como parametro un socket ya conectado.
        Receiver(Socket* conexion, Renderer *renderer,
                    bool *victory, bool *ko);
        /// Recibo bloques, minions, escaleras, puas etc...
        void receiveMap();
        /// Cuando empieza la partida se recibe el tamanio del mapa
        void receiveMapSize();
        ///"Ciclo" del receiver, recibe informacion del servidor hasta que el mismo
        ///le indica el fin de la ejecucion.
        void update(bool *running);
        ~Receiver();
};

#endif //RECEIVER_H
