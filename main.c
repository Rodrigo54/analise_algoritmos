/**
 * @package Ordenação de Vetores
 * programa que atende os requisitos da
 * 5 questao da primeira parcial de estrutura de dados 2
 *
 * @author Rodrigo Alves Mesquita <rodrigo54mix@gmail.com>
 * @link http://www.github.com/rodrigo54
 * @version 0.1
 * @date 5 Abr 20TAM
 * @copyright 20TAM by Rodrigo Alves Mesquita
 *
 * @file main.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include "ordenacao.h"
#ifndef TAM
#define TAM 15
#endif

int main(){
    system("title Ordenação de Vetores");
    setlocale(LC_ALL, "Portuguese");//Define o idioma para Portugues
	int a[TAM],i;
	for (i=0;i<TAM; i++){
       a[i]=rand()%100;
       //printf("%d\t",a[i]);
    }
	int aux[TAM];
    int opcao,busca,result;
	do{
        printf("\n\tOrdenação de Vetores!");
        printf("\n\tVetor Original:{");
         for(i = 0; i < TAM; i++){
             printf(" %d",a[i]);
             if(i < TAM - 1)
               printf(",");
         }
         printf("}\n");
        //quickSort( a, 0, 8);
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
                insertion_sort(a,TAM);

                printf("\n\tVetor Ordenado:{");
                 for(i = 0; i < TAM; i++){
                     printf(" %d",a[i]);
                     if(i < TAM - 1)
                       printf(",");
                 }
                printf("}\n\t");
                getch();
                system("cls");
                break;
            case 2:
                select_sort(a,TAM);

                printf("\n\tVetor Ordenado:{");
                 for(i = 0; i < TAM; i++){
                     printf(" %d",a[i]);
                     if(i < TAM - 1)
                       printf(",");
                 }
                printf("}\n\t");
                getch();
                system("cls");
                break;
            case 3:
                bubble_sort(a,TAM);

                printf("\n\tVetor Ordenado:{");
                 for(i = 0; i < TAM; i++){
                     printf(" %d",a[i]);
                     if(i < TAM - 1)
                       printf(",");
                 }
                printf("}\n\t");
                getch();
                system("cls");
                break;
            case 4:
                mergeSort( a, 0, TAM ,aux);

                printf("\n\tVetor Ordenado:{");
                 for(i = 0; i < TAM; i++){
                     printf(" %d",a[i]);
                     if(i < TAM - 1)
                       printf(",");
                 }
                printf("}\n\t");
                getch();
                system("cls");
                break;
            case 5:
                quickSort( a, 0, TAM);
                printf("\n\tVetor Ordenado:{");
                 for(i = 0; i < TAM; i++){
                     printf(" %d",a[i]);
                     if(i < TAM - 1)
                       printf(",");
                 }
                printf("}\n\t");
                getch();
                system("cls");
                break;
            case 6:
                printf("\n\tDigite um valor\n\t");
                scanf("%d",&busca);
                insertion_sort(a,TAM);
                result = busca_sequ( a, TAM, busca);
                printf("\n\tVetor ordenado:{");
                 for(i = 0; i < TAM; i++){
                     printf(" %d",a[i]);
                     if(i < TAM - 1)
                       printf(",");
                 }
                 printf("}\n");
                 printf("\n\tValor %d encontrado na posição %d\n\t",busca,result);
                getch();
                system("cls");
                break;
            case 7:
                printf("\n\tDigite um valor\n\t");
                scanf("%d",&busca);
                insertion_sort(a,TAM);
                result = busca_bin( a, TAM, busca);
                printf("\n\tVetor ordenado:{");
                 for(i = 0; i < TAM; i++){
                     printf(" %d",a[i]);
                     if(i < TAM - 1)
                       printf(",");
                 }
                 printf("}\n");
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
