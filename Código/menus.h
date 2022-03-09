#ifndef MENUS_FILE_H
#define MENUS_FILE_H

int menuCadastrar( ){
    char resposta = '\0';
    enum MENU { Aluno = '1', Professor = '2', Disciplina = '3', Voltar = '0'};
    
    do{
        puts( "=====================================\n"
              "             MENU CADASTRO           \n"
              "=====================================\n");	
        printf( "CADASTRAR: \n"	
                "[1] | Aluno\n"
                "[2] | Professor\n"
                "[3] | Disciplina\n"
                "[0] | Voltar\n\n-> ");
        resposta = getchar( ); getchar( );
        if( !(resposta == Professor) && !(resposta == Aluno) && !(resposta == Disciplina) && !(resposta == Voltar) ){
                puts("   ^ Valor inserido inválido! \n");
        }else putchar('\n');
    }while( !(resposta == Professor) && !(resposta == Aluno) && !(resposta == Disciplina) && !(resposta == Voltar) );    
    
    return resposta;
}

int menuListar( ){
    char resposta = '\0';
    enum MENU { Aluno = '1', Professor = '2', Disciplina = '3', Voltar = '0'};

    do{
        puts("=====================================\n"
             "             MENU LISTAS             \n"
             "=====================================\n");	
        printf( "LISTAR: \n"	
                "[1] | Aluno\n"
                "[2] | Professor\n"
                "[3] | Disciplina\n"	
                "[0] | Voltar\n\n-> " );
        resposta = getchar( ); getchar( ); 
        if( !(resposta == Professor) && !(resposta == Aluno) && !(resposta == Disciplina) && !(resposta == Voltar)){
             puts("   ^ Valor inserido inválido! \n");
        }else putchar('\n');
    }while( !(resposta == Professor) && !(resposta == Aluno) && !(resposta == Disciplina) && !(resposta == Voltar) );

    return resposta;
    
}
int menuPrincipal( ){
    char resposta = '\0';
    enum MENU{ Realizar_Cadastro = '1', Listar_Informações = '2', Encerrar_Programa = '0'};
    
    do{
            puts( "=====================================\n"
                  "            PROJETO ESCOLA           \n"
                  "=====================================\n");
            printf ("MENU PRINCIPAL\n"
                    "[1] | Cadastrar\n"
                    "[2] | Listar \n"
                    "[0] | Encerrar \n\n-> ");
            resposta = getchar( ); getchar( ); 
            if( !(resposta == Realizar_Cadastro) && !(resposta == Listar_Informações) && !(resposta == Encerrar_Programa) ){
                puts("   ^ Valor inserido inválido! \n");
            }else putchar('\n');
        }while( !(resposta == Realizar_Cadastro) && !(resposta == Listar_Informações) &&  !(resposta == Encerrar_Programa) );
    return resposta;
}



#endif ///MENUS_FILE_H