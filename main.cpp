/*
 
 PROGRAMA PARA ABRIR UM ARQUIVO TEXTO CONTENDO VARIOS DADOS DE ALUNOS 
 (PRIMEIRO NOME E DUAS NOTAS),
 LER OS DADOS E CALCULAR A MEDIA ARITMETICA DAS DUAS NOTAS DO ALUNO,
 IMPRIMIR NOME E MEDIA NA TELA
 
 */

#include<stdio.h>  /*FILE, printf, scanf*/
#define MAX 30
struct aluno
{
	char nome[MAX];
  int ra;
  double p1;
  double p2;
  double trab;
  double po;
  
};

int main()

{
    
    FILE*  arq;         /* variavel para acessar um arquivo */
    FILE*  arqsaida;    /* variavel para manip arquivo de saida*/ 
    char nome[MAX];     /* nome do arquivo a ser aberto*/
    double media;
    aluno registro;
    int cont;
    scanf(" %s", nome);
    
    /*abertura de um arquivo*/
    arq = fopen(nome, "r");
    
    /* verificando se arquivo foi aberto */
    if( arq == NULL )
    {
        printf("\n\n Arquivo %s nao pode ser aberto.\n\n", nome);
    }
    else
    {


        arqsaida = fopen("Reprovados.txt", "a");
        if( arqsaida == NULL )
        {
            printf("\n\n Arquivo media.txt nao pode ser aberto.\n\n");
        }
        else
        {

            printf("Arquivo foi aberto!\n\n");
            
            
            
            /*leitura dos dados do arquivo*/
            fscanf(arq, "%[^0123456789] %d %lf %lf %lf %lf", registro.nome, &registro.ra,&registro.p1, &registro.p2,&registro.trab,&registro.po);
            
            fprintf(arqsaida,"Lista de Reprovados:\n");
            while( feof(arq) == 0 )    /*CHEGOU AO FINAL DO ARQUIVO??? verificando se chegou ao fim do arquivo*/
            {
                /*calcula da media e impressao na tela*/
                if (registro.p1 < registro.po){
                registro.p1 = registro.po;
                }else if (registro.p2 <registro.po){
                registro.p2 = registro.po;
                }

                media = (0.35 * registro.p1) + (0.35 * registro.p2) + (0.3 * registro.trab);
                
                 if(media<6){
                  
                  fprintf(arqsaida, "%s %d %.1lf", registro.nome, registro.ra,media);
                  cont++;
                 }
                 
                
            
                /*leitura dos proximos dados do arquivo*/
                fscanf(arq, "%[^0123456789] %d %lf %lf %lf %lf", registro.nome, &registro.ra,&registro.p1, &registro.p2,&registro.trab,&registro.po);
            }
            fprintf(arqsaida,"\n");
            fprintf(arqsaida,"Total:%d",cont);
            /*fechamento do arquivo*/
            fclose(arq);
            fclose(arqsaida);
        }// fim else arqsaida
            
    }
    printf("\n");    
    return 0;
}


     