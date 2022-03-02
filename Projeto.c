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
};
typedef struct professor Professor;

struct aluno{
    Dados dado; 
};
typedef struct aluno Aluno;

struct Disciplinas{
    char nome[TAM_NOME_DISC],
         codigo[TAM_COD_DISC],
         semestre[TAM_SEM];
    int vagas,
        quantidadeMatriculado;
    Professor professor;
};

int quantidadeProfessor = 0,
    quantidadeAluno = 0,
    quantidadeDisciplinas = 0;

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
    char resposta = '\0';
    enum MENU { Professor = '1', Aluno = '2', Disciplina = '3', Voltar = '0'};

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

    puts( "\t>>>> OPÇÃO EM MANUTENÇÃO <<<<\n" ); 
}
void listar( ){
    char resposta = '\0';
    enum MENU { Professor = '1', Aluno = '2', Disciplina = '3', Voltar = '0' };

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

    puts( "\t>>>> OPÇÃO EM MANUTENÇÃO <<<<\n" );
};