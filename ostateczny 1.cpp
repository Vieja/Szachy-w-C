#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
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

void ustaw_piony(int szachownica[8][8][3],int tab2[8][8])
{
    int x = 12;
    int y = 12;
    int a=1;
    int b=6;
    int c=11;

    for(i=1;i<4;i++)
    {
        szachownica[7][i-1][0]=i;
        szachownica[0][i-1][0]=(-1)*i;
        szachownica[7][8-i][0]=i;
        szachownica[0][8-i][0]=(-1)*i;
    }
    szachownica[0][3][0]=-4;
    szachownica[0][4][0]=-5;
    szachownica[7][3][0]=4;
    szachownica[7][4][0]=5;
    for(i=0;i<8;i++)
    {
        szachownica[1][i][0]=-6;
        szachownica[6][i][0]=6;
    }
    //szachownica[0][0][0]=-5;
    //szachownica[7][1][0]=1;
    // szachownica[5][4][0]=4;
   // szachownica[1][6][0]=6;
        for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            szachownica[i][j][1]=x;
            szachownica[i][j][2]=y;
            x=x+79;
            tab2[i][j]=0;
        }
        x=12;
        y=y+79;
    }
}

void display_piony(int tab[8][8][3],int podswietlenie[8][8], ALLEGRO_BITMAP *plansza, ALLEGRO_BITMAP *krol_b, ALLEGRO_BITMAP *krol_c, ALLEGRO_BITMAP *krolowka_b, ALLEGRO_BITMAP *krolowka_c,
                   ALLEGRO_BITMAP *hetman_b, ALLEGRO_BITMAP *hetman_c, ALLEGRO_BITMAP *kon_b, ALLEGRO_BITMAP *kon_c,ALLEGRO_BITMAP *wieza_b, ALLEGRO_BITMAP *wieza_c,
                   ALLEGRO_BITMAP *pion_b, ALLEGRO_BITMAP *pion_c,ALLEGRO_BITMAP *blue,ALLEGRO_BITMAP *blue_b,ALLEGRO_BITMAP *ruch_c,ALLEGRO_BITMAP *ruch_b,ALLEGRO_BITMAP *zapisz)
{
    al_draw_bitmap (plansza,0,0,0);
    if (czy_niebiesko == 1)
    {
          for(i=0;i<8;i++)
          {
              for(j=0;j<8;j++)
              {
                  if(podswietlenie[i][j]==1)
                  {
                      if( ((i%2)==0 & (j%2)==0) | ((i%2)!=0 & (j%2)!=0)) al_draw_bitmap (blue_b,tab[i][j][1]-8,tab[i][j][2]-8,0);
                      else al_draw_bitmap (blue,tab[i][j][1]-8,tab[i][j][2]-8,0);
                  }

              }
          }
    }
    int typ;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
           typ=szachownica[i][j][0];
           if(teraz_czarne==0)
           {
           switch(typ)
           {
            case 1:
                  al_draw_bitmap (wieza_b,tab[i][j][1],tab[i][j][2],NULL);
                  break;
            case  -1:
                  al_draw_bitmap (wieza_c,tab[i][j][1],tab[i][j][2],NULL);
                  break;
            case  2:
                  al_draw_bitmap (kon_b,tab[i][j][1],tab[i][j][2],NULL);
                  break;
            case  -2:
                  al_draw_bitmap (kon_c,tab[i][j][1],tab[i][j][2],NULL);
                  break;
            case  3:
                  al_draw_bitmap (hetman_b,tab[i][j][1],tab[i][j][2],NULL);
                  break;
            case -3:
                  al_draw_bitmap (hetman_c,tab[i][j][1],tab[i][j][2],NULL);
                  break;
            case  4:
                  al_draw_bitmap (krolowka_b,tab[i][j][1],tab[i][j][2],NULL);
                  break;
            case  -4:
                  al_draw_bitmap (krolowka_c,tab[i][j][1],tab[i][j][2],NULL);
                  break;
            case  5:
                  al_draw_bitmap (krol_b,tab[i][j][1],tab[i][j][2],NULL);
                  break;
            case  -5:
                  al_draw_bitmap (krol_c,tab[i][j][1],tab[i][j][2],NULL);
                  break;
            case  6:
                  al_draw_bitmap (pion_b,tab[i][j][1],tab[i][j][2],NULL);
                  break;
            case  -6:
                  al_draw_bitmap (pion_c,tab[i][j][1],tab[i][j][2],NULL);
                  break;
           }
           } else
           {
               switch(typ)
           {
            case 1:
                  al_draw_bitmap (wieza_c,tab[i][j][1],tab[i][j][2],NULL);
                  break;
            case  -1:
                  al_draw_bitmap (wieza_b,tab[i][j][1],tab[i][j][2],NULL);
                  break;
            case  2:
                  al_draw_bitmap (kon_c,tab[i][j][1],tab[i][j][2],NULL);
                  break;
            case  -2:
                  al_draw_bitmap (kon_b,tab[i][j][1],tab[i][j][2],NULL);
                  break;
            case  3:
                  al_draw_bitmap (hetman_c,tab[i][j][1],tab[i][j][2],NULL);
                  break;
            case -3:
                  al_draw_bitmap (hetman_b,tab[i][j][1],tab[i][j][2],NULL);
                  break;
            case  4:
                  al_draw_bitmap (krolowka_c,tab[i][j][1],tab[i][j][2],NULL);
                  break;
            case  -4:
                  al_draw_bitmap (krolowka_b,tab[i][j][1],tab[i][j][2],NULL);
                  break;
            case  5:
                  al_draw_bitmap (krol_c,tab[i][j][1],tab[i][j][2],NULL);
                  break;
            case  -5:
                  al_draw_bitmap (krol_b,tab[i][j][1],tab[i][j][2],NULL);
                  break;
            case  6:
                  al_draw_bitmap (pion_c,tab[i][j][1],tab[i][j][2],NULL);
                  break;
            case  -6:
                  al_draw_bitmap (pion_b,tab[i][j][1],tab[i][j][2],NULL);
                  break;
           }
           }
        }
    }
    if(teraz_czarne==1) al_draw_bitmap(ruch_c,650,120,NULL); else al_draw_bitmap(ruch_b,650,120,NULL);
}

