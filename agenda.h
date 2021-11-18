#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED
        
typedef struct agenda AGENDA;
struct agenda
{
    char nomemedico[50];
    char nomepaciente[50];
    int dia;
    int mes;
    int ano;
};   

void CadastrarAgendamento(){
    AGENDA agenda;
    int opcao;
    FILE* arquivo;

    arquivo = fopen("agenda.bin","ab");
    if(arquivo == NULL)
    {
        printf("<ERRO!> Problema na abertura do arquivo!\n");
    }else
        do{
            system("cls");
            fflush(stdin);
            desenha(24,5,100,20);
            gotoxy(26,5);
            printf(" FAZER AGENDAMENTO ");
            gotoxy(26,7);
            printf("Nome do medico: ");
            gotoxy(26,8);
            printf("Nome do paciente: ");
            gotoxy(26,9);
            printf("Data: ");
            gotoxy(26,10);
            printf("Horario: ");

            gotoxy(42,7);
            fflush(stdin);
            pegaLetras(agenda.nomemedico);
            if (strcmp(agenda.nomemedico,"")==0)break; 

            gotoxy(43,8);
            fflush(stdin);
            pegaLetras(agenda.nomepaciente);
            if (strcmp(agenda.nomepaciente,"")==0) break; 

            gotoxy(36,9);
            fflush(stdin);
            scanf("%d/%d/%d", &agenda.dia,&agenda.mes,&agenda.ano);
        {
            fwrite(&agenda, sizeof(AGENDA),1,arquivo);
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
    while(opcao !=0);
    fclose(arquivo);
}

void ListarAgenda(){
    AGENDA agenda;
    int opcao,x;
    FILE* arquivo;

    int indice =0;  
    system("cls");

    arquivo = fopen("agenda.bin","rb");

    if(arquivo == NULL){
        printf("<ERRO!> Problema na abertura do arquivo!\n");
    }else{
        printf("-------------------------------AGENDA-------------------------------\n\n");
        while(fread(&agenda, sizeof(AGENDA),1,arquivo)==1){
            printf("---------------------------------------------------------------------\n");
            gotoxy(0,x++);
            printf("Nome do medico: %s\n",agenda.nomemedico);
            gotoxy(0,x++);
            printf("Nome do paciente: %s\n",agenda.nomepaciente);
            gotoxy(0,x++);
            printf("Data: %d\n",agenda.dia,agenda.mes,agenda.ano);
            gotoxy(0,x++);
            printf("---------------------------------------------------------------------\n\n"); 
            indice++;
        }
        fclose(arquivo);
        system("pause > null");
    }
}

void RemoverAgenda(){
    AGENDA agenda;
    FILE* temp;
    FILE* arq;
    char nome[40];

    temp = fopen("tmp_pct.bin","wb");
    arq = fopen("agenda.bin","rb");
    system("cls");

    if(arq==NULL&&temp==NULL){
        printf("<ERRO!> Problema na abertura do arquivo!\n");
        getch();
    }else{
        fflush(stdin);
        printf("Digite o nome do paciente a deletar: ");
        gets(nome);
        while (fread(&agenda,sizeof(AGENDA),1,arq)==1)
        {
            if(strcmp(nome,agenda.nomepaciente)==0)
            {
                gotoxy(0,8);
                printf("Nome do paciente: %s\n",agenda.nomepaciente);
                gotoxy(0,9);
                printf("Nome do medico: %s\n",agenda.nomemedico);
                gotoxy(0,10);
                printf("-------------------------------------------------\n");
            }
            else
            {
                fwrite(&agenda,sizeof(AGENDA),1,temp);//gravando os dados no arquivo temp
            }            
        }
        fclose(arq);
        fclose(temp);
        fflush(stdin);
        gotoxy(0,15);
        printf("Deseja deletar (s/n)? ");
        if(getche()=='s')
        {
            if(remove("agenda.bin")==0&&rename("tmp_pct.bin","agenda.bin")==0) //verifica se as operacoes foram realizadas com sucesso!
            {
                printf("\nOperacao realizada com sucesso!");
                system("pause > null"); 
            }
            else
            {
                remove("tmp_pct.bin");//remover o arquivo tmp se a condicao foi "n" na hora de deletar
                printf("\nAgenda nao foi removido!");
                system("pause > null");  
            }
        }
        fclose(temp);
        fclose(arq);
        getch();
    }
}
#endif