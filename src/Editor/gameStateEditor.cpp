#include "gameStateEditor.h"
#include "../Cliente/Sprite.h"
#include "../Cliente/block_sprite.h"
#include "../Cliente/character_sprite.h"
#include "../Cliente/background_sprite.h"
#include <iostream>
#include <fstream>
/// TAMANIOS
#define ICON_BACKGROUND_WIDTH Block_sprite::width*3

/// PARA ALMACENAR
#define STATIC_BACKGROUND 1
#define STATIC_BLOCK 10
#define STATIC_MEGAMAN 11
#define STATIC_LADDER 12
#define STATIC_SPIKE 13
#define STATIC_MET 14

#define STATIC 1
#define NON_STATIC 0

#define ICONS_POS 100

#define BLOCK_EARTH 100
#define BLOCK_SPIKE 1000
#define BLOCK_LADDER 1500
#define MEGAMANN 1
#define METN 8
#define CAM_SPEEDX 20

/// PARA EXPORTAR
#define PBLOCK_EARTH 10
#define PBLOCK_SPIKE 11
#define PBLOCK_LADDER 12
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

void gameStateEditor::load(int stack){
    /// FONDO
    Sprite *spr = new Background_sprite(renderer->get_renderer(), "../sprites/editor_background.jpeg");
    spr->setPosX(0);
    spr->setPosY(0);
    renderer->addSprite(STATIC_BACKGROUND, spr, 0, STATIC);
    /// FONDO DE ICONOS
    spr = new Sprite(renderer->get_renderer(), "../sprites/icons_background.jpeg");
    spr->setHeight(window->get_height());
    spr->setWidth(ICON_BACKGROUND_WIDTH);
    spr->setPosX(0);
    spr->setPosY(0);
    renderer->addSprite(STATIC_BACKGROUND, spr, 1, STATIC);
    /// BLOQUE
    spr = new Block_sprite(renderer->get_renderer(), "../sprites/block.png");
    spr->setPosX(ICON_BACKGROUND_WIDTH/2-Block_sprite::width/2);
    spr->setPosY(Block_sprite::height*1);
    renderer->addSprite(STATIC_BLOCK, spr, 1, STATIC);
    /// MEGAMAN
    spr = new Character_sprite(renderer->get_renderer(), "../sprites/megaman.png");
    spr->setState(-1,-1);
    spr->setPosX(ICON_BACKGROUND_WIDTH/2-Block_sprite::width/2);
    spr->setPosY(Block_sprite::height*2);
    renderer->addSprite(STATIC_MEGAMAN, spr, 1, STATIC);
    /// ESCALERA
    spr = new Block_sprite(renderer->get_renderer(), "../sprites/ladder.png");
    spr->setPosX(ICON_BACKGROUND_WIDTH/2-Block_sprite::width/2);
    spr->setPosY(Block_sprite::height*4);
    renderer->addSprite(STATIC_LADDER, spr, 1, STATIC);
    /// PUA
    spr = new Block_sprite(renderer->get_renderer(), "../sprites/spike.png");
    spr->setPosX(ICON_BACKGROUND_WIDTH/2-Block_sprite::width/2);
    spr->setPosY(Block_sprite::height*5);
    renderer->addSprite(STATIC_SPIKE, spr, 1, STATIC);
    /// MET
    spr = new Block_sprite(renderer->get_renderer(), "../sprites/met.png");
    spr->setPosX(ICON_BACKGROUND_WIDTH/2-Block_sprite::width/2);
    spr->setPosY(Block_sprite::height*6);
    renderer->addSprite(STATIC_MET, spr, 1, STATIC);
}

