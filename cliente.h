
/* Esta função trata o menu do cliente*/
void menuCliente(){
/* variavel que recebe o ultimo numero da lista */
long int codigo = 0;
/* Contador para para verifciar a capacidade de armazenamento*/
int tamaho = 1;
char op ;
/* Ponteiro para estrutura do tipo cliente */
Cliente *cliente = malloc(sizeof(Cliente));
 do{
 /* limpa a tela */

/* Mensagem para imprimir menu*/
 imprimirMenu(msgMenuCliente);
 scanf(" %c%*[^\n]",&op);
op = toupper(op);

switch (op){
/*C – Cadastrar um cliente */
            case 'C' :
                /* Atualiza o codigo de serie para um novo cadastro*/
                codigo = controledeSerie(bancoCliente);
                /* funçao para cadastrar cliente*/
                cadastroCliente(cliente+codigo, &codigo);
                /* funçao para gravar cliente*/
                gravarDadosCliente(cliente+codigo);
                /*Condiçao de almento de tamanho de capacidade maxima */
                if(tamaho >= TAMANHOINICIAL){
                cliente = realloc(cliente, tamaho*sizeof(cliente));
                };
                /* desaloca o espaço da memoria*/
                tamaho++;
                /* segura a lista por 3 segundos*/
            break;
             /*L – Listar todos os clientes cadastrados.*/
            case 'L' :
                codigo = controledeSerie(bancoCliente);
                /* imprime menu titulo do indice de clientes em paralelo */
                imprimirMenu(msgMenuTitulosClientes);
                /* Recebe a referencia dos clientes cadastrados no vetor */
                cliente =  carregarDadosCliente(cliente, &codigo);
                /* Faz a ordenação da lista*/
                cliente =  ordenarLista(cliente, &codigo);
                /* Passa a referencia dos clientes cadastrados no vetor e os lista*/
                listarTodosCliente(cliente, &codigo);
                /* desaloca o espaço da memoria*/
            //    cliente == NULL;
                /* segura a lista por 3 segundos*/
                     sleep(6);
            break;
             /*B – Buscar cliente já cadastrado.*/
            case 'B' :

                codigo = controledeSerie(bancoCliente);
                cliente = carregarDadosCliente(cliente, &codigo);
                cliente = buscar(cliente, &codigo);
                listarCliente(cliente);
                /* segura a lista por 3 segundos*/
                     sleep(3);
            break;
            case 'A' :
                /*A – Atualizar um cliente cadastrado.*/
                atualizarCadastroCliente(cliente);
                /* segura a lista por 3 segundos*/
                     sleep(1);
            break;
                /*E – Excluir um dado do cliente.*/
            case 'E' :
                codigo = controledeSerie(bancoCliente);
                exclusaoCadastroCLiente(&codigo);
                /* segura a lista por 3 segundos*/
                     sleep(1);
            break;
   }}while(op != 'S');
}

/*esta função faz a atualizacao do cliente */
Cliente atualizarCadastroCliente(Cliente *cliente){
long int posicao = buscaPorCodigo(bancoCliente);
cadastroCliente(cliente,&posicao);
atualizarDadosCliente(cliente, &posicao);
}

/*esta função faz a exclusão dos dados do cliente */
void exclusaoCadastroCLiente(long int *codigo){
codigo = buscaPorCodigo(bancoCliente);
excluirDadosCliente(codigo);
}

