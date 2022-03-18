#ifndef LISTA_FILE_H
#define LISTA_FILE_H

Aluno *ordenaAlunosPorSexo( ); 
Aluno *ordenaAlunosPorOrdemAlfabetica( );
Aluno *ordenaAlunosPorNascimento( );

Professor *ordernaProfessoresPorSexo( );
Professor *ordernaProfessoresPorOrdemAlfabetica( );
Professor *ordernaProfessoresPorNascimento( );

void relatorioAlunos( Aluno[] );
void relatorioProfessores( Professor[] );
void relatorioDisciplinas( Disciplinas[] );

void listarProfessores( ){
    int menuListarProfessor( );
    Professor *professoresOrdenados;
    char resposta = '\0';
    enum MENU{ Filtro_Geral = '1', Filtro_Sexo = '2', Filtro_Nome = '3',
               Filtro_Nascimento = '4', Filtro_Buscar = '5', Filtro_Aniversario = '6', Voltar = '0'};
    
    do{ 	
        resposta = menuListarProfessor( );
        switch( resposta ){
            case Filtro_Geral : 
                relatorioProfessores( docente );
                break;
            case Filtro_Sexo: 
                professoresOrdenados = ordernaProfessoresPorSexo( ); 
                relatorioProfessores( professoresOrdenados );
                break;
            case Filtro_Nome: 
                professoresOrdenados = ordernaProfessoresPorOrdemAlfabetica( ); 
                relatorioProfessores( professoresOrdenados );
                break;
            case Filtro_Nascimento:
                professoresOrdenados = ordernaProfessoresPorNascimento( ); 
                relatorioProfessores( professoresOrdenados );
                break;
            //case Filtro_Buscar : faltaCriar( ); break;
            //case Filtro_Aniversario : faltaCriar( ); break;
            case Voltar: break;}
    }while( resposta != Voltar );
 
}
void listarAlunos( ){
    int menuListarAluno( );
    Aluno *alunosOrdenados;
    char resposta = '\0';
    enum MENU{ Filtro_Geral = '1', Filtro_Sexo = '2', Filtro_Nome = '3', Filtro_Nascimento = '4', Filtro_Buscar = '5', Filtro_Aniversario = '6', Voltar = '0'};
    
    do{ 	
        resposta = menuListarAluno( );
        switch( resposta ){
            case Filtro_Geral:
                relatorioAlunos( discente );
            case Filtro_Sexo: 
                alunosOrdenados = ordenaAlunosPorSexo( );
                relatorioAlunos( alunosOrdenados );
                break;
            case Filtro_Nome: 
                alunosOrdenados = ordenaAlunosPorOrdemAlfabetica( );
                relatorioAlunos( alunosOrdenados );
                break;
            case Filtro_Nascimento: 
                alunosOrdenados = ordenaAlunosPorNascimento( );
                relatorioAlunos( alunosOrdenados );
                break;
            //case Filtro_Buscar : faltaCriar( ); break;
            //case Filtro_Aniversario : faltaCriar( ); break;
            case Voltar: break;
        }
    }while( resposta != Voltar );

  
}
void listarDisciplinas( ){
    int menuListarDisciplinas( );
    Disciplinas *disciplinasOrdenadas;
    char resposta = '\0';
    enum MENU{ Filtro_Geral = '1', Filtro_SemAluno = '2', Filtro_Disciplina = '3', Filtro_Vagas = '4', Voltar = '0'};
    
    do{ 	
        resposta = menuListarDisciplinas( );
        switch( resposta ){
            case Filtro_Geral : 
                relatorioDisciplinas( materia );
                break;
            //case Filtro_SemAluno: 
            //case Filtro_Disciplina : 
            //case Filtro_Vagas : 
            case Voltar: break;}
    }while( resposta != Voltar );
}

