#include "Allegro.h"
#include "Menu.h"

extern int czy_niebiesko;
extern int czy_bicia;
extern int teraz_czarne;
extern int szach;
extern int activate_szachuje;
extern int szachuje;
extern int k,i,j;
extern bool czy_istnieje_ruch;
extern bool sprawdzanie_szach_mata;
extern int xx,yy,XX,YY;
extern int type;
extern int type_bitego;
extern int roznica;

void display_piony(int szachownica[8][8][3],int podswietlenie[8][8], ALLEGRO_BITMAP *plansza, ALLEGRO_BITMAP *krol_b, ALLEGRO_BITMAP *krol_c, ALLEGRO_BITMAP *krolowka_b, ALLEGRO_BITMAP *krolowka_c,
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
                      if( ((i%2)==0 & (j%2)==0) | ((i%2)!=0 & (j%2)!=0)) al_draw_bitmap (blue_b,szachownica[i][j][1]-8,szachownica[i][j][2]-8,0);
                      else al_draw_bitmap (blue,szachownica[i][j][1]-8,szachownica[i][j][2]-8,0);
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
                  al_draw_bitmap (wieza_b,szachownica[i][j][1],szachownica[i][j][2],NULL);
                  break;
            case  -1:
                  al_draw_bitmap (wieza_c,szachownica[i][j][1],szachownica[i][j][2],NULL);
                  break;
            case  2:
                  al_draw_bitmap (kon_b,szachownica[i][j][1],szachownica[i][j][2],NULL);
                  break;
            case  -2:
                  al_draw_bitmap (kon_c,szachownica[i][j][1],szachownica[i][j][2],NULL);
                  break;
            case  3:
                  al_draw_bitmap (hetman_b,szachownica[i][j][1],szachownica[i][j][2],NULL);
                  break;
            case -3:
                  al_draw_bitmap (hetman_c,szachownica[i][j][1],szachownica[i][j][2],NULL);
                  break;
            case  4:
                  al_draw_bitmap (krolowka_b,szachownica[i][j][1],szachownica[i][j][2],NULL);
                  break;
            case  -4:
                  al_draw_bitmap (krolowka_c,szachownica[i][j][1],szachownica[i][j][2],NULL);
                  break;
            case  5:
                  al_draw_bitmap (krol_b,szachownica[i][j][1],szachownica[i][j][2],NULL);
                  break;
            case  -5:
                  al_draw_bitmap (krol_c,szachownica[i][j][1],szachownica[i][j][2],NULL);
                  break;
            case  6:
                  al_draw_bitmap (pion_b,szachownica[i][j][1],szachownica[i][j][2],NULL);
                  break;
            case  -6:
                  al_draw_bitmap (pion_c,szachownica[i][j][1],szachownica[i][j][2],NULL);
                  break;
           }
           } else
           {
               switch(typ)
           {
            case 1:
                  al_draw_bitmap (wieza_c,szachownica[i][j][1],szachownica[i][j][2],NULL);
                  break;
            case  -1:
                  al_draw_bitmap (wieza_b,szachownica[i][j][1],szachownica[i][j][2],NULL);
                  break;
            case  2:
                  al_draw_bitmap (kon_c,szachownica[i][j][1],szachownica[i][j][2],NULL);
                  break;
            case  -2:
                  al_draw_bitmap (kon_b,szachownica[i][j][1],szachownica[i][j][2],NULL);
                  break;
            case  3:
                  al_draw_bitmap (hetman_c,szachownica[i][j][1],szachownica[i][j][2],NULL);
                  break;
            case -3:
                  al_draw_bitmap (hetman_b,szachownica[i][j][1],szachownica[i][j][2],NULL);
                  break;
            case  4:
                  al_draw_bitmap (krolowka_c,szachownica[i][j][1],szachownica[i][j][2],NULL);
                  break;
            case  -4:
                  al_draw_bitmap (krolowka_b,szachownica[i][j][1],szachownica[i][j][2],NULL);
                  break;
            case  5:
                  al_draw_bitmap (krol_c,szachownica[i][j][1],szachownica[i][j][2],NULL);
                  break;
            case  -5:
                  al_draw_bitmap (krol_b,szachownica[i][j][1],szachownica[i][j][2],NULL);
                  break;
            case  6:
                  al_draw_bitmap (pion_c,szachownica[i][j][1],szachownica[i][j][2],NULL);
                  break;
            case  -6:
                  al_draw_bitmap (pion_b,szachownica[i][j][1],szachownica[i][j][2],NULL);
                  break;
           }
           }
        }
    }
    if(teraz_czarne==1) al_draw_bitmap(ruch_c,650,120,NULL); else al_draw_bitmap(ruch_b,650,120,NULL);
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

