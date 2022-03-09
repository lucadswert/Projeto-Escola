#ifndef VALIDA_FILE_H
#define VALIDA_FILE_H

#include "gerais.h"

//Validação de dados de professores e alunos
bool validaMatricula( char *matricula );
bool validaCpf( char *cpf );
bool validaSexo( char sexo );
bool validaNascimento( char *data );
bool validaNome( char *nome );

///validação de dados de matricula
bool validaNomeDiscplina( char* );
bool validaCodigo( char* );
bool validaSemestre( char* );
bool validaVagas( int );
bool validaQuanMatr( int );
bool validaProfessores( char* );

///VALIDA DADOS SOLICITADOS DE PROFESSORES E ALUNOS
bool validaMatricula( char *matricula ){
  //FaltaFazer//
    return NULL;
}
bool validaNome (char *nome){
    //FaltaFazer//
    return NULL;
}
bool validaNascimento (char *data){
    //FaltaFazer//
    return NULL;
}
bool validaCpf (char *cpf){
    //FaltaFazer//
    return NULL;
}
bool validaSexo( char sexo ){
    //FaltaFazer//
    return NULL;
}

///VALIDA DADOS SOLICITADOS DAS DISCIPLINAS
bool validaNomeDiscplina( char *nome ){
    
    return true;
}
bool validaCodigo( char *codigo ){

    return true;
}
bool validaSemestre( char *semestre ){

    return true;
}
bool validaVagas( int vagas ){

    return true;
}
bool validaQuanMatr( int quantidadeMatriculados ){

    return true;
}
bool validaProfessores( char *Professor ){

    return true;
}
#endif ///VALIDA_FILE_H