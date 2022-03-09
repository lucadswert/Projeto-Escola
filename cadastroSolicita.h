#ifndef CADASTROSOLICITA_FILE_H
#define CADASTROSOLICITA_FILE_H

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
#define TAM_COD_DISC 13
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

bool cadastrarProfessor( ){
    bool solicitaMatriculaProfessor( );
    bool solicitaNomeProfessor( );
    bool solicitaNascimentoProfessor( );
    bool solicitaCpfProfessor( );
    bool solicitaSexoProfessor( );
    
    if( (solicitaMatriculaProfessor( )) == true ){
        if( solicitaNomeProfessor( ) == true) {
            if( solicitaNascimentoProfessor( ) == true){
                if( solicitaCpfProfessor( ) == true){
                    if( solicitaSexoProfessor( ) == true){    
                        return true;
                    }else{ return false;}
                }else{ return false; }
            }else{ return false; }
        }else{ return false;}
    }else{ return false;}
}

bool solicitaMatriculaProfessor( ){ ////REPLICAR ESSE MODELO NAS DEMAIS FUNÇÕES
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    static int posicao = 0;
    
    do{
        printf("Digite o numero de matricula: \n");
        fgets((docente[posicao].dado.matricula), TAM_MAT, stdin);
        ///criar função que tirar o \n do final da string e inserir ela aqui tb
        DADO = validaMatricula( docente[posicao].dado.matricula );
    }while( DADO == INVALIDO );
    
    posicao++;
    return true;
}
bool solicitaNomeProfessor( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    static int posicao = 0;
    do{
        printf("Digite o nome do professor:\n");
        fgets(docente[posicao].dado.nome, TAM_NOME, stdin);
        DADO = validaNome (docente[posicao].dado.nome );
   }while( DADO == INVALIDO );
  
    posicao++;
    return true;
}
bool solicitaNascimentoProfessor( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    static int posicao = 0;
    
    do{
        printf("Digite a data de nascimento:\n");
        fgets(docente[posicao].dado.nascimento, TAM_NAC, stdin);
        DADO = validaNascimento ( docente[posicao].dado.nascimento );
   }while( DADO == INVALIDO );
  
    posicao++;
    return true;
}
bool solicitaCpfProfessor(){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    static int posicao = 0;
    
    do{
        printf("Digite o CPF:\n");
        fgets(docente[posicao].dado.cpf, TAM_CPF, stdin);
        DADO = validaCpf ( docente[posicao].dado.cpf );
   }while( DADO == INVALIDO );

    posicao++;  
    return true;
}
bool solicitaSexoProfessor( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    static int posicao = 0;
    
    do{
        printf("Digite o sexo:\n");
        scanf("%c", &docente[posicao].dado.sexo);
        getchar( );
        DADO = validaSexo (docente[posicao].dado.sexo);
    }while( DADO == INVALIDO );

    posicao++; 
    return true;
}

bool cadastrarAluno(){
    bool solicitaMatriculaAluno( );
    bool solicitaNomeAluno( );
    bool solicitaNascimentoAluno( );
    bool solicitaCpfAluno( );
    bool solicitaSexoAluno( );

    if( (solicitaMatriculaAluno( )) == true ){
        if( solicitaNomeAluno( ) == true) {
            if( solicitaNascimentoAluno( ) == true){
                if( solicitaCpfAluno( ) == true){
                    if( solicitaSexoAluno( ) == true){    
                        return true;
                    }else{ return false;}
                }else{ return false; }
            }else{ return false; }
        }else{ return false;}
    }else{ return false;}
}  

