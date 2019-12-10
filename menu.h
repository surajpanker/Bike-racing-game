int start_menu()
{
     bool running=true;
     int x,y;

     bike_process bk;
//https://www.willusher.io/sdl2%20tutorials/2013/08/20/lesson-4-handling-events
     while(running)
     while(SDL_PollEvent( &event ) )
     {
          if(event.type == SDL_MOUSEMOTION)
          {
               cerr<<"inside"<<endl;
               x = event.motion.x;
               y = event.motion.y;
               if((x>594) && (x<756) && (y>340) && (y<357))
               {
                    apply_surface(0,0,play_menu,screen);
               }
               else if((x>572) && (x<778) && (y>414) && (y<431))
               {
                    apply_surface(0,0,instruction_menu,screen);
               }
               else if((x>641) && (x<708) && (y>490) && (y<506))
               {
                    apply_surface(0,0,quit_menu,screen);
               }
               else
               apply_surface(0,0,menu_pic,screen);
               SDL_Flip(screen);

        }
        else
          apply_surface(0,0,menu_pic,screen);
          SDL_Flip(screen);
        if(event.type == SDL_MOUSEBUTTONDOWN)
          {
               x = event.motion.x;
               y = event.motion.y;
               if((x>594) && (x<756) && (y>340) && (y<357))
               {
                    while(bk.process())
                    {
                         SDL_Flip(screen);
                    }
               }
               else if((x>572) && (x<778) && (y>414) && (y<431))
               {
                    apply_surface(0,0,instruction_menu,screen);
               }
               else if((x>641) && (x<708) && (y>490) && (y<506))
               {
                    return 0;
               }
          }
     }

     return 0;
}