/* Esta função cadastra dados do cliente */
Cliente cadastroCliente(Cliente *cliente, long int *codigo){
cliente->codigo = *codigo;
printf("Informe o nome: \n");
scanf(" %[^\n]s",cliente->nome );
printf("Informe o CPF: \n");
scanf(" %[^\n]s", cliente->CPF);
printf("Informe o telefone: \n");
scanf(" %[^\n]s", cliente->telefone);
printf("====Endereço=====\n");
printf("Informe o logradouro :\n");
scanf(" %[^\n]s", cliente->endereco.logradouro);
printf("Informe o complemento :\n");
scanf(" %[^\n]s", cliente->endereco.complemento);
printf("Informe o CEP: \n");
scanf(" %[^\n]s", cliente->endereco.cep);
printf("Informe o bairro :\n");
scanf(" %[^\n]s", cliente->endereco.bairro);
printf("Informe a cidade :\n");
scanf(" %[^\n]s", cliente->endereco.cidade);
printf("Informe a UF: \n");
scanf(" %[^\n]s", cliente->endereco.uf);
}

/* Esta função grava os dados do cliente*/
void gravarDadosCliente(Cliente *cliente){
    FILE *arquivo;
    arquivo = abrirArquivo('a', "dBcliente.txt");
        fprintf(arquivo,"%li;%s;%s;%s;%s;%s;%s;%s;%s;%s\n", cliente->codigo, cliente->nome,
        cliente->CPF, cliente->telefone, cliente->endereco.logradouro, cliente->endereco.complemento,
        cliente->endereco.cep,cliente->endereco.bairro, cliente->endereco.cidade, cliente->endereco.uf);
        printf("\n salvo!!!!! \n\n\n");
   fecharConexao(arquivo);
}


/* Esta função grava os dados do cliente*/
void atualizarDadosCliente(Cliente *cliente, long int *posicao){
    long int i = 0;
    FILE *arquivo;
    arquivo = abrirArquivo('g', "dBcliente.txt");
    char *linha = malloc(sizeof(Cliente));
       while(i <= *posicao){
            fscanf(arquivo," %[^\n]s", linha);
                    if(i == *posicao-1 || i == 0){
                        fprintf(arquivo,"\n%li;%s;%s;%s;%s;%s;%s;%s;%s;%s\n" , cliente->codigo, cliente->nome,
                        cliente->CPF, cliente->telefone, cliente->endereco.logradouro, cliente->endereco.complemento,
                        cliente->endereco.cep,cliente->endereco.bairro, cliente->endereco.cidade, cliente->endereco.uf);
                        }  i++;}
                        printf("\n Atualizado!!\n");
                        fecharConexao(arquivo);

   }


/*esta função faz a exclusao dos dados do cliente*/
void excluirDadosCliente(int long *posicao){
Cliente *cliente;
long int i = 0;
    FILE *arquivo;
    arquivo = abrirArquivo('g', "dBcliente.txt");
    char *linha = malloc(sizeof(Cliente));
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
        printf("\n Ex!!!!! \n\n\n");
}


/* Esta funçao carrega dinamicamente os clientes cadastrados*/
int carregarDadosCliente(Cliente *cliente, long int *qtd){
int i = 0;
FILE *arquivo;

cliente = malloc(sizeof(Cliente)* (*qtd));
/*redireciona o ponteiro para a primeira posição */
//rewind(arquivo);
arquivo = abrirArquivo('l',"dBcliente.txt" );
char *linha = malloc(sizeof(Cliente)* (*qtd));

while(i < *qtd)
{  //          linha = realloc(linha, sizeof(Cliente)* (*qtd));
            fscanf(arquivo, " %[^\n]s", linha);
            (cliente+i)->codigo = atoi(strtok(linha, ";"));
            strcpy((cliente+i)->nome, strtok(NULL, ";"));
            strcpy((cliente+i)->CPF, strtok(NULL, ";"));
            strcpy((cliente+i)->telefone, strtok(NULL, ";"));
            strcpy((cliente+i)->endereco.logradouro, strtok(NULL, ";"));
            strcpy((cliente+i)->endereco.complemento, strtok(NULL, ";"));
            strcpy((cliente+i)->endereco.cep, strtok(NULL, ";"));
            strcpy((cliente+i)->endereco.bairro, strtok(NULL, ";"));
            strcpy((cliente+i)->endereco.cidade, strtok(NULL, ";"));
            strcpy((cliente+i)->endereco.uf, strtok(NULL, ";"));
i++;
}fecharConexao(arquivo);
return cliente;
};


