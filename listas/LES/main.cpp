#include <iostream>
#include "Nodo.h"
#include "Lista.h"

using namespace std;

int main(void) {
    lista<int> *lis = new lista<int>();

    lis->insertarInicio(1);
    lis->insertarInicio(2);
    lis->insertarInicio(3);
    lis->insertarInicio(4);

    lis->mostrarLista();
    
    return 0;
}