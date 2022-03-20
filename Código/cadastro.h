 #include "valida.h"

#ifndef CADASTRO_FILE_H
#define CADASTRO_FILE_H

bool cadastrarProfessor( ){
    bool solicitaMatriculaProfessor( );
    bool solicitaNomeProfessor( );
    bool solicitaNascimentoProfessor( );
    bool solicitaCpfProfessor( );
    bool solicitaSexoProfessor( );

    if( professoresCadastrados < quantMaxProfessor ){ 
        for( int posicao = 0; posicao < TAM_MINIS; posicao++ ){
            docente[professoresCadastrados].ministrando[posicao] = -1;}
        professoresCadastrados++;
        if( solicitaMatriculaProfessor( ) )
            if( solicitaNomeProfessor( ) ) 
                if( solicitaNascimentoProfessor( ) )
                    if( solicitaCpfProfessor( ) )
                        if( solicitaSexoProfessor( ) ){
                            return true;}
        professoresCadastrados--; 
        return false; 
    }else{  
        puts( "Quantidae máxima atingida!" );
        return false; }
}

bool solicitaMatriculaProfessor( ){ 
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    int posicao = professoresCadastrados - 1;
    
    do{
        printf("Digite o numero de matricula: \n");
        fgets((docente[posicao].dado.matricula), TAM_MAT, stdin);
        
        if( sair( docente[posicao].dado.matricula[0], docente[posicao].dado.matricula[1] ) ){ 
            return false;
        }else{
            limpaTexto(docente[posicao].dado.matricula);
            DADO = validaMatricula( docente[posicao].dado.matricula );
            if( DADO == VALIDO && ( verificaMatriculaProfessor( 1, docente[posicao].dado.matricula )
                || verificaMatriculaAluno( 0, docente[posicao].dado.matricula ) ) ){
                puts( "Matricula repetida");
                DADO = INVALIDO;}}
    }while( DADO == INVALIDO );
    
    return true;
}
bool solicitaNomeProfessor( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    int posicao = professoresCadastrados - 1;
    
    do{
        printf("Digite o nome do professor:\n");
        fgets(docente[posicao].dado.nome, TAM_NOME, stdin);
        limpaTexto(docente[posicao].dado.nome);
        
        if( sair( docente[posicao].dado.nome[0], docente[posicao].dado.nome[1] ) ){              
            return false;
        }else{ 
            DADO = validaNome( docente[posicao].dado.nome );}
    }while( DADO == INVALIDO );
    
    padronizaNome( docente[posicao].dado.nome );
    return true;
}
bool solicitaNascimentoProfessor( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    int posicao = professoresCadastrados - 1;
    
    do{
        printf("Digite a data de nascimento:\n");
        fgets(docente[posicao].dado.nascimento, TAM_NAC, stdin);
        limpaTexto(docente[posicao].dado.nascimento);
        
        if( sair( docente[posicao].dado.nascimento[0], docente[posicao].dado.nascimento[1] ) ){ 
            return false;
        }else{ DADO = validaNascimento ( docente[posicao].dado.nascimento );}
    }while( DADO == INVALIDO );
    
    return true;
}
bool solicitaCpfProfessor(){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    int posicao = professoresCadastrados - 1;
    
    do{
        printf("Digite o CPF:\n");
        fgets(docente[posicao].dado.cpf, TAM_CPF, stdin);
        
        if( sair( docente[posicao].dado.cpf[0], docente[posicao].dado.cpf[1] ) ){               
            return false;
        }else{ 
            limpaTexto(docente[posicao].dado.cpf);
            DADO = validaCpf ( docente[posicao].dado.cpf );            
            if( DADO == VALIDO && ( verificaCpfProfessor( 1, docente[posicao].dado.cpf )
                || verificaCpfAluno( 0, docente[posicao].dado.cpf ) ) ){
                puts( "CPF repetido");
                DADO = INVALIDO;}}
    }while( DADO == INVALIDO );
    
    return true;
}
bool solicitaSexoProfessor( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    int posicao = professoresCadastrados - 1;
    char TesteSaida[4]; 
    
    do{
        printf("Digite o sexo:\n");
        fgets( TesteSaida, 4, stdin);
        
        if( sair( TesteSaida[0], TesteSaida[1] ) ){              
            return false;
        }else{ 
            docente[posicao].dado.sexo = TesteSaida[0];
            DADO = validaSexo(docente[posicao].dado.sexo);}
    }while( DADO == INVALIDO );
    if( docente[posicao].dado.sexo == 'f' || docente[posicao].dado.sexo == 'm'  ){
      docente[posicao].dado.sexo = docente[posicao].dado.sexo - 32;
      return true;
    }
    else { 
      return true;}
}

