#include "main.h"

//allocation de la mémoire
void reserver_memoire()
{
    SDL_Init(SDL_INIT_VIDEO);
    if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
}

//afficher le fond
void affiche_fond(SDL_Renderer *renderer)
{
    //mettre la couleur du fond
    SDL_SetRenderDrawColor(renderer,200,173,127,255);
    SDL_RenderClear(renderer);

    //dessiner les bordures
    SDL_SetRenderDrawColor(renderer,0,0,0,255);

    SDL_RenderDrawLine(renderer,0,100,width,100);
    SDL_RenderDrawLine(renderer,0,100+1,width,100+1);
    SDL_RenderDrawLine(renderer,0,500,width,500);
    SDL_RenderDrawLine(renderer,0,500+1,width,500+1);
    SDL_RenderDrawLine(renderer,320,100,320,500);
    SDL_RenderDrawLine(renderer,800,100,800,500);

    SDL_Surface *surface1 = NULL;
    SDL_Texture *texture1 = NULL;
       //******************************importer une image point d'interogation*********************************
    surface1 = SDL_LoadBMP("images/image.bmp");
    texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
    SDL_Rect dstrect1 = {1050,10,50,50};
    SDL_RenderCopy(renderer, texture1, NULL, &dstrect1);

     //******************************importer une image nom*********************************
    surface1 = SDL_LoadBMP("images/titre2.bmp");
    texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
    SDL_Rect dstrect_nom = {520,10,100,80};
    SDL_RenderCopy(renderer, texture1, NULL, &dstrect_nom);

    //*******************************importer une image score*********************************
    surface1 = SDL_LoadBMP("images/score.bmp");
    texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
    SDL_Rect dstrect2 = {890,10,100,60};
    SDL_RenderCopy(renderer, texture1, NULL, &dstrect2);
    //***************************************importer decor ***********************************
    surface1 = SDL_LoadBMP("images/decor.bmp");
    texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
    SDL_Rect dstrect_dec1 = {230,180,80,240};
    SDL_Rect dstrect_dec2 = {810,180,80,240};
    SDL_RenderCopy(renderer, texture1, NULL, &dstrect_dec1);
    SDL_RenderCopy(renderer, texture1, NULL, &dstrect_dec2);

         //*******************************importer une image cercles gauche et droite*********************************
   /* surface1 = SDL_LoadBMP("images/cercle.bmp");
    texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
    SDL_Rect dstrect3 = {60,200,20,240};
    SDL_Rect dstrect4 = {width-80,200,20,240};
    SDL_RenderCopy(renderer, texture1, NULL, &dstrect3);
    SDL_RenderCopy(renderer, texture1, NULL, &dstrect4);*/
    for(int i=0;i<12;i++)
    {
        surface1 = SDL_LoadBMP("images/cercle_reserve2.bmp");
        texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
        SDL_Rect dstrect_7 = {60,200+20*i,20,20};
        SDL_RenderCopy(renderer, texture1, NULL, &dstrect_7);
    }

    for(int i=0;i<12;i++)
    {
        surface1 = SDL_LoadBMP("images/cercle_reserve2.bmp");
        texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
        SDL_Rect dstrect_8 = {width-80,200+20*i,20,20};
        SDL_RenderCopy(renderer, texture1, NULL, &dstrect_8);
    }

              //*******************************importer une image reserve pions*********************************
    for(int i=0;i<6;i++)
    {
        surface1 = SDL_LoadBMP("images/reserve_blanc.bmp");
        texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
        SDL_Rect dstrect_6 = {105,180+40*i,40,40};
        SDL_RenderCopy(renderer, texture1, NULL, &dstrect_6);
    }

    for(int i=0;i<6;i++)
    {
        surface1 = SDL_LoadBMP("images/reserve_blanc.bmp");
        texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
        SDL_Rect dstrect_6 = {105+40,180+40*i,40,40};
        SDL_RenderCopy(renderer, texture1, NULL, &dstrect_6);
    }

    for(int i=0;i<6;i++)
    {
        surface1 = SDL_LoadBMP("images/reserve_noir.bmp");
        texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
        SDL_Rect dstrect_7 = {width-105-80,180+40*i,40,40};
        SDL_RenderCopy(renderer, texture1, NULL, &dstrect_7);
    }

    for(int i=0;i<6;i++)
    {
        surface1 = SDL_LoadBMP("images/reserve_noir.bmp");
        texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
        SDL_Rect dstrect_7 = {width-105-80+40,180+40*i,40,40};
        SDL_RenderCopy(renderer, texture1, NULL, &dstrect_7);
    }

    SDL_DestroyTexture(texture1);
    SDL_FreeSurface(surface1);

}

