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
bool validaNomeDisciplina(char *);
///VALIDA DADOS SOLICITADOS DE PROFESSORES E ALUNOS

bool validaMatricula( char *matricula ){ //OK
    char *mensagensDeErro[4] = { };
    int erro = 0;

    if ( !tamanhoCerto(TAM_MAT, matricula) ){
        mensagensDeErro[erro++] = "  Tamanho inválido";}

    for(int i = 0; matricula[i] != '\0'; i++){
        if( !ehNumero(matricula[i]) ){ 
            mensagensDeErro[erro++] = "  Caractere inserido inválido";}}

    mensagensDeErro[erro] = NULL;
    
    if( mensagensDeErro[0] == NULL ){
        if( alunosCadastrados > 0 ){ 
            for( int cadastrado = 0; cadastrado < alunosCadastrados; cadastrado++){
                if( (strcmp( matricula, discente[cadastrado].dado.matricula)) == 0 ){ 
                    puts("  Matricula repetida");
                    return false;}}}
    
        if( professoresCadastrados > 0 ){
            for( int cadastrado = 0; cadastrado < professoresCadastrados; cadastrado++){
                if( (strcmp( matricula, docente[cadastrado].dado.matricula)) == 0 ){ 
                    puts ( "   Matricula repetida");
                    return false;}}}
    }else{
        for( int posicoes = 0; mensagensDeErro[posicoes] != NULL; posicoes++ ){
            puts( mensagensDeErro[posicoes] );}
        return false;}
    return true;
}
bool validaNome(char *nome){ //OK
    for(int i = 0; nome[i] != '\0'; i++){
        if(!(ehLetra(nome[i])) && !(nome[i] == ' ')){
            puts( " Caractere inválido" );
            return false;}}
    return true;
}
bool validaNascimento (char *data){ //Validar Formato e Consistência
    char *mensagensDeErro[3] = { };
    int erro = 0;
  
    if ( !tamanhoCerto(TAM_NAC, data) ){
        mensagensDeErro[erro++] = "  Tamanho inválido";}  

    for(int i = 0; data[i] != '\0'; i++){
        if( !ehNumero(data[i]) && !(data[i] == '/')){ 
            mensagensDeErro[erro++] = "  Caractere inserido inválido";
            break;}}
    mensagensDeErro[erro] = NULL;
    if( mensagensDeErro[0] == NULL ){
        return true;
    }else{
        for( int posicoes = 0; mensagensDeErro[posicoes] != NULL; posicoes++ ){
            puts( mensagensDeErro[posicoes] );}
        return false;}
}
bool validaCpf (char *cpf){ // Validar Formato
    char *mensagensDeErro[3] = { };
    int erro = 0;

    if ( !tamanhoCerto(TAM_CPF, cpf) ){
        mensagensDeErro[erro++] = "  Tamanho inválido";}  
  
    for(int i = 0; cpf[i] != '\0'; i++){
        if( !ehNumero(cpf[i]) && !(cpf[i] == '.') && !(cpf[i] == '-') ){ 
            mensagensDeErro[erro++] = "  Caractere inserido inválido";
            break;}}
    
    mensagensDeErro[erro] = NULL;
    
    if( mensagensDeErro[0] == NULL ){
        if( alunosCadastrados > 0 ){ 
            for( int cadastrado = 0; cadastrado < alunosCadastrados; cadastrado++){
                if( (strcmp( cpf, discente[cadastrado].dado.cpf)) == 0 ){ 
                    puts("  CPF repetido");
                    return false;}}}
    
        if( professoresCadastrados > 0 ){
            for( int cadastrado = 0; cadastrado < professoresCadastrados; cadastrado++){
                if( (strcmp( cpf, docente[cadastrado].dado.cpf)) == 0 ){ 
                    puts( "   CPF repetido" );
                    return false;}}}
    }else{
        for( int posicoes = 0; mensagensDeErro[posicoes] != NULL; posicoes++ ){
            puts( mensagensDeErro[posicoes] );}
        return false;}
    
    return true;
}
bool validaSexo( char sexo ){ //OK
    if (!(sexo == 'm') && !(sexo == 'M') && !(sexo == 'F') && !(sexo == 'f') ){
        puts( " Opção inválida" );
        return false;
    }else{  
      return true;}
}

///VALIDA DADOS SOLICITADOS DAS DISCIPLINAS
bool validaNomeDisciplina(char *nomeDisciplina ){ // Okay
    /// FAZER FUNCAO QUE DIMINUI OU AUMENTA TODAS AS LETRAS DA STRING
    /// PARA FAZER COMPARACAO

    for(int i = 0; nomeDisciplina[i] != '\0'; i++){
        if(!(ehLetra(nomeDisciplina[i])) && !(nomeDisciplina[i] == ' ')){
            puts("  Caractere Invalido");
            return false;}}
    if( disciplinasCadastradas > 0 ){ 
        for( int cadastrado = 0; cadastrado < disciplinasCadastradas; cadastrado++){
            if( (strcmp( nomeDisciplina, materia[cadastrado].nome)) == 0 ){ 
                puts("  Este nome já está associado a uma discplina");
                return false;}}}
    return true;
}
bool validaCodigo( char *codigo ){ //// Validar Formato
    char *mensagensDeErro[3] = { };
    int erro = 0;

    if ( !tamanhoCerto(TAM_COD_DISC, codigo) ){
        mensagensDeErro[erro++] = "  Tamanho inválido";} 
  
    for(int i = 0; codigo[i] != '\0'; i++){
        if( !ehNumero(codigo[i]) && !ehLetra(codigo[i])){ 
            mensagensDeErro[erro++] = "  Caractere inserido inválido";
            break;}}
    
    mensagensDeErro[erro] = NULL;
    
    if( mensagensDeErro[0] == NULL ) {
        if( disciplinasCadastradas > 0 ){ 
            for( int cadastrado = 0; cadastrado < disciplinasCadastradas; cadastrado++){
                if( (strcmp( codigo, materia[cadastrado].codigo)) == 0 ){ 
                    puts("  Código já associado a uma disciplina" );
                    return false;}}}
    }else{
        for( int posicoes = 0; mensagensDeErro[posicoes] != NULL; posicoes++ ){
            puts( mensagensDeErro[posicoes] );}
        return false;}
  return true;
}
bool validaSemestre( char *semestre ){ //Validar Formato
    char *mensagensDeErro[3] = { };
    int erro = 0;

     if ( !tamanhoCerto(TAM_SEM, semestre) ){
        mensagensDeErro[erro++] = "  Tamanho inválido";} 
  
    for(int i = 0; semestre[i] != '\0'; i++){
        if( !ehNumero(semestre[i]) && !(semestre[i] == '.') ){ 
            mensagensDeErro[erro++] = "  Caractere inserido inválido";
            break;}}
    
    mensagensDeErro[erro] = NULL;
    if( mensagensDeErro[0] == NULL ){
        return true;
    }else{
        for( int posicoes = 0; mensagensDeErro[posicoes] != NULL; posicoes++ ){
            puts( mensagensDeErro[posicoes] );}
        return false;}
}
bool validaVagas( int vagas ){ //// Okay
    if( vagas < 0 ){
        puts( " Valor inválido" );
        return false;
    }else{
      return true;}
}
bool validaQuanMatr( int quantidadeMatriculados ){ 
    /// Ver amanhã cedo
    return true;
}
bool validaProfessores( char *Professor ){

    return true;
}
#endif ///VALIDA_FILE_H