bool cadastrarAluno(){
    bool solicitaMatriculaAluno( );
    bool solicitaNomeAluno( );
    bool solicitaNascimentoAluno( );
    bool solicitaCpfAluno( );
    bool solicitaSexoAluno( );

    if( alunosCadastrados < quantMaxAluno ){ 
        for( int posicao = 0; posicao < TAM_MATRIZ; posicao++ ){
            discente[alunosCadastrados].matrizCurricular[posicao] = -1;}
        alunosCadastrados++;
        //if( solicitaMatriculaAluno( ) )
           if( solicitaNomeAluno( ) ) 
                if( solicitaNascimentoAluno( ) )
                   // if( solicitaCpfAluno( ) )
                       // if( solicitaSexoAluno( ) )
                            return true;
        alunosCadastrados--;
        return false; 
    }else{  
        puts( "Quantidade máxima atingida!" );
        return false; }
}  

bool solicitaMatriculaAluno( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    int posicao = alunosCadastrados - 1;
    
    do{
        printf("Digite a matricula do Aluno:\n");
        fgets(discente[posicao].dado.matricula, TAM_MAT, stdin);
        
        if( sair( discente[posicao].dado.matricula[0], discente[posicao].dado.matricula[1] ) ){
            return false;
        }else{ 
            limpaTexto(discente[posicao].dado.matricula);
            DADO = validaMatricula(discente[posicao].dado.matricula );
            if( DADO == VALIDO && ( verificaMatriculaProfessor( 0, discente[posicao].dado.matricula )
                || verificaMatriculaAluno( 1, discente[posicao].dado.matricula ) ) ){
                puts( "Matricula repetida");
                DADO = INVALIDO;}}
    }while( DADO == INVALIDO );
    return true;
}
bool solicitaNomeAluno(){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    int posicao = alunosCadastrados - 1;
    
    do{
        printf("Digite o nome do Aluno:\n");
        fgets(discente[posicao].dado.nome, TAM_NOME, stdin);
        limpaTexto(discente[posicao].dado.nome);
        if( sair( discente[posicao].dado.nome[0], discente[posicao].dado.nome[1]) ){
            return false;
        }else{ DADO = validaNome( discente[posicao].dado.nome );}
    }while( DADO == INVALIDO );
    
    padronizaNome( discente[posicao].dado.nome );
    return true;
} 
bool solicitaSexoAluno( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    int posicao = alunosCadastrados - 1;
    char testeSaida[4];
    
    do{
        printf("Digite o sexo:\n");
        fgets( testeSaida, 3, stdin );
        
        if( sair( testeSaida[0], testeSaida[1] ) ){ 
            return false;
        }else{ 
            discente[posicao].dado.sexo = testeSaida[0];
            DADO = validaSexo (discente[posicao].dado.sexo);}
    }while( DADO == INVALIDO );
    if( discente[posicao].dado.sexo == 'f' || discente[posicao].dado.sexo == 'm'  ){
      discente[posicao].dado.sexo = discente[posicao].dado.sexo - 32;
      return true;
    }
    else { 
      return true;}
}
bool solicitaCpfAluno( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    int posicao = alunosCadastrados - 1;
    
    do{
        printf("Digite o CPF:\n");
        fgets(discente[posicao].dado.cpf, TAM_CPF, stdin);
        
        if( sair( discente[posicao].dado.cpf[0], discente[posicao].dado.cpf[1])){
            return false;
        }else{ 
            limpaTexto(discente[posicao].dado.cpf);
            DADO = validaCpf ( discente[posicao].dado.cpf );
            if( DADO == VALIDO && ( verificaCpfAluno( 1, discente[posicao].dado.cpf )
                || verificaCpfProfessor( 0, discente[posicao].dado.cpf ) ) ){
                puts( "CPF repetido");
                DADO = INVALIDO;}}
    }while( DADO == INVALIDO );
 
    return true;
}
bool solicitaNascimentoAluno( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    int posicao = alunosCadastrados - 1;
    
    do{
        printf("Digite a data de nascimento:\n");
        fgets(discente[posicao].dado.nascimento, TAM_NAC, stdin);
        
        if( sair(discente[posicao].dado.nascimento[0],discente[posicao].dado.nascimento[1] )){
            return false;
        }else{ 
            limpaTexto(discente[posicao].dado.nascimento);
            DADO = validaNascimento ( discente[posicao].dado.nascimento );}
    }while( DADO == INVALIDO );
  
    return true;
}

