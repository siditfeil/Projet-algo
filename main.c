#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <SDL2/SDL.h>

static const int width = 800;
static const int height = 600;

int main(int argc, char **argv)
{
    SDL_Rect cases[2];
    // Initialize SDL
    //c'est comme un malloc
    //SDL_INIT_VIDEO :Charge le système d'affichage (vidéo). C'est la partie que nous chargerons le plus souvent.
    //// Chargement de la vidéo et de l'audio  ----> SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    SDL_Init(SDL_INIT_VIDEO);
    //La fonctionSDL_Init renvoie une valeur : -1 en cas d'erreur ; 0 si tout s'est bien passé
    if (SDL_Init(SDL_INIT_VIDEO) == -1) // Démarrage de la SDL. Si erreur :
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); // Écriture de l'erreur
        exit(EXIT_FAILURE); // On quitte le programme
    }

    // Create a SDL window
    //undefined x and y positions  x et y : ces arguments correspondent à la position de départ de la fenêtre en pixel
    SDL_Window *window = SDL_CreateWindow("Projet Algo",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height,0);
    //gestion des erreurs
    if (window == NULL)
    {
        printf("Erreur lors de la creation d'une fenetre : %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    // Create a renderer (accelerated and in sync with the display refresh rate)
    //le renderer est en fait l'espace où nous allons pouvoir dessiner, écrire
    //       *******SDL_RENDERER_ACCELERATED*****
    //	Utilise l'accélération matérielle, c'est à dire la carte graphique.
    //Il est fortement recommandé de le mettre puisque c'est un des atouts majeurs de la SDL 2.0 par rapport à la SDL 1.2 et surtout parce que c'est beaucoup plus rapide.
    //          ******SDL_RENDERER_PRESENTVSYNC*****
    //	Synchronise le rendu avec la fréquence de rafraîchissement.
    //La fréquence de rafraîchissement correspond au nombre de fois où l'écran est mis à jour par seconde. Ainsi, le rendu sera synchronisé avec celle-ci.
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    ////Uint8 r,  Uint8 g , Uint8 b , Uint8  a
    //R, g, b et a correspondent en anglais à red, green, blue et alpha, ce qui en français correspond à rouge, vert, bleu et alpha (la transparence).
    SDL_SetRenderDrawColor(renderer,0,0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer,255,255,255, 255);
    //SDL_RenderDrawLine(renderer,20,20,150,150);

    //SDL_Surface* surface=NULL;
    //surface=SDL_CreateRGBSurface(0,150,150,32,100,100,100,100);

    //cases[0].x=cases[0].y=50;
    //cases[0].w=cases[0].h=100;
    //cases[1].x=250;
    //cases[1].y=50;
    //cases[1].w=cases[1].h=100;
    //SDL_RenderFillRects(renderer,cases,2);
    SDL_Rect rect={50,50,100,100};
    SDL_RenderDrawRect(renderer,&rect);

    //SDL_Point ligne_depart,ligne_arrivee;

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
        }

        // Clear screen
        ///* Clear the entire screen to our selected color. */
        //SDL_RenderClear(renderer);

        // Draw

        // Show what was drawn
        ///* Up until now everything was drawn behind the scenes.
//           This will show the new, red contents of the window. */
        SDL_RenderPresent(renderer);
    }

    // Release resources
    //// Destruction du renderer et de la fenêtre :
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    //SDL_FreeSurface(surface);
    //tous les systèmes initialisés seront arrêtés et libérés de la mémoire.
    ////  SDL_Quit()  --> Arrêt de la SDL (libération de la mémoire).
    SDL_Quit();

    return 0;
}
