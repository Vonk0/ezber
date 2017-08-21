#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int *slen_a;

int fseek_b(FILE **dosya){
	int lines, slen, curchar, i;
	
	for(curchar = fgetc(*dosya), lines = 0; curchar != EOF; curchar = fgetc(*dosya)){
		if(curchar == '\n'){
			++lines;
		}
	}
	
	rewind(*dosya);

	slen_a = (int*)calloc(lines, sizeof(int));

	for(slen = 0, curchar = fgetc(*dosya), i = 0; curchar != EOF; curchar = fgetc(*dosya), ++slen){
		if(curchar == '\n'){
			*(slen_a + i) = slen;
			slen = 0;
			++i;
		}
	}
	rewind(*dosya);
	return lines;
}

int fseek_e(FILE **dosya, int check, int curpos){
	rewind(*dosya);
	int eski = curpos;

	if(check == 0){
		puts("File is empty or there is a trouble with the file!");
		return 0;
	}
	else{
		int atla, i;

		for(atla = 0, i = 0; curpos > 0; --curpos, ++i){
			atla += *(slen_a + i);
		}
			
		if(eski < 1){
			rewind(*dosya);
		}	
		else{	
			fseek(*dosya, ++atla, SEEK_SET);
		}
		return 1;
	}
}