void affiche_identification( SDL_Renderer *renderer)
{
    SDL_Texture *texture1 = NULL;
    SDL_Surface *surface1 = NULL;
    SDL_Texture *texture2 = NULL;
    SDL_Surface *surface2 = NULL;
    surface1 = SDL_LoadBMP("images/identif_new.bmp");
    texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
    surface2 = SDL_LoadBMP("images/boutton_identification.bmp");
    texture2 = SDL_CreateTextureFromSurface(renderer, surface2);
    SDL_Rect dstrect1 = {320,100,480,400};
    SDL_Rect dstrect2 = {560,340,160,80};
    SDL_RenderCopy(renderer, texture1, NULL, &dstrect1);
    SDL_RenderCopy(renderer, texture2, NULL, &dstrect2);
    //dessiner rectangle entourage
    SDL_Rect rect0={320,100,480,400};
    SDL_Rect rect1={320+1,100+1,480+1,400+1};
    SDL_RenderDrawRect(renderer,&rect0);
    SDL_RenderDrawRect(renderer,&rect1);
    SDL_DestroyTexture(texture1);
    SDL_DestroyTexture(texture2);
    SDL_FreeSurface(surface1);
    SDL_FreeSurface(surface2);
}

void affiche_mode(SDL_Renderer *renderer)
{
    SDL_Surface *surface1 = NULL;
    SDL_Texture *texture1 = NULL;
    SDL_Surface *surface2 = NULL;
    SDL_Texture *texture2 = NULL;
    SDL_Surface *surface3 = NULL;
    SDL_Texture *texture3 = NULL;
    surface1 = SDL_LoadBMP("images/zone_pion.bmp");
    surface2 = SDL_LoadBMP("images/joueurVSjoueur.bmp");
    surface3 = SDL_LoadBMP("images/joueurVSordinateur.bmp");
    texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
    texture2 = SDL_CreateTextureFromSurface(renderer, surface2);
    texture3 = SDL_CreateTextureFromSurface(renderer, surface3);
    SDL_Rect dstrect1 = {321,101,480-1,400-1};
    SDL_Rect dstrect2 = {440,180,240,80};
    SDL_Rect dstrect3 = {440,340,240,80};
    SDL_RenderCopy(renderer, texture1, NULL, &dstrect1);
    SDL_RenderCopy(renderer, texture2, NULL, &dstrect2);
    SDL_RenderCopy(renderer, texture3, NULL, &dstrect3);
    SDL_DestroyTexture(texture1);
    SDL_DestroyTexture(texture2);
    SDL_DestroyTexture(texture3);
    SDL_FreeSurface(surface1);
    SDL_FreeSurface(surface2);
    SDL_FreeSurface(surface3);
}


void affiche_plateau(SDL_Renderer *renderer,  SDL_Texture *texture)
{
    SDL_Rect dst1 = {320, 100, 0, 0};
    SDL_SetRenderTarget(renderer, texture); // La texture est la cible de rendu, maintenant, on dessine sur la texture.
    SDL_SetRenderDrawColor(renderer,167,103,38,255);
    SDL_RenderClear(renderer);
    //mettre la couleur en noir
    SDL_SetRenderDrawColor(renderer,0,0,0,255);

    //dessiner rectangle entourage
    SDL_Rect rect0={0,0,480,400};
    SDL_Rect rect1={1,1,480-1,400-1};
    SDL_RenderDrawRect(renderer,&rect0);
    SDL_RenderDrawRect(renderer,&rect1);

    //lignes horizontales
    for(int i=1;i<5;i++)
    {
      SDL_RenderDrawLine(renderer,0,80*i,480,80*i);
    }

    //lignes verticales
    for(int i=1;i<6;i++)
    {
      SDL_RenderDrawLine(renderer,80*i,0,80*i,400);
    }

    SDL_SetRenderTarget(renderer, NULL); /* Le renderer est la cible de rendu. */

     /* On récupère les dimensions de la texture, on la copie sur le renderer et on met à jour l’écran. */
    SDL_QueryTexture(texture, NULL, NULL, &dst1.w, &dst1.h);
    SDL_RenderCopy(renderer, texture, NULL, &dst1);

}

