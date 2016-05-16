#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include <iostream>
#include <vector>

#define FPS 60
#define WIDTH 640
#define HEIGHT 480

void cap_framerate(const Uint32 &starting_tick){
    if ((1000/FPS) > SDL_GetTicks() - starting_tick){
        SDL_Delay(1000/FPS - (SDL_GetTicks() - starting_tick));
    }
}


class Surface{
    private:
        SDL_Surface *s;
    public:
        Surface(SDL_Window *w){
            s = SDL_GetWindowSurface(w);
        }
        SDL_Surface* get_surface(){
            return s;
        }

        ~Surface(){
           // SDL_FreeSurface(s);
        }
};

int main(int argc, char **argv){

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = NULL;
    window = SDL_CreateWindow("Hello world!",
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                WIDTH,
                                HEIGHT,
                                SDL_WINDOW_RESIZABLE);

    if(window == NULL){
        std::cout<<"Hubo un error inicilizando"<<std::endl;
        std::cout<< SDL_GetError()<<std::endl;
    }

    Surface screen(window);

    // COLORES
    Uint32 white = SDL_MapRGB(screen.get_surface()->format, 255,255,255);
    Uint32 red = SDL_MapRGB(screen.get_surface()->format, 255, 0, 0);
    Uint32 blue = SDL_MapRGB(screen.get_surface()->format, 0, 0, 255);
    Uint32 green = SDL_MapRGB(screen.get_surface()->format, 0, 255, 0);
    Uint32 a = SDL_MapRGB(screen.get_surface()->format, 0, 255, 255);
    Uint32 b = SDL_MapRGB(screen.get_surface()->format, 255, 255, 0);
    Uint32 c = SDL_MapRGB(screen.get_surface()->format, 255, 0, 255);
    Uint32 d = SDL_MapRGB(screen.get_surface()->format, 0, 0, 0);
    Uint32 e = SDL_MapRGB(screen.get_surface()->format, 150, 0, 255);
    Uint32 f = SDL_MapRGB(screen.get_surface()->format, 10, 200, 125);
    Uint32 g = SDL_MapRGB(screen.get_surface()->format, 10, 150, 255);

 //   SDL_FillRect(screen.get_surface(), NULL, white);


    Uint32 starting_tick;
    SDL_Event event;
    bool running = true;
    // LOOP PRINCIPAL DEL PROGRAMA
    while (running){
        // IGNORAR ESTO
        starting_tick = SDL_GetTicks();
        // SI HAY ALGUN EVENTO EN LA COLA LO PROCESO
        while (SDL_PollEvent(&event)){
            // EL EVENTO FUE SALIR CORTO EL LOOP
            if (event.type == SDL_QUIT){
                running = false;
                break;
            // EL EVENTO ES UNA TECLA
            }else if (event.type == SDL_KEYDOWN){
                switch(event.key.keysym.sym){
                    case SDLK_1:
                        SDL_FillRect(screen.get_surface(), NULL, white);
                        break;
                    case SDLK_2:
                        SDL_FillRect(screen.get_surface(), NULL, a);
                        break;
                    case SDLK_3:
                        SDL_FillRect(screen.get_surface(), NULL, b);
                        break;
                    case SDLK_4:
                        SDL_FillRect(screen.get_surface(), NULL, c);
                        break;
                    case SDLK_5:
                        SDL_FillRect(screen.get_surface(), NULL, d);
                        break;
                    case SDLK_UP:
                        SDL_FillRect(screen.get_surface(), NULL, blue);
                        break;
                    case SDLK_DOWN:
                        SDL_FillRect(screen.get_surface(), NULL, e);
                        break;
                    case SDLK_LEFT:
                        SDL_FillRect(screen.get_surface(), NULL, f);
                        break;
                    case SDLK_RIGHT:
                        SDL_FillRect(screen.get_surface(), NULL, g);
                        break;
                    case SDLK_a:
                        SDL_FillRect(screen.get_surface(), NULL, green);
                        break;
                }
            }
        }
        SDL_UpdateWindowSurface(window);
        // LIMITA LOS FPS PARA NO SOBRECARGAR EL CPU
        cap_framerate(starting_tick);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
