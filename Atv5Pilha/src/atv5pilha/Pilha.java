/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package atv5pilha;

/**
 *
 * @author RodrigoPC
 */
public class Pilha {
    
    private int topo;
    private int vet[];
    
    public Pilha(int length){
        this.topo = 0;
        this.vet = new int[length];
    }
    
    public void empilha(int element){
        if(!cheia()){
            this.vet[topo++] = element;
//            System.out.println("Numero adicionado");
        }else{
            System.out.println("Pilha está cheia.");
        }
        
    }
    
    public int desimpilha(){
        if(vazia()){
//            System.out.println("Pilha vazia. Não há nenhum elemento.");
        }else
            return this.vet[--this.topo];
        
        return -1;
    }
    
    public double calculaOp(String op){
        int numeroFinal=0;
        int ult,penult;
        switch(op){
            case "+":
                if(vazia()){
                    System.out.println("Insira pelo menos 2 elementos para calcular");
                }else{
                    ult = desimpilha();
                    penult = desimpilha();
                    if(this.topo == 0 && penult == -1)
                        penult = 0;
                    numeroFinal = penult + ult;
                    empilha(numeroFinal);
                }
                break;
            case "-":
                if(vazia()){
                    System.out.println("Insira pelo menos 2 elementos para calcular");
                }else{
                    ult = desimpilha();
                    penult = desimpilha();
                    if(this.topo == 0 && penult == -1){
                        penult = 0;
                    }
                    numeroFinal = penult - ult;
                    empilha(numeroFinal);
                }
                break;
            case "/":
                if(vazia()){
                    System.out.println("Insira pelo menos 2 elementos para calcular");
                }else{
                    ult = desimpilha();
                    penult = desimpilha();
                    if(this.topo == 0 && penult == -1){
                        System.out.println("Insira pelo menos mais um numero para dividir.");
                    }else{
                        numeroFinal = ult / penult;
                        empilha(numeroFinal);
                    }
                }
                break;
            case "*":
                if(vazia()){
                    System.out.println("Insira pelo menos 2 elementos para calcular");
                }else{
                    ult = desimpilha();
                    penult = desimpilha();
                    if(this.topo == 0 && penult == -1)
                        System.out.println("Insira pelo menos mais um numero para multiplicar.");
                    numeroFinal = penult * ult;
                    empilha(numeroFinal);
                }
                break;
        }
        
        
        return numeroFinal;
    }
    
    
    public boolean cheia(){
        if(this.topo == vet.length) return true;
        else return false;
    }
    
    public boolean vazia(){
        if(this.topo == 0) return true;
        else return false;
    }
    
    
}
