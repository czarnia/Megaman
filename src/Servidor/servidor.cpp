#include "servidor.h"

#include <map>
#include <string>

//--------------->Auxiliares<---------------//
std::vector<std::string> obtener_claves(std::map<std::string,
                                                Conexion_cliente*> hash){
  std::vector<std::string> v;
  std::map<std::string,Conexion_cliente*>::iterator i;
  for (i = hash.begin(); i != hash.end(); i++){
    v.push_back(i->first);
  }
  return v;
}
//------------------------------------------//


Servidor::Servidor(){
  skt.bind(NULL, puerto);
  skt.listen(MAX_CONEXIONES);
}

Servidor::~Servidor(){
  std::vector<std::string> claves_clientes = obtener_claves(clientes);
  for (size_t i = 0; i < claves_clientes.size(); i++){
    Conexion_cliente* cliente = clientes[claves_clientes[i]];
    clientes.erase(claves_clientes[i]);
    cliente.join();
    delete cliente;
  }
}

void Servidor::aceptar_clientes(){
  char* addr_aceptado = malloc(sizeof(struct sockaddr));
  Socket* aceptado = skt.accept(addr_aceptado);
  std::string id(addr_aceptado->sa_data);
  server.agregar_cliente(aceptado, id);
  free(addr_aceptado);

  skt.shutdown(SHUT_RDWR);
}

void Servidor::agregar_cliente(Socket* cliente_nuevo, std::string id_cliente){
  clientes[id_cliente] = new Conexion_cliente(cliente_nuevo);
  clientes[id_cliente].start();
}
