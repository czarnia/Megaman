#include "gameStateEditor.h"
#include "../Cliente/Sprite.h"
#include "../Cliente/block_sprite.h"
#include "../Cliente/character_sprite.h"
#include "../Cliente/background_sprite.h"
#include <iostream>
#include <fstream>
#include <sstream>
/// TAMANIOS
#define ICON_BACKGROUND_WIDTH Block_sprite::width*3

#define CHAMBER_SIZEX 33
#define CHAMBER_SIZEY 25

/// PARA ALMACENAR
#define STATIC_BACKGROUND 1
#define STATIC_BLOCK 10
#define STATIC_MEGAMAN 11
#define STATIC_LADDER 12
#define STATIC_SPIKE 13
#define STATIC_MET 14
#define STATIC_BUMBY 15
#define STATIC_J_SNIPER 16
#define STATIC_SNIPER 17
#define STATIC_SAVE 18
#define STATIC_EXIT 19

#define STATIC 1
#define NON_STATIC 0
#define FRONT 1
#define BACK 0
#define ICONS_POS 100

#define BLOCK_EARTHN 100
#define BLOCK_SPIKEN 1000
#define BLOCK_LADDERN 1500
#define MEGAMANN 1
#define BUMBYN 2000
#define SNIPERN 3000
#define METN 4000
#define J_SNIPERN 5000
#define CAM_SPEEDX 35

/// PARA EXPORTAR
#define PBLOCK_EARTH 10
#define PBLOCK_SPIKE 11
#define PBLOCK_LADDER 12
#define PMEGAMAN 1
#define PMET 4
#define PBUMBY 2
#define PJ_SNIPER 3
#define PSNIPER 5

#include <fstream>

gameStateEditor::gameStateEditor(Window *window, Renderer* renderer):
    window(window),
    renderer(renderer)
{
    bossSelected = 0;
    megamanPlaced = false;
    quit = false;
    window->setTitle("Megaman: Level editor");
    window->maximize();
    object = gameStateEditor::NOTHING;
    load();
}

