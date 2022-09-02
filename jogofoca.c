#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "forca.h" // é um header nosso, está puxando as informações do arquivo forca.h que contêm todas as funções do código

/* Declaração de variáveis globais, utilizadas em todo o código e fora de todas as outras funções
   Desta forma, não preciso declarar em cada uma das funções:
   ex: void chuta(char chutes[26], int* chutesdados){ ----->  void chuta(){
   Tomar cuidado ao utilizar variáveis globais, pq perde um pouco o controle sobre a variável pois qualquer linha pode alterá-la
*/
char palavrasecreta[TAMANHO_PALAVRA]; // array de 10 posições
char chutes[26]; // Quantas vezes a pessoa pode chutar, número de letras do alfabeto
int chutesdados=0; // Quantos chutes a pessoa já deu

// Funções

void abertura() {
	printf("\n******************************\n");
	printf("*       Jogo de Forca       *\n");
	printf("******************************\n\n");
	printf("Regrinhas:\n");
	printf("Digite apenas utilizando letras em maiusculo! Ex: AMORA\n");
	printf("Nao utilize acentos, por favor. Ex: MELAO\n\n");
}

void chuta(){
	char chute;

	printf("Digite uma letra: ");
	scanf(" %c", &chute); // Colocar um espaço antes do %c para ele não entender que o enter é um char

	chutes[chutesdados] = chute; // Aqui chutesdados deixou de ser um ponteiro pois agora é uma variável global
	chutesdados++;
}

int jachutou(char letra){
	// a letra já foi chutada?
	int achou=0;

	for(int j=0; j < chutesdados; j++){

		if(chutes[j] == letra){
			achou=1;
			break;
		}
	}

	return achou;
}

void desenhaforca(){

	int erros = chuteserrados();

	printf("  _______       \n");
	printf(" |/      |      \n");
	// (erros>=1 ? '(' : ' ') ------> significa se erros >= 1 então aparece ( se não (simbolo : ) aparece ' ' (espaço vazio)
	printf(" |      %c%c%c    \n", (erros>=1 ? '(' : ' '), (erros>=1 ? '_' : ' '), (erros>=1 ? ')' : ' '));
	printf(" |      %c%c%c    \n", (erros>=3 ? '\\' : ' '), (erros>=2 ? '|' : ' '), (erros>=3 ? '/' : ' '));
	printf(" |       %c       \n", (erros>=2 ? '|' : ' '));
	printf(" |      %c %c     \n", (erros>=4 ? '/' : ' '), (erros>=4 ? '\\' : ' '));
	printf(" |                \n");
	printf("_|___             \n");
	printf("\n\n");

	// imprime a palavra secreta
	int achou=0; // booleano

	for(int i=0; i<strlen(palavrasecreta); i++){ // strlen irá contar o número de letras até o /0 que indica o final da palavra.

		int achou = jachutou(palavrasecreta[i]);

		if(achou){
			printf("%c ", palavrasecreta[i]);
		} else{
			printf("_ ");
		}
	}
	printf("\n\n");
}

void adicionapalavra(){
	char quer;
	char novapalavra[TAMANHO_PALAVRA];

	printf("Voce quer adicionar uma nova palavra ao jogo? (S/N)  ");
	scanf(" %c", &quer);

	if(quer == 'S'){
		printf("Qual a nova palavra? ");
		scanf("%s", novapalavra);

		FILE* f;

		f = fopen("palavras.txt", "r+"); // r+ significa permissão de leitura e escrita

		int qtd;
		fscanf(f, "%d", &qtd);
		qtd++;

		fseek(f, 0, SEEK_SET); // o 0 indica a posição inicial do arquivo, SEEK_SET é para posicionar no começo
		fprintf(f, "%d", qtd);

		fseek(f, 0, SEEK_END); // SEEK_END é para posicionar no final
		fprintf(f, "\n%s", novapalavra);

		fclose(f);

		printf("\n\nA palavra **%s** foi adicionada com sucesso!\n\n", novapalavra);
	}

}

void escolhepalavra(){
	FILE* f; // variável FILE com ponteiro
	// fopen abre outros arquivos, o palavras.txt é o nome do arquivo e o segundo parâmetro é 'r' de read em inglês
	f = fopen("palavras.txt", "r");

	if(f == 0){ // Se o ponteiro for nulo, quer dizer que o fopen falhou, ou seja, ocorreu algum problema com o arquivo
		printf("Desculpe, banco de dados nao disponivel\n\n");
		exit(1); // se exit = 0, programa funcionou normalmente, se exit > 0, o programa irá fechar
	}

	int qtddepalavras;

	// ler algo do arquivo indicado pelo f, no caso o número de linhas q está indicado na primeira linha do arquivo
	fscanf(f, "%d", &qtddepalavras);

	srand(time(0));
	int randomico = rand() % qtddepalavras;

	for(int i=0; i<=randomico; i++){
		fscanf(f, "%s", palavrasecreta);
	}

	fclose(f); // é sempre importante fechar um arquivo no código
}

int acertou() {
	for(int i=0; i<strlen(palavrasecreta); i++){
		if(!jachutou(palavrasecreta[i])){
			return 0;
		}
	}

	return 1;
}

int chuteserrados(){

	int existe, erros=0; 
	for(int i=0; i<chutesdados; i++){

		existe = 0;

		for(int j=0; j<strlen(palavrasecreta); j++){
			if(chutes[i] == palavrasecreta[j]){

				existe = 1;
				break;
			}
		}

		if(!existe) erros++;
	}

	return erros;
}

int enforcou(){

	return chuteserrados() >= 5;
}

// *************************************************************************************************************************************

int main() {

	escolhepalavra(palavrasecreta);
	abertura();

	do {

		desenhaforca(palavrasecreta, chutes, chutesdados);

		chuta(chutes, &chutesdados); // Passando os dois parâmetros para a função chuta(), &chutesdados está passando o local onde a info está gravada


	} while(!acertou() && !enforcou()); // booleanos (0 é negativo e 1 é positivo) o ! nega uma variação booleana; invoca as variáveis

	if(acertou()){
	    printf("\nParabens, voce ganhou!\n\n");
	    printf("A palavra e **%s**\n\n", palavrasecreta);

	    printf("       ___________      \n");
	    printf("      '._==_==_=_.'     \n");
	    printf("      .-\\:      /-.    \n");
	    printf("     | (|:.     |) |    \n");
	    printf("      '-|:.     |-'     \n");
	    printf("        \\::.    /      \n");
	    printf("         '::. .'        \n");
	    printf("           ) (          \n");
	    printf("         _.' '._        \n");
	    printf("        '-------'       \n\n\n");

	} else {
	    printf("\nPuxa, voce foi enforcado!\n");
	    printf("A palavra era **%s**\n\n", palavrasecreta);

	    printf("    _______________         \n");
	    printf("   /               \\       \n"); 
	    printf("  /                 \\      \n");
	    printf("//                   \\/\\  \n");
	    printf("\\|   XXXX     XXXX   | /   \n");
	    printf(" |   XXXX     XXXX   |/     \n");
	    printf(" |   XXX       XXX   |      \n");
	    printf(" |                   |      \n");
	    printf(" \\__      XXX      __/     \n");
	    printf("   |\\     XXX     /|       \n");
	    printf("   | |           | |        \n");
	    printf("   | I I I I I I I |        \n");
	    printf("   |  I I I I I I  |        \n");
	    printf("   \\_             _/       \n");
	    printf("     \\_         _/         \n");
	    printf("       \\_______/           \n\n\n");

	}

	adicionapalavra();

	system("pause");
	return 0;
}
