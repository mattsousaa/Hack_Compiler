#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define A_equal_zero 	    0xEAA0;
#define A_equal_1    		0xEFE0;
#define A_equal_menos_um    0xEEA0;
#define A_equal_D           0xE320;
#define A_equal_A           0xEC20;
#define A_equal_neg_D       0xE360;
#define A_equal_neg_A       0xEC60;
#define A_equal_menos_D     	0xE3E0;
#define A_equal_menos_A     	0xECE0;
#define A_equal_D_mais_um   	0xE7E0;
#define A_equal_A_mais_um   	0xEDE0;
#define A_equal_D_menos_um  	0xE3A0;
#define A_equal_A_menos_um  	0xECA0;
#define A_equal_D_mais_A    	0xE0A0;
#define A_equal_D_menos_A  	 0xE4E0;
#define A_equal_A_menos_D 	 0xE1E0;
#define A_equal_D_and_A   	 0xE020;
#define A_equal_D_or_A   	 0xE560;
#define A_equal_M   	      0xFC20;
#define A_equal_neg_M 	      0xFC60;
#define A_equal_menos_M       0xFCE0;
#define A_equal_M_mais_um 	  0xFDE0;
#define A_equal_M_menos_um	  0xFCA0;
#define A_equal_D_mais_M 	  0xF0A0;
#define A_equal_D_menos_M 	  0xF4E0;
#define A_equal_M_menos_D 	  0xF1E0;
#define A_equal_D_and_M 	  0xF020;
#define A_equal_D_or_M 		  0xF560;

//#################################################################
#define D_equal_zero 		  0xEA90;
#define D_equal_1    		  0xEFD0;
#define D_equal_menos_um  	  0xEE90;
#define D_equal_D         	  0xE310;
#define D_equal_A         	  0xEC10;
#define D_equal_neg_D     	  0xE350;
#define D_equal_neg_A     	  0xEC50;
#define D_equal_menos_D   	  0xE3D0;
#define D_equal_menos_A   	  0xECD0;
#define D_equal_D_mais_um     0xE7D0;
#define D_equal_A_mais_um     0xEDD0;
#define D_equal_D_menos_um    0xE390;
#define D_equal_A_menos_um 	  0xEC90;
#define D_equal_D_mais_A   	  0xE090;
#define D_equal_D_menos_A  	  0xE4D0;
#define D_equal_A_menos_D  	  0xE1D0;
#define D_equal_D_and_A  	  0xE010;
#define D_equal_D_or_A  	  0xE550;
#define D_equal_M  		      0xFC10;
#define D_equal_neg_M 		  0xFC50;
#define D_equal_menos_M 	  0xFCD0;
#define D_equal_M_mais_um 	  0xFDD0;
#define D_equal_M_menos_um	  0xFC90;
#define D_equal_D_mais_M 	  0xF090;
#define D_equal_D_menos_M 	  0xF4D0;
#define D_equal_M_menos_D 	  0xF1D0;
#define D_equal_D_and_M 	  0xF010;
#define D_equal_D_or_M 		  0xF550;
//#################################################################
#define M_equal_zero 	   0xEA88;
#define M_equal_1    	   0xEFC8;
#define M_equal_menos_um   0xEE88;
#define M_equal_D          0xE308;
#define M_equal_A          0xEC08;
#define M_equal_neg_D      0xE348;
#define M_equal_neg_A      0xEC48;
#define M_equal_menos_D    0xE3C8;
#define M_equal_menos_A    0xECC8;
#define M_equal_D_mais_um  0xE7C8;
#define M_equal_A_mais_um  0xEDC8;
#define M_equal_D_menos_um   0xE388;
#define M_equal_A_menos_um   0xEC88;
#define M_equal_D_mais_A     0xE088;
#define M_equal_D_menos_A    0xE4C8;
#define M_equal_A_menos_D    0xE1C8;
#define M_equal_D_and_A      0xE008;
#define M_equal_D_or_A       0xE548;
#define M_equal_M  		     0xFC08;
#define M_equal_neg_M 	     0xFC48;
#define M_equal_menos_M      0xFCC8;
#define M_equal_M_mais_um    0xFDC8;
#define M_equal_M_menos_um   0xFC88;
#define M_equal_D_mais_M     0xF088;
#define M_equal_D_menos_M    0xF4C8;
#define M_equal_M_menos_D    0xF1C8;
#define M_equal_D_and_M      0xF008;
#define M_equal_D_or_M       0xF548;

