/*função principal para o pedido */
void menuPedido(){
long int codigo =0;
Pedido *pedido = malloc(sizeof(Pedido)*QTD_MAX_PROD);
char op;
do{
       imprimirMenu(msgMenuGerenciarPedidos);
        scanf(" %c%*[^\n]",&op);
        op=toupper(op);

switch (op){

                /*C – Cadastrar um pedido */
            case 'C' :
                codigo = controledeSerie(bancoPedido);
                cadastroPedido(pedido+codigo, &codigo);
                gravarDadosPedido(pedido+codigo);
                /* segura a lista por 3 segundos*/
                     sleep(1);
            break;
             /*L – Listar todos os pruduto cadastrados.*/
            case 'L' :
                codigo = controledeSerie(bancoPedido);
                pedido  = carregarDadosPedidos(pedido, &codigo);
                listadeProdutoscadastrado(pedido);
                /* segura a lista por 3 segundos*/
                     sleep(6);
            break;
             /*B – l9sta pedido já cadastrado por dia.*/
            case 'D' :
                codigo = controledeSerie(bancoPedido);
                pedido  = carregarDadosPedidos(pedido, &codigo);
                listaProdutosData(pedido, &codigo);
                /* segura a lista por 3 segundos*/
                     sleep(3);
            break;
            case 'A' :
                /*A – Atualizar um pedido cadastrado.*/
            break;
            case 'S':
            break;
            default:
            printf("Opcao Incorreta!\n");
            main();
   }}while(op != 'S');
}

Pedido cadastroPedido(Pedido *pedido, int *codigo){
int i;
pedido->codigo = *codigo;
cadastroClientePedido(pedido);
cadastroProdutoPedido(pedido);
pedido->dia = verificaTempo(opDia);
pedido->mes = verificaTempo(opMes);
pedido->ano = verificaTempo(opAno);
printf("PEDIDO REGISTRADO COM SUCESSO! \n  Aparecida de Goiania %d de %d de 20%d \n\n.",
pedido->dia, pedido->mes, pedido->ano);
}

int cadastroClientePedido(Pedido *pedido){
Cliente *cliente;
int i;
/* carrega os busca os codigos*/
long int qtdCliente =  controledeSerie(bancoCliente);
/* carrega se nao carregar volta ao menu cadastro cliente*/
if (qtdCliente < 0) menuCliente();
/* carrega os clientes existentes*/
cliente = carregarDadosCliente(cliente, &qtdCliente);
/*realiza a busca na lista e armazena o cliente em questao para a estrutura cliente */
printf("Informe o codigo do CLIENTE : \n");
cliente = buscar(cliente, &qtdCliente);
/*copia os dados relevantes do cliente para estrutura ou banco do pedido */
pedido->cliente.codigo = cliente->codigo;
strcpy(pedido->cliente.nome, cliente->nome);

printf("O cliente é : Codigo: %ld %s \n", pedido->cliente.codigo, pedido->cliente.nome);
printf("OK! \n");

return pedido;
}
/* esta função realiza o cadastro de um pedido */
int cadastroProdutoPedido(Pedido *pedido){
Produto *produto;
int i;
/* carrega os busca os codigos*/
long int qtdProduto =  controledeSerie(bancoProduto);
/* carrega se nao carregar volta ao menu cadastro produto*/
if (qtdProduto < 0) menuProduto();
/* carrega os clientes existentes*/
produto = carregarDadosProdutos(produto, &qtdProduto);
/*realiza a busca na lista e armazena o produto em questao para a estrutura produto */
printf("Informe o codigo do PRODUTO : \n");
produto = buscarProduto(produto, &qtdProduto);
/*copia os dados relevantes do produto para estrutura ou banco do pedido */
pedido->produto.codigo = produto->codigo;
strcpy(pedido->produto.nome, produto->nome);
printf("Informe a quantidade do %s \n",  pedido->produto.nome);
/*Quantidade para o produto em questao */
scanf("%d",&pedido->produto.quantidade);
printf("O produto é : Codigo: %ld %s \n", pedido->produto.codigo, pedido->produto.nome);
printf("OK! \n");
return pedido;
}

