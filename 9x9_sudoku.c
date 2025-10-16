#include <stdio.h>
#include <stdlib.h>

#define N 9

void tabloyu_yazdir(char tablo[N][N])
{
    for(int i=0;i<N;i++){
    for(int j=0;j<N;j++)
    {
        printf("%c  ",tablo[i][j]);
    }
    printf("\n");
    }
}

int kontrol_et(char tablo[N][N],int satir,int sutun,int sayi)
{
    //satir kontrolü
    for(int x=0;x<N;x++)
    {
        if(tablo[satir][x]==sayi)
        return 0;
    }

    //sütün kontrolü
    for(int x=0;x<N;x++)
    {
        if(tablo[x][sutun]==sayi)
        return 0;
    }

    //grup kontrolü
    int grupSatiri = satir-satir % 3;
    int grupSutunu = sutun-sutun % 3;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(tablo[grupSatiri + i][grupSutunu + j] == sayi)
            return 0;
        }
    }
    return 1;
}


 

void tabloyu_doldur(char tablo[N][N])
{
    int n = 0;

    while(n<28)
    {
        int i = rand()%9;
        int j = rand()%9;

        if(tablo[i][j]=='-')
        {
            int x = rand()%9;
            tablo[i][j]='1'+x;
            n++;
        }
    }
    tabloyu_yazdir(tablo);
}




int main() {
    char tablo[N][N];

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            tablo[i][j]='-';
        }
    }

    tabloyu_doldur(tablo);


    return 0;
}
