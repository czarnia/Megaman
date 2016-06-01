#include "main_menu.h"
#include "gameState.h"

MainMenu::MainMenu(SDL_Window *window, Renderer *renderer):
    window(window),
    renderer(renderer)
{
    start = false;
    quit = false;
    load();
}

void MainMenu::updateInput(){
    SDL_Event event;
    while (SDL_PollEvent(&event)){
        if (event.type == SDL_QUIT){
            quit = true;
        }else if (event.type == SDL_KEYDOWN){
            switch (event.key.keysym.sym){
                case SDLK_RETURN:
                    start = true;
                    break;
                default:
                    break;
            }
        }
    }
}

void MainMenu::load(int stack){
    Sprite *spr = new Sprite(renderer->get_renderer(), "menu_backround.jpeg");
    spr->set_Sprite(640,480,1,1);
    sprites.push_back(spr);
    renderer->add(0,*(sprites.end()-1));
}

int MainMenu::unload(){
    std::vector<Sprite*>::iterator it = sprites.begin();
    for(; it != sprites.end(); ++it)
        delete (*it);
    sprites.clear();
    renderer->clearSprites();
    return 0;
}

GameState::StateCode MainMenu::update(){
    updateInput();

    if (start){
       // start = false;
        return GameState::BOSS_SELECT;
    }else if (quit){
        return GameState::QUIT;
    }else{
        return GameState::CONTINUE;
    }
}

void MainMenu::render(){
    renderer->clear();
    renderer->drawAll();
    renderer->present();
}

MainMenu::~MainMenu(){
    unload();
}
