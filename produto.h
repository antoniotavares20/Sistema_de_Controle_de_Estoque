void menuProduto(){
system("clear");
long int codigo = 0;
Produto *produto = malloc(sizeof(Produto));
char op = " ";
char categoria[30];

 do{
/* Mensagem para imprimir menu*/
imprimirMenu(msgMenuProduto);
//scanf(" %c%*[^\n]",&op);
scanf(" %c%*[^\n]",&op);
op = toupper(op);

switch (op){
                /*C – Cadastrar um Produto */
            case 'C' :
                codigo = controledeSerie(bancoProduto);
                cadastroProduto(produto+codigo, &codigo);
                gravarDadosProduto(produto+codigo);
                 /* segura a lista por 3 segundos*/
                     sleep(1);
            break;
             /*L – Listar todos os pruduto cadastrados.*/
            case 'L' :
            codigo = controledeSerie(bancoProduto);
            printf("Infome a categoria: \n");
            scanf(" %[^\n]s", &categoria);
            imprimirMenu(msgMenuTitulosProdutos);
            produto =  carregarDadosProdutos(produto, &codigo);
            produto = ordenarListaProduto(produto, &codigo);
            listarTodosProdutos(produto, &categoria, &codigo);
                /* segura a lista por 3 segundos*/
                     sleep(6);
            break;
             /*B – Buscar produto já cadastrado.*/
            case 'B':
                codigo = controledeSerie(bancoProduto);
                produto = carregarDadosProdutos(produto,&codigo);
                produto = buscarProduto(produto, &codigo);
                lerProduto(produto);
                 /* segura a lista por 3 segundos*/
                     sleep(5);
            break;
            case 'A':
            codigo = controledeSerie(bancoProduto);
            atualizarCadastroProduto(produto , &codigo);
             /* segura a lista por 3 segundos*/
                     sleep(1);
            break;
            case 'E':
            exclusaoCadastroProduto(produto);
             /* segura a lista por 3 segundos*/
                     sleep(1);
            break;
            case 'P':
            /*esta função faz a atualização do estoque */
            codigo = buscaPorCodigo(bancoProduto);
            produto = carregarDadosProdutos(produto, &codigo);
            produto = atualizarEstoque(produto+codigo-1, &codigo);
            atualizarDadosProduto(produto, &codigo);
            break;
   }}while(op != 'S');
}


/* Esta função cadastra dados do Produto */
Produto cadastroProduto(Produto *produto, long int *idproduto){
produto->codigo = *idproduto;
printf("Produto: \n");
scanf(" %[^\n]s",produto->nome );
printf("Informe o Fornecedor: \n");
scanf(" %[^\n]s", produto->fornecedor);
printf("Informe a categoria: \n");
scanf(" %[^\n]s", produto->categoria);
printf("Informe a quantidade: \n");
scanf("%d", &produto->quantidade);
printf("Informe a valor unitario: \n");
scanf("%d", &produto->valor);
}

/* Esta função grava os dados do produto*/
void gravarDadosProduto(Produto *produto){
    FILE *arquivo;
    arquivo = abrirArquivo('a', "dBprodutos.txt");

        fprintf(arquivo,"%d;%s;%s;%s;%d;%d\n" , produto->codigo, produto->nome, produto->fornecedor, produto->categoria, produto->quantidade,
        produto->valor);
        printf("\n salvo com sucesso!! \n\n\n");
   fecharConexao(arquivo);
}


/* Esta função faz a listagem de todos os produtos cadastados no banco*/
void listarTodosProdutos(Produto *produto, char *categoria,long int *qtd) {
long int i = 0, j = 0;
while(j <= *qtd){
if(strcmp(categoria , (produto+i)->categoria) == 0){
     printf("%ld - %s - %s - %s - %d -  %d \n" , (produto+i)->codigo, (produto+i)->nome, (produto+i)->fornecedor, (produto+i)->categoria, (produto+i)->quantidade,
        (produto+i)->valor);
        printf("\n");
        i++;
        }
        j++;
}
if(i==0){
printf("Erro não encontrado produto para a categoria\n");
printf("Lista de todos os produtos:\n");
i = 0;
while(i < *qtd){
        printf("%d - %s - %s - %s - %d -  %d \n" , (produto+i)->codigo, (produto+i)->nome, (produto+i)->fornecedor, (produto+i)->categoria, (produto+i)->quantidade,
        (produto+i)->valor);
        printf("\n");
        i++;
}
}}


/* Esta funçao carrega dinamicamente os cadastro de prodtutos*/
int carregarDadosProdutos(Produto *produto, long int *qtd){
int i = 0;
produto = malloc(sizeof(Produto)*(*qtd));
FILE *arquivo;
arquivo = abrirArquivo('l',"dBprodutos.txt" );

char *linha = malloc(sizeof(Produto)* (*qtd));
while(i < *qtd){
            fscanf(arquivo, " %[^\n]s", linha);
            (produto+i)->codigo = atoi(strtok(linha, ";"));
            strcpy((produto+i)->nome, strtok(NULL, ";"));
            strcpy((produto+i)->fornecedor, strtok(NULL, ";"));
            strcpy((produto+i)->categoria, strtok(NULL, ";"));
            (produto+i)->quantidade = atoi(strtok(NULL, ";"));
            (produto+i)->valor = atoi(strtok(NULL, ";"));
i++;
}
fecharConexao(arquivo);
return produto;
};


