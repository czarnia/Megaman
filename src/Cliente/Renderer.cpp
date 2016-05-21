#include "Renderer.h"

Renderer::Renderer(SDL_Window *w){
    renderer = SDL_CreateRenderer(w, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Renderer* Renderer::get_renderer(){
    return renderer;
}

void Renderer::clear(){
    SDL_RenderClear(renderer);
}

void Renderer::draw(SDL_Texture* texture, SDL_Rect* rect, SDL_Rect* crop){
    SDL_RenderCopy(renderer, texture, NULL, rect);
}

void Renderer::present(){
    SDL_RenderPresent(renderer);
}

void Renderer::add(Sprite* spr){
    textures.push_back(spr->get_texture());
    rectangles.push_back(spr->get_rectangle());
    crops.push_back(spr->get_crop());
}

void Renderer::drawAll(){
    for (int i = 0; i<textures.size(); i++){
        if(textures[i] && rectangles[i] && crops[i]){
            draw(textures[i],rectangles[i],crops[i]);
        }
    }
}

Renderer::~Renderer(){
    SDL_DestroyRenderer(renderer);
}

