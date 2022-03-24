#ifndef MATRICULA_FILE_H 
#define  MATRICULA_FILE_H

#include "valida.h"
///VERIFICAR SE O ALUNO NÁO ESTA TENTANDO SE MATRICULAR NUMA MESMO DISCIPLINA
void matricular( ){
    bool solicitaCodigoMatricula( char[] ); 
    char codigoDeMatricula[TAM_COD_MAT];
    
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    static int disciplina = 0;
    
    do{
        DADO = solicitaCodigoMatricula( codigoDeMatricula );
        if( !DADO == INVALIDO ){
            strcpy( &codigoDeMatricula[0], (caixaAlta( &codigoDeMatricula[0] )) );
            for( int i = 0; i < disciplinasCadastradas; i++){
                if( (strcmp( &codigoDeMatricula[12], materia[i].codigo )) == 0 ){
                    char matriculaAluno[TAM_MAT - 1];
                    strncpy( matriculaAluno, codigoDeMatricula, TAM_MAT - 2 );
                    for( int x = 0; x < alunosCadastrados; x++ ){
                        if ( (strcmp(matriculaAluno, discente[x].dado.matricula  )) == 0  ){
                            materia[i].turma[materia[i].quantidadeMatriculado] = &discente[x];
                            materia[i].quantidadeMatriculado++;
                            materia[i].vagas--;
                            if( disciplina < TAM_MATRIZ ){
                                discente[x].matrizCurricular[disciplina++] = i;}
                            printf( "%s cadastrado em %s \n", discente[x].dado.nome, materia[i].nome );
                            break;
                        }else if( x == alunosCadastrados - 1 ){ puts( "> Aluno não cadastrado <" );}
                    }break;
                }else if (i == disciplinasCadastradas - 1) { puts( "> Disciplina não cadastrada <" ); }}}
    }while( DADO != INVALIDO );
}
bool solicitaCodigoMatricula( char codigoDeMatricula[] ){
    bool validaCodigoMatricula( char[] );
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    
    do{
        printf("\n====================================\n"
                "||      MATRICULANDO - ALUNO      || \n"
                "====================================\n"
                "- Digite o Codigo de Matrícula [matriculaDoAluno/codigoDaDisciplina]\n->");
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

#endif  //MATRICULAR_FILE_H
