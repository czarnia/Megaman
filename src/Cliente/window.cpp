#include "window.h"
#include "Renderer.h"
#include "Sprite.h"
#include <vector>
#include <exception>
#include "sender.h"

#define FPS 60
#define ORIGIN_CENTERED 1
#define ORIGIN_CORNER 0
#define MEGAMAN_HEALTH 100
#define MEGAMAN_SPEED 10
#define DAMAGE 10
#define BULLET_SPEED 20

Window::Window(int width, int height): width(width), height(height){
    window = NULL;
    window = SDL_CreateWindow("Main menu",
                                SDL_WINDOWPOS_UNDEFINED, // POS X
                                SDL_WINDOWPOS_UNDEFINED, // POS Y
                                width,
                                height,
                                SDL_WINDOW_SHOWN);
	//TODO: manejar con excepcion!
    if (window == NULL){
        std::cout<<"Error al crear ventana"<<std::endl;
    }
}

void Window::cap_framerate(const Uint32 &starting_tick){
    if ((1000/FPS) > SDL_GetTicks() - starting_tick){
        SDL_Delay(1000/FPS - (SDL_GetTicks() - starting_tick));
    }
}

void Window::run(Socket *skt){
    Renderer renderer(window);

	// EN ALGUN LADO POR ACA LANZO EL THREAD QUE RECIBE LA INFORMACION DEL
	// SERVIDOR Y LE ACTUALICE LA INFORMACION AL RENDERER PARA SABER QUE
	// DIBUJAR Y DONDE HACERLO
    Sender sender(skt);

	// POR AHORA DIBUJO COSAS A MANO PARA QUE VEAN COMO FUNCIONA
    // FONDO
	// PRIMERO CARGO LA TEXTURA DE ALGUN ARCHIVO EXTERNO DIRECTAMENTE EN EL
	// CONSTRUCTOR DE SPRITE
    Sprite backround(renderer.get_renderer(), "backround.jpeg");
	// LUEGO ESTABLEZCO LA POSICION INICIAL, ANCHO Y ALTO DE LO QUE VOY A DIBUJAR
	// EN ESTE CASO COMO ES EL FONDO, CUBRO TODA LA PANTALLA
	// ORIGIN_CORNER ES UN FLAG PARA SABER QUE PUNTO TOMO COMO ORIGEN DE LA FIGURA
	// POR AHORA IGNORAR LOS ULTIMOS 2 PARAMETROS
    backround.set_Sprite(0, 0, width, height, ORIGIN_CORNER, 1, 1);
	// POR ULTIMO TENGO QUE AGREGAR LA NUEVA FIGURA AL RENDERER PARA QUE ESTE
	// LA PUEDA DIBUJAR
    renderer.add(&backround);
    //

    //PERSONAJES
    Sprite megaman(renderer.get_renderer(), "megaman.gif");
    megaman.set_Sprite(15, height-25, 40, 50, ORIGIN_CENTERED, 10, 5);
    renderer.add(&megaman);


    Uint32 starting_tick;
    SDL_Event event;
    bool running = true;
    // LOOP PRINCIPAL
	while (running){
        starting_tick = SDL_GetTicks();
		while (SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT){
                running = false;
                break;
            }else if (event.type == SDL_KEYDOWN){
                switch (event.key.keysym.sym){
                    case SDLK_UP:
                        std::cout<<"se apreto arriba"<<std::endl;
                        megaman.setPosY(megaman.getPosY()-5);
                        sender.send("move", "up");
                        // ACA ENVIO AL SERVIDOR LA INFO DE LA TECLA
                        break;
                    case SDLK_DOWN:
                        std::cout<<"se apreto abajo"<<std::endl;
                        megaman.setPosY(megaman.getPosY()+5);
                        sender.send("move", "down");
                        // ACA ENVIO AL SERVIDOR LA INFO DE LA TECLA
                        break;
                    case SDLK_LEFT:
                        std::cout<<"se apreto izquierda"<<std::endl;
                        megaman.setPosX(megaman.getPosX()-5);
                        sender.send("move", "left");
                        // ACA ENVIO AL SERVIDOR LA INFO DE LA TECLA
                        break;
                    case SDLK_RIGHT:
                        std::cout<<"se apreto derecha"<<std::endl;
                        megaman.setPosX(megaman.getPosX()+5);
                        sender.send("move", "right");
                        // ACA ENVIO AL SERVIDOR LA INFO DE LA TECLA
                        break;
                    case SDLK_a:
                        std::cout<<"Se disparo"<<std::endl;
                        sender.send("attack","");
                        // ACA ENVIO AL SERVIDOR LA INFO DE LA TECLA
                        break;
                    case SDLK_1:
                        std::cout<<"Se cambio de arma"<<std::endl;
                        sender.send("gunChange","gun1");
                        // ACA ENVIO AL SERVIDOR LA INFO DE LA TECLA
                        break;
                    case SDLK_2:
                        std::cout<<"Se cambio de arma"<<std::endl;
                        sender.send("gunChange","gun2");
                        // ACA ENVIO AL SERVIDOR LA INFO DE LA TECLA
                        break;
                    case SDLK_3:
                        std::cout<<"Se cambio de arma"<<std::endl;
                        sender.send("gunChange","gun3");
                        // ACA ENVIO AL SERVIDOR LA INFO DE LA TECLA
                        break;
                    case SDLK_4:
                        std::cout<<"Se cambio de arma"<<std::endl;
                        sender.send("gunChange","gun4");
                        // ACA ENVIO AL SERVIDOR LA INFO DE LA TECLA
                        break;
                    case SDLK_5:
                        std::cout<<"Se cambio de arma"<<std::endl;
                        sender.send("gunChange","gun5");
                        // ACA ENVIO AL SERVIDOR LA INFO DE LA TECLA
                        break;
                    default:
                        break;
                }
            }
		}

		//ACTUALIZO TEXTURAS
		cap_framerate(starting_tick);
        renderer.clear();
        renderer.drawAll();
        renderer.present();
	}
}

Window::~Window(){
    SDL_DestroyWindow(window);
}

SDL_Window* Window::get_window(){
    return window;
}

