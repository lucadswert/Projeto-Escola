#ifndef VALIDA_FILE_H
#define VALIDA_FILE_H
#include <string.h>
#include "gerais.h"

//Validação de dados de professores e alunos
bool validaMatricula( char *matricula );
bool validaCpf( char *cpf );
bool validaSexo( char sexo );
bool validaNascimento( char *data );
bool validaNome( char *nome );

///validação de dados de matricula
bool validaCodigo( char* );
bool validaSemestre( char* );
bool validaVagas( int );
bool validaQuanMatr( int );
bool validaProfessores( char* );

///VALIDA DADOS SOLICITADOS DE PROFESSORES E ALUNOS
bool validaMatricula( char *matricula ){
    //// FAZER 10/03
    /// *A matrícula não pode ser repetid
    
    if ( !tamanhoCerto(TAM_MAT, matricula) ){
        puts( "Tamanho inválido");
        return false;}

    for(int i = 0; matricula[i] != '\0'; i++){
        if( !ehNumero(matricula[i]) ){ 
            puts( "Caractere inserido inválido");
            return false;}}

    for( int cadastrado = 0; cadastrado < alunosCadastrados;             cadastrado++){
        //printf( "%d cadastrado\n", cadastrado+1 );
        if( alunosCadastrados > 1 && (strcmp( matricula, discente[cadastrado+1].dado.matricula)) == 0 ){ 
            puts( "Matricula invalida");
            return false;}
    }
    for( int cadastrado = 0; cadastrado < professoresCadastrados;             cadastrado++){
        //printf( "%d cadastrado\n", cadastrado+1 );
        if( professoresCadastrados > 1 && (strcmp( matricula, docente[cadastrado+1].dado.matricula)) == 0 ){ 
            
            puts( "Matricula invalida");
            return false;}
    }


      
    return true;
}
bool validaNome (char *nome){ //// FAZER 10/03
    /// Tem que ser letra
    /// Máximo de 61 caracteres
    //FaltaFazer//
    return true;
}
bool validaNascimento (char *data){
    //FaltaFazer//
    return true;
}
bool validaCpf (char *cpf){
    //FaltaFazer//
    return true;
}
bool validaSexo( char sexo ){ //// FAZER 10/03
    /// Apenas F ou M (letra)//
    /// Apenas 1 Caractere///
    //FaltaFazer//
    return true;
}

///VALIDA DADOS SOLICITADOS DAS DISCIPLINAS

bool validaCodigo( char *codigo ){ //// FAZER 10/03
    /// TEM QUE TER 3 letras e 3 números, respectivamente
    /// Deve ter 6 caracteres

    return true;
}
bool validaSemestre( char *semestre ){

    return true;
}
bool validaVagas( int vagas ){ //// FAZER 10/03
    /// Tem que ser número não negativo

    return true;
}
bool validaQuanMatr( int quantidadeMatriculados ){ 
    /// Ver amanhã cedo
    return true;
}
bool validaProfessores( char *Professor ){

    return true;
}
#endif ///VALIDA_FILE_H