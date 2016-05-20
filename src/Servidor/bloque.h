#ifndef BLOQUE_H
#define BLOQUE_H

class Bloque: public Ubicable{
	public:
		Bloque(Coordenada &coordenada);
		//Agrega una coordenada a las posiciones abarcadas por un bloque.
		void agregar_coordenada(Coordenada &coordenada);
		//Intenta ubicar a un elemento ubicable en las coordenadas del mapa
		//que sean ocupadas por ese objeto, devuelve true sólo si la ubicación
		//del objeto o personaje fue realizada con éxito. 
		bool ubicar(Mapa &mapa, Coordenada &coordenada);
		//Devuelve true sólo si el ubicable recibido tiene permitido 
		//ubicarse en la misma celda.
		bool es_ubicable_con(Ubicable &ubicable);
		//Devuelve false si no puede compartir celda con ningun
		//ubicable.
		bool puede_compartir_celda();
		//Destructor del bloque.
		~Bloque();
	private:
		std::vector<Coordenada*> coordenadas; 	//Por el momento suponemos que un bloque ocupa n coordenadas porque suelen 
												//encontrarse varios "mini-bloques" juntos.
}

#endif //BLOQUE_H
