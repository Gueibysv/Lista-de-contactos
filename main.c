#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lista.c"
#include<locale.h>


main(){
	lista_contactos*ld;
	lista_email*le;
	le=iniciar();
	int op,res;
	ld=criar();
	char s[100];
	char nome[50],empresa[50],endereco[50];
	int telefone;
	setlocale(LC_ALL,"Portuguese");
	
	printf("\n----------------CADASTRO DO CONTACTO-----------------\n");
	while(op!=5){
	
		menu();
		scanf("%i",&op);
		system("cls");
		switch(op){
			case 1:
		
				printf("\n Digite o nome: ");
				scanf("%s", &nome);
	
				printf("\n Digite o endereço: ");
				scanf("%s", &endereco);
	
				printf("\n Digite o nome da Empresa: ");
				scanf("%s", &empresa);
				
				printf("\n Digite o número de telefone: ");
				scanf("%i", &telefone);
			
				ld=insere(ld,nome,endereco,empresa,telefone);
				system("cls");
			break;
			case 2:
				printf("-------------IMPRESSÃO DE CONTACTOS-------------\n");
				imprimir(ld);
				printf("\n");	
			break;
			case 3:
				printf("\n Digite o email para busca: ");
				scanf("%s", &s);
				buscar(ld,s);
				
			break;
			case 4:
				printf("\n Digite o nome: ");
				scanf("%s", &nome);		
				ld=remover(ld,nome);
			break;
			
			case 5:
			break;
			
			default:
				printf("\n OPÇÃO INVÁLIDA\n");
				
		}
	}

}

