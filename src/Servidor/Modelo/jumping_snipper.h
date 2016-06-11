#ifndef JUMPING_SNIPPER_H
#define JUMPING_SNIPPER_H

class JumpingSnipper : public Snipper {
	private:
		StrategyMoverJumpingSnipper salto_snipper;
		Arma_minion* arma;
	public:
		JumpingSnipper(Mapa *mapa, Coordenada c, Arma_minion* arma, int id);
		//Le hace un update al personaje.
		virtual void update(size_t tiempo, Mapa* mapa);
};

#endif //JUMPING_SNIPPER_H
