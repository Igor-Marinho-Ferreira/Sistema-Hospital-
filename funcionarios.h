#ifndef FUNCIONARIOS_H_INCLUDED
#define FUNCIONARIOS_H_INCLUDED

typedef struct funcionario FUNCIONARIO;
struct funcionario
{
    char nome[50];
    char login[30];
    char senha[30];

};
void CadastrarFuncionario(){
    FUNCIONARIO funcionario;
    int opcao;
    FILE* arquivo;
    char confirmarsenha[30];

    arquivo = fopen("funcionarios.bin","ab");
    if(arquivo == NULL)
    {
        printf("<ERRO!> Problema na abertura do arquivo!\n");
    }else
        do{
            system("cls");
            fflush(stdin);
            desenha(24,5,100,20);
            gotoxy(26,5);
            printf(" CADASTRAR FUNCIONARIO ");
            gotoxy(26,7);
            printf("Nome: ");
            gotoxy(26,8);
            printf("Usuario: ");
            gotoxy(26,9);
            printf("Senha: ");
            gotoxy(26,10);
            printf("Confirme a senha: ");

            gotoxy(32,7);
            fflush(stdin);
            pegaLetras(funcionario.nome);
            if (strcmp(funcionario.nome,"")==0)break; 

            gotoxy(36,8);
            fflush(stdin);
            gets(funcionario.login);
            if (strcmp(funcionario.login,"")==0) break; 

            gotoxy(34,9);
            fflush(stdin);
            pegaSenha(funcionario.senha);
            if (strcmp(funcionario.senha,"")==0) break; 

            gotoxy(43,10);
            fflush(stdin);
            pegaSenha(confirmarsenha);
            if (strcmp(confirmarsenha,"")==0) break;//se digitar nada vai sair
            //vai verificar a senha 
            if(strcmp(confirmarsenha,funcionario.senha)==0){
                fwrite(&funcionario, sizeof(FUNCIONARIO),1,arquivo);
                gotoxy(30,20);
                printf(" ---- CADASTRADO COM SUCESSO! DESEJA CONTINUAR CADASTRANDO ? ----- ");
                gotoxy(30,21);
                printf("      0 = NAO      ");
                gotoxy(30,22);
                printf("      1 = SIM      ");
                gotoxy(30,23);        
            }else{
                gotoxy(30,20);
                printf("Senhas não coincidem");
                gotoxy(30,21);
                printf("Digite qualquer tecla para tentar novamente ou 0 para sair: ");
            }
            fflush(stdin);
            scanf("%d",&opcao);
        }
        while(opcao !=0);
        fclose(arquivo);
}

void ListarFuncionario(){
    FUNCIONARIO funcionario;
    int opcao,x;
    FILE* arquivo;
    char login[30]; 
 
    system("cls");

    arquivo = fopen("funcionarios.bin","rb");  // leitura 
    if(arquivo == NULL){
        printf("<ERRO!> Problema na abertura do arquivo!\n");
    }else{
        fflush(stdin);
        printf("Digite o usuario do funcionario que deseja procurar: ");
        gets(login);
        while(fread(&funcionario, sizeof(FUNCIONARIO),1,arquivo)==1){
            if(strcmp(login,funcionario.login)==0)
            {
                gotoxy(0,8);
                printf("Funcionario: %s\n",funcionario.nome);
                printf("-------------------------------------------------\n");
            }
        }
        fclose(arquivo);
        system("pause > null");
    }
}

void RemoverFuncionario(){
    FILE* arq;
    FILE* temp;
    FUNCIONARIO funcionario;
    char login[30];
    arq = fopen("funcionarios.bin","rb"); //abrir em modo rb leitura binaria
    temp = fopen("tmp_func.bin","wb"); //abrir em modo wb ele limpa e grava binario
    system("cls");

    if(arq==NULL&&temp==NULL)
    {
        printf("<ERRO!> Problema na abertura do arquivo!\n");
        getch();
    }else{
        fflush(stdin);
        printf("Digite o usuario do funcionario a deletar: ");
        gets(login);
        while (fread(&funcionario,sizeof(FUNCIONARIO),1,arq)==1)
        {
            if(strcmp(login,funcionario.login)==0)
            {
                gotoxy(0,8);
                printf("Nome: %s\n",funcionario.nome);
                printf("-------------------------------------------------\n");
            }
            else
            {
                fwrite(&funcionario,sizeof(FUNCIONARIO),1,temp);//gravando os dados no arquivo temp
            }            
        }
        fclose(arq);//fechar o arq
        fclose(temp);//fechar o temp
        fflush(stdin);
        gotoxy(0,15);
        printf("Deseja deletar (s/n)? ");
        if(getche()=='s')
        {
            if(remove("funcionarios.bin")==0&&rename("tmp_func.bin","funcionarios.bin")==0) //verifica se as operacoes foram realizadas com sucesso!
            {
                printf("\nOperacao realizada com sucesso!");
                system("pause > null"); 
            }
            else
            {
                remove("tmp_func.bin");//remover o arquivo tmp se a condicao foi "n" na hora de deletar
                printf("\nFuncionario nao foi removido!");
                system("pause > null");  
            }
        }
        fclose(temp);
        fclose(arq);
        getch();
    }    
}
#endif