/**********************************************/
/*    IAS Assembler - MC 404 - Trabalho 1     */
/* Vitor Alves Mesquita da Silva - RA: 158498 */
/**********************************************/

#ifndef TAM_PALAVRA
#define TAM_PALAVRA 64
#endif

/* ENUMS */
#ifndef TIPO_ITEM
#define TIPO_ITEM
enum tipoItem{ ROTULO=1, DIRETIVA=2, INSTRUCAO=3, DECIMAL=4, HEXADECIMAL=5, ENTRE_ASPAS=6, DESCONHECIDO=7};
#endif

#ifndef TIPO_PALAVRA
#define TIPO_PALAVRA
enum tipoPalavra{ NUMERO_HEXA=1, INSTRUCOES=2};
#endif

#ifndef LADO
#define LADO
enum lado{ESQUERDA=1, DIREITA=2};
#endif

#ifndef TIPO_INSTRUCAO
#define TIPO_INSTRUCAO
enum tipoInstrucao {
	LD=1,
	LDmenos=2,
	LDmod=3,
	LDmq=4,
	LDmq_mx=5,
	ST=6,
	JMP=7,
	JUMPmais=8,
	ADD=9,
	ADDmod=10,
	SUB=11,
	SUBmod=12,
	MUL=13,
	DIV=14,
	LSH=15,
	RSH=16,
	STaddr=17
};
#endif

/* STRUCTS */
#ifndef PALAVRA
#define PALAVRA
struct palavra {
	char campo1[TAM_PALAVRA], campo2[TAM_PALAVRA];
	int pos;  /* posicao associada */
	int tipo;
	struct palavra *prox;
};
#endif

#ifndef ROT
#define ROT
struct rotulo {
	char nome[64];
	int pos; /* posicao assiciada */
	int lado;
	struct rotulo *prox;
};
#endif

#ifndef ITEM
#define ITEM
struct item {
	char campo[64];
	int tipo;
	int linha;
	struct item *prox;
};
#endif

/* FUNÇÕES */
int indentificarInstrucao(char campo[]);
bool ehInstrucao(char campo[]);
void preencherInstrucao(char *campo, int tipoInstrucao, 
	struct item *pItem, int ladoInstrucao, struct rotulo *listaRotulos);
void executarInstrucao(struct item *pItem, struct item *listaItens, struct rotulo *listaRotulos,
	int *pontoDeMontagem, struct palavra *listaPalavras, int *ladoAtual);
bool ehStringZero(char *string);
int escolherLado(struct palavra *p);
