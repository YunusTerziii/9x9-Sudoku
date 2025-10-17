#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int sudoku_coz(char tablo[N][N])
{
    int satir,sutun;
    int boshucre_bulundu = 0;

    //bos hücre arıyoruz
    for(satir =0;satir<N;satir++)
    {
        for(sutun =0;sutun<N;sutun++)
        {
            if(tablo[satir][sutun]=='-')
            {
            boshucre_bulundu = 1;
            break;
            }
        }
        if(boshucre_bulundu)
            break;
    }
    if(!boshucre_bulundu)
    {
        return 1;
    }

    int sayilar[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for(int i=0;i<N;i++)
    {
        int j=rand()%N;
        int temp=sayilar[i];
        temp = sayilar[i];
        sayilar[i] = sayilar[j];
        sayilar[j] = temp;
    }

    for(int i=0;i<N;i++)
    {
        int sayiDenemesi = sayilar[i];
        char karakterSayi = sayiDenemesi + '0';

        if(kontrol_et(tablo,satir,sutun,karakterSayi))
        {
            tablo[satir][sutun] = karakterSayi;
            if(sudoku_coz(tablo))
            {
                return 1;
            }
            tablo[satir][sutun]='-';
        }
    }
    return 0;
    
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
