#include "window.h"
#include "Renderer.h"
#include "Sprite.h"
#include <vector>
#include <exception>
#include "sender.h"
#include "receiver.h"
#include "../Comun/mutex.h"

#define FPS 60
#define ORIGIN_CENTERED 1
#define ORIGIN_CORNER 0
#define FONDO 1
#define FONDO_HP 2
#define HP_BAR1 3
#define HP_BAR2 4
#define HP_BAR3 5
#define HP_BAR4 6
#define MEGAMAN 7


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

int Window::get_width(){
    return width;
}

int Window::get_height(){
    return height;
}

void Window::cap_framerate(const Uint32 &starting_tick){
    if ((1000/FPS) > SDL_GetTicks() - starting_tick){
        SDL_Delay(1000/FPS - (SDL_GetTicks() - starting_tick));
    }
}

void Window::run(Socket *skt){
    Renderer renderer(window);
    Mutex mutex;

	// EN ALGUN LADO POR ACA LANZO EL THREAD QUE RECIBE LA INFORMACION DEL
	// SERVIDOR Y LE ACTUALICE LA INFORMACION AL RENDERER PARA SABER QUE
	// DIBUJAR Y DONDE HACERLO
    Sender sender(skt);
    Receiver receiver(skt, renderer, mutex);

    //FONDO
    Sprite backround(renderer.get_renderer(), "backround.jpeg");
    backround.set_Sprite(width, height, ORIGIN_CORNER, 1, 1);
    renderer.add(FONDO,&backround);
    //

    //FONDO VIDA
    Sprite hp_backround(renderer.get_renderer(), "hp_backround.jpeg");
    hp_backround.set_Sprite(width/5,height, ORIGIN_CORNER, 1, 1);
    renderer.add(FONDO_HP, &hp_backround);
    //


    //PERSONAJES
    Sprite megaman(renderer.get_renderer(), "megaman.jpeg");
    megaman.set_Sprite(40, 50, ORIGIN_CENTERED, 10, 5);
    renderer.add(MEGAMAN,&megaman);

    //VIDA
    Sprite hp_bar1(renderer.get_renderer(), "hp_bar.png");
    hp_bar1.set_Sprite(width/6, 40, ORIGIN_CORNER, 1, 1);
    hp_bar1.setPosX(10);
    hp_bar1.setPosY(height/5);
    renderer.add(HP_BAR1, &hp_bar1);

    Sprite hp_bar2(renderer.get_renderer(), "hp_bar.png");
    hp_bar2.set_Sprite(width/6, 40, ORIGIN_CORNER, 1, 1);
    hp_bar2.setPosX(10);
    hp_bar2.setPosY(2*height/5);
    renderer.add(HP_BAR2, &hp_bar2);

    Sprite hp_bar3(renderer.get_renderer(), "hp_bar.png");
    hp_bar3.set_Sprite(width/6, 40, ORIGIN_CORNER, 1, 1);
    hp_bar3.setPosX(10);
    hp_bar3.setPosY(3*height/5);
    renderer.add(HP_BAR3, &hp_bar3);

    Sprite hp_bar4(renderer.get_renderer(), "hp_bar.png");
    hp_bar4.set_Sprite(width/6, 40, ORIGIN_CORNER, 1, 1);
    hp_bar4.setPosX(10);
    hp_bar4.setPosY(4*height/5);
    renderer.add(HP_BAR4, &hp_bar4);
    //

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
                        megaman.setPosY(megaman.getPosY()-10);
                        sender.send("move", "up"); // ENVIO LA TECLA
                        break;
                    case SDLK_DOWN:
                        std::cout<<"se apreto abajo"<<std::endl;
                        megaman.setPosY(megaman.getPosY()+10);
                        sender.send("move", "down");  // ENVIO LA TECLA
                        break;
                    case SDLK_LEFT:
                        std::cout<<"se apreto izquierda"<<std::endl;
                        megaman.setPosX(megaman.getPosX()-10);
                        sender.send("move", "left");  // ENVIO LA TECLA
                        break;
                    case SDLK_RIGHT:
                        std::cout<<"se apreto derecha"<<std::endl;
                        megaman.setPosX(megaman.getPosX()+10);
                        sender.send("move", "right");  // ENVIO LA TECLA
                        break;
                    case SDLK_a:
                        std::cout<<"Se disparo"<<std::endl;
                        sender.send("attack","");  // ENVIO LA TECLA
                        break;
                    case SDLK_s:
                        std::cout<<"Se salto"<<std::endl;
                        sender.send("jump","");
                    case SDLK_1:
                        std::cout<<"Se cambio de arma 1"<<std::endl;
                        sender.send("gunChange","gun1");  // ENVIO LA TECLA
                        break;
                    case SDLK_2:
                        std::cout<<"Se cambio de arma 2"<<std::endl;
                        sender.send("gunChange","gun2");  // ENVIO LA TECLA
                        break;
                    case SDLK_3:
                        std::cout<<"Se cambio de arma 3"<<std::endl;
                        sender.send("gunChange","gun3");  // ENVIO LA TECLA
                        break;
                    case SDLK_4:
                        std::cout<<"Se cambio de arma 4"<<std::endl;
                        sender.send("gunChange","gun4");  // ENVIO LA TECLA
                        break;
                    case SDLK_5:
                        std::cout<<"Se cambio de arma 5"<<std::endl;
                        sender.send("gunChange","gun5");  // ENVIO LA TECLA
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


