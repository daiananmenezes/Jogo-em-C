#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 6

typedef struct{
	int id;
	int velMax;
	int hp;
}tipoCarta;

tipoCarta vetTrunfo[TAM];

void criaBaralho(){
	int i;
	for(i = 0; i < TAM; i++){
		vetTrunfo[i].id = i+1;
		vetTrunfo[i].velMax = rand() % 3 * 100 + rand() % 10 * 10;
		vetTrunfo[i].hp = rand() % 100 + 1;
	}
}

void mostraCarta(tipoCarta c){
	printf("Id: %i - Vel. M�xima: %ikm/h - HP: %ikW\n",c.id, c.velMax, c.hp);
}

void mostraBaralho(){
	int i;
	for(i = 0; i < TAM; i++){
		mostraCarta(vetTrunfo[i]);
	}
}

int recuperaValor(tipoCarta c, int op){
	int valor;
	switch(op){
		case 1: valor = c.velMax;
			    break;
		case 2: valor = c.hp;
		  	    break;
	}	
	return valor;
}

int menuCaracteristicas(){
	int op;
	printf("\n");
	do{
		printf("Escolha a caracter�stica:\n");
		printf("1. Velocidade m�xima\n");
		printf("2. HP\n");
		printf("Op��o: ");
		scanf("%i", &op);
	}while(op < 1 || op > 2);
	return op;
}

void mostraPlacar(int placar[][3]){
	int i, j;
	printf("## PLACAR FINAL ##\n\n");
	printf("USU  x  COMP - VENC\n");
	for(i = 0; i < TAM/2; i++){
		for(j = 0; j < 3; j++){
			printf("%i\t", placar[i][j] );
		}
		printf("\n");
	}
	printf("\n");
}

void main(){
	setlocale(LC_ALL, "");
	srand(time(NULL));
	tipoCarta cUsu, cComp;
	
	int placar[3][3];
	int op, k, venc, i;
	int vUsu, vComp, pUsu, pComp;
		
	k = 0;
	i = 0;
	pUsu = 0;
	pComp = 0;
	criaBaralho();
		
	do{
		cUsu = vetTrunfo[k];
		k++;
		cComp = vetTrunfo[k];
		k++;
		
		system("cls");
		printf("## SUPER TRUNFO ##\n\n");
		printf("Rodada %i\n\n", i);
		printf("Sua carta....: ");
		mostraCarta(cUsu);
		
		op = menuCaracteristicas();
				
		vUsu = recuperaValor(cUsu, op);
		vComp = recuperaValor(cComp, op);
		
		placar[i][0] = vUsu; 
		placar[i][1] = vComp;
	
		printf("\nAn�lise da Jogada\n");
		printf("Sua carta....: ");
		mostraCarta(cUsu);
		printf("Carta do comp: ");
		mostraCarta(cComp);
		printf("\nValor do usu�rio %i x %i Valor do computador\n\n", vUsu, vComp);
		
		if(vUsu > vComp){
			printf("Voc� venceu!\n");
			pUsu++;
			placar[i][2] = vUsu;			
		} else if(vUsu < vComp){
			printf("O computador venceu!\n");
			pComp++;
			placar[i][2] = vComp;
		} else {
			printf("Empate!\n");
			placar[i][2] = 0;
		}	
		i++;
		
		getch();	
	}while(k < TAM);
	
	system("cls");
	mostraPlacar(placar);
	
	if(pUsu > pComp){
		printf("Parab�ns! Voc� venceu o jogo!\n\n");
	} else if(pUsu < pComp){
		printf("O computador venceu o jogo!\n\n");
	} else {
		printf("O jogo terminou empatado!\n\n");
	}
	
}