/* esta função todos os clientes*/
void listarTodosCliente(Cliente *cliente, long int *qtd) {
long int i = 0;
while(i <= *qtd) {
    printf(" %li - %s- %s -  %s -  %s  -  %s -  %s - %s - %s - %s " , (cliente+i)->codigo, (cliente+i)->nome,
    (cliente+i)->CPF, (cliente+i)->telefone, (cliente+i)->endereco.logradouro, (cliente+i)->endereco.complemento,
    (cliente+i)->endereco.cep,(cliente+i)->endereco.bairro, (cliente+i)->endereco.cidade, (cliente+i)->endereco.uf);
    i++;
    printf("\n");
}

}


/* esta função lista um cliente*/
void listarCliente(Cliente *cliente){
                printf("Codigo: %ld   ",cliente->codigo);
                printf("Cliente : %s\n",cliente->nome );
                printf("CPF : %s\n",cliente->CPF);
                printf("Telefone : %s\n",cliente->telefone);
                printf("Endereço : \n");
                printf("Logradouro : %s    ", cliente->endereco.logradouro);
                printf("Complemento : %s   \n", cliente->endereco.complemento);
                printf("CEP : %s    ", cliente->endereco.cep);
                printf("Bairro : %s \n", cliente->endereco.bairro);
                printf("Cidade : %s   ", cliente->endereco.cidade);
                printf("UF : %s \n", cliente->endereco.uf);
                printf("=================================================\n");
};


/*esta função busca por codigo os nomes */
int buscaNumericaCodigo( Cliente *cliente, long int *busca, long int *qtd){
    long int posicao = 0 ;
     for(posicao = 0; posicao <= *qtd; posicao++){
        if( (cliente+posicao)->codigo == *busca && posicao <= *qtd){

            return cliente+posicao;
         } else{
         printf("Erro !! \n nao foi encontrado\n");
            return buscar(cliente, qtd);
        }}}

/*esta função busca todos os nomes */
void  buscaSequencialNome(){
int i = 0 ;
for(i = 0; i< 10; i++){
printf("teste");
}
}


/*esta função busca todos os clientes por nome ou codigo */
int buscar(Cliente *cliente,long int *qtd){


int op;
char *busca = malloc(sizeof(cliente->codigo));
char t[50];
long int n,i;
    printf("[BUSCA: ] \n 1 -> CODIGO: \n 2 -> NOME: \n 999 -> SAIR: \n");
    scanf("%d", &op);
    switch (op){
        case 1:
            printf("Codigo: \n");
            scanf("%ld", &n);
            for(i=0; i< *qtd; i++){
            if(n==(cliente+i)->codigo){
                printf("cod %ld \n", (cliente+i)->codigo);
                                            return cliente+i;
                }
            if(n > *qtd){
                printf("Erro!! Nao encontrado!!");
                main();
             }
             }
        break;
        case 2:
               printf("Nome: \n");
               scanf(" %[^\n]s",&t);
               for(i=0; i< *qtd; i++){
                        if(strcmp((cliente+i)->nome, t) == 0 ){
                            return cliente+i;
                        }
            if(n > *qtd){
                printf("Erro!! Nao encontrado!!");
                main();
             }
             }

        break;
        }

        }


/* esta função ordena a lista de Clientes*/
int ordenarLista(Cliente *cliente, int *qtd ){
char aux[40];
int i = 0, j = 0;
for(i=0; i<*qtd; i++) {
	for(j=0; j<*qtd; j++) {
		if(strcmp((cliente+i)->nome, (cliente+j)->nome) < 0) {
		strcpy(aux, (cliente+i)->nome);
		strcpy((cliente+i)->nome, (cliente+j)->nome);
		strcpy((cliente+j)->nome, aux);
		}
	}
}
return cliente;
}

