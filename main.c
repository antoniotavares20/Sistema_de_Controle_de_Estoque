#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <time.h>
#include <locale.h>
#define TAMANHOINICIAL 100
#define TAM_LINHA_MSG 55
#define QTD_MAX_PROD 2
#include "estruturas.h"
#include "mensagens.h"
#include "prototiposFuncoes.h"
#include "pedido.h"
#include "cliente.h"
#include "produto.h"


/* função principal */
int main(){
setlocale(LC_ALL, "Portuguese");
  char opcao;
   do{
        /*funcao para imprimir menu principal */
        imprimirMenu(msgMenuPrincipal);
        scanf(" %c%*[^\n]",&opcao);
        /*funcao que converte para maiusculo */
        opcao=toupper(opcao);

    switch (opcao){
        case 'C':
        /*funcao para imprimir menu do Cliente */
            menuCliente();
            break;
        case 'P' :
        /* funçaõ para imprimir menu do Produto */
            menuProduto();
            break;
        case 'E':
        /* funçaõ para imprimir a geremcia de pedidos */
            menuPedido();
            break;
        case 'S':
            break;
       default:
     printf("Opcao Incorreta!\n");
      main();
    }
    }while(opcao != 'S');
}


/*esta função controla o numero de serie do codigo */
long int controledeSerie(int banco){
char linha;
int i = 0;
FILE *arquivo;

switch(banco){

    case bancoCliente:
        arquivo = abrirArquivo('a',"dBcliente.txt" );
        break;
    case bancoProduto:
        arquivo = abrirArquivo('a', "dBprodutos.txt");
        break;
    case bancoPedido:
        arquivo = abrirArquivo('a', "dBpedido.txt");
        break;
        }
            while( (linha =fgetc(arquivo))!= EOF){
			if(linha == '\n'){
                i++;
    }}
    fecharConexao(arquivo);
    return i;
return i;
};


/* esta função abre o arquvivo para operaçoes do CRUD*/
void abrirArquivo(char modo , char *caminho) {
    FILE *arquivo ;//ponteiro para manipular o arquivo
    switch(modo){
        case 'g': //modo de gravacao
          arquivo = fopen(caminho, "r+");
        break;
        case 'l': //modo de leitura
            arquivo = fopen(caminho,"r");
        break;
        case 'a'://modo de gravacao
            arquivo = fopen(caminho, "a+");
        break;
        }
        if(arquivo == NULL){ //caso dê erro, retorna ao menu inicial
            printf("foi possivel abrir o arquivo \n");
            main();
        };
};


/*esta função fecha a conexão com o arquivo */
void fecharConexao(FILE *arquivo){
 if(arquivo != NULL){
     fclose(arquivo);
    }else{
    if(fclose(arquivo) != 0){
    printf("Erro ao salvar!\n");
}}};



/*Esta função realiza a busca e validação por codigo)*/
int buscaPorCodigo(int banco){
long int qtd  = controledeSerie(banco);
long int codigo;
do{
printf("Informe o Codigo: \n 999 -> [Sair] \n");
scanf("%ld", &codigo);
if(codigo > qtd)
printf("Não cadastrado\n");
if (codigo < 0 )
printf("O Codigo deve ser maior que zero\n");
if(codigo >= 0 && codigo < qtd )
return codigo;
}while(codigo != 999);
main();
}




