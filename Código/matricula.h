 #ifndef MATRICULA_FILE_H 
#define  MATRICULA_FILE_H

#include "valida.h"

bool solicitaCodigoMatricula( char codigoDeMatricula[] ){
    bool validaCodigoMatricula( char[] );
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    
    do{
        printf("Digite o Codigo de Matricula [matriculaDoAluno/codigoDaDisciplina]\n  -" );
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
        mensagemDeErro[erro++] = "Codigo invalido!";}

    for( int caracter = 0; codigoDeMatricula[caracter] != '\0'; caracter++ ){
        if( !ehNumero(codigoDeMatricula[caracter]) && !ehLetra(codigoDeMatricula[caracter] ) && codigoDeMatricula[caracter] != '/' ){
             mensagemDeErro[erro++] = "Caracteres inválidos";}
        if( codigoDeMatricula[caracter] == '/' && caracter != 11 ){
            puts( "Codigo invalido!" );
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