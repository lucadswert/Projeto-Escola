#ifndef LISTA_FILE_H
#define LISTA_FILE_H

void ordenaAlunosPorSexo( Aluno * ); 
void ordenaAlunosPorOrdemAlfabetica( Aluno * );
void ordenaAlunosPorNascimento( Aluno * );

void ordernaProfessoresPorSexo( Professor* );
void ordernaProfessoresPorOrdemAlfabetica(  Professor* );
void ordernaProfessoresPorNascimento( Professor* );

void relatorioAlunos( Aluno[] );
void relatorioProfessores( Professor[] );
void relatorioDisciplinas( );
void disciplinaComAlunos( int );

void listarProfessores( ){
    int menuListarProfessor( );
    Professor professoresOrdenados[professoresCadastrados];
    char resposta = '\0';
    enum MENU{ Filtro_Geral = '1', Filtro_Sexo = '2', Filtro_Nome = '3',
               Filtro_Nascimento = '4', Filtro_Buscar = '5', 
               Filtro_Aniversario = '6', Voltar = '0'};
    
    if( professoresCadastrados > 0 ){
        for( int posicao = 0; posicao < professoresCadastrados; posicao++ ){
            professoresOrdenados[posicao] = docente[posicao];}
        do{ 	
            resposta = menuListarProfessor( );
            switch( resposta ){
                case Filtro_Geral : 
                    relatorioProfessores( docente );
                    break;
                case Filtro_Sexo: 
                    ordernaProfessoresPorSexo( professoresOrdenados ); 
                    relatorioProfessores( professoresOrdenados );
                    break;
                case Filtro_Nome: 
                    ordernaProfessoresPorOrdemAlfabetica( professoresOrdenados ); 
                    relatorioProfessores( professoresOrdenados );
                    break;
                case Filtro_Nascimento:
                    ordernaProfessoresPorNascimento( professoresOrdenados ); 
                    relatorioProfessores( professoresOrdenados );
                    break;
                //case Filtro_Buscar : faltaCriar( ); break;
                //case Filtro_Aniversario : faltaCriar( ); break;
                case Voltar: break;}
        }while( resposta != Voltar );
    }else{ puts( "\tNão há professores cadastrados" );}
}
void listarAlunos( ){
    int menuListarAluno( );
    Aluno alunosOrdenados[alunosCadastrados];
    char resposta = '\0';
    enum MENU{ Filtro_Geral = '1', Filtro_Sexo = '2', Filtro_Nome = '3', 
               Filtro_Nascimento = '4', Filtro_Buscar = '5',
               Filtro_Aniversario = '6', Voltar = '0'};

    if( alunosCadastrados > 0 ){ 
        for( int posicao = 0; posicao < alunosCadastrados; posicao++ ){
            alunosOrdenados[posicao] = discente[posicao];}
      
        do{ 	
            resposta = menuListarAluno( );
            switch( resposta ){
                case Filtro_Geral:
                    relatorioAlunos( discente );
                case Filtro_Sexo: 
                    ordenaAlunosPorSexo( alunosOrdenados );
                    relatorioAlunos( alunosOrdenados );
                    break;
                case Filtro_Nome: 
                    ordenaAlunosPorOrdemAlfabetica( alunosOrdenados );
                    relatorioAlunos( alunosOrdenados );
                    break;
                case Filtro_Nascimento: 
                    ordenaAlunosPorNascimento( alunosOrdenados );
                    relatorioAlunos( alunosOrdenados );
                    break;
                //case Filtro_Buscar : faltaCriar( ); break;
                //case Filtro_Aniversario : faltaCriar( ); break;
                case Voltar: break;
            }
        }while( resposta != Voltar );
    }else{ puts( "\tNão há alunos cadastrados" );}
}
void listarDisciplinas( ){
    int solicitaCodigoFiltro( );
    int posicao;
    int menuListarDisciplinas( );
    char resposta = '\0';
    enum MENU{ Filtro_Geral = '1', Filtro_disciplinas_com_alunos = '2',
               Filtro_disciplinas_vagas = '3', Voltar = '0'};
    
    if( disciplinasCadastradas > 0 ){ 
        do{ 	
            resposta = menuListarDisciplinas( );
            switch( resposta ){
                case Filtro_Geral : 
                    relatorioDisciplinas( );
                    break;
                case Filtro_disciplinas_com_alunos:
                    posicao = solicitaCodigoFiltro( );
                    if( posicao > -1 ){
                        disciplinaComAlunos( posicao );}
                    break;
                //case Filtro_Vagas : 
                case Voltar: break;}
        }while( resposta != Voltar );
    }else{ puts( "\tNão há disciplinas cadastradas" );}
}

