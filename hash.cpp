#include <iostream>
using namespace std;

// =====================
// ESTRUCTURA DEL NODO
// =====================
struct Nodo {
    int clave;
    int valor;
    Nodo* siguiente;
};

// =====================
// CLASE TABLA HASH
// =====================
class TablaHash {
private:
    Nodo** tabla;
    int tamaño;

public:
    TablaHash(int t);
    void insertar(int clave, int valor);
    bool buscar(int clave);
    void eliminar(int clave);
    void mostrar();
    ~TablaHash();
};

// =====================
// CONSTRUCTOR
// =====================
TablaHash::TablaHash(int t) {
    tamaño = t;
    tabla = new Nodo*[tamaño];
    for (int i = 0; i < tamaño; i++)
        tabla[i] = nullptr;
}

// =====================
// INSERTAR
// =====================
void TablaHash::insertar(int clave, int valor) {
    int idx = clave % tamaño;

    Nodo* nuevo = new Nodo;
    nuevo->clave = clave;
    nuevo->valor = valor;
    nuevo->siguiente = tabla[idx];

    tabla[idx] = nuevo;
}

// =====================
// BUSCAR
// =====================
bool TablaHash::buscar(int clave) {
    int idx = clave % tamaño;
    Nodo* actual = tabla[idx];

    while (actual != nullptr) {
        if (actual->clave == clave)
            return true;
        actual = actual->siguiente;
    }
    return false;
}

// =====================
// ELIMINAR
// =====================
void TablaHash::eliminar(int clave) {
    int idx = clave % tamaño;
    Nodo* actual = tabla[idx];
    Nodo* anterior = nullptr;

    while (actual != nullptr) {
        if (actual->clave == clave) {
            if (anterior == nullptr)
                tabla[idx] = actual->siguiente;
            else
                anterior->siguiente = actual->siguiente;

            delete actual;
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
}

// =====================
// MOSTRAR
// =====================
void TablaHash::mostrar() {
    for (int i = 0; i < tamaño; i++) {
        cout << i << ": ";
        Nodo* actual = tabla[i];
        while (actual != nullptr) {
            cout << "(" << actual->clave << "," << actual->valor << ") -> ";
            actual = actual->siguiente;
        }
        cout << "NULL\n";
    }
}

// =====================
// DESTRUCTOR
// =====================
TablaHash::~TablaHash() {
    for (int i = 0; i < tamaño; i++) {
        Nodo* actual = tabla[i];
        while (actual != nullptr) {
            Nodo* temp = actual;
            actual = actual->siguiente;
            delete temp;
        }
    }
    delete[] tabla;
}

// =====================
// MAIN
// =====================
int main() {
    TablaHash th(7);
    // main eliminado vovler a crearlo 
    return 0;
}
