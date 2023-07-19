#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "Nodo.h"

// Definición de la clase lista enlazada simple con template
template <typename T>
class lista {
    private:
        // Atributos: puntero al primer y último Nodo, y tamaño de la lista
        Nodo<T>* primero;
        Nodo<T>* ultimo;
        int tamano; 
    
    public:
        // Constructor: crea una lista vacía
        lista();

        // Destructor: libera la memoria de los nodos
        ~lista();

        // Métodos de acceso: getters y setters
        Nodo<T>* getPrimero() const;
        Nodo<T>* getUltimo() const;
        int getTamano() const;
        void setPrimero(Nodo<T>* p);
        void setUltimo(Nodo<T>* u);
        void setTamano(int t);

        // Métodos de operaciones: insertar, eliminar, buscar, mostrar, etc.
        void insertarInicio(T d); // Inserta un dato al inicio de la lista
        void insertarFinal(T d); // Inserta un dato al final de la lista
        void insertarPosicion(T d, int p); // Inserta un dato en una posición válida de la lista
        void eliminarInicio(); // Elimina el dato del inicio de la lista
        void eliminarFinal(); // Elimina el dato del final de la lista
        void eliminarPosicion(int p); // Elimina el dato de una posición válida de la lista
        bool buscarDato(T d) const; // Busca un dato en la lista y devuelve true si lo encuentra o false si no
        int posicionDato(T d) const; // Devuelve la posición de un dato en la lista o -1 si no lo encuentra
        T datoPosicion(int p) const; // Devuelve el dato de una posición válida de la lista o 0 si no existe
        bool listaVacia() const; // Devuelve true si la lista está vacía o false si no
        void mostrarLista() const; // Muestra los datos de la lista en orden
};

// Implementación del constructor con template
template <typename T>
lista<T>::lista() {
    primero = nullptr;
    ultimo = nullptr;
    tamano = 0;
}

// Implementación del destructor con template
template <typename T>
lista<T>::~lista() {
    // Se crea un puntero auxiliar para recorrer la lista y liberar la memoria de cada Nodo
    Nodo<T>* aux = primero;
    while (aux != nullptr) {
        primero = primero->getSiguiente();
        delete aux;
        aux = primero;
    }
}

// Implementación de los métodos de acceso con template
template <typename T>
Nodo<T>* lista<T>::getPrimero() const {
    return primero;
}

template <typename T>
Nodo<T>* lista<T>::getUltimo() const {
    return ultimo;
}

template <typename T>
int lista<T>::getTamano() const {
    return tamano;
}

template <typename T>
void lista<T>::setPrimero(Nodo<T>* p) {
    primero = p;
}

template <typename T>
void lista<T>::setUltimo(Nodo<T>* u) {
    ultimo = u;
}

template <typename T>
void lista<T>::setTamano(int t) {
    tamano = t;
}

// Implementación de los métodos de operaciones con template
template <typename T>
void lista<T>::insertarInicio(T d) {
    // Se crea un nuevo Nodo con el dato y se asigna al inicio de la lista
    Nodo<T>* nuevo = new Nodo<T>(d, primero);
    primero = nuevo;

    // Si la lista estaba vacía, el último también apunta al nuevo Nodo
    if (ultimo == nullptr) 
        ultimo = nuevo;
    
    // Se incrementa el tamaño de la lista
    tamano++;
}

template <typename T>
void lista<T>::insertarFinal(T d) {
    // Se crea un nuevo Nodo con el dato y se asigna al final de la lista
    Nodo<T>* nuevo = new Nodo<T>(d, nullptr);

    // Si la lista estaba vacía, el primero y el último apuntan al nuevo Nodo
    if (primero == nullptr) {
        primero = nuevo;
        ultimo = nuevo;
    } else {
        // Si no, se enlaza el último Nodo con el nuevo y se actualiza el último
        ultimo->setSiguiente(nuevo);
        ultimo = nuevo;
    }

    // Se incrementa el tamaño de la lista
    tamano++;
}

template <typename T>
void lista<T>::insertarPosicion(T d, int p) {
    // Se verifica que la posición sea válida (entre 1 y el tamaño de la lista)
    if (p >= 1 && p <= tamano) {
        // Si la posición es 1, se inserta al inicio
        if (p == 1) {
            insertarInicio(d);
        } else {
            // Si no, se crea un nuevo Nodo con el dato y se recorre la lista hasta la posición anterior
            Nodo<T>* nuevo = new Nodo<T>(d, nullptr);
            Nodo<T>* aux = primero;
            
            for (int i = 1; i < p - 1; i++) 
                aux = aux->getSiguiente();
            
            // Se enlaza el nuevo Nodo con el siguiente de la posición y se actualiza el siguiente del anterior
            nuevo->setSiguiente(aux->getSiguiente());
            aux->setSiguiente(nuevo);

            // Si la posición es el tamaño de la lista, se actualiza el último
            if (p == tamano) 
                ultimo = nuevo;
        
            // Se incrementa el tamaño de la lista
            tamano++;
        }
    }
}

