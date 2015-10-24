/**
 * @package Ordenação de Vetores
 * programa que atende os requisitos da
 * 5 questao da primeira parcial de estrutura de dados 2
 *
 * @author Rodrigo Alves Mesquita <rodrigo54mix@gmail.com>
 * @link http://www.github.com/rodrigo54
 * @version 0.1
 * @date 5 Abr 2015
 * @copyright 2015 by Rodrigo Alves Mesquita
 *
 * @file main.c
 */

#include "ordenacao.h"
//#ifndef tam_v
//#define tam_v 15
//#endif

int main(){
  system("title Ordenação de Vetores");
  setlocale(LC_ALL, "Portuguese");//Define o idioma para Portugues

  int opcao,busca,result;
  int tam_v = 15;
  a = aux = (int *) malloc(tam_v * sizeof(int));
  cria_vetor(a,tam_v);
  aux = a;

	do{
    printf("\n\tOrdenação de Vetores!");
    printf("\n\tVetor Original:");
    mostra_vetor(aux,tam_v);

    printf("\n\tSelecione um método de ordenação:");
    printf("\n\t1. Insert Sort");
    printf("\n\t2. Select Sort");
    printf("\n\t3. Bubble Sort");
    printf("\n\t4. Merge Sort");
    printf("\n\t5. Quick Sort");
    printf("\n\t6. Busca Sequencial");
    printf("\n\t7. Busca binaria\n\t");
    scanf("%d",&opcao);
    switch(opcao){
      case 1:
        insertion_sort(a,tam_v);
        printf("\n\tVetor Ordenado:");
        mostra_vetor(a,tam_v);
        getch();
        system("cls");
        break;
      case 2:
        select_sort(a,tam_v);
        printf("\n\tVetor Ordenado:");
        mostra_vetor(a,tam_v);
        getch();
        system("cls");
        break;
      case 3:
        bubble_sort(a,tam_v);
        printf("\n\tVetor Ordenado:");
        mostra_vetor(a,tam_v);
        getch();
        system("cls");
        break;
      case 4:
        mergeSort( a, 0, tam_v ,aux);
        printf("\n\tVetor Ordenado:");
        mostra_vetor(a,tam_v);
        getch();
        system("cls");
        break;
      case 5:
        quickSort( a, 0, tam_v);
        printf("\n\tVetor Ordenado:");
        mostra_vetor(a,tam_v);
        getch();
        system("cls");
        break;
      case 6:
        printf("\n\tDigite um valor\n\t");
        scanf("%d",&busca);
        insertion_sort(a,tam_v);
        result = busca_sequ( a, tam_v, busca);
        printf("\n\tVetor ordenado:");
        mostra_vetor(a,tam_v);
        printf("\n\tValor %d encontrado na posição %d\n\t",busca,result);
        getch();
        system("cls");
        break;
      case 7:
        printf("\n\tDigite um valor\n\t");
        scanf("%d",&busca);
        insertion_sort(a,tam_v);
        result = busca_bin( a, tam_v, busca);
        printf("\n\tVetor ordenado:");
        mostra_vetor(a,tam_v);
        printf("\n\tValor %d encontrado na posição %d\n\t",busca,result);
        getch();
        system("cls");
        break;
      default:
        printf("\a\tDigite uma opção valida\n");
        getch();//espera que o usuário pressione uma tecla
        system("cls");
        break;
    }
	}while(opcao);
    return 0;
}
