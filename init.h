bool init_all()
{
     if(SDL_Init(SDL_INIT_EVERYTHING)==-1)
     return false;
//SDL is composed of eight subsystems - Audio, CDROM, Event Handling, File I/O, Joystick Handling, Threading, Timers and Video. Before you can use any of these subsystems they must be initialized by calling SDL_Init (or SDL_InitSubSystem). SDL_Init must be called before any other SDL function. It automatically initializes the Event Handling, File I/O and Threading subsystems and it takes a parameter specifying which other subsystems to initialize. So, to initialize the default subsystems and the Video subsystems you would call:

     screen=SDL_SetVideoMode( WIDTH,HEIGHT,BPP,SDL_SWSURFACE );
//
//SDL_SWSURFACE	Create the video surface in system memory
    if(screen==NULL)
    {
        return false;
    }

    if(TTF_Init()==-1)                  //Font Initialization...
    {
        return false;
    }


    SDL_WM_SetCaption("RISING SUN BIKE RACING GAME",NULL);
    return true;
}

//Load a image file on screen and returns the address..
SDL_Surface* load_image(std::string filename,int col1=0xFF,int col2=0xFF , int col3=0xFF )
{
    SDL_Surface *loaded_image=NULL;
    SDL_Surface *optimized_image=NULL;

    loaded_image=IMG_Load(filename.c_str());
    if(loaded_image!=NULL)
    {
        optimized_image=SDL_DisplayFormat(loaded_image);        //Create an optimized image

        SDL_FreeSurface(loaded_image);//        //Free the old image

//Frees the resources used by a previously created SDL_Surface. If the surface was created using SDL_CreateRGBSurfaceFrom then the pixel data is not freed.

//http://lazyfoo.net/SDL_tutorials/lesson05/index.php
        if(optimized_image!=NULL)
        {
            SDL_SetColorKey(optimized_image,SDL_SRCCOLORKEY,SDL_MapRGB(optimized_image->format,col1,col2,col3));
        }
    }
//Then we check if the image was optimized.
/*
If the image was optimized, we have to map the color we want to set as the color key. 
We call SDL_MapRGB() to take the red, green, and blue values and give us the pixel value
 back in the same format as the surface. You can learn more about pixels in article 3.*/
    return optimized_image;     //Return the address of the loaded image...
}

bool load_files()
{
     for(int i=0;i<3;i++)
     {
          back[i]=load_image("image/bg2.png");         //Loads the background image..
          if(back[i]==NULL)
          return false;
     }
     bg[0]=background(0,0,back[0]->w,back[0]->h);
     bg[0]=background(WIDTH,0,back[1]->w,back[1]->h);

     upback=load_image("image/bg1.png");     //Loads the uper side of the  background image..
     if(upback==NULL)
     return false;

     bike=load_image("image/bike.PNG");      //Loads the image of bike..
     if(bike==NULL)
     return false;
     bike_y=LAYER_Y-bike->h;

     obs_wall[0]=load_image("image/wall.JPG");
     obs_wall[1]=load_image("image/wall1.JPG");
     if(obs_wall==NULL || obs_wall[1]==NULL)
     return false;

     w1[0]=wall(WIDTH+50,LAYER_Y-obs_wall[0]->h,obs_wall[0]->w,obs_wall[0]->h);
     w1[1]=wall(WIDTH+1350,LAYER_Y-obs_wall[0]->h,obs_wall[0]->w,obs_wall[0]->h);
     w1[2]=wall(WIDTH+3350,LAYER_Y-obs_wall[0]->h,obs_wall[0]->w,obs_wall[0]->h);
     w1[3]=wall(WIDTH+5050,LAYER_Y-obs_wall[0]->h,obs_wall[0]->w,obs_wall[0]->h);
     w1[4]=wall(WIDTH+7100,LAYER_Y-obs_wall[0]->h,obs_wall[0]->w,obs_wall[0]->h);

     w2[0]=wall(WIDTH+2050,LAYER_Y-obs_wall[1]->h,obs_wall[1]->w,obs_wall[1]->h);
     w2[1]=wall(WIDTH+4350,LAYER_Y-obs_wall[1]->h,obs_wall[1]->w,obs_wall[1]->h);
     w2[2]=wall(WIDTH+6050,LAYER_Y-obs_wall[1]->h,obs_wall[1]->w,obs_wall[1]->h);
     w2[3]=wall(WIDTH+7800,LAYER_Y-obs_wall[1]->h,obs_wall[1]->w,obs_wall[1]->h);


     font=TTF_OpenFont("times.ttf",20);      //Font file is loaded....

     time_limit=TTF_RenderText_Solid(font,"Time limit is 1:30 minute",textColor);
     die=TTF_RenderText_Solid(font,"GAME OVER",textColor);

    menu_pic=load_image("image/menu.jpg");
    play_menu=load_image("image/menu_play.jpg");
    instruction_menu=load_image("image/menu_instruction.jpg");
    quit_menu=load_image("image/menu_exit.jpg");
    if(menu_pic==NULL || play_menu==NULL || instruction_menu==NULL || quit_menu==NULL)
    return false;

     return true;
}