void affiche_regles(SDL_Renderer *renderer)
{
    SDL_Surface *surface1 = NULL;
    SDL_Texture *texture1 = NULL;
    SDL_Surface *surface2 = NULL;
    SDL_Texture *texture2 = NULL;
    surface1 = SDL_LoadBMP("images/regles.bmp");
    texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
    surface2 = SDL_LoadBMP("images/quitter.bmp");
    texture2 = SDL_CreateTextureFromSurface(renderer, surface2);
    SDL_Rect dstrect1 = {321,101,480-1,400-1};
    SDL_Rect dstrect2 = {510,450,100,40};
    SDL_RenderCopy(renderer, texture1, NULL, &dstrect1);
    SDL_RenderCopy(renderer, texture2, NULL, &dstrect2);
    SDL_DestroyTexture(texture1);
    SDL_DestroyTexture(texture2);
    SDL_FreeSurface(surface1);
    SDL_FreeSurface(surface2);
}

void afficher_coup(SDL_Renderer *renderer)
{

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(plateau[i][j].typeC==REMPLIE && plateau[i][j].coulP==NOIR)
            {
                NUMBOX numB;
                numB.l=i;
                numB.c=j;
                POINT hg;
                hg=NUMBOX_to_POINTHG(numB);
                //hg.x=hg.x+10;
                //hg.y=hg.y+10;
                affiche_pion_noir(renderer,hg);

            }
            if(plateau[i][j].typeC==REMPLIE && plateau[i][j].coulP==BLANC)
            {
                NUMBOX numB;
                numB.l=i;
                numB.c=j;
                POINT hg;
                hg=NUMBOX_to_POINTHG(numB);
                //hg.x=hg.x+10;
                //hg.y=hg.y+10;
                affiche_pion_blanc(renderer,hg);

            }

        }
    }

}

void afficher_coup_reserve(SDL_Renderer *renderer)
{

    for(int i=0;i<6;i++)
    {
        for(int j=0;j<2;j++)
        {
            if(tab_blanc[i][j].typeC==REMPLIE && tab_blanc[i][j].coulP==BLANC)
            {
                NUMBOX numB;
                numB.l=i;
                numB.c=j;
                POINT hg;
                hg=NUMBOX_to_POINTHG_reserve_blanc(numB);
                affiche_pion_blanc_reserve(renderer,hg);

            }
            if(tab_noir[i][j].typeC==REMPLIE && tab_noir[i][j].coulP==NOIR)
            {
                NUMBOX numB;
                numB.l=i;
                numB.c=j;
                POINT hg;
                hg=NUMBOX_to_POINTHG_reserve_noir(numB);
                affiche_pion_noir_reserve(renderer,hg);

            }

        }
    }

}


void affiche_pion_blanc( SDL_Renderer *renderer ,POINT hg)
{

    SDL_Texture *texture4 = NULL;
    SDL_Surface *surface4 = NULL;
    surface4 = SDL_LoadBMP("images/pion_blanc.bmp");
    texture4 = SDL_CreateTextureFromSurface(renderer, surface4);
    SDL_Rect dstrect_4 = {hg.x+8,hg.y+8,60,60};
    SDL_RenderCopy(renderer, texture4, NULL, &dstrect_4);
    SDL_DestroyTexture(texture4);
    SDL_FreeSurface(surface4);


}

void affiche_pion_noir( SDL_Renderer *renderer ,POINT hg)
{

    SDL_Texture *texture4 = NULL;
    SDL_Surface *surface4 = NULL;
    surface4 = SDL_LoadBMP("images/pion_noir.bmp");
    texture4 = SDL_CreateTextureFromSurface(renderer, surface4);
    SDL_Rect dstrect_5 = {hg.x+8,hg.y+8,60,60};
    SDL_RenderCopy(renderer, texture4, NULL, &dstrect_5);
    SDL_DestroyTexture(texture4);
    SDL_FreeSurface(surface4);


}

