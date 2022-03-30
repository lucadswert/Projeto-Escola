#ifndef MENUS_FILE_H
#define MENUS_FILE_H

char menuPrincipal( ){
    char resposta[3];
    enum MENU{ Realizar_Cadastro = '1', Atualizar_Cadastro = '2',
               Listar_Informacoes = '3', Matricular_Aluno = '4',
               Filtro_por_palavra_chave = '5', Encerrar_Programa = '0'};

    do{
        printf( "=====================================\n"
                "            PROJETO ESCOLA           \n"
                "=====================================\n"
                "MENU PRINCIPAL\n"
                "[1] | Cadastrar\n"
                "[2] | Atualizar\n"
                "[3] | Listar \n"
                "[4] | Matricular\n"
                "[5] | Buscar por palavra chave\n"
                "[0] | Encerrar \n\n-> " );
        fgets(resposta, 3, stdin );
        if( !(resposta[0] == Realizar_Cadastro) && !(resposta[0] == Atualizar_Cadastro) &&
            !(resposta[0] == Listar_Informacoes) && !(resposta[0] == Matricular_Aluno) &&
            !(resposta[0] == Encerrar_Programa) && !(resposta[0] == Filtro_por_palavra_chave ) ){
            puts( "   > Valor inserido inv�lido <\n" );
        }else putchar('\n'); ///MELHORAR
    }while( !(resposta[0] == Realizar_Cadastro) && !(resposta[0] == Atualizar_Cadastro) &&
            !(resposta[0] == Listar_Informacoes) && !(resposta[0] == Matricular_Aluno) &&
            !(resposta[0] == Encerrar_Programa) && !(resposta[0] == Filtro_por_palavra_chave ) );

    return resposta[0];
}
char menuCadastrar( ){
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
            puts( "   > Valor inserido inv�lido < \n" );
        }else putchar('\n');
    }while( !(resposta[0] == Professor) && !(resposta[0] == Aluno) &&
            !(resposta[0] == Disciplina) && !(resposta[0] == Voltar) );

    return resposta[0];
}

