#include "gameStateEditor.h"
#include "../Cliente/Sprite.h"
#include "../Cliente/block_sprite.h"
#include "../Cliente/character_sprite.h"
#include <iostream>
#include <fstream>

#define BLOCK_EARTH 100
#define BLOCK_SPIKE 1000
#define BLOCK_STAIR 1500
#define MEGAMANN 1
#define METN 8
#define CAM_SPEEDX 20

#define PBLOCK_EARTH 10
#define PBLOCK_SPIKE 11
#define PBLOCK_STAIR 12
#define PMEGAMAN 1
#define PMET 8

gameStateEditor::gameStateEditor(Window *window, Renderer* renderer):
    window(window),
    renderer(renderer)
{
    window->setTitle("Megaman: Level editor");
    object = gameStateEditor::NOTHING;
    load();
}

void gameStateEditor::chooseBlock(SDL_Event *event){
    switch(event->key.keysym.sym){
        case SDLK_b:/// BLOQUE
            object = gameStateEditor::BLOCK;
            std::cout<<"Se eligio un blocke"<<std::endl;
            break;
        case SDLK_s:/// PUAS
            object = gameStateEditor::SPIKES;
            std::cout<<"Se eligio puas"<<std::endl;
            break;
        case SDLK_e:/// ESCALERA
            object = gameStateEditor::STAIR;
            std::cout<<"Se eligio escalera"<<std::endl;
            break;
        case SDLK_m:/// MEGAMAN
            object = gameStateEditor::MEGAMAN;
            std::cout<<"Se eligio megaman"<<std::endl;
            break;
        case SDLK_1: /// MET
            object = gameStateEditor::MET;
            std::cout<<"Se eligio un met"<<std::endl;
            break;
        default:
            break;
    }
}

void gameStateEditor::updateInput(SDL_Event *event){
    Sprite *spr;
    if ( event->button.button == SDL_BUTTON_LEFT && object != gameStateEditor::NOTHING){
        int x = (event->button.x + renderer->camX)/Block_sprite::width*Block_sprite::width;
        int y = (event->button.y + renderer->camY)/Block_sprite::height*Block_sprite::height;

        switch(object){
            case gameStateEditor::BLOCK:
                if (!renderer->ocupied(x,y)){
                    spr = new Block_sprite(renderer->get_renderer(), "../sprites/block.png");
                    spr->setPosX(x);
                    spr->setPosY(y);
                    renderer->addMapSprite(BLOCK_EARTH, spr);
                }
                break;
            case gameStateEditor::SPIKES:
                if (!renderer->ocupied(x,y)){
                    spr = new Block_sprite(renderer->get_renderer(), "../sprites/spike.gif");
                    spr->setPosX(x);
                    spr->setPosY(y);
                    renderer->addMapSprite(BLOCK_SPIKE, spr);
                }
                break;
            case gameStateEditor::STAIR:
                if (!renderer->ocupied(x,y)){
                    spr = new Block_sprite(renderer->get_renderer(), "../sprites/ladder.png");
                    spr->setPosX(x);
                    spr->setPosY(y);
                    renderer->addMapSprite(BLOCK_STAIR, spr);
                }
                break;
            case gameStateEditor::MEGAMAN:
                if (!renderer->ocupied(x,y) && !renderer->ocupied(x,y+Block_sprite::width)){
                    if(renderer->find(MEGAMANN)){
                        std::cout<< "Ya se coloco un megaman"<<std::endl;
                    }else{
                        spr = new Character_sprite(renderer->get_renderer(), "../sprites/megaman.png");
                        spr->setPosX(x);
                        spr->setPosY(y);
                        renderer->addSprite(MEGAMANN, spr);
                    }
                }
                break;
            case gameStateEditor::MET:
                if (!renderer->ocupied(x,y)){
                    spr = new Block_sprite(renderer->get_renderer(), "../sprites/met.png");
                    spr->setPosX(x);
                    spr->setPosY(y);
                    renderer->addSprite(METN, spr);
                }
                break;
            default:
                break;
        }
    }else if (event->button.button == SDL_BUTTON_RIGHT){
        int x = (event->button.x + renderer->camX)/Block_sprite::width*Block_sprite::width;
        int y = (event->button.y + renderer->camY)/Block_sprite::width*Block_sprite::width;
        if(renderer->ocupied(x,y)){
            renderer->erase(x,y);
        }
    }
}

void gameStateEditor::load(int stack){

}

int gameStateEditor::unload(){
    return 0;
}

void gameStateEditor::updateCameraPos(SDL_Event *event){
    switch(event->key.keysym.sym){
        case SDLK_LEFT:
            if (renderer->camX > 0)
                renderer->camX -= CAM_SPEEDX;
            else
                renderer->camX = 0;
            break;
        case SDLK_RIGHT:
            renderer->camX += CAM_SPEEDX;
            break;
        default:
            break;
    }
}

GameState::StateCode gameStateEditor::update(){
    SDL_Keysym pressed;
    SDL_Event event;
    while (SDL_PollEvent(&event)){

        if (event.type == SDL_QUIT){
            return GameState::QUIT;
            break;

        }else if (event.type == SDL_KEYDOWN){
            pressed.sym = event.key.keysym.sym;
            if( pressed.sym == SDLK_UP || pressed.sym == SDLK_DOWN ||
                pressed.sym == SDLK_LEFT || pressed.sym == SDLK_RIGHT)
                updateCameraPos(&event);
            else
                chooseBlock(&event);

        }else if (event.type == SDL_MOUSEBUTTONDOWN){
            updateInput(&event);
        }
    }
    return GameState::CONTINUE;
}

void gameStateEditor::render(){
    renderer->clear();
    renderer->drawAll();
    renderer->present();
}

void gameStateEditor::exportMap(){
    std::string fileName;
    std::ofstream ofile;
    std::cout<<"Ingrese un nombre para el nuevo mapa:"<<std::endl;
    int block_type;
    int char_type;
    std::cin>>fileName;
    ofile.open(fileName.c_str());

    std::map<int,Sprite*>::iterator it;
    it = renderer->map_sprites.begin();

    for (; it != renderer->map_sprites.end(); ++it){

        if (it->first < BLOCK_SPIKE)
            block_type = PBLOCK_EARTH;
        else if (it->first > BLOCK_SPIKE && it->first < BLOCK_STAIR)
            block_type = PBLOCK_SPIKE;
        else
            block_type = PBLOCK_STAIR;

        ofile << block_type << " ";
        ofile << it->second->getPosX() + Block_sprite::width/2<< " ";
        ofile << it->second->getPosY() + Block_sprite::height/2<< " ";
        ofile << std::endl;
    }

    it = renderer->sprites.begin();
    for (; it != renderer->sprites.end(); ++it){

        if (it-> first == MEGAMANN)
            char_type = PMEGAMAN;
        else if (it->first == METN)
            char_type = PMET;
        else {}

        ofile << char_type << " ";
        if (char_type == PMEGAMAN){
            ofile << it->second->getPosX() + Block_sprite::width/2<< " ";
            ofile << it->second->getPosY() + Block_sprite::height<< " ";
            ofile << std::endl;
        }else{
            ofile << it->second->getPosX() + Block_sprite::width/2<< " ";
            ofile << it->second->getPosY() + Block_sprite::height/2<< " ";
            ofile << std::endl;
        }
    }

    ofile.close();
}

gameStateEditor::~gameStateEditor(){
    exportMap();
    unload();
}
