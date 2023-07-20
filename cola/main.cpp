#include <iostream>

#include "Cola.h"

using namespace std;

int main(void) {
    Cola<int> *cola = new Cola<int>();

    cola->encolar(1);
    cola->encolar(2);
    cola->encolar(3);

    cout << "Frente de la cola: " << cola->frenteCola() << endl;

    cola->mostrarCola();

    return 0;
}