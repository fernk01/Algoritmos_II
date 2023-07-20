#ifndef COLA_H_
#define COLA_H_

#include "Nodo.h"

template <class T>
class Cola {
    private:
        Nodo<T>* frente;
        Nodo<T>* final;

    public:
        // Constructor
        Cola() : frente(NULL), final(NULL) {}

        // Destructor: libera la memoria de todos los nodos en la cola
        ~Cola() {
            while (!estaVacia()) {
                desencolar();
            }
        }

        // Verifica si la cola está vacía
        bool estaVacia() const {
            return frente == NULL;
        }

        // Agrega un elemento al final de la cola
        void encolar(T dato);

        // Elimina el elemento del frente de la cola
        void desencolar();

        // Obtiene el elemento del frente de la cola
        T frenteCola() const;
        void mostrarCola();
};

template <class T>  
void Cola<T>::encolar(T dato) {
    Nodo<T>* nuevoNodo = new Nodo<T>(dato);

    if (estaVacia()) {
        frente = final = nuevoNodo;
    } else {
        final->cambiarSiguiente(nuevoNodo);
        final = nuevoNodo;
    }
}

template <class T>
void Cola<T>::desencolar() {
    if (!estaVacia()) {
        Nodo<T>* nodoAEliminar = frente;
        frente = frente->obtenerSiguiente();
        delete nodoAEliminar;

        if (estaVacia()) 
            final = NULL;
        
    }
}

template <class T>
// Obtiene el elemento del frente de la cola
T Cola<T>::frenteCola() const {
    if (!estaVacia()) {
        return frente->obtenerDato();
    }
    throw std::runtime_error("La cola está vacía");
}

template <class T>
void Cola<T>::mostrarCola() {
    Nodo<T>* actual = frente;
    while (actual != NULL) {
        std::cout << actual->obtenerDato() << " ";
        actual = actual->obtenerSiguiente();
    }
    std::cout << std::endl;
}
#endif /* COLA_H_ */
