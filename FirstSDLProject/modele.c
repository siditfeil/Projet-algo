#include "main.h"

void init_plateau()
{
	int l,c;
	for(l=0;l<5;l++)
	{
		for(c=0;c<6;c++)
		{
			plateau[l][c].typeC = VIDE;
			plateau[l][c].coulP = AUTRE;
		}
	}
}

void init_reserve()
{
    int l,c;
	for(l=0;l<6;l++)
	{
		for(c=0;c<2;c++)
		{
			tab_blanc[l][c].coulP = BLANC;
			tab_blanc[l][c].typeC = REMPLIE;

			tab_noir[l][c].coulP = NOIR;
			tab_noir[l][c].typeC = REMPLIE;
		}
	}
}

bool est_joueur_vs_joueur(POINT p)
{
    if( (p.x>=440 && p.x<=680) && (p.y>=180 && p.y<=260) ) return true;
    else return false;
}

bool est_joueur_vs_ordinateur(POINT p)
{
    if( (p.x>=440 && p.x<=680) && (p.y>=340 && p.y<=420) ) return true;
    else return false;
}

void appliquer_coup(POINT p,int ig)
{
    NUMBOX numb;
    numb=point_to_numBox(p);
    if(plateau[numb.l][numb.c].typeC==VIDE && plateau[numb.l][numb.c].coulP==AUTRE)
    {

        if(ig==1)
        {
            plateau[numb.l][numb.c].typeC=REMPLIE;
            plateau[numb.l][numb.c].coulP=BLANC;
        }
        if(ig==2)
        {
            plateau[numb.l][numb.c].typeC=REMPLIE;
            plateau[numb.l][numb.c].coulP=NOIR;
        }

    }
}

void mettre_a_jour_case(POINT p)
{
    NUMBOX numb;
    numb=point_to_numBox(p);
    plateau[numb.l][numb.c].typeC=VIDE;
    plateau[numb.l][numb.c].coulP=AUTRE;
}

void mettre_a_jour_case_reserve_blanc(POINT p)
{
    NUMBOX numb;
    numb=point_to_numBox_reserve_blanc(p);
    tab_blanc[numb.l][numb.c].typeC=VIDE;
    tab_blanc[numb.l][numb.c].coulP=AUTRE;
}

void mettre_a_jour_case_reserve_noir(POINT p)
{
    NUMBOX numb;
    numb=point_to_numBox_reserve_noir(p);
    tab_noir[numb.l][numb.c].typeC=VIDE;
    tab_noir[numb.l][numb.c].coulP=AUTRE;
}

bool est_case_vide(POINT p)
{
    NUMBOX numb;
    numb=point_to_numBox(p);
   if(plateau[numb.l][numb.c].typeC==VIDE && plateau[numb.l][numb.c].coulP==AUTRE ) return true;
   return false;
}

bool est_coup_valide(POINT p)
{
    NUMBOX numb;
    numb=point_to_numBox(p);
    if(plateau[numb.l][numb.c].typeC==VIDE ) return true ;
    else return false;
}

bool est_blanc(POINT p)
{
    NUMBOX numb;
    numb=point_to_numBox(p);
    if(plateau[numb.l][numb.c].typeC==REMPLIE && plateau[numb.l][numb.c].coulP==BLANC ) return true ;
    else return false;
}

bool est_noir(POINT p)
{
    NUMBOX numb;
    numb=point_to_numBox(p);
    if(plateau[numb.l][numb.c].typeC==REMPLIE && plateau[numb.l][numb.c].coulP==NOIR ) return true ;
    else return false;
}

bool est_dansPlateau(POINT p)
{
    if( (p.x>=320 && p.x<=800) && (p.y>=100 && p.y<=500) ) return true;
    else return false;

}

bool est_regle_jeux(POINT p)
{
     if( (p.x>=1050 && p.x<=1100) && (p.y>=10 && p.y<=60) ) return true;
     else return false ;
}

bool est_identifier(POINT p)
{
    if( (p.x>=560 && p.x<=740) && (p.y>=340 && p.y<=420) ) return true;
    else return false ;
}

