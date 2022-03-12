#ifndef GERAIS_FILE_H
#define GERAIS_FILE_H

#define bool _Bool 
#define true 1
#define false 0

//Dados - Alunos e Professores//
/// Formato CPF: 0 0 0 . 0 0 0 . 0 0 0 - 0 0 '\0' \n
///              0 1 2 3 4 5 6 7 8 9 0 1 2 3   4   5 
#define TAM_CPF 16
/// Formato Data Nascimento: 0 0 / 0 0 / 0 0 0 0 '\0' \n
///                          0 1 2 3 4 5 6 7 8 9   0   1 
#define TAM_NAC 12
#define TAM_NOME 61
#define TAM_MAT 13

//Dados - Disciplina//
#define TAM_COD_DISC 8
#define TAM_SEM 7
#define TAM_NOME_DISC 31

#define quantMaxAluno 3
#define quantMaxProfessor 3
#define quantMaxDisciplina 3

struct dados{
    char cpf[TAM_CPF],
         nascimento[TAM_NAC],
         nome[TAM_NOME],
         matricula[TAM_MAT],
         sexo;
};
typedef struct dados Dados;

struct professor{
    Dados dado;     
}docente[quantMaxProfessor];
typedef struct professor Professor;

struct aluno{
    Dados dado; 
}discente[quantMaxAluno];
typedef struct aluno Aluno;

struct Disciplinas{
    char nome[TAM_NOME_DISC],
         codigo[TAM_COD_DISC],
         semestre[TAM_SEM];
    int vagas,
        quantidadeMatriculado;
    Professor professor;
}materia[quantMaxDisciplina];

int professoresCadastrados = 0,
    alunosCadastrados = 0,
    disciplinasCadastradas = 0;

void limpaTexto( char* );
bool tamanhoCerto( int, char* );
bool ehNumero( char );
bool ehLetra ( char );

void limpaTexto( char *texto ){
    for( int caracter = 0; texto[caracter] != '\0'; caracter++ ){
        if( texto[caracter+1] == '\0' )
            texto[caracter] = '\0';}    
}
bool ehNumero( char digito ){
    if( digito < '0' || digito > '9'){
    	return false;}
    return true;
}
bool tamanhoCerto( const int tamanho, char *dado){
    int size;
    for( int contador = 0; dado[contador] != '\0'; contador++ ){
        if( dado[contador+1] == '\0' ){
            size = contador + 1;}}
  
    if( size != tamanho-2){
    	return false;}
    
    return true;
}

bool ehLetra(char caracter){
    char caracteresEspeciais[] = ("àèìòùÀÈÌÒÙáéíóúýÁÉÍÓÚÝâêîôûÂÊÎÔÛãñõÃÑÕäëïöüÿÄËÏÖÜŸçÇ");
    
    if( (caracter >= 'A' && caracter <= 'Z') ||
	       ( caracter >= 'a' && caracter <= 'z' ) ){
        return true;}
  
    for(int i = 0; caracteresEspeciais[i] != '\0'; i++){
      if( caracter == caracteresEspeciais[i] ){
          return true;}
    }
    return false;     
}
#endif ///GERAIS_FILE_H