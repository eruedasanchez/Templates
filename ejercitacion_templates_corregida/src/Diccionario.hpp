#include <vector>

#ifndef __DICCIONARIO_HPP
#define __DICCIONARIO_HPP

template<class Clave, class Valor>
class Diccionario {
public:
    Diccionario();
    void definir(Clave k, Valor v);
    bool def(Clave k) const;
    Valor obtener(Clave k) const;
    unsigned int encontrarMinPos(std::vector<Clave> &keys, unsigned int desde, unsigned int hasta) const;
    void intercambiar(std::vector<Clave> &keys, unsigned int indice, unsigned int minimo) const;
    void selectionSort(std::vector<Clave> &keys) const;
    std::vector<Clave> claves() const;           // Ejercicio 8

private:

    struct Asociacion {
        Asociacion(Clave k, Valor v);
        Clave clave;
        Valor valor;
    };
    std::vector<Asociacion> _asociaciones;
};

template<class Clave, class Valor>
Diccionario<Clave,Valor>::Diccionario() {
}

template<class Clave, class Valor>
Diccionario<Clave,Valor>::Asociacion::Asociacion(Clave k, Valor v) : clave(k), valor(v) {
}

template<class Clave, class Valor>
void Diccionario<Clave,Valor>::definir(Clave k, Valor v) {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            _asociaciones[i].valor = v;
            return;
        }
    }
    _asociaciones.push_back(Asociacion(k, v));
}

template<class Clave, class Valor>
bool Diccionario<Clave,Valor>::def(Clave k) const {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            return true;
        }
    }
    return false;
}

template<class Clave, class Valor>
Valor Diccionario<Clave,Valor>::obtener(Clave k) const {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            return _asociaciones[i].valor;
        }
    }
    assert(false);
}

/* Ejercicio 8 */

template<class Clave, class Valor>
unsigned int Diccionario<Clave,Valor>::encontrarMinPos(std::vector<Clave> &keys, unsigned int desde, unsigned int hasta) const {
    unsigned int min = desde;
    for(unsigned int i = desde + 1; i < hasta; i++){
        if(keys[i] <= keys[min]){
            min = i;
        }
    }
    return min;
}

template<class Clave, class Valor>
void Diccionario<Clave,Valor>::intercambiar(std::vector<Clave> &keys, unsigned int indice, unsigned int minimo) const {
    Clave tmp = keys[indice];
    keys[indice] = keys[minimo];
    keys[minimo] = tmp;
}

template<class Clave, class Valor>
void Diccionario<Clave,Valor>::selectionSort(std::vector<Clave> &keys) const {
    for(unsigned int i = 0; i < keys.size(); i++) {
        unsigned int minPos = encontrarMinPos(keys, i, keys.size());
        intercambiar(keys, i, minPos);
    }

}

template<class Clave, class Valor>
std::vector<Clave> Diccionario<Clave,Valor>::claves() const {
    std::vector<Clave> v1;
    for(unsigned int i = 0; i < _asociaciones.size(); i++){
        v1.push_back(_asociaciones[i].clave);
    }
    selectionSort(v1);
    return v1;

}

#endif /*__DICCIONARIO_HPP */


