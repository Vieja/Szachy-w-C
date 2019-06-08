#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>

void display_piony(int szachownica[8][8][3],int podswietlenie[8][8], ALLEGRO_BITMAP *plansza, ALLEGRO_BITMAP *krol_b, ALLEGRO_BITMAP *krol_c,
                   ALLEGRO_BITMAP *krolowka_b, ALLEGRO_BITMAP *krolowka_c, ALLEGRO_BITMAP *hetman_b, ALLEGRO_BITMAP *hetman_c, ALLEGRO_BITMAP *kon_b,
                   ALLEGRO_BITMAP *kon_c,ALLEGRO_BITMAP *wieza_b, ALLEGRO_BITMAP *wieza_c, ALLEGRO_BITMAP *pion_b, ALLEGRO_BITMAP *pion_c,ALLEGRO_BITMAP *blue,
                   ALLEGRO_BITMAP *blue_b,ALLEGRO_BITMAP *ruch_c,ALLEGRO_BITMAP *ruch_b,ALLEGRO_BITMAP *zapisz);

int sprawdz_ruch(int szachownica[8][8][3],int podswietlenie[8][8],int d1,int d2,int c1, int c2 , ALLEGRO_BITMAP *plansza, ALLEGRO_BITMAP *krol_b,
                 ALLEGRO_BITMAP *krol_c, ALLEGRO_BITMAP *krolowka_b, ALLEGRO_BITMAP *krolowka_c, ALLEGRO_BITMAP *hetman_b, ALLEGRO_BITMAP *hetman_c,
                 ALLEGRO_BITMAP *kon_b, ALLEGRO_BITMAP *kon_c,ALLEGRO_BITMAP *wieza_b, ALLEGRO_BITMAP *wieza_c, ALLEGRO_BITMAP *pion_b, ALLEGRO_BITMAP *pion_c,
                 ALLEGRO_BITMAP *blue,ALLEGRO_BITMAP *blue_b,ALLEGRO_BITMAP *ruch_c,ALLEGRO_BITMAP *ruch_b,ALLEGRO_BITMAP *zapisz);

int czy_szach_mat(int szachownica[8][8][3],int podswietlenie[8][8], ALLEGRO_BITMAP *plansza, ALLEGRO_BITMAP *krol_b, ALLEGRO_BITMAP *krol_c,
                  ALLEGRO_BITMAP *krolowka_b, ALLEGRO_BITMAP *krolowka_c, ALLEGRO_BITMAP *hetman_b, ALLEGRO_BITMAP *hetman_c, ALLEGRO_BITMAP *kon_b,
                  ALLEGRO_BITMAP *kon_c,ALLEGRO_BITMAP *wieza_b, ALLEGRO_BITMAP *wieza_c, ALLEGRO_BITMAP *pion_b, ALLEGRO_BITMAP *pion_c,ALLEGRO_BITMAP *blue,
                  ALLEGRO_BITMAP *blue_b,ALLEGRO_BITMAP *ruch_c,ALLEGRO_BITMAP *ruch_b,ALLEGRO_BITMAP *zapisz);

int AI (int szachownica[8][8][3],int podswietlenie[8][8], ALLEGRO_BITMAP *plansza, ALLEGRO_BITMAP *krol_b, ALLEGRO_BITMAP *krol_c, ALLEGRO_BITMAP *krolowka_b,
        ALLEGRO_BITMAP *krolowka_c, ALLEGRO_BITMAP *hetman_b, ALLEGRO_BITMAP *hetman_c, ALLEGRO_BITMAP *kon_b, ALLEGRO_BITMAP *kon_c,ALLEGRO_BITMAP *wieza_b,
        ALLEGRO_BITMAP *wieza_c, ALLEGRO_BITMAP *pion_b, ALLEGRO_BITMAP *pion_c,ALLEGRO_BITMAP *blue,ALLEGRO_BITMAP *blue_b,ALLEGRO_BITMAP *ruch_c,
        ALLEGRO_BITMAP *ruch_b,ALLEGRO_BITMAP *zapisz);

int tura(ALLEGRO_EVENT_QUEUE * event_queue, int szachownica[8][8][3],int podswietlenie[8][8],ALLEGRO_BITMAP *plansza, ALLEGRO_BITMAP *krol_b,  ALLEGRO_BITMAP *krol_c,
         ALLEGRO_BITMAP *krolowka_b, ALLEGRO_BITMAP *krolowka_c, ALLEGRO_BITMAP *hetman_b, ALLEGRO_BITMAP *hetman_c, ALLEGRO_BITMAP *kon_b, ALLEGRO_BITMAP *kon_c,
         ALLEGRO_BITMAP *wieza_b, ALLEGRO_BITMAP *wieza_c, ALLEGRO_BITMAP *pion_b, ALLEGRO_BITMAP *pion_c, ALLEGRO_BITMAP *blue,ALLEGRO_BITMAP *blue_b,
         ALLEGRO_BITMAP *ruch_c,ALLEGRO_BITMAP *ruch_b,ALLEGRO_BITMAP *zapisz,ALLEGRO_BITMAP *zapisz2,ALLEGRO_DISPLAY * okno);

int sub_menu(ALLEGRO_EVENT_QUEUE * event_queue,int y,ALLEGRO_BITMAP *plansza,ALLEGRO_BITMAP *menu, ALLEGRO_BITMAP *vsgracz, ALLEGRO_BITMAP *vskomputer,
             ALLEGRO_BITMAP *powrot, ALLEGRO_BITMAP *vsgracz2, ALLEGRO_BITMAP *vskomputer2, ALLEGRO_BITMAP *powrot2);

int display_menu(ALLEGRO_EVENT_QUEUE * event_queue,int y,ALLEGRO_BITMAP *plansza,ALLEGRO_BITMAP *menu, ALLEGRO_BITMAP *nowa_gra, ALLEGRO_BITMAP *wczytaj,
                 ALLEGRO_BITMAP *exit, ALLEGRO_BITMAP *nowa_gra2, ALLEGRO_BITMAP *wczytaj2, ALLEGRO_BITMAP *exit2,ALLEGRO_BITMAP *vsgracz,
                 ALLEGRO_BITMAP *vskomputer, ALLEGRO_BITMAP *powrot, ALLEGRO_BITMAP *vsgracz2, ALLEGRO_BITMAP *vskomputer2, ALLEGRO_BITMAP *powrot2);