void pokaz_ruchy(int szachownica[8][8][3],int podswietlenie[8][8],int d1,int d2)
{
 if(podswietlenie[d1][d2]==1 | czy_bicia==1 | activate_szachuje==1)
 {
    if(czy_bicia==0 & activate_szachuje==0)
    {
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            podswietlenie[i][j]=0;
        }
    }
    }
    int typ=szachownica[d1][d2][0];
    switch (typ)
                {
                    case 6:
                        {
                    if(teraz_czarne==0)
                    {
                        if(szachownica[d1-1][d2][0]==0) if(sprawdzanie_szach_mata == false) podswietlenie[d1-1][d2]=1;
                        if(szachownica[d1-1][d2-1][0]<0)if(sprawdzanie_szach_mata == false) podswietlenie[d1-1][d2-1]=1;
                        if(szachownica[d1-1][d2+1][0]<0)if(sprawdzanie_szach_mata == false) podswietlenie[d1-1][d2+1]=1;
                        if(szachownica[d1-2][d2][0]==0 & szachownica[d1-1][d2][0]==0 & d1==6)if(sprawdzanie_szach_mata == false) podswietlenie[d1-2][d2]=1;
                        if(szachownica[d1-1][d2-1][0]==k | szachownica[d1-1][d2+1][0]==k)
                        {
                            szach=1;
                            if(activate_szachuje==1) szachuje=1;
                        }
                    }
                    else
                    {
                        if(szachownica[d1+1][d2][0]==0)if(sprawdzanie_szach_mata == false) podswietlenie[d1+1][d2]=1;
                        if(szachownica[d1+1][d2-1][0]<0)if(sprawdzanie_szach_mata == false) podswietlenie[d1+1][d2-1]=1;
                        if(szachownica[d1+1][d2+1][0]<0)if(sprawdzanie_szach_mata == false) podswietlenie[d1+1][d2+1]=1;
                        if(szachownica[d1+2][d2][0]==0 & szachownica[d1+1][d2][0]==0 & d1==1)if(sprawdzanie_szach_mata == false) podswietlenie[d1+2][d2]=1;
                        else if(szachownica[d1+1][d2-1][0]==k | szachownica[d1+1][d2+1][0]==k)
                        {
                            szach=1;
                            if(activate_szachuje==1) szachuje=1;
                        }
                    }
                        break;
                        }
                    case 1:
                        {
                        int x=d1-1;
                        int y=d2;
                        while(szachownica[x][y][0]==0 & x>=0)
                        {
                            if(sprawdzanie_szach_mata == false) podswietlenie[x][y]=1;
                            x=x-1;
                        } if (szachownica[x][y][0]<=0 & x>=0) if(sprawdzanie_szach_mata == false)  podswietlenie[x][y]=1;
                        if (szachownica[x][y][0]==k & x>=0)
                        {
                            szach=1;
                            if(activate_szachuje==1) szachuje=1;
                        }
                        x=d1+1;
                        while(szachownica[x][y][0]==0 & x<8)
                        {
                            if(sprawdzanie_szach_mata == false) podswietlenie[x][y]=1;
                            x=x+1;
                        } if (szachownica[x][y][0]<=0 & x<8) if(sprawdzanie_szach_mata == false) podswietlenie[x][y]=1;
                        if (szachownica[x][y][0]==k & x<8)
                        {
                            szach=1;
                            if(activate_szachuje==1) szachuje=1;
                        }
                        x=d1;
                        y=d2-1;
                        while(szachownica[x][y][0]==0 & y>=0)
                        {
                            if(sprawdzanie_szach_mata == false) podswietlenie[x][y]=1;
                            y=y-1;
                        } if (szachownica[x][y][0]<=0 & y>=0) if(sprawdzanie_szach_mata == false) podswietlenie[x][y]=1;
                        if (szachownica[x][y][0]==k & y>=0)
                        {
                            szach=1;
                            if(activate_szachuje==1) szachuje=1;
                        }
                        y=d2+1;
                        while(szachownica[x][y][0]==0 & y<8)
                        {
                            if(sprawdzanie_szach_mata == false)podswietlenie[x][y]=1;
                            y=y+1;
                        } if (szachownica[x][y][0]<=0 & y<8) if(sprawdzanie_szach_mata == false) podswietlenie[x][y]=1;
                        if (szachownica[x][y][0]==k & y<8)
                        {
                            szach=1;
                            if(activate_szachuje==1) szachuje=1;
                        }
                        break;
                        }

                    case 2:
                        {
                        if(szachownica[d1-2][d2-1][0]<=0 & d1-2>=0 & d2-1>=0)if(sprawdzanie_szach_mata == false) podswietlenie[d1-2][d2-1]=1;
                        if(szachownica[d1-2][d2+1][0]<=0 & d1-2>=0 & d2+1<8) if(sprawdzanie_szach_mata == false) podswietlenie[d1-2][d2+1]=1;
                        if(szachownica[d1-1][d2-2][0]<=0 & d1-1>=0 & d2-2>=0)if(sprawdzanie_szach_mata == false) podswietlenie[d1-1][d2-2]=1;
                        if(szachownica[d1+1][d2-2][0]<=0 & d1+1<8 & d2-2>=0)if(sprawdzanie_szach_mata == false)  podswietlenie[d1+1][d2-2]=1;
                        if(szachownica[d1+2][d2-1][0]<=0 & d1+2<8 & d2-1>=0)if(sprawdzanie_szach_mata == false)  podswietlenie[d1+2][d2-1]=1;
                        if(szachownica[d1+2][d2+1][0]<=0 & d1+2<8 & d2+1<8) if(sprawdzanie_szach_mata == false)  podswietlenie[d1+2][d2+1]=1;
                        if(szachownica[d1-1][d2+2][0]<=0 & d1-1>=0 & d2+2<8) if(sprawdzanie_szach_mata == false) podswietlenie[d1-1][d2+2]=1;
                        if(szachownica[d1+1][d2+2][0]<=0 & d1+1<8 & d2+2<8) if(sprawdzanie_szach_mata == false)  podswietlenie[d1+1][d2+2]=1;

                        if (szachownica[d1-2][d2-1][0]==k)
                        {
                            szach=1;
                            if(activate_szachuje==1) szachuje=1;
                        }
                        if (szachownica[d1-2][d2+1][0]==k)
                        {
                            szach=1;
                            if(activate_szachuje==1) szachuje=1;
                        }
                        if (szachownica[d1-1][d2-2][0]==k)
                        {
                            szach=1;
                            if(activate_szachuje==1) szachuje=1;
                        }
                        if (szachownica[d1+1][d2-2][0]==k)
                        {
                            szach=1;
                            if(activate_szachuje==1) szachuje=1;
                        }
                        if (szachownica[d1+2][d2-1][0]==k)
                        {
                            szach=1;
                            if(activate_szachuje==1) szachuje=1;
                        }
                        if (szachownica[d1+2][d2+1][0]==k)
                        {
                            szach=1;
                            if(activate_szachuje==1) szachuje=1;
                        }
                        if (szachownica[d1-1][d2+2][0]==k)
                        {
                            szach=1;
                            if(activate_szachuje==1) szachuje=1;
                        }
                        if (szachownica[d1+1][d2+2][0]==k)
                        {
                            szach=1;
                            if(activate_szachuje==1) szachuje=1;
                        }
                        break;
                        }

                    case 3:
                        {
                        int x=d1-1;
                        int y=d2-1;
                        while(szachownica[x][y][0]==0 & x>=0 & y>=0)
                        {
                            if(sprawdzanie_szach_mata == false) podswietlenie[x][y]=1;
                            x=x-1;
                            y=y-1;
                        } if (szachownica[x][y][0]<=0 & x>=0 & y>=0) if(sprawdzanie_szach_mata == false) podswietlenie[x][y]=1;
                        if (szachownica[x][y][0]==k)
                        {
                            szach=1;
                            if(activate_szachuje==1) szachuje=1;
                        }
                        x=d1+1;
                        y=d2+1;
                        while(szachownica[x][y][0]==0 & x<8 & y<8)
                        {
                            if(sprawdzanie_szach_mata == false) podswietlenie[x][y]=1;
                            x=x+1;
                            y=y+1;
                        } if (szachownica[x][y][0]<=0 & x<8 & y<8) if(sprawdzanie_szach_mata == false) podswietlenie[x][y]=1;
                        if (szachownica[x][y][0]==k)
                        {
                            szach=1;
                            if(activate_szachuje==1) szachuje=1;
                        }
                        x=d1+1;
                        y=d2-1;
                        while(szachownica[x][y][0]==0 & x<8 & y>=0)
                        {
                            if(sprawdzanie_szach_mata == false) podswietlenie[x][y]=1;
                            x=x+1;
                            y=y-1;
                        } if (szachownica[x][y][0]<=0 & x<8 & y>=0) if(sprawdzanie_szach_mata == false) podswietlenie[x][y]=1;
                        if (szachownica[x][y][0]==k)
                        {
                            szach=1;
                            if(activate_szachuje==1) szachuje=1;
                        }
                        x=d1-1;
                        y=d2+1;
                        while(szachownica[x][y][0]==0 & x>=0 & y<8)
                        {
                            if(sprawdzanie_szach_mata == false) podswietlenie[x][y]=1;
                            x=x-1;
                            y=y+1;
                        } if (szachownica[x][y][0]<=0 & x>=0 & y<8)if(sprawdzanie_szach_mata == false) podswietlenie[x][y]=1;
                         if (szachownica[x][y][0]==k)
                         {
                             szach=1;
                             if(activate_szachuje==1) szachuje=1;
                         }
                         break;
                        }

                    case 4:
                        {
                        int x=d1-1;
                        int y=d2;
                        while(szachownica[x][y][0]==0 & x>=0)
                        {
                            if(sprawdzanie_szach_mata == false) podswietlenie[x][y]=1;
                            x=x-1;
                        } if (szachownica[x][y][0]<=0 & x>=0) if(sprawdzanie_szach_mata == false)  podswietlenie[x][y]=1;
                        if (szachownica[x][y][0]==k & x>=0)
                        {
                            szach=1;
                            if(activate_szachuje==1) szachuje=1;
                        }
                        x=d1+1;
                        while(szachownica[x][y][0]==0 & x<8)
                        {
                            if(sprawdzanie_szach_mata == false) podswietlenie[x][y]=1;
                            x=x+1;
                        } if (szachownica[x][y][0]<=0 & x<8) if(sprawdzanie_szach_mata == false) podswietlenie[x][y]=1;
                        if (szachownica[x][y][0]==k & x<8)
                        {
                            szach=1;
                            if(activate_szachuje==1) szachuje=1;
                        }
                        x=d1;
                        y=d2-1;
                        while(szachownica[x][y][0]==0 & y>=0)
                        {
                            if(sprawdzanie_szach_mata == false) podswietlenie[x][y]=1;
                            y=y-1;
                        } if (szachownica[x][y][0]<=0 & y>=0) if(sprawdzanie_szach_mata == false) podswietlenie[x][y]=1;
                        if (szachownica[x][y][0]==k & y>=0)
                        {
                            szach=1;
                            if(activate_szachuje==1) szachuje=1;
                        }
                        y=d2+1;
                        while(szachownica[x][y][0]==0 & y<8)
                        {
                            if(sprawdzanie_szach_mata == false)podswietlenie[x][y]=1;
                            y=y+1;
                        } if (szachownica[x][y][0]<=0 & y<8) if(sprawdzanie_szach_mata == false) podswietlenie[x][y]=1;
                        if (szachownica[x][y][0]==k & y<8)
                        {
                            szach=1;
                            if(activate_szachuje==1) szachuje=1;
                        }
                        x=d1-1;
                        y=d2-1;
                        while(szachownica[x][y][0]==0 & x>=0 & y>=0)
                        {
                            if(sprawdzanie_szach_mata == false) podswietlenie[x][y]=1;
                            x=x-1;
                            y=y-1;
                        } if (szachownica[x][y][0]<=0 & x>=0 & y>=0) if(sprawdzanie_szach_mata == false) podswietlenie[x][y]=1;
                        if (szachownica[x][y][0]==k & x>=0 & y>=0)
                        {
                            szach=1;
                            if(activate_szachuje==1) szachuje=1;
                        }
                        x=d1+1;
                        y=d2+1;
                        while(szachownica[x][y][0]==0 & x<8 & y<8)
                        {
                            if(sprawdzanie_szach_mata == false) podswietlenie[x][y]=1;
                            x=x+1;
                            y=y+1;
                        } if (szachownica[x][y][0]<=0 & x<8 & y<8) if(sprawdzanie_szach_mata == false) podswietlenie[x][y]=1;
                        if (szachownica[x][y][0]==k & x<8 & y<8)
                        {
                            szach=1;
                            if(activate_szachuje==1) szachuje=1;
                        }
                        x=d1+1;
                        y=d2-1;
                        while(szachownica[x][y][0]==0 & x<8 & y>=0)
                        {
                            if(sprawdzanie_szach_mata == false) podswietlenie[x][y]=1;
                            x=x+1;
                            y=y-1;
                        } if (szachownica[x][y][0]<=0 & x<8 & y>=0) if(sprawdzanie_szach_mata == false)  podswietlenie[x][y]=1;
                        if (szachownica[x][y][0]==k  & x<8 & y>=0)
                        {
                            szach=1;
                            if(activate_szachuje==1) szachuje=1;
                        }
                        x=d1-1;
                        y=d2+1;
                        while(szachownica[x][y][0]==0 & x>=0 & y<8)
                        {
                            if(sprawdzanie_szach_mata == false) podswietlenie[x][y]=1;
                            x=x-1;
                            y=y+1;
                        } if (szachownica[x][y][0]<=0 & x>=0 & y<8) if(sprawdzanie_szach_mata == false) podswietlenie[x][y]=1;
                        if (szachownica[x][y][0]==k  & x>=0 & y<8)
                        {
                            szach=1;
                            if(activate_szachuje==1) szachuje=1;
                        }
                        break;
                        }

                    case 5:
                        {
                        if(szachownica[d1-1][d2][0]<=0 & d1-1>=0) if(sprawdzanie_szach_mata == false) podswietlenie[d1-1][d2]=1;
                        if(szachownica[d1+1][d2][0]<=0 & d1+1<8) if(sprawdzanie_szach_mata == false) podswietlenie[d1+1][d2]=1;
                        if(szachownica[d1][d2-1][0]<=0 & d2-1>=0) if(sprawdzanie_szach_mata == false) podswietlenie[d1][d2-1]=1;
                        if(szachownica[d1][d2+1][0]<=0 & d2+1<8) if(sprawdzanie_szach_mata == false) podswietlenie[d1][d2+1]=1;
                        if(szachownica[d1-1][d2-1][0]<=0 & d1-1>=0 & d2-1>=0) if(sprawdzanie_szach_mata == false) podswietlenie[d1-1][d2-1]=1;
                        if(szachownica[d1-1][d2+1][0]<=0 & d1-1>=0 & d2+1<8) if(sprawdzanie_szach_mata == false) podswietlenie[d1-1][d2+1]=1;
                        if(szachownica[d1+1][d2-1][0]<=0 & d1+1<8 & d2-1>=0) if(sprawdzanie_szach_mata == false) podswietlenie[d1+1][d2-1]=1;
                        if(szachownica[d1+1][d2+1][0]<=0 & d1+1<8 & d2+1<8) if(sprawdzanie_szach_mata == false) podswietlenie[d1+1][d2+1]=1;


                        if(szachownica[d1-1][d2][0]==k)
                        {
                            szach=1;
                            if(activate_szachuje==1) szachuje=1;
                        }
                        if(szachownica[d1+1][d2][0]==k)
                        {
                            szach=1;
                            if(activate_szachuje==1) szachuje=1;
                        }
                        if(szachownica[d1][d2-1][0]==k)
                        {
                            szach=1;
                            if(activate_szachuje==1) szachuje=1;
                        }
                        if(szachownica[d1][d2+1][0]==k)
                        {
                            szach=1;
                            if(activate_szachuje==1) szachuje=1;
                        }
                        if(szachownica[d1-1][d2-1][0]==k)
                        {
                            szach=1;
                            if(activate_szachuje==1) szachuje=1;
                        }
                        if(szachownica[d1-1][d2+1][0]==k)
                        {
                            szach=1;
                            if(activate_szachuje==1) szachuje=1;
                        }
                        if(szachownica[d1+1][d2-1][0]==k)
                        {
                            szach=1;
                            if(activate_szachuje==1) szachuje=1;
                        }
                        if(szachownica[d1+1][d2+1][0]==k)
                        {
                            szach=1;
                            if(activate_szachuje==1) szachuje=1;
                        }
                        break;
                        }

}}}

