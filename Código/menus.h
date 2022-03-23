#ifndef MENUS_FILE_H
#define MENUS_FILE_H

int menuCadastrar( ){
    char resposta[3];
    enum MENU { Aluno = '1', Professor = '2', Disciplina = '3', Voltar = '0'};
    
    do{
        printf( "=====================================\n"
                "             MENU CADASTRO           \n"
                "=====================================\n"
                "CADASTRAR: \n"	
                "[1] | Aluno\n"
                "[2] | Professor\n"
                "[3] | Disciplina\n"
                "[0] | Voltar\n\n-> ");
        fgets(resposta, 3, stdin );
        if( !(resposta[0] == Professor) && !(resposta[0] == Aluno) && 
            !(resposta[0] == Disciplina) && !(resposta[0] == Voltar) ){
            puts( "   > Valor inserido inválido < \n" );
        }else putchar('\n');
    }while( !(resposta[0] == Professor) && !(resposta[0] == Aluno) && 
            !(resposta[0] == Disciplina) && !(resposta[0] == Voltar) );    
    
    return resposta[0];
}

int menuListar( ){
    char resposta[3];
    enum MENU { Aluno = '1', Professor = '2', Disciplina = '3', 
                Aniversariantes = '4', Voltar = '0'};

    do{
        printf( "=====================================\n"
                "             MENU LISTAS             \n"
                "=====================================\n"
                "LISTAR: \n"	
                "[1] | Aluno\n"
                "[2] | Professor\n"
                "[3] | Disciplina\n"	
                "[4] | Aniversariantes\n"	
                "[0] | Voltar\n\n-> " );
        fgets(resposta, 3, stdin );
        if( !(resposta[0] == Professor) && !(resposta[0] == Aluno) &&
            !(resposta[0] == Disciplina) && !(resposta[0] == Aniversariantes) && 
            !(resposta[0] == Voltar)){
            puts("   > Valor inserido inválido <\n");
        }else putchar('\n');
    }while( !(resposta[0] == Professor) && !(resposta[0] == Aluno) && 
            !(resposta[0] == Disciplina) && !(resposta[0] == Aniversariantes) &&
            !(resposta[0] == Voltar) );

    return resposta[0];
}
int menuPrincipal( ){
  char resposta[3];
  enum MENU{ Realizar_Cadastro = '1', Listar_Informações = '2',
             Matricular_Aluno = '3', Filtro_por_palavra_chave = '4', 
             Encerrar_Programa = '0'};
    
    do{
        printf( "=====================================\n"
                "            PROJETO ESCOLA           \n"
                "=====================================\n"
                "MENU PRINCIPAL\n"
                "[1] | Cadastrar\n"
                "[2] | Listar \n"
                "[3] | Matricular\n"
                "[4] | Buscar por palavra chave\n"
                "[0] | Encerrar \n\n-> " );
        fgets(resposta, 3, stdin ); 
        if( !(resposta[0] == Realizar_Cadastro) && !(resposta[0] == Listar_Informações) && 
            !(resposta[0] == Matricular_Aluno) && !(resposta[0] == Encerrar_Programa) &&
            !(resposta[0] == Filtro_por_palavra_chave ) ){
            puts("   > Valor inserido inválido <\n" );
        }else putchar('\n'); ///MELHORAR
    }while( !(resposta[0] == Realizar_Cadastro) && !(resposta[0] == Listar_Informações) && 
            !(resposta[0] == Matricular_Aluno) && !(resposta[0] == Encerrar_Programa) && 
            !(resposta[0] == Filtro_por_palavra_chave ) );

    return resposta[0];
}