Professor *ordernaProfessoresPorSexo( ){
    Professor professoresOrdenados[professoresCadastrados];
    Professor aux;

    for( int posicao = 0; posicao < professoresCadastrados; posicao++ ){
        professoresOrdenados[posicao] = docente[posicao];}
  
    for( int ordenador = professoresCadastrados - 1; ordenador >= 1 ; ordenador--){
		for( int i = 0; i < ordenador; i++ ){
			if( professoresOrdenados[i].dado.sexo > professoresOrdenados[i+1].dado.sexo ){
				aux = professoresOrdenados[i];
                professoresOrdenados[i] = professoresOrdenados[i+1];
                professoresOrdenados[i+1] = aux;}}}
    return professoresOrdenados;
}
Professor *ordernaProfessoresPorOrdemAlfabetica( ){
    Professor professoresOrdenados[professoresCadastrados];
    Professor aux;

    for( int posicao = 0; posicao < professoresCadastrados; posicao++ ){
        professoresOrdenados[posicao] = docente[posicao];}

    for( int ordenador = professoresCadastrados - 1; ordenador >= 1 ; ordenador--){
		for( int i = 0; i < ordenador; i++ ){
			if( (strcmp(professoresOrdenados[i].dado.nome, professoresOrdenados[i+1].dado.nome)) > 0 ){
				strcpy(aux.dado.nome, professoresOrdenados[i].dado.nome);
                strcpy(professoresOrdenados[i].dado.nome, professoresOrdenados[i+1].dado.nome);
                strcpy(professoresOrdenados[i+1].dado.nome, aux.dado.nome);}}}
    return professoresOrdenados;
}
Professor *ordernaProfessoresPorNascimento( ){
    Professor professoresOrdenados[professoresCadastrados],
              aux,
              AAMM_1[ 6 ], AAAA_1[5],
              AAMM_2[ 6 ], AAAA_2[5];

    for( int posicao = 0; posicao < professoresCadastrados; posicao++ ){
        professoresOrdenados[posicao] = docente[posicao];}
    
   for( int ordenador = professoresCadastrados - 1; ordenador >= 1 ; ordenador--){
		for( int i = 0; i < ordenador; i++ ){
            strcpy( AAAA_1, &professoresOrdenados[i].dado.nascimento[6]);
            strcpy( AAAA_2, &professoresOrdenados[i+1].dado.nascimento[6]);
			if( strcmp( AAAA_1, AAAA_2 ) > 0 ){
				strcpy(aux.dado.nascimento, professoresOrdenados[i].dado.nascimento);
                strcpy(professoresOrdenados[i].dado.nascimento, professoresOrdenados[i+1].dado.nascimento);
                strcpy(professoresOrdenados[i+1].dado.nascimento, aux.dado.nascimento);
            }else if( strcmp( AAAA_1, AAAA_2 ) == 0 ){
                strncpy( AAMM_1, professoresOrdenados[i].dado.nascimento, 5 );
                strncpy( AAMM_2, professoresOrdenados[i+1].dado.nascimento, 5 );
                if( strcmp( AAMM_1, AAMM_2 ) > 0 ){
                    strcpy(aux.dado.nascimento, professoresOrdenados[i].dado.nascimento);
                    strcpy(professoresOrdenados[i].dado.nascimento, professoresOrdenados[i+1].dado.nascimento);
                    strcpy(professoresOrdenados[i+1].dado.nascimento, aux.dado.nascimento);}}}}   
    return professoresOrdenados;
}
Aluno *ordenaAlunosPorSexo( ){
    Aluno alunosOrdenados[alunosCadastrados];
    Aluno aux;

    for( int posicao = 0; posicao < alunosCadastrados; posicao++ ){
        alunosOrdenados[posicao] = discente[posicao];}
  
    for( int ordenador = alunosCadastrados - 1; ordenador >= 1 ; ordenador--){
		for( int i = 0; i < ordenador; i++ ){
			if( alunosOrdenados[i].dado.sexo > alunosOrdenados[i+1].dado.sexo ){
				aux = alunosOrdenados[i];
                alunosOrdenados[i] = alunosOrdenados[i+1];
                alunosOrdenados[i+1] = aux;}}}
    return alunosOrdenados;
}
Aluno *ordenaAlunosPorOrdemAlfabetica( ){
    Aluno alunosOrdenados[alunosCadastrados];
    Aluno aux;

    for( int posicao = 0; posicao < alunosCadastrados; posicao++ ){
        alunosOrdenados[posicao] = discente[posicao];}

    for( int ordenador = alunosCadastrados - 1; ordenador >= 1 ; ordenador--){
		for( int i = 0; i < ordenador; i++ ){
			if( (strcmp(alunosOrdenados[i].dado.nome, alunosOrdenados[i+1].dado.nome)) > 0 ){
				strcpy(aux.dado.nome, alunosOrdenados[i].dado.nome);
                strcpy(alunosOrdenados[i].dado.nome, alunosOrdenados[i+1].dado.nome);
                strcpy(alunosOrdenados[i+1].dado.nome, aux.dado.nome);}}}
    return alunosOrdenados;    
}
Aluno *ordenaAlunosPorNascimento ( ){
  Aluno alunosOrdenados[alunosCadastrados];
    Aluno aux, AAMM_1[ 6 ], AAAA_1[5],
               AAMM_2[ 6 ], AAAA_2[5];

    for( int posicao = 0; posicao < alunosCadastrados; posicao++ ){
        alunosOrdenados[posicao] = discente[posicao];}
    
    for( int ordenador = alunosCadastrados - 1; ordenador >= 1 ; ordenador--){
		for( int i = 0; i < ordenador; i++ ){
            strcpy( AAAA_1, &alunosOrdenados[i].dado.nascimento[6]);
            strcpy( AAAA_2, &alunosOrdenados[i+1].dado.nascimento[6]);
			if( strcmp( AAAA_1, AAAA_2 ) > 0 ){
				strcpy(aux.dado.nascimento, alunosOrdenados[i].dado.nascimento);
                strcpy(alunosOrdenados[i].dado.nascimento, alunosOrdenados[i+1].dado.nascimento);
                strcpy(alunosOrdenados[i+1].dado.nascimento, aux.dado.nascimento);
            }else if( strcmp( AAAA_1, AAAA_2 ) == 0 ){
                strncpy( AAMM_1, alunosOrdenados[i].dado.nascimento, 5 );
                strncpy( AAMM_2, alunosOrdenados[i+1].dado.nascimento, 5 );
                if( strcmp( AAMM_1, AAMM_2 ) > 0 ){
                    strcpy(aux.dado.nascimento, alunosOrdenados[i].dado.nascimento);
                    strcpy(alunosOrdenados[i].dado.nascimento, alunosOrdenados[i+1].dado.nascimento);
                    strcpy(alunosOrdenados[i+1].dado.nascimento, aux.dado.nascimento);}}}}
    return alunosOrdenados;
}
void relatorioAlunos( Aluno alunosOrdenados[] ){
    printf( " %*s  %*s  %*s  %*s  %*s  \n", TAM_MAT+4, "MATRÍCULA", TAM_CPF, "CPF", TAM_NAC+11, "NASCIMENTO", 14, "SEXO", 4, "NOME" );
    for( int posicao = 0; posicao < alunosCadastrados; posicao++ ){
        printf( " %*s  %*s  %*s  %*c      %-*s\n", TAM_MAT+5, alunosOrdenados[posicao].dado.matricula, 
                                               TAM_CPF+5, alunosOrdenados[posicao].dado.cpf, 
                                               TAM_NAC+5, alunosOrdenados[posicao].dado.nascimento, 
                                               9, alunosOrdenados[posicao].dado.sexo, 
                                               TAM_NOME, alunosOrdenados[posicao].dado.nome );} 
}
void relatorioProfessores( Professor professoresOrdenados[] ){
    printf( " %*s  %*s  %*s  %*s  %*s  \n", TAM_MAT+5, "MATRÍCULA", TAM_CPF, "CPF", TAM_NAC+11, "NASCIMENTO", 12, "SEXO ", 14, "NOME" );
    for( int posicao = 0; posicao < professoresCadastrados; posicao++ ){
         printf( " %*s  %*s  %*s  %*c          %-s\n", TAM_MAT+5, professoresOrdenados[posicao].dado.matricula,
                                                TAM_CPF+5, professoresOrdenados[posicao].dado.cpf, 
                                                TAM_NAC+5, professoresOrdenados[posicao].dado.nascimento,
                                                9, professoresOrdenados[posicao].dado.sexo, 
                                                professoresOrdenados[posicao].dado.nome );} 
}
void relatorioDisciplinas( Disciplinas disciplinasOrdenadas[] ){
    //printf( "%*s %*s %*s %*c %*s",  );
    for( int posicao = 0; posicao < disciplinasCadastradas; posicao++ ){
         printf("%s  %s  %d %d  %s\n", materia[posicao].codigo, materia[posicao].semestre, 
                                       materia[posicao].vagas, materia[posicao].quantidadeMatriculado, 
                                       materia[posicao].nome );} 
}

#endif //LISTAS_FILE_H