//#################################################################

void to_binario(char binario[],int num){
	int mask = 0x8000;
	if(mask &  num){
		strcpy(binario,"1");
		}
		else{
		 strcpy(binario,"0");
		}
		mask = mask >> 1;
	while(mask !=0 ){
		if(mask &  num){
		strcat(binario,"1");
		}
		else{
		 strcat(binario,"0");
		}
		mask = mask >> 1;
	}
}

//#################################################################
// 				FUNCAO QUE RECEBE VALOR DE VARIÁVEIS


void cmp_variable(FILE *r , FILE *w ,int i, char atual, int *cont_var){
	FILE *var_read =  fopen("variable_map.txt", "r");
	FILE *var_write = fopen("variable_map.txt", "a");
	 	char binario [16];  // binario a salvar
	 	char LINHA[150];    // linha lida do arquivo de variaveis
	 	char variavel [150];  // variavel da linha do arquivo fonte 
	 	char* campo;        //
	 	int num = 0;  
	 	int controle = 0;  
	 	char igual = '=';
	 	int pos = 0;  // diz a posicao do proximo char 
	 	
	 	variavel[0]=atual;  // primeiro valor apos o @
	 	while(atual != '\n'){
	 		    pos += 1;
	 			atual = fgetc(r);
	 			if( atual != '\n')
	 				variavel[pos] = atual;
	 	}
	 	// indicar o fim da string
	 	variavel[pos] = '\0'; 
	 	//printf("%s\n",variavel );
	 	while( fgets(LINHA,sizeof(LINHA),var_read) != NULL) {
	 		campo = (char*)strtok(LINHA, "=");
	 		if(strcmp(variavel,campo) == strcmp(&atual,&atual)){
	 			campo = (char*)strtok(NULL, "=");
	 			printf("%s",campo);
	 			num = atoi(campo);
	 			to_binario(binario,num);
	 			fprintf(w, "%s\n", binario);
	 			fclose(var_read);
	 			fclose(var_write);
	 			controle = 1;
	 			return;
	 			
	 		}
	 	}
	 		if(controle ==0){
				fprintf(var_write, "%s", variavel);
				fprintf(var_write, "%c",'=');
				sprintf(binario,"%d",*cont_var);
				fprintf(var_write, "%s",binario);
				fprintf(var_write,  "%c", '=');
				fprintf(var_write, "%c",'\n');
				// fprintf(e, "%d",*valor_linha );
				 to_binario(binario,*cont_var);
				 fprintf(w, "%s\n", 		binario);
				 *cont_var += 1;
			}
			fclose(var_read);
	 		fclose(var_write);
	 		return;
}
//#################################################################
int confere_num(char num){

	if((num == '0') | (num == '1') |(num == '2') |(num == '3') |(num == '4') |(num== '5') |(num == '6') |(num == '7') |(num == '8') |(num == '9')) {
		return 1;
	}else {
		return 0 ;
	}
}
int lerNumero(FILE *r,FILE *w ,int i,char num){
		char binario[16];
	 	char atual;
	 	int potencia = 0;
	 	int instrucao = 0;
	 	int controle = 0;
	 	int numero;
	 	int res = 1; // res recebe resultado caso der erro em @
	     
	 	atual = num;
	 	while((atual != '\n') && (controle == 0)){
	 		    if     ( atual == '1') {instrucao = instrucao*10 + 1;}
	 		    else if( atual == '2') {instrucao = instrucao*10 + 2;}
	 		    else if( atual == '3') {instrucao = instrucao*10 + 3;}
	 		    else if( atual == '4') {instrucao = instrucao*10 + 4;}
	 		    else if( atual == '5') {instrucao = instrucao*10 + 5;}
	 		    else if( atual == '6') {instrucao = instrucao*10 + 6;}
	 		    else if( atual == '7') {instrucao = instrucao*10 + 7;}
	 		    else if( atual == '8') {instrucao = instrucao*10 + 8;}
	 		    else if( atual == '9') {instrucao = instrucao*0  + 9;}
	 		    else if( atual == '0') {instrucao = instrucao*10 + 0;
	 		    }else {
	 		    	printf("erro na linha : %d \n", i);
	 		    	return 0;
	 		    }
	 		    atual = fgetc(r);
	 		    if(atual == '\n') {
	 		    	controle = 1;
	 		    }
	 		    potencia++;
	 	}
	 	if(instrucao > 0x7fff ){
	 		printf("Dumped value max line %d\n",i);
	 		exit(0);
	 	}
	 	to_binario(binario,instrucao);
		fprintf(w,"%s\n",binario);
		return 1;
}

