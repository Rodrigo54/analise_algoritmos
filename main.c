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
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include <wchar.h>  //Biblioteca para conjunto UTF8 de caracteres
#include <io.h>     //Biblioteca para conjunto UTF8 de caracteres
#include <fcntl.h>  //Biblioteca para conjunto UTF8 de caracteres
#define UTF_8  0x40000
#include "ordenacao.h"


int main(){
  _setmode(_fileno(stdout), UTF_8); //Define no console o conjunto UTF8 de caracteres
  system("title ORDENACAO DE VETORES");
  system("color 0e");
  /*CORES 1=FUNDO 2=TEXTO
    0 = Preto        8 = Cinza
    1 = Azul         9 = Azul claro
    2 = Verde        A = Verde claro
    3 = Verde-água   B = Verde-água claro
    4 = Vermelho     C = Vermelho claro
    5 = Roxo         D = Lilás
    6 = Amarelo      E = Amarelo claro
    7 = Branco       F = Branco brilhante
  */

  int *a, *aux;
  int opcao,busca,result;
  int tam_v = 15;

  //tempo em milissegundos
  double tempo = 0.0000000;

  a = (int *) malloc(tam_v * sizeof(int));
  aux = (int *) malloc(tam_v * sizeof(int));

  do{
    cria_vetor(a,tam_v);
    wprintf(L"\n\t├─────── ORDENAÇÃO DE VETORES ──────────┤");
    wprintf(L"\n\n\tVetor Original:");
    mostra_vetor(a,tam_v);

    wprintf(L"\n\t┌────── Selecione uma das opções ──────┐");
    wprintf(L"\n\t│ 1. Definir o Tamanho do vetor        │");
    wprintf(L"\n\t│ 2. Insert Sort                       │");
    wprintf(L"\n\t│ 3. Select Sort                       │");
    wprintf(L"\n\t│ 4. Bubble Sort                       │");
    wprintf(L"\n\t│ 5. Merge Sort                        │");
    wprintf(L"\n\t│ 6. Quick Sort                        │");
    wprintf(L"\n\t│ 7. Busca Sequencial                  │");
    wprintf(L"\n\t│ 8. Busca Binaria                     │");
    wprintf(L"\n\t│ 0. Sair                              │");
    wprintf(L"\n\t└──────────────────────────────────────┘\n\t");
    scanf("%d",&opcao);
    switch(opcao){
      case 1:
        wprintf(L"\n\tDigite o Tamanho do vetor:  ");
        scanf("%d",&tam_v);
        free(a);
        free(aux);
        a = (int *) malloc(tam_v * sizeof(int));
        aux = (int *) malloc(tam_v * sizeof(int));
        system("cls");
        break;
      case 2:
        StartCounter();
        insertion_sort(a,tam_v);
        tempo = GetCounter();
        wprintf(L"\n\tVetor Ordenado:");
        mostra_vetor(a,tam_v);
        printempo(tempo);
        getch();
        system("cls");
        break;
      case 3:
        StartCounter();
        select_sort(a,tam_v);
        tempo = GetCounter();
        wprintf(L"\n\tVetor Ordenado:");
        mostra_vetor(a,tam_v);
        printempo(tempo);
        getch();
        system("cls");
        break;
      case 4:
        StartCounter();
        bubble_sort(a,tam_v);
        tempo = GetCounter();
        wprintf(L"\n\tVetor Ordenado:");
        mostra_vetor(a,tam_v);
        printempo(tempo);
        getch();
        system("cls");
        break;
      case 5:
        StartCounter();
        mergeSort( a, 0, tam_v-1, aux);
        tempo = GetCounter();
        wprintf(L"\n\tVetor Ordenado:");
        mostra_vetor(a,tam_v);
        printempo(tempo);
        getch();
        system("cls");
        break;
      case 6:
        StartCounter();
        quickSort(a, 0, tam_v-1);
        tempo = GetCounter();
        wprintf(L"\n\tVetor Ordenado:");
        mostra_vetor(a,tam_v);
        printempo(tempo);
        getch();
        system("cls");
        break;
      case 7:
        wprintf(L"\n\tDigite um valor:  ");
        scanf("%d",&busca);
        insertion_sort(a,tam_v);
        StartCounter();
        result = busca_sequ( a, tam_v, busca);
        tempo = GetCounter();
        wprintf(L"\tVetor ordenado:");
        mostra_vetor(a,tam_v);
        printempo(tempo);
        if(result == -1)
          wprintf(L"\n\tValor não encontrado!\n");
        else
          wprintf(L"\n\tValor %d encontrado na posição %d\n\t",busca,result+1);
        getch();
        system("cls");
        break;
      case 8:
        wprintf(L"\n\tDigite um valor:  ");
        scanf("%d",&busca);
        insertion_sort(a,tam_v);
        StartCounter();
        result = busca_bin( a, tam_v, busca);
        tempo = GetCounter();
        wprintf(L"\tVetor ordenado:");
        mostra_vetor(a,tam_v);
        printempo(tempo);
        if(result == -1)
          wprintf(L"\tValor não encontrado!\n");
        else
          wprintf(L"\tValor %d encontrado na posição %d\n\t",busca,result+1);
        getch();
        system("cls");
        break;
      case 0:
        system("cls");
        wprintf(L"\n\n\t\t");
        wprintf(L"\n\t┌────────── ORDENAÇÃO DE VETORES ─────────┐");
        wprintf(L"\n\t│                                         │");
        wprintf(L"\n\t│  Programa feito para obtenção de nota   │");
        wprintf(L"\n\t│  parcial de estrutura de dados          │");
        wprintf(L"\n\t│  Obrigado por usar nosso app!           │");
        wprintf(L"\n\t│                                         │");
        wprintf(L"\n\t│  Criado por Rodrigo Alves Mesquita      │");
        wprintf(L"\n\t│                                         │");
        wprintf(L"\n\t└─────────────────────────────────────────┘\n\t");
        getch();
        exit(0);
        break;
      default:
        wprintf(L"\a\tDigite uma opção valida\n");
        getch();//espera que o usuário pressione uma tecla
        system("cls");
        break;
    }
	}while(opcao);
    return 0;
}
