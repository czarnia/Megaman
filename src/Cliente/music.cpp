#include "music.h"

#define FOREVER -1

Music::Music(){
    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096);
    piece = NULL;
}

void Music::play(){
   // Mix_PlayMusic(piece, FOREVER);
}

void Music::changeTrack(std::string file){
    if (piece){
        Mix_FreeMusic(piece);
        piece = NULL;
    }
    piece = Mix_LoadMUS(file.c_str());
    Mix_Music *a = piece;
    int b = 3;
}

void Music::stop(){
    Mix_HaltMusic();
}

Music::~Music(){
    if(piece)
        Mix_FreeMusic(piece);
    piece = NULL;
    Mix_CloseAudio();
}
