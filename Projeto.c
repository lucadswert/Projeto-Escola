#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "cadastroSolicita.h"


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
            case Aluno: cadastrarAluno(); break;
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


