#include "valida.h"

#ifndef CADASTRO_FILE_H
#define CADASTRO_FILE_H

bool cadastrarProfessor( ){
    bool solicitaMatriculaProfessor( );
    bool solicitaNomeProfessor( );
    bool solicitaNascimentoProfessor( );
    bool solicitaCpfProfessor( );
    bool solicitaSexoProfessor( );
    
    if( (solicitaMatriculaProfessor( )) == true ){
        //if( (solicitaNomeProfessor( )) == true) {
            //if( solicitaNascimentoProfessor( ) == true){
                if( solicitaCpfProfessor( ) == true){
                    //if( solicitaSexoProfessor( ) == true){
                        professoresCadastrados++;
                        //printf("Quantidade de professores cadastrados: %d\n",               
                        //professoresCadastrados);
                       
                        return true;
                    //}else{ return false;}
                }else{ return false; }
            //}else{ return false; }
        //}else{ return false;}
    }else{ return false;}
}

bool solicitaMatriculaProfessor( ){ 
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    static int posicao = 0;

    do{
        printf("Digite o numero de matricula: \n");
        fgets((docente[posicao].dado.matricula), TAM_MAT, stdin);
        limpaTexto(docente[posicao].dado.matricula);
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
        limpaTexto(docente[posicao].dado.nome);
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
        limpaTexto(docente[posicao].dado.nascimento);
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
        limpaTexto(docente[posicao].dado.cpf);
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
       // if( solicitaNomeAluno( ) == true) {
            //if( solicitaNascimentoAluno( ) == true){
                if( solicitaCpfAluno( ) == true){
                    if( solicitaSexoAluno( ) == true){
                        alunosCadastrados++;
                        return true;
                    }else{ return false;}
                }else{ return false; }
            //else{ return false; }
       // }else{ return false;}
    }else{ return false;}
}  

bool solicitaMatriculaAluno( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    static int posicao = 0;
    
    do{
        printf("Digite a matricula do Aluno:\n");
        fgets(discente[posicao].dado.matricula, TAM_MAT, stdin);
        limpaTexto(discente[posicao].dado.matricula);
        DADO = validaMatricula(discente[posicao].dado.matricula );
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
        limpaTexto(discente[posicao].dado.nome);
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
        limpaTexto(discente[posicao].dado.cpf);
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
        limpaTexto(discente[posicao].dado.nascimento);
        DADO = validaNascimento ( discente[posicao].dado.nascimento );
   }while( DADO == INVALIDO );
  
    posicao++;
    return true;
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
            //if( solicitaSemestre( ) ){
              //  if( solicitaVagas( ) ){
                   // if( solicitaQuanMatr( ) ){
                       // if( solicitaProfessor( ) ){
                            disciplinasCadastradas++;
                            return true;
                        //}else{ return false;}
                 //   }else{ return false;}
               // }else{ return false;}
           // }else{ return false;}
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
        limpaTexto(materia[posicao].nome);
        DADO = validaNomeDisciplina(materia[posicao].nome );
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
        limpaTexto(materia[posicao].codigo);
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
        limpaTexto(materia[posicao].semestre);
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
  //Ver se será inserido pelo usuário ou pelo sistema//
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    static int posicao = 0;
    
    do{
        printf("Digite a quantidade de matriculados da disciplina:\n");
        scanf( "%d", &materia[posicao].quantidadeMatriculado);
        getchar();
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
        limpaTexto(materia[posicao].professor.dado.nome);
        DADO = validaProfessores(materia[posicao].professor.dado.nome);
   }while( DADO == INVALIDO );
  
    posicao++;
    return true;
}
#endif ///CADASTRO_FILE_H
