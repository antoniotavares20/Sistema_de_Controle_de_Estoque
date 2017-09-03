/* Escopo das funções*/
/* Escopo da função do menu do cliente*/
void menuCliente();
void menuPedido();
long int controledeSerie();
/* função para realizar a exclusao do cadastro do cliente*/
void exclusaoCadastroCLiente();
/*função para atualização do cliente */
Cliente atualizarCadastroCliente(Cliente *cliente);
/* função para atualização do produto*/
Produto atualizarCadastroProduto(Produto *produto, int *);
/* Esta função grava os dados do produto*/
Produto atualizarDadosProduto(Produto *produto, long int *);
/*Esta função faz o cadastro do produto */
Produto cadastroProduto(Produto *produto, long int *);
/* Escopo da função cadastro de cliente*/
Cliente cadastroCliente(Cliente *, long int *);
/* Escopo da função cadastro de cliente*/
Pedido cadastroPedido(Pedido *, int *);
/* Escopo da função para gravar o cliente*/
void gravarDadosCliente(Cliente *cliente);
/*Esta função faz a busca por codigo */
int buscaPorCodigo(int);
/*função par buscar informações a partir do codigo*/
void excluirDadosCliente(int long *);
/*esta função solicta informa o codigo para a exclusão dos dados do produto */
void exclusaoCadastroProduto(long int *);
/*função para carregar dados do cliente */
int carregarDadosCliente(Cliente *cliente, long int *);
/* Esta funçao carrega dinamicamente os cadastro de prodtutos*/
int carregarDadosProdutos(Produto *produto,long int *);

/*escopo da função para buscar cliente */
int buscar(Cliente *,long int *);
/*função para realizar a busca sequencial do nome do arquivo */
//int buscaSequencialNome(char *busca, long int *, Cliente *);

/* Escopo da função para listar todos os clientes em paralelo*/
void listarTodosCliente(Cliente *,long int * );
/*Esta funçao faz a busca numerica do codigo de qualquer item do banco*/
int buscaNumericaCodigo( Cliente *, long int *, long int *);

/* Esta função faz a listagem de todos os produtos cadastados no banco*/
void listarTodosProdutos(Produto *produto, char *, long int *);
/* Escopo da função para listar os clientes em serie cliente*/
void listarCliente(Cliente *);
/* Escopo da função imprimir menu de todas areas*/
void imprimirMenu(int msg);
/* Escopo da função de impressao*/
void imprimirMsg(char *);
/*Imprime dados do menu*/
void imprimirDados(char *, int );
/* esta função ordena a lista de Cliente*/
int ordenarLista(Cliente *, int *) ;
/* esta função ordena a lista de Produtos*/
int ordenarListaProduto(Produto *, int *) ;
/*esta função faz a leitura de um produto*/
void lerProduto(Produto *);
/*esta função busca todos os nomes dos produtos */
int buscaSequencialNomeProduto(char *, int *qtd, Produto *);
/* esta função faz a busca binaria de um codigo do produto */
int buscaNumericaCodigoProduto( Produto *, long int *, long int *);
/*esta função busca todos os produtos por nome ou produtos */
int buscarProduto(Produto *, long int *);
/*  Esta função verifica a atualização do estoque */
int atualizarEstoque(Produto *, long int *);
/*esta função faz exclusao de um dos produtos a partir do codigo */
void excluirDadosProduto(int long *);
/* esta função cadastra um pedido para um cliente em especifico*/
int cadastroClientePedido(Pedido *);
/*esta função cadastra um produto para um pedido de um cleinte */
int cadastroProdutoPedido(Pedido *pedido);
/* esta função retorna a DDHHAA em cada tipo especificado */
int verificaTempo(int);
/* Esta função imprime a lista de todos os produtos em uma data especifica*/
void listarPedido(Pedido *);

