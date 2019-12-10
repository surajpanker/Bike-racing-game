
void apply_surface(int x,int y,SDL_Surface *source,SDL_Surface *distination,SDL_Rect *clip=NULL)
{
    SDL_Rect offset;
    offset.x=x;
    offset.y=y;
    SDL_BlitSurface(source,clip,distination,&offset);       //Load image to the display screen i.e. on the screen..
}