void effacer_pion(SDL_Renderer *renderer ,POINT p)
{
    //probleme de couleur
    SDL_Surface *surface1 = NULL;
    SDL_Texture *texture1 = NULL;
    surface1 = SDL_LoadBMP("images/zone_pion.bmp");
    texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
    SDL_Rect dstrect = {p.x+2,p.y+2,78,78};
    SDL_RenderCopy(renderer, texture1, NULL, &dstrect);
}



void affiche_pion_blanc_reserve(SDL_Renderer *renderer,POINT p)
{
    SDL_Surface *surface1 = NULL;
    SDL_Texture *texture1 = NULL;
    surface1 = SDL_LoadBMP("images/reserve_blanc.bmp");
    texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
    SDL_Rect dstrect_6 = {p.x,p.y,40,40};
    SDL_RenderCopy(renderer, texture1, NULL, &dstrect_6);
}


void affiche_pion_noir_reserve(SDL_Renderer *renderer,POINT p)
{
    SDL_Surface *surface1 = NULL;
    SDL_Texture *texture1 = NULL;
    surface1 = SDL_LoadBMP("images/reserve_noir.bmp");
    texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
    SDL_Rect dstrect_6 = {p.x,p.y,40,40};
    SDL_RenderCopy(renderer, texture1, NULL, &dstrect_6);
}


void effacer_pion_reserve(SDL_Renderer *renderer,POINT p)
{
    SDL_Surface *surface1 = NULL;
    SDL_Texture *texture1 = NULL;
    surface1 = SDL_LoadBMP("images/efface_reserve.bmp");
    texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
    SDL_Rect dstrect = {p.x,p.y,40,40};
    SDL_RenderCopy(renderer, texture1, NULL, &dstrect);
}


void affiche_sur_brillance_blanc_reserve(SDL_Renderer *renderer,POINT p)
{
    SDL_Surface *surface1 = NULL;
    SDL_Texture *texture1 = NULL;
    surface1 = SDL_LoadBMP("images/brill_blanc3.bmp");
    texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
    SDL_Rect dstrect = {p.x,p.y,40,40};
    SDL_RenderCopy(renderer, texture1, NULL, &dstrect);
}

void affiche_sur_brillance_noir_reserve(SDL_Renderer *renderer,POINT p)
{
    SDL_Surface *surface1 = NULL;
    SDL_Texture *texture1 = NULL;
    surface1 = SDL_LoadBMP("images/brill_noir3.bmp");
    texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
    SDL_Rect dstrect = {p.x,p.y,40,40};
    SDL_RenderCopy(renderer, texture1, NULL, &dstrect);
}

void affiche_sur_brillance_blanc(SDL_Renderer *renderer,POINT p)
{
    SDL_Surface *surface1 = NULL;
    SDL_Texture *texture1 = NULL;
    surface1 = SDL_LoadBMP("images/surbrill_blanc.bmp");
    texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
    SDL_Rect dstrect = {p.x+8,p.y+8,60,60};
    SDL_RenderCopy(renderer, texture1, NULL, &dstrect);
}

void affiche_sur_brillance_noir(SDL_Renderer *renderer,POINT p)
{
    SDL_Surface *surface1 = NULL;
    SDL_Texture *texture1 = NULL;
    surface1 = SDL_LoadBMP("images/surbrill_noir.bmp");
    texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
    SDL_Rect dstrect = {p.x+8,p.y+8,60,60};
    SDL_RenderCopy(renderer, texture1, NULL, &dstrect);
}

void regles_jeux(SDL_Renderer *renderer,SDL_Texture *texture,POINT p,int etat)
{
    POINT clic2;
    if(est_regle_jeux(p))
    {
        affiche_regles(renderer);
        SDL_RenderPresent(renderer);
        if(etat==1)
        {
            do{
                clic2=attend_clic2();
            }while(!est_quitter_regles(clic2));
            affiche_plateau(renderer,texture);
            afficher_coup(renderer);
            SDL_RenderPresent(renderer);
        }

        if(etat==0)
        {
            do{
                clic2=attend_clic2();
            }while(!est_quitter_regles(clic2));
            affiche_mode(renderer);
            SDL_RenderPresent(renderer);
        }

    }
}