/* esta função ordena a lista de Produtos*/
int ordenarListaProduto(Produto *produto, int *qtd ){
char aux[40];
int i = 0, j = 0;
for(i=0; i<*qtd; i++) {
	for(j=0; j<*qtd; j++) {
		if(strcmp((produto+i)->nome, (produto+j)->nome) < 0) {
		strcpy(aux, (produto+i)->nome);
		strcpy((produto+i)->nome, (produto+j)->nome);
		strcpy((produto+j)->nome, aux);
		}
	}
}
return produto;
}


/*esta função faz a atualizacao do produto os dados */
Produto atualizarCadastroProduto(Produto *produto, int *total){
long int posicao = buscaPorCodigo(bancoProduto);
cadastroProduto(produto,&posicao);
atualizarDadosProduto(produto, &posicao);
}


/* Esta função grava os dados do produto*/
Produto atualizarDadosProduto(Produto *produto, long int *posicao){
   long int i = 0;
    FILE *arquivo;
    arquivo = abrirArquivo('g',"dBprodutos.txt");
    char *linha = malloc(sizeof(Produto));
       while(i <= *posicao){
            fscanf(arquivo," %[^\n]s", linha);
                    if(i == *posicao-1 || i == 0){
                        fprintf(arquivo,"\n%d;%s;%s;%s;%d;%d\n" ,
                        produto->codigo, produto->nome, produto->fornecedor,
                        produto->categoria, produto->quantidade,produto->valor);
                     }  i++;}
                        printf("\n Atualizado!!\n\n");
                        fecharConexao(arquivo);
}


/*esta função solicta informa o codigo para a exclusão dos dados do produto */
void exclusaoCadastroProduto(long int *codigo){
codigo = buscaPorCodigo(bancoProduto);
excluirDadosProduto(codigo);
}


/*esta função faz a exclusao dos dados do produto*/
void excluirDadosProduto(int long *posicao){
Produto *produto;
long int i = 0;
    FILE *arquivo;
    arquivo = abrirArquivo('g', "dBprodutos.txt");
    char *linha = malloc(sizeof(Produto));
       while(i <= *posicao) {
       fscanf(arquivo, " %[^\n]s", linha);
                    if(i == *posicao){
                        fscanf(arquivo, " %[^\n]s");
                            }
                printf(arquivo," \n %s", linha);
                fseek(arquivo, 1, SEEK_SET);
                printf(arquivo,"%ld", i);
          i++; }
           fecharConexao(arquivo);
        printf("\n Excluido com sucesso!!!!! \n\n\n");
}


/*  Esta função verifica a atualização do estoque */
int atualizarEstoque(Produto *produto, long int *codigo){
printf("Informe a quantidade do: %s \n\n", produto->nome);//
produto->codigo = *codigo;
scanf("%d", &produto->quantidade);
return produto;
}

/*esta função busca todos os produtos por nome ou produtos */
int buscarProduto(Produto *produto, long int *qtd){
int op;
char busca[30];
    printf("[BUSCA: ] \n 1 -> CODIGO: \n 2 -> NOME: \n 999 -> SAIR: \n");
    scanf("%d", &op);
    switch (op){
        case 999:
            main();
        break;
        case 1:
              printf("CODIGO: \n");
              scanf(" %[^\n]s", &busca);
              long int b = atoi(busca);
              produto =  buscaNumericaCodigoProduto(produto,&b, qtd);
              return produto;
        break;
        case 2:
              printf("NOME: \n");
              scanf(" %[^\n]s", &busca);
              produto = buscaSequencialNomeProduto(&busca, qtd, produto);
              return  produto;

        break;
}  };

/*esta função busca por codigo do produto */
int buscaNumericaCodigoProduto( Produto *produto, long int *busca, long int *qtd){
long int posicao = 0, meio;
long int deslocamento = (*qtd)-1 ;
    while(posicao <= deslocamento){
    meio = (posicao + deslocamento)/2;
        if((produto+meio)->codigo == (*busca))
           return produto+meio;
        if((produto+meio)->codigo < (*busca))
            posicao = meio + 1;
        else
            deslocamento = meio-1;
    }
    printf("Erro !! \n nao foi encontrado\n");
    main();
        return buscar(produto, qtd);
}

/*esta função busca todos os nomes dos produtos */
int buscaSequencialNomeProduto(char *busca, int *qtd, Produto *produto){
    int posicao = 0 ;
     for(posicao = 0; posicao <=*qtd; posicao++){

        if(strcmp ((produto+posicao)->nome, busca) == 0){
            return produto+posicao;
         }
         if(posicao == *qtd){
         printf("Erro !! \n ao foi encontrado\n");
         main();
            return buscarProduto(produto, qtd);
        }}}

/*Esta função imprime o produto */
void lerProduto(Produto *produto){
                printf("Codigo: %li   ",produto->codigo);
                printf("Nome : %s\n",produto->nome );
                printf(" Fornecedor: %s\n", produto->fornecedor);
                printf("Categoria : %s\n",produto->categoria);
                printf("Quantidade : %d Und.   ", produto->quantidade);
                printf("Valor Unitario : %d ,00 R$  \n", produto->valor);
                printf("=================================================\n");
}

