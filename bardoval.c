#include <stdio.h>
#include <stdlib.h>
#define TAM 102

//Estrutura produto
struct produto{
	char nome[TAM];
	char lote[20];
	int qtd;
	char validade[12];
};

//Procedimento que cadastra um produto no sistema
void cadastro(){
	char prod[TAM];

	printf("Insira o nome do produto: ");
	fgets(prod, TAM, stdin);

	FILE *arq;

	//Criando arquivo
	arq = fopen(prod, "a");
	fclose(arq);

	//Registrando o produto no documento "produtos"
	arq = fopen("produtos.txt", "a");

	fprintf(arq, "%s", prod);

	fclose(arq);
}

//Procedimento que apresenta todos os produtos já registrados no sistema ao usuário
void produtos(){
	char prod;
	FILE *arq;

	arq = fopen("produtos.txt", "r");

	//Recebendo o conteúdo do arquivo e imprimindo na tela do usuário
	while(!feof(arq)){
		fscanf(arq, "%c", &prod);
		printf("%c", prod);
	}

	fclose(arq);
}

//Procedimento que registra uma entrada de um produto que já está no sistema
void entrada(){
	struct produto prod;

	printf("Insira o nome do produto que receberá a entrada: ");
	fgets(prod.nome, TAM, stdin);

	printf("Insira o número do lote: ");
	fgets(prod.lote, 20, stdin);

	//Eliminando o \n do final da string
	for(int i=0; i<sizeof(prod.lote); i++){
		if(prod.lote[i] == '\n'){
			prod.lote[i] = '\0';
		}
	}

	printf("Insira a quantidade comprada do produto: ");
	scanf("%d", &prod.qtd);

	while (getchar() != '\n');//Limpando o buffer de leitura

	printf("Insira a data de validade do lote (formato XX/XX/XXXX): ");
	fgets(prod.validade, 12, stdin);

	FILE *arq;

	arq = fopen(prod.nome, "a");

	//Salvando os dados do novo lote no arquivo
	fprintf(arq, "%d %s %s", prod.qtd, prod.lote, prod.validade);

	fclose(arq);
}

//Procedimento que gera um relatório de um produto já cadastrado no sistema
void relatorio(){
	char name[TAM], prod;
	FILE *arq;

	printf("Insira o nome do produto para que o relatório seja gerado: ");
	fgets(name, TAM, stdin);

	printf("Quantidade em estoque | Lote | Validade\n");

	arq = fopen(name, "r");

	//Recebendo o conteúdo do arquivo e imprimindo na tela do usuário
	while(!feof(arq)){
		fscanf(arq, "%c", &prod);
		printf("%c", prod);
	}

	fclose(arq);
}

//Procedimento que faz a baixa de um produto no estoque
void baixaestoque(int estoq[8], int quantidade, char name[TAM], char lot[8][15], char val[8][15], int h){
	FILE *arq;

	arq = fopen(name, "w");

		/*Se o lote de um produto não for zerado com a venda, então o arquivo recebe
		todos os lotes do produto, com a devida baixa. Caso o lote seja zerado, o mesmo
		será excluído do arquivo. Caso seja necessário usar o mesmo produto de diferentes
		lotes, o sistema fará as devidas baixas por meio de chamada recursiva desse
		procedimento.*/
		if((estoq[0] - quantidade)>=0){
			if((estoq[0] - quantidade)==0){
				for(int k=1; k<h; k++){
					fprintf(arq, "%d %s %s\n", estoq[k], lot[k], val[k]);//Imprime dados do lote no arquivo
				}
			}
			else{
				estoq[0] -= quantidade;

				for(int k=0; k<h; k++){
					fprintf(arq, "%d %s %s\n", estoq[k], lot[k], val[k]);//Imprime dados do lote no arquivo
				}
			}

			fclose(arq);
		}
		else{
			estoq[0] -= quantidade;

			quantidade = (-1)*estoq[0];

			for(int k=1; k<h; k++){
				fprintf(arq, "%d %s %s\n", estoq[k], lot[k], val[k]);//Imprime dados do lote no arquivo
			}

			fclose(arq);

			int j=0;

			arq = fopen(name, "r");

			//Lê e registra os dados do produto que terá baixa no estoque
			while((fscanf(arq, "%d %s %s\n", &estoq[j], lot[j], val[j]))!=EOF){
				j++;
			}

			fclose(arq);

			baixaestoque(estoq, quantidade, name, lot, val, j);//Chamada recursiva
		}
}

