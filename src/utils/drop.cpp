#include "drop.h"
#include "raylib.h"

double lastUpdate = 0; 


bool BlockDrop(double interval, bool paused){
    if(paused == true) return  false;

    double currentTime = GetTime();
    if(currentTime - lastUpdate >= interval){
        lastUpdate = currentTime;
        return true;
    }
    return false;
};
