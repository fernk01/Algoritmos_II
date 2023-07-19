#ifndef NODO_
#define NODO_

template <typename T> 
class Nodo {
    private:
        T dato;
        Nodo<T> *siguiente;

    public:
        // Constructores: por defecto, por parámetros y por copia
        Nodo();
        Nodo(T d, Nodo<T> *s);
        Nodo(const Nodo<T> &n);

        // Métodos de acceso: getters y setters
        T getDato() const;
        Nodo<T> *getSiguiente() const;

        void setDato(T d);
        void setSiguiente(Nodo<T> *s);
};

// Implementación de los constructores con template
template <typename T> 
Nodo<T>::Nodo() {
    dato = 0;
    siguiente = nullptr;
}

template <typename T> 
Nodo<T>::Nodo(T d, Nodo<T> *s) {
    dato = d;
    siguiente = s;
}

template <typename T> 
Nodo<T>::Nodo(const Nodo<T> &n) {
    dato = n.dato;
    siguiente = n.siguiente;
}

// Implementación de los métodos de acceso con template
template <typename T> 
T Nodo<T>::getDato() const { 
    return dato; 
}

template <typename T> 
Nodo<T> *Nodo<T>::getSiguiente() const {
    return siguiente;
}

template <typename T>
void Nodo<T>::setDato(T d) { 
    dato = d; 
}

template <typename T> 
void Nodo<T>::setSiguiente(Nodo<T> *s) { 
    siguiente = s; 
}

#endif