//Procedimento que gera uma nota fiscal
void notafiscal(int control){
	char data[12];
	int tip;

	printf("Insira a data de emissão (formato XX/XX/XXXX): ");
	fgets(data, 12, stdin);

	printf("Insira quantos tipos diferentes de mercadorias foram comprados: ");
	scanf("%d", &tip);

	while (getchar() != '\n');//Limpando o buffer de leitura

	char name[tip][TAM];
	int quant[tip];
	float val_Un[tip];

	//Recebendo os dados dos produtos
	for(int i=0; i<tip; i++){
		printf("Insira o nome do produto: ");
		fgets(name[i], TAM, stdin);

		printf("Insira a quantidade do produto: ");
		scanf("%d", &quant[i]);

		while (getchar() != '\n');//Limpando o buffer de leitura

		printf("Insira o valor unitário do produto (use '.' no lugar de ','): R$");
		scanf("%f", &val_Un[i]);

		while (getchar() != '\n');//Limpando o buffer de leitura
	}

	//Se control=1, então essa é a 1ª via da nota fiscal, logo, é preciso dar baixa no estoque
	if(control = 1){
		for(int i=0; i<tip; i++){
			FILE *arq;

			arq = fopen(name[i], "r");

			char lot[8][15], val[8][15];
			int estoq[8], j=0;

			//Lê e registra os dados do produto que terá baixa no estoque
			while((fscanf(arq, "%d %s %s\n", &estoq[j], lot[j], val[j]))!=EOF){
				j++;
			}

			fclose(arq);

			baixaestoque(estoq, quant[i], name[i], lot, val, j);//Chama baixaestoque
		}
	}

	char cpf[12];
	int confirmacpf;

	printf("O cliente deseja CPF na nota? (Se sim, digite 1, caso contrário, digite qualquer outro número): ");
	scanf("%d", &confirmacpf);

	while (getchar() != '\n');//Limpando o buffer de leitura

	if(confirmacpf==1){
		printf("Digite o CPF do cliente: ");
		scanf("%s", cpf);
		while (getchar() != '\n');//Limpando o buffer de leitura
	}

	//Imprimindo a nota fiscal
	printf("\n\n\t\tNota Fiscal de Venda a Consumidor\n\nNf-e: N° %d\tSérie 1\n", rand()%1000000);
	printf("Data de emissão: %s\nNome do Impressor: Valterci Almeida Secco\tEndereço: Rua 7 de Setembro, Centro, Mirassol-SP\n", data);
		
	if(confirmacpf==1){
		printf("CPF do cliente: %s\n", cpf);
	}

	float total=0;

	for(int i=0; i<tip; i++){
		printf("\nIdentificação do produto: %s\t Quantidade comprada: %d un\t Valor unitário: R$%.2f\t Valor total: R$%.2f\n", name[i], quant[i], val_Un[i], quant[i]*val_Un[i]);
		total += quant[i] * val_Un[i];
	}

	printf("\nValor a ser pago: R$%.2f\n", total);
}

//Procedimento que registra uma venda
void saida(){
	int c=1;

	notafiscal(c);//Chama notafiscal para imprimir 1ª via da nota fiscal
}

int main(){
	int funcionalidade, controle, c=0;

	printf("\n\tBEM-VINDO AO SISTEMA QUANTAS GELADAS!!!\n");

	do{
		//Apresentando as opções de interação com o sistema
		printf("\nPara realizar o cadastro de um novo produto, digite 1.\n");
		printf("Para vizualizar os produtos já cadastrados, digite 2.\n");
		printf("Para registrar uma entrada no estoque, digite 3.\n");
		printf("Para registrar uma saída do estoque (venda), digite 4.\n");
		printf("Para gerar relatório de um produto, digite 5.\n");
		printf("Para emitir a segunda via de uma nota fiscal, digite 6.\n\n");

		printf("Digite o número da funcionalidade desejada: ");
		scanf("%d", &funcionalidade);

		while (getchar() != '\n');//Limpando o buffer de leitura

		//Switch case que chama funções específicas para cada funcionalidade dos sistema
		switch(funcionalidade){
			case 1: 
				cadastro();
				break;
			case 2:
				produtos();
				break;
			case 3:
				entrada();
				break;
			case 4:
				saida();
				break;
			case 5:
				relatorio();
				break;
			case 6:
				notafiscal(c);
				break;
			default: 
				printf("O valor inserido é inválido.\n");
		}

		printf("\n\n\nDeseja executar alguma outra atividade no sistema? Se sim, digite 1. Se não, digite qualquer outro número: ");
		scanf("%d", &controle);
		while (getchar() != '\n');//Limpando o buffer de leitura
		printf("\n\n");
	}while(controle==1);

	return 0;
}