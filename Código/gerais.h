#ifndef GERAIS_FILE_H
#define GERAIS_FILE_H
#include <stdbool.h>
///AUMENTAR A QUANTIDADE DE CARACTERES DE CADA DADO PARA NÃO SOBRECARREGAR 
///O BUFFER E APRIMORAR O VERIFICADOR DE TAMANHO PARA LIDAR COM ISSO 
//Dados - Alunos e Professores//
/// Formato CPF: 0 0 0 . 0 0 0 . 0 0 0 - 0 0 '\0' \n
///              0 1 2 3 4 5 6 7 8 9 0 1 2 3   4   5 
#define TAM_CPF 16
/// Formato Data Nascimento: 0 0 / 0 0 / 0 0 0 0 '\0' \n
///                          0 1 2 3 4 5 6 7 8 9   0   1 
#define TAM_NAC 12
#define TAM_NOME 32
#define TAM_MAT 13
#define TAM_COD_MAT 20
//Dados - Disciplina//
#define TAM_COD_DISC 8
#define TAM_SEM 8
#define TAM_NOME_DISC 31
#define TAM_TURMA 40

#define quantMaxAluno 10
#define quantMaxProfessor 10
#define quantMaxDisciplina 10

#define TAM_MATRIZ 8
#define TAM_MINIS 4

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
    int ministrando[TAM_MINIS];
}docente[quantMaxProfessor];
typedef struct professor Professor;

