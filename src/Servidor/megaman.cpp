#include "megaman.h"

Megaman::Megaman(Mapa *mapa, Coordenada *c, std::string id):
Personaje(mapa, c, id){}

void Megaman::atacar(){}
void Megaman::update(size_t tiempo){}
void Megaman::recibir_ataque(/*Bala ataque*/){}
