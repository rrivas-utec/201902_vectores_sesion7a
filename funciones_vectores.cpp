#include "funciones_vectores.h"

device dev;
//---------------------------
number randint (number first, number last) {
    distribution dist(first, last);
    return dist(dev);
}
//---------------------------
void imprimir(container& vec) {
    for (const auto & item: vec)
        cout << item << " ";
    cout << endl;
}
//---------------------------
void remover_multiplo(container& vec, number multiplo) {
    auto last = remove_if(
            begin(vec), end(vec),
            [multiplo](number n){ return int(n) % int(multiplo) == 0; });
    vec.erase(last, end(vec));
}
//---------------------------
void ejemplo1() {
    range n;
    cout << "ingrese un numero: ";
    cin >> n;
    vector<number> vec(n);
    for (auto it = begin(vec);
         it != end(vec); ++it) {
        cout  << "Ingresar el valor #"
              << distance(begin(vec), it) + 1
              << ": ";
        cin >> *it;
    }
    for (auto it = vec.rbegin();
         it != vec.rend(); ++it)
        cout << *it << " ";
    cout << endl;
}
//---------------------------
void ejemplo2() {
    range n;
    cout << "ingrese un numero: ";
    cin >> n;
    container vec(n);
    for (auto & item: vec)
            item = randint(1, 30);

    imprimir(vec);
    remover_multiplo(vec, 3);
    imprimir(vec);
}
//---------------------------
container contar_letras(string text) {
    container counter(255);
    for (const auto& car: text)
        counter[car]++;
    return counter;
}

void imprimir_estadistica_letras(string text) {
    auto vec = contar_letras(text);
    for (range i = 0; i < vec.size(); ++i)
        if (vec[i] != 0)
            cout << "caracter '" << char(i) << "' :" << vec[i] << endl;
}

//---------------------------
void ejercicio1() {
    string text;
    cout << "Ingrese un texto: ";
    cin.ignore();
    getline(cin, text);
    imprimir_estadistica_letras(text);
}

number calcular_promedio(container& vec) {
    number total = 0;
    for (const auto& value: vec)
        total += value;
    return total / vec.size();
}
number calcular_total(container& vec, number filter) {
    number total = 0;
    for (const auto& value: vec)
        if (value < filter)
            total += value;
    return total;
}

container generar_container_diferencia(
        container vec) {
    auto promedio = calcular_promedio(vec);
    for (auto& item: vec)
        item -= promedio;
    return vec;
}

void ejercicio2() {
    range n;
    cout << "ingrese un numero: ";
    cin >> n;
    container vec(n);
    for (auto & item: vec)
        item = randint(1, 30);
    imprimir(vec);
    cout  << "promedio: "
          << calcular_promedio(vec) << endl;
    cout  << "la suma de menores de 50 es : "
          << calcular_total(vec, 50) << endl;
    cout  << "Las diferencias son :\n";
    auto result = generar_container_diferencia(vec);
    imprimir(result);

}

number multiplicar_impares(container& vec) {
    return accumulate(begin(vec), end(vec), 1,
      [](number total, number next){
          if (next % 2 != 0)
              return total * next;
          else
              return total;
      });
}
number sumar_pares(container& vec) {
    return accumulate(begin(vec), end(vec), 0,
      [](number total, number next){
          if (next % 2 == 0)
              return total + next;
          else
              return total;
      });
}
container generar_vector_posiciones_multiplo(container& vec,
        range pos) {
    container result;
    for (auto it = begin(vec); it != end(vec); ++it)
       if (distance(begin(vec), it) % pos == 0)
           result.emplace_back(*it);
    return result;
}

void ejercicio3() {
    range n;
    cout << "ingrese un numero: ";
    cin >> n;
    container vec(n);
    for (auto & item: vec)
        item = randint(1, 10);
    imprimir(vec);
    cout  << "Multiplicar impares: "
          << multiplicar_impares(vec) << endl;
    cout  << "Sumar pares: "
          << sumar_pares(vec) << endl;

    auto result = generar_vector_posiciones_multiplo(vec, 3);
    cout  << "Generar vector de posiciones multiplo de 3: \n";
    imprimir(result);
}
