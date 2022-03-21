#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "cadastro.h"
#include "listas.h"
#include "menus.h"
#include "matricula.h"

int main( ){
    int menuPrincipal(  );
    void cadastrar( ); 
    void listar( );
	void matricular( );

	char resposta = '\0';
    enum MENU{ Realizar_Cadastro = '1', Listar_Informações = '2', 
               Matricular_Aluno = '3', Filtro_por_palavra_chave = '4',
               Encerrar_Programa = '0'};
    
    do{ 	
        resposta = menuPrincipal( );
        switch( resposta ){
            case Realizar_Cadastro : cadastrar( ); break;
            case Listar_Informações: listar( ); break;
            case Matricular_Aluno : matricular( ); break;
            case Filtro_por_palavra_chave: filtroPorPalavraChave( ); break;
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
            case Aluno: 
                if( !cadastrarAluno( ) ){
                    puts( "\n\tOps!Aluno não cadastrado! ");}
                break;
            case Disciplina: 
                if( !cadastrarDisciplina( ) ){
                    puts( "\n\tOps!Discplina não cadastrada! ");}
                break;
            case Voltar: break;     
        }
    }while( opcao != Voltar );
}
void listar( ){
    void listarProfessores( );
    void listarAlunos( );
    void listarDisciplinas( );
    void aniversarianteMes( );
    
    int menuListar( );
    int opcao = -1;
    enum MENU { Aluno = '1', Professor = '2', Disciplina = '3', Aniversariantes = '4', Voltar = '0'};
    
    do{
        opcao = menuListar( );
        switch( opcao ){
                case Professor: listarProfessores( ); break;
                case Aluno: listarAlunos( ); break;
                case Disciplina: listarDisciplinas( ); break;
                case Aniversariantes: aniversarianteMes( ); break; 
                case Voltar: break;   
        }
    }while( opcao != Voltar );
}

void matricular( ){
    bool solicitaCodigoMatricula( char[] ); 
    char codigoDeMatricula[TAM_COD_MAT];
    
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    static int disciplina = 0;
    
    do{
        DADO = solicitaCodigoMatricula( codigoDeMatricula );
        if( !DADO == INVALIDO ){
            strcpy( &codigoDeMatricula[0], (caixaAlta( &codigoDeMatricula[0] )) );
            for( int i = 0; i < disciplinasCadastradas; i++){
                if( (strcmp( &codigoDeMatricula[12], materia[i].codigo )) == 0 ){
                    int matriculaAluno[TAM_MAT - 1];
                    strncpy( matriculaAluno, codigoDeMatricula, TAM_MAT - 2 );
                    for( int x = 0; x < alunosCadastrados; x++ ){
                        if ( (strcmp(matriculaAluno, discente[x].dado.matricula  )) == 0  ){
                            materia[i].turma[materia[i].quantidadeMatriculado] = &discente[x];
                            materia[i].quantidadeMatriculado++;
                            materia[i].vagas--;
                            if( disciplina < TAM_MATRIZ ){
                                discente[x].matrizCurricular[disciplina++] = i;}
                            printf( "%s cadastrado em %s \n", discente[x].dado.nome, materia[i].nome );
                            break;
                        }else if( x == alunosCadastrados - 1 ){ puts( "Aluno não cadastrado" );}
                    }break;
                }else if (i == disciplinasCadastradas - 1) { puts( "Disciplina não cadastrada" ); }
            }
        }
    }while( DADO != INVALIDO );
}