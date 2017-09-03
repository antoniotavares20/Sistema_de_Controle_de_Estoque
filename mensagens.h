
/*esta função seleciona os tipos de menus existentes*/
void imprimirMenu(int msg){
setlocale(LC_ALL, "Portuguese");

/*Mensagem para Principal*/
char  msgPrincipal[][TAM_LINHA_MSG]= {
"Digite um comando para prosseguir:",
"C – Gerenciar Clientes",
"P – Gerenciar Produtos",
"E – Gerenciar Pedidos",
"S – Sair." ,
";",
};

/*Mensagem para gerenciar Cliente*/
char msgCliente[][TAM_LINHA_MSG] = {
"============ Gerenciar Cliente  ============",
 "Digite um comando para prosseguir:",
 "C – Cadastrar um cliente.",
 "L – Listar todos os clientes cadastrados.",
 "B – Buscar cliente já cadastrado.",
 "A – Atualizar um cliente cadastrado.",
 "E – Excluir um cliente cadastrado." ,
 };

/*Mensagem para gerenciar produtos*/
char msgProduto[][TAM_LINHA_MSG] = {
"============== Gerenciar Produtos ========",
 "Digite um comando para prosseguir:",
 "C – Cadastrar um produto.",
 "L – Listar todos os produtos cadastrados.",
 "B – Buscar produto já cadastrado.",
 "A – Atualizar um produto cadastrado",
 "E – Excluir um produto cadastrado",
 "P – Atualizar estoque de um produto",
 ";",
};

/*Mensagem do iten gerenciar pedidos*/
char msgGerenciarPedidos[][TAM_LINHA_MSG] = {
"Digite um comando para prosseguir: ",
"C – Cadastrar um pedido.",
"L – Listar todos os pedidos de um cliente.",
"D – Listar todos os pedidos em um dia específico. ",
";",
};

/*mensagem para imprimir titulos do cliente*/
char msgtituloCliente[][TAM_LINHA_MSG] = {"Codigo","Nome", "CPF", "Telefone","Endereço Logradouro",
"Complemento", "CEP", "Bairro","Cidade", "UF \n",";"};

char msgtituloProduto[][TAM_LINHA_MSG] = { "Codigo", "Nome", "Fornecedor", "Categoria", "Quantidade",
 "Valor Unitário \n", ";"};

char msgtituloPedidos[][TAM_LINHA_MSG] = { "Codigo", "Dia", "Mes", "Ano", "Cliente",
 "Produto \n", ";"};

switch(msg){
    /*Menu principal */
    case msgMenuPrincipal:
    imprimirMsg(msgPrincipal);
    break;
    /*Menu cliente */
    case msgMenuCliente:
    imprimirMsg(msgCliente);
    break;
    /*Menu produto*/
    case msgMenuProduto:
    imprimirMsg(msgProduto);
    break;
    /*Menu gerenciar pedidos*/
    case msgMenuGerenciarPedidos:
    imprimirMsg(msgGerenciarPedidos);
    break;
    /*Menu listar titulos do cliente*/
    case msgMenuTitulosClientes:
    imprimirMsgSerie(msgtituloCliente);
    break;
    /*Menu listar titulos do Produtos*/
    case msgMenuTitulosProdutos:
    imprimirMsgSerie(msgtituloProduto);
    break;
    /*Menu listar titulos do Pedidos*/
    case msgMenuTitulosPedidos:
    imprimirMsgSerie(msgtituloPedidos);
    break;

};
};


/*essa função imprime as mensagens*/
void imprimirMsg(char *msg){
   system("clear");

do{
        printf("%s\n",msg);
        msg+=TAM_LINHA_MSG;
        }while(strcmp(msg,";") > 0);

}

/*essa função imprime as mensagens em serie*/
imprimirMsgSerie(char *msg){
do{
        printf("%s ",msg);
        msg+=TAM_LINHA_MSG;
        }while(strcmp(msg,";") != 0);
                printf(" \n");
}
