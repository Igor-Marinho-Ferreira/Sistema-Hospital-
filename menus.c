#include <stdio.h>
#include <stdlib.h>
#include "menus.h"

void Exibir_SelecionarOpcao(int *Opcao){ // Exibir texto para selecionar uma opção no menu
    printf("\n\n\t\t\tSelecione qual o tipo de operacao deseja realizar");
    printf("\n\n\t\t\t\t\t");
    scanf("%d",Opcao);
}

void Exibir_MenuPrincipal(){ // Exibir menu principal
    LimparTela();
    Exibir_Cabecalho();
    printf("\n\t\t\t1- Gerenciar Medicos");
    printf("\n\t\t\t2- Gerenciar Pacientes");
    printf("\n\t\t\t3- Gerenciar Agendamentos");
    printf("\n\t\t\t4- Consultar Prontuarios");
    printf("\n\t\t\t5- Ver Consultas Agendadas na Semana");
}

void SelecionarMenuPrincipal(){
    int Opcao;

    Exibir_MenuPrincipal();

    Exibir_SelecionarOpcao(&Opcao);

    switch (Opcao){
        case 1:
            printf("Teste");
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            SelecionarMenuPrincipal();
            break;
    }
}