char menuListar( ){
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
            puts("   > Valor inserido inv�lido <\n");
        }else putchar('\n');
    }while( !(resposta[0] == Professor) && !(resposta[0] == Aluno) &&
            !(resposta[0] == Disciplina) && !(resposta[0] == Aniversariantes) &&
            !(resposta[0] == Voltar) );

    return resposta[0];
}
char menuAtualizar( ){
    char resposta[3];
    enum MENU { Aluno = '1', Professor = '2', Disciplina = '3', Voltar = '0'};

    do{
        printf( "=====================================\n"
                "             MENU ATUALIZAR          \n"
                "=====================================\n"
                "ATUALIZAR: \n"
                "[1] | Aluno\n"
                "[2] | Professor\n"
                "[3] | Disciplina\n"
                "[0] | Voltar\n\n-> " );
        fgets(resposta, 3, stdin );
        if( !(resposta[0] == Professor) && !(resposta[0] == Aluno) &&
            !(resposta[0] == Disciplina) && !(resposta[0] == Voltar)){
            puts("   > Valor inserido inv�lido <\n");
        }else putchar('\n');
    }while( !(resposta[0] == Professor) && !(resposta[0] == Aluno) &&
            !(resposta[0] == Disciplina) && !(resposta[0] == Voltar) );

    return resposta[0];
}
char subMenuTipoDeAtualizacao( ){
    char resposta[3];
    enum MENU { MODIFICAR = '1', EXCLUIR = '2', Voltar = '0'};

    do{
        printf( "TIPO: \n"
                "[1] | MODIFICA��O\n"
                "[2] | EXCLUS�O\n"
                "[0] | Voltar\n\n-> " );
        fgets(resposta, 3, stdin );
        if( !(resposta[0] == MODIFICAR ) && !(resposta[0] == EXCLUIR) &&
            !(resposta[0] == Voltar) ){
            puts("   > Valor inserido inv�lido <\n");
        }else putchar('\n');
    }while( !(resposta[0] == MODIFICAR ) && !(resposta[0] == EXCLUIR) &&
            !(resposta[0] == Voltar) );

    return resposta[0];
}
char subMenuTipoDeAtualizacaoGrade( ){
    char resposta[3];
    enum MENU{ MATRICULAR  = '1', DESMATRICULAR = '2', Voltar = '0'};;

    do{
        printf( "TIPO: \n"
                "[1] | MATRICULAR\n"
                "[2] | DESMATRICULAR\n"
                "[0] | Voltar\n\n-> " );
        fgets(resposta, 3, stdin );
        if( !(resposta[0] == MATRICULAR ) && !(resposta[0] == DESMATRICULAR ) &&
            !(resposta[0] == Voltar) ){
            puts("   > Valor inserido inv�lido <\n");
        }else putchar('\n');
    }while( !(resposta[0] == MATRICULAR ) && !(resposta[0] == DESMATRICULAR ) &&
            !(resposta[0] == Voltar ) );

    return resposta[0];
}
char subMenuEscolhaDeDado_1( ){
    char resposta[3];
    enum MENU { CPF = '1', NOME = '2', MATRICULA = '3',
                NASCIMENTO = '4', SEXO = '5', GRADE = '6',
                Tudo = '7', Voltar = '0'};

    do{
        printf(
                "ATUALIZAR: \n"
                "[1] | CPF\n"
                "[2] | NOME\n"
                "[3] | MATRICULA\n"
                "[4] | NASCIMENTO\n"
                "[5] | SEXO\n"
                "[6] | GRADE\n"
                "[7] | TUDO\n"
                "[0] | Voltar\n\n-> " );
        fgets(resposta, 3, stdin );
        if( !(resposta[0] == CPF ) && !(resposta[0] == NOME) &&
            !(resposta[0] == MATRICULA ) && !(resposta[0] == NASCIMENTO) &&
            !(resposta[0] == SEXO ) && !(resposta[0] == GRADE) &&
            !(resposta[0] == Tudo ) && !(resposta[0] == Voltar) ){
            puts("   > Valor inserido inv�lido <\n");
        }else putchar('\n');
    }while( !(resposta[0] == CPF ) && !(resposta[0] == NOME) &&
            !(resposta[0] == MATRICULA ) && !(resposta[0] == NASCIMENTO) &&
            !(resposta[0] == SEXO ) && !(resposta[0] == GRADE) &&
            !(resposta[0] == Tudo ) && !(resposta[0] == Voltar) );

    return resposta[0];
}
char subMenuEscolhaDeDado_2( ){
    char resposta[3];
    enum MENU { CODIGO = '1', NOME = '2', SEMESTRE = '3',
                VAGAS = '4', PROFESSOR = '5', Tudo = '6',
                Voltar = '0' };

    do{
        printf(
                "ATUALIZAR: \n"
                "[1] | C�DIGO\n"
                "[2] | NOME\n"
                "[3] | SEMESTRE\n"
                "[4] | VAGAS\n"
                "[5] | PROFESSOR\n"
                "[6] | TUDO\n"
                "[0] | Voltar\n\n-> " );
        fgets(resposta, 3, stdin );
        if( !(resposta[0] == CODIGO ) && !(resposta[0] == NOME) &&
            !(resposta[0] == SEMESTRE ) && !(resposta[0] == VAGAS ) &&
            !(resposta[0] == PROFESSOR ) && !(resposta[0] == Voltar) &&
            !(resposta[0] == Tudo ) ){
            puts("   > Valor inserido inv�lido <\n");
        }else putchar('\n');
    }while( !(resposta[0] == CODIGO ) && !(resposta[0] == NOME) &&
            !(resposta[0] == SEMESTRE ) && !(resposta[0] == VAGAS ) &&
            !(resposta[0] == PROFESSOR ) && !(resposta[0] == Voltar) &&
            !(resposta[0] == Tudo ) );

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
            puts("   > Valor inserido inv�lido <\n");
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
            puts("   > Valor inserido inv�lido <\n");
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
                "[2] | Matriculados \n"
                "[3] | Vagas\n"
                "[0] | Voltar \n\n-> ");
        fgets(resposta, 3, stdin );
        if( !(resposta[0] == Filtro_Geral) && !(resposta[0] == Filtro_Disciplina) &&
            !(resposta[0] == Filtro_Vagas) && !(resposta[0] == Encerrar_Programa)){
            puts("   > Valor inserido inv�lido <\n");
        }else putchar('\n');
    }while( !(resposta[0] == Filtro_Geral) && !(resposta[0] == Filtro_Disciplina) &&
            !(resposta[0] == Filtro_Vagas) && !(resposta[0] == Encerrar_Programa));

    return resposta[0];
}

#endif ///MENUS_FILE_H
