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

    th.insertar(10, 100);
    th.insertar(3, 200);
    th.insertar(17, 300);
    th.insertar(24, 400);
    th.insertar(31, 500);
    th.mostrar(); 

    cout << "Tabla hash:\n";
    th.mostrar();

    cout << "\nBuscar clave 17: ";
    if (th.buscar(17))
        cout << "Encontrada\n";
    else
        cout << "No encontrada\n";

    cout << "\nEliminar clave 17\n";
    th.eliminar(17);

    cout << "\nTabla hash actualizada:\n";
    th.mostrar();

    return 0;
}
