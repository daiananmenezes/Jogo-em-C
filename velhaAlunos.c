#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

char velha[3][3];		
void mostraVelha(){
     int i, j;
     system("cls");						
	 printf("\n## JOGO DA VELHA ##\n\n");
     printf("    0   1   2\n");
     for(i = 0; i < 3; i++){
        printf("%d  ", i);					
        for(j = 0; j < 3; j++){
           printf(" %c ", velha[i][j]);
           if(j < 2){
              printf("|");
           }
        }
        if(i < 2){
           printf("\n   -----------\n");
        }

     }
     printf("\n");
}


void inicializaVelha(){
	int i, j;
    for(i = 0; i < 3; i++){				
        for(j = 0; j < 3; j++){			
           velha[i][j] = ' ';
        }
    }	
}

int lePosicao(char *msg){
	int n;
	do{
		printf("%s", msg);
		scanf("%i", &n);
	}while(n < 0 || n > 2);
	return n;
}

char leOpcao(){
	char op;
	do{
		printf("Deseja continuar (S/N)? ");
		fflush(stdin);
		scanf("%c", &op);
		op = toupper(op);
	}while(op != 'S' && op != 'N');
	return op;
}

char sorteiaPrimeiroJogador(){
	int n = rand() % 2;							
	if(n == 0){
		printf("O computador iniciar� o jogo\n\n");
		return 'O';	
	} else {
		printf("Voc� iniciar� o jogo\n\n");
		return 'X';
	}
}

int avaliaVencedor(char peca){
	int i, j, cont;
	
	for(i = 0; i < 3; i++){	
		cont = 0;
		for(j = 0; j < 3; j++){
			if(velha[i][j] == peca){
				cont++;
			}
		}
		if(cont == 3){
			return 1;
		}
	}
	
	for(j = 0; j < 3; j++){
		cont = 0;
		for(i = 0; i < 3; i++){
			if(velha[i][j] == peca){
				cont++;
			}
		}
		if(cont == 3){
			return 1;
		}
	}
	
	if(velha[0][0] == peca && velha[1][1] == peca && velha[2][2] == peca){
		return 1;
	}
	
	if(velha[2][0] == peca && velha[1][1] == peca && velha[0][2] == peca){
		return 1;
	}
	
	return 0;
}

void main(){
	srand(time(NULL));							
	setlocale(LC_ALL, "");
	
	int i, j, cont, venc;
	char peca, op;
	
	do{
		inicializaVelha();
		mostraVelha();
		
		peca = sorteiaPrimeiroJogador();
		cont = 0;
		
		do{
			do{
				if(peca == 'X'){
					printf("\nVoc� joga!\n");
					i = lePosicao("Informe a linha: ");
					j = lePosicao("Informe a coluna: ");
				} else {	
					i = rand() % 3;
					j = rand() % 3;
					printf("\nO computador joga: %i,%i\n", i, j);
					getch();
				}		
			}while(velha[i][j] != ' ');
			
			velha[i][j] = peca;
			cont++;	
			mostraVelha();
			
			venc = avaliaVencedor(peca);
			if(venc == 1){		
				break;
			}
			
			if(peca == 'X'){
				peca = 'O';
			} else {
				peca = 'X';
			}
		}while(cont < 9);
		
		if(venc == 1){
			if(peca == 'X'){
				printf("\n\nParab�ns! Voc� venceu!!\n");
			} else {
				printf("\n\nO computador venceu!!\n");
			}
		} else {
			printf("\n\nVelha! N�o h� vencedor!\n\n");
		}
	
		op = leOpcao();
	}while(op == 'S');
}







