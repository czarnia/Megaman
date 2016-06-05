#ifndef _EDITOR_H_
#define _EDITOR_H_

#include "../Cliente/window.h"
#include "../Cliente/Renderer.h"

class Editor{
    private:
        Window *window;
        Renderer *renderer;
    public:
        Editor();
        void run();
        ~Editor();
};


#endif // _EDITOR_H_
