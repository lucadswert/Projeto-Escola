#ifndef MATRICULA_FILE_H
#define  MATRICULA_FILE_H
#include "_validar.h"

void matricular( );
void desmatricular( );
bool solicitaCodigoMatricula( char[] );
bool validaCodigoMatricula( char[] );
void ajusteGradeAluno( unsigned, unsigned );
void ajusteGradeProfessor( unsigned, unsigned );

void matricular( ){
    char codigoDeMatricula[TAM_COD_MAT];
    enum VALIDAR{ VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO = VALIDO,
                 ALUNO = VALIDO;

    do{
        printf( "\n====================================\n"
                "||           MATRICULANDO         || \n"
                "====================================\n"
                "- Digite o Codigo de Desmatrícula [matriculaDoAluno/codigoDaDisciplina]\n->");
        DADO = solicitaCodigoMatricula( codigoDeMatricula );
        if( !DADO == INVALIDO ){
            strcpy( &codigoDeMatricula[0], ( caixaAlta( &codigoDeMatricula[0] ) ) );
            int disciplinaId = verificaCodigoDisciplina( &codigoDeMatricula[12] );
            if( disciplinaId != -1 ){
                char matriculaAluno[TAM_MAT - 1];
                strncpy( matriculaAluno, codigoDeMatricula, TAM_MAT - 2 );
                int alunoId = verificaMatriculaAluno( matriculaAluno );
                if( alunoId != -1 ){
                    for( int grade = 0; grade < discente[alunoId].disciplinasCursando; grade++ ){
                        if( discente[alunoId].matrizCurricular[grade] == disciplinaId ){
                                printf("na posicao = %d\n", grade );
                            ALUNO = INVALIDO; break;}}
                    if( ALUNO == VALIDO ){
                        if( discente[alunoId].disciplinasCursando < TAM_MATRIZ ){
                            int vagasRestantes = materia[disciplinaId].vagas - materia[disciplinaId].quantidadeMatriculado;
                            if( vagasRestantes > 0 ){
                                discente[alunoId].matrizCurricular[discente[alunoId].disciplinasCursando++] = disciplinaId;
                                materia[disciplinaId].quantidadeMatriculado++;
                                printf( "%s cadastrado em %s \n", discente[alunoId].dado.nome, materia[disciplinaId].nome );
                                atualizaCadastroDisciplina( disciplinaId );
                                atualizaCadastroAluno( alunoId );
                                break;
                            }else{ puts( "> Não há mais vagas nessa disciplina <" ); }
                        }else{ puts( "> Grade cheia <" ); }
                    }else{ puts( "O aluno já está matriculado nesta disciplina " ); }
                }else{ puts( "> Aluno não cadastrado <" );}
            }else{ puts( "> Disciplina não cadastrada <" );}}
    }while( DADO != INVALIDO || ALUNO != INVALIDO );
}
void desmatricular( ){
    char codigoDeMatricula[TAM_COD_MAT];
    enum VALIDAR{ VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;

    do{
        printf( "\n====================================\n"
                "||         DESMATRICULANDO        || \n"
                "====================================\n"
                "- Digite o Codigo de Matrícula [matriculaDoAluno/codigoDaDisciplina]\n->");
        DADO = solicitaCodigoMatricula( codigoDeMatricula );
        if( !DADO == INVALIDO ){
            strcpy( &codigoDeMatricula[0], ( caixaAlta( &codigoDeMatricula[0] ) ) );
            int disciplinaId = verificaCodigoDisciplina( &codigoDeMatricula[12] );
            if( disciplinaId != -1 ){
                char matriculaAluno[TAM_MAT - 1];
                strncpy( matriculaAluno, codigoDeMatricula, TAM_MAT - 2 );
                int alunoId = verificaMatriculaAluno( matriculaAluno );
                if( alunoId != -1 ){
                    for( int grade = 0; grade < discente[alunoId].disciplinasCursando; grade++ ){
                        if( discente[alunoId].matrizCurricular[grade] == disciplinaId ){
                            ajusteGradeAluno( alunoId, disciplinaId );
                            materia[disciplinaId].quantidadeMatriculado--;
                            printf( "%s não está mais matriculado em %s \n", discente[alunoId].dado.nome, materia[disciplinaId].nome );
                            atualizaCadastroDisciplina( disciplinaId );
                            atualizaCadastroAluno( alunoId );
                            break;
                        }else if( (grade+1) == discente[alunoId].disciplinasCursando ){ puts( "> Aluno não está cadastrado nessa disciplina <\n" ); }
                    }break;
                }else{ puts( "> Aluno não cadastrado <" );}
            }else{ puts( "> Disciplina não cadastrada <" );}}
    }while( DADO != INVALIDO );
}
bool solicitaCodigoMatricula( char codigoDeMatricula[] ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;

    do{
        fgets( codigoDeMatricula, TAM_COD_MAT, stdin );
        if( sair(codigoDeMatricula[0], codigoDeMatricula[1] ) ){
            return false;
        }else{
            limpaTexto( codigoDeMatricula );
            DADO = validaCodigoMatricula( codigoDeMatricula );}
    }while( DADO == INVALIDO );

    return true;
}
bool validaCodigoMatricula( char codigoDeMatricula[] ){
    char matricula[TAM_MAT-1];
    char codigoDisciplina[TAM_COD_DISC];
    char *mensagemDeErro[3];
    int erro = 0;

    strncpy( matricula, codigoDeMatricula, 11  );

    if( !tamanhoCerto( TAM_COD_MAT, codigoDeMatricula ) ){
        mensagemDeErro[erro++] = "> Código inválido <";}

    for( int caracter = 0; codigoDeMatricula[caracter] != '\0'; caracter++ ){
        if( !ehNumero(codigoDeMatricula[caracter]) && !ehLetra(codigoDeMatricula[caracter] ) && codigoDeMatricula[caracter] != '/' ){
             mensagemDeErro[erro++] = "> Caracteres inválidos <";}
        if( codigoDeMatricula[caracter] == '/' && caracter != 11 ){
            puts( "> Código inválido <" );
            return false;}
    }
    if( !validaMatricula( matricula ) ){
        return false;}

    if( !validaCodigo( &codigoDeMatricula[TAM_MAT-1] ) ){
        return false;}

    mensagemDeErro[erro] = NULL;

    if( mensagemDeErro[0] == NULL ){
        return true;
    }else{
        for( int posicao = 0; mensagemDeErro[posicao] != NULL; posicao++ ){

            puts( mensagemDeErro[posicao] );}
        return false;}
}
void ajusteGradeAluno( unsigned id, unsigned apagar ){
    for( int disciplina = apagar; disciplina < discente[id].disciplinasCursando-1; disciplina++ ){
        discente[id].matrizCurricular[disciplina] = discente[id].matrizCurricular[disciplina + 1];}
    discente[id].disciplinasCursando--;
}
void ajusteGradeProfessor( unsigned id, unsigned apagar ){
    for( int disciplina = apagar; disciplina < docente[id].disciplinasMinistrando-1; disciplina++ ){
        docente[id].ministrando[disciplina] = docente[id].ministrando[disciplina=1];}
    docente[id].disciplinasMinistrando--;
}
#endif  //MATRICULAR_FILE_H
