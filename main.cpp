#include <iostream>
using namespace std;
#include <sstream>
#include <SDL/SDL.h>
#include "SDL/SDL_image.h
#include "SDL/SDL_ttf.h"
#include "constants.h"
#include "string"
#include "coardinate.h"
#include "variable.h"
#include "init.h"
#include "function.h"
#include "collision.h"
#include "process.h"
#include "menu.h"


int main(int ch,char *cha[])
{
     if(!init_all())
     return 0;

     if(!load_files())
     return 0;

     int opt=start_menu();


     return 1;
}
