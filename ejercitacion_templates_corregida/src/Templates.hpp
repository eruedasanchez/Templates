/* Ejercicio 1 */

template<class T>
T cuadrado(T x) {
    return x * x;
}

/* Ejercicio 2 */

template<class Contenedor, class Elem>
bool contiene(Contenedor lista, Elem valor){
    bool encontre = false;
    for (Elem x: lista){
        if (x == valor){
            encontre = true;
            break;
        }
    }
    return encontre;
}

/* Ejercicio 3 */

template<class Contenedor>
bool esPrefijo(Contenedor l1, Contenedor l2){
    bool prefijo = false;
    int i = 0;
    if(l1.size() < l2.size()){
        while(i < l1.size() && l1[i] == l2[i]){
            i++;
        }
    }

    if(i == l1.size()){
        prefijo = true;
    }
    return prefijo;
}

/* Ejercicio 4 */

template<class Contenedor, class Elem>
Elem maximo(Contenedor lista) {
    Elem max = lista[0];
    for(int j = 1; j < lista.size(); j++){
        if(lista[j] > max){
            max = lista[j];
        }
    }
    return max;
}



