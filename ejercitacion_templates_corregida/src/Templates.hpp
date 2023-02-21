/* Ejercicio 1 */

template<class T>
T cuadrado(T x) {
    return x * x;
}

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