void erro(int i){
 printf("Erro na linha %d\n",i);
 exit(0);
}


int main(){
	int cont_var = 16;
	char binario[16];   // armazena string binaria no arquivo
	int i = 0 ;  // diz   a linha de execucao
	char atual;  // ultimo caractere lido do arquivo
	int instrucao = 0; // instrucao binaria
	int res = 1; // res recebe 0 caso der erro no @
	FILE *r,*w;
	r = fopen("instrucoes.txt","r");
	w = fopen("instrucoes.hack", "w");
	int t = 0; 

	while(((atual = fgetc(r)) != EOF) && (t == 0)){
		i++;
		switch(atual){
			case  'A':
				if(((atual = fgetc(r)) == EOF) || atual == '\n'){
					erro(i);
				}else if(atual == '='){
					if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
						erro(i);
						t =1;
					}else if (atual == '0'){
						atual = fgetc(r);
						if(atual == '\n'){
							instrucao = A_equal_zero;
							to_binario(binario,instrucao);
							fprintf(w, "%s",binario);
							fprintf(w, "%c",atual);
						}else{
							erro(i);
						}
					}else if (atual == '1'){
						atual = fgetc(r);
						if(atual == '\n'){
							instrucao = A_equal_1;
							to_binario(binario,instrucao);
							fprintf(w, "%s",binario);
							fprintf(w, "%c",atual);
						}else{
							erro(i);
						}
					}else if (atual == 'A'){
						atual = fgetc(r);
						if(atual == '\n'){
							instrucao = A_equal_A;
							to_binario(binario,instrucao);
							fprintf(w, "%s",binario);
							fprintf(w, "%c",atual);
						}else if(atual == '+'){
							if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
								erro(i);
								t =1;
							}else if(atual == '1'){
								atual = fgetc(r);
								if(atual == '\n'){
									instrucao = A_equal_A_mais_um;
									to_binario(binario,instrucao);
									fprintf(w, "%s",binario);
									fprintf(w, "%c",atual);
								}else{
									erro(i);
								}
							}else if(atual == 'D'){
								atual = fgetc(r);
								if(atual == '\n'){
									instrucao = A_equal_D_mais_A;
									to_binario(binario,instrucao);
									fprintf(w, "%s",binario);
									fprintf(w, "%c",atual);
								}else{
									erro(i);
								}
							}
						}else if(atual == '-'){
							if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
								erro(i);
								t =1;
							}else if(atual == '1'){
								atual = fgetc(r);
								if(atual == '\n'){
									instrucao = A_equal_A_menos_um;
									to_binario(binario,instrucao);
									fprintf(w, "%s",binario);
									fprintf(w, "%c",atual);
								}else{
									erro(i);
								}
							}else if(atual == 'D'){
								atual = fgetc(r);
								if(atual == '\n'){
									instrucao = A_equal_A_menos_D;
									to_binario(binario,instrucao);
									fprintf(w, "%s",binario);
									fprintf(w, "%c",atual);
								}else{
									erro(i);
								}
							}
						}else if(atual == '|'){
							if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
								erro(i);
								t =1;
							}else if(atual == 'D'){
								atual = fgetc(r);
								if(atual == '\n'){
									instrucao = A_equal_D_or_A;
									to_binario(binario,instrucao);
									fprintf(w, "%s",binario);
									fprintf(w, "%c",atual);
								}else{
									erro(i);
								}
							}
						}else if(atual == '&'){
							if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
								erro(i);
								t =1;
							}else if(atual == 'D'){
								atual = fgetc(r);
								if(atual == '\n'){
									instrucao = A_equal_D_and_A;
									to_binario(binario,instrucao);
									fprintf(w, "%s",binario);
									fprintf(w, "%c",atual);
								}else{
									erro(i);
								}
							}
						}else {
							erro(i);
						}
					}else if (atual == 'D'){
						atual = fgetc(r);
						if(atual == '\n'){
							instrucao = A_equal_D;
							to_binario(binario,instrucao);
							fprintf(w, "%s",binario);
							fprintf(w, "%c",atual);
						}else if(atual == '+'){
							if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
								erro(i);
								t =1;
							}else if(atual == '1'){
								atual = fgetc(r);
								if(atual == '\n'){
									instrucao = A_equal_D_mais_um;
									to_binario(binario,instrucao);
									fprintf(w, "%s",binario);
									fprintf(w, "%c",atual);
								}else{
									erro(i);
								}
							}else if(atual == 'A'){
								atual = fgetc(r);
								if(atual == '\n'){
									instrucao = A_equal_D_mais_A;
									to_binario(binario,instrucao);
									fprintf(w, "%s",binario);
									fprintf(w, "%c",atual);
								}else{
									erro(i);
								}
							}else if(atual == 'M'){
								atual = fgetc(r);
								if(atual == '\n'){
									instrucao = A_equal_D_mais_M;
									to_binario(binario,instrucao);
									fprintf(w, "%s",binario);
									fprintf(w, "%c",atual);
								}else{
									erro(i);
								}
							}
						}else if(atual == '-'){
							if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
								erro(i);
								t =1;
							}else if(atual == '1'){
								atual = fgetc(r);
								if(atual == '\n'){
									instrucao = A_equal_D_menos_um;
									to_binario(binario,instrucao);
									fprintf(w, "%s",binario);
									fprintf(w, "%c",atual);
								}else{
									erro(i);
								}
							}else if(atual == 'M'){
								atual = fgetc(r);
								if(atual == '\n'){
									instrucao = A_equal_D_menos_M;
									to_binario(binario,instrucao);
									fprintf(w, "%s",binario);
									fprintf(w, "%c",atual);
								}else{
									erro(i);
								}
							}else if(atual == 'A'){
								atual = fgetc(r);
								if(atual == '\n'){
									instrucao = A_equal_D_menos_A;
									to_binario(binario,instrucao);
									fprintf(w, "%s",binario);
									fprintf(w, "%c",atual);
								}else{
									erro(i);
								}
							}
						}else if(atual == '|'){
							if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
								erro(i);
								t =1;
							}else if(atual == 'A'){
								atual = fgetc(r);
								if(atual == '\n'){
									instrucao = A_equal_D_or_A;
									to_binario(binario,instrucao);
									fprintf(w, "%s",binario);
									fprintf(w, "%c",atual);
								}else{
									erro(i);
								}
							}else if(atual == 'M'){
								atual = fgetc(r);
								if(atual == '\n'){
									instrucao = A_equal_D_or_M;
									to_binario(binario,instrucao);
									fprintf(w, "%s",binario);
									fprintf(w, "%c",atual);
								}else{
									erro(i);
								}
							}
						}else if(atual == '&'){
							if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
								erro(i);
								t =1;
							}else if(atual == 'A'){
								atual = fgetc(r);
								if(atual == '\n'){
									instrucao = A_equal_D_and_A;
									to_binario(binario,instrucao);
									fprintf(w, "%s",binario);
									fprintf(w, "%c",atual);
								}else{
									erro(i);
								}
							}else if(atual == 'M'){
								atual = fgetc(r);
								if(atual == '\n'){
									instrucao = A_equal_D_and_M;
									to_binario(binario,instrucao);
									fprintf(w, "%s",binario);
									fprintf(w, "%c",atual);
								}else{
									erro(i);
								}
							}
						}else {
							erro(i);
						}
					}else if (atual == 'M'){
						atual = fgetc(r);
						if(atual == '\n'){
							instrucao = A_equal_M;
							to_binario(binario,instrucao);
							fprintf(w, "%s",binario);
							fprintf(w, "%c",atual);
						}else if(atual == '+'){
							if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
								erro(i);
								t =1;
							}else if(atual == '1'){
								atual = fgetc(r);
								if(atual == '\n'){
									instrucao = A_equal_M_mais_um;
									to_binario(binario,instrucao);
									fprintf(w, "%s",binario);
									fprintf(w, "%c",atual);
								}else{
									erro(i);
								}
							}else if(atual == 'D'){
								atual = fgetc(r);
								if(atual == '\n'){
									instrucao = A_equal_D_mais_M;
									to_binario(binario,instrucao);
									fprintf(w, "%s",binario);
									fprintf(w, "%c",atual);
								}else{
									erro(i);
								}
							}
						}else if(atual == '-'){
							if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
								erro(i);
								t =1;
							}else if(atual == '1'){
								atual = fgetc(r);
								if(atual == '\n'){
									instrucao = A_equal_M_menos_um;
									to_binario(binario,instrucao);
									fprintf(w, "%s",binario);
									fprintf(w, "%c",atual);
								}else{
									erro(i);
								}
							}else if(atual == 'D'){
								atual = fgetc(r);
								if(atual == '\n'){
									instrucao = A_equal_M_menos_D;
									to_binario(binario,instrucao);
									fprintf(w, "%s",binario);
									fprintf(w, "%c",atual);
								}else{
									erro(i);
								}
							}
						}else if(atual == '|'){
							if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
								erro(i);
								t =1;
							}else if(atual == 'D'){
								atual = fgetc(r);
								if(atual == '\n'){
									instrucao = A_equal_D_or_M;
									to_binario(binario,instrucao);
									fprintf(w, "%s",binario);
									fprintf(w, "%c",atual);
								}else{
									erro(i);
								}
							}
						}else if(atual == '&'){
							if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
								erro(i);
								t =1;
							}else if(atual == 'D'){
								atual = fgetc(r);
								if(atual == '\n'){
									instrucao = A_equal_D_and_M;
									to_binario(binario,instrucao);
									fprintf(w, "%s",binario);
									fprintf(w, "%c",atual);
								}else{
									erro(i);
								}
							}
						}else {
							erro(i);
						}
					}else if (atual == '-'){
							if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
								erro(i);
								t =1;
							}else if(atual == '1'){
								atual = fgetc(r);
								if(atual == '\n'){
									instrucao = A_equal_menos_um;
									to_binario(binario,instrucao);
									fprintf(w, "%s",binario);
									fprintf(w, "%c",atual);
								}else{
									erro(i);
								}
							}else if(atual == 'D'){
								atual = fgetc(r);
								if(atual == '\n'){
									instrucao = A_equal_menos_D;
									to_binario(binario,instrucao);
									fprintf(w, "%s",binario);
									fprintf(w, "%c",atual);
								}else{
									erro(i);
								}
							}else if(atual == 'M'){
								atual = fgetc(r);
								if(atual == '\n'){
									instrucao = A_equal_menos_M;
									to_binario(binario,instrucao);
									fprintf(w, "%s",binario);
									fprintf(w, "%c",atual);
								}else{
									erro(i);
								}
							}else if(atual == 'A'){
								atual = fgetc(r);
								if(atual == '\n'){
									instrucao = A_equal_menos_A;
									to_binario(binario,instrucao);
									fprintf(w, "%s",binario);
									fprintf(w, "%c",atual);
								}else{
									erro(i);
								}
							}
					}else if (atual == '!'){
							if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
								erro(i);
								t =1;
							}else if(atual == 'D'){
								atual = fgetc(r);
								if(atual == '\n'){
									instrucao = A_equal_neg_D;
									to_binario(binario,instrucao);
									fprintf(w, "%s",binario);
									fprintf(w, "%c",atual);
								}else{
									erro(i);
								}
							}else if(atual == 'M'){
								atual = fgetc(r);
								if(atual == '\n'){
									instrucao = A_equal_neg_M;
									to_binario(binario,instrucao);
									fprintf(w, "%s",binario);
									fprintf(w, "%c",atual);
								}else{
									erro(i);
								}
							}else if(atual == 'A'){
								atual = fgetc(r);
								if(atual == '\n'){
									instrucao = A_equal_neg_A;
									to_binario(binario,instrucao);
									fprintf(w, "%s",binario);
									fprintf(w, "%c",atual);
								}else{
									erro(i);
								}
							}
					}else{
						erro(i);
					}
				}else{
					erro(i);
				}
			break;
			case  'M':
				if(((atual = fgetc(r)) == EOF) || atual == '\n'){
						erro(i);
					}else if(atual == '='){
						if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
							erro(i);
							t =1;
						}else if (atual == '0'){
							atual = fgetc(r);
							if(atual == '\n'){
								instrucao = M_equal_zero;
								to_binario(binario,instrucao);
								fprintf(w, "%s",binario);
								fprintf(w, "%c",atual);
							}else{
								erro(i);
							}
						}else if (atual == '1'){
							atual = fgetc(r);
							if(atual == '\n'){
								instrucao = M_equal_1;
								to_binario(binario,instrucao);
								fprintf(w, "%s",binario);
								fprintf(w, "%c",atual);
							}else{
								erro(i);
							}
						}else if (atual == 'A'){
							atual = fgetc(r);
							if(atual == '\n'){
								instrucao = M_equal_A;
								to_binario(binario,instrucao);
								fprintf(w, "%s",binario);
								fprintf(w, "%c",atual);
							}else if(atual == '+'){
								if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
									erro(i);
									t =1;
								}else if(atual == '1'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = M_equal_A_mais_um;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}else if(atual == 'D'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = M_equal_D_mais_A;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}
							}else if(atual == '-'){
								if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
									erro(i);
									t =1;
								}else if(atual == '1'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = M_equal_A_menos_um;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}else if(atual == 'D'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = M_equal_A_menos_D;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}
							}else if(atual == '|'){
								if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
									erro(i);
									t =1;
								}else if(atual == 'D'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = M_equal_D_or_A;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}
							}else if(atual == '&'){
								if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
									erro(i);
									t =1;
								}else if(atual == 'D'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = M_equal_D_and_A;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}
							}else {
								erro(i);
							}
						}else if (atual == 'D'){
							atual = fgetc(r);
							if(atual == '\n'){
								instrucao = M_equal_D;
								to_binario(binario,instrucao);
								fprintf(w, "%s",binario);
								fprintf(w, "%c",atual);
							}else if(atual == '+'){
								if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
									erro(i);
									t =1;
								}else if(atual == '1'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = M_equal_D_mais_um;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}else if(atual == 'A'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = M_equal_D_mais_A;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}else if(atual == 'M'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = M_equal_D_mais_M;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}
							}else if(atual == '-'){
								if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
									erro(i);
									t =1;
								}else if(atual == '1'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = M_equal_D_menos_um;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}else if(atual == 'M'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = M_equal_D_menos_M;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}else if(atual == 'A'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = M_equal_D_menos_A;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}
							}else if(atual == '|'){
								if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
									erro(i);
									t =1;
								}else if(atual == 'A'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = M_equal_D_or_A;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}else if(atual == 'M'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = M_equal_D_or_M;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}
							}else if(atual == '&'){
								if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
									erro(i);
									t =1;
								}else if(atual == 'A'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = M_equal_D_and_A;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}else if(atual == 'M'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = M_equal_D_and_M;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}
							}else {
								erro(i);
							}
						}else if (atual == 'M'){
							atual = fgetc(r);
							if(atual == '\n'){
								instrucao = M_equal_M;
								to_binario(binario,instrucao);
								fprintf(w, "%s",binario);
								fprintf(w, "%c",atual);
							}else if(atual == '+'){
								if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
									erro(i);
									t =1;
								}else if(atual == '1'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = M_equal_M_mais_um;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}else if(atual == 'D'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = M_equal_D_mais_M;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}
							}else if(atual == '-'){
								if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
									erro(i);
									t =1;
								}else if(atual == '1'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = M_equal_M_menos_um;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}else if(atual == 'D'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = M_equal_M_menos_D;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}
							}else if(atual == '|'){
								if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
									erro(i);
									t =1;
								}else if(atual == 'D'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = M_equal_D_or_M;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}
							}else if(atual == '&'){
								if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
									erro(i);
									t =1;
								}else if(atual == 'D'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = M_equal_D_and_M;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}
							}else {
								erro(i);
							}
						}else if (atual == '-'){
								if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
									erro(i);
									t =1;
								}else if(atual == '1'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = M_equal_menos_um;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}else if(atual == 'D'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = M_equal_menos_D;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}else if(atual == 'M'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = M_equal_menos_M;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}else if(atual == 'A'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = M_equal_menos_A;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}
						}else if (atual == '!'){
								if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
									erro(i);
									t =1;
								}else if(atual == 'D'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = M_equal_neg_D;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}else if(atual == 'M'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = M_equal_neg_M;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}else if(atual == 'A'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = M_equal_neg_A;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}
						}else{
							erro(i);
						}
					}else{
						erro(i);
					}
			break;
			case  'D':
				if(((atual = fgetc(r)) == EOF) || atual == '\n'){
						erro(i);
					}else if(atual == '='){
						if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
							erro(i);
							t =1;
						}else if (atual == '0'){
							atual = fgetc(r);
							if(atual == '\n'){
								instrucao = D_equal_zero;
								to_binario(binario,instrucao);
								fprintf(w, "%s",binario);
								fprintf(w, "%c",atual);
							}else{
								erro(i);
							}
						}else if (atual == '1'){
							atual = fgetc(r);
							if(atual == '\n'){
								instrucao = D_equal_1;
								to_binario(binario,instrucao);
								fprintf(w, "%s",binario);
								fprintf(w, "%c",atual);
							}else{
								erro(i);
							}
						}else if (atual == 'A'){
							atual = fgetc(r);
							if(atual == '\n'){
								instrucao = D_equal_A;
								to_binario(binario,instrucao);
								fprintf(w, "%s",binario);
								fprintf(w, "%c",atual);
							}else if(atual == '+'){
								if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
									erro(i);
									t =1;
								}else if(atual == '1'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = D_equal_A_mais_um;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}else if(atual == 'D'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = D_equal_D_mais_A;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}
							}else if(atual == '-'){
								if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
									erro(i);
									t =1;
								}else if(atual == '1'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = D_equal_A_menos_um;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}else if(atual == 'D'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = D_equal_A_menos_D;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}
							}else if(atual == '|'){
								if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
									erro(i);
									t =1;
								}else if(atual == 'D'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = D_equal_D_or_A;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}
							}else if(atual == '&'){
								if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
									erro(i);
									t =1;
								}else if(atual == 'D'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = D_equal_D_and_A;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}
							}else {
								erro(i);
							}
						}else if (atual == 'D'){
							atual = fgetc(r);
							if(atual == '\n'){
								instrucao = D_equal_D;
								to_binario(binario,instrucao);
								fprintf(w, "%s",binario);
								fprintf(w, "%c",atual);
							}else if(atual == '+'){
								if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
									erro(i);
									t =1;
								}else if(atual == '1'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = D_equal_D_mais_um;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}else if(atual == 'A'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = D_equal_D_mais_A;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}else if(atual == 'M'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = D_equal_D_mais_M;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}
							}else if(atual == '-'){
								if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
									erro(i);
									t =1;
								}else if(atual == '1'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = D_equal_D_menos_um;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}else if(atual == 'M'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = D_equal_D_menos_M;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}else if(atual == 'A'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = D_equal_D_menos_A;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}
							}else if(atual == '|'){
								if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
									erro(i);
									t =1;
								}else if(atual == 'A'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = D_equal_D_or_A;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}else if(atual == 'M'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = D_equal_D_or_M;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}
							}else if(atual == '&'){
								if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
									erro(i);
									t =1;
								}else if(atual == 'A'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = D_equal_D_and_A;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}else if(atual == 'M'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = D_equal_D_and_M;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}
							}else {
								erro(i);
							}
						}else if (atual == 'M'){
							atual = fgetc(r);
							if(atual == '\n'){
								instrucao = D_equal_M;
								to_binario(binario,instrucao);
								fprintf(w, "%s",binario);
								fprintf(w, "%c",atual);
							}else if(atual == '+'){
								if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
									erro(i);
									t =1;
								}else if(atual == '1'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = D_equal_M_mais_um;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}else if(atual == 'D'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = D_equal_D_mais_M;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}
							}else if(atual == '-'){
								if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
									erro(i);
									t =1;
								}else if(atual == '1'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = D_equal_M_menos_um;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}else if(atual == 'D'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = D_equal_M_menos_D;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}
							}else if(atual == '|'){
								if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
									erro(i);
									t =1;
								}else if(atual == 'D'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = D_equal_D_or_M;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}
							}else if(atual == '&'){
								if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
									erro(i);
									t =1;
								}else if(atual == 'D'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = D_equal_D_and_M;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}
							}else {
								erro(i);
							}
						}else if (atual == '-'){
								if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
									erro(i);
									t =1;
								}else if(atual == '1'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = D_equal_menos_um;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}else if(atual == 'D'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = D_equal_menos_D;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}else if(atual == 'M'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = D_equal_menos_M;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}else if(atual == 'A'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = D_equal_menos_A;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}
						}else if (atual == '!'){
								if(((atual = fgetc(r)) == EOF)|| atual == '\n'){
									erro(i);
									t =1;
								}else if(atual == 'D'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = D_equal_neg_D;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}else if(atual == 'M'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = D_equal_neg_M;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}else if(atual == 'A'){
									atual = fgetc(r);
									if(atual == '\n'){
										instrucao = D_equal_neg_A;
										to_binario(binario,instrucao);
										fprintf(w, "%s",binario);
										fprintf(w, "%c",atual);
									}else{
										erro(i);
									}
								}
						}else{
							erro(i);
						}
					}else{
						erro(i);
					}
			break;
			case  '@':
				if(((atual = fgetc(r)) == EOF) || atual == '\n'){
					erro(i);
				}else if ( confere_num(atual) == 1){
					res = lerNumero(r,w,i,atual);
					if(res == 0)
				 		exit(0); 
				}else{
					cmp_variable(r,w,i,atual,&cont_var);
				}             // if pra não printar proximo	
			break;
			default:
				erro(i);
			break;
		}
	}
	fclose(r);
	fclose(w);
}