int sprawdz_czy_szach(int szachownica[8][8][3],int podswietlenie[8][8],int d1,int d2)
{
    czy_bicia=1;
    int alter_szachownica[8][8][3];
    if(teraz_czarne==1) teraz_czarne=0; else teraz_czarne=1;
    szach=0;
    for(int ii=0;ii<8;ii++)
    {
        for(int jj=0;jj<8;jj++)
        {
            alter_szachownica[ii][jj][0]=szachownica[ii][jj][0]*(-1);
        }
    }
    for(int ii=0;ii<8;ii++)
    {
        for(int jj=0;jj<8;jj++)
        {
            if(szachownica[ii][jj][0]<0)
            {
                pokaz_ruchy(alter_szachownica,podswietlenie,ii,jj);
            }
        }
    }
    czy_bicia=0;
    if(teraz_czarne==1) teraz_czarne=0; else teraz_czarne=1;
    if (szach==1) return 1;
        else return 0;
}

int sprawdz_ruch(int szachownica[8][8][3],int podswietlenie[8][8],int d1,int d2,int c1, int c2 , ALLEGRO_BITMAP *plansza, ALLEGRO_BITMAP *krol_b, ALLEGRO_BITMAP *krol_c, ALLEGRO_BITMAP *krolowka_b, ALLEGRO_BITMAP *krolowka_c,
                   ALLEGRO_BITMAP *hetman_b, ALLEGRO_BITMAP *hetman_c, ALLEGRO_BITMAP *kon_b, ALLEGRO_BITMAP *kon_c,ALLEGRO_BITMAP *wieza_b, ALLEGRO_BITMAP *wieza_c,
                   ALLEGRO_BITMAP *pion_b, ALLEGRO_BITMAP *pion_c,ALLEGRO_BITMAP *blue,ALLEGRO_BITMAP *blue_b,ALLEGRO_BITMAP *ruch_c,ALLEGRO_BITMAP *ruch_b,ALLEGRO_BITMAP *zapisz)
{
    int temp1=szachownica[c1][c2][0];
    int temp2=szachownica[d1][d2][0];
    int czy=0;
    if(podswietlenie[c1][c2]==1 | sprawdzanie_szach_mata == true)
    {
        szachownica[c1][c2][0]=szachownica[d1][d2][0];
        szachownica[d1][d2][0]=0;
        czy=sprawdz_czy_szach(szachownica,podswietlenie,d1,d2);
        if(czy==0)
        {
        czy_istnieje_ruch = true;
        if(sprawdzanie_szach_mata == true)
        {
           szachownica[c1][c2][0]=temp1;
           szachownica[d1][d2][0]=temp2;
        } else
        {
        if(( c1==0 | c1==7) & szachownica[c1][c2][0]==6) return 3;
        display_piony(szachownica,podswietlenie,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
        }
        return 1;

        } else
        {
            szach=0;
            szachownica[c1][c2][0]=temp1;
            szachownica[d1][d2][0]=temp2;
            return 2;
        }
    } else
    {
        return 0;
    }
}

void znajdz_ruchy(int szachownica[8][8][3],int podswietlenie[8][8])

{
    int typ;

    for (i=0;i<8;i++)
    {
        for (j=0;j<8;j++)
        {
            typ=szachownica[i][j][0];
                switch (typ)
                {
                    case 6:
                    if(teraz_czarne==0)
                    {
                        if(szachownica[i-1][j][0]==0 | (szachownica[i-1][j-1][0]<0 & i-1>=0 & j-1>=0) | (szachownica[i-1][j+1][0]<0 & i-1>=0 & j+1<8) )
                        {
                            czy_niebiesko=1;
                            podswietlenie[i][j]=1;
                        }
                    } else
                    {
                        if(szachownica[i+1][j][0]==0 | (szachownica[i+1][j-1][0]<0 & i+1<8 & j-1>=0) | (szachownica[i+1][j+1][0]<0 & i+1<8 & j+1<8) )
                        {
                            czy_niebiesko=1;
                            podswietlenie[i][j]=1;
                        }
                    }
                    break;
                    case 1:
                        if( (szachownica[i-1][j][0]==0 & i-1>0) | (szachownica[i+1][j][0]==0 & i+1<8) | (szachownica[i][j-1][0]==0 & j-1>0) | (szachownica[i][j+1][0]==0 & j+1<8) )
                        {
                            czy_niebiesko=1;
                            podswietlenie[i][j]=1;
                        }
                    break;
                    case 2:
                        if( (szachownica[i-2][j-1][0]<=0 & i-2>=0 & j-1>0) | (szachownica[i-2][j+1][0]<=0 & i-2>=0 & j+1<8) | (szachownica[i-1][j-2][0]<=0 & i-1>=0 & j-2>=0) |
                            (szachownica[i+1][j-2][0]<=0 & i+1<8 & j-2>=0) | (szachownica[i+2][j-1][0]<=0 & i+2<8 & j-1>=0) | (szachownica[i+2][j+1][0]<=0 & i+2<8 & j+1<8) |
                            (szachownica[i-1][j+2][0]<=0 & i-1>=0 & j+2<8) | (szachownica[i+1][j+2][0]<=0 & i+1<8 & j+2<8) )
                        {
                           czy_niebiesko=1;
                           podswietlenie[i][j]=1;
                        }
                    break;
                    case 3:
                        if( (szachownica[i-1][j-1][0]<=0 & i-1>=0 & j-1>=0) | (szachownica[i-1][j+1][0]<=0 & i-1>=0 & j+1<8) | (szachownica[i+1][j-1][0]<=0 & i+1<8 & j-1>=0) |
                            (szachownica[i+1][j+1][0]<=0 & i+1<8 & j+1<8) )
                        {
                           czy_niebiesko=1;
                           podswietlenie[i][j]=1;
                        }
                    break;
                    case 4:
                        if( (szachownica[i-1][j-1][0]<=0 & i-1>=0 & j-1>=0) | (szachownica[i-1][j+1][0]<=0 & i-1>=0 & j+1<8) | (szachownica[i+1][j-1][0]<=0 & i+1<8 & j-1>=0) |
                            (szachownica[i+1][j+1][0]<=0 & i+1<8 & j+1<8)   | (szachownica[i-1][j][0]<=0 & i-1>=0)  | (szachownica[i+1][j][0]<=0 & i+1<8) |
                            (szachownica[i][j+1][0]<=0 & j+1<8) | (szachownica[i][j-1][0]<=0 & j-1>=0) )
                           {
                           czy_niebiesko=1;
                           podswietlenie[i][j]=1;
                           }
                    break;
                    case 5:
                        if( (szachownica[i-1][j-1][0]<=0 & i-1>=0 & j-1>=0) | (szachownica[i-1][j+1][0]<=0 & i-1>=0 & j+1<8) | (szachownica[i+1][j-1][0]<=0 & i+1<8 & j-1>=0) |
                            (szachownica[i+1][j+1][0]<=0 & i+1<8 & j+1<8)  | (szachownica[i-1][j][0]<=0 & i-1>=0) | (szachownica[i+1][j][0]<=0 & i+1<8) |
                            (szachownica[i][j+1][0]<=0 & j+1<8) | (szachownica[i][j-1][0]<=0 & j-1>0) )
                           {
                           czy_niebiesko=1;
                           podswietlenie[i][j]=1;
                           }
                    break;

                }
}}}

int szachmat_czy_pat(int szachownica[8][8][3],int podswietlenie[8][8])
{
    int alter_szachownica[8][8][3];
    activate_szachuje=1;
    if(teraz_czarne==1) teraz_czarne=0; else teraz_czarne=1;
    for(int ii=0;ii<8;ii++)
    {
        for(int jj=0;jj<8;jj++)
        {
            alter_szachownica[ii][jj][0]=szachownica[ii][jj][0]*(-1);
        }
    }
    for(int ii=0;ii<8;ii++)
    {
        for(int jj=0;jj<8;jj++)
        {
            {
                if(szachownica[ii][jj][0]<0)
                {
                   pokaz_ruchy(alter_szachownica,podswietlenie,ii,jj);
                }
            }
        }
    }
    if(teraz_czarne==1) teraz_czarne=0; else teraz_czarne=1;
    if(szachuje==1)
    {
        szachuje=0;
        activate_szachuje=0;
        return 1;
    } else
    {
        szachuje=0;
        activate_szachuje=0;
        return 0;
    }
}

int czy_szach_mat(int szachownica[8][8][3],int podswietlenie[8][8], ALLEGRO_BITMAP *plansza, ALLEGRO_BITMAP *krol_b, ALLEGRO_BITMAP *krol_c, ALLEGRO_BITMAP *krolowka_b, ALLEGRO_BITMAP *krolowka_c,
                   ALLEGRO_BITMAP *hetman_b, ALLEGRO_BITMAP *hetman_c, ALLEGRO_BITMAP *kon_b, ALLEGRO_BITMAP *kon_c,ALLEGRO_BITMAP *wieza_b, ALLEGRO_BITMAP *wieza_c,
                   ALLEGRO_BITMAP *pion_b, ALLEGRO_BITMAP *pion_c,ALLEGRO_BITMAP *blue,ALLEGRO_BITMAP *blue_b,ALLEGRO_BITMAP *ruch_c,ALLEGRO_BITMAP *ruch_b,ALLEGRO_BITMAP *zapisz)
{
    czy_bicia=1;
    sprawdzanie_szach_mata = true;
    int typ;
    int sprawdzamy;
    czy_istnieje_ruch=0;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            typ=szachownica[i][j][0];
             switch (typ)
                {
                    case 6:
                        {
                    if(teraz_czarne==0)
                    {
                        if(szachownica[i-1][j][0]==0) sprawdz_ruch(szachownica,podswietlenie,i,j,i-1,j,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                        if(szachownica[i-1][j-1][0]<0) sprawdz_ruch(szachownica,podswietlenie,i,j,i-1,j-1,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                        if(szachownica[i-1][j+1][0]<0) sprawdz_ruch(szachownica,podswietlenie,i,j,i-1,j+1,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                        if(szachownica[i-2][j][0]==0 & szachownica[i-1][j][0]==0 & i==6) sprawdz_ruch(szachownica,podswietlenie,i,j,i-2,j,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                    }
                    else
                    {
                        if(szachownica[i+1][j][0]==0) sprawdz_ruch(szachownica,podswietlenie,i,j,i+1,j,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                        if(szachownica[i+1][j-1][0]<0) sprawdz_ruch(szachownica,podswietlenie,i,j,i+1,j-1,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                        if(szachownica[i+1][j+1][0]<0) sprawdz_ruch(szachownica,podswietlenie,i,j,i+1,j+1,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                        if(szachownica[i+2][j][0]==0 & szachownica[i+1][j][0]==0 & i==1) sprawdz_ruch(szachownica,podswietlenie,i,j,i+2,j,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                    }
                        break;
                        }
                    case 1:
                        {
                        int x=i-1;
                        int y=j;
                        while(szachownica[x][y][0]==0 & x>=0)
                        {
                            sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            x=x-1;
                        } if (szachownica[x][y][0]<=0 & x>0 & czy_bicia==0) sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                        x=i+1;
                        y=j;
                        while(szachownica[x][y][0]==0 & x<8)
                        {
                            sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            x=x+1;
                        } if (szachownica[x][y][0]<=0 & x<8 & czy_bicia==0) sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                        x=i;
                        y=j-1;
                        while(szachownica[x][y][0]==0 & y>=0)
                        {
                            sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            y=y-1;
                        } if (szachownica[x][y][0]<=0 & y>=0 & czy_bicia==0) sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                        x=i;
                        y=j+1;
                        while(szachownica[x][y][0]==0 & y<8)
                        {
                            sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            y=y+1;
                        } if (szachownica[x][y][0]<=0 & y<8 & czy_bicia==0) sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                        break;
                        }

                    case 2:
                        {
                        if(szachownica[i-2][j-1][0]<=0 & i-2>=0 & j-1>=0) sprawdz_ruch(szachownica,podswietlenie,i,j,i-2,j-1,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                        if(szachownica[i-2][j+1][0]<=0 & i-2>=0 & j+1<8)  sprawdz_ruch(szachownica,podswietlenie,i,j,i-2,j+1,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                        if(szachownica[i-1][j-2][0]<=0 & i-1>=0 & j-2>=0) sprawdz_ruch(szachownica,podswietlenie,i,j,i-1,j-2,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                        if(szachownica[i+1][j-2][0]<=0 & i+1<8 & j-2>=0)  sprawdz_ruch(szachownica,podswietlenie,i,j,i+1,j-2,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                        if(szachownica[i+2][j-1][0]<=0 & i+2<8 & j-1>=0)  sprawdz_ruch(szachownica,podswietlenie,i,j,i+2,j-1,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                        if(szachownica[i+2][j+1][0]<=0 & i+2<8 & j+1<8)   sprawdz_ruch(szachownica,podswietlenie,i,j,i+2,j+1,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                        if(szachownica[i-1][j+2][0]<=0 & i-1>=0 & j+2<8)  sprawdz_ruch(szachownica,podswietlenie,i,j,i-1,j+2,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                        if(szachownica[i+1][j+2][0]<=0 & i+1<8 & j+2<8)   sprawdz_ruch(szachownica,podswietlenie,i,j,i+1,j+2,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                        break;
                        }

                    case 3:
                        {
                        int x=i-1;
                        int y=j-1;
                        while(szachownica[x][y][0]==0 & x>=0 & y>=0)
                        {
                            sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            x=x-1;
                            y=y-1;
                        } if (szachownica[x][y][0]<=0 & x>=0 & y>=0) sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                        x=i+1;
                        y=j+1;
                        while(szachownica[x][y][0]==0 & x<8 & y<8)
                        {
                            sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            x=x+1;
                            y=y+1;
                        } if (szachownica[x][y][0]<=0 & x<8 & y<8) sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                        x=i+1;
                        y=j-1;
                        while(szachownica[x][y][0]==0 & x<8 & y>=0)
                        {
                            sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            x=x+1;
                            y=y-1;
                        } if (szachownica[x][y][0]<=0 & x<8 & y>=0) sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                        x=i-1;
                        y=j+1;
                        while(szachownica[x][y][0]==0 & x>=0 & y<8)
                        {
                            sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            x=x-1;
                            y=y+1;
                        } if (szachownica[x][y][0]<=0 & x>=0 & y<8) sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                         break;
                        }

                    case 4:
                        {
                        int x=i-1;
                        int y=j;
                        while(szachownica[x][y][0]==0 & x>=0)
                        {
                            sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            x=x-1;
                        } if (szachownica[x][y][0]<=0 & x>=0)  sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                        x=i+1;
                        while(szachownica[x][y][0]==0 & x<8)
                        {
                            sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            x=x+1;
                        } if (szachownica[x][y][0]<=0 & x<8) sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                        x=i;
                        y=j-1;
                        while(szachownica[x][y][0]==0 & y>=0)
                        {
                            sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            y=y-1;
                        } if (szachownica[x][y][0]<=0 & y>=0) sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                        y=j+1;
                        while(szachownica[x][y][0]==0 & y<8)
                        {
                            sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            y=y+1;
                        } if (szachownica[x][y][0]<=0 & y<8) sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                        x=i-1;
                        y=j-1;
                        while(szachownica[x][y][0]==0 & x>=0 & y>=0)
                        {
                            sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            x=x-1;
                            y=y-1;
                        } if (szachownica[x][y][0]<=0 & x>=0 & y>=0) sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                        x=i+1;
                        y=j+1;
                        while(szachownica[x][y][0]==0 & x<8 & y<8)
                        {
                            sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            x=x+1;
                            y=y+1;
                        } if (szachownica[x][y][0]<=0 & x<8 & y<8) sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                        x=i+1;
                        y=j-1;
                        while(szachownica[x][y][0]==0 & x<8 & y>=0)
                        {
                            sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            x=x+1;
                            y=y-1;
                        } if (szachownica[x][y][0]<=0 & x<8 & y>=0) sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                        y=j+1;
                        while(szachownica[x][y][0]==0 & x>=0 & y<8)
                        {
                            sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            x=x-1;
                            y=y+1;
                        } if (szachownica[x][y][0]<=0 & x>=0 & y<8) sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                        break;
                        }

                    case 5:
                        {
                        if(szachownica[i-1][j][0]<=0 & i-1>=0) sprawdz_ruch(szachownica,podswietlenie,i,j,i-1,j,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                        if(szachownica[i+1][j][0]<=0 & i+1<8) sprawdz_ruch(szachownica,podswietlenie,i,j,i+1,j,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                        if(szachownica[i][j-1][0]<=0 & j-1>=0) sprawdz_ruch(szachownica,podswietlenie,i,j,i,j-1,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                        if(szachownica[i][j+1][0]<=0 & j+1<8) sprawdz_ruch(szachownica,podswietlenie,i,j,i,j+1,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                        if(szachownica[i-1][j-1][0]<=0 & i-1>=0 & j-1>=0) sprawdz_ruch(szachownica,podswietlenie,i,j,i-1,j-1,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                        if(szachownica[i-1][j+1][0]<=0 & i-1>=0 & j+1<8) sprawdz_ruch(szachownica,podswietlenie,i,j,i-1,j+1,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                        if(szachownica[i+1][j-1][0]<=0 & i+1<8 & j-1>=0) sprawdz_ruch(szachownica,podswietlenie,i,j,i+1,j-1,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                        if(szachownica[i+1][j+1][0]<=0 & i+1<8 & j+1<8) sprawdz_ruch(szachownica,podswietlenie,i,j,i+1,j+1,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                        break;
                        }
        }
        }
    }
    sprawdzamy=szachmat_czy_pat(szachownica,podswietlenie);
    int check=2;
    if(czy_istnieje_ruch==false)
    {
        if(sprawdzamy==1) check=1;
        else check=0;
    }
        else
    szachuje=0;
    sprawdzanie_szach_mata = false;
    czy_bicia=0;
    czy_istnieje_ruch=false;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            podswietlenie[i][j]=0;
        }
    }
    if(check!=2) return check;
}

void czy_oplacalny(int d1,int d2,int typ1 ,int c1,int c2,int typ2)

{
    if(typ1!=6) typ1+=1; else typ1=1;
    if(typ2!=0)
    {
        if(typ2!=6) typ2+=1; else typ2=1;
    }
    if(type==0)
    {
        xx=d1;
        yy=d2;
        XX=c1;
        YY=c2;
        type = typ1;
        if(typ2!=0)
        {
            type_bitego=typ2;
            roznica=typ2-typ1;
        }
    } else if (type_bitego==0 | roznica < typ2-typ1)
    {
        xx=d1;
        yy=d2;
        XX=c1;
        YY=c2;
        type = typ1;
        type_bitego=typ2;
        roznica=typ2-typ1;
    } else
    {
        int szansa;
        szansa=rand()%4;
        printf("&d",szansa);
        if (szansa!=0)
        {
        xx=d1;
        yy=d2;
        XX=c1;
        YY=c2;
        type = typ1;
        if(typ2!=0)
        {
            type_bitego=typ2;
            roznica=typ2-typ1;
        } else
        {
            type_bitego=0;
            roznica=0;
        }
        }
    }
}

int AI(int szachownica[8][8][3],int podswietlenie[8][8], ALLEGRO_BITMAP *plansza, ALLEGRO_BITMAP *krol_b, ALLEGRO_BITMAP *krol_c, ALLEGRO_BITMAP *krolowka_b, ALLEGRO_BITMAP *krolowka_c,
                   ALLEGRO_BITMAP *hetman_b, ALLEGRO_BITMAP *hetman_c, ALLEGRO_BITMAP *kon_b, ALLEGRO_BITMAP *kon_c,ALLEGRO_BITMAP *wieza_b, ALLEGRO_BITMAP *wieza_c,
                   ALLEGRO_BITMAP *pion_b, ALLEGRO_BITMAP *pion_c,ALLEGRO_BITMAP *blue,ALLEGRO_BITMAP *blue_b,ALLEGRO_BITMAP *ruch_c,ALLEGRO_BITMAP *ruch_b,ALLEGRO_BITMAP *zapisz)
{
    int koniec_gry;
    koniec_gry=czy_szach_mat(szachownica,podswietlenie,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
    if(koniec_gry==1) return 3;
    if(koniec_gry==0) return 4;
    sprawdzanie_szach_mata = true;
    int sprawdz;
    int typ;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            typ=szachownica[i][j][0];
             switch (typ)
                {
                    case 6:
                        {
                        if(szachownica[i+1][j][0]==0) {
                                sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,i+1,j,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                                if(sprawdz==1) czy_oplacalny(i,j,typ,i+1,j,szachownica[i+1][j][0]);
                        }
                        if(szachownica[i+1][j-1][0]<0) {
                                sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,i+1,j-1,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                                if(sprawdz==1) czy_oplacalny(i,j,typ,i+1,j-1,szachownica[i+1][j-1][0]);
                        }
                        if(szachownica[i+1][j+1][0]<0) {
                                sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,i+1,j+1,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                                if(sprawdz==1) czy_oplacalny(i,j,typ,i+1,j+1,szachownica[i+1][j+1][0]);
                        }
                        if(szachownica[i+2][j][0]==0 & szachownica[i+1][j][0]==0 & i==1) {
                                sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,i+2,j,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                                if(sprawdz==1) czy_oplacalny(i,j,typ,i+2,j,szachownica[i+2][j][0]);

                        }
                        break;
                        }
                    case 1:
                        {
                        int x=i-1;
                        int y=j;
                        while(szachownica[x][y][0]==0 & x>=0)
                        {
                            sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            if(sprawdz==1) czy_oplacalny(i,j,typ,x,y,szachownica[x][y][0]);
                            x=x-1;
                        } if (szachownica[x][y][0]<=0 & x>0 & czy_bicia==0) {
                            sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            if(sprawdz==1) czy_oplacalny(i,j,typ,x,y,szachownica[x][y][0]);}
                        x=i+1;
                        y=j;
                        while(szachownica[x][y][0]==0 & x<8)
                        {
                            sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            if(sprawdz==1) czy_oplacalny(i,j,typ,x,y,szachownica[x][y][0]);
                            x=x+1;
                        } if (szachownica[x][y][0]<=0 & x<8 & czy_bicia==0) {
                            sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            if(sprawdz==1) czy_oplacalny(i,j,typ,x,y,szachownica[x][y][0]);}
                        x=i;
                        y=j-1;
                        while(szachownica[x][y][0]==0 & y>=0)
                        {
                            sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            if(sprawdz==1) czy_oplacalny(i,j,typ,x,y,szachownica[x][y][0]);
                            y=y-1;
                        } if (szachownica[x][y][0]<=0 & y>=0 & czy_bicia==0) {
                            sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            if(sprawdz==1) czy_oplacalny(i,j,typ,x,y,szachownica[x][y][0]);}
                        x=i;
                        y=j+1;
                        while(szachownica[x][y][0]==0 & y<8)
                        {
                            sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            if(sprawdz==1) czy_oplacalny(i,j,typ,x,y,szachownica[x][y][0]);
                            y=y+1;
                        } if (szachownica[x][y][0]<=0 & y<8 & czy_bicia==0) {
                            sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            if(sprawdz==1) czy_oplacalny(i,j,typ,x,y,szachownica[x][y][0]);}
                        break;
                        }

                    case 2:
                        {
                        if(szachownica[i-2][j-1][0]<=0 & i-2>=0 & j-1>=0) {
                                sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,i-2,j-1,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                                if(sprawdz==1) czy_oplacalny(i,j,typ,i-2,j-1,szachownica[i-2][j-1][0]);
                        }
                        if(szachownica[i-2][j+1][0]<=0 & i-2>=0 & j+1<8)  {
                                sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,i-2,j+1,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                                if(sprawdz==1) czy_oplacalny(i,j,typ,i-2,j+1,szachownica[i-2][j+1][0]);
                        }
                        if(szachownica[i-1][j-2][0]<=0 & i-1>=0 & j-2>=0) {
                                sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,i-1,j-2,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                                if(sprawdz==1) czy_oplacalny(i,j,typ,i-1,j-2,szachownica[i-1][j-2][0]);
                        }
                        if(szachownica[i+1][j-2][0]<=0 & i+1<8 & j-2>=0)  {
                                sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,i+1,j-2,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                                if(sprawdz==1) czy_oplacalny(i,j,typ,i+1,j-2,szachownica[i+1][j-2][0]);
                        }
                        if(szachownica[i+2][j-1][0]<=0 & i+2<8 & j-1>=0)  {
                                sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,i+2,j-1,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                                if(sprawdz==1) czy_oplacalny(i,j,typ,i+2,j-1,szachownica[i+2][j-1][0]);
                        }
                        if(szachownica[i+2][j+1][0]<=0 & i+2<8 & j+1<8)   {
                                sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,i+2,j+1,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                                if(sprawdz==1) czy_oplacalny(i,j,typ,i+2,j+1,szachownica[i+2][j+1][0]);
                        }
                        if(szachownica[i-1][j+2][0]<=0 & i-1>=0 & j+2<8)  {
                                sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,i-1,j+2,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                                if(sprawdz==1) czy_oplacalny(i,j,typ,i-1,j+2,szachownica[i-1][j+2][0]);
                        }
                        if(szachownica[i+1][j+2][0]<=0 & i+1<8 & j+2<8)   {
                                sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,i+1,j+2,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                                if(sprawdz==1) czy_oplacalny(i,j,typ,i+1,j+2,szachownica[i+1][j+2][0]);
                        }
                        break;
                        }

                    case 3:
                        {
                        int x=i-1;
                        int y=j-1;
                        while(szachownica[x][y][0]==0 & x>=0 & y>=0)
                        {
                            sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            if(sprawdz==1) czy_oplacalny(i,j,typ,x,y,szachownica[x][y][0]);
                            x=x-1;
                            y=y-1;
                        } if (szachownica[x][y][0]<=0 & x>=0 & y>=0) {
                            sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            if(sprawdz==1) czy_oplacalny(i,j,typ,x,y,szachownica[x][y][0]);}
                        x=i+1;
                        y=j+1;
                        while(szachownica[x][y][0]==0 & x<8 & y<8)
                        {
                            sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            if(sprawdz==1) czy_oplacalny(i,j,typ,x,y,szachownica[x][y][0]);
                            x=x+1;
                            y=y+1;
                        } if (szachownica[x][y][0]<=0 & x<8 & y<8) {
                            sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            if(sprawdz==1) czy_oplacalny(i,j,typ,x,y,szachownica[x][y][0]);}
                        x=i+1;
                        y=j-1;
                        while(szachownica[x][y][0]==0 & x<8 & y>=0)
                        {
                            sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            if(sprawdz==1) czy_oplacalny(i,j,typ,x,y,szachownica[x][y][0]);
                            x=x+1;
                            y=y-1;
                        } if (szachownica[x][y][0]<=0 & x<8 & y>=0) {
                            sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            if(sprawdz==1) czy_oplacalny(i,j,typ,x,y,szachownica[x][y][0]);}
                        x=i-1;
                        y=j+1;
                        while(szachownica[x][y][0]==0 & x>=0 & y<8)
                        {
                            sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            if(sprawdz==1) czy_oplacalny(i,j,typ,x,y,szachownica[x][y][0]);
                            x=x-1;
                            y=y+1;
                        } if (szachownica[x][y][0]<=0 & x>=0 & y<8) {
                            sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            if(sprawdz==1) czy_oplacalny(i,j,typ,x,y,szachownica[x][y][0]);}
                         break;
                        }

                    case 4:
                        {
                        int x=i-1;
                        int y=j;
                        while(szachownica[x][y][0]==0 & x>=0)
                        {
                            sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            if(sprawdz==1) czy_oplacalny(i,j,typ,x,y,szachownica[x][y][0]);
                            x=x-1;
                        } if (szachownica[x][y][0]<=0 & x>=0)  {
                            sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            if(sprawdz==1) czy_oplacalny(i,j,typ,x,y,szachownica[x][y][0]);}
                        x=i+1;
                        while(szachownica[x][y][0]==0 & x<8)
                        {
                            sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            if(sprawdz==1) czy_oplacalny(i,j,typ,x,y,szachownica[x][y][0]);
                            x=x+1;
                        } if (szachownica[x][y][0]<=0 & x<8) {
                            sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            if(sprawdz==1) czy_oplacalny(i,j,typ,x,y,szachownica[x][y][0]);}
                        x=i;
                        y=j-1;
                        while(szachownica[x][y][0]==0 & y>=0)
                        {
                            sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            if(sprawdz==1) czy_oplacalny(i,j,typ,x,y,szachownica[x][y][0]);
                            y=y-1;
                        } if (szachownica[x][y][0]<=0 & y>=0) {
                            sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            if(sprawdz==1) czy_oplacalny(i,j,typ,x,y,szachownica[x][y][0]);}
                        y=j+1;
                        while(szachownica[x][y][0]==0 & y<8)
                        {
                            sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            if(sprawdz==1) czy_oplacalny(i,j,typ,x,y,szachownica[x][y][0]);
                            y=y+1;
                        } if (szachownica[x][y][0]<=0 & y<8) {
                            sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            if(sprawdz==1) czy_oplacalny(i,j,typ,x,y,szachownica[x][y][0]);}
                        x=i-1;
                        y=j-1;
                        while(szachownica[x][y][0]==0 & x>=0 & y>=0)
                        {
                            sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            if(sprawdz==1) czy_oplacalny(i,j,typ,x,y,szachownica[x][y][0]);
                            x=x-1;
                            y=y-1;
                        } if (szachownica[x][y][0]<=0 & x>=0 & y>=0) {
                            sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            if(sprawdz==1) czy_oplacalny(i,j,typ,x,y,szachownica[x][y][0]);}
                        x=i+1;
                        y=j+1;
                        while(szachownica[x][y][0]==0 & x<8 & y<8)
                        {
                            sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            if(sprawdz==1) czy_oplacalny(i,j,typ,x,y,szachownica[x][y][0]);
                            x=x+1;
                            y=y+1;
                        } if (szachownica[x][y][0]<=0 & x<8 & y<8) {
                            sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            if(sprawdz==1) czy_oplacalny(i,j,typ,x,y,szachownica[x][y][0]);}
                        x=i+1;
                        y=j-1;
                        while(szachownica[x][y][0]==0 & x<8 & y>=0)
                        {
                            sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            if(sprawdz==1) czy_oplacalny(i,j,typ,x,y,szachownica[x][y][0]);
                            x=x+1;
                            y=y-1;
                        } if (szachownica[x][y][0]<=0 & x<8 & y>=0) {
                            sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            if(sprawdz==1) czy_oplacalny(i,j,typ,x,y,szachownica[x][y][0]);}
                        y=j+1;
                        while(szachownica[x][y][0]==0 & x>=0 & y<8)
                        {
                            sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            if(sprawdz==1) czy_oplacalny(i,j,typ,x,y,szachownica[x][y][0]);
                            x=x-1;
                            y=y+1;
                        } if (szachownica[x][y][0]<=0 & x>=0 & y<8) {
                            sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,x,y,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                            if(sprawdz==1) czy_oplacalny(i,j,typ,x,y,szachownica[x][y][0]);}
                        break;
                        }

                    case 5:
                        {
                        if(szachownica[i-1][j][0]<=0 & i-1>=0) {
                                sprawdz=sprawdz_ruch(szachownica,podswietlenie,i,j,i-1,j,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                                if(sprawdz==1) czy_oplacalny(i,j,typ,i-1,j,szachownica[i-1][j][0]);}
                        if(szachownica[i+1][j][0]<=0 & i+1<8) {
                                sprawdz_ruch(szachownica,podswietlenie,i,j,i+1,j,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                                if(sprawdz==1) czy_oplacalny(i,j,typ,i+1,j,szachownica[i+1][j][0]);}
                        if(szachownica[i][j-1][0]<=0 & j-1>=0) {
                                sprawdz_ruch(szachownica,podswietlenie,i,j,i,j-1,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                                if(sprawdz==1) czy_oplacalny(i,j,typ,i,j-1,szachownica[i][j-1][0]);}
                        if(szachownica[i][j+1][0]<=0 & j+1<8) {
                                sprawdz_ruch(szachownica,podswietlenie,i,j,i,j+1,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                                if(sprawdz==1) czy_oplacalny(i,j,typ,i,j+1,szachownica[i][j+1][0]);}
                        if(szachownica[i-1][j-1][0]<=0 & i-1>=0 & j-1>=0) {
                                sprawdz_ruch(szachownica,podswietlenie,i,j,i-1,j-1,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                                if(sprawdz==1) czy_oplacalny(i,j,typ,i-1,j-1,szachownica[i-1][j-1][0]);}
                        if(szachownica[i-1][j+1][0]<=0 & i-1>=0 & j+1<8) {
                                sprawdz_ruch(szachownica,podswietlenie,i,j,i-1,j+1,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                                if(sprawdz==1) czy_oplacalny(i,j,typ,i-1,j+1,szachownica[i-1][j+1][0]);}
                        if(szachownica[i+1][j-1][0]<=0 & i+1<8 & j-1>=0) {
                                sprawdz_ruch(szachownica,podswietlenie,i,j,i+1,j-1,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                                if(sprawdz==1) czy_oplacalny(i,j,typ,i+1,j-1,szachownica[i+1][j-1][0]);}
                        if(szachownica[i+1][j+1][0]<=0 & i+1<8 & j+1<8) {
                                sprawdz_ruch(szachownica,podswietlenie,i,j,i+1,j+1,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                                if(sprawdz==1) czy_oplacalny(i,j,typ,i+1,j+1,szachownica[i+1][j+1][0]);}
                        break;
                        }
                }
        }
    }

    szachownica[XX][YY][0]=szachownica[xx][yy][0];
    szachownica[xx][yy][0]=0;
    sprawdz=sprawdz_ruch(szachownica,podswietlenie,xx,yy,XX,YY,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
    if(sprawdz==3) szachownica[XX][YY][0]=4;
    sprawdzanie_szach_mata = false;
    xx=0; yy=0; XX=0; YY=0; type=0; type_bitego=0; roznica=0;
    display_piony(szachownica,podswietlenie,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
    al_flip_display();
    return 1;

}


int tura(ALLEGRO_EVENT_QUEUE * event_queue, int szachownica[8][8][3],int podswietlenie[8][8],ALLEGRO_BITMAP *plansza, ALLEGRO_BITMAP *krol_b, ALLEGRO_BITMAP *krol_c, ALLEGRO_BITMAP *krolowka_b, ALLEGRO_BITMAP *krolowka_c,
                   ALLEGRO_BITMAP *hetman_b, ALLEGRO_BITMAP *hetman_c, ALLEGRO_BITMAP *kon_b, ALLEGRO_BITMAP *kon_c,ALLEGRO_BITMAP *wieza_b, ALLEGRO_BITMAP *wieza_c,
                   ALLEGRO_BITMAP *pion_b, ALLEGRO_BITMAP *pion_c,ALLEGRO_BITMAP *blue,ALLEGRO_BITMAP *blue_b,ALLEGRO_BITMAP *ruch_c,ALLEGRO_BITMAP *ruch_b,ALLEGRO_BITMAP *zapisz,ALLEGRO_BITMAP *zapisz2,ALLEGRO_DISPLAY * okno)
{
    int koniec_gry;
    koniec_gry=czy_szach_mat(szachownica,podswietlenie,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
    if(koniec_gry==1) return 3;
    if(koniec_gry==0) return 4;
    znajdz_ruchy(szachownica,podswietlenie);
    display_piony(szachownica,podswietlenie,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
    al_flip_display();
    ALLEGRO_EVENT ev;
    bool czy = false;
    bool niebieski_zapisz = false;
    int pos_x = 7;
    int pos_y = 7;
    int pos_x2 = 0;
    int pos_y2 = 0;
    int c1=0;
    int c2=0;
    int d1,d2;
    int sprawdz;
    al_draw_bitmap (zapisz,650,470,0);
    while(!czy)
    {
        al_wait_for_event(event_queue, &ev);
        al_draw_rectangle(pos_x,pos_y,pos_x + 74,pos_y +74, al_map_rgb(255,0,0),5);
        al_flip_display();
        if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            switch(ev.keyboard.keycode)
            {
            case ALLEGRO_KEY_UP:
               if(pos_y-79>=7)
               {
                   pos_y -= 79;
                   c1-=1;
               }
               display_piony(szachownica,podswietlenie,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
               al_draw_rectangle(pos_x,pos_y,pos_x + 74,pos_y +74, al_map_rgb(255,0,0),5);
               if(niebieski_zapisz==true) al_draw_bitmap(zapisz2,650,470,0); else al_draw_bitmap(zapisz,650,470,0);
               if(pos_x2 != 0) al_draw_rectangle(pos_x2,pos_y2,pos_x2 + 74,pos_y2 +74, al_map_rgb(255,0,0),5);
               al_flip_display();
                break;
            case ALLEGRO_KEY_DOWN:
                if(pos_y+79<=560)
               {
                   pos_y += 79;
                   c1+=1;
               }
                display_piony(szachownica,podswietlenie,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                if(niebieski_zapisz==true) al_draw_bitmap(zapisz2,650,470,0); else al_draw_bitmap(zapisz,650,470,0);
                al_draw_rectangle(pos_x,pos_y,pos_x + 74,pos_y +74, al_map_rgb(255,0,0),5);
                if(pos_x2 != 0) al_draw_rectangle(pos_x2,pos_y2,pos_x2 + 74,pos_y2 +74, al_map_rgb(255,0,0),5);
                al_flip_display();
                break;
            case ALLEGRO_KEY_LEFT:
                if(pos_x>560) pos_x-=300;
                else if(pos_x-79>=6)
               {
                   pos_x -= 79;
                   c2-=1;
                   }
                niebieski_zapisz=false;
                display_piony(szachownica,podswietlenie,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                al_draw_rectangle(pos_x,pos_y,pos_x + 74,pos_y +74, al_map_rgb(255,0,0),5);
               if(niebieski_zapisz==true) al_draw_bitmap(zapisz2,650,470,0); else al_draw_bitmap(zapisz,650,470,0);
               if(pos_x2 != 0) al_draw_rectangle(pos_x2,pos_y2,pos_x2 + 74,pos_y2 +74, al_map_rgb(255,0,0),5);
                al_flip_display();
                break;

            case ALLEGRO_KEY_RIGHT:
                if(pos_x+79<=560)
               {
                   pos_x += 79;
                   c2+=1;
               } else if(pos_x<=860)
               {
                   niebieski_zapisz=true;
                   pos_x+=300;
               }
                display_piony(szachownica,podswietlenie,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                al_draw_rectangle(pos_x,pos_y,pos_x + 74,pos_y +74, al_map_rgb(255,0,0),5);
                if(niebieski_zapisz==true) al_draw_bitmap(zapisz2,650,470,0); else al_draw_bitmap(zapisz,650,470,0);
                if(pos_x2 != 0) al_draw_rectangle(pos_x2,pos_y2,pos_x2 + 74,pos_y2 +74, al_map_rgb(255,0,0),5);
                al_flip_display();
                break;

            case ALLEGRO_KEY_ENTER:
                {
                if(niebieski_zapisz == true) return 2; else
                   {
                if (pos_x2!=0)
                {
                   if(podswietlenie[c1][c2]==1)
                   {
                   czy_bicia=1;
                   szach=0;
                   sprawdz=sprawdz_ruch(szachownica,podswietlenie,d1,d2,c1,c2,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                   if(sprawdz==3) {int wartosc=al_show_native_message_box(okno,"Wybierz","Czy pion ma sie zmienic w Hetmana?","Jezeli nie, zostanie Skoczkiem","",ALLEGRO_MESSAGEBOX_YES_NO);
                   if(wartosc==1) szachownica[c1][c2][0]=4; else szachownica[c1][c2][0]=2;}

                   if (sprawdz==1 | sprawdz==3) return 1; else
                   {
                       pos_x2 = 0;
                czy_niebiesko = 0;
                for(i=0;i<8;i++)
                {
                    for(j=0;j<8;j++)
                    {
                        podswietlenie[i][j]=0;
                    }
                }
                znajdz_ruchy(szachownica,podswietlenie);
                display_piony(szachownica,podswietlenie,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                if(niebieski_zapisz==true) al_draw_bitmap(zapisz2,650,470,0); else al_draw_bitmap(zapisz,650,470,0);
                al_draw_rectangle(pos_x,pos_y,pos_x + 74,pos_y +74, al_map_rgb(255,0,0),5);
                al_flip_display();
                   }
                   } else
                   {
                pos_x2 = 0;
                czy_niebiesko = 0;
                for(i=0;i<8;i++)
                {
                    for(j=0;j<8;j++)
                    {
                        podswietlenie[i][j]=0;
                    }
                }
                znajdz_ruchy(szachownica,podswietlenie);
                display_piony(szachownica,podswietlenie,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                if(niebieski_zapisz==true) al_draw_bitmap(zapisz2,650,470,0); else al_draw_bitmap(zapisz,650,470,0);
                al_draw_rectangle(pos_x,pos_y,pos_x + 74,pos_y +74, al_map_rgb(255,0,0),5);
                al_flip_display();
                   }
                } else
                {
                if(podswietlenie[c1][c2]==1)
                   {
                   pos_x2 = pos_x;
                   pos_y2 = pos_y;
                   d1=c1;
                   d2=c2;
                   pokaz_ruchy(szachownica,podswietlenie,d1,d2);
                   display_piony(szachownica,podswietlenie,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                   if(niebieski_zapisz==true) al_draw_bitmap(zapisz2,650,470,0); else al_draw_bitmap(zapisz,650,470,0);
                   al_flip_display();
                  }
                } }break;
            }

            case ALLEGRO_KEY_ESCAPE:
                if (pos_x2!=0) pos_x2 = 0;
                czy_niebiesko = 0;
                for(i=0;i<8;i++)
                {
                    for(j=0;j<8;j++)
                    {
                        podswietlenie[i][j]=0;
                    }
                }
                znajdz_ruchy(szachownica,podswietlenie);
                display_piony(szachownica,podswietlenie,plansza,krol_b,krol_c,krolowka_b,krolowka_c,hetman_b,hetman_c,kon_b,kon_c,wieza_b,wieza_c,pion_b,pion_c,blue,blue_b,ruch_c,ruch_b,zapisz);
                if(niebieski_zapisz==true) al_draw_bitmap(zapisz2,200,200,0); else al_draw_bitmap(zapisz,650,470,0);
                al_draw_rectangle(pos_x,pos_y,pos_x + 74,pos_y +74, al_map_rgb(255,0,0),5);
                if(pos_x2 != 0) al_draw_rectangle(pos_x2,pos_y2,pos_x2 + 74,pos_y2 +74, al_map_rgb(255,0,0),5);
                al_flip_display();
                break;
                }
                }else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) return 0;
                }}

int sub_menu(ALLEGRO_EVENT_QUEUE * event_queue,int y,ALLEGRO_BITMAP *plansza,ALLEGRO_BITMAP *menu, ALLEGRO_BITMAP *vsgracz, ALLEGRO_BITMAP *vskomputer,
             ALLEGRO_BITMAP *powrot, ALLEGRO_BITMAP *vsgracz2, ALLEGRO_BITMAP *vskomputer2, ALLEGRO_BITMAP *powrot2)
{
    bool czy = false;
    ALLEGRO_EVENT ev;
    al_draw_bitmap (menu,0,0,0);
    al_draw_bitmap (vsgracz, 130,60,NULL);
    al_draw_bitmap (vskomputer, 80,200,NULL);
    al_draw_bitmap (powrot, 170,395,NULL);
    al_flip_display();
    while(!czy)
    {
        al_wait_for_event(event_queue, &ev);
        if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
          {
            switch(ev.keyboard.keycode)
            {
               case ALLEGRO_KEY_UP:
                  if(y>1) y -= 1;

        switch(y)
            {
                case 1:
                al_draw_bitmap (menu,0,0,0);
                al_draw_bitmap (vsgracz2, 130,60,NULL);
                al_draw_bitmap (vskomputer, 80,200,NULL);
                al_draw_bitmap (powrot, 170,395,NULL);
                al_flip_display();
                break;
                case 2:
                al_draw_bitmap (menu,0,0,0);
                al_draw_bitmap (vsgracz, 130,60,NULL);
                al_draw_bitmap (vskomputer2, 80,200,NULL);
                al_draw_bitmap (powrot, 170,395,NULL);
                al_flip_display();
                break;
                case 3:
                al_draw_bitmap (menu,0,0,0);
                al_draw_bitmap (vsgracz, 130,60,NULL);
                al_draw_bitmap (vskomputer, 80,200,NULL);
                al_draw_bitmap (powrot2, 170,395,NULL);
                al_flip_display();
                break;
            }

                  break;
               case ALLEGRO_KEY_DOWN:
                  if(y<3) y += 1;

        switch(y)
            {
                case 1:
                al_draw_bitmap (menu,0,0,0);
                al_draw_bitmap (vsgracz2, 130,60,NULL);
                al_draw_bitmap (vskomputer, 80,200,NULL);
                al_draw_bitmap (powrot, 170,395,NULL);
                al_flip_display();
                break;
                case 2:
                al_draw_bitmap (menu,0,0,0);
                al_draw_bitmap (vsgracz, 130,60,NULL);
                al_draw_bitmap (vskomputer2, 80,200,NULL);
                al_draw_bitmap (powrot, 170,395,NULL);
                al_flip_display();
                break;
                case 3:
                al_draw_bitmap (menu,0,0,0);
                al_draw_bitmap (vsgracz, 130,60,NULL);
                al_draw_bitmap (vskomputer, 80,200,NULL);
                al_draw_bitmap (powrot2, 170,395,NULL);
                al_flip_display();
                break;
            }

                  break;

               case ALLEGRO_KEY_ENTER:
                switch(y)
            {
                case 1:
                return 1;
                break;
                case 2:
                return 2;
                break;
                case 3:
                return 0;
                break;
            }
                break;
             }

        } else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) return 4;
    }
}

int display_menu(ALLEGRO_EVENT_QUEUE * event_queue,int y,ALLEGRO_BITMAP *plansza,ALLEGRO_BITMAP *menu, ALLEGRO_BITMAP *nowa_gra, ALLEGRO_BITMAP *wczytaj,
                 ALLEGRO_BITMAP *exit, ALLEGRO_BITMAP *nowa_gra2, ALLEGRO_BITMAP *wczytaj2, ALLEGRO_BITMAP *exit2,ALLEGRO_BITMAP *vsgracz,
                 ALLEGRO_BITMAP *vskomputer, ALLEGRO_BITMAP *powrot, ALLEGRO_BITMAP *vsgracz2, ALLEGRO_BITMAP *vskomputer2, ALLEGRO_BITMAP *powrot2)
{
    bool czy = false;
    ALLEGRO_EVENT ev;
    al_draw_bitmap (menu,0,0,0);
    al_draw_bitmap (nowa_gra, 120,60,NULL);
    al_draw_bitmap (wczytaj, 90,200,NULL);
    al_draw_bitmap (exit, 240,395,NULL);
    al_flip_display();
    while(!czy)
    {
        al_wait_for_event(event_queue, &ev);
        if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
          {
            switch(ev.keyboard.keycode)
            {
               case ALLEGRO_KEY_UP:
                  if(y>1) y -= 1;

        switch(y)
            {
                case 1:
                al_draw_bitmap (menu,0,0,0);
                al_draw_bitmap (nowa_gra2, 120,60,NULL);
                al_draw_bitmap (wczytaj, 90,200,NULL);
                al_draw_bitmap (exit, 240,395,NULL);
                al_flip_display();
                break;
                case 2:
                al_draw_bitmap (menu,0,0,0);
                al_draw_bitmap (nowa_gra, 120,60,NULL);
                al_draw_bitmap (wczytaj2, 90,200,NULL);
                al_draw_bitmap (exit, 240,395,NULL);
                al_flip_display();
                break;
                case 3:
                al_draw_bitmap (menu,0,0,0);
                al_draw_bitmap (nowa_gra, 120,60,NULL);
                al_draw_bitmap (wczytaj, 90,200,NULL);
                al_draw_bitmap (exit2, 240,395,NULL);
                al_flip_display();
                break;
            }

                  break;
               case ALLEGRO_KEY_DOWN:
                  if(y<3) y += 1;

        switch(y)
            {
                case 1:
                al_draw_bitmap (menu,0,0,0);
                al_draw_bitmap (nowa_gra2, 120,60,NULL);
                al_draw_bitmap (wczytaj, 90,200,NULL);
                al_draw_bitmap (exit, 240,395,NULL);
                al_flip_display();
                break;
                case 2:
                al_draw_bitmap (menu,0,0,0);
                al_draw_bitmap (nowa_gra, 120,60,NULL);
                al_draw_bitmap (wczytaj2, 90,200,NULL);
                al_draw_bitmap (exit, 240,395,NULL);
                al_flip_display();
                break;
                case 3:
                al_draw_bitmap (menu,0,0,0);
                al_draw_bitmap (nowa_gra, 120,60,NULL);
                al_draw_bitmap (wczytaj, 90,200,NULL);
                al_draw_bitmap (exit2, 240,395,NULL);
                al_flip_display();
                break;
            }

                  break;

               case ALLEGRO_KEY_ENTER:

                switch(y)
            {
                case 1:
                int wynik;
                wynik=sub_menu(event_queue,0,plansza,menu,vsgracz,vskomputer,powrot,vsgracz2,vskomputer2,powrot2);
                if (wynik==0) display_menu(event_queue,0,plansza,menu,nowa_gra,wczytaj,exit,nowa_gra2,wczytaj2,exit2,vsgracz,vskomputer,powrot,vsgracz2,vskomputer2,powrot2);
                if (wynik==1) return 1;
                if (wynik==2) return 2;
                if (wynik==4) return 0;
                break;

                case 2:
                    return 4;
                break;

                case 3:
                    return 0;
                break;
            }
             }

        } else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) return 0;
    }


}
int main() {

    al_init();
    bool done = false;
    int zarodek;
    time_t tt;
    zarodek = time(&tt);
    srand(zarodek);
    FILE *zapis_gry;
    al_init_primitives_addon();
    al_install_keyboard();
    al_install_mouse();
    al_init_image_addon();
    ALLEGRO_KEYBOARD_STATE klawiatura;
    ALLEGRO_DISPLAY * okno = al_create_display( 784, 640 );
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
    ALLEGRO_EVENT_QUEUE * event_queue2 = NULL;
    al_set_window_title( okno, "Szachy" );

    event_queue = al_create_event_queue();
    event_queue2 = al_create_event_queue();

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
        }
          break; }
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
