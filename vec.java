
package com.mycompany.mavenproject1;
import java.io.IOException; 
import java.io.File; 
import java.io.FileWriter; 
import java.util.Scanner; 
class persistencia{
    
    
    
    void guardarDatos(){
        try{
                    FileWriter guardar  = new FileWriter("datos.txt"); 
                    Scanner nuevo = new Scanner("guardar"); 
                    String linea = nuevo.nextLine(); 
                    System.out.println("Datos guardados correctamente");
                    
                    
        }catch(Exception e){
            System.out.println("Error al guardar los archvis p");
            
        }
        
        
        
    }
}

public class Mavenproject1 {

    public static void main(String[] args) {
         persistencia nuevo = new persistencia(); 
    }
}


