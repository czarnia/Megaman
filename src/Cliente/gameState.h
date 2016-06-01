#ifndef GAMESTATE_H_DEFINED
#define GAMESTATE_H_DEFINED

class GameState{
    public:
        /// Para devolver en update()
        enum StateCode{
            MAIN_MENU, BOSS_SELECT, GAME_START, CONTINUE, QUIT, GAME_OVER, VICTORY
        };

        virtual ~GameState(){}

        /// Inicializa todo lo que el stado de juego necesite
        virtual void load(int stack=0) = 0;

        /// Destruye todo lo relacionado con el estado de juego actual
        virtual int unload() = 0;

        /// Se llama en el loop principla, siver para cambiar de estados de juego
        virtual StateCode update() = 0;

};

#endif //GAMESTATE_H_DEFINED
