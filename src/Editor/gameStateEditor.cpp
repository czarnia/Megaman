#include "gameStateEditor.h"
#include "../Cliente/Sprite.h"
#include "../Cliente/block_sprite.h"
#include "../Cliente/character_sprite.h"
#include <iostream>
#include <fstream>

#define BLOCKN 0
#define MEGAMANN 1
#define METN 8
#define CAM_SPEEDX 3

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
                    renderer->addMapSprite(BLOCKN+100, spr);
                }
                break;
            case gameStateEditor::SPIKES:
                if (!renderer->ocupied(x,y)){
                    spr = new Block_sprite(renderer->get_renderer(), "../sprites/spike.gif");
                    spr->setPosX(x);
                    spr->setPosY(y);
                    renderer->addMapSprite(BLOCKN+100, spr);
                }
                break;
            case gameStateEditor::STAIR:
                if (!renderer->ocupied(x,y)){
                    spr = new Block_sprite(renderer->get_renderer(), "../sprites/stair.jpeg");
                    spr->setPosX(x);
                    spr->setPosY(y);
                    renderer->addMapSprite(BLOCKN+100, spr);
                }
                break;
            case gameStateEditor::MEGAMAN:
                if (!renderer->ocupied(x,y) && !renderer->ocupied(x,y+Block_sprite::width)){
                    spr = new Main_character(renderer->get_renderer(), "../sprites/megaman.png");
                    spr->setPosX(x);
                    spr->setPosY(y);
                    renderer->addSprite(MEGAMANN, spr);
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
        int x = event->button.x/Block_sprite::width*Block_sprite::width;
        int y = event->button.y/Block_sprite::width*Block_sprite::width;
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
    if (event->button.x < window->get_width()/4){
        renderer->camX -= CAM_SPEEDX;
    }
    if (event->button.x > window->get_width()*3/4){
        renderer->camX += CAM_SPEEDX;
    }
    if (event->button.y < window->get_height()/4){
        renderer->camY -= CAM_SPEEDX;
    }
    if (event->button.y > window->get_height()*3/4){
        renderer->camY += CAM_SPEEDX;
    }
}

GameState::StateCode gameStateEditor::update(){

    SDL_Event event;
    while (SDL_PollEvent(&event)){
        if (event.type == SDL_QUIT){
            return GameState::QUIT;
            break;
        }else if (event.type == SDL_KEYDOWN){
            chooseBlock(&event);
        }else if (event.type == SDL_MOUSEBUTTONDOWN){
            updateInput(&event);
        }else if (event.type == SDL_MOUSEMOTION){
            updateCameraPos(&event);
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

    std::cin>>fileName;
    ofile.open(fileName.c_str());

    std::map<int,Sprite*>::iterator it;
    it = renderer->map_sprites.begin();

    for(; it != renderer->map_sprites.end(); ++it){
        ofile << it->first << " ";
        ofile << it->second->getPosX() << " ";
        ofile << it->second->getPosY() << " ";
        ofile << std::endl;
    }

    it = renderer->sprites.begin();
    for(; it != renderer->sprites.end(); ++it){
        ofile << it->first << " ";
        ofile << it->second->getPosX() << " ";
        ofile << it->second->getPosY() << " ";
        ofile << std::endl;
    }

    ofile.close();
}

gameStateEditor::~gameStateEditor(){
    exportMap();
    unload();
}