struct aluno{
    Dados dado;
    int matrizCurricular[TAM_MATRIZ];
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

struct{
    int professoresCadastradosBackup,
        alunosCadastradosBackup,
        disciplinasCadastradasBackup;
}dadosGerais;

char *arquivoDeProfessores = "arquivo_de_professores.txt";
char *arquivoDeAlunos = "arquivo_de_alunos.txt";
char *arquivoDeDisciplinas = "arquivo_de_disciplinas.txt";
char *arquivoDeDadosGerais = "arquivo_de_dados_gerais.txt";

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

char diminuiLetra( char );
char aumentaLetra( char );

bool verificaMatriculaProfessor( int, char * );
bool verificaMatriculaAluno( int, char*  );
bool verificaCpfAluno( int, char * );
bool verificaCpfProfessor( int, char * );
int verificaCodigoDisciplina( int, char* );
int verificaNomeProfessor( int, char* );

///SEÇÃO DE ARQUIVOS 
bool criaArquivos( );

bool salvaDadosGerais( );
bool salvaCadastroProfessor( );
bool salvaCadastroDisciplina( );
bool salvaCadastroAluno( );
bool recuperaCadastrosAlunos( );
bool recuperaCadastrosDisciplinas( );
bool recuperaCadastrosProfessores( );
bool recuperaDadosGerais( );

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
          return true;}}
    return false;     
}
char *caixaAlta( char *texto ){
    char *textoBackup = (char*)malloc((strlen( texto ))*sizeof(char) );

    for( int caracter = 0; texto[caracter] != '\0'; caracter++ ){
        textoBackup[caracter] = aumentaLetra(texto[caracter]);}
    
    //free( textoBackup );
    return textoBackup;
}
char *caixaBaixa( char *texto ){
    char *textoBackup = (char*)malloc((strlen( texto ))*sizeof(char) );
    
    for( int caracter = 0; texto[caracter] != '\0'; caracter++ ){
        textoBackup[caracter] = diminuiLetra(texto[caracter]);}
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
    nome[0] = aumentaLetra(nome[0]); 
    for( int caracter = 0; nome[caracter] != '\0'; caracter++ ){
        if( nome[caracter-1] == ' ' ){
            nome[caracter] = aumentaLetra(nome[caracter]); }}
}
char diminuiLetra( char letra ){
    char caracteresEspeciais[] = "àèìòùáéíóúýâêîôûãñõçÀÈÌÒÙÁÉÍÓÚÝÂÊÎÔÛÃÑÕÇ";

    if( letra < 91 && letra > 64 ){
        return letra + 32;
    }else{
        for( int caracterEsp = 20; caracterEsp < 40; caracterEsp++ ){
            if( letra == caracteresEspeciais[caracterEsp] ){
                letra = caracteresEspeciais[caracterEsp - 20];
                return letra; }}}
    return letra;
}
char aumentaLetra( char letra ){
    char caracteresEspeciais[] = "àèìòùáéíóúýâêîôûãñõçÀÈÌÒÙÁÉÍÓÚÝÂÊÎÔÛÃÑÕÇ";

    if( letra < 123 && letra > 96 ){
        return letra - 32;
    }else{
        for( int caracterEsp = 0; caracterEsp < 20; caracterEsp++ ){
            if( letra == caracteresEspeciais[caracterEsp] ){
                letra = caracteresEspeciais[caracterEsp + 20];
                return letra; }}}
    return letra;
}
bool verificaMatriculaProfessor( int filtro, char *matricula ){
    switch( filtro ){ 
        case 0:
            if( professoresCadastrados > 0 ){ 
                for( int cadastrado = 0; cadastrado < professoresCadastrados; cadastrado++){
                    if( (strcmp( matricula, docente[cadastrado].dado.matricula)) == 0 ){ 
                        return true;}}
                        }break;
        case 1:
            if( professoresCadastrados > 1 ){ 
                for( int cadastrado = 0; cadastrado < (professoresCadastrados - 1); cadastrado++){
                    if( (strcmp( matricula, docente[cadastrado].dado.matricula)) == 0 ){ 
                        return true;}}
                        }break;
        default: puts( "> Filtro inválido <\n" );}
    return false;
}
bool verificaMatriculaAluno( int filtro, char *matricula ){
    switch( filtro ){ 
        case 0:
            if( alunosCadastrados > 0 ){ 
                for( int cadastrado = 0; cadastrado < alunosCadastrados; cadastrado++){
                    if( (strcmp( matricula, discente[cadastrado].dado.matricula)) == 0 ){ 
                        return true;}}
                      }break;
        case 1:
            if( alunosCadastrados > 1 ){ 
                for( int cadastrado = 0; cadastrado < (alunosCadastrados - 1); cadastrado++){
                    if( (strcmp( matricula, discente[cadastrado].dado.matricula)) == 0 ){ 
                        return true;}}
                    }break;
        default: puts( "> Filtro inválido <\n" ); }
    return false;
}
bool verificaCpfAluno( int filtro, char *cpf  ){
    
      switch( filtro ){ 
        case 0:
            if( alunosCadastrados > 0 ){ 
                for( int cadastrado = 0; cadastrado < alunosCadastrados; cadastrado++){
                    if( (strcmp( cpf, discente[cadastrado].dado.cpf)) == 0 ){ 
                        return true;}}
                }break;
        case 1:
            if( alunosCadastrados > 1 ){ 
                for( int cadastrado = 0; cadastrado < (alunosCadastrados - 1); cadastrado++){
                    if( (strcmp( cpf, discente[cadastrado].dado.cpf)) == 0 ){ 
                        return true;}}
                 }break;
        default: puts( "> Filtro inválido <\n" ); }
    return false;
}