bool cadastrarDisciplina(){
    bool solicitaNomeDisciplina( );
    bool solicitaCodigo( );
    bool solicitaSemestre( );
    bool solicitaVagas( );
    bool solicitaProfessor( );
    
    if( disciplinasCadastradas < quantMaxDisciplina ){
        disciplinasCadastradas++;
        if( solicitaNomeDisciplina( ) )
            if( solicitaCodigo( ) )
                if( solicitaSemestre( ) )
                    if( solicitaVagas( ) )
                       if( solicitaProfessor( ) ){ 
                           return true;}
        disciplinasCadastradas--;
        return false;
    }else{  
        puts( "Quantidae máxima atingida!" );
        return false; }
}

bool solicitaNomeDisciplina( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    int posicao = disciplinasCadastradas - 1;
    
    do{
        printf("Digite o nome da disciplina:\n");
        fgets(materia[posicao].nome, TAM_NOME_DISC, stdin);
        
        if( sair( materia[posicao].nome[0], materia[posicao].nome[1] )){
            return false;
        }else{
            limpaTexto(materia[posicao].nome);
            strcpy( materia[posicao].nome, caixaAlta( materia[posicao].nome ) );
            DADO = validaNomeDisciplina(materia[posicao].nome );}
    }while( DADO == INVALIDO );

    return true;
}
bool solicitaCodigo( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    int posicao = disciplinasCadastradas - 1;
    
    do{
        printf("Digite o código da disciplina:\n");
        fgets(materia[posicao].codigo, TAM_COD_DISC, stdin);
        
        if( sair( materia[posicao].codigo[0], materia[posicao].codigo[1] ) ){
            return false;
        }else{
            limpaTexto(materia[posicao].codigo);
            strcpy( materia[posicao].codigo, caixaAlta(materia[posicao].codigo ) );
            DADO = validaCodigo (materia[posicao].codigo );} 
            if( DADO == VALIDO && ( verificaCodigoDisciplina( 1 ,materia[posicao].codigo ) > -1 ) ){
                puts( "Codigo associado a outra disciplina" );
                DADO = INVALIDO;}
    }while( DADO == INVALIDO );
  
    return true;
}
bool solicitaSemestre( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    int posicao = disciplinasCadastradas - 1;
    
    do{
        printf("Digite o semestre da disciplina:\n");
        fgets(materia[posicao].semestre, TAM_SEM, stdin);
        
        if( sair( materia[posicao].semestre[0], materia[posicao].semestre[1] ) ){
            return false;
        }else{
            limpaTexto(materia[posicao].semestre);
            DADO = validaSemestre (materia[posicao].semestre);}
    }while( DADO == INVALIDO );

    return true;
}
bool solicitaVagas( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    int posicao = disciplinasCadastradas - 1;
    char testeSaida[4];
        
    do{
        printf("Digite o número de vagas da disciplina:\n");
        fgets( testeSaida, 4, stdin );
        
        if( sair(testeSaida[0], testeSaida[1] ) ){
            return false;
        }else{ //aprimorar
            materia[posicao].vagas = charParaInt( testeSaida[0] )*10 + charParaInt( testeSaida[1] );
            DADO = validaVagas(materia[posicao].vagas);}
            materia[posicao].turma = (Aluno*)malloc( (materia[posicao].vagas) * sizeof(Aluno**) );
    }while( DADO == INVALIDO );
  
    return true;
}
bool solicitaProfessor( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    int posicao = disciplinasCadastradas - 1;
    
    do{
        printf("Digite o professor da disciplina:\n");
        fgets(materia[posicao].professor.dado.nome, TAM_NOME, stdin);
        
        if( sair( materia[posicao].professor.dado.nome[0], materia[posicao].professor.dado.nome[1] ) ){
            return false;
        }else{
            limpaTexto(materia[posicao].professor.dado.nome);
            DADO = validaProfessores(materia[posicao].professor.dado.nome);} 
    }while( DADO == INVALIDO );
    padronizaNome( materia[posicao].professor.dado.nome );
    docente[verificaNomeProfessor( 1, materia[posicao].professor.dado.nome)].ministrando[disciplinasCadastradas] = posicao;  
    
    return true;
}
#endif ///CADASTRO_FILE_H
