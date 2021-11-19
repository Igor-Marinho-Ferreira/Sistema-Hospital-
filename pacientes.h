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

typedef struct prontuario PRONTUARIO;
struct prontuario
{
    char nome[50];
    char evolucaom[500];
    char evolucaoe[500];
    char exames[500];
    char raciocinio[500];
    char hipoteses[500];
    char diagnostico[500];
    char prescricoes[500];
    char resumo[500];
    char cpf[13];
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
    PRONTUARIO prontuario;
    int opcao,x;
    FILE* arquivo;
    FILE* arquivo1;

    char cpf[13];   
    system("cls");

    arquivo = fopen("pacientes.bin","rb");
    arquivo1 = fopen("prontuario.bin","rb");  // leitura 

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
            }
        }
        fclose(arquivo);
        while(fread(&prontuario, sizeof(PRONTUARIO),1,arquivo1)==1){
            if(strcmp(cpf,prontuario.cpf)==0){
                printf("-------------------------------Prontuario-------------------------------\n");
                gotoxy(0,12);
                printf("Evolução medica diaria: %s\n",prontuario.evolucaom);
                gotoxy(0,13);
                printf("Evolução de enfermagem diaria: %s\n",prontuario.evolucaoe);
                gotoxy(0,14);
                printf("Exames: %s\n",prontuario.exames);
                gotoxy(0,15);
                printf("Raciocinio medico: %s\n",prontuario.raciocinio);
                gotoxy(0,16);
                printf("Hipoteses diagnosticas: %s\n",prontuario.hipoteses);
                gotoxy(0,17);
                printf("Diagnostico definitivo: %s\n",prontuario.diagnostico);
                gotoxy(0,18);
                printf("Prescriçoes medicas: %s\n",prontuario.prescricoes);
                gotoxy(0,19);
                printf("Resumo de alta: %s\n",prontuario.resumo);
                gotoxy(0,20);
                printf("------------------------------------------------------------------------\n");    
            }
        }
        fclose(arquivo1);
        system("pause > null");
    }
}
void CriarProntuario(){
    PRONTUARIO prontuario;
    int opcao;
    FILE* arquivo;


    arquivo = fopen("prontuario.bin","ab");  // escrita e binario
    if(arquivo == NULL)
    {
        printf("<ERRO!> Problema na abertura do arquivo!\n");

    }else
        do{
            system("cls");
            fflush(stdin);
            desenha(24,5,100,20);
            gotoxy(26,5);
            printf(" CRIAR PRONTUARIO ");
            gotoxy(26,7);
            printf("Indentificacao do paciente: ");
            gotoxy(26,8);
            printf("CPF: ");
            gotoxy(26,9);
            printf("Evolucao medica diaria: ");
            gotoxy(26,10);
            printf("Evolucao de enfermagem diaria: ");
            gotoxy(26,11);
            printf("Exames: ");
            gotoxy(26,12);
            printf("Raciocinio medico: ");
            gotoxy(26,13);
            printf("Hipoteses diagnosticas: ");
            gotoxy(26,14);
            printf("Diagnostico definitivo: ");
            gotoxy(26,15);
            printf("Prescricoes medicas: ");
            gotoxy(26,16);
            printf("Resumo de alta: ");

            gotoxy(55,7);
            fflush(stdin);
            pegaLetraeDigito(prontuario.nome);
            if (strcmp(prontuario.nome,"")==0)break; 
            
            gotoxy(55,8);
            fflush(stdin);
            pegaLetraeDigito(prontuario.cpf);
            if (strcmp(prontuario.cpf,"")==0)break; 

            gotoxy(55,9);
            fflush(stdin);
            pegaLetraeDigito(prontuario.evolucaom);
            if (strcmp(prontuario.evolucaom,"")==0)break; 

            gotoxy(55,10);
            fflush(stdin);
            pegaLetraeDigito(prontuario.evolucaoe);
            if (strcmp(prontuario.evolucaoe,"")==0)break; 

            gotoxy(45,11);
            fflush(stdin);
            pegaLetraeDigito(prontuario.exames);
            if (strcmp(prontuario.exames,"")==0)break; 

            gotoxy(55,12);
            fflush(stdin);
            pegaLetraeDigito(prontuario.raciocinio);
            if (strcmp(prontuario.raciocinio,"")==0)break; 

            gotoxy(55,13);
            fflush(stdin);
            pegaLetraeDigito(prontuario.hipoteses);
            if (strcmp(prontuario.hipoteses,"")==0)break; 

            gotoxy(55,14);
            fflush(stdin);
            pegaLetraeDigito(prontuario.diagnostico);
            if (strcmp(prontuario.diagnostico,"")==0)break; 

            gotoxy(55,15);
            fflush(stdin);
            pegaLetraeDigito(prontuario.prescricoes);
            if (strcmp(prontuario.prescricoes,"")==0)break; 

            gotoxy(55,16);
            fflush(stdin);
            pegaLetraeDigito(prontuario.resumo);
            if (strcmp(prontuario.resumo,"")==0)break; 
        {
            fwrite(&prontuario, sizeof(PRONTUARIO),1,arquivo);
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

#endif
