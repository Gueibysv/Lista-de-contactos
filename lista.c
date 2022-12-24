#include"lista.h"

// cria��o da estrutura e lista de emails
struct Email{
	char *email;
	struct Email* prox;
};
// Inicializa��o da lista de emails
lista_email*iniciar(){
	return NULL;
}
// inser��o de elementos na lista de emails
lista_email*inserir(lista_email*l,char*gmail){
	lista_email*novo=(lista_email*)malloc(sizeof(lista_email));
		novo->email=(char*)malloc(strlen(gmail+1)); // malloc para reservar espa�o na lista
		strcpy(novo->email, gmail);
		novo->prox=l;
		return novo;
}
// impress�o de elementos da lista de emails
void imprimir_email(lista_email*l){
	lista_email*aux;
	for(aux=l;aux!=NULL;aux=aux->prox){
		printf("\n Email: %s",aux->email); // impress�o da lista de emails
	}
}
// PART2
// cria��o da estrutura e lista de contactos
struct Contactos{
	char nome[50];
	char empresa[50];
	char endereco[50];
	int telefone;
	lista_email* email;	// ponteiro que aposta para a lista de emails
	struct Contactos*prox,*ant;
};
// Inicializa��o da lista de contactos
lista_contactos*criar(){
	return NULL;
}
//inser��o de elementos na lista de contactos
lista_contactos*insere(lista_contactos *l,char* nome,char* endereco,char *empresa,int telefone){
	char s[50];
	int n;
	lista_contactos*novo=(lista_contactos*)malloc(sizeof(lista_contactos));
	if(novo!=NULL){
		strcpy(novo->nome,nome);
        strcpy(novo->empresa,empresa);
        strcpy(novo->endereco,endereco);
		novo->telefone=telefone;
		novo->email=NULL;
		printf("\n Digite o email: ");
        scanf("%s" , &s);
 		novo->email = inserir(novo->email,s );  // Aqui � feita a inser��o do email na lista de contactos
		printf("\n Adicionar email?\n");
		printf("[1]-SIM [2]-N�O\n");
		scanf("\n%i" , &n); 
		 while (n == 1)
        {
        	printf("\n Digite o email: ");
        	scanf("%s" , &s);
 			novo->email = inserir(novo->email,s ); // Aqui � feita a inser��o do email na lista de contactos 
			printf("\n Deseja adicionar mais algum email?\n");
			printf("[1]-SIM [2]-NAO\n");
			scanf("\n%i" , &n); 
        }
       		novo->prox=l;
       		novo->ant=NULL;
        if(l!=NULL){
			l->ant=novo;
	    }
	    return novo;
	}	
}
//impress�o da lista de elementos da lista de contactos
void imprimir(lista_contactos*l){
	lista_contactos*p;
	for(p=l; p!=NULL; p=p->prox){
				printf("\n______________________________");
				printf("\n Nome: %s",p->nome);
				printf("\n Telefone: %i",p->telefone);
				printf("\n Morada: %s",p->endereco);
				printf("\n Empresa: %s",p->empresa);
				imprimir_email(p->email); //Invoca��o da fun��o imprimir emails
				
			}
}
//FUN��O PARA BUSCA DO EMAIL
void buscar(lista_contactos*l,char *email){
     	lista_contactos* aux1=l,*aux3=NULL;
    	lista_email*aux2;
    	if(l==NULL)
    	printf("A lista est� vazia");
    	else{
    		while(aux1!=NULL){
    			aux2=aux1->email;
				while(aux2!=NULL){
				if(strcmp(aux2->email,email)==0){
				aux3=aux1; // aqui o auxiliar recebe o aux1 que � do tipo lista e guarda o endere�o 
					if(aux3!=NULL){
    			printf("\nContacto encontrado\n");
				printf("\nNome: %s\n",aux3->nome); 
			}
				}
				aux2=aux2->prox;					
				}
			 aux1=aux1->prox;
			}
		}
}
// remover um elemento da lista de contactos
lista_contactos*remover(lista_contactos*l,char*nome){
	lista_contactos*p=l;
	if(p==NULL){
	printf("A Lista est� VAZIA");
	return NULL;
	}else{
	
	int t=strcmp(p->nome,nome);
	while(p!=NULL && strcmp(p->nome,nome)!=0){
		p=p->prox;
	}
	if(p==NULL){ // elemento n�o encontrado
	printf("CONTACTO INEXISTENTE");
	return l; //retorna a lista
	} 
	if(p->ant==NULL) // provavelmente o 1� da lista
		l=p->prox;
	else
		p->ant->prox=p->prox; // provavelmente foi encontrado no meio da lista
	if(p->prox!=NULL){ // provavelmente � o ultimo elemento
	p->prox->ant=p->ant;
	}
}
	free(p->email);
	free(p);
	p=NULL;
	printf("CONTACTO REMOVIDO COM SUCESSO");
	return l; // retorna a lista
	
}
//procedimento do menu para apresenta��o
void menu(){
printf("\n-----------------------------------------------------\n");
printf("                                                    |\n");
printf("1-Inserir um contacto                               |\n");
printf("2-Imprimir lista de contactos                       |\n");
printf("3-Imprimir o nome do contacto atrav�s do e-mail     |\n");
printf("4-remover um contacto                               |\n");
printf("                                                    |\n");
printf("5-Sair do Programa                                  |\n");
printf("-----------------------------------------------------\n");
printf("\n");
}