bool est_dans_zone_reserve_blanc(POINT p)
{
    if( (p.x>=105 && p.x<=185) && (p.y>=180 && p.y<=420) ) return true;
    else return false ;
}


bool est_dans_zone_reserve_noir(POINT p)
{
    if( (p.x>=935 && p.x<=1015) && (p.y>=180 && p.y<=420) ) return true;
    else return false;
}

bool est_quitter_regles(POINT p)
{
    if( (p.x>=510 && p.x<=610) && (p.y>=450 && p.y<=490) ) return true;
    else return false;
}


void appliquer_clic_reserve_blanc(SDL_Renderer *renderer,POINT clic1,int ig,int nb_blanc)
{
    POINT clic2,hg1;
    NUMBOX numb;
    hg1=point_to_pointHG_reserveBlanc(clic1);
    affiche_sur_brillance_blanc_reserve(renderer,hg1);
    SDL_RenderPresent(renderer);
    clic2=attend_clic2();
    if(est_dansPlateau(clic2) && est_coup_valide(clic2))
    {
        appliquer_coup(clic2,ig);
        numb=point_to_numBox_reserve_blanc(hg1);
        tab_blanc[numb.l][numb.c].coulP=AUTRE;
        tab_blanc[numb.l][numb.c].typeC=VIDE;
        effacer_pion_reserve(renderer,hg1);
        //nb_blanc--;
        tour=2;
        afficher_main(renderer);
        afficher_coup(renderer);
        SDL_RenderPresent(renderer);
    }
    else
    {
        affiche_pion_blanc_reserve(renderer,hg1);
        afficher_coup(renderer);
        SDL_RenderPresent(renderer);
        //SDL_ShowSimpleMessageBox(0, "Eror", "coup invalide", window);
    }
}


void appliquer_clic_reserve_noir(SDL_Renderer *renderer,POINT clic1,int ig,int nb_noir)
{
    POINT clic2,hg1;
    NUMBOX numb;
    hg1=point_to_pointHG_reserveNoir(clic1);
    affiche_sur_brillance_noir_reserve(renderer,hg1);
    SDL_RenderPresent(renderer);
    clic2=attend_clic2();
    if(est_dansPlateau(clic2) && est_coup_valide(clic2))
    {
        appliquer_coup(clic2,ig);
        numb=point_to_numBox_reserve_noir(hg1);
        tab_noir[numb.l][numb.c].coulP=AUTRE;
        tab_noir[numb.l][numb.c].typeC=VIDE;
        effacer_pion_reserve(renderer,hg1);
        //nb_blanc--;
        tour=1;
        afficher_main(renderer);
        afficher_coup(renderer);
        SDL_RenderPresent(renderer);
    }
    else
    {
        affiche_pion_noir_reserve(renderer,hg1);
        afficher_coup(renderer);
        SDL_RenderPresent(renderer);
        //SDL_ShowSimpleMessageBox(0, "Eror", "coup invalide", window);
    }
}

void jouer_blanc(SDL_Renderer *renderer,POINT clic2,POINT hg1,int ig)
{
    appliquer_coup(clic2,ig);
    mettre_a_jour_case(hg1);
    effacer_pion(renderer,hg1);
    //tour=2;
    afficher_main(renderer);
    afficher_coup(renderer);
    SDL_RenderPresent(renderer);
}

void jouer_noir(SDL_Renderer *renderer,POINT clic2,POINT hg1,int ig)
{
    appliquer_coup(clic2,ig);
    mettre_a_jour_case(hg1);
    effacer_pion(renderer,hg1);
    //tour=1;
    afficher_main(renderer);
    afficher_coup(renderer);
    SDL_RenderPresent(renderer);
}

void appliquer_clic_blanc_dans_plateau(SDL_Renderer *renderer,POINT clic1,int ig)
{
    POINT hg1,clic2;
    hg1=point_to_pointHG(clic1);
    affiche_sur_brillance_blanc(renderer,hg1);
    SDL_RenderPresent(renderer);
    clic2=attend_clic2();
    if(est_dansPlateau(clic2) )
    {
        POINT hg2,p;
        hg2=point_to_pointHG(clic2);
        if(est_coup_valide(clic2))
        {
            int aux1=-1;
            if(est_deplacement_possible(clic1,clic2))
            {
                jouer_blanc(renderer,clic2,hg1,ig);
                aux1=1;
                tour=2;
                afficher_main(renderer);
                SDL_RenderPresent(renderer);
            }

            if(est_jeu_possible_gauche(clic1,clic2,tour))
            {
                jouer_blanc(renderer,clic2,hg1,ig);
                aux1=1;
                p.x=hg1.x-80;   p.y=hg1.y;
                manger_pion_adverse(renderer,p);
                griser_pion(renderer,tour);
                griser_pion_reserve_noir(renderer);
                manger_second_pion_adverse(renderer);
                tour=2;
                afficher_main(renderer);
                SDL_RenderPresent(renderer);
            }

            if(est_jeu_possible_droit(clic1,clic2,tour))
            {
                jouer_blanc(renderer,clic2,hg1,ig);
                aux1=1;
                p.x=hg1.x+80;  p.y=hg1.y;
                manger_pion_adverse(renderer,p);
                griser_pion(renderer,tour);
                griser_pion_reserve_noir(renderer);
                manger_second_pion_adverse(renderer);
                tour=2;
                afficher_main(renderer);
                SDL_RenderPresent(renderer);
            }

            if(est_jeu_possible_haut(clic1,clic2,tour))
            {
                jouer_blanc(renderer,clic2,hg1,ig);
                aux1=1;
                p.x=hg1.x;   p.y=hg1.y-80;
                manger_pion_adverse(renderer,p);
                griser_pion(renderer,tour);
                griser_pion_reserve_noir(renderer);
                manger_second_pion_adverse(renderer);
                tour=2;
                afficher_main(renderer);
                SDL_RenderPresent(renderer);
            }

            if(est_jeu_possible_bas(clic1,clic2,tour))
            {
                jouer_blanc(renderer,clic2,hg1,ig);
                aux1=1;
                p.x=hg1.x;   p.y=hg1.y+80;
                manger_pion_adverse(renderer,p);
                griser_pion(renderer,tour);
                griser_pion_reserve_noir(renderer);
                manger_second_pion_adverse(renderer);
                tour=2;
                afficher_main(renderer);
                SDL_RenderPresent(renderer);
            }


            if(aux1==-1) re_Afficher_pion_blanc(renderer,hg1);

        }
        else re_Afficher_pion_blanc(renderer,hg1);
    }
    else
    {
        re_Afficher_pion_blanc(renderer,hg1);
    }
}


void appliquer_clic_noir_dans_plateau(SDL_Renderer *renderer,POINT clic1,int ig)
{
    POINT hg1,clic2,p;
    hg1=point_to_pointHG(clic1);
    affiche_sur_brillance_noir(renderer,hg1);
    SDL_RenderPresent(renderer);
    clic2=attend_clic2();
    if(est_dansPlateau(clic2) )
    {
        if(est_coup_valide(clic2))
        {
            int aux2=-1;

            if(est_deplacement_possible(clic1,clic2))
            {
                jouer_noir(renderer,clic2,hg1,ig);
                aux2=1;
                tour=1;
                afficher_main(renderer);
                SDL_RenderPresent(renderer);
            }

            if(est_jeu_possible_gauche(clic1,clic2,tour))
            {
                jouer_blanc(renderer,clic2,hg1,ig);
                aux2=1;
                p.x=hg1.x-80;   p.y=hg1.y;
                manger_pion_adverse(renderer,p);
                griser_pion(renderer,tour);
                griser_pion_reserve_blanc(renderer);
                manger_second_pion_adverse(renderer);
                tour=1;
                afficher_main(renderer);
                SDL_RenderPresent(renderer);
            }


            if(est_jeu_possible_droit(clic1,clic2,tour))
            {
                jouer_blanc(renderer,clic2,hg1,ig);
                aux2=1;
                p.x=hg1.x+80;   p.y=hg1.y;
                manger_pion_adverse(renderer,p);
                griser_pion(renderer,tour);
                griser_pion_reserve_blanc(renderer);
                manger_second_pion_adverse(renderer);
                tour=1;
                afficher_main(renderer);
                SDL_RenderPresent(renderer);
            }

            if(est_jeu_possible_haut(clic1,clic2,tour))
            {
                jouer_blanc(renderer,clic2,hg1,ig);
                aux2=1;
                p.x=hg1.x;
                p.y=hg1.y-80;
                manger_pion_adverse(renderer,p);
                griser_pion(renderer,tour);
                griser_pion_reserve_blanc(renderer);
                manger_second_pion_adverse(renderer);
                tour=1;
                afficher_main(renderer);
                SDL_RenderPresent(renderer);
            }

            if(est_jeu_possible_bas(clic1,clic2,tour))
            {
                jouer_blanc(renderer,clic2,hg1,ig);
                aux2=1;
                p.x=hg1.x;   p.y=hg1.y+80;
                manger_pion_adverse(renderer,p);
                griser_pion(renderer,tour);
                griser_pion_reserve_blanc(renderer);
                manger_second_pion_adverse(renderer);
                tour=1;
                afficher_main(renderer);
                SDL_RenderPresent(renderer);
            }

            if(aux2==-1) re_Afficher_pion_noir(renderer,hg1);

        }
        else re_Afficher_pion_noir(renderer,hg1);
    }
    else
    {
        re_Afficher_pion_noir(renderer,hg1);
    }
}



