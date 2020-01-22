#include "main.h"


/*void affiche_pion_blanc( SDL_Renderer *renderer , int x, int y,int longueur ,int largeur)
{
        SDL_Texture *texture4 = NULL;
            SDL_Surface *surface4 = NULL;
         //*******************************importer une image pion blanc*********************************
    surface4 = SDL_LoadBMP("images/test_pion_blanc2.bmp");
    texture4 = SDL_CreateTextureFromSurface(renderer, surface4);
    SDL_Rect dstrect_4 = {x,y,longueur,largeur};
    //410,190,60,60
    SDL_RenderCopy(renderer, texture4, NULL, &dstrect_4);
    SDL_DestroyTexture(texture4);
    SDL_FreeSurface(surface4);

}
void affiche_pion_noir( SDL_Renderer *renderer , int x, int y,int longueur ,int largeur)
{

        SDL_Texture *texture4 = NULL;
        SDL_Surface *surface4 = NULL;
     //*******************************importer une image pion noir*********************************
    surface4 = SDL_LoadBMP("images/test_pion_noir3.bmp");
    texture4 = SDL_CreateTextureFromSurface(renderer, surface4);
    SDL_Rect dstrect_5 = {x,y,longueur,largeur};
    //330,110,60,60
    SDL_RenderCopy(renderer, texture4, NULL, &dstrect_5);

    SDL_DestroyTexture(texture4);
    SDL_FreeSurface(surface4);

}*/
void affiche_identification( SDL_Renderer *renderer , int x, int y,int longueur ,int largeur)
{

    SDL_Texture *texture4 = NULL;
    SDL_Surface *surface4 = NULL;
    surface4 = SDL_LoadBMP("images/identif.bmp");
    texture4 = SDL_CreateTextureFromSurface(renderer, surface4);
    SDL_Rect dstrect_6 = {x,y,longueur,largeur};
    //330,110,60,60
    SDL_RenderCopy(renderer, texture4, NULL, &dstrect_6);

    SDL_DestroyTexture(texture4);
    SDL_FreeSurface(surface4);

}


int main(int argc, char **argv)
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *texture = NULL;
    //SDL_Texture *texture3 = NULL;
    //SDL_Texture *texture5 = NULL;
    //SDL_Surface *surface3 = NULL;
    //SDL_Surface *surface5 = NULL;



    reserver_memoire();
    //******************window*********************************************************
   // affiche_fenetre(window);
//XXXXXXXXXXXXXXXXXX

     window = SDL_CreateWindow("Projet Algo",50,50, width, height, SDL_WINDOW_RESIZABLE);
    if (window == NULL)
    {
        printf("Erreur lors de la creation d'une fenetre : %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    //*************renderer*********************************************************************
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderer == NULL)
    {
        printf("Erreur lors de la creation d'un renderer : %s",SDL_GetError());
        return EXIT_FAILURE;
    }

    // *************************************texture*********************************************************************************
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 480, 400);
    if(NULL == texture)
    {
        fprintf(stderr, "Erreur SDL_CreateTexture : %s", SDL_GetError());
        return EXIT_FAILURE;
    }

//XXXXXXXXXXXXXXXXXXXX

    //affiche_plateau(renderer,texture);

    //affiche_pion_blanc(renderer,410,190,60,60);
   // affiche_pion_noir(renderer,330,110,60,60);
   affiche_identification(renderer ,400,180,320.240);

    //**********************************affichage**************************************
    bool running = true;
    SDL_Event event;
    while(running)
    {
        // Process events
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                running = false;
            }
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                SDL_Log("Mouvement de souris (%d %d)", event.motion.x, event.motion.y);
            }
        }


        SDL_RenderPresent(renderer);
    }


    //*******************************liberation de la mémoire*************************************
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_DestroyTexture(texture);


    SDL_DestroyTexture(texture3);


    SDL_DestroyTexture(texture5);


    SDL_FreeSurface(surface3);
    SDL_FreeSurface(surface5);


    SDL_Quit();

    return 0;
}
