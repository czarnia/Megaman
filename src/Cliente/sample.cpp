#include "sample.h"

Sample::Sample(){
    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096);
    sound = NULL;
}




Sample::~Sample(){
    if(sound)
     //   Mix_FreeMusic(piece);
    sound = NULL;
    Mix_CloseAudio();
}
