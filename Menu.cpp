#include "Menu.h"
#include "Allegro.h"

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

void ustaw_piony(int szachownica[8][8][3],int podswietlenie[8][8])
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
  //  szachownica[0][0][0]=-5;
  //  szachownica[7][1][0]=1;
  //   szachownica[5][4][0]=4;
   // szachownica[1][6][0]=6;
        for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            szachownica[i][j][1]=x;
            szachownica[i][j][2]=y;
            x=x+79;
            podswietlenie[i][j]=0;
        }
        x=12;
        y=y+79;
    }
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
    }


}

