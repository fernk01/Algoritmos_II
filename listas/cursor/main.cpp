#include <iostream>
#include "Nodo.h"
#include "Lista.h"

using namespace std;

int main(void) {
    Lista<int> *lis = new Lista<int>();

    lis->agregar(1);
    lis->agregar(2);
    lis->agregar(3);

    // Mostar lista con iterador interno.
    cout << "Lista con iterador interno:" << endl;
    lis->iniciarCursor();
    while (lis->avanzarCursor()) {
        cout << lis->obtenerCursor() << endl;
    }
    
    return 0;
}