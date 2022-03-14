#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "cadastro.h"
#include "listas.h"
#include "menus.h"

int main( ){
    int menuPrincipal(  );
    void cadastrar( ); 
    void listar( );

	char resposta = '\0';
    enum MENU{ Realizar_Cadastro = '1', Listar_Informações = '2', Encerrar_Programa = '0'};
    
    do{ 	
        resposta = menuPrincipal( );
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
    void listarDiscplinas( );
    
    int menuListar( );
    int opcao = -1;
    enum MENU { Aluno = '1', Professor = '2', Disciplina = '3', Voltar = '0'};
    
    do{
        opcao = menuListar( );
        switch( opcao ){
                case Professor: listarProfessores( ); break;
                case Aluno: listarAlunos( ); break;
                case Disciplina: listarDiscplinas( ); break;
                case Voltar: break;   
        }
    }while( opcao != Voltar );
}

