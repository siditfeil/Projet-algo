#include "constantes.h"

//Partie vue
void reserver_memoire();
void affiche_fond(SDL_Renderer *renderer);
void affiche_identification( SDL_Renderer *renderer);
void affiche_mode(SDL_Renderer *renderer);
void affiche_plateau(SDL_Renderer *renderer, SDL_Texture *texture);
void affiche_regles(SDL_Renderer *renderer);
void afficher_coup(SDL_Renderer *renderer);
void afficher_coup_reserve(SDL_Renderer *renderer);
void affiche_pion_blanc( SDL_Renderer *renderer ,POINT hg);
void affiche_pion_noir( SDL_Renderer *renderer ,POINT hg);
void effacer_pion(SDL_Renderer *renderer ,POINT p);
void affiche_pion_blanc_reserve(SDL_Renderer *renderer,POINT p);
void affiche_pion_noir_reserve(SDL_Renderer *renderer,POINT p);
void effacer_pion_reserve(SDL_Renderer *renderer,POINT p);
void affiche_sur_brillance_blanc_reserve(SDL_Renderer *renderer,POINT p);
void affiche_sur_brillance_noir_reserve(SDL_Renderer *renderer,POINT p);
void affiche_sur_brillance_blanc(SDL_Renderer *renderer,POINT p);
void affiche_sur_brillance_noir(SDL_Renderer *renderer,POINT p);
void regles_jeux(SDL_Renderer *renderer,SDL_Texture *texture,POINT p,int etat);
void afficher_main(SDL_Renderer *renderer);
void re_Afficher_pion_blanc(SDL_Renderer *renderer,POINT hg1);
void re_Afficher_pion_noir(SDL_Renderer *renderer,POINT hg1);
void griser_pion(SDL_Renderer *renderer,int tour );
void manger_pion_adverse(SDL_Renderer *renderer,POINT hg1);
//void verifie_tab();
void griser_pion_reserve_blanc(SDL_Renderer *renderer);
void griser_pion_reserve_noir(SDL_Renderer *renderer);
void remplir_reserve_blanc(SDL_Renderer *renderer,POINT hg);
void remplir_reserve_noir(SDL_Renderer *renderer,POINT hg);




//partie modele
void init_plateau();
bool est_joueur_vs_joueur(POINT p);
bool est_joueur_vs_ordinateur(POINT p);
void appliquer_coup(POINT p1,int ig);
void mettre_a_jour_case(POINT p);
void mettre_a_jour_case_reserve_blanc(POINT p);
void mettre_a_jour_case_reserve_noir(POINT p);
bool est_case_vide(POINT p);
bool est_coup_valide(POINT p);
bool est_blanc(POINT p);
bool est_noir(POINT p);
bool est_dansPlateau(POINT p);
bool est_regle_jeux(POINT p);
bool est_identifier(POINT p);
bool est_dans_zone_reserve_blanc(POINT p);
bool est_dans_zone_reserve_noir(POINT p);
bool est_quitter_regles(POINT p);
void appliquer_clic_reserve_blanc(SDL_Renderer *renderer,POINT clic1,int ig,int nb_blanc);
void appliquer_clic_reserve_noir(SDL_Renderer *renderer,POINT clic1,int ig,int nb_noir);
void jouer_blanc(SDL_Renderer *renderer,POINT clic2,POINT hg1,int ig);
void jouer_noir(SDL_Renderer *renderer,POINT clic2,POINT hg1,int ig);
void appliquer_clic_blanc_dans_plateau(SDL_Renderer *renderer,POINT clic1,int ig);
void appliquer_clic_noir_dans_plateau(SDL_Renderer *renderer,POINT clic1,int ig);
bool est_deplacement_possible(POINT p1,POINT p2);
bool est_jeu_possible(POINT p1,POINT p2);
bool est_jeu_possible_gauche(POINT p1,POINT p2,int tour);
bool est_jeu_possible_droit(POINT p1,POINT p2,int tour);
bool est_jeu_possible_bas(POINT p1,POINT p2,int tour);
bool est_jeu_possible_haut(POINT p1,POINT p2,int tour);
void manger_second_pion_adverse(SDL_Renderer *renderer);
void ecrire_score_dans_fichier(char nom[]);





//parite Controller
POINT attend_clic2();
POINT point_to_pointHG(POINT p);
POINT NUMBOX_to_POINTHG(NUMBOX numB);
POINT NUMBOX_to_POINTHG_reserve_blanc(NUMBOX numB);
POINT NUMBOX_to_POINTHG_reserve_noir(NUMBOX numB);
POINT point_to_pointHG_reserveBlanc(POINT p);
POINT point_to_pointHG_reserveNoir(POINT p);
NUMBOX point_to_numBox(POINT p);
NUMBOX point_to_numBox_reserve_blanc(POINT p);
NUMBOX point_to_numBox_reserve_noir(POINT p);
void gerer_event(SDL_Window *window);