void gameStateEditor::chooseBlock(SDL_Event *event){
    int objectPressed = renderer->pressed(event->button.x, event->button.y);

    switch(objectPressed){
        case STATIC_BLOCK:/// BLOQUE
            object = gameStateEditor::BLOCK;
            std::cout<<"Se eligio un bloque"<<std::endl;
            break;
        case STATIC_SPIKE:/// PUAS
            object = gameStateEditor::SPIKES;
            std::cout<<"Se eligio puas"<<std::endl;
            break;
        case STATIC_LADDER:/// ESCALERA
            object = gameStateEditor::LADDER;
            std::cout<<"Se eligio escalera"<<std::endl;
            break;
        case STATIC_MEGAMAN:/// MEGAMAN
            object = gameStateEditor::MEGAMAN;
            std::cout<<"Se eligio megaman"<<std::endl;
            break;
        case STATIC_MET: /// MET
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
        if ( event->button.x > ICONS_POS){
            switch(object){
                case gameStateEditor::BLOCK:
                    if (!renderer->ocupied(x,y)){
                        spr = new Block_sprite(renderer->get_renderer(), "../sprites/block.png");
                        spr->setPosX(x);
                        spr->setPosY(y);
                        renderer->addSprite(BLOCK_EARTH, spr, 1, NON_STATIC);
                    }
                    break;
                case gameStateEditor::SPIKES:
                    if (!renderer->ocupied(x,y)){
                        spr = new Block_sprite(renderer->get_renderer(), "../sprites/spike.png");
                        spr->setPosX(x);
                        spr->setPosY(y);
                        renderer->addSprite(BLOCK_SPIKE, spr, 1, NON_STATIC);
                    }
                    break;
                case gameStateEditor::LADDER:
                    if (!renderer->ocupied(x,y)){
                        spr = new Block_sprite(renderer->get_renderer(), "../sprites/ladder.png");
                        spr->setPosX(x);
                        spr->setPosY(y);
                        renderer->addSprite(BLOCK_LADDER, spr, 1, NON_STATIC);
                    }
                    break;
                case gameStateEditor::MEGAMAN:
                    if (!renderer->ocupied(x,y) && !renderer->ocupied(x,y+Block_sprite::width)){
                        if(renderer->find(MEGAMANN)){
                            std::cout<< "Ya se coloco un megaman"<<std::endl;
                        }else{
                            spr = new Character_sprite(renderer->get_renderer(), "../sprites/megaman.png");
                            spr->setState(-1,-1);
                            spr->setPosX(x);
                            spr->setPosY(y);
                            renderer->addSprite(MEGAMANN, spr, 1, NON_STATIC);
                        }
                    }
                    break;
                case gameStateEditor::MET:
                    if (!renderer->ocupied(x,y)){
                        spr = new Block_sprite(renderer->get_renderer(), "../sprites/met.png");
                        spr->setPosX(x);
                        spr->setPosY(y);
                        renderer->addSprite(METN, spr, 1, NON_STATIC);
                    }
                    break;
                default:
                    break;
            }
        }
    }else if (event->button.button == SDL_BUTTON_RIGHT){
        int x = (event->button.x + renderer->camX)/Block_sprite::width*Block_sprite::width;
        int y = (event->button.y + renderer->camY)/Block_sprite::width*Block_sprite::width;
        if(renderer->ocupied(x,y)){
            renderer->erase(x,y);
        }
    }
}



int gameStateEditor::unload(){
    renderer->clearSprites();
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
    bool click;
    while (SDL_PollEvent(&event)){

        if (event.type == SDL_QUIT){
            return GameState::QUIT;
            break;

        }else if (event.type == SDL_KEYDOWN){
            pressed.sym = event.key.keysym.sym;
            if( pressed.sym == SDLK_UP || pressed.sym == SDLK_DOWN ||
                pressed.sym == SDLK_LEFT || pressed.sym == SDLK_RIGHT)
                updateCameraPos(&event);

        }else if (event.type == SDL_MOUSEBUTTONDOWN){
            click = true;
            chooseBlock(&event);
            updateInput(&event);
        }else if (event.type == SDL_MOUSEBUTTONUP){
            click = false;
        }else if (event.type == SDL_MOUSEMOTION){
            if (click){
                updateInput(&event);
            }
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
    int object_type;
    std::cin>>fileName;
    ofile.open(fileName.c_str());

    std::map<int,Sprite*>::iterator it;
    it = renderer->sprites[0].begin();

    /*for (; it != renderer->sprites[0].end(); ++it){

        if (it->first > MEGAMAN && it->first < BLOCK_EARTH)
            object_type = PMET;
        else if (it->first > BLOCK_EARTH && it->first < BLOCK_SPIKE)
            object_type = PBLOCK_EARTH;
        else if (it->first > BLOCK_SPIKE && it->first < BLOCK_LADDER)
            object_type = PBLOCK_SPIKE;
        else if (it->first > BLOCK_LADDER)
            object_type = PBLOCK_LADDER;
        else if (it->first == MEGAMAN)
            object_type = PMEGAMAN;



        ofile << object_type << " ";
        ofile << it->second->getPosX() + Block_sprite::width/2 - ICON_BACKGROUND_WIDTH<< " ";
        ofile << it->second->getPosY() + Block_sprite::height/2 << " ";
        ofile << std::endl;
    }*/

    it = renderer->sprites[1].begin();
    for (; it != renderer->sprites[1].end(); ++it){

        if (it->first > MEGAMAN && it->first < BLOCK_EARTH)
            object_type = PMET;
        else if (it->first > BLOCK_EARTH && it->first < BLOCK_SPIKE)
            object_type = PBLOCK_EARTH;
        else if (it->first > BLOCK_SPIKE && it->first < BLOCK_LADDER)
            object_type = PBLOCK_SPIKE;
        else if (it->first > BLOCK_LADDER)
            object_type = PBLOCK_LADDER;
        else if (it->first == MEGAMANN)
            object_type = PMEGAMAN;



        ofile << object_type << " ";
        ofile << it->second->getPosX() + Block_sprite::width/2 - ICON_BACKGROUND_WIDTH<< " ";
        ofile << it->second->getPosY() + Block_sprite::height/2 << " ";
        ofile << std::endl;
    }

    ofile.close();
}

gameStateEditor::~gameStateEditor(){
    exportMap();
    unload();
}