bool est_deplacement_possible(POINT p1,POINT p2)
{
    POINT hg1,hg2;
    hg1=point_to_pointHG(p1);
    hg2=point_to_pointHG(p2);
    bool var1=(hg2.x==hg1.x-80);
    bool var2=(hg2.x==hg1.x+80);
    bool var3=(hg2.y==hg1.y);
    bool var4=(hg2.y==hg1.y-80);
    bool var5=(hg2.y==hg1.y+80);
    bool var6=(hg2.x==hg1.x);
    if((var1 && var3 ) || (var2 && var3 ) || (var4 && var6 ) || (var5 && var6 )  ) return true;
    else return false ;
}


bool est_jeu_possible_gauche(POINT p1,POINT p2,int tour)
{
    POINT hg1,hg2,hg3;
    int l,c;
    NUMBOX numb1,numb2;
    hg1=point_to_pointHG(p1);
    hg2=point_to_pointHG(p2);
    numb1=point_to_numBox(hg1);
    numb2=point_to_numBox(hg2);
    bool var1;
    if(tour==1) var1=(plateau[numb1.l][numb1.c-1].coulP==NOIR);
    if(tour==2) var1=(plateau[numb1.l][numb1.c-1].coulP==BLANC);
    if((numb1.l==numb2.l) && (numb1.c==(numb2.c+2)) && var1)
        return true ;
    else return false;

}

bool est_jeu_possible_droit(POINT p1,POINT p2,int tour)
{
    POINT hg1,hg2,hg3;
    int l,c;
    NUMBOX numb1,numb2;
    hg1=point_to_pointHG(p1);
    hg2=point_to_pointHG(p2);
    //hg3.x=hg1.x+80;    hg3.y=hg1.y;
    numb1=point_to_numBox(hg1);
    numb2=point_to_numBox(hg2);
    bool var1;
    if(tour==1) var1=(plateau[numb1.l][numb1.c+1].coulP==NOIR);
    if(tour==2) var1=(plateau[numb1.l][numb1.c+1].coulP==BLANC);
    //bool var2=(plateau[numb1.l][numb1.c].coulP != plateau[numb1.l][numb1.c+1].coulP);
    if((hg2.x==hg1.x+160 && hg2.y==hg1.y) && var1)
    {
        return true;
    }
    else return false;

}

bool est_jeu_possible_haut(POINT p1,POINT p2,int tour)
{
    POINT hg1,hg2;
    int l,c;
    NUMBOX numb1,numb2;
    hg1=point_to_pointHG(p1);
    hg2=point_to_pointHG(p2);
    numb1=point_to_numBox(hg1);
    numb2=point_to_numBox(hg2);
    bool var1;
    if(tour==1) var1=(plateau[numb1.l-1][numb1.c].coulP==NOIR);
    if(tour==2) var1=(plateau[numb1.l-1][numb1.c].coulP==BLANC);
    if((hg2.x==hg1.x && hg2.y==hg1.y-160) && var1)
        return true ;
    else return false;

}

