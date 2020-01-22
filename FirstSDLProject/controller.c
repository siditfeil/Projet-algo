#include "main.h"

POINT attend_clic2()
{
	int encore = 1;
	POINT P;
	SDL_Event event;
	P.x = -100;
	P.y = -100;
	while (SDL_WaitEvent(&event) && encore)
		{
		/* Si l'utilisateur clique avec la souris */
		if ((event.type == SDL_MOUSEBUTTONDOWN) && (event.button.button == SDL_BUTTON_LEFT))
			{
			encore=0;
			P.x = event.button.x;
			P.y = event.button.y;
			}
		/* Si l'utilisateur déplace la souris */
		if (event.type == SDL_MOUSEMOTION)
			{
			//printf("%cEn attente de clic ... %4d %4d           %c",13,event.motion.x,HEIGHT - event.motion.y,13);
			fflush(stdout);
			}
		/* Si l'utilisateur a demandé à fermer la fenêtre, on quitte */
		if (event.type == SDL_QUIT) exit(0);

		}

	return P;
}


POINT point_to_pointHG(POINT p)
{
    POINT hg;
    int q1=(p.x-320)/80;
    int q2=(p.y-100)/80;
    hg.x=q1*80+320;
    hg.y=q2*80+100;
    return hg;
}


POINT NUMBOX_to_POINTHG(NUMBOX numB)
{
    POINT hg;
    hg.x=numB.c*80+320;
    hg.y=numB.l*80+100;
    return hg;
}

POINT NUMBOX_to_POINTHG_reserve_blanc(NUMBOX numB)
{
    POINT hg;
    hg.x=numB.c*40+105;
    hg.y=numB.l*40+180;
    return hg;
}

POINT NUMBOX_to_POINTHG_reserve_noir(NUMBOX numB)
{
    POINT hg;
    hg.x=numB.c*40+935;
    hg.y=numB.l*40+180;
    return hg;
}

POINT point_to_pointHG_reserveBlanc(POINT p)
{
    POINT hg;
    int q1=(p.x-105)/40;
    int q2=(p.y-180)/40;
    hg.x=q1*40+105;
    hg.y=q2*40+180;
    return hg;
}

POINT point_to_pointHG_reserveNoir(POINT p)
{
    POINT hg;
    int q1=(p.x-935)/40;
    int q2=(p.y-180)/40;
    hg.x=q1*40+935;
    hg.y=q2*40+180;
    return hg;
}


NUMBOX point_to_numBox(POINT p)
{
    NUMBOX numB;
    POINT hg;
    numB.c=(p.x-320)/80;
    numB.l=(p.y-100)/80;
    return numB;
}

NUMBOX point_to_numBox_reserve_blanc(POINT p)
{
    NUMBOX numB;
    numB.c=(p.x-105)/40;
    numB.l=(p.y-180)/40;
    return numB;
}

NUMBOX point_to_numBox_reserve_noir(POINT p)
{
    NUMBOX numB;
    numB.c=(p.x-935)/40;
    numB.l=(p.y-180)/40;
    return numB;
}

void gerer_event(SDL_Window *window)
{
        SDL_PollEvent(&event);
        char char1,char2,char3,char4,char5;
        switch (event.type)
        {
            case SDL_QUIT:
                quit = true;
                break;

        case SDL_KEYDOWN: // Un événement de type touche enfoncée est effectué
            SDL_Log("+key");  // Affiche un message +key (pour dire qu'on appuie sur une touche du clavier)

            if (event.key.keysym.scancode == SDL_SCANCODE_W) // Regarde si le scancode W est enfoncé (Z sous un azerty)
                //SDL_Log("Scancode W"); // Affiche un message
                char1='a';
                char2='w';
                char3='c';
                char4='h';
                printf("voici la chaine : %c%c%c \n",char2,char3,char4);

               // SDL_ShowSimpleMessageBox(0, "Mouse", "w was pressed!", window);

            if (event.key.keysym.sym == SDLK_w) // Regarde si le keycode w est enfoncé (la touche W sous un azerty)
                SDL_Log("Keycode W"); // Affiche un message

            if (event.key.keysym.sym == SDLK_z) // Regarde si on appuyer sur la touche Z (la touche Z sous un azerty)
                SDL_Log("Keycode Z"); // Affiche un message

            break;
        }
}
