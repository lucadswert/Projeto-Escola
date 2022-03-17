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
  enum MENU{ Realizar_Cadastro = '1', Listar_Informações = '2', Matricular_Aluno = '3', Encerrar_Programa = '0'};
    
    do{
            puts( "=====================================\n"
                  "            PROJETO ESCOLA           \n"
                  "=====================================\n");
            printf ("MENU PRINCIPAL\n"
                    "[1] | Cadastrar\n"
                    "[2] | Listar \n"
                    "[3] | Matricular\n"
                    "[0] | Encerrar \n\n-> ");
            resposta = getchar( ); getchar( ); 
            if( !(resposta == Realizar_Cadastro) && !(resposta == Listar_Informações) && !(resposta == Encerrar_Programa) && !(resposta == Matricular_Aluno)){
            }else putchar('\n');
        }while( !(resposta == Realizar_Cadastro) && !(resposta == Listar_Informações) &&  !(resposta == Encerrar_Programa) && !(resposta == Matricular_Aluno));
    return resposta;
}

int menuListarProfessor( ){
    char resposta = '\0';
    enum MENU{ Filtro_Geral = '1', Filtro_Sexo = '2', Filtro_Nome = '3', Filtro_Nascimento = '4', Filtro_Buscar = '5', Filtro_Aniversario = '6', Encerrar_Programa = '0'};
    
    do{
            puts( "=====================================\n"
                  "          LISTA DE PROFESSORES       \n"
                  "=====================================\n"
                  "Filtros:\n"
                    "[1] | Geral\n"
                    "[2] | Sexo \n"
                    "[3] | Nome\n"
                    "[4] | Nascimento\n"
                    "[5] | Buscar\n"
                    "[6] | Aniversariantes\n"
                    "[0] | Voltar \n\n-> ");
            resposta = getchar( ); getchar( ); 
            if( !(resposta == Filtro_Geral) && !(resposta == Filtro_Sexo) && !(resposta == Filtro_Nome) && !(resposta == Filtro_Nascimento) && !(resposta == Filtro_Buscar) && !(resposta == Filtro_Aniversario) && !(resposta == Encerrar_Programa)){
            }else putchar('\n');
        }while( !(resposta == Filtro_Geral) && !(resposta == Filtro_Sexo) && !(resposta == Filtro_Nome) && !(resposta == Filtro_Nascimento) && !(resposta == Filtro_Buscar) && !(resposta == Filtro_Aniversario) && !(resposta == Encerrar_Programa));
    return resposta;
}

int menuListarAluno( ){
  char resposta = '\0';
  enum MENU{ Filtro_Geral = '1', Filtro_Sexo = '2', Filtro_Nome = '3', Filtro_Nascimento = '4', Filtro_Buscar = '5', Filtro_Aniversario = '6', Encerrar_Programa = '0'};
    
    do{
            puts( "=====================================\n"
                  "            LISTA DE ALUNOS          \n"
                  "=====================================\n");
            printf ("FILTROS:\n"
                    "[1] | Geral\n"
                    "[2] | Sexo \n"
                    "[3] | Nome\n"
                    "[4] | Nascimento\n"
                    "[5] | Buscar\n"
                    "[6] | Aniversariantes\n"
                    "[0] | Voltar \n\n-> ");
            resposta = getchar( ); getchar( ); 
            if( !(resposta == Filtro_Geral) && !(resposta == Filtro_Sexo) && !(resposta == Filtro_Nome) && !(resposta == Filtro_Nascimento) && !(resposta == Filtro_Buscar) && !(resposta == Filtro_Aniversario) && !(resposta == Encerrar_Programa)){
            }else putchar('\n');
        }while( !(resposta == Filtro_Geral) && !(resposta == Filtro_Sexo) && !(resposta == Filtro_Nome) && !(resposta == Filtro_Nascimento) && !(resposta == Filtro_Buscar) && !(resposta == Filtro_Aniversario) && !(resposta == Encerrar_Programa));
    return resposta;
}

int menuListarDisciplinas(){
  char resposta = '\0';
  enum MENU{ Filtro_Geral = '1', Filtro_SemAluno = '2', Filtro_Disciplina = '3', Filtro_Vagas = '4', Encerrar_Programa = '0'};
    
    do{
            puts( "=====================================\n"
                  "          LISTA DE DISCIPLINAS       \n"
                  "=====================================\n");
            printf ("FILTROS:\n"
                    "[1] | Geral\n"
                    "[2] | Uma disciplina \n"
                    "[3] | Menos de 3 Disciplinas \n"
                    "[4] | Mais de 40 Vagas\n"
                    "[0] | Voltar \n\n-> ");
            resposta = getchar( ); getchar( ); 
            if( !(resposta == Filtro_Geral) && !(resposta == Filtro_Disciplina) && !(resposta == Filtro_Vagas) && !(resposta == Filtro_SemAluno) && !(resposta == Encerrar_Programa)){
            }else putchar('\n');
        }while( !(resposta == Filtro_Geral) && !(resposta == Filtro_Disciplina) && !(resposta == Filtro_Vagas) && !(resposta == Filtro_SemAluno) && !(resposta == Encerrar_Programa));
    return resposta;
}

#endif ///MENUS_FILE_H
