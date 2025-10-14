#include <stdio.h>
#include <stdlib.h>

#define satir 9
#define sutun 9

void tabloyu_yazdir(char tablo[satir][sutun])
{
    for(int i=0;i<satir;i++){
    for(int j=0;j<sutun;j++)
    {
        printf("%c  ",tablo[i][j]);
    }
    printf("\n");
    }
}

void tabloyu_doldur(char tablo[satir][sutun])
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
    char tablo[satir][sutun];

    for(int i=0;i<satir;i++)
    {
        for(int j=0;j<sutun;j++)
        {
            tablo[i][j]='-';
        }
    }

    tabloyu_doldur(tablo);


    return 0;
}
