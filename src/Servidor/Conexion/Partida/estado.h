#ifndef ESTADO_H
#define ESTADO_H

#include "../../../Comun/socket.h"

class Estado{
  private:
    int comando;
    int tipo;
    int id;
    int coord_x;
    int coord_y;
	public:
		//Creador del Estado.
		Estado(int op, int t = 0, int i = 0, int x = 0, int y = 0);
		//Envia un estado.
		void enviar(Socket* skt);
};

#endif //ESTADO_H
