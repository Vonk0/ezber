#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>

/*Random question chosing*/

int isvalueinarray(int val, int *arr, int size){
        int i, a;
        for (i=0; i < size; i++) {
                if (*(arr + i) == val){
                        a = 1;
                        break;
                }
                a = 0;
        }
        return a;
}

void delay(float gecikme){
         int i, d;
         for(;gecikme > 0; --gecikme){
                 for ( i = 1 ; i <= 32767 ; i++ ){
                         for ( d = 1 ; d <= 32767 ; d++ )
                                 {}
                 }
         }
}

void gecikme(FILE *fp){
	rewind(fp);

	int gec_sur, i;
	char soru_cevap[1000];
	printf("Lütfen istediğiniz gecikme süresini giriniz: ");
	scanf("%d", &gec_sur);
	char *sor;

	putchar('\n');
	while(fgets(soru_cevap, 1000, fp) != NULL){
		sor = soru_cevap;

		while(*sor != ':'){
			putchar(*sor);
			++sor;
		}
		printf(":");
		fflush(stdout);
		delay(gec_sur);
		++sor;

		while(*sor != '\t'){
			putchar(*sor);
			++sor;
		}
		putchar('\n');
		fflush(stdout);
		delay(1);
	}
	putchar('\n');
}

int tamamlama(FILE *fp){
	rewind(fp);

	int i = 0;
	char soru_cevap[1000], cevap[998], kul[998], *sor;

	putchar('\n');
	while(fgets(soru_cevap, 1000, fp) != NULL){
		sor = soru_cevap;
		while(*sor != ':'){
                	putchar(*sor);
			++sor;
		}
		printf(":");
		++sor;
		int space_kon = 1;

		while(*sor != '\t' && *sor != '\n'){
			if(isalpha(*sor) || (*sor ==  ' ' && space_kon == 0)){
                      		cevap[i] = (*sor);
                        	++sor;
				++i;
			}
			else{
				++sor;
				space_kon = 0;
			}
		}

		i = 0;

		putchar(' ');
		scanf(" %s", kul);

		if(strcmp(kul, cevap) == 0){
			printf("Doğru!\n");
			fflush(stdout);
			delay(1);
		}
		else{
			printf("Yanlış, doğrusu: %s\n", cevap);
			fflush(stdout);
			delay(1);
		}
		memset(cevap, 0, strlen(cevap));
	}
	return 0;
}


void abcde(FILE *fp){
	rewind(fp);

	char cevaplar[5][1000], soru_cevap[3000], *sor, abcde[] = {"ABCDE"};
	int kul, i = 0, j;

	putchar('\n');
	while(fgets(soru_cevap, 3000, fp) != NULL){
                sor = soru_cevap;
                while(*sor != ':'){
                        putchar(*sor);
                        ++sor;
                }
                printf(":\n");
                ++sor;

		int n, space_kon = 1;

		for(j = 0; j < 5; ++j){
			n = 0;

        		while(*sor != '\n' && *sor != '\t'){
                		if(isalpha(*sor) || isdigit(*sor)){
                                	cevaplar[j][n] = *sor;
                                	++n;
                        	}
				++sor;
			}
			for(;!isalpha(*sor) && !isdigit(*sor); ++sor){}
		}
		
		/*for(j = 0; j < 5; ++j){
			printf("%c. %s ",abcde[j], cevaplar[j]);
		}*/
		
		srand(time(NULL));
		
		int random, rangec[5] = {32, 32, 32, 32, 32}, anahtar;

		for(i = 0; i < 5; ++i){
                	while(isvalueinarray((random = (rand() % (4 + 1 - 0) + 0)), rangec, 5)){
				random = rand() % (4 + 1 - 0) + 0;
			}

                        rangec[i] = random;
		}
		
		for(i = 0; i < 5; ++i){
			//printf("%d ", rangec[i]);
			printf("%c. %s ", abcde[i], cevaplar[rangec[i]]);
		

			if(!strcmp(cevaplar[rangec[i]], cevaplar[0])){
				anahtar = abcde[i];
			}
		}

		getchar();
		kul = toupper(getchar());
			
		if(kul == anahtar){
			printf("Doğru!\n");
               		fflush(stdout);
                	delay(1);
        	}
        	else{
                	printf("Yanlış, doğrusu: %c. %s\n", anahtar, cevaplar[0]);
        		fflush(stdout);
                	delay(1);
		}
		
		for(i = 0; i < 5; ++i){
			memset(cevaplar[i], 0, 1000);
		}
		memset(rangec, 32, 5);
	}       
}



