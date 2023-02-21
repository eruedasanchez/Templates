#include <map>
#include <utility>

#ifndef __MULTICONJUNTO_HPP
#define __MULTICONJUNTO_HPP

template<class T>
class Multiconjunto {
public:
    Multiconjunto();
    void agregar(T x);
    int ocurrencias(T x) const;

private:
    std::map<T,int> _multiconj;
};

template<class T>
Multiconjunto<T>::Multiconjunto() : _multiconj() {
    /* Constructor de la clase multiconjunto. Se crea un multiconjunto vacio */
}

template<class T>
void Multiconjunto<T>::agregar(T x) {
        if(_multiconj.count(x) == 1){
            _multiconj[x]++;
            return;
        }
        _multiconj[x] = 1;
}

template<class T>
int Multiconjunto<T>::ocurrencias(T x) const {
    int apariciones = 0;
    for(std::pair<T,int> tcs : _multiconj){
        if(tcs.first == x){
            apariciones = tcs.second;
        }
    }
    return apariciones;
}

#endif /*__MULTICONJUNTO_HPP*/
