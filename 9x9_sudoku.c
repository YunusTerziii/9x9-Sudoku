#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 9

void menuyu_goster();
void devam_etmek_icin_bekle();
void tabloyu_yazdir(char tablo[N][N]);
int kontrol_et(char tablo[N][N], int satir, int sutun, int sayi);
int sudoku_coz(char tablo[N][N]);
int cozum_sayisini_bul(char tablo[N][N]);
void tablo_uret(char tablo[N][N]);


int main() {
    srand(time(NULL));
    int secim;

    while (1) {
        menuyu_goster();
        printf("Seciminiz: ");
        scanf("%d", &secim);
        
        while (getchar() != '\n'); 

        switch (secim) {
            case 1:
            { 
                printf("\n--- Ornek Sudoku Bulmacasi Cozuluyor ---\n\n");
                char bulmaca[N][N] = {
                    {'5', '3', '-', '-', '7', '-', '-', '-', '-'},
                    {'6', '-', '-', '1', '9', '5', '-', '-', '-'},
                    {'-', '9', '8', '-', '-', '-', '-', '6', '-'},
                    {'8', '-', '-', '-', '6', '-', '-', '-', '3'},
                    {'4', '-', '-', '8', '-', '3', '-', '-', '1'},
                    {'7', '-', '-', '-', '2', '-', '-', '-', '6'},
                    {'-', '6', '-', '-', '-', '-', '2', '8', '-'},
                    {'-', '-', '-', '4', '1', '9', '-', '-', '5'},
                    {'-', '-', '-', '-', '8', '-', '-', '7', '9'}
                };
                
                printf("Cozulecek Bulmaca:\n");
                tabloyu_yazdir(bulmaca);
                
                if (sudoku_coz(bulmaca)) {
                    printf("\nCozum Bulundu:\n");
                    tabloyu_yazdir(bulmaca);
                } else {
                    printf("\nBu bulmaca icin cozum bulunamadi.\n");
                }
                devam_etmek_icin_bekle();
                break;
            }
            case 2:
            {
                printf("\n--- Rastgele Dolu Sudoku Uretiliyor ---\n\n");
                char tablo[N][N];
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        tablo[i][j] = '-';
                    }
                }
                if (sudoku_coz(tablo)) {
                    tabloyu_yazdir(tablo);
                }
                devam_etmek_icin_bekle();
                break;
            }
            case 3:
            {
                printf("\n--- Tek Cozumlu Sudoku Bulmacasi Uretiliyor ---\n");
                printf("Bu islem birkac saniye surebilir...\n\n");
                char bulmaca[N][N] = {{'-'}}; 
                tablo_uret(bulmaca);
                tabloyu_yazdir(bulmaca);
                devam_etmek_icin_bekle();
                break;
            }
            case 4:
                printf("Programdan cikiliyor. Hoscakalin!\n");
                exit(0);
            default:
                printf("Gecersiz secim! Lutfen 1-4 arasi bir deger giriniz.\n");
                devam_etmek_icin_bekle();
                break;
        }
    }

    return 0;
}

void menuyu_goster() {
    printf("===================================\n");
    printf("         SUDOKU UYGULAMASI\n");
    printf("===================================\n");
    printf("1. Ornek Sudoku Coz\n");
    printf("2. Rastgele Dolu Sudoku Uret\n");
    printf("3. Tek Cozumlu Bulmaca Uret\n");
    printf("4. Cikis\n");
    printf("===================================\n");
}

void devam_etmek_icin_bekle() {
    printf("\nDevam etmek icin Enter tusuna basin...");
    getchar();
}

void tabloyu_yazdir(char tablo[N][N]) {
    printf("\n");
    for (int i = 0; i < N; i++) {
        if (i % 3 == 0 && i != 0) {
            printf("-------------------------\n");
        }
        for (int j = 0; j < N; j++) {
            if (j % 3 == 0 && j != 0) {
                printf("| ");
            }
            printf("%c  ", tablo[i][j]);
        }
        printf("\n");
    }
}

int kontrol_et(char tablo[N][N], int satir, int sutun, int sayi) {
    for (int x = 0; x < N; x++) {
        if (tablo[satir][x] == sayi) return 0;
        if (tablo[x][sutun] == sayi) return 0;
    }
    int grupSatiri = satir - satir % 3;
    int grupSutunu = sutun - sutun % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tablo[grupSatiri + i][grupSutunu + j] == sayi) return 0;
        }
    }
    return 1;
}

int sudoku_coz(char tablo[N][N]) {
    int satir, sutun;
    int boshucre_bulundu = 0;
    for (satir = 0; satir < N; satir++) {
        for (sutun = 0; sutun < N; sutun++) {
            if (tablo[satir][sutun] == '-') {
                boshucre_bulundu = 1;
                break;
            }
        }
        if (boshucre_bulundu) break;
    }
    if (!boshucre_bulundu) return 1;

    int sayilar[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < N; i++) {
        int j = rand() % N;
        int temp = sayilar[i];
        sayilar[i] = sayilar[j];
        sayilar[j] = temp;
    }

    for (int i = 0; i < N; i++) {
        char karakterSayi = sayilar[i] + '0';
        if (kontrol_et(tablo, satir, sutun, karakterSayi)) {
            tablo[satir][sutun] = karakterSayi;
            if (sudoku_coz(tablo)) return 1;
            tablo[satir][sutun] = '-';
        }
    }
    return 0;
}

int cozum_sayisini_bul(char tablo[N][N]) {
    int satir, sutun;
    int bos_hucre_bulundu = 0;
    for (satir = 0; satir < N; satir++) {
        for (sutun = 0; sutun < N; sutun++) {
            if (tablo[satir][sutun] == '-') {
                bos_hucre_bulundu = 1;
                break;
            }
        }
        if (bos_hucre_bulundu) break;
    }
    if (!bos_hucre_bulundu) return 1;

    int cozum_sayaci = 0;
    for (int sayi_denemesi = 1; sayi_denemesi <= 9; sayi_denemesi++) {
        char karakter_sayi = sayi_denemesi + '0';
        if (kontrol_et(tablo, satir, sutun, karakter_sayi)) {
            tablo[satir][sutun] = karakter_sayi;
            cozum_sayaci += cozum_sayisini_bul(tablo);
            tablo[satir][sutun] = '-';
        }
        if (cozum_sayaci > 1) return 2;
    }
    return cozum_sayaci;
}

void tablo_uret(char tablo[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tablo[i][j] = '-';
        }
    }
    sudoku_coz(tablo);

    int pozisyonlar[N * N];
    for (int i = 0; i < N * N; i++) {
        pozisyonlar[i] = i;
    }
    
    for (int i = 0; i < N * N; i++) {
        int j = rand() % (N * N);
        int temp = pozisyonlar[i];
        pozisyonlar[i] = pozisyonlar[j];
        pozisyonlar[j] = temp;
    }

    for (int i = 0; i < N * N; i++) {
        int satir = pozisyonlar[i] / N;
        int sutun = pozisyonlar[i] % N;
        
        char yedek = tablo[satir][sutun];
        tablo[satir][sutun] = '-';
        
        if (cozum_sayisini_bul(tablo) != 1) {
            tablo[satir][sutun] = yedek;
        }
    }
}