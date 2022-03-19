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
bool validaProfessores( char* );
bool validaNomeDisciplina(char *);

///VALIDA DADOS SOLICITADOS DE PROFESSORES E ALUNOS
bool validaMatricula( char *matricula ){ 
    char *mensagensDeErro[4] = { };
    int erro = 0;

    if ( !tamanhoCerto(TAM_MAT, matricula) ){
        mensagensDeErro[erro++] = "  Tamanho inválido";}

    for(int i = 0; matricula[i] != '\0'; i++){
        if( !ehNumero(matricula[i]) ){ 
            mensagensDeErro[erro++] = "  Caractere inserido inválido";}}

    mensagensDeErro[erro] = NULL;
    
    if( mensagensDeErro[0] != NULL ){
        for( int posicoes = 0; mensagensDeErro[posicoes] != NULL; posicoes++ ){
            puts( mensagensDeErro[posicoes] );}
        return false;}
    
    return true;
}
bool validaNome(char *nome){ 
    for(int i = 0; nome[i] != '\0'; i++){
        if(!(ehLetra(nome[i])) && !(nome[i] == ' ')){
            puts( " Caractere inválido" );
            return false;}}
    return true;
}
bool validaNascimento( char *data ){    
    char *mensagensDeErro[3] = { };
    int erro = 0;
  
    if ( !tamanhoCerto(TAM_NAC, data) ){
        mensagensDeErro[erro++] = "  Tamanho inválido";}  

    for(int i = 0; data[i] != '\0'; i++){
        if( !ehNumero(data[i]) && !(data[i] == '/')){ 
            mensagensDeErro[erro++] = "  Caractere inserido inválido";
            break;}}
    mensagensDeErro[erro] = NULL;
  ///PESSOAL, ESSA VALIDAÇÃO PODERIA SER FEITA
  
  for( int i = 0; i < 2; i++){
    if(!ehNumero(data[i])){
      puts( "  Formato invalido" );
            return false;}}
  
  for (int i = 3; i < 5; i++){
    if (!ehNumero(data[i])){
      puts( "  Formato invalido" );
            return false;}}
  
  for (int i = 6; i < 10; i++){
    if (!ehNumero(data[i])){
      puts( "  Formato invalido" );
            return false;}}
  
   for(int i = 2; i < 3 ; i++){
        if ( !(data[i] == '/') ){
            puts( "  Formato invalido" );
            return false;}}
    for(int i = 5; i < 6 ; i++){
        if ( !(data[i] == '/') ){
            puts( "  Formato invalido" );
            return false;}}
    
    /// DESSA MANEIRA, COM APENAS UM LAÇO
  /*
    for( int caracter = 0; data[caracter] != '\0'; caracter++ ){
        if( !ehNumero(data[caracter]) && caracter != 2 && caracter != 5 ){
            puts( "  Formato invalido" );
            return false;}}
    */
    int dia = (charParaInt(data[0])*10)+charParaInt(data[1]),
        mes = (charParaInt(data[3])*10)+charParaInt(data[4]),
        ano = (charParaInt(data[6])*1000)+charParaInt(data[7])*100+charParaInt(data[8]*10)+charParaInt(data[9]);

    if(  dia <= 31 &&  mes <= 12 && ano >= 1899  && ano <= 2003){
        if( ( mes == 4 || mes == 6 || mes == 9 || mes == 11 ) && dia > 30  ){ 
            puts(" Data invalida");
            return false;
        }else if( mes == 2 && dia > 29 ){
            puts(" Data invalida");
            return false;}
            
    }else{
        puts(" Data invalida");
        return false;}
    
    if( mensagensDeErro[0] == NULL ){
        return true;
    }else{
        for( int posicoes = 0; mensagensDeErro[posicoes] != NULL; posicoes++ ){
            puts( mensagensDeErro[posicoes] );}
        return false;}
}
bool validaCpf (char *cpf){ 
    char *mensagensDeErro[3] = { };
    int erro = 0;

    if ( !tamanhoCerto(TAM_CPF, cpf) ){
        mensagensDeErro[erro++] = "  Tamanho inválido";}  
  
    for(int i = 0; cpf[i] != '\0'; i++){
        if( !ehNumero(cpf[i]) && !(cpf[i] == '.') && !(cpf[i] == '-') ){ 
            mensagensDeErro[erro++] = "  Caractere inserido inválido";
            break;}}
  
    mensagensDeErro[erro] = NULL;
    
    for(int i = 0; i < 3 ; i++){
        if ( !ehNumero(cpf[i])){
            puts( "  Formato invalido" );
            return false;}}
  
    for(int i = 4; i < 7 ; i++){
        if ( !ehNumero(cpf[i])){
            puts( "  Formato invalido" );
            return false;}}
  
    for(int i = 12; i < 14 ; i++){
        if ( !ehNumero(cpf[i])){
            puts( "  Formato invalido" );
            return false;}}
  
    for(int i = 3; i < 4 ; i++){
        if ( !(cpf[i] == '.') ){
            puts( "  Formato invalido" );
            return false;}}
    for(int i = 7; i < 8 ; i++){
        if ( !(cpf[i] == '.') ){
            puts( "  Formato invalido" );
            return false;}}
  
    for(int i = 11; i < 12 ; i++){
        if ( !(cpf[i] == '-') ){
            puts( "  Formato invalido" );
            return false;}}
    
    /*/// DESSA MANEIRA, COM APENAS UM LAÇO
    for( int caracter = 0; cpf[caracter] != '\0'; caracter++ ){
        if( !ehNumero(cpf[caracter]) && caracter != 3 && caracter != 7 && caracter != 11 ){
            puts( "  Formato invalido" );
            return false;}}
    */
    if( mensagensDeErro[0] != NULL ){
        for( int posicoes = 0; mensagensDeErro[posicoes] != NULL; posicoes++ ){
            puts( mensagensDeErro[posicoes] );}
        return false;}
    
    return true;
}
bool validaSexo( char sexo ){ 
    if (!(sexo == 'm') && !(sexo == 'M') && !(sexo == 'F') && !(sexo == 'f') ){
        puts( " Opção inválida" );
        return false;
    }else{  
      return true;}
}

