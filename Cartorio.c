#include <stdio.h> //biblioteca de comunicaçao com o usuario
#include <stdlib.h> //biblioteca de alocaçao de memória
#include <locale.h> //biblioteca de alocaçao de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string

int registro()  // Funçao responsavel por cadastrar os usuarios no sistema
{ 
    //inicio da criação das variaveis
    char arquivo[40];  //string-----
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // final da criação das variaveis/string
    printf("Digite o CPF a ser cadastrado: "); //Para registrar o nome
    scanf("%s",cpf); //%s refece-se a string
    
    strcpy(arquivo, cpf); 	//Responsavel por copiar os valores das string
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo,"w"); //cria o arquivo
    fprintf(file,cpf); //salvo o valor da variavel
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo,"a"); // o "A" altera um arquivo ja criado 
    fprintf(file,",");		//adiciona virgula para difencias as infomaçoes do suario
    fclose(file); //fechar o arquivo
    
    printf("Digite o nome a ser cadastrado: "); //Para registrar o Nome
    scanf("%s",nome); 
    
    file = fopen(arquivo,"a"); //adicionando o nome no registro
    fprintf(file,nome);
    fclose(file);   //sempre feche o arquivo quando colocar
    
    file = fopen(arquivo,"a"); //para a virgula no arquivo de registro
    fprintf(file,",");
    fclose(file); 
    
    printf("Digite o Sobrenome a ser cadastrado: "); //Para registrar o Sobrenome
    scanf("%s",sobrenome);
    
    file = fopen(arquivo, "a");		//Adicionando o Sobrenome no registro
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo,"a");   //para a virgula no arquivo
    fprintf(file,",");
    fclose(file); 
    
    printf("Digite o cargo a ser cadastrado: ");  //Para registrar o Cargo
    fprintf(file,cargo);
    scanf("%s",cargo);
    
    file = fopen(arquivo,"a");		//Adicionando o cadastro no arquivo
    fprintf(file,cargo);
    fclose(file);
    
    file = fopen(arquivo,"a");  //para a virgula no arquivo
    fprintf(file,",");
    fclose(file);
    
    system("pause");  
	   
	system("cls");          
                                //fim do armazenamento
}

int consulta()   //usado para consultar as informaçoes armazenados
{
	setlocale(LC_ALL, "portuguese"); //definindo a linguagem nessa funçao
					//criando as variaveis
    char cpf[40];
    char conteudo[200];
    				//fim
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);		//Puchando a variavel CPF armazenada no arquivo
    
    FILE *file;           	//acesse o arquivo
    file = fopen(cpf,"r");	//"r" usado para ler o arquivo cpf
    
    if(file == NULL)		//Usado para o caso de não ter o cpf registrado. Dois == são comparação
    {
    
    	printf("Não foi possivel abrir o arquivo, não localizado.\n ");
    	
	}
	
    while(fgets(conteudo, 200, file) != NULL)  //"while" ele estiver escrevendo no conteudo/variavel até 200 valores que estao dentro do arquivo CPF enquando for diferente de nulo
    {
    	printf("\nEssas são as informações do usuário: ");
    	printf("%s", conteudo); //usado para aparecer na tela o conteudo encontrado
    	printf("\n\n");
	}
	fclose(file);
    system("pause");
    
    system("cls");
}

int deletar() //usado para apagar o usuario no registro
{
	char cpf[40]; // definindo a variavel
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf); //puchando a variavel cpf (que é a variavel usado para definir o usuario) armazenada no arquivo
	
	remove(cpf); //apagando o arquivo correspondente a variavel cpf (que é a variavel usado para definir o usuario)

	FILE *file;
	file = fopen(cpf,"r");
	
	    if(file == NULL)   // caso não tenha nenhum usuario com o cpf informado
		{
			printf("Usuario não se encontra no sistema.\n");
			system("pause");
		}
		fclose(file);
		
		system("cls");
}

int main()         //funçao principal, ela vai ser sempre a primeira a ser executada
{                         
	int opcao=0;   //definindo as variaveis
	int laco=1; 	//precisa que seja 1 para sempre entrar no for, pois enquanto a variavel for 1 irá repitir o codigo
	char senhadigitada[10] = "a";
	int comparacao;
	
	setlocale(LC_ALL, "portuguese");
	
	printf("\t\t\t\t\t\t###-Cartório da EBAC-###\n\n");
	printf("Login de Adimistrador!\n\n\Digite a sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		system("cls");

		for(laco=1;laco=1;) //usado para repitir o codigo apartir daqui
		{  			//chaves usado para definir o inicio e o fim do laço
	
			setlocale(LC_ALL, "portuguese"); //definindo a linguagem
	
			printf("\t\t\t\t\t\t###-Cartório da EBAC-###\n\n"); //inicio do menu de opcao
			printf("Escolha a opçao desejada no menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n\n");
			printf("\t4 - Sair do sistema\n\n\n");
			printf("opção: ");//fim das opcaoes

			scanf("%d", &opcao);  //armazenando a escolha do usuario
	
			system("cls"); //tem como função limpar a tela apos a escolha da opção
	
			switch(opcao) //usado para escolher a opçao
			{
				case 1: //Se a variavel for a opçao 1
		    	registro(); //pucha a funçao "int" Registro
				break;  //sempre se deve fechar
			
				case 2: //Ou 2
				consulta(); //pucha a funçao "int" Consulta
				break;
			
				case 3: //Ou 3
	    		deletar();  //pucha a funçao "int" Deletar
				break;
			
				case 4:
				printf("Obrigado por ter utilizado o sistema!");
				return 0;
				break;
		
				default:  //Ou não for nenhum
				printf("Esta opcao não esta disponivel!\n");
				system("pause");
				break;
			
			}
		}
	} 
	else
		printf("Senha incorreta!");
	
}