bool solicitaMatriculaAluno( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    static int posicao = 0;
    
    do{
        printf("Digite a matricula do Aluno:\n");
        fgets(discente[posicao].dado.matricula, TAM_MAT, stdin);
        DADO = validaNome (discente[posicao].dado.matricula );
   }while( DADO == INVALIDO );
  
    posicao++;
    return true;
}
bool solicitaNomeAluno(){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    static int posicao = 0;
    
    do{
        printf("Digite o nome do Aluno:\n");
        fgets(discente[posicao].dado.nome, TAM_NOME, stdin);
        DADO = validaNome (discente[posicao].dado.nome );
   }while( DADO == INVALIDO );
  
    posicao++;
    return true;
} 
bool solicitaSexoAluno( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    static int posicao = 0;
    
    do{
        printf("Digite o sexo:\n");
        scanf("%c", &discente[posicao].dado.sexo);
        getchar( );
        DADO = validaSexo (discente[posicao].dado.sexo);
   }while( DADO == INVALIDO );

    posicao++; 
    return true;
}
bool solicitaCpfAluno( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    static int posicao = 0;
    
    do{
        printf("Digite o CPF:\n");
        fgets(discente[posicao].dado.cpf, TAM_CPF, stdin);
        DADO = validaCpf ( discente[posicao].dado.cpf );
   }while( DADO == INVALIDO );

    posicao++;  
    return true;
    
  }
bool solicitaNascimentoAluno( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    static int posicao = 0;
    
    do{
        printf("Digite a data de nascimento:\n");
        fgets(discente[posicao].dado.nascimento, TAM_NAC, stdin);
        DADO = validaNascimento ( discente[posicao].dado.nascimento );
   }while( DADO == INVALIDO );
  
    posicao++;
    return true;
}

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

bool cadastrarDisciplina(){
    bool solicitaNomeDisciplina( );
    bool solicitaCodigo( );
    bool solicitaSemestre( );
    bool solicitaVagas( );
    bool solicitaQuanMatr( );
    bool solicitaProfessor( );
    
    if( solicitaNomeDisciplina( ) ){
        if( solicitaCodigo( ) ){
            if( solicitaSemestre( ) ){
                if( solicitaVagas( ) ){
                    if( solicitaQuanMatr( ) ){
                        if( solicitaProfessor( ) ){
                            return true;
                        }else{ return false;}
                    }else{ return false;}
                }else{ return false;}
            }else{ return false;}
        }else{ return false;}
    }else{ return false;}
}

bool solicitaNomeDisciplina( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    static int posicao = 0;
    
    do{
        printf("Digite o nome da disciplina:\n");
        fgets(materia[posicao].nome, TAM_NOME_DISC, stdin);
        DADO = validaNomeDiscplina (materia[posicao].nome );
   }while( DADO == INVALIDO );
  
    posicao++;
    return true;
}
bool solicitaCodigo( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    static int posicao = 0;
    
    do{
        printf("Digite o código da disciplina:\n");
        fgets(materia[posicao].codigo, TAM_COD_DISC, stdin);
        DADO = validaCodigo (materia[posicao].codigo );
   }while( DADO == INVALIDO );
  
    posicao++;
    return true;
}
bool solicitaSemestre( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    static int posicao = 0;
    
    do{
        printf("Digite o semestre da disciplina:\n");
        fgets(materia[posicao].semestre, TAM_SEM, stdin);
        DADO = validaSemestre (materia[posicao].semestre);
   }while( DADO == INVALIDO );
  
    posicao++;
    return true;
}
bool solicitaVagas( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    static int posicao = 0;
    
    do{
        printf("Digite o número de vagas da disciplina:\n");
        scanf("%d", &materia[posicao].vagas);
        //testar com getchar dps
        DADO = validaVagas (materia[posicao].vagas);
   }while( DADO == INVALIDO );
  
    posicao++;
    return true;
}
bool solicitaQuanMatr( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    static int posicao = 0;
    
    do{
        printf("Digite a quantidade de matriculados da disciplina:\n");
        scanf( "%d", &materia[posicao].quantidadeMatriculado);
        DADO = validaQuanMatr(materia[posicao].quantidadeMatriculado);
   }while( DADO == INVALIDO );
  
    posicao++;
    return true;
}
bool solicitaProfessor( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    static int posicao = 0;
    
    do{
        printf("Digite o professor da disciplina:\n");
        fgets(materia[posicao].professor.dado.nome, TAM_NOME, stdin);
        DADO = validaProfessores(materia[posicao].professor.dado.nome);
   }while( DADO == INVALIDO );
  
    posicao++;
    return true;
}

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

#endif ///CADASTRO_FILE_H
