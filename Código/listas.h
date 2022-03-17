#ifndef LISTA_FILE_H
#define LISTA_FILE_H

Aluno *ordenaAlunosPorSexo( ); 
//Aluno *ordenaAlunosPorOrdemAlfabetica( );


Professor *ordernaProfessoresPorSexo( );
Professor *ordernaProfessoresPorOrdemAlfabetica( );

void listarProfessores( ){
    int menuListarProfessor( );
    menuListarProfessor( );
    ordernaProfessoresPorOrdemAlfabetica( );
  
}
void listarAlunos( ){
    int menuListarAluno( );
    menuListarAluno( );
    
    ordenaAlunosPorSexo( );
  
}
void listarDisciplinas( ){
    int menuListarDisciplinas( );
    menuListarDisciplinas( );

    
}
Professor *ordernaProfessoresPorSexo( ){
    Professor professoresOrdenados[professoresCadastrados];
    Professor aux;

    for( int posicao = 0; posicao < professoresCadastrados; posicao++ ){
        professoresOrdenados[posicao] = docente[posicao];}
    /*
    printf("\nAntes de Ordenar\n");
    for( int posicao = 0; posicao < professoresCadastrados; posicao++ ){
        printf( "nome: %s                   sexo: %c\n", professoresOrdenados[posicao].dado.nome, professoresOrdenados[posicao].dado.sexo );}*/
  
    for( int ordenador = professoresCadastrados - 1; ordenador >= 1 ; ordenador--){
		for( int i = 0; i < ordenador; i++ ){
			if( professoresOrdenados[i].dado.sexo > professoresOrdenados[i+1].dado.sexo ){
				aux = professoresOrdenados[i];
                professoresOrdenados[i] = professoresOrdenados[i+1];
                professoresOrdenados[i+1] = aux;
            }
        }
    }
    /*
    printf("\nDepois de Ordenar\n");
    for( int posicao = 0; posicao < professoresCadastrados; posicao++ ){
        printf( "nome: %s                   sexo: %c\n", professoresOrdenados[posicao].dado.nome, professoresOrdenados[posicao].dado.sexo );} */
}
Professor *ordernaProfessoresPorOrdemAlfabetica( ){
    Professor professoresOrdenados[professoresCadastrados];
    Professor aux;

    for( int posicao = 0; posicao < professoresCadastrados; posicao++ ){
        professoresOrdenados[posicao] = docente[posicao];}
    
    /*printf("\nAntes de Ordenar\n");
    for( int posicao = 0; posicao < professoresCadastrados; posicao++ ){
        printf( "nome: %s                   \n", professoresOrdenados[posicao].dado.nome );}*/
  
    for( int ordenador = professoresCadastrados - 1; ordenador >= 1 ; ordenador--){
		for( int i = 0; i < ordenador; i++ ){
			if( (strcmp(professoresOrdenados[i].dado.nome, professoresOrdenados[i+1].dado.nome)) == -1 ){
                 printf( "nomeAux: %s     \nNomeOutro: %s\n", aux.dado.nome, professoresOrdenados[i].dado.nome );
				strcpy(aux.dado.nome, professoresOrdenados[i].dado.nome);
                strcpy(professoresOrdenados[i].dado.nome, professoresOrdenados[i+1].dado.nome);
                strcpy(professoresOrdenados[i+1].dado.nome, aux.dado.nome);
            }
        }
    }
    
   /* printf("\nDepois de Ordenar\n");
    for( int posicao = 0; posicao < professoresCadastrados; posicao++ ){
        printf( "nome: %s                   \n", professoresOrdenados[posicao].dado.nome );} */
}

Aluno *ordenaAlunosPorSexo( ){
    Aluno alunosOrdenados[alunosCadastrados];
    Aluno aux;

    for( int posicao = 0; posicao < alunosCadastrados; posicao++ ){
        alunosOrdenados[posicao] = discente[posicao];}
    
   /* printf("\nAntes de Ordenar\n");
    for( int posicao = 0; posicao < alunosCadastrados; posicao++ ){
        printf( "nome: %s                   sexo: %c\n", professoresOrdenados[posicao].dado.nome, professoresOrdenados[posicao].dado.sexo );}*/
  
    for( int ordenador = alunosCadastrados - 1; ordenador >= 1 ; ordenador--){
		for( int i = 0; i < ordenador; i++ ){
			if( alunosOrdenados[i].dado.sexo > alunosOrdenados[i+1].dado.sexo ){
				aux = alunosOrdenados[i];
                alunosOrdenados[i] = alunosOrdenados[i+1];
                alunosOrdenados[i+1] = aux;
            }
        }
    }
    /*
    printf("\nDepois de Ordenar\n");
    for( int posicao = 0; posicao < professoresCadastrados; posicao++ ){
        printf( "nome: %s                   sexo: %c\n", professoresOrdenados[posicao].dado.nome, professoresOrdenados[posicao].dado.sexo );} 
}*/
}


#endif //LISTAS_FILE_H