template <typename T>
void lista<T>::eliminarInicio() {
    // Se verifica que la lista no esté vacía
    if (primero != nullptr) {
        // Se crea un puntero auxiliar al primer Nodo y se actualiza el primero al siguiente
        Nodo<T>* aux = primero;
        primero = primero->getSiguiente();
        // Se libera la memoria del Nodo eliminado
        delete aux;

        // Si la lista quedó vacía, se actualiza el último a nulo
        if (primero == nullptr) 
            ultimo = nullptr;
        
        // Se decrementa el tamaño de la lista
        tamano--;
    }
}

template <typename T>
void lista<T>::eliminarFinal() {
    // Se verifica que la lista no esté vacía
    if (primero != nullptr) {
        // Si la lista tiene un solo elemento, se elimina el inicio
        if (primero == ultimo) {
            eliminarInicio();
        }
        else {
            // Si no, se recorre la lista hasta el penúltimo Nodo y se guarda su dirección en un puntero auxiliar
            Nodo<T>* aux = primero;
            while (aux->getSiguiente() != ultimo) 
                aux = aux->getSiguiente();
            
            // Se libera la memoria del último Nodo y se actualiza el último al auxiliar
            delete ultimo;
            ultimo = aux;
            // Se actualiza el siguiente del último a nulo
            ultimo->setSiguiente(nullptr);
            // Se decrementa el tamaño de la lista
            tamano--;
        }
    }
}

template <typename T>
void lista<T>::eliminarPosicion(int p) {
    // Se verifica que la posición sea válida (entre 1 y el tamaño de la lista)
    if (p >= 1 && p <= tamano) {
        // Si la posición es 1, se elimina el inicio
        if (p == 1) {
            eliminarInicio();
        } else {
            // Si no, se recorre la lista hasta la posición anterior
            Nodo<T>* aux = primero;
            for (int i = 1; i < p - 1; i++) 
                aux = aux->getSiguiente();
            
            // Se crea un puntero auxiliar al Nodo a eliminar y se actualiza el siguiente del anterior
            Nodo<T>* eliminar = aux->getSiguiente();
            aux->setSiguiente(eliminar->getSiguiente());

            // Si la posición es el tamaño de la lista, se actualiza el último
            if (p == tamano) 
                ultimo = aux;
            
            // Se libera la memoria del Nodo eliminado
            delete eliminar;
            // Se decrementa el tamaño de la lista
            tamano--;
        }
    }
}

template <typename T>
bool lista<T>::buscarDato(T d) const {
    // Se crea un puntero auxiliar para recorrer la lista
    Nodo<T>* aux = primero;
    // Se recorre la lista hasta encontrar el dato o llegar al final
    while (aux != nullptr && aux->getDato() != d) 
        aux = aux->getSiguiente();
    
    // Si el puntero es nulo, no se encontró el dato
    if (aux == nullptr) 
        return false;
    
    // Si no, se encontró el dato
    else 
        return true;
    
}

template <typename T>
int lista<T>::posicionDato(T d) const {
    // Se crea un puntero auxiliar para recorrer la lista y un contador para la posición
    Nodo<T>* aux = primero;
    int pos = 1;
    // Se recorre la lista hasta encontrar el dato o llegar al final
    while (aux != nullptr && aux->getDato() != d) {
        aux = aux->getSiguiente();
        pos++;
    }
    // Si el puntero es nulo, no se encontró el dato
    if (aux == nullptr) 
        return -1;
    
    // Si no, se encontró el dato y se retorna la posición
    else 
        return pos;
    
}

template <typename T>
T lista<T>::datoPosicion(int p) const {
    // Se verifica que la posición sea válida (entre 1 y el tamaño de la lista)
    if (p >= 1 && p <= tamano) {
        // Si la posición es 1, se retorna el dato del inicio
        if (p == 1) {
            return primero->getDato();
        } else {
            // Si no, se recorre la lista hasta la posición
            Nodo<T>* aux = primero;
            for (int i = 1; i < p; i++) 
                aux = aux->getSiguiente();
            
            // Se retorna el dato del Nodo en la posición
            return aux->getDato();
        }
    }
}

template <typename T>
bool lista<T>::listaVacia() const {
    // Si el primero es nulo, la lista está vacía
    if (primero == nullptr) 
        return true;
    
    // Si no, la lista no está vacía
    return false;

}

template <typename T>
void lista<T>::mostrarLista() const {
    // Se crea un puntero auxiliar para recorrer la lista
    Nodo<T>* aux = primero;
    // Se recorre la lista hasta el final
    while (aux != nullptr) {
        // Se muestra el dato del Nodo
        std::cout << aux->getDato() << " ";
        // Se avanza al siguiente Nodo
        aux = aux->getSiguiente();
    }
    std::cout << endl;
}

#endif