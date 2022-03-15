#ifndef MATRICULA_FILE_H 
#define  MATRICULA_FILE_H

#include "valida.h"

void matricular( ){
    char *solicitaCodigoMatricula( ); 
    char codigoDeMatricula[TAM_COD_MAT];
    
    do{
        listarAlunos( );
        listarDisciplinas( );
        strcpy( codigoDeMatricula, solicitaCodigoMatricula( ) );
        if( codigoDeMatricula[0] != " " ){
        /// verificar se matricula existe
        /// verificar se codigo de disciplina existe
        /// 
        }
    }while( codigoDeMatricula[0] != " " );
}
char *solicitaCodigoMatricula( ){
    bool validaCodigoMatricula( char* );
    char codigoMatricula[TAM_COD_MAT];
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    
    do{
        printf("Digite o Codigo de Matricula [matriculaDoAluno/codigoDaDisciplina]\n  -" );
        fgets( codigoMatricula, TAM_COD_MAT, stdin );
        if( sair(codigoMatricula[0], codigoMatricula[1] ) ){
            return " ";
        }else{
            limpaTexto( codigoMatricula );
            DADO = validaCodigoMatricula( codigoMatricula );}
    }while( DADO == INVALIDO );

    return codigoMatricula;
}
bool validaCodigoMatricula( char *codigoMatricula ){
    char matricula[TAM_MAT-1];
    char codigoDisciplina[TAM_COD_DISC];
    char *mensagemDeErro[3];
    int erro = 0;

    strncpy( matricula, TAM_MAT-2, codigoMatricula );
    strncpy( codigoDisciplina, TAM_COD_DISC -2, codigoMatricula[TAM_MAT+1] );
    
    if( !tamanhoCerto( codigoMatricula, TAM_COD_MAT ) ){
        mensagemDeErro[erro++] = "Codigo invalido!";}
    
    for( int caracter = 0; codigoMatricula[caracter] != '\0'; caracter++ ){
        if( !ehNumero(codigoMatricula[caracter]) && !ehLetra(codigoMatricula[caracter] ) && codigoMatricula[caracter] != '/' ){
             mensagemDeErro[erro++] = "Caracteres inválidos";}
        if( codigoMatricula[caracter] != '/' && caracter != 11 ){
            puts( "Codigo invalido!" );
            return false;}
    }
    if( !validaMatricula( matricula ) ){
        puts( "Matricula invalida!" );
        return false;}
    if( !validaCodigo( codigoDisciplina ) ){
        puts( "Disciplina invalida!" );
        return false;}

    mensagemDeErro[erro] = NULL;
    
    if( mensagemDeErro[0] = NULL ){
        return true;
    }else{
        for( int posicao = 0; mensagemDeErro[posicao] != NULL; posicao++ ){
            puts( mensagemDeErro[posicao] );}
        return false;}
}

#endif  //MATRICULAR_FILE_H