void afficher_main(SDL_Renderer *renderer)
{
    SDL_Surface *surface1 = NULL;
    SDL_Texture *texture1 = NULL;
    if(tour==1)
        surface1 = SDL_LoadBMP("images/main_blanche.bmp");
    if(tour==2)
        surface1 = SDL_LoadBMP("images/main_noire.bmp");
    texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
    SDL_Rect dstrect = {480,510,160,80};
    SDL_RenderCopy(renderer, texture1, NULL, &dstrect);
}


void re_Afficher_pion_blanc(SDL_Renderer *renderer,POINT hg1)
{
        effacer_pion(renderer,hg1);
        affiche_pion_blanc(renderer,hg1);
        afficher_coup(renderer);
        SDL_RenderPresent(renderer);
}

void re_Afficher_pion_noir(SDL_Renderer *renderer,POINT hg1)
{
        effacer_pion(renderer,hg1);
        affiche_pion_noir(renderer,hg1);
        afficher_coup(renderer);
        SDL_RenderPresent(renderer);
}


void griser_pion(SDL_Renderer *renderer,int tour )
{

    NUMBOX numB,numB1;
    POINT hg,hg1;

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(tour==2 && plateau[i][j].coulP==BLANC)
            {
                numB.l=i;
                numB.c=j;
                hg=NUMBOX_to_POINTHG(numB);
                affiche_sur_brillance_blanc(renderer,hg);
                SDL_RenderPresent(renderer);
            }

            if(tour==1 && plateau[i][j].coulP==NOIR)
            {
                numB.l=i;
                numB.c=j;
                hg=NUMBOX_to_POINTHG(numB);
                affiche_sur_brillance_noir(renderer,hg);
                SDL_RenderPresent(renderer);

            }

        }
    }



}

void griser_pion_reserve_blanc(SDL_Renderer *renderer)
{
    POINT hg1;
    NUMBOX numB1;
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<2;j++)
        {
           if(tab_blanc[i][j].coulP==BLANC)
            {
                numB1.l=i;
                numB1.c=j;
                hg1=NUMBOX_to_POINTHG_reserve_blanc(numB1);
                affiche_sur_brillance_blanc_reserve(renderer,hg1);
                SDL_RenderPresent(renderer);
            }

        }
    }
}

void griser_pion_reserve_noir(SDL_Renderer *renderer)
{
    POINT hg1;
    NUMBOX numB1;
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<2;j++)
        {
           if((tab_noir[i][j].coulP==NOIR))
            {
                numB1.l=i;
                numB1.c=j;
                hg1=NUMBOX_to_POINTHG_reserve_noir(numB1);
                affiche_sur_brillance_noir_reserve(renderer,hg1);
                SDL_RenderPresent(renderer);
            }

        }
    }
}

/*void verifie_tab()
{
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<2;j++)
        {
            if(tab_blanc[i][j].coulP==BLANC) printf("(%d,%d) ",i,j);
            else printf("(n,n) ");
        }
        printf("\n");
    }
        printf("***************noir**************\n");

    for(int i=0;i<6;i++)
    {
        for(int j=0;j<2;j++)
        {
            if(tab_noir[i][j].coulP==NOIR) printf("(%d,%d) ",i,j);
            else printf("(n,n) ");
        }
        printf("\n");
    }
}*/

void remplir_reserve_blanc(SDL_Renderer *renderer,POINT hg)
{
    SDL_Texture *texture1 = NULL;
    SDL_Surface *surface1 = NULL;
    surface1 = SDL_LoadBMP("images/remplir_reserve_blanc3.bmp");
    texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
    SDL_Rect dstrect1 = {hg.x,hg.y,20,20};
    SDL_RenderCopy(renderer, texture1, NULL, &dstrect1);

    SDL_DestroyTexture(texture1);
    SDL_FreeSurface(surface1);
}

void remplir_reserve_noir(SDL_Renderer *renderer,POINT hg)
{
    SDL_Texture *texture1 = NULL;
    SDL_Surface *surface1 = NULL;
    surface1 = SDL_LoadBMP("images/remplir_reserve_noir3.bmp");
    texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
    SDL_Rect dstrect1 = {hg.x,hg.y,20,20};
    SDL_RenderCopy(renderer, texture1, NULL, &dstrect1);

    SDL_DestroyTexture(texture1);
    SDL_FreeSurface(surface1);
}


