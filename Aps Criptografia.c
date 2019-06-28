# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <conio.h> 



void menu_opcoes()
{

    system("cls");

   printf("Menu\n\n");
   printf("Para cifrar uma mensagem----------------digite 1\n");
   printf("Para decifrar uma mensagem--------------digite 2\n");
   printf("Para sair do programa-------------------digite 3\n\n");
   printf("Observacoes para a frase e para a chave\n\n");
   printf("Sera permitido no maximo 128 caracteres\n\n");
   printf("Nao sera permitidos letras que nao esteja no alfabeto\n\n");
   printf("Devera ser criado uma pasta chamada Criptografia no disco :C para salvar o arquivo\n");
}

void somente_letras(char *msg)
{ // Remove numeros e caracteres especiais
    int i,j=0;
    char msg_nova[128];

    for(i=0;i<strlen(msg);i++)
	{ // Pega todos os caracteres do vetor string(texto ou chave)
        if(msg[i]>=65 && msg[i]<=90)
		{ // Se o caractere atual não estiver no intervalo A-Z
           msg_nova[j] = msg[i]; // Adiciona a letra maiuscula a um novo vetor
            j++;
        }
    }

    for(i=0;i<j;i++){ // Substitue o texto antigo pelo novo(que contem somente letras)
        msg[i] = msg_nova[i];
    }

    msg[i] = '\0'; // Adiciona um valor nulo ao final do texto
}



void criptografar()
{
    //declaração de variaveis
    char msg[128];
    char chave[128];
    int i;
    int tamChave;
    int tammsg;



    //Entrada de dados mensagem a ser criptografada
    printf("Mensagem deve conter maximo de 128 Letras!\n\n");
    printf("Digite a mensagem para ser cifrada:\n\n");
    fflush(stdin); //limpa o buffer do teclado
    gets(msg);
    strupr(msg);// convertendo a string para maiuscula

    if (strlen(msg) < 4)
    {
    	printf("Frase menor que 4 caracteres... Tente novamente!\n\n");

    	printf("Digite a mensagem para crifrar:\n\n");
        fflush(stdin);
        gets(msg);
        strupr(msg);
	}

    somente_letras(msg);


    //Entrada de dados Chave
    printf("Chave no maximo 128 caracteres\n\n");
    printf("Informe a chave:\n\n ");
    fflush(stdin); //limpa o buffer do teclado
    gets(chave);
    strupr(chave);//convertendo a string para maiuscula

    if (strlen(chave) < 4)
    {
    	printf("Chave menor que 4 caracteres...Tente novamente!\n\n");

    	printf("Informe a chave:\n\n");
        fflush(stdin);
        gets(chave);
        strupr(chave);
	}



    somente_letras(chave);

    tammsg = strlen(msg);
    tamChave = strlen(chave);
    printf("o tamanho da chave e:  %d", tamChave);


      for (i=0 ; i <strlen(msg); i++)
      {
        if(i >= tamChave)
		{
            msg[i] = ((msg[i] - 65) + (chave[i%strlen (chave)]-65))%26 + 65;
        }
		else
		{
            msg[i] = (msg[i] + chave[i])%26 + 65;
        }

      }
       printf("\nMensagem cifrada: %s", msg);


    FILE *texto;

    texto = fopen("C:\\Criptografia\\criptografado.txt","w");
    fprintf(texto,msg);
    fclose(texto);

    system("explorer C:\\Criptografia\\criptografado.txt");

}

void descriptografar()
{


	//declaração de variaveis
	char pause;
    char msg[128];
    char chave[128];
    int i;
    int tamChave;
    int tammsg;

    printf("\nPressione Enter para abrir a pasta!\n\n");
    getch();
    setbuf(stdin,NULL);

    system("explorer c:\\Criptografia\\criptografado.txt");


	  //Entrada de dados mensagem a ser descriptografada
    printf("Copie e cole a mensagem Cifrada para ser Descifrada:");
    fflush(stdin); //limpa o buffer do teclado
    gets(msg);
    strupr(msg);// convertendo a string para maiuscula

    if (strlen(msg) < 4)
    {
    	printf("Frase menor que 4 caracteres... Tente novamente!\n\n");

    	printf("Digite a mensagem para cifrar: ");
        fflush(stdin);
        gets(msg);
        strupr(msg);
	}


    //Entrada de dados Chave
    printf("Informe a chave: ");
    fflush(stdin); //limpa o buffer do teclado
    gets(chave);
    strupr(chave);//convertendo a string para maiuscula

    if (strlen(chave) < 4)
    {
    	printf("Chave menor que 4 caracteres...Tente novamente!\n\n");

    	printf("Informe a chave: ");
        fflush(stdin);
        gets(chave);
        strupr(chave);
	}

    tammsg = strlen(msg);
    tamChave = strlen(chave);
    printf("o tamanho da chave e:  %d", tamChave);




      for (i=0 ; i <strlen(msg); i++)
      {
        if(i <= tamChave || i >= tamChave)
		{
            msg[i] = (msg[i] - chave[i % strlen(chave)] + 26) % 26 + 65;
        }
		else
		{
            msg[i] = (msg[i] - chave[i])%26 + 65;
        }


      }
       printf("\nMensagem descifrada    = %s", msg);


}


int main(){



    //Declaração de variaveis
    int escolha;

    do
    {
        menu_opcoes();
        scanf("%d", &escolha);

        switch(escolha)
        {
            case 1:
                system("cls"); // limpa o que tem antes
                criptografar();
                getch();//pausa no sistema
            break;

            case 2:
                system("cls");
                descriptografar();
                getch();
            break;

            case 3:
                system("cls");
                printf("Programa finalizado com sucesso\n\n");
                getch;
            break;

            default:
                system("cls");
                printf("Opcao invalida! Tente novamente.");
                getch();
            break;
        }

    }while(escolha != 3);


       system("pause");

}
