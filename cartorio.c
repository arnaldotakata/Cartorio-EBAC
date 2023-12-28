#include <stdio.h>  //biblioteca de cominica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��a de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
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
	
	strcpy(arquivo, cpf); // os valores da string cpf ser� copiada dentro da string arquivo
	
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
		printf("Arquivo n�o encontrado. \n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nInforma��es do usu�rio: ");
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
	 	printf("CPF n�o encontrado. \n");
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
	
	  printf("\t CART�RIO DA EBAC\n\n"); //inicio do menu
	  printf("\t Op��es:\n\n");
	  printf("\t1) Registrar nome do usu�rio\n");
	  printf("\t2) Consultar nome do usu�rio\n");
 	  printf("\t3) Deletar nome do usu�rio\n\n"); 
	  printf("Op��o:"); // fim do menu
	
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
	    printf("Essa op��o n�o est� dispon�vel!\n"); 
	    system("pause");
	    break;
	    
	  }
	    
	}// fim da selecao
}   
