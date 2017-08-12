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

int cik(FILE** dosya, int* secim){
	char dosya_ad[50];
	int pyn, yn;

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

		printf("Peki kaynak dosyayı değiştirmek ister misiniz? (Y/n): ");
                getchar();
		pyn = getchar();

		if(pyn != 'n' && pyn != 'N'){
			*dosya = in_file();
		}
		
		return 1;
	}
}

int main(){
	setlocale(LC_ALL, "Turkish");

	int secim, kontrol = 1, problem = 0;

	FILE* dosya;

	printf("Lütfen alıştırma tipini seçip giriniz\n(1: gecikme, 2: tamamlama, 3: abcde): ");
        scanf(" %d", &secim);
	
	dosya = in_file();

	while(kontrol){
		kontrol = 0;
		if(problem){
			printf("Lütfen alıştırma tipini seçip giriniz\n(1: gecikme, 2: tamamlama, 3: abcde): ");
			scanf(" %d", &secim);
			dosya = in_file();
			problem = 0;
		}
		switch(secim){
			case 1:
				gecikme(dosya);
				kontrol = cik(&dosya, &secim);
				break;
			case 2:
				tamamlama(dosya);
				kontrol = cik(&dosya, &secim);
				break;
			case 3:
				abcde(dosya);
				kontrol = cik(&dosya, &secim);
				break;
			default:
				printf("Büyük olasılıkla yanlış seçim yapılmış.\n Yeniden seçim yapmaya yönlendiriliyorsunuz:\n\n");
				kontrol = 1;
				problem = 1;
				break;
	     	}
	}
	fclose(dosya);
	printf("Başarılar...\n");
	return 0;
}
