#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <math.h>
#include <string.h>
#include <SDL2/SDL_ttf.h>

#ifndef DEF_CONSTANTES
#define DEF_CONSTANTES

    #define width 1120
    #define height 600

    //Couleur pion
    enum COUL
    {
            BLANC, NOIR,AUTRE
    };
    typedef enum COUL COUL;


    //etat pion remplie ou vide
    enum TYPE {
        REMPLIE,VIDE
    };
    typedef enum TYPE TYPE;


    struct CASE {
        COUL coulP;
        TYPE typeC;
        //int coup_possible;
    };
    typedef struct CASE CASE;



    struct POINT
    {
        int x;
        int y;
    };typedef struct POINT POINT;

    struct NUMBOX {
        int l ;
        int c ;
    };typedef struct NUMBOX NUMBOX;

    CASE plateau [5][6];
    CASE tab_blanc[6][2];
    CASE tab_noir[6][2];
    int tour;
    int res1;
    int res2;
    bool quit;
    SDL_Event event;


#endif
