#include "main.h"


int main(int argc, char **argv)
{

    //**********************************************************************************************************
    /**/    SDL_Window *window = NULL;
    /**/    SDL_Renderer *renderer = NULL;
    /**/    SDL_Texture *texture = NULL;
            SDL_Texture *texture1 = NULL;
            SDL_Surface * surface1=NULL;
    /**/    reserver_memoire();
    /**/
    /**/    //fênetre
    /**/    window = SDL_CreateWindow("Projet Algo",50,50, width, height, SDL_WINDOW_RESIZABLE);
    /**/    if (window == NULL)
    /**/    {
    /**/        printf("Erreur lors de la creation d'une fenetre : %s", SDL_GetError());
    /**/       return EXIT_FAILURE;
    /**/    }
    /**/
    /**/    //le renderer
    /**/    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    /**/    if(renderer == NULL)
    /**/    {
    /**/       printf("Erreur lors de la creation d'un renderer : %s",SDL_GetError());
    /**/       return EXIT_FAILURE;
    /**/    }
    /**/
    /**/    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 480, 400);
    /**/    if(NULL == texture)
    /**/    {
    /**/        fprintf(stderr, "Erreur SDL_CreateTexture : %s", SDL_GetError());
    /**/        return EXIT_FAILURE;
    /**/    }

            TTF_Init();
            if(TTF_Init() == -1)
            {
                fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
                exit(EXIT_FAILURE);
            }
            TTF_Font * font = TTF_OpenFont("arial.ttf",15);
            SDL_Color color={255,220,250};
            //SDL_Surface * surface1 = TTF_RenderText_Solid(font,"sidi",color);
            //SDL_Texture * texture1 = SDL_CreateTextureFromSurface(renderer, surface1);

    /**///***************************************************************************************************************

    // etat=-1 on est dans la phase d'identification
    // etat=0 et aux=0 choisir le mode de jeu
    // etat=1 et aux =1 en jeu
    // etat=2 regles de jeu affichées


    //déclarations

    POINT clic1,clic2;
    POINT hg1,hg2;
    NUMBOX numb;
    int ig=0;
    int etat=-2;
    int aux=-1;
    int var1=0;
    int nb_blanc=12;
    int nb_noir=12;
    tour=1;
    res1=0;
    res2=0;
    quit = false;


   //************************//
    init_plateau();
    init_reserve();
    affiche_fond(renderer);
    affiche_identification(renderer);
    SDL_RenderPresent(renderer);
    //********************//

    bool bool1,bool2;
    bool1=true;
    bool2=false;
 /*   int texW = 0;
    int texH = 0;
    SDL_QueryTexture(texture1, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = {465,200, texW, texH };
    SDL_RenderCopy(renderer, texture1, NULL, &dstrect);
    //SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);*/
    int i=0;
    while(!quit)
    {
        SDL_Keysym keysym;
        //clic1=attend_clic2();
        while( SDL_PollEvent( &event ) ) {
                //Si l'utilisateur ferme la fenêtre avec le X
                if( event.type == SDL_QUIT ) {
                    //On quitte le programme
                    quit = true; }
                if(event.type == SDL_KEYDOWN)
                {
                    keysym=event.key.keysym;
                    char s1[20];
                    strcpy(s1, SDL_GetKeyName(keysym.sym));
                    printf(" le premier %s \n",s1);
                    printf(" ici ici %s \n",SDL_GetKeyName(keysym.sym));
                    surface1 = TTF_RenderText_Solid(font,s1,color);
                    texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
                    int texW = 0;
                    int texH = 0;
                    SDL_QueryTexture(texture1, NULL, NULL, &texW, &texH);
                    SDL_Rect dstrect = {465+15*i,210, texW, texH };
                    SDL_RenderCopy(renderer, texture1, NULL, &dstrect);
                    //SDL_RenderCopy(renderer, texture, NULL, NULL);
                    i++;
                    SDL_RenderPresent(renderer);
                }
            }


   /*     //partie jeu
        clic1=attend_clic2();
        if(etat==-2 && est_dansPlateau(clic1))
        {
            gerer_event(window);
        }

        //verifie que l'utilisateur a bien s'identifier
        if(etat!=1 && etat!=0)
        {
            //clic1=attend_clic2();
            if(est_identifier(clic1))
            {
                etat=0;
                affiche_mode(renderer);
                SDL_RenderPresent(renderer);
            }

        }

        //****************************dans l'etat 0 choix mode de jeu *******************************

        if(etat==0)
        {
            clic1=attend_clic2();
            if((est_joueur_vs_ordinateur(clic1) || est_joueur_vs_joueur(clic1)))
            {
                etat=1;
                affiche_plateau(renderer,texture);
                afficher_main(renderer);
                SDL_RenderPresent(renderer);
            }

            if((est_regle_jeux(clic1)))
            {
                regles_jeux(renderer,texture,clic1,etat);
            }
        }


        //********************************dans l'etat 1 sur en mode jeu plateau ***************

        if(etat==1)
        {
             clic1=attend_clic2();
            afficher_main(renderer);
            SDL_RenderPresent(renderer);

            //********clic sur régles de jeu ***************

            regles_jeux(renderer,texture,clic1,etat);

            //********************** pions blancs ***********************
            if(tour==1)
            {
                //**********clic dans réserve blanc************
                if((est_dans_zone_reserve_blanc(clic1)) && nb_blanc>0)
                {
                    ig=1;
                    appliquer_clic_reserve_blanc(renderer,clic1,ig,nb_blanc);
                    nb_blanc--;
                    //tour=2;
                }

                if(est_dansPlateau(clic1) && est_blanc(clic1))
                {
                    ig=1;
                    appliquer_clic_blanc_dans_plateau(renderer,clic1,ig);
                }
            }

            //****************clic dans zone reserve noir ************************
            if(tour==2)
            {
                if(est_dans_zone_reserve_noir(clic1) && nb_noir>0 )
                {
                    ig=2;
                    appliquer_clic_reserve_noir(renderer,clic1,ig,nb_noir);
                    //tour=1;
                    nb_noir--;
                }

                if(est_dansPlateau(clic1) && est_noir(clic1))
                {
                    ig=2;
                    appliquer_clic_noir_dans_plateau(renderer,clic1,ig);
                }
            }
        }*/
    }
     //printf("text est :%s \n",text);



    //*******************************liberation de la mémoire*************************************
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_DestroyTexture(texture);
    SDL_DestroyTexture(texture1);
    SDL_FreeSurface(surface1);
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();

    return 0;
}
