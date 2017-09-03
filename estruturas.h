/*esta tipo de dado retorna uma sequencia enumerada de elementos do menu*/
enum {
    msgMenuPrincipal = 1 ,
    msgMenuCliente,
    msgMenuProduto ,
    msgMenuGerenciarPedidos,
    msgMenuTitulosClientes,
    msgMenuTitulosProdutos,
    msgMenuTitulosPedidos
}Mensagem;

enum {
    bancoCliente = 1 ,
    bancoProduto,
    bancoPedido,
}banco;

/* esta é uma estrutura do endereco*/
typedef struct {
char logradouro[100],
complemento[30],
cep[30],
bairro[30],
cidade[30],
uf[30];
}Endereco;


/* esta é uma estrutura do cliente*/
typedef struct Cliente{
 long int codigo;
 char nome[30];
 char CPF[30];
 char  telefone[50];
 Endereco endereco;
}Cliente;

/*Esta é uma estrutura do tipo Produto*/
typedef struct Produto{
long int codigo;
 char nome[30], fornecedor[30], categoria[30];
 int quantidade, valor;
}Produto;

/* esta é uma estrutura do Pedido*/
typedef struct Pedido{
long int codigo;
int dia, mes, ano;
Produto produto;
Cliente cliente;
}Pedido;

/*esta é uma estrutura para verficar o tempo*/
typedef struct tm * temepoAtual;

/* enumera as opcoes para data */
typedef enum datas{
    opDia = 1,
    opMes,
    opAno
}datas;


