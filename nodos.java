

class nodo{
     int dato; 
     nodo siguienteNodo; 
     nodo  nodoAnterior; 

    nodo(int n){
        this.dato = n; 
        this.siguienteNodo = null; 
        this.nodoAnterior = null; 
    }

    int getDato(){
        return dato; 
    }

    nodo getSiguienteNodo(){
       return siguienteNodo; 
    }

    void setDato(int datoM){
        this.dato = datoM; 
    }

    void setSiguienteNodo(nodo nuevo){
        this.siguienteNodo = nuevo; 
    }
    nodo getAnterior(){
        return nodoAnterior; 
    }
    void setNodoAnterior(nodo anterior){
        this.nodoAnterior = anterior ; 

    }
}; 

class lista{

    nodo cabeza; 

    lista(){
        this.cabeza = null; 
    }

    void insertarNodo(int tipoDeD){
        nodo nuevo = new nodo(tipoDeD);
        if(cabeza == null){
            cabeza = nuevo; 
            return; 
        }
        else{
            nodo temporal = cabeza; 
            while(temporal.getSiguienteNodo() != null){
                temporal = temporal.getSiguienteNodo(); 

            }
            temporal.setSiguienteNodo(nuevo); 
            nuevo.setNodoAnterior(temporal);
        }

    }
    
    void mostrarLista(){
        nodo recorrer = cabeza; 
           

        while(recorrer !=null){
        
            System.out.print(recorrer.getDato() + " - ");
            recorrer = recorrer.getSiguienteNodo(); 
        }
        System.out.print(" NULL "); 
        

    } 

    void eliminarNodo(int datoEliminar){
        nodo temporal = cabeza; 
        nodo temporal2 = null; 

        while(temporal !=null && temporal.getDato() != datoEliminar){
            temporal2 = temporal; 
            temporal = temporal.getSiguienteNodo(); 
            
           
        }
        if(temporal == null){
                        System.out.println("ELEMENTO NO ENCONTRADO");
                        return; 
                    }
                    if(temporal2 == null){
                        cabeza = temporal.getSiguienteNodo(); 
                        
                    }else{
                        nodo siguiente = temporal.getSiguienteNodo(); 
                        temporal2.setSiguienteNodo(temporal.getSiguienteNodo()); 
                        siguiente.setNodoAnterior(temporal2); 
                        
                    }

                    
    }
    
    
    nodo getCabeza(){
        return cabeza; 
    }

    void setCabeza(nodo cabezaMo){
        this.cabeza = cabezaMo; 

    }
    int semilla = 123456; 

    int aleatorio(){
       semilla = (9874125 * semilla + 112456) % 49; 
       return semilla; 
    }
}


class ordenamietos{

            nodo partir(lista numeros){
            
                nodo tortuga = numeros.getCabeza(); 
                nodo conejo = numeros.getCabeza(); 
                nodo anterior = null; 

                while( conejo != null && conejo.getSiguienteNodo() !=null){
                    anterior = tortuga; 
                    tortuga = tortuga.getSiguienteNodo();
                    conejo =  conejo.getSiguienteNodo().getSiguienteNodo(); 
                }

                System.out.println(tortuga.getDato()); 
                //System.out.println(conejo.getDato()); 
                tortuga.setNodoAnterior(null); 

                return tortuga; 

            }


            


 

}
public class nodos{
    public static void main(String [] args){

      
        lista lista = new lista(); 

        for(int i = 0; i<10; i++){
            lista.insertarNodo(lista.aleatorio());
        }
        lista.mostrarLista();
        System.out.println("");
        System.out.println("---------");

        ordenamietos mit = new ordenamietos(); 
        mit.partir(lista);

        //lista.mostrarLista(); 
        
      

    }
}