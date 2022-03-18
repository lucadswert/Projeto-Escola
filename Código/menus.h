#ifndef MENUS_FILE_H
#define MENUS_FILE_H

int menuCadastrar( ){
    char resposta[3];
   
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
        fgets(resposta, 3, stdin );
        if( !(resposta[0] == Professor) && !(resposta[0] == Aluno) && !(resposta[0] == Disciplina) && !(resposta[0] == Voltar) ){
            puts("   ^ Valor inserido inválido! \n");
        }else putchar('\n');
    }while( !(resposta[0] == Professor) && !(resposta[0] == Aluno) && !(resposta[0] == Disciplina) && !(resposta[0] == Voltar) );    
    
    return resposta[0];
}

int menuListar( ){
    char resposta[3];
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
        fgets(resposta, 3, stdin );
        if( !(resposta[0] == Professor) && !(resposta[0] == Aluno) && !(resposta[0] == Disciplina) && !(resposta[0] == Voltar)){
             puts("   ^ Valor inserido inválido! \n");
        }else putchar('\n');
    }while( !(resposta[0] == Professor) && !(resposta[0] == Aluno) && !(resposta[0] == Disciplina) && !(resposta[0] == Voltar) );

    return resposta[0];
    
}
int menuPrincipal( ){
  char resposta[3];
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
            fgets(resposta, 3, stdin ); 
            if( !(resposta[0] == Realizar_Cadastro) && !(resposta[0] == Listar_Informações) && !(resposta[0] == Matricular_Aluno) && !(resposta[0] == Encerrar_Programa)){
            }else putchar('\n');
        }while( !(resposta[0] == Realizar_Cadastro) && !(resposta[0] == Listar_Informações) && !(resposta[0] == Matricular_Aluno) && !(resposta[0] == Encerrar_Programa));

    return resposta[0];
}

int menuListarProfessor( ){
    char resposta[3];
    enum MENU{ Filtro_Geral = '1', Filtro_Sexo = '2', Filtro_Nome = '3', Filtro_Nascimento = '4', Filtro_Buscar = '5', Filtro_Aniversario = '6', Encerrar_Programa = '0'};
    
    do{
            puts( "=====================================\n"
                  "          LISTA DE PROFESSORES       \n"
                  "=====================================\n"
                    "\nFILTROS:\n"
                    "[1] | Geral\n"
                    "[2] | Sexo \n"
                    "[3] | Nome\n"
                    "[4] | Nascimento\n"
                    "[5] | Buscar\n"
                    "[6] | Aniversariantes\n"
                    "[0] | Voltar \n\n-> ");
            fgets(resposta, 3, stdin );  
            if( !(resposta[0] == Filtro_Geral) && !(resposta[0] == Filtro_Sexo) && !(resposta[0] == Filtro_Nome) && !(resposta[0] == Filtro_Nascimento) && !(resposta[0] == Filtro_Buscar) && !(resposta[0] == Filtro_Aniversario) && !(resposta[0] == Encerrar_Programa)){
            }else putchar('\n');
        }while( !(resposta[0] == Filtro_Geral) && !(resposta[0] == Filtro_Sexo) && !(resposta[0] == Filtro_Nome) && !(resposta[0] == Filtro_Nascimento) && !(resposta[0] == Filtro_Buscar) && !(resposta[0] == Filtro_Aniversario) && !(resposta[0] == Encerrar_Programa));
    return resposta[0];
}

int menuListarAluno( ){
  char resposta[3];
  enum MENU{ Filtro_Geral = '1', Filtro_Sexo = '2', Filtro_Nome = '3', Filtro_Nascimento = '4', Filtro_Buscar = '5', Filtro_Aniversario = '6', Encerrar_Programa = '0'};
    
    do{
            puts( "=====================================\n"
                  "            LISTA DE ALUNOS          \n"
                  "=====================================\n");
            printf ("\nFILTROS:\n"
                    "[1] | Geral\n"
                    "[2] | Sexo \n"
                    "[3] | Nome\n"
                    "[4] | Nascimento\n"
                    "[5] | Buscar\n"
                    "[6] | Aniversariantes\n"
                    "[0] | Voltar \n\n-> ");
            fgets(resposta, 3, stdin );  
            if( !(resposta[0] == Filtro_Geral) && !(resposta[0] == Filtro_Sexo) && !(resposta[0] == Filtro_Nome) && !(resposta[0] == Filtro_Nascimento) && !(resposta[0] == Filtro_Buscar) && !(resposta[0] == Filtro_Aniversario) && !(resposta[0] == Encerrar_Programa)){
            }else putchar('\n');
        }while( !(resposta[0] == Filtro_Geral) && !(resposta[0] == Filtro_Sexo) && !(resposta[0] == Filtro_Nome) && !(resposta[0] == Filtro_Nascimento) && !(resposta[0] == Filtro_Buscar) && !(resposta[0] == Filtro_Aniversario) && !(resposta[0] == Encerrar_Programa));
  
    return resposta[0];
}

int menuListarDisciplinas(){
  char resposta[3];
  enum MENU{ Filtro_Geral = '1', Filtro_SemAluno = '2', Filtro_Disciplina = '3', Filtro_Vagas = '4', Encerrar_Programa = '0'};
    
    do{
            puts( "=====================================\n"
                  "          LISTA DE DISCIPLINAS       \n"
                  "=====================================\n");
            printf ("\nFILTROS:\n"
                    "[1] | Geral\n"
                    "[2] | Uma disciplina \n"
                    "[3] | Menos de 3 Disciplinas \n"
                    "[4] | Mais de 40 Vagas\n"
                    "[0] | Voltar \n\n-> ");
            fgets(resposta, 3, stdin );  
            if( !(resposta[0] == Filtro_Geral) && !(resposta[0] == Filtro_Disciplina) && !(resposta[0] == Filtro_Vagas) && !(resposta[0] == Filtro_SemAluno) && !(resposta[0] == Encerrar_Programa)){
            }else putchar('\n');
        }while( !(resposta[0] == Filtro_Geral) && !(resposta[0] == Filtro_Disciplina) && !(resposta[0] == Filtro_Vagas) && !(resposta[0] == Filtro_SemAluno) && !(resposta[0] == Encerrar_Programa));
  
    return resposta[0];
}

#endif ///MENUS_FILE_H
