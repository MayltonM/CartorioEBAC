#include <stdio.h>//biblioteca de comunicação do usurário
#include <stdlib.h>//biblioteca de manutençao de arquivo
#include <locale.h>//biblioteca de texto regional
#include <string.h>//biblioteca q gerencia strings

//função de registrar usuários no sistema
int registrar(){
	//variásveis da criação de usuário
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s",cpf);
	
	strcpy(arquivo,cpf); //copiar os valores das strings
	
	FILE *file; //habilita o acesso ao arquivo
	file = fopen(arquivo, "w"); //dá um titulo ao arquivo e o escreve
	fprintf(file,cpf);//salva o valor da variavel no arquivo
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abertura do arquivo
	fprintf(file,",");//escreve no arquivo
	fclose(file);//fecha arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");//abertura do arquivo
	fprintf(file,nome);//escreve no arquivo
	fclose(file);//fecha arquivo
	
	file = fopen(arquivo, "a");//abertura do arquivo
	fprintf(file,",");//escreve no arquivo
	fclose(file);//fecha arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");//abertura do arquivo
	fprintf(file,sobrenome);//escreve no arquivo
	fclose(file);//fecha arquivo
	
	file = fopen(arquivo, "a");//abertura do arquivo
	fprintf(file,",");//escreve no arquivo
	fclose(file);//fecha arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");//abertura do arquivo
	fprintf(file,cargo);//escreve no arquivo
	fclose(file);//fecha arquivo
	
	file = fopen(arquivo, "a");//abertura do arquivo
	fprintf(file,".");//escreve no arquivo
	fclose(file);//fecha arquivo
	
	system("pause");
	
}

//função de consultar
int consultar(){
	
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;//habilita o acesso ao arquivo
	file = fopen(cpf,"r");//abertura do arquivo
	
	if(file == NULL){
		printf("Não foi possível abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file)!=NULL){
		printf("\n Essas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

//função de deletar
int deletar(){
	
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");//leitura
	scanf("%s",cpf);//%s corresponde a leitura de string
	
	FILE *file;//habilita o acesso ao arquivo
	file = fopen(cpf,"r");//abertura do arquivo
	
	//início da verificação
	if(file == NULL){
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}else{
		remove(cpf);
		printf("O usuário removido do sistema!.\n");
		system("pause");
	}//fim da verificação
	
}

int main(){
	
	int opcao = 0; //opcao a se escoher
	int x = 0;
	
	for(x=1;x=1;){
	
		setlocale(LC_ALL, "Portuguese"); // linguagem usada
		
		system("cls");//função de limpar a tela
		
		printf("Cartório da EBAC \n\n\n");//menu inicial
		printf("Selecione a opção desejada no menu\n\n");
		printf("\t1 - Registrar Nomes\n \t2 - Consultar Nomes\n \t3 - Deletar Nomes\n");
		printf("Opção : ");
		scanf("%d", &opcao);//fim do menu inicial
		
		system("cls");
		
		//inicio das condições
		switch(opcao){
			case 1:
			registrar();
			break;
		 	case 2:
			consultar();
			break;
			case 3:
			deletar();
			break;
			default:
			printf("Você escolheu uma opção inexistente!\n\n");
			system("pause");
			break;
		}//fim das condições
	}


}