int menuListarProfessor( ){
    char resposta[3];
    enum MENU{ Filtro_Geral = '1', Filtro_Sexo = '2', Filtro_Nome = '3',
               Filtro_Nascimento = '4', Filtro_por_tamanho_de_grade = '5',
               Filtro_por_palavra_chave = '6', Encerrar_Programa = '0'};
    
    do{
        printf( "=====================================\n"
                "          LISTA DE PROFESSORES       \n"
                "=====================================\n"
                "\nORDENAR POR:\n"
                "[1] | Geral\n"
                "[2] | Sexo \n"
                "[3] | Nome\n"
                "[4] | Nascimento\n\n"
                "FILTRAR POR:\n"
                "[5] | Tamanho da Grade\n"
                "[6] | Por palavra chave\n\n"
                "[0] | Voltar \n\n-> ");
        fgets(resposta, 3, stdin );  
        if( !(resposta[0] == Filtro_Geral) && !(resposta[0] == Filtro_Sexo) &&
            !(resposta[0] == Filtro_Nome) && !(resposta[0] == Filtro_Nascimento) && 
            !(resposta[0] == Filtro_por_tamanho_de_grade ) && !(resposta[0] == Encerrar_Programa) && 
            !( resposta[0] == Filtro_por_palavra_chave ) ){
            puts("   > Valor inserido inválido <\n");
        }else putchar('\n');///MELHORAR
    }while( !(resposta[0] == Filtro_Geral) && !(resposta[0] == Filtro_Sexo) && 
            !(resposta[0] == Filtro_Nome) && !(resposta[0] == Filtro_Nascimento) && 
            !(resposta[0] == Filtro_por_tamanho_de_grade ) && !(resposta[0] == Encerrar_Programa) && 
            !(resposta[0] == Filtro_por_palavra_chave ) );
    return resposta[0];
}

int menuListarAluno( ){
  char resposta[3];
  enum MENU{ Filtro_Geral = '1', Filtro_Sexo = '2', Filtro_Nome = '3',
             Filtro_Nascimento = '4', Filtro_por_tamanho_de_grade = '5',
             Filtro_por_palavra_chave = '6', Encerrar_Programa = '0'};
    
    do{
        printf( "=====================================\n"
                "            LISTA DE ALUNOS          \n"
                "=====================================\n"
                "\nORDENAR POR:\n"
                "[1] | Geral\n"
                "[2] | Sexo \n"
                "[3] | Nome\n"
                "[4] | Nascimento\n\n"
                "FILTRAR POR:\n"
                "[5] | Tamanho da Grade\n"
                "[6] | Por palavra chave\n\n"
                "[0] | Voltar \n\n-> ");
        fgets(resposta, 3, stdin );  
        if( !(resposta[0] == Filtro_Geral) && !(resposta[0] == Filtro_Sexo) && 
            !(resposta[0] == Filtro_Nome) && !(resposta[0] == Filtro_Nascimento) && 
            !(resposta[0] == Filtro_por_tamanho_de_grade ) && !(resposta[0] == Encerrar_Programa) && 
            !( resposta[0] == Filtro_por_palavra_chave ) ){
            puts("   > Valor inserido inválido <\n");
        }else putchar('\n');
    }while( !(resposta[0] == Filtro_Geral) && !(resposta[0] == Filtro_Sexo) &&
            !(resposta[0] == Filtro_Nome) && !(resposta[0] == Filtro_Nascimento) &&
            !(resposta[0] == Filtro_por_tamanho_de_grade ) && !(resposta[0] == Encerrar_Programa) && 
            !( resposta[0] == Filtro_por_palavra_chave ) );

    return resposta[0];
}

int menuListarDisciplinas( ){
  char resposta[3];
  enum MENU{ Filtro_Geral = '1', Filtro_Disciplina = '2', Filtro_Vagas = '3', Encerrar_Programa = '0'};
    
    do{
        printf( "=====================================\n"
                "          LISTA DE DISCIPLINAS       \n"
                "=====================================\n"
                "\nFILTRAR POR:\n"
                "[1] | Geral\n"
                "[2] | Disciplina \n"
                "[3] | Vagas\n"
                "[0] | Voltar \n\n-> ");
        fgets(resposta, 3, stdin );  
        if( !(resposta[0] == Filtro_Geral) && !(resposta[0] == Filtro_Disciplina) &&
            !(resposta[0] == Filtro_Vagas) && !(resposta[0] == Encerrar_Programa)){
            puts("   > Valor inserido inválido <\n");
        }else putchar('\n');
    }while( !(resposta[0] == Filtro_Geral) && !(resposta[0] == Filtro_Disciplina) && 
            !(resposta[0] == Filtro_Vagas) && !(resposta[0] == Encerrar_Programa));
  
    return resposta[0];
}

#endif ///MENUS_FILE_H
