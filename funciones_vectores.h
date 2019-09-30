//
// Created by rudri on 9/30/2019.
//

#ifndef VECTORES_SESION7A_FUNCIONES_VECTORES_H
#define VECTORES_SESION7A_FUNCIONES_VECTORES_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <iterator>
#include <algorithm>
#include <random>
#include <string>
#include <numeric>
using namespace std;

typedef double decimal;
typedef int number;
typedef uniform_int_distribution<number> distribution;
typedef size_t range;
typedef vector<number> container;
typedef random_device device;

number randint(number first, number last);

void imprimir(container& vec);
void remover_multiplo(container& vec, number multiplo);
void ejemplo1();
void ejemplo2();
container contar_letras(string text);
void imprimir_estadistica_letras(string text);
void ejercicio1();
number calcular_promedio(container& vec);
number calcular_total(container& vec, number filter);
container generar_container_diferencia(container vec);
void ejercicio2();
number multiplicar_impares(container& vec);
number sumar_pares(container& vec);
container generar_vector_posiciones_multiplo(container& vec, range pos);
void ejercicio3();

#endif //VECTORES_SESION7A_FUNCIONES_VECTORES_H
