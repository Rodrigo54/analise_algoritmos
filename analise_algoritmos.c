/**
 * @package Análise de Algoritmos
 * programa que atende os requisitos do
 * trabalho de Projeto e Análise de Algoritmos
 *
 * @author Rodrigo Alves Mesquita <rodrigo54mix@gmail.com>
 * @link http://www.github.com/rodrigo54
 * @version 1.5
 * @date 24 Out 2015
 * @copyright 2015 by Rodrigo Alves Mesquita
 *
 * @file analise_algoritmos.c
 * Este  é o arquivo das funções
**/

#include "analise_algoritmos.h"
#include <windows.h>
#include <time.h>
#include <wchar.h>

double PCFreq = 0.0;
__int64 CounterStart = 0;

void mostra_vetor(int *a, int tam)
{
  int i;
  wprintf(L"\n\t{");
  for(i = 0; i < tam; i++){
    wprintf(L"%d",a[i]);
    if(i < tam - 1)
      wprintf(L", ");
  }
  wprintf(L"}\n");
}

void cria_vetor(int *a, int tam)
{
  int i;
  srand(time(NULL));
  for (i=0;i<tam; i++){
    a[i] = rand()%100;
  }
}

// Função de Ordenação por Inserção
void insertion_sort(int *a, int tam )
{
 int i, j, tmp;

 for(i = 1; i < tam; i++)
 {
  tmp = a[i];
  for(j = i-1; j >= 0 && tmp < a[j]; j--)
  {
   a[j+1] = a[j];
  }
  a[j+1] = tmp;
 }
}

// Função de ordenação por seleção
void select_sort(int *a, int tam)
{
 int i, j, k, tmp, troca;

 for(i = 0; i < tam-1; i++){
    troca = 0;
    k = i;
    tmp = a[i];

    for(j = i+1; j < tam; j++){
        if(a[j] < tmp){
            k = j;
            tmp = a[j];
            troca = 1;
        }
    }
    if(troca){
        a[k] = a[i];
        a[i] = tmp;
    }
 }
}

// Função de ordenação bolha
void bubble_sort(int *a, int tam)
{
 int i, j, tmp;

 for(i = tam -1; i >= 1; i--){

    for(j = 0; j < i; j++){

       if(a[j] > a[j+1]){
            tmp = a[j];
            a[j] = a[j+1];
            a[j+1] = tmp;
       }
    }
 }
}

//Função Merge sort
void intercala(int *v,int ini, int meio,int fim,int aux[])
{
  int i = ini, j = meio + 1, k = 0;

  while(i <= meio && j <= fim){
      if (v[i] <= v[j]){
          aux[k++] = v[i++];
      }else{
          aux[k++] = v[j++];
      }
  }
  while(i <= meio){
      aux[k++] = v[i++];
  }
  while(j <= fim){
      aux[k++] = v[j++];
  }

  for(i = ini, k = 0; i <= fim; i++,k++){
      v[i]=aux[k];
  }
}
void mergeSort (int *vet, int esq, int dir,int aux[])
{
  int meio;

  if(esq < dir){
      meio = (esq+dir)/2;
      mergeSort(vet,esq,meio,aux);
      mergeSort(vet,meio+1,dir,aux);
      intercala(vet,esq,meio,dir,aux);
  }
}

/** @name Busca Binária
 *  @note Leia mais em biblioteca_sistema_veiculo.h
**/
int busca_bin(int *vet, int tam, int valor)
{
  int ini, fim, meio;

  ini = 0;
  fim = tam -1;

  while(ini <= fim){

      meio = (ini + fim)/2;

      if(vet[meio] == valor){
          return meio;
      }

      if(valor > vet[meio]){
          ini = meio +1;
      }else{
          fim = meio -1;
      }
  }
  return -1;
}

/** @name Busca Sequencial
 *  @note Leia mais em biblioteca_sistema_veiculo.h
**/
int busca_sequ(int *vet, int tam, int elem)
{
    int i;
    for (i=0; i<tam; i++) {
        if (elem == vet[i])
        return i; // encontrou
    else if (elem < vet[i])
        return -1;//interrompe busca
    }
    return -1;//não encontrou
}

/** @name Ordenação Quicksort
 *  @note Leia mais em biblioteca_sistema_veiculo.h
**/
int particao(int *v, int p, int r)
{
 int c = v[p], i = p+1, j = r, t;
   while (/*A*/ i <= j) {
      if (v[i] <= c) ++i;
      else if (c < v[j]) --j;
      else {
         t = v[i], v[i] = v[j], v[j] = t;
         ++i; --j;
      }
   }
   // agora i == j+1
   v[p] = v[j], v[j] = c;
   return j;

 return j;
}

void quickSort(int *vet, int pini, int pfim )
{
  int pivot;
  if (pini < pfim){
    pivot = particao( vet , pini, pfim);
    quickSort( vet, pini, pivot);
    quickSort(vet, pivot+1, pfim);
  }
}
/********* END Ordenação Quicksort **********/

void StartCounter(void)
{
  LARGE_INTEGER li;
  if(!QueryPerformanceFrequency(&li))
    wprintf(L"QueryPerformanceFrequency Failed.\n");
  PCFreq = (double)(li.QuadPart) / 1000.0;
  QueryPerformanceCounter(&li);
  CounterStart = li.QuadPart;
}

double GetCounter(void)
{
  LARGE_INTEGER li;
  QueryPerformanceCounter(&li);
  return (double)(li.QuadPart - CounterStart) / PCFreq;
}

void printempo(double t)
{
  if (t < 0.9){
    t  = (t * 1000);
    wprintf(L"\tTempo = %.7lf microsegundos\n", t);
  }
  else if ( t > 1000){
    t = (t * 0.001);
    wprintf(L"\tTempo = %.7lf segundos\n", t);
  }
  else{
    wprintf(L"\tTempo = %.7lf milissegundos\n", t);
  }
}