/*esta função busca a data e retorna em tipos inteiros */
int verificaTempo(int op){
char nomedata[20];
int *data;
struct tm * tempoAtual;
time_t tempo;
time(&tempo);
tempoAtual = localtime(&tempo);

switch(op){
case 1:
/* função retorna a data em tempo atual a partir do parametro da estrutra tm*/
strftime(nomedata,sizeof(int),"%d", tempoAtual);
data = atoi(nomedata);
return data;

case 2:
strftime(nomedata,sizeof(int),"%m", tempoAtual);
data = atoi(nomedata);
return data;

case 3:
strftime(nomedata,sizeof(int),"%y", tempoAtual);
data = atoi(nomedata);
return data;
}
}

/* Esta função grava os dados do pedido*/
void gravarDadosPedido(Pedido *pedido){
    FILE *arquivo;
    arquivo = abrirArquivo('a', "dBpedido.txt");
        fprintf(arquivo,"%li;%s;%li;%s;%li;%d;%d;%d;%d\n", pedido->codigo,
        pedido->cliente.nome,pedido->cliente.codigo,
        pedido->produto.nome, pedido->produto.codigo,pedido->produto.quantidade,
        pedido->dia, pedido->mes, pedido->ano);
        printf("\n salvo!!!!!\n");
        fecharConexao(arquivo);
}
/* Esta funçao carrega dinamicamente os clientes cadastrados*/
int carregarDadosPedidos(Pedido *pedido,long int*qtd){
int i = 0;
FILE *arquivo;
pedido = malloc(sizeof(Pedido)*(*qtd));
arquivo = abrirArquivo('l',"dBpedido.txt" );
char *linha = malloc(sizeof(Pedido)* (*qtd));

while(i < *qtd)
{           linha = realloc(linha, sizeof(Cliente)* (*qtd));
            fscanf(arquivo, " %[^\n]s", linha);
            (pedido+i)->codigo = atoi(strtok(linha, ";"));

            strcpy((pedido+i)->cliente.nome, strtok(NULL, ";"));
            (pedido+i)->cliente.codigo = atoi(strtok(NULL, ";"));

            strcpy((pedido+i)->produto.nome, strtok(NULL, ";"));
            (pedido+i)->produto.codigo = atoi(strtok(NULL, ";"));
            (pedido+i)->produto.quantidade = atoi(strtok(NULL, ";"));

            (pedido+i)->dia = atoi(strtok(NULL, ";"));
            (pedido+i)->mes = atoi(strtok(NULL, ";"));
            (pedido+i)->ano = atoi(strtok(NULL, ";"));
    i++;
}fecharConexao(arquivo);
return pedido;
};


void listadeProdutoscadastrado(Pedido *pedido){
   long int qtd =pedido->codigo;
   long int i, j, q, z;
    char aux[i][30];
    for(i = 0; i < qtd; i++){
        strcpy(aux[i], (pedido+i)->cliente.nome);
        printf("ok impresso");
        for(j = 0; j< qtd; j++){
                printf("Cliente: %d", aux[i]);
                if(strcmp(aux[i], (pedido+q)->cliente.nome) == 0){
                    printf("Produto: %s  ", (pedido+q)->cliente.nome);
                    printf("Qantidade: %d \n",(pedido+q)->produto.quantidade);
                    printf("Dia: %d .",(pedido+q)->dia);
                    printf("Mes: %d .",(pedido+q)->mes);
                    printf("Ano: 20%d .\n",(pedido+q)->ano);
                    printf("-----------------------------");
                }}
        for(j = i; j >=0; j--){
                if( strcmp(aux[i], aux[j]) == 0){
                      i++;
                }
        }
    }
}


void listaProdutosData(Pedido *pedido,long int *qtd){
printf("Informe o dia em específico:\n\n");
long int  i =0;
int dia;
scanf("%d", &dia);

while(i <= *qtd){
if(dia == (pedido+i)->dia){
    listarPedido(pedido+i);
}
i++;
}
}

void listarPedido(Pedido *pedido){
printf("Codigo do Pedido: nr:%ld \n", pedido->codigo);
printf("Cliente: %s       ", pedido->cliente.nome);
printf("Codigo do Cliente %ld", pedido->cliente.codigo);
printf("Cliente: %s", pedido->produto.nome);
printf("Codigo do Produto %ld       ", pedido->produto.codigo);
printf("Codigo do Quantidade %ld    ", pedido->produto.quantidade);
printf("Codigo do Quantidade %ld    ", pedido->produto.quantidade);
printf("Data: %d de %d de 29%d", pedido->dia, pedido->mes, pedido->ano);
}




