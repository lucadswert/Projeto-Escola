#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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

char *validaMatricula( char *matricula );
char *validaCpf( char *cpf );
char *validaSexo( char *sexo );
char *validaNascimento( char *data );
char *validaNome( char *nome );
///Adicionar função de limpeza de buffer para caso o usuário insira uma quantidade de dados maior do que ///a solicitada

int main( ){
    void cadastrar( ); 
    void listar( );

	char resposta = '\0';

    enum MENU{ Realizar_Cadastro = '1', Listar_Informações = '2', Encerrar_Programa = '0'};
    
    
    do{ 	
        do{
            puts( "=====================================\n"
                  "            PROJETO ESCOLA           \n"
                  "=====================================\n");
            printf ("MENU PRINCIPAL\n"
                    "[1] | Realizar Cadastro\n"
                    "[2] | Listar Informações\n"
                    "[0] | Encerrar Programa\n\n-> ");
            resposta = getchar( ); getchar( ); 
            if( !(resposta == Realizar_Cadastro) && !(resposta == Listar_Informações) && !(resposta == Encerrar_Programa) ){
                puts("   ^ Valor inserido inválido! \n");
            }else putchar('\n');
        }while( !(resposta == Realizar_Cadastro) && !(resposta == Listar_Informações) &&  !(resposta == Encerrar_Programa) );
        
        switch( resposta ){
            case Realizar_Cadastro : cadastrar( ); break;
            case Listar_Informações: listar( ); break;
            case Encerrar_Programa: printf ("Programa Encerrado\n"); break;}
    }while( resposta != Encerrar_Programa );

    return EXIT_SUCCESS;
}
void cadastrar( ){
    int menuCadastrar( );
    bool cadastrarAluno( );
    bool cadastrarProfessor( ); 
    bool cadastrarDisciplina( );
    int opcao = -1;
    enum MENU { Aluno = '1', Professor = '2',  Disciplina = '3', Voltar = '0'};
    
    do{
        opcao = menuCadastrar( );
        switch( opcao ){
            case Professor: 
                if( !cadastrarProfessor( ) ){
                    puts( "\n\tOps!Professor não cadastrado! ");}
                break;
           // case Aluno: cadastrarAluno(); break;
            //case Disciplina: cadastrarDisciplina(); break;
            //case Voltar: break;     
        }
    }while( opcao != Voltar );
}
void listar( ){
    int menuListar( );
    int opcao = -1;
    
    enum MENU { Aluno = '1', Professor = '2', Disciplina = '3', Voltar = '0'};
    do{
        opcao = menuListar( );
        switch( opcao ){
                case Professor: 
                 //   printf("Matricula: %s\n", docente.dado.matricula);
                  //  printf("Nome: %s\n", docente.dado.nome);               
                  //  printf("Sexo: %c\n", docente.dado.sexo);  
                //    printf("CPF: %s\n", docente.dado.cpf);  
                  //  printf("Nascimento: %s\n", docente.dado.nascimento);  
                    break;
                    
                case Aluno: 
                   // printf("Matricula: %s\n", discente.dado.matricula);
                 //   printf("Nome: %s\n", discente.dado.nome);               
                  //  printf("Sexo: %c\n", discente.dado.sexo);  
                  //  printf("CPF: %s\n", discente.dado.cpf);  
                  //  printf("Nascimento: %s\n", discente.dado.nascimento);
                    break;
                  
                case Disciplina: 
                   // printf("Materia: %s\n", materia.nome);
                   // printf("Codigo: %s\n", materia.codigo);               
                   // printf("Semestre: %s\n", materia.semestre);   
                   // printf("Vagas: %d\n", materia.vagas);  
                    //printf("Professor: %s\n", materia.professor.dado.nome);
                    break;
                
                  case Voltar: 
                  //puts( "\t>>>> OPÇÃO EM MANUTENÇÃO <<<<\n" ); 
                  break;   
        }
    }while( opcao != Voltar );
    
    //puts( "\t>>>> OPÇÃO EM MANUTENÇÃO <<<<\n" );
}
int menuCadastrar( ){
    char resposta = '\0';
    enum MENU { Aluno = '1', Professor = '2', Disciplina = '3', Voltar = '0'};
    
    do{
        puts( "=====================================\n"
              "             MENU CADASTRO           \n"
              "=====================================\n");	
        printf( "CADASTRAR: \n"	
                "[1] | Aluno\n"
                "[2] | Professor\n"
                "[3] | Disciplina\n"
                "[0] | Voltar\n\n-> ");
        resposta = getchar( ); getchar( );
        if( !(resposta == Professor) && !(resposta == Aluno) && !(resposta == Disciplina) && !(resposta == Voltar) ){
                puts("   ^ Valor inserido inválido! \n");
        }else putchar('\n');
    }while( !(resposta == Professor) && !(resposta == Aluno) && !(resposta == Disciplina) && !(resposta == Voltar) );    
    
    return resposta;
}
int menuListar( ){
    char resposta = '\0';
    enum MENU { Aluno = '1', Professor = '2', Disciplina = '3', Voltar = '0'};

    do{
        puts("=====================================\n"
             "             MENU LISTAS             \n"
             "=====================================\n");	
        printf( "LISTAR: \n"	
                "[1] | Aluno\n"
                "[2] | Professor\n"
                "[3] | Disciplina\n"	
                "[0] | Voltar\n\n-> " );
        resposta = getchar( ); getchar( ); 
        if( !(resposta == Professor) && !(resposta == Aluno) && !(resposta == Disciplina) && !(resposta == Voltar)){
             puts("   ^ Valor inserido inválido! \n");
        }else putchar('\n');
    }while( !(resposta == Professor) && !(resposta == Aluno) && !(resposta == Disciplina) && !(resposta == Voltar) );

    return resposta;
    
}
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
    char *mensagemDeErro = NULL;
    static int posicao = 0;
    
    do{
        printf("Digite o numero de matricula: \n");
        fgets((docente[posicao].dado.matricula), TAM_MAT, stdin);
        ///criar função que tirar o \n do final da string e inserir ela aqui tb
        mensagemDeErro = validaMatricula( docente[posicao].dado.matricula );
        if( mensagemDeErro != NULL ){
            puts( mensagemDeErro ); }
    }while( mensagemDeErro != NULL );
    
    posicao++;
    return true;
}
char *validaMatricula( char *matricula ){
  //FaltaFazer//
    return NULL;
}

