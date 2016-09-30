/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package atv5pilha;

import java.util.Scanner;
import java.util.regex.Pattern;

/**
 *
 * @author RodrigoPC
 */
public class Atv5Pilha {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        String op = null;
        
        Pilha pilha = new Pilha(20);
        System.out.println("Para sair insira sair ");
        System.out.println("Insira numeros ou operacoes(+ - / *)");
        do{
            Scanner entrada = new Scanner(System.in);
            System.out.println("Insira:");
            op = entrada.nextLine();
            if(op.contains("sair")) break;
            if( op.contains("+") || op.contains("-") || op.contains("/") || op.contains("*") ){
                System.out.println("Resultado: "+pilha.calculaOp(op));
            }else if(isNumeric(op)){
                pilha.empilha(Integer.parseInt(op));
                
            }
//            System.out.println("");
                
        }while(!(op.contains("sair")));
        
        
    }
    
    public static boolean isNumeric(String str){
        for (char c:str.toCharArray()) {
            if(!Character.isDigit(c)) return false;
        }
        return true;
    }
    
}
