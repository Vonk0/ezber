#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "fonk_ezber.h"
#include <ctype.h>
#include <string.h>

FILE* in_file(){
	char dosya_ad[50];
        FILE* dosya;
	
		printf("Lütfen kaynak dosya adresini giriniz:\n");
	YAN:		
		getchar();
		scanf(" %s", dosya_ad);

		dosya = fopen(dosya_ad, "r");

	if(dosya == NULL){
		printf("Girilen adres geçerli değil. Lütfen,\ntekrar giriniz: ");
		
		goto YAN;
	}
}

int cik(int* secim){
	char dosya_ad[50];
	int pyn, yn = 'y';
	
	printf("Alıştırmadan çıktınız. Yeniden alıştırma seçmek ister misiniz? (Y/n): ");
	getchar();
	yn = getchar();

	if(yn == 'N' || yn == 'n'){
		return 0;
	}
	else{
		printf("Lütfen alıştırma tipini seçip giriniz\n(1: gecikme, 2: tamamlama, 3: abcde): ");
                if(scanf(" %d", secim) != 1){
			return 1;
		}
		
	return 1;
	}
}

void cik2(FILE **dosya, int durum){
	int pyn;
	if(!durum){
		*dosya = in_file();
	}
	else{
		printf("Peki kaynak dosyayı değiştirmek ister misiniz? (Y/n): ");
		getchar();
		pyn = getchar();
		if(pyn != 'n' && pyn != 'N'){
			*dosya = in_file();
		}
	}
}


int main(){
	setlocale(LC_ALL, "Turkish");

	int secim, kontrol = 1, problem = 1, durum = 0;

	FILE* dosya;

	while(kontrol){
		kontrol = 0;
		if(problem){
			printf("Lütfen alıştırma tipini seçip giriniz\n(1: gecikme, 2: tamamlama, 3: abcde): ");
			scanf(" %d", &secim);
			problem = 0;
		}
		switch(secim){
			case 1:
				cik2(&dosya, durum);
				gecikme(dosya);
				kontrol = cik(&secim);
				durum = 1;
				break;
			case 2:
				cik2(&dosya, durum);
				tamamlama(dosya);
				kontrol = cik(&secim);
				durum = 1;
				break;
			case 3:
				cik2(&dosya, durum);
				abcde(dosya);
				kontrol = cik(&secim);
				durum = 1;
				break;
			default:
				printf("\nBüyük olasılıkla yanlış seçim yapılmış.\nYeniden seçim yapmaya yönlendiriliyorsunuz:\n\n");
				kontrol = 1;
				problem = 1;
				durum = 0;
				break;
	     	}
	}
	fclose(dosya);
	printf("Başarılar...\n");
	return 0;
}
