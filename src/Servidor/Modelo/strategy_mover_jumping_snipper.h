#ifndef STRATEGY_MOVER_JUMPING_SNIPPER_H
#define STRATEGY_MOVER_JUMPING_SNIPPER_H

class StrategyMoverJumpingSnipper : public StrategyMover{
	protected:
		int direccion;
		size_t tiempo_pasado;
		bool flotando;
	public:
		virtual void mover(Mapa *mapa, Personaje *pj, size_t tiempo);
		
		friend class StrategyMoverJumpingSnipper;	
};

#endif //STRATEGY_MOVER_JUMPING_SNIPPER_H

