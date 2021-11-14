#ifndef PACIENTES_H_INCLUDED
#define PACIENTES_H_INCLUDED
typedef struct paciente PACIENTE;
struct paciente
{
    char nome[50];
    char telefone [15];
    char cep    [15];
    char email[100];
    char comorbidades[100];

};

void CadastrarPaciente(){
    PACIENTE paciente;
    int opcao;
    FILE* arquivo;


    arquivo = fopen("pacientes.bin","ab");  // escrita e bin�rio
    if(arquivo == NULL)
    {
        printf("Problema ao tentar abrir o arquivo. \n");

    }else
        do{
            system("cls");
            fflush(stdin);
            desenha(24,5,100,20);
            gotoxy(26,5);
            printf(" CADASTRAR PACIENTE ");
            gotoxy(26,7);
            printf("Nome: ");
            gotoxy(26,8);
            printf("Idade: ");
            gotoxy(26,9);
            printf("3 - Sem ideias");
            gotoxy(26,10);
            printf("CEP: ");
            gotoxy(26,11);
            printf("Telefone: ");
            gotoxy(26,12);
            printf("Email: ");
            gotoxy(26,12);

            fflush(stdin);
            pegaLetras(paciente.nome);
            if (strcmp(paciente.nome,"")==0) break; // se n�o digitar nada ent�o saia
            gotoxy(30,13);
        {
            fwrite(&paciente, sizeof(PACIENTE),1,arquivo);
            gotoxy(30,20);
            printf(" ---- CADASTRADO COM SUCESSO! DESEJA CONTINUAR CADASTRANDO ? ----- ");
            gotoxy(30,20);
            printf("      0 = NAO      ");
            gotoxy(30,20);
            printf("      1 = SIM      ");
            gotoxy(30,20);        
        }
        fflush(stdin);
        scanf("%d",&opcao);
    }
    while(opcao != 0);
    fclose(arquivo); //Cadastro conclu�do, feche o arquivo
}
#endif