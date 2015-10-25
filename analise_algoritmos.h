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
 * @file analise_algoritmos.h
 * Este arquivo é o cabeçalho do analise_algoritmos.c
**/

#ifndef ORDENACAO_H_INCLUDED
#define ORDENACAO_H_INCLUDED

void cria_vetor(int *a, int tam);
void mostra_vetor(int *a, int tam);

void insertion_sort(int *a, int tam);
void select_sort(int *a, int tam);
void bubble_sort(int *a, int tam);

void intercala(int *v,int ini, int meio,int fim,int aux[]);
void mergeSort (int *vet, int esq, int dir,int aux[]);

int busca_bin(int *vet, int tam, int valor);
int busca_sequ(int *vet, int tam, int elem);

void quickSort(int *vet, int pini, int pfim );
int particao(int *v, int p, int r);

void StartCounter(void);
double GetCounter(void);
void printempo(double t);

#endif // ORDENACAO_H_INCLUDED