bool verificaCpfProfessor( int filtro, char *cpf ){
      switch( filtro ){ 
        case 0:
            if( professoresCadastrados > 0 ){ 
                for( int cadastrado = 0; cadastrado < professoresCadastrados; cadastrado++){
                    if( (strcmp( cpf, docente[cadastrado].dado.cpf)) == 0 ){ 
                        return true;}}
                }break;
        case 1:
            if( professoresCadastrados > 1 ){ 
                for( int cadastrado = 0; cadastrado < (professoresCadastrados - 1); cadastrado++){
                    if( (strcmp( cpf, docente[cadastrado].dado.cpf)) == 0 ){ 
                        return true;}}
            }break;
        default: puts( "> Filtro inválido <\n" ); 
    }
    return false;
}
int verificaCodigoDisciplina( int filtro, char *codigoMatricula ){
    enum VERIFICA{ EXISTENCIA = 0, REPETICAO = 1 };
    switch( filtro ){
        case EXISTENCIA:
            if( disciplinasCadastradas > 0 ){
                for( int cadastrada = 0; cadastrada < disciplinasCadastradas; cadastrada++){
                    if( (strcmp(codigoMatricula, materia[cadastrada].codigo )) == 0 ){
                      return cadastrada;}}}
            break;

        case REPETICAO:
            if( disciplinasCadastradas > 1 ){
                for( int cadastrada = 0; cadastrada < disciplinasCadastradas-1; cadastrada++){
                    if( (strcmp(codigoMatricula, materia[cadastrada].codigo )) == 0 ){
                      return cadastrada;}}}
            break;
    }
    return -1;
}
bool verificaNomeDisciplina( char *nomeDisciplina ){
    if( disciplinasCadastradas > 0 ){ 
        for( int cadastrado = 0; cadastrado < disciplinasCadastradas-1; cadastrado++){
            if( (strcmp( nomeDisciplina, materia[cadastrado].nome)) == 0 ){ 
                return cadastrado;}}
    }return false;
}
int verificaNomeProfessor( int filtro, char *nomeProfessor ){
     enum VERIFICA{ EXISTENCIA = 0, REPETICAO = 1 };
    
    switch( filtro ){
        case EXISTENCIA:
            if( professoresCadastrados > 0 ){
                for( int posicao = 0; posicao < professoresCadastrados; posicao++ ){
                    if( (strcmp(docente[posicao].dado.nome, nomeProfessor )) == 0  )
                        return posicao;}}   
            break;
        case REPETICAO:
            if( professoresCadastrados > 1 ){
                    for( int posicao = 0; posicao < professoresCadastrados - 1 ; posicao++ ){
                        if( (strcmp(docente[posicao].dado.nome, nomeProfessor )) == 0  )
                            return posicao;}}  
            break;
    }
    return -1;
}
bool criaArquivos( ){
    FILE *files; 

    files = fopen( arquivoDeDadosGerais, "r" );
    if( !files ){
        files = fopen( arquivoDeDadosGerais, "w" );
        if( !files )
            return false;
        fclose( files );}
    
    files = fopen( arquivoDeProfessores, "r" );
    if( !files ){
        files = fopen( arquivoDeProfessores, "w" );
        if( !files )
            return false;
        fclose( files );}
    
    files = fopen( arquivoDeAlunos, "r" );
        if( !files ){
            files = fopen( arquivoDeAlunos, "w" );
            if( !files )
                return false;
            fclose( files );}
    
    files = fopen( arquivoDeDisciplinas, "r" );
        if( !files ){
            files = fopen( arquivoDeDisciplinas, "w" );
            if( !files )
                return false;
            fclose( files );}
    return true;
}
bool recuperaDadosGerais( ){
    FILE *dadosGeraisFPtr = fopen( arquivoDeDadosGerais, "r" );
    char PROFESSORES[] = "PROFESSORES",
         ALUNOS[] = "ALUNOS",
         DISCIPLINAS[] = "DISCIPLINAS";
    
    if( dadosGeraisFPtr == NULL ){
        return false;
    }else{
        fscanf( dadosGeraisFPtr, "%s  %s  %s\n\t%d\t\t\t%d\t\t %d", PROFESSORES, ALUNOS, DISCIPLINAS,
                &professoresCadastrados, &alunosCadastrados, &disciplinasCadastradas );
        fclose( dadosGeraisFPtr );
        return true;}
}
bool salvaDadosGerais( ){
    FILE *dadosGeraisFPtr = fopen( arquivoDeDadosGerais, "w" );
    char PROFESSORES[] = "PROFESSORES",
         ALUNOS[] = "ALUNOS",
         DISCIPLINAS[] = "DISCIPLINAS";
    
    if( dadosGeraisFPtr == NULL ){
        return false;
    }else{
        fprintf( dadosGeraisFPtr, "%s  %s  %s\n\t%d\t\t\t%d\t\t %d", PROFESSORES, ALUNOS, DISCIPLINAS,
                 professoresCadastrados, alunosCadastrados, disciplinasCadastradas );
        fclose( dadosGeraisFPtr );
        return true;}
}

