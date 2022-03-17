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
#define TAM_COD_MAT 20
//Dados - Disciplina//
#define TAM_COD_DISC 8
#define TAM_SEM 7
#define TAM_NOME_DISC 31
#define TAM_TURMA 40

#define quantMaxAluno 3
#define quantMaxProfessor 3
#define quantMaxDisciplina 3

struct Disciplinas;

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
    Aluno **turma;
}materia[quantMaxDisciplina];
typedef struct Disciplinas Disciplinas;

int professoresCadastrados = 0,
    alunosCadastrados = 0,
    disciplinasCadastradas = 0;

void limpaTexto( char* );
bool tamanhoCerto( int, char* );
bool ehNumero( char );
bool ehLetra ( char );
char *caixaAlta( char* );
char *caixaBaixa( char* );
int charParaInt( char );
bool sair( char sinal, char valor );
void padronizaNome( char* );

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
    char caracteresEspeciais[] = "àèìòùÀÈÌÒÙáéíóúýÁÉÍÓÚÝâêîôûÂÊÎÔÛãñõÃÑÕäëïöüÿÄËÏÖÜŸçÇ";
    
    if( (caracter >= 'A' && caracter <= 'Z') ||
	       ( caracter >= 'a' && caracter <= 'z' ) ){
        return true;}
  
    for(int i = 0; caracteresEspeciais[i] != '\0'; i++){
      if( caracter == caracteresEspeciais[i] ){
          return true;}
    }
    return false;     
}
char *caixaAlta( char *texto ){
    char *textoBackup = (char*)malloc((strlen( texto ))*sizeof(char) );
    
    char caracteresEspeciais[] = "àèìòùáéíóúýâêîôûãñõçÀÈÌÒÙÁÉÍÓÚÝÂÊÎÔÛÃÑÕÇ";
    
    strcpy(textoBackup, texto );
    
    for( int caracter = 0; texto[caracter] != '\0'; caracter++ ){
        if( texto[caracter] >= 'a' && texto[caracter] <= 'z' ){
            textoBackup[caracter] = ( texto[caracter] - 32);
        }else{//
        //PESSOAL ESSA PARTE DO CODIGO ESTA PREJUDICA. 
        //O REPLIT N LIDA BEM COM CARACTERES ESPECIAIS
        //MESMO COM A BIBLIOTECA LOCALE.H. JA TESTEI.
        ///POREM SE VCS TESTAREM EM QUALQUER OUTRA IDE FUNCIONA
            for( int caracterEsp = 0; caracterEsp < 20; caracterEsp++ ){
                if( texto[caracter] == caracteresEspeciais[caracterEsp] ){
                    textoBackup[caracter] = caracteresEspeciais[caracterEsp + 20];
                    break;
                }}}
    }
    //free( textoBackup );
    return textoBackup;
}
char *caixaBaixa( char *texto ){
    char *textoBackup = (char*)malloc((strlen( texto ))*sizeof(char) );
    
    char caracteresEspeciais[] = "ÀÈÌÒÙÁÉÍÓÚÝÂÊÎÔÛÃÑÕÇàèìòùáéíóúýâêîôûãñõç";
    
    strcpy(textoBackup, texto );
    
    for( int caracter = 0; texto[caracter] != '\0'; caracter++ ){
        if( texto[caracter] >= 'A' && texto[caracter] <= 'Z' ){
            textoBackup[caracter] = ( texto[caracter] + 32);
        }else{//
        //PESSOAL ESSA PARTE DO CODIGO ESTA PREJUDICA. 
        //O REPLIT N LIDA BEM COM CARACTERES ESPECIAIS
        //MESMO COM A BIBLIOTECA LOCALE.H. JA TESTEI.
        ///POREM SE VCS TESTAREM EM QUALQUER OUTRA IDE FUNCIONA
            for( int caracterEsp = 0; caracterEsp < 20; caracterEsp++ ){
                if( texto[caracter] == caracteresEspeciais[caracterEsp] ){
                    textoBackup[caracter] = caracteresEspeciais[caracterEsp + 20];
                    break;
                }}}
    }
    //free( textoBackup );
    return textoBackup;
}
int charParaInt( char letra ){
    switch( letra ){
        case '0' : return 0;
        case '1' : return 1;
        case '2' : return 2;
        case '3' : return 3;
        case '4' : return 4;
        case '5' : return 5;
        case '6' : return 6;
        case '7' : return 7;
        case '8' : return 8;
        case '9' : return 9;
        default: return -1;                     
    }
}
bool sair( char sinal, char valor ){
    if( sinal == '-' && valor == '1' ) return true;
    else return false;
}
void padronizaNome( char nome[] ){
    strcpy( nome, caixaBaixa( nome ) );
    for( int caracter = 0; nome[caracter] != '\0'; caracter++ ){
        if( nome[caracter-1] == ' ' ){
            nome[caracter] = nome[caracter] - 32; }}
}
#endif ///GERAIS_FILE_H