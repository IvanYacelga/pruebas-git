#include <iostream>
using namespace std; 

class nodo{
    private: 
      int dato; 
      nodo * siguiente; 

    public: 
    nodo(int n){
        this->dato = n; 
        //this->siguiente = nullptr; 
    }
    
    int getDato(){
        return dato; 
    }
    nodo * getSiguiente(){
        return siguiente; 
    }

    void setDato(int n){
        this->dato = n; 
    }

    void setSiguiente(nodo * sig){
        this->siguiente = sig; 
    }
};


class lista{
    public: 
      nodo * cabeza = nullptr; 

    lista(){
        this->cabeza = nullptr; 
    }  
    //----------------------------------------------------

    void insertarDato(int n){

        nodo * nuevo = new nodo(n); 

        if(cabeza == nullptr){
            cabeza = nuevo; 
        }else{
            nodo * aux = cabeza; 
            while(aux->getSiguiente() !=nullptr){
                aux = aux->getSiguiente(); 
            }

            aux->setSiguiente(nuevo); 
             
        }

    }

    //----------------------------------------------------
    void mostrar(){
        nodo * aux = cabeza; 
        while(aux != nullptr){
            cout << aux->getDato() << " - ";
            aux = aux->getSiguiente(); 
        }
    }
    //-----------------------------------------------------
    void eliminarNodo(int eliminar){
        nodo * aux1 = cabeza; 
        nodo * aux2 = nullptr; 

        while(aux1->getDato() !=  eliminar && aux1 !=nullptr){
            // cabeza - A- B - c - NU
            aux2 = aux1; 
            aux1 = aux1->getSiguiente(); 
        }

        if(aux1 == nullptr){
            return; 
        }

        if(aux2 == nullptr){
            cabeza = aux1->getSiguiente(); 
            delete aux1; 
        }else{
            aux2->setSiguiente(aux1->getSiguiente()); 
            delete aux1 ;

        }
    }
    //----------------------------------------------------------
   

    void buscarNodo(int a ){
        nodo * aux = cabeza; 
        while(aux != nullptr){
            if(aux->getDato() == a){
                cout << "ELemento encontrado"; 
                return; 

            }
            else{
                aux = aux->getSiguiente(); 
            }
        }
        cout << "ELemento no encontrado"; 
        

    }





}; 

int main(){

    lista * nueva = new lista (); 
    nueva->insertarDato(6); 

    nueva->insertarDato(9); 
    nueva->insertarDato(2); 
    nueva->insertarDato(4); 
    nueva->insertarDato(9); 
    nueva->insertarDato(1); 

    nueva->mostrar(); 

    nueva->eliminarNodo(4); 
    cout << "\n" << endl; 
    nueva->mostrar(); 

    nueva->buscarNodo(9); 

    return 0; 

}