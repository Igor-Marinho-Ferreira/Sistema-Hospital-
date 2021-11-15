#ifndef PACIENTES_H_INCLUDED
#define PACIENTES_H_INCLUDED

typedef struct paciente PACIENTE;
struct paciente
{
    char nome[50];
    char telefone[120];
    char idade[15];
    char cep[15];
    char cpf[13];
    char email[100];

};

void CadastrarPaciente(){
    PACIENTE paciente;
    int opcao;
    FILE* arquivo;


    arquivo = fopen("pacientes.bin","ab");  // escrita e binario
    if(arquivo == NULL)
    {
        printf("<ERRO!> Problema na abertura do arquivo!\n");

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
            printf("CPF: ");
            gotoxy(26,10);
            printf("CEP: ");
            gotoxy(26,11);
            printf("Telefone: ");
            gotoxy(26,12);
            printf("Email: ");

            gotoxy(32,7);
            fflush(stdin);
            pegaLetras(paciente.nome);
            if (strcmp(paciente.nome,"")==0)break; 

            gotoxy(33,8);
            fflush(stdin);
            pegaDigito(paciente.idade);
            if (strcmp(paciente.idade,"")==0) break; 

            gotoxy(33,9);
            fflush(stdin);
            pegaDigito(paciente.cpf);
            if (strcmp(paciente.cpf,"")==0) break; 

            gotoxy(31,10);
            fflush(stdin);
            pegaDigito(paciente.cep);
            if (strcmp(paciente.cep,"")==0) break; 

            gotoxy(37,11);
            fflush(stdin);
            pegaDigito(paciente.telefone);
            if (strcmp(paciente.telefone,"")==0) break; 

            gotoxy(33,12);
            fflush(stdin);
            pegaEmail(paciente.email);
            if (strcmp(paciente.email,"")==0) break; 
        {
            fwrite(&paciente, sizeof(PACIENTE),1,arquivo);
            gotoxy(30,20);
            printf(" ---- CADASTRADO COM SUCESSO! DESEJA CONTINUAR CADASTRANDO ? ----- ");
            gotoxy(30,21);
            printf("      0 = NAO      ");
            gotoxy(30,22);
            printf("      1 = SIM      ");
            gotoxy(30,23);        
        }
        fflush(stdin);
        scanf("%d",&opcao);
        system("cls");
    }
    while(opcao != 0);
    fclose(arquivo); 
}

void RemoverPacientes(){
    FILE* arq;
    FILE* temp;
    PACIENTE paciente;
    char cpf[13];
    arq = fopen("pacientes.bin","rb"); //abrir em modo rb leitura binaria
    temp = fopen("tmp_pct.bin","wb"); //abrir em modo wb ele limpa e grava binario
    system("cls");

    if(arq==NULL&&temp==NULL)
    {
        printf("<ERRO!> Problema na abertura do arquivo!\n");
        getch();
    }else{
        fflush(stdin);
        printf("Digite o CPF do paciente a deletar: ");
        gets(cpf);
        while (fread(&paciente,sizeof(PACIENTE),1,arq)==1)
        {
            if(strcmp(cpf,paciente.cpf)==0)
            {
                gotoxy(0,8);
                printf("Nome: %s\n",paciente.nome);
                gotoxy(0,9);
                printf("CPF: %s\n",paciente.cpf);
                gotoxy(0,10);
                printf("-------------------------------------------------\n");
            }
            else
            {
                fwrite(&paciente,sizeof(PACIENTE),1,temp);//gravando os dados no arquivo temp
            }            
        }
        fclose(arq);//fechar o arq
        fclose(temp);//fechar o temp
        fflush(stdin);
        gotoxy(0,15);
        printf("Deseja deletar (s/n)? ");
        if(getche()=='s')
        {
            if(remove("pacientes.bin")==0&&rename("tmp_pct.bin","pacientes.bin")==0) //verifica se as operacoes foram realizadas com sucesso!
            {
                printf("\nOperacao realizada com sucesso!");
                system("pause > null"); 
            }
            else
            {
                remove("tmp_pct.bin");//remover o arquivo tmp se a condicao foi "n" na hora de deletar
                printf("\nPaciente nao foi removido!");
                system("pause > null");  
            }
        }
        fclose(temp);
        fclose(arq);
        getch();
    }
}
void ListarPacientes(){
    PACIENTE paciente;
    int opcao,x;
    FILE* arquivo;

    char cpf[13];   
    system("cls");

    arquivo = fopen("pacientes.bin","rb");  // leitura 
    if(arquivo == NULL){
        printf("<ERRO!> Problema na abertura do arquivo!\n");
    }else{
        fflush(stdin);
        printf("Digite o CPF do paciente que deseja procurar: ");
        gets(cpf);
        while(fread(&paciente, sizeof(PACIENTE),1,arquivo)==1){
            if(strcmp(cpf,paciente.cpf)==0)
            {
                gotoxy(0,8);
                printf("Nome: %s\n",paciente.nome);
                gotoxy(0,9);
                printf("Idade: %s\n",paciente.idade);
                gotoxy(0,10);
                printf("CPF: %s\n",paciente.cpf);
                gotoxy(0,11);
                printf("Telefone: %s\n",paciente.telefone);
                printf("-------------------------------------------------\n");
            }
        }
        fclose(arquivo);
        system("pause > null");
    }
}
#endif
