#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include "Menu.h"
#include "Allegro.h"
# define PLIK "plik.txt"

int szachownica[8][8][3];
int podswietlenie[8][8];
int czy_niebiesko = 0;
int czy_bicia = 0;
int teraz_czarne = 0;
int szach = 0;
int activate_szachuje=0;
int szachuje=0;
int k=-5;
bool czy_istnieje_ruch = false;
bool sprawdzanie_szach_mata = false;
int i,j;
int xx,yy,XX,YY = 0;
int type = 0;
int type_bitego = 0;
int roznica=0;

int main() {

    al_init();
    bool done = false;
    FILE *zapis_gry;
    al_init_primitives_addon();
    al_install_keyboard();
    al_init_image_addon();
    ALLEGRO_KEYBOARD_STATE klawiatura;
    ALLEGRO_DISPLAY *okno = al_create_display( 784, 640 );
    ALLEGRO_BITMAP *plansza = al_load_bitmap("images/board.png");
    ALLEGRO_BITMAP *menu = al_load_bitmap("images/board0.png");
    ALLEGRO_BITMAP *krol_b = al_load_bitmap("images/piony/krol_b.png");
    ALLEGRO_BITMAP *krolowka_b = al_load_bitmap("images/piony/krolowka_b.png");
    ALLEGRO_BITMAP *kon_b = al_load_bitmap("images/piony/kon_b.png");
    ALLEGRO_BITMAP *wieza_b = al_load_bitmap("images/piony/wieza_b.png");
    ALLEGRO_BITMAP *hetman_b = al_load_bitmap("images/piony/hetman_b.png");
    ALLEGRO_BITMAP *pion_b = al_load_bitmap("images/piony/pion_b.png");
    ALLEGRO_BITMAP *krol_c = al_load_bitmap("images/piony/krol_c.png");
    ALLEGRO_BITMAP *krolowka_c = al_load_bitmap("images/piony/krolowka_c.png");
    ALLEGRO_BITMAP *kon_c = al_load_bitmap("images/piony/kon_c.png");
    ALLEGRO_BITMAP *wieza_c = al_load_bitmap("images/piony/wieza_c.png");
    ALLEGRO_BITMAP *hetman_c = al_load_bitmap("images/piony/hetman_c.png");
    ALLEGRO_BITMAP *pion_c = al_load_bitmap("images/piony/pion_c.png");
    ALLEGRO_BITMAP *blue = al_load_bitmap("images/blue.png");
    ALLEGRO_BITMAP *blue_b = al_load_bitmap("images/blue_b.png");
    ALLEGRO_BITMAP *nowa_gra = al_load_bitmap("images/nowa gra.png");
    ALLEGRO_BITMAP *nowa_gra2 = al_load_bitmap("images/nowa gra2.png");
    ALLEGRO_BITMAP *vsgracz = al_load_bitmap("images/vsgracz.png");
    ALLEGRO_BITMAP *vsgracz2 = al_load_bitmap("images/vsgracz2.png");
    ALLEGRO_BITMAP *vskomputer = al_load_bitmap("images/vskomputer.png");
    ALLEGRO_BITMAP *vskomputer2 = al_load_bitmap("images/vskomputer2.png");
    ALLEGRO_BITMAP *wczytaj = al_load_bitmap("images/wczytaj.png");
    ALLEGRO_BITMAP *wczytaj2 = al_load_bitmap("images/wczytaj2.png");
    ALLEGRO_BITMAP *powrot = al_load_bitmap("images/powrot.png");
    ALLEGRO_BITMAP *powrot2 = al_load_bitmap("images/powrot2.png");
    ALLEGRO_BITMAP *exit = al_load_bitmap("images/exit.png");
    ALLEGRO_BITMAP *exit2 = al_load_bitmap("images/exit2.png");
    ALLEGRO_BITMAP *zapisz = al_load_bitmap("images/zapisz.png");
    ALLEGRO_BITMAP *zapisz2 = al_load_bitmap("images/zapisz2.png");
    ALLEGRO_BITMAP *ruch_b = al_load_bitmap("images/ruch_b.png");
    ALLEGRO_BITMAP *ruch_c = al_load_bitmap("images/ruch_c.png");
    ALLEGRO_EVENT_QUEUE * event_queue = NULL;
    al_set_window_title( okno, "Szachy" );

    event_queue = al_create_event_queue();
    al_register_event_source(event_queue,al_get_keyboard_event_source());
    al_register_event_source(event_queue,al_get_display_event_source(okno));

    int frommenu;
    bool wait = false;

frommenu=display_menu(event_queue,0,plansza,menu,nowa_gra,wczytaj,exit,nowa_gra2,wczytaj2,exit2,vsgracz,vskomputer,powrot,vsgracz2,vskomputer2,powrot2);
switch(frommenu)
 {
case 0:
{
    al_destroy_display(okno);
    wait=true;
    break;
}
case 1:
{
    int turn;
    ustaw_piony(szachownica,podswietlenie);
    while(!wait)
    {
        for(i=0;i<8;i++)
          {
            for(j=0;j<8;j++)
              {
                  podswietlenie[i][j]=0;
              }
          }
        turn=tura(event_queue,szachownica,podswietlenie,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz,zapisz2,okno);
            if (turn==0)  //zamknieta guzikiem
            {
                al_destroy_display(okno);
                wait=true;
            }
            if (turn==2) //zapisz i wyjdz
            {
                zapis_gry = fopen(PLIK, "w");
                for(i=0;i<8;i++)
                {
                    for(j=0;j<8;j++)
                    {
                       fprintf(zapis_gry,"%d " ,szachownica[i][j][0]);
                    }
                       fprintf(zapis_gry,"\n");
                }
                fprintf(zapis_gry,"%d",teraz_czarne);
                fclose(zapis_gry);
                al_destroy_display(okno);
                wait=true;
            }
            if (turn==1)  //ruch wykonany
            {
                for(i=0;i<8;i++)
                {
                    for(j=0;j<8;j++)
                    {
                        szachownica[i][j][0]=(szachownica[i][j][0])*(-1);
                    }
                }
                if (teraz_czarne==0) teraz_czarne=1; else teraz_czarne=0;
            }
            if (turn==3)  //szach mat
            {
                for(i=0;i<8;i++)
                {
                    for(j=0;j<8;j++)
                    {
                        szachownica[i][j][0]=(szachownica[i][j][0])*(-1);
                    }
                }
                if (teraz_czarne==0) teraz_czarne=1; else teraz_czarne=0;
                znajdz_ruchy(szachownica,podswietlenie);
                display_piony(szachownica,podswietlenie,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                al_flip_display();
                if(teraz_czarne==0) al_show_native_message_box(okno,"Koniec Gry","SZACH MAT","Wygraly biale",NULL,NULL);
                else al_show_native_message_box(okno,"Koniec Gry","SZACH MAT","Wygraly czarne",NULL,NULL);
                al_destroy_display(okno);
                wait=true;
            }
            if (turn==4)  //pat
            {
                for(i=0;i<8;i++)
                {
                    for(j=0;j<8;j++)
                    {
                        szachownica[i][j][0]=(szachownica[i][j][0])*(-1);
                    }
                }
                if (teraz_czarne==0) teraz_czarne=1; else teraz_czarne=0;
                znajdz_ruchy(szachownica,podswietlenie);
                display_piony(szachownica,podswietlenie,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                al_flip_display();
                al_show_native_message_box(okno,"Koniec Gry","Pat","Remis",NULL,NULL);
                al_destroy_display(okno);
                wait=true;
            }
    }
          break;
}
case 4:
    {
        int turn;
        ustaw_piony(szachownica,podswietlenie);
        for(i=0;i<8;i++)
          {
              for(j=0;j<8;j++)
              {
                  szachownica[i][j][0]=0;
              }
          }
        zapis_gry = fopen(PLIK, "r");
        for(i=0;i<8;i++)
          {
              for(j=0;j<8;j++)
               {
                  fscanf(zapis_gry,"%d",&szachownica[i][j][0]);
               }
          }
        fscanf(zapis_gry,"%d",&teraz_czarne);
        fclose(zapis_gry);
        wait=false;
        while(!wait)
        {
          for(i=0;i<8;i++)
          {
              for(j=0;j<8;j++)
              {
                  podswietlenie[i][j]=0;
              }
          }
          turn=tura(event_queue,szachownica,podswietlenie,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz,zapisz2,okno);
          if (turn==0)  //zamknêta guzikiem
            {
                   al_destroy_display(okno);
                   wait=true;
            }
          if (turn==2) //zapisz i wyjdŸ
            {
            zapis_gry = fopen(PLIK, "w");
            for(i=0;i<8;i++)
              {
                    for(j=0;j<8;j++)
                    {
                       fprintf(zapis_gry,"%d " ,szachownica[i][j][0]);
                    }
                    fprintf(zapis_gry,"\n");
              }
            fprintf(zapis_gry,"%d",teraz_czarne);
            fclose(zapis_gry);
            al_destroy_display(okno);
            wait=true;
            }
           if (turn==1)  //ruch wykonany
            {
                for(i=0;i<8;i++)
                {
                    for(j=0;j<8;j++)
                    {
                        szachownica[i][j][0]=(szachownica[i][j][0])*(-1);
                    }
                }
                   if (teraz_czarne==0) teraz_czarne=1; else teraz_czarne=0;
            }
           if (turn==3)  //szach mat
            {
                for(i=0;i<8;i++)
                {
                    for(j=0;j<8;j++)
                    {
                        szachownica[i][j][0]=(szachownica[i][j][0])*(-1);
                    }
                }
            if (teraz_czarne==0) teraz_czarne=1; else teraz_czarne=0;
            znajdz_ruchy(szachownica,podswietlenie);
            display_piony(szachownica,podswietlenie,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
            al_flip_display();
            if(teraz_czarne==0) al_show_native_message_box(okno,"Koniec Gry","SZACH MAT","Wygraly biale",NULL,NULL);
            else al_show_native_message_box(okno,"Koniec Gry","SZACH MAT","Wygraly czarne",NULL,NULL);
            al_destroy_display(okno);
            wait=true;

            }
           if (turn==4)  //pat
            {
                for(i=0;i<8;i++)
                {
                    for(j=0;j<8;j++)
                    {
                        szachownica[i][j][0]=(szachownica[i][j][0])*(-1);
                    }
                }
                if (teraz_czarne==0) teraz_czarne=1; else teraz_czarne=0;
                znajdz_ruchy(szachownica,podswietlenie);
                display_piony(szachownica,podswietlenie,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                al_flip_display();
                al_show_native_message_box(okno,"Koniec Gry","Pat","Remis",NULL,NULL);
                al_destroy_display(okno);
                wait=true;
            }
        } break;
}
case 2:
{
        int turn;
        ustaw_piony(szachownica,podswietlenie);
        while(!wait)
        {
          for(i=0;i<8;i++)
          {
              for(j=0;j<8;j++)
              {
                  podswietlenie[i][j]=0;
              }
          }
          turn=tura(event_queue,szachownica,podswietlenie,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz,zapisz2,okno);
          if (turn==0)  //zamknêta guzikiem
            {
                al_destroy_display(okno);
                wait=true;
            }
          if (turn==2) //zapisz i wyjdŸ
            {
                zapis_gry = fopen(PLIK, "w");
                for(i=0;i<8;i++)
                {
                      for(j=0;j<8;j++)
                       {
                          fprintf(zapis_gry,"%d " ,szachownica[i][j][0]);
                       }
                       fprintf(zapis_gry,"\n");
                }
                fprintf(zapis_gry,"%d",teraz_czarne);
                fclose(zapis_gry);
                al_destroy_display(okno);
                wait=true;
            }
          if (turn==1)  //ruch wykonany
            {
                for(i=0;i<8;i++)
                {
                    for(j=0;j<8;j++)
                    {
                          szachownica[i][j][0]=(szachownica[i][j][0])*(-1);
                    }
                }
                if (teraz_czarne==0) teraz_czarne=1; else teraz_czarne=0;
            }
          if (turn==3)  //szach mat
            {
                for(i=0;i<8;i++)
                {
                    for(j=0;j<8;j++)
                    {
                        szachownica[i][j][0]=(szachownica[i][j][0])*(-1);
                    }
                }
                if (teraz_czarne==0) teraz_czarne=1; else teraz_czarne=0;
                znajdz_ruchy(szachownica,podswietlenie);
                display_piony(szachownica,podswietlenie,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                al_flip_display();
                if(teraz_czarne==0) al_show_native_message_box(okno,"Koniec Gry","SZACH MAT","Wygraly biale",NULL,NULL);
                else al_show_native_message_box(okno,"Koniec Gry","SZACH MAT","Wygraly czarne",NULL,NULL);
                al_destroy_display(okno);
                wait=true;
            }
          if (turn==4)  //pat
            {
                for(i=0;i<8;i++)
                {
                    for(j=0;j<8;j++)
                    {
                        szachownica[i][j][0]=(szachownica[i][j][0])*(-1);
                    }
                }
                if (teraz_czarne==0) teraz_czarne=1; else teraz_czarne=0;
                znajdz_ruchy(szachownica,podswietlenie);
                display_piony(szachownica,podswietlenie,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                al_flip_display();
                al_show_native_message_box(okno,"Koniec Gry","Pat","Remis",NULL,NULL);
                al_destroy_display(okno);
                wait=true;
            }
          if(wait==false)
            {
                turn=AI(szachownica,podswietlenie,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                if (turn==1)
                 {
                     for(i=0;i<8;i++)
                       {
                          for(j=0;j<8;j++)
                           {
                              szachownica[i][j][0]=(szachownica[i][j][0])*(-1);
                           }
                       }
                     if (teraz_czarne==0) teraz_czarne=1; else teraz_czarne=0;
                 }
                if (turn==3)  //szach mat
                 {
                     for(i=0;i<8;i++)
                       {
                          for(j=0;j<8;j++)
                           {
                              szachownica[i][j][0]=(szachownica[i][j][0])*(-1);
                           }
                       }
                     if (teraz_czarne==0) teraz_czarne=1; else teraz_czarne=0;
                     znajdz_ruchy(szachownica,podswietlenie);
                     display_piony(szachownica,podswietlenie,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                     al_flip_display();
                     if(teraz_czarne==0) al_show_native_message_box(okno,"Koniec Gry","SZACH MAT","Wygraly biale",NULL,NULL);
                     else al_show_native_message_box(okno,"Koniec Gry","SZACH MAT","Wygraly czarne",NULL,NULL);
                     al_destroy_display(okno);
                     wait=true;
                }
               if (turn==4)  //pat
                {
                     for(i=0;i<8;i++)
                       {
                          for(j=0;j<8;j++)
                           {
                              szachownica[i][j][0]=(szachownica[i][j][0])*(-1);
                           }
                       }
                     if (teraz_czarne==0) teraz_czarne=1; else teraz_czarne=0;
                     znajdz_ruchy(szachownica,podswietlenie);
                     display_piony(szachownica,podswietlenie,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                     al_flip_display();
                     al_show_native_message_box(okno,"Koniec Gry","Pat","Remis",NULL,NULL);
                     al_destroy_display(okno);
                     wait=true;
                }
          }
      }
}
 }

    return 0;
}
