#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <math.h>

#define WINDOW_W 20
#define WINDOW_H 20
#define PRECISION 0.001
#define PI 3.14159265

static const int width = 1120;
static const int height =600;

int main(int argc, char **argv)
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *texture = NULL;
    SDL_Texture *texture1 = NULL;
    SDL_Texture *texture2 = NULL;
    SDL_Texture *texture3 = NULL;
    SDL_Surface *surface1 = NULL;
    SDL_Surface *surface2 = NULL;
    SDL_Surface *surface3 = NULL;
    SDL_Surface *surface_nom = NULL;
    SDL_Texture *texture_nom = NULL;

    SDL_Init(SDL_INIT_VIDEO);
    if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    //******************window*********************************************************
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
    //je change la couleur du fond
    SDL_SetRenderDrawColor(renderer,200,173,127,255);
    SDL_RenderClear(renderer);

     //**********************************Dessiner sur la texture ********************************

     SDL_Rect dst1 = {320, 100, 0, 0};
     SDL_SetRenderTarget(renderer, texture); // La texture est la cible de rendu, maintenant, on dessine sur la texture.
     SDL_SetRenderDrawColor(renderer,167,103,38,255);
     SDL_RenderClear(renderer);
     SDL_SetRenderDrawColor(renderer,0,0,0,255);
     for(int i=0;i<5;i++)
     {
        SDL_RenderDrawLine(renderer,0,80*i,480+1,80*i);
        SDL_RenderDrawLine(renderer,1,80*i+1,480+1,1+80*i);
     }

     for(int i=0;i<6;i++)
     {
        SDL_RenderDrawLine(renderer,80*i,0,80*i,400);
        SDL_RenderDrawLine(renderer,80*i+1,1,80*i+1,401);
     }

     SDL_SetRenderTarget(renderer, NULL); /* Le renderer est la cible de rendu. */

     /* On récupère les dimensions de la texture, on la copie sur le renderer
       et on met à jour l’écran. */
     SDL_QueryTexture(texture, NULL, NULL, &dst1.w, &dst1.h);
     SDL_RenderCopy(renderer, texture, NULL, &dst1);



     //****************************affichage bordure************************************
     SDL_SetRenderDrawColor(renderer,0,0,0,255);
     SDL_RenderDrawLine(renderer,800,100,800,500);
     SDL_RenderDrawLine(renderer,800-1,100-1,800-1,500-1);
     SDL_RenderDrawLine(renderer,320,500,800,500);
     SDL_RenderDrawLine(renderer,320-1,500-1,800-1,500-1);
     SDL_RenderDrawLine(renderer,0,100,320,100);
     SDL_RenderDrawLine(renderer,0+1,100+1,320+1,100+1);
     SDL_RenderDrawLine(renderer,0,500,320,500);
     SDL_RenderDrawLine(renderer,0+1,500+1,320+1,500+1);
     SDL_RenderDrawLine(renderer,800,100,1120,100);
     SDL_RenderDrawLine(renderer,800,100+1,1120,100+1);
     SDL_RenderDrawLine(renderer,800,500,1120,500);
     SDL_RenderDrawLine(renderer,800-1,500-1,1120-1,500-1);
     //POINT p1;
    // p1.x=50; p1.y=50;
     //draw_fill_circle(p1,100,vert);


     //******************************importer une image point d'interogation*********************************
    surface1 = SDL_LoadBMP("images/image.bmp");
    texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
    SDL_Rect dstrect1 = {1050,10,50,50};
    SDL_RenderCopy(renderer, texture1, NULL, &dstrect1);

     //******************************importer une image nom*********************************
    surface_nom = SDL_LoadBMP("images/titre2.bmp");
    texture_nom = SDL_CreateTextureFromSurface(renderer, surface_nom);
    SDL_Rect dstrect_nom = {520,10,100,80};
    SDL_RenderCopy(renderer, texture_nom, NULL, &dstrect_nom);

    //*******************************importer une image score*********************************
    surface2 = SDL_LoadBMP("images/score.bmp");
    texture2 = SDL_CreateTextureFromSurface(renderer, surface2);
    SDL_Rect dstrect2 = {890,0,100,80};
    SDL_RenderCopy(renderer, texture2, NULL, &dstrect2);


     //*******************************importer une image cercles gauche*********************************
    surface3 = SDL_LoadBMP("images/cercle.bmp");
    texture3 = SDL_CreateTextureFromSurface(renderer, surface3);
    SDL_Rect dstrect3 = {60,200,20,240};
    SDL_Rect dstrect4 = {width-80,200,20,240};
    SDL_RenderCopy(renderer, texture3, NULL, &dstrect3);
    SDL_RenderCopy(renderer, texture3, NULL, &dstrect4);



    //****************************colorer un cercle de gauche*************************************************************
     //Couleur de dessin :  autre
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_Rect rect1={65,208,10,10};
    SDL_RenderDrawRect(renderer,&rect1);
    SDL_RenderFillRect(renderer,&rect1);
    SDL_Rect rect2={65,208+4*19.3,10,10};
    SDL_RenderDrawRect(renderer,&rect2);
    SDL_RenderFillRect(renderer,&rect2);

    //****************************colorer un cercle de droite*************************************************************
     //Couleur de dessin :  autre
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_Rect rect3={width-80+5,208,11,11};
    SDL_RenderDrawRect(renderer,&rect3);
    SDL_RenderFillRect(renderer,&rect3);
    SDL_Rect rect4={width-80+5,208+6*19.3,11,11};
    SDL_RenderDrawRect(renderer,&rect4);
    SDL_RenderFillRect(renderer,&rect4);



    //**********************************les cercles de stockage apres recuperation*****************************
   /* SDL_SetRenderDrawColor(renderer,167,103,38,255);
     for(int j=0;j<12;j++)
    {
        for(double i = 0.0; i < 360; i+= PRECISION)
            SDL_RenderDrawPoint(renderer,100+(WINDOW_W /2 - cos(i)*WINDOW_W / 2),200+(20*j)+(WINDOW_H / 2 - sin(i)* WINDOW_H / 2));
    }

    for(int j=0;j<12;j++)
    {
        for(double i = 0.0; i < 360; i+= PRECISION)
            SDL_RenderDrawPoint(renderer,1020+(WINDOW_W /2 - cos(i)*WINDOW_W / 2),200+(20*j)+(WINDOW_H / 2 - sin(i)* WINDOW_H / 2));
    }*/


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
                SDL_Log("Mouvement de souris (%d %d) (%d %d)", event.motion.x, event.motion.y, event.motion.xrel, event.motion.yrel);
            }
        }


        SDL_RenderPresent(renderer);
    }


    //*******************************liberation de la mémoire*************************************
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_DestroyTexture(texture);
    SDL_DestroyTexture(texture1);
    SDL_DestroyTexture(texture2);
    SDL_DestroyTexture(texture3);
    SDL_FreeSurface(surface1);
    SDL_FreeSurface(surface2);
    SDL_FreeSurface(surface3);
    SDL_FreeSurface(surface_nom);
    SDL_Quit();

    return 0;
}
