#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Email lista_email;
lista_email*iniciar();
lista_email*inserir(lista_email*l,char *s);
 void imprimir_email(lista_email*l);
 typedef struct Contactos lista_contactos;
 lista_contactos*criar();
 lista_contactos*insere(lista_contactos *l,char* nome,char* endereco,char *empresa,int telefone);
 void imprimir(lista_contactos*l);
 void buscar(lista_contactos *l,char *email);
 void menu();
 lista_contactos*remover(lista_contactos*l,char*nome);