bool salvaCadastroProfessor( ){
    FILE *cadastroProfessorFPtr = fopen( arquivoDeProfessores, "a+" );

    if( !cadastroProfessorFPtr ){
        return false;
    }else{
        fseek( cadastroProfessorFPtr, (professoresCadastrados-1)*sizeof(Professor), SEEK_SET );
        fwrite( &docente[professoresCadastrados-1], sizeof(Professor), 1, cadastroProfessorFPtr );
        fclose( cadastroProfessorFPtr );
        return true;}
}
bool recuperaCadastrosProfessores( ){
    FILE *cadastroProfessorFPtr = fopen( arquivoDeProfessores, "r" );
    
    if( !cadastroProfessorFPtr ){
        return false;
    }else{
        for( int posicao = 0; posicao < professoresCadastrados; posicao++ ){
            fseek( cadastroProfessorFPtr, posicao*sizeof(Professor), SEEK_SET );
            fread( &docente[posicao], sizeof(Professor), 1, cadastroProfessorFPtr );}
        fclose( cadastroProfessorFPtr );
        return true;}
}
bool salvaCadastroAluno( ){
    FILE *cadastroAlunoFPtr = fopen( arquivoDeAlunos, "a+" );

    if( !cadastroAlunoFPtr ){
        return false;
    }else{
        int posicao = alunosCadastrados-1;
        //fseek( cadastroAlunoFPtr, (alunosCadastrados-1)*sizeof(Aluno), SEEK_SET );
        //fwrite( &discente[alunosCadastrados-1], sizeof(Aluno), 1, cadastroAlunoFPtr );
        fprintf( cadastroAlunoFPtr, "%*s %*s %*s %*s %*c\n", 
            TAM_CPF, discente[posicao].dado.cpf, TAM_NAC, discente[posicao].dado.nascimento, 
            TAM_NOME, discente[posicao].dado.nome, TAM_MAT, discente[posicao].dado.matricula, 
            4, discente[posicao].dado.sexo );
        fclose( cadastroAlunoFPtr );
        return true;}
}
bool recuperaCadastrosAlunos( ){
    FILE *cadastroAlunoFPtr = fopen( arquivoDeAlunos, "r" );
    
    if( !cadastroAlunoFPtr ){
        return false;
    }else{
        for( int posicao = 0; posicao < alunosCadastrados; posicao++ ){
            fscanf( cadastroAlunoFPtr, "%s %s %s %s %c", 
                discente[posicao].dado.cpf, discente[posicao].dado.nascimento, 
                discente[posicao].dado.nome, discente[posicao].dado.matricula,
                &discente[posicao].dado.sexo  );
    
            /*
            fseek( cadastroAlunoFPtr, posicao*sizeof(Aluno), SEEK_SET );
            fread( &discente[posicao], sizeof(Aluno), 1, cadastroAlunoFPtr );*/
            
            }
        fclose( cadastroAlunoFPtr );
        return true;}
}
bool salvaCadastroDisciplina( ){
    FILE *cadastroDisciplinaFPtr = fopen( arquivoDeDisciplinas, "a+" );

    if( !cadastroDisciplinaFPtr ){
        return false;
    }else{
        fseek( cadastroDisciplinaFPtr, (disciplinasCadastradas-1)*sizeof(Disciplinas), SEEK_SET );
        fwrite( &materia[disciplinasCadastradas-1], sizeof(Disciplinas), 1, cadastroDisciplinaFPtr );
        fclose( cadastroDisciplinaFPtr );
        return true;}
    return true;
}
bool recuperaCadastrosDisciplinas( ){
    FILE *cadastroDisciplinaFPtr = fopen( arquivoDeDisciplinas, "r" );
    
    if( !cadastroDisciplinaFPtr ){
        return false;
    }else{
        for( int posicao = 0; posicao < disciplinasCadastradas; posicao++ ){
            fseek( cadastroDisciplinaFPtr, posicao*sizeof(Disciplinas), SEEK_SET );
            fread( &materia[posicao], sizeof(Disciplinas), 1, cadastroDisciplinaFPtr );}
        fclose( cadastroDisciplinaFPtr );
        return true;}
}
#endif ///GERAIS_FILE_H
