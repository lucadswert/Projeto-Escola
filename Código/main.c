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

    ///CHAMA FUNÇÃO DE RECUPERAÇÃO DE DADOS QUANTITATIVOS
    do{ 	
        resposta = menuPrincipal( );
        switch( resposta ){
            case Realizar_Cadastro: cadastrar( ); break;
            case Listar_Informações: listar( ); break;
            case Matricular_Aluno: matricular( ); break;
            case Filtro_por_palavra_chave: filtroPorPalavraChave( ); break;
            case Encerrar_Programa: printf( "<<<<<<<<< Programa Encerrado >>>>>>>>>\n\n" ); break;}
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
                    puts( "\n\t> Ops! Professor não cadastrado! <");
                }else{
                    ///CHAMA FUNÇÃO DE SAVE DADOS CADASTRAIS DE PROFESSORES
                    ///CHAMA FUNÇÃO DE SAVE DADOS QUANTITATIVOS 
                }
                break;
            case Aluno: 
                if( !cadastrarAluno( ) ){
                    puts( "\n\t> Ops! Aluno não cadastrado! <");
                
                }else{
                    //CHAMA FUNÇÃO DE SAVE DADOS CADASTRAIS DE ALUNOS
                    ///CHAMA FUNÇÃO DE SAVE DADOS QUANTITATIVOS  
                }
                break;
            case Disciplina: 
                if( !cadastrarDisciplina( ) ){
                    puts( "\n\t> Ops! Discplina não cadastrada! <");
                }else{
                    ///CHAMA FUNÇÃO DE SAVE DADOS CADASTRAIS DE DISCIPLINAS
                    ///CHAMA FUNÇÃO DE SAVE DADOS QUANTITATIVOS 
                }
                break;
            case Voltar: break;}
    }while( opcao != Voltar );
}
void listar( ){
    void listarProfessores( );
    void listarAlunos( );
    void listarDisciplinas( );
    void aniversarianteMes( );
    
    int menuListar( );
    int opcao = -1;
    enum MENU { Aluno = '1', Professor = '2', Disciplina = '3', 
                Aniversariantes = '4', Voltar = '0'};
    
    do{
        opcao = menuListar( );
        switch( opcao ){
                case Professor:
                    ///CHAMA FUNÇÃO DE RECUPERAÇÃO DE DADOS DE PROFESSORES
                    listarProfessores( );
                    break;
                case Aluno: 
                    ///CHAMA FUNÇÃO DE RECUPERAÇÃO DE DADOS DE ALUNOS
                    listarAlunos( ); 
                    break;
                case Disciplina: 
                    ///CHAMA FUNÇÃO DE RECUPERAÇÃO DE DADOS DE DISCIPLINAS
                    listarDisciplinas( ); 
                    break;
                case Aniversariantes: 
                    ///CHAMA FUNÇÃO DE RECUPERAÇÃO DE DADOS DE ALUNOS
                    ///CHAMA FUNÇÃO DE RECUPERAÇÃO DE DADOS DE PROFESSORES
                    aniversarianteMes( ); 
                    break; 
                case Voltar: break;}
    }while( opcao != Voltar );
}
