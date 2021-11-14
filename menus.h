#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

void SelecionarMenuPrincipal(){
    int Opcao;
    do{
        desenhaJanela();
        dicaDeTela("Digite um numero correspondente a opcao desejada ou 0 (ZERO) para SAIR");
        desenha(24,5,100,20);
        gotoxy(26,5);
        printf(" MENU ");
        gotoxy(26,7);
        printf("1 - Gerenciar Pacientes");
        gotoxy(26,8);
        printf("2 - Funcionarios");
        gotoxy(26,9);
        printf("3 - Agenda");//Talvez algo relacionado a Agendamentos
        gotoxy(26,10);
        printf("4 - Consultar Prontuarios");
        gotoxy(26,11);
        printf("5 - Sem ideias");
        gotoxy(26,12);
        printf("0 - Sair");
        gotoxy(24,20);
        printf("Selecione qual o tipo de operacao deseja realizar: ");
        scanf("%d",&Opcao);
        switch (Opcao){
            case 0:
                system("cls");
                gotoxy(0,0);
                printf("ENCERRADO!");
                system("pause > NULL");
                break;
            case 1:
                menuPacientes();
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
        }        
    }while (Opcao != 0);
}

void menuPacientes()
{
    system("cls");
    sleep(1);
    int opcao;
    do
    {
        desenhaJanela();
        dicaDeTela("Digite um numero correspondente a opcao desejada ou 0 (ZERO) para SAIR");
        desenha(24,5,100,20);
        gotoxy(26,5);
        printf(" MENU PACIENTES ");
        gotoxy(26,6);
        printf(" 1 - Cadastrar Paciente");
        gotoxy(26,7);
        printf(" 2 - Remover Paciente");
        gotoxy(26,8);
        printf(" 0 - Voltar");

        gotoxy(24,20);
        printf("Selecione qual o tipo de operacao deseja realizar: ");
        scanf("%d",&opcao);

        switch (opcao)
        {
        case 0:
            system("cls");
            sleep(1);
            break;
        case 1:
            CadastrarPaciente();
        case 2:
            break;

        case 3:
            break;
        }
    }
    while (opcao !=0);
}


#endif // DEBUG