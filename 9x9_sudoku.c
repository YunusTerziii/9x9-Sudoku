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




int main() {
    char tablo[satir][sutun];

    for(int i=0;i<satir;i++)
    {
        for(int j=0;j<sutun;j++)
        {
            tablo[i][j]='-';
        }
    }

    tabloyu_yazdir(tablo);

    return 0;
}