bool solicitaNomeProfessor( ){
    char *mensagemDeErro = NULL;
    static int posicao = 0;
    do{
        printf("Digite o nome do professor:\n");
        fgets(docente[posicao].dado.nome, TAM_NOME, stdin);
        mensagemDeErro = validaNome (docente[posicao].dado.nome );
        if( mensagemDeErro != NULL ){
            puts (mensagemDeErro); }
   }while( mensagemDeErro != NULL );
  
    posicao++;
    return true;
}
char *validaNome (char *nome){
    //FaltaFazer//
    return NULL;
}

bool solicitaNascimentoProfessor( ){
    char *mensagemDeErro = NULL;
    static int posicao = 0;
    do{
    printf("Digite a data de nascimento:\n");
    fgets(docente[posicao].dado.nascimento, TAM_NAC, stdin);
    mensagemDeErro = validaNascimento ( docente[posicao].dado.nascimento );
    if( mensagemDeErro != NULL ){
            puts (mensagemDeErro); }
   }while( mensagemDeErro != NULL );
  
    posicao++;
    return true;
}

char *validaNascimento (char *data){
    //FaltaFazer//
    return NULL;
}


bool solicitaCpfProfessor(){
    char *mensagemDeErro = NULL;
    static int posicao = 0;
    do{
    printf("Digite o CPF:\n");
    fgets(docente[posicao].dado.cpf, TAM_CPF, stdin);
    mensagemDeErro = validaCpf ( docente[posicao].dado.cpf );
    if( mensagemDeErro != NULL ){
        puts (mensagemDeErro); }
   }while( mensagemDeErro != NULL );

    posicao++;  
    return true;
}
char *validaCpf (char *cpf){
    //FaltaFazer//
    return NULL;
}

  bool solicitaSexoProfessor( ){
    char *mensagemDeErro = NULL;
    static int posicao = 0;
    do{
    printf("Digite o sexo:\n");
    scanf("%c", &docente[posicao].dado.sexo);
    getchar( );
    mensagemDeErro = validaSexo (docente[posicao].dado.sexo);
    if( mensagemDeErro != NULL ){
        puts (mensagemDeErro); }
   }while( mensagemDeErro != NULL );

    posicao++; 
    return true;
}
char *validaSexo( char sexo ){
    //FaltaFazer//
    return NULL;
  }
bool cadastrarAluno(){
                 
    printf("Digite o nome do aluno: ");
    fgets(discente[0].dado.nome, TAM_NOME, stdin);

    printf("Digite o sexo: ");
    scanf("%c", &discente[0].dado.sexo);
    getchar( );

    printf("Digite o CPF: ");
    fgets(discente[0].dado.cpf, TAM_CPF, stdin);

    printf("Digite a data de nascimento: ");
    fgets(discente[0].dado.nascimento, TAM_NAC, stdin);
    return true;
}
bool cadastrarDisciplina(){
    printf("Digite o nome da disciplina: ");
    fgets(materia[0].nome, TAM_NOME_DISC, stdin);
               
    printf("Digite o código da matéria: ");
    fgets(materia[0].codigo, TAM_COD_DISC, stdin);

    printf("Digite a quantidade de vagas: ");
    scanf("%d", &materia[0].vagas);

    printf("Digite o semestre: ");
    fgets(materia[0].semestre, TAM_SEM, stdin);

    printf("Digite o professor da matéria: ");
    fgets(materia[0].professor.dado.nome, TAM_NOME, stdin);
  
    return true;
}