void gameStateEditor::load(int stack){
    /// FONDO
    Sprite *spr = new Sprite(renderer->get_renderer(), "../sprites/editor_background.jpeg");
    spr->setWidth(window->get_width());
    spr->setHeight(window->get_height());
    spr->setPosX(0);
    spr->setPosY(0);
    renderer->addSprite(STATIC_BACKGROUND, spr, BACK, STATIC);
    /// FONDO DE ICONOS
    spr = new Sprite(renderer->get_renderer(), "../sprites/icons_background.jpeg");
    spr->setHeight(window->get_height());
    spr->setWidth(ICON_BACKGROUND_WIDTH);
    spr->setPosX(0);
    spr->setPosY(0);
    renderer->addSprite(STATIC_BACKGROUND, spr, FRONT, STATIC);
    /// BLOQUE
    spr = new Block_sprite(renderer->get_renderer(), "../sprites/block.png");
    spr->setPosX(ICON_BACKGROUND_WIDTH/2-Block_sprite::width/2);
    spr->setPosY(Block_sprite::height*1);
    renderer->addSprite(STATIC_BLOCK, spr, FRONT, STATIC);
    /// MEGAMAN
    spr = new Character_sprite(renderer->get_renderer(), "../sprites/megaman.png");
    spr->changeState(-1,-1);
    spr->setPosX(ICON_BACKGROUND_WIDTH/2-Block_sprite::width/2);
    spr->setPosY(Block_sprite::height*2);
    renderer->addSprite(STATIC_MEGAMAN, spr, FRONT, STATIC);
    /// ESCALERA
    spr = new Block_sprite(renderer->get_renderer(), "../sprites/ladder.png");
    spr->setPosX(ICON_BACKGROUND_WIDTH/2-Block_sprite::width/2);
    spr->setPosY(Block_sprite::height*4);
    renderer->addSprite(STATIC_LADDER, spr, FRONT, STATIC);
    /// PUA
    spr = new Block_sprite(renderer->get_renderer(), "../sprites/spike.png");
    spr->setPosX(ICON_BACKGROUND_WIDTH/2-Block_sprite::width/2);
    spr->setPosY(Block_sprite::height*5);
    renderer->addSprite(STATIC_SPIKE, spr, FRONT, STATIC);
    /// MET
    spr = new Block_sprite(renderer->get_renderer(), "../sprites/met.png");
    spr->setPosX(ICON_BACKGROUND_WIDTH/2-Block_sprite::width/2);
    spr->setPosY(Block_sprite::height*6);
    renderer->addSprite(STATIC_MET, spr, FRONT, STATIC);
    /// BUMBY
    spr = new Block_sprite(renderer->get_renderer(), "../sprites/bumby.png");
    spr->setPosX(ICON_BACKGROUND_WIDTH/2-Block_sprite::width/2);
    spr->setPosY(Block_sprite::height*7);
    renderer->addSprite(STATIC_BUMBY, spr, FRONT, STATIC);
    /// JUMPING SNIPER
    spr = new Character_sprite(renderer->get_renderer(), "../sprites/j_sniper.png");
    spr->changeState(-1,-1);
    spr->setPosX(ICON_BACKGROUND_WIDTH/2-Block_sprite::width/2);
    spr->setPosY(Block_sprite::height*8);
    renderer->addSprite(STATIC_J_SNIPER, spr, FRONT, STATIC);
    /// SNIPER
    spr = new Character_sprite(renderer->get_renderer(), "../sprites/sniper.png");
    spr->changeState(-1,-1);
    spr->setPosX(ICON_BACKGROUND_WIDTH/2-Block_sprite::width/2);
    spr->setPosY(Block_sprite::height*10);
    renderer->addSprite(STATIC_SNIPER, spr, FRONT, STATIC);
    /// BOTON GUARDAR
    spr = new Sprite(renderer->get_renderer(), "../sprites/save.png");
    spr->setHeight(50);
    spr->setWidth(50);
    spr->setPosX(window->get_width()*3/4+100);
    spr->setPosY(10);
    renderer->addSprite(STATIC_SAVE, spr, FRONT, STATIC);
    /// BOTON SALIR
    spr = new Sprite(renderer->get_renderer(), "../sprites/exit.png");
    spr->setHeight(50);
    spr->setWidth(50);
    spr->setPosX(window->get_width()*3/4+160);
    spr->setPosY(10);
    renderer->addSprite(STATIC_SAVE, spr, FRONT, STATIC);
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
        case STATIC_BUMBY:
            object = gameStateEditor::BUMBY;
            std::cout<<"Se eligio un bumby"<<std::endl;
            break;
        case STATIC_J_SNIPER:
            object = gameStateEditor::J_SNIPER;
            std::cout<<"Se eligio un jumping sniper"<<std::endl;
            break;
        case STATIC_SNIPER:
            object = gameStateEditor::SNIPER;
            std::cout<<"Se eligio un sniper"<<std::endl;
            break;
        case STATIC_SAVE:
            object = gameStateEditor::SAVE;
            break;
        case STATIC_EXIT:
            object = gameStateEditor::EXIT;
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
                        renderer->addSprite(BLOCK_EARTHN, spr, FRONT, NON_STATIC);
                    }
                    break;
                case gameStateEditor::SPIKES:
                    if (!renderer->ocupied(x,y)){
                        spr = new Block_sprite(renderer->get_renderer(), "../sprites/spike.png");
                        spr->setPosX(x);
                        spr->setPosY(y);
                        renderer->addSprite(BLOCK_SPIKEN, spr, FRONT, NON_STATIC);
                    }
                    break;
                case gameStateEditor::LADDER:
                    if (!renderer->ocupied(x,y)){
                        spr = new Block_sprite(renderer->get_renderer(), "../sprites/ladder.png");
                        spr->setPosX(x);
                        spr->setPosY(y);
                        renderer->addSprite(BLOCK_LADDERN, spr, FRONT, NON_STATIC);
                    }
                    break;
                case gameStateEditor::MEGAMAN:
                    if (!renderer->ocupied(x,y) && !renderer->ocupied(x,y+Block_sprite::width)){
                        if(renderer->find(MEGAMANN)){
                            std::cout<< "Ya se coloco un megaman"<<std::endl;
                        }else{
                            megamanPlaced = true;
                            spr = new Character_sprite(renderer->get_renderer(), "../sprites/megaman.png");
                            spr->changeState(-1,-1);
                            spr->setPosX(x);
                            spr->setPosY(y);
                            renderer->addSprite(MEGAMANN, spr, FRONT, NON_STATIC);
                            spr = new Block_sprite(renderer->get_renderer(), "../sprites/nothing.png");
                            spr->setPosX(x);
                            spr->setPosY(y+Block_sprite::height);
                            renderer->addSprite(0, spr, BACK, NON_STATIC);
                        }
                    }
                    break;
                case gameStateEditor::MET:
                    if (!renderer->ocupied(x,y)){
                        spr = new Block_sprite(renderer->get_renderer(), "../sprites/met.png");
                        spr->changeState(-1,-1);
                        spr->setPosX(x);
                        spr->setPosY(y);
                        renderer->addSprite(METN, spr, FRONT, NON_STATIC);
                    }
                    break;
                case gameStateEditor::BUMBY:
                    if (!renderer->ocupied(x,y)){
                        spr = new Block_sprite(renderer->get_renderer(), "../sprites/bumby.png");
                        spr->changeState(-1,-1);
                        spr->setPosX(x);
                        spr->setPosY(y);
                        renderer->addSprite(BUMBYN, spr, FRONT, NON_STATIC);
                    }
                    break;
                case gameStateEditor::J_SNIPER:
                    if (!renderer->ocupied(x,y)){
                        spr = new Character_sprite(renderer->get_renderer(), "../sprites/j_sniper.png");
                        spr->changeState(-1,-1);
                        spr->setPosX(x);
                        spr->setPosY(y);
                        renderer->addSprite(J_SNIPERN, spr, FRONT, NON_STATIC);
                        spr = new Block_sprite(renderer->get_renderer(), "../sprites/nothing.png");
                        spr->setPosX(x);
                        spr->setPosY(y+Block_sprite::height);
                        renderer->addSprite(0, spr, BACK, NON_STATIC);
                    }
                    break;
                case gameStateEditor::SNIPER:
                    if (!renderer->ocupied(x,y)){
                        spr = new Character_sprite(renderer->get_renderer(), "../sprites/sniper.png");
                        spr->changeState(-1,-1);
                        spr->setPosX(x);
                        spr->setPosY(y);
                        renderer->addSprite(SNIPERN, spr, FRONT, NON_STATIC);
                        spr = new Block_sprite(renderer->get_renderer(), "../sprites/nothing.png");
                        spr->setPosX(x);
                        spr->setPosY(y+Block_sprite::height);
                        renderer->addSprite(0, spr, BACK, NON_STATIC);
                    }
                    break;
                case gameStateEditor::SAVE:
                    if (megamanPlaced && bossSelected != 0)
                        exportMap();
                    else
                        std::cout<<"No se coloco un megaman o no se eligio un jefe"<<std::endl;
                    object = gameStateEditor::BLOCK;
                    break;
                case gameStateEditor::EXIT:
                    quit = true;
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
        if(!renderer->find(MEGAMANN))
            megamanPlaced = false;
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

        if (event.type == SDL_QUIT || quit){
            return GameState::QUIT;
            break;

        }else if (event.type == SDL_KEYDOWN){
            pressed.sym = event.key.keysym.sym;
            if( pressed.sym == SDLK_UP || pressed.sym == SDLK_DOWN ||
                pressed.sym == SDLK_LEFT || pressed.sym == SDLK_RIGHT)
                updateCameraPos(&event);
            else if (pressed.sym == SDLK_1)
                bossSelected = 20;
            else if (pressed.sym == SDLK_2)
                bossSelected = 21;
            else if (pressed.sym == SDLK_3)
                bossSelected = 22;
            else if (pressed.sym == SDLK_4)
                bossSelected = 23;
            else if (pressed.sym == SDLK_5)
                bossSelected = 24;

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
    int object_type;
    static int i = 0;
    /// NOMBRE PARA EL ARCHIVO
    std::ostringstream os;
    os << "mapa" << i << ".txt";
    std::string fileName(os.str());
    i++;

    std::map<int,Sprite*>::iterator it;
    int sizeX = 0;
    int sizeY = 0;
    /// CALCULO EL TAMANIO DEL MAPA
    it = renderer->sprites[FRONT].begin();
    for(; it!= renderer->sprites[FRONT].end(); ++it){
        if (it->second->getPosX() > sizeX){
            sizeX = it->second->getPosX();
        }
        if (it->second->getPosY() > sizeY){
            sizeY = it->second->getPosY();
        }
    }

    sizeX /= Block_sprite::width;
    sizeY /= Block_sprite::height;

    /// LE AGREGO EL TAMANIO DE LA CAMARA DEL BOSS
    sizeX += CHAMBER_SIZEX;

    /// ABRO EL ARCHIVO PARA IMPRIMIR
    std::ofstream ofile;
    ofile.open(fileName.c_str());
    /// IMPRIMOP TAMANIO DEL MAPA
    ofile << sizeX << " ";
    ofile << CHAMBER_SIZEY << " ";
    ofile << std::endl;
    /// MODIFICO CODIGOS PARA SER COHERENTE CON EL PROTOCOLO
    it = renderer->sprites[FRONT].begin();
    for (; it != renderer->sprites[FRONT].end(); ++it){

        if (it->first == MEGAMANN)
            object_type = PMEGAMAN;
        else if (it->first >= BLOCK_EARTHN && it->first < BLOCK_SPIKEN)
            object_type = PBLOCK_EARTH;
        else if (it->first >= BLOCK_SPIKEN && it->first < BLOCK_LADDERN)
            object_type = PBLOCK_SPIKE;
        else if (it->first >= BLOCK_LADDERN && it->first < BUMBYN)
            object_type = PBLOCK_LADDER;
        else if (it->first >= BUMBYN && it->first < SNIPERN)
            object_type = PBUMBY;
        else if (it->first >= SNIPERN && it->first < METN)
            object_type = PSNIPER;
        else if (it->first >= METN && it->first < J_SNIPERN)
            object_type = PMET;
        else if (it->first >=J_SNIPERN)
            object_type = PJ_SNIPER;

    /// IMPRIMO POSICIONES DE CADA COSA
        if(it->first == PMEGAMAN || it->first == PSNIPER || it->first == J_SNIPERN){
            ofile << object_type << " ";
            ofile << it->second->getPosX() + Block_sprite::width/2 - ICON_BACKGROUND_WIDTH<< " ";
            ofile << it->second->getPosY() + Block_sprite::height << " ";
            ofile << std::endl;
        }else{
            ofile << object_type << " ";
            ofile << it->second->getPosX() + Block_sprite::width/2 - ICON_BACKGROUND_WIDTH<< " ";
            ofile << it->second->getPosY() + Block_sprite::height/2 << " ";
            ofile << std::endl;
        }
    }
    sizeX -= CHAMBER_SIZEX;
    sizeX *= Block_sprite::width;

    int blocktype;
    int posX;
    int posY;
    std::fstream chamberfile;
    chamberfile.open("chamber.txt");

    /// LE AGREGO LA CAMARA DEL BOSS AL FINAL
    while (!chamberfile.eof()){
        chamberfile >> blocktype;
        chamberfile >> posX;
        chamberfile >> posY;

        if (blocktype == 1)
            blocktype = bossSelected;
        if (!chamberfile.eof()){
        ofile << blocktype << " ";
        ofile << posX + sizeX << " ";
        ofile << posY;
        ofile << std::endl;
        }

    }
    chamberfile.close();
    ofile.close();
}

gameStateEditor::~gameStateEditor(){
    unload();
}