bool est_jeu_possible_bas(POINT p1,POINT p2,int tour)
{
    POINT hg1,hg2,hg3;
    int l,c;
    NUMBOX numb1,numb2;
    hg1=point_to_pointHG(p1);
    hg2=point_to_pointHG(p2);
    numb1=point_to_numBox(hg1);
    numb2=point_to_numBox(hg2);
    bool var1;
    if(tour==1) var1=(plateau[numb1.l+1][numb1.c].coulP==NOIR);
    if(tour==2) var1=(plateau[numb1.l+1][numb1.c].coulP==BLANC);
    if((hg2.x==hg1.x && hg2.y==hg1.y+160) && var1)
    {
        return true ;
    }
    else return false;

}

void manger_pion_adverse(SDL_Renderer *renderer,POINT p)
{
    mettre_a_jour_case(p);
    effacer_pion(renderer,p);
    SDL_RenderPresent(renderer);
}

void manger_second_pion_adverse(SDL_Renderer *renderer)
{
    POINT clic3,hg1,hg2,hg3,hg4;
    NUMBOX numb1,numb2,numb3;
    clic3=attend_clic2();
    if(est_dansPlateau(clic3))
    {
        hg1=point_to_pointHG(clic3);
        mettre_a_jour_case(hg1);
        effacer_pion(renderer,hg1);
        afficher_coup(renderer);
        afficher_coup_reserve(renderer);
        if(tour==1)
        {
            hg4.x=60;   hg4.y=200+20*res1;
           remplir_reserve_noir(renderer,hg4) ;
           SDL_RenderPresent(renderer);
           res1++;
            hg4.x=60;   hg4.y=200+20*res1;
           remplir_reserve_noir(renderer,hg4) ;
           SDL_RenderPresent(renderer);
           res1++;
        }
        if(tour==2)
        {
            hg4.x=width-80;   hg4.y=200+20*res2;
           remplir_reserve_blanc(renderer,hg4) ;
           SDL_RenderPresent(renderer);
           res2++;
            hg4.x=width-80;   hg4.y=200+20*res2;
           remplir_reserve_blanc(renderer,hg4) ;
           SDL_RenderPresent(renderer);
           res2++;
        }
        SDL_RenderPresent(renderer);
    }

    if(est_dans_zone_reserve_blanc(clic3))
    {
        hg2=point_to_pointHG_reserveBlanc(clic3);
        mettre_a_jour_case_reserve_blanc(hg2);
        effacer_pion_reserve(renderer,hg2);
        afficher_coup(renderer);
        afficher_coup_reserve(renderer);
        hg4.x=width-80;   hg4.y=200+20*res2;
        remplir_reserve_blanc(renderer,hg4) ;
        SDL_RenderPresent(renderer);
        res2++;
        hg4.x=width-80;   hg4.y=200+20*res2;
        remplir_reserve_blanc(renderer,hg4) ;
        SDL_RenderPresent(renderer);
        res2++;
    }

    if(est_dans_zone_reserve_noir(clic3))
    {
        hg3=point_to_pointHG_reserveNoir(clic3);
        mettre_a_jour_case_reserve_noir(hg3);
        effacer_pion_reserve(renderer,hg3);
        afficher_coup(renderer);
        afficher_coup_reserve(renderer);
        hg4.x=60;   hg4.y=200+20*res1;
        remplir_reserve_noir(renderer,hg4) ;
        res1++;
        hg4.x=60;   hg4.y=200+20*res1;
        remplir_reserve_noir(renderer,hg4) ;
        SDL_RenderPresent(renderer);
        res1++;
    }


}

void ecrire_score_dans_fichier(char nom[])
{
    FILE* fichier = NULL;

    fichier = fopen("score.txt", "w");

    if (fichier != NULL)
    {
        //fputs("\n",fichier);
        fputs(nom , fichier);
        fputs("            " , fichier);
        fputs("G:" , fichier);
        fputs("    D:" , fichier);
        fputs("\n" , fichier);
        fclose(fichier);
    }
    else
    {
        // On affiche un message d'erreur si on veut
        printf("Impossible d'ouvrir le fichier test.txt");
    }
}