void ordernaProfessoresPorSexo( Professor *professores ){
    Professor aux;
  
    for( int ordenador = professoresCadastrados - 1; ordenador >= 1 ; ordenador--){
		for( int i = 0; i < ordenador; i++ ){
			if( professores[i].dado.sexo > professores[i+1].dado.sexo ){
				aux = professores[i];
                professores[i] = professores[i+1];
                professores[i+1] = aux;}}}
}
void ordernaProfessoresPorOrdemAlfabetica( Professor *professores ){
    Professor aux;
    
    for( int ordenador = professoresCadastrados - 1; ordenador >= 1 ; ordenador--){
		for( int i = 0; i < ordenador; i++ ){
			if( (strcmp(professores[i].dado.nome, professores[i+1].dado.nome)) > 0 ){
				strcpy(aux.dado.nome, professores[i].dado.nome);
                strcpy(professores[i].dado.nome, professores[i+1].dado.nome);
                strcpy(professores[i+1].dado.nome, aux.dado.nome);}}}
}
void ordernaProfessoresPorNascimento( Professor *professores ){
    Professor aux,
              AAMM_1[ 6 ], AAAA_1[5],
              AAMM_2[ 6 ], AAAA_2[5];
    
   for( int ordenador = professoresCadastrados - 1; ordenador >= 1 ; ordenador--){
		for( int i = 0; i < ordenador; i++ ){
            strcpy( AAAA_1, &professores[i].dado.nascimento[6]);
            strcpy( AAAA_2, &professores[i+1].dado.nascimento[6]);
			if( strcmp( AAAA_1, AAAA_2 ) > 0 ){
				strcpy(aux.dado.nascimento, professores[i].dado.nascimento);
                strcpy(professores[i].dado.nascimento, professores[i+1].dado.nascimento);
                strcpy(professores[i+1].dado.nascimento, aux.dado.nascimento);
            }else if( strcmp( AAAA_1, AAAA_2 ) == 0 ){
                strncpy( AAMM_1, professores[i].dado.nascimento, 5 );
                strncpy( AAMM_2, professores[i+1].dado.nascimento, 5 );
                if( strcmp( AAMM_1, AAMM_2 ) > 0 ){
                    strcpy(aux.dado.nascimento, professores[i].dado.nascimento);
                    strcpy(professores[i].dado.nascimento, professores[i+1].dado.nascimento);
                    strcpy(professores[i+1].dado.nascimento, aux.dado.nascimento);}}}}   
}
void ordenaAlunosPorSexo( Aluno *alunos ){
    Aluno aux;

    for( int ordenador = alunosCadastrados - 1; ordenador >= 1 ; ordenador--){
		for( int i = 0; i < ordenador; i++ ){
			if( alunos[i].dado.sexo > alunos[i+1].dado.sexo ){
				aux = alunos[i];
                alunos[i] = alunos[i+1];
                alunos[i+1] = aux;}}}
}
void ordenaAlunosPorOrdemAlfabetica( Aluno *alunos ){
    Aluno aux;

    for( int ordenador = alunosCadastrados - 1; ordenador >= 1 ; ordenador--){
		for( int i = 0; i < ordenador; i++ ){
			if( (strcmp(alunos[i].dado.nome, alunos[i+1].dado.nome)) > 0 ){
				strcpy(aux.dado.nome, alunos[i].dado.nome);
                strcpy(alunos[i].dado.nome, alunos[i+1].dado.nome);
                strcpy(alunos[i+1].dado.nome, aux.dado.nome);}}}
}
void ordenaAlunosPorNascimento( Aluno *alunos ){
    Aluno aux, AAMM_1[ 6 ], AAAA_1[5],
               AAMM_2[ 6 ], AAAA_2[5];

    for( int ordenador = alunosCadastrados - 1; ordenador >= 1 ; ordenador--){
		for( int i = 0; i < ordenador; i++ ){
            strcpy( AAAA_1, &alunos[i].dado.nascimento[6]);
            strcpy( AAAA_2, &alunos[i+1].dado.nascimento[6]);
			if( strcmp( AAAA_1, AAAA_2 ) > 0 ){
				strcpy(aux.dado.nascimento, alunos[i].dado.nascimento);
                strcpy(alunos[i].dado.nascimento, alunos[i+1].dado.nascimento);
                strcpy(alunos[i+1].dado.nascimento, aux.dado.nascimento);
            }else if( strcmp( AAAA_1, AAAA_2 ) == 0 ){
                strncpy( AAMM_1, alunos[i].dado.nascimento, 5 );
                strncpy( AAMM_2, alunos[i+1].dado.nascimento, 5 );
                if( strcmp( AAMM_1, AAMM_2 ) > 0 ){
                    strcpy(aux.dado.nascimento, alunos[i].dado.nascimento);
                    strcpy(alunos[i].dado.nascimento, alunos[i+1].dado.nascimento);
                    strcpy(alunos[i+1].dado.nascimento, aux.dado.nascimento);}}}}
}
void relatorioAlunos( Aluno alunosOrdenados[] ){
    printf( " %*s  %*s  %*s  %*s  %*s  \n", TAM_MAT+4, "MATRÍCULA", TAM_CPF, "CPF", 
                                            TAM_NAC+11, "NASCIMENTO", 14, "SEXO", 4, "NOME" );
    for( int posicao = 0; posicao < alunosCadastrados; posicao++ ){
        printf( " %*s  %*s  %*s  %*c      %-*s\n", TAM_MAT+5, alunosOrdenados[posicao].dado.matricula, 
                                               TAM_CPF+5, alunosOrdenados[posicao].dado.cpf, 
                                               TAM_NAC+5, alunosOrdenados[posicao].dado.nascimento, 
                                               9, alunosOrdenados[posicao].dado.sexo, 
                                               TAM_NOME, alunosOrdenados[posicao].dado.nome );} 
}
void relatorioProfessores( Professor professoresOrdenados[] ){
    printf( " %*s  %*s  %*s  %*s  %*s  \n", TAM_MAT+5, "MATRÍCULA", TAM_CPF, "CPF", 
                                            TAM_NAC+11, "NASCIMENTO", 12, "SEXO ", 14, "NOME" );
    for( int posicao = 0; posicao < professoresCadastrados; posicao++ ){
         printf( " %*s  %*s  %*s  %*c          %-s\n", TAM_MAT+5, professoresOrdenados[posicao].dado.matricula,
                                                TAM_CPF+5, professoresOrdenados[posicao].dado.cpf, 
                                                TAM_NAC+5, professoresOrdenados[posicao].dado.nascimento,
                                                9, professoresOrdenados[posicao].dado.sexo, 
                                                professoresOrdenados[posicao].dado.nome );} 
}
void relatorioDisciplinas( ){
    printf( "%*s %*s %*s %*s %*s\n", TAM_COD_DISC+4, "CÓDIGO", TAM_SEM+4, "SEMESTRE", 
                                     11,"RELAÇÃO", 18, "PROFESSOR", 18, "NOME" );
    for( int posicao = 0; posicao < disciplinasCadastradas; posicao++ ){
        printf( "%*s  %*s  %*d/%d      %-*s  %-*s\n", TAM_COD_DISC+3, materia[posicao].codigo, 
                                                          TAM_SEM+2, materia[posicao].semestre,
                                                          4 ,materia[posicao].quantidadeMatriculado, 
                                                          materia[posicao].vagas + materia[posicao].quantidadeMatriculado, 
                                                          20, materia[posicao].professor.dado.nome, 20 ,materia[posicao].nome );} 
}
void disciplinaComAlunos( int posicao ){
    
    printf( "DISCIPLINA\n%*s %*s %*s %*s %*s\n", TAM_COD_DISC+4, "CÓDIGO", TAM_SEM+4, "SEMESTRE", 
                                     11,"RELAÇÃO", 18, "PROFESSOR", 18, "NOME" );
    for( int posicao = 0; posicao < disciplinasCadastradas; posicao++ ){
        printf( "AlLUNOS MATRICULADOS\n%*s  %*s  %*d/%d      %-*s  %-*s\n", TAM_COD_DISC+3, materia[posicao].codigo, 
                                                          TAM_SEM+2, materia[posicao].semestre,
                                                          4 ,materia[posicao].quantidadeMatriculado, 
                                                          materia[posicao].vagas + materia[posicao].quantidadeMatriculado, 
                                                          20, materia[posicao].professor.dado.nome, 20 ,materia[posicao].nome );} 
    printf( "\n%*s %*s  \n", TAM_MAT+4, "MATRÍCULA", 4, "NOME" );
    
    for( int alunos = 0; alunos < materia[posicao].quantidadeMatriculado; alunos++ ){
        printf( " %*s      %-*s\n", TAM_MAT+5, materia[posicao].turma[alunos]->dado.matricula,
                                               TAM_NOME, materia[posicao].turma[alunos]->dado.nome );} 
}
int solicitaCodigoFiltro( ){
    enum VALIDAR { VALIDO = 1, INVALIDO = 0 };
    enum VALIDAR DADO;
    char codigo[TAM_COD_DISC];
    int posicao;
    
    do{
        printf("Digite o código da disciplina:\n");
        fgets(codigo, TAM_COD_DISC, stdin);
        
        if( sair( codigo[0], codigo[1] ) ){
            return " ";
        }else{
            limpaTexto(codigo);
            strcpy( codigo, caixaAlta( codigo ) );
            DADO = validaCodigo (codigo );
            if( DADO == VALIDO ){
                posicao = verificaCodigoDisciplina( 0, codigo );
                if( posicao < 0 ){ 
                    puts( "Essa disciplina não está cadastrada" );
                    DADO = INVALIDO;}}}
    }while( DADO == INVALIDO );
  
    return posicao;
}
#endif //LISTAS_FILE_H

