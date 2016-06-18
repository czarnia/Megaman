#ifndef _EVENT_H_
#define _EVENT_H_

class Event{
    public:
        Event(int,int,int,int,int);
        Event(int);
        Event(){}
        Event& operator=(Event &origin);
        int command;
        int objectType;
        int objectID;
        int posX;
        int posY;
};

#endif