///VALIDA DADOS SOLICITADOS DAS DISCIPLINAS
bool validaNomeDisciplina( char *nomeDisciplina ){ 
    for(int i = 0; nomeDisciplina[i] != '\0'; i++){
        if(!(ehLetra(nomeDisciplina[i])) && !(nomeDisciplina[i] == ' ')){
            puts("  Caractere Invalido");
            return false;}}
    if( verificaNomeDisciplina( nomeDisciplina) ){ 
        puts( "Este nome já está associado a uma disciplina." );
        return false;}
    return true;
}
bool validaCodigo( char *codigo ){ 
    char *mensagensDeErro[3] = { };
    int erro = 0;

    if ( !tamanhoCerto(TAM_COD_DISC, codigo) ){
        mensagensDeErro[erro++] = "  Tamanho inválido";} 
  
    for(int i = 0; codigo[i] != '\0'; i++){
        if( !ehNumero(codigo[i]) && !ehLetra(codigo[i])){ 
            mensagensDeErro[erro++] = "  Caractere inserido inválido";
            break;}}
    
    mensagensDeErro[erro] = NULL;

    ///PESSOA ESSA VALIDACAO PODERIA SER FEITA COM UM LACO SO
    for(int i = 0; i < 3; i++){
        if( !ehLetra(codigo[i]) ) { 
            puts("  Formato invalido");
            return false;}}
  
    for(int i = 3; i < 6; i++){
        if( !ehNumero(codigo[i]) ) { 
            puts( "  Formato invalido" );
            return false;}}
    /* //DESSA MANEIRA
    for(int caracter = 0; caracter < ((TAM_COD_DISC-2)/2); caracter++ ){
        if( !ehLetra(codigo[caracter]) || !ehNumero(codigo[(caracter+((TAM_COD_DISC-2)/2))] )){ 
            puts("  Formato invalido");
            return false;}}
    */
    if( mensagensDeErro[0] != NULL ){
        for( int posicoes = 0; mensagensDeErro[posicoes] != NULL; posicoes++ ){
            puts( mensagensDeErro[posicoes] );}
        return false;}
  return true;
}
bool validaSemestre( char *semestre ){ 

    char *mensagensDeErro[3] = { };
    int erro = 0;

     if ( !tamanhoCerto(TAM_SEM, semestre) ){
        mensagensDeErro[erro++] = "  Tamanho inválido";} 
  
    for(int i = 0; semestre[i] != '\0'; i++){
        if( !ehNumero(semestre[i]) && !(semestre[i] == '.') ){ 
            mensagensDeErro[erro++] = "  Caractere inserido inválido";
            break;}}
  
    mensagensDeErro[erro] = NULL;

    /*
    for(int i = 0; i < 4 ; i++){
        if ( !ehNumero(semestre[i]) ){
            puts ( "  Formato invalido" );
            return false;}}
  
    for(int i = 4; i < 5 ; i++){ 
        ///PESSOAL QUE DESGRAÇA É ESSA AQUI
        ///VOCES FIZERAM UM LACO DE REPETICAO
        ///QUE SO REPETE UMA UNICA VEZ??????????

        if ( !(semestre[i] == '.') ){
            puts ( "  Formato invalido" );
            return false;}}
    */
    ///sugestao de como a gente poderia fazer
    for( int caracter = 0; semestre[caracter] != '\0'; caracter++ ){
        if( !ehNumero(semestre[caracter]) && caracter != 4 ){
            puts( "  Formato invalido" );
            return false;}}
    /*
    ///PESSOAL, MAIS UM TRECHO DO CODIGO EM QUE
    /// O REPLIT ESTÁ DANDO PROBLEMA.
    ///ELE NÃO ESTÁ CONSEGUINDO COMPARAR O CARACTER
    ///REPRESENTADO POR semestre[5] COM OS CARACTERES
    ///ENTRE ASPAS SIMPLES. EU NÃO VEJO OUTRA ALTERNATIVA
    ///VAMOS TER QUE DEIXAR COMENTADO E FALAR COM O PROFESSOR.
    
    if ((semestre[5] != '1') && (semestre[5] != '2')){
        puts ( "  Semestre invalido" );
        return false;}
    */
    if( mensagensDeErro[0] == NULL ){
        return true;
    }else{
        for( int posicoes = 0; mensagensDeErro[posicoes] != NULL; posicoes++ ){
            puts( mensagensDeErro[posicoes] );}
        return false;}
}
bool validaVagas( int vagas ){ 
    if( vagas < 0 ){
        puts( " Valor inválido" );
        return false;
    }else{
      return true;}
}
bool validaProfessores( char *professor ){ 
    if( validaNome( professor ) ){ 
        int tamanho = 0;
        char *professorAtualBackup = (char*)malloc( (strlen( professor ))*sizeof(char) ),
             *professorDaLista = NULL;
        
        strcpy( professorAtualBackup, caixaAlta(professor) );
    
        if( professoresCadastrados > 0 ){ 
            for( int cadastrado = 0; cadastrado < professoresCadastrados; cadastrado++){
                tamanho = strlen( docente[cadastrado].dado.nome  );
                professorDaLista = (char*)malloc( tamanho*sizeof(char) );
                strcpy( professorDaLista, caixaAlta(docente[cadastrado].dado.nome ));
                
                if( (strcmp( professorAtualBackup, professorDaLista)) == 0 ){ 
                    free( professorAtualBackup );
                    free( professorDaLista );
                    return true;}}
            puts("  Professor invalido!" );
            free( professorAtualBackup );
            free( professorDaLista );
            return false;
        }else{ 
            puts("  Professor invalido!" );
            free( professorAtualBackup );
            free( professorDaLista );
            return false;}
    }else{ return false;}
}

#endif ///VALIDA_FILE_H
