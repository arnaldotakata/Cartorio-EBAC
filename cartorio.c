#include <stdio.h>  //biblioteca de cominicação com o usuário
#include <stdlib.h> //biblioteca de alocaçõa de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca das strings


int registro()
{
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	
	printf("Cadastre o CPF: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // os valores da string cpf será copiada dentro da string arquivo
	
	FILE *file; //cria um arquivo dentro do arquivo (FILE), dando origem ao banco de dados
	file = fopen(arquivo, "w"); // fopen = abri o arquivo file, "w" = cria um arquivo de texto no modo de escrita 
	fprintf(file,cpf); // fprint = armazena a variavel cpf que o usuario digitar dentro do file
	fclose(file); // fecha o arquivo

	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Cadastre o nome: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Cadastre o sobrenome: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Qual o cargo? ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
}

int consulta()
{
	setlocale(LC_ALL,"PORTUGUESE"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: " );
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file ==NULL)
	{
		printf("Arquivo não encontrado. \n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nInformações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
}

int deletar()
{
	char cpf[40];
	
	 printf("Deletar CPF: ");
	 scanf("%s", cpf);
	 
	 remove(cpf);
	 
	 FILE *file;
	 file = fopen(cpf, "r");
	 
	 if(file != NULL)
	 {
	 	printf("CPF deletado com sucesso. \n");
	 	system("pause");
	 }
	 
	 if(file == NULL)
	 {
	 	printf("CPF não encontrado. \n");
	 	system("pause");
	 }
	 
}


int main()

{
	int opcao=0; //Definindo variaveis
	int loop=1;
	
	for(loop=1;loop=1;)
	{
		system("cls");
	
	  setlocale(LC_ALL,"PORTUGUESE"); //Definindo a linguagem
	
	  printf("\t CARTÓRIO DA EBAC\n\n"); //inicio do menu
	  printf("\t Opções:\n\n");
	  printf("\t1) Registrar nome do usuário\n");
	  printf("\t2) Consultar nome do usuário\n");
 	  printf("\t3) Deletar nome do usuário\n\n"); 
	  printf("Opção:"); // fim do menu
	
	  scanf("%d" , &opcao); //armazenando a escolha do usuario
	
	  system("cls");
	  
	  switch(opcao)
	  {
	  	case 1:
	  	registro();
	    break;
	    
	    case 2:
	    consulta();
	    break;
	    	
	    case 3:
	    deletar();
	    break;
	    
	    default:
	    printf("Essa opção não está disponível!\n"); 
	    system("pause");
	    break;
	    
	  }
	    
	}// fim da selecao
}   
