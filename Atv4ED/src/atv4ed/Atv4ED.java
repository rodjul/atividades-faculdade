/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package atv4ed;

/**
 *
 * @author 31597947
 */
public class Atv4ED {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int []vetTamanho = {1000,10000,100000};
        int i=0;
        
        long tempo0,tempo1;
        while(i<vetTamanho.length){
            System.out.println("Vetor aleatório de tamanho "+vetTamanho[i]);
            Ordenacao ordenacao = new Ordenacao(vetTamanho[i]);
            ordenacao.copyVetor();
            
            tempo0 = System.nanoTime();
            ordenacao.bubbleSort();
            tempo1 = System.nanoTime();
            System.out.format("Bubble Sort: ordenado em %s milissegundos",(tempo1-tempo0)/1000000);
            System.out.println("");
            
            ordenacao.vetorOriginal();
            
            tempo0 = System.nanoTime();
            ordenacao.selectionSort();
            tempo1 = System.nanoTime();
            System.out.format("Selection Sort: ordenado em %s milissegundos",(tempo1-tempo0)/1000000);
            System.out.println("");
            
            ordenacao.vetorOriginal();
            
            tempo0 = System.nanoTime();
            ordenacao.insertionSort();
            tempo1 = System.nanoTime();
            System.out.format("Insertion Sort: ordenado em %s milissegundos",(tempo1-tempo0)/1000000);
            System.out.println("");
            
            ordenacao.vetorOriginal();
            
            tempo0 = System.nanoTime();
            ordenacao.sortMerge();
            tempo1 = System.nanoTime();
            System.out.format("Merge Sort: ordenado em %s milissegundos",(tempo1-tempo0)/1000000);
            System.out.println("");
            
            ordenacao.vetorOriginal();
            
            tempo0 = System.nanoTime();
            ordenacao.sortQuick();
            tempo1 = System.nanoTime();
            System.out.format("Quick Sort: ordenado em %s milissegundos",(tempo1-tempo0)/1000000);
            
            System.out.println("");
            System.out.println("");
            i++;
        }
        
        i=0;
        //ordem crescente
        while(i<vetTamanho.length){
            
            System.out.println("Vetor ordenado em ordem crescente de tamanho "+vetTamanho[i]);
            Ordenacao ordenacao = new Ordenacao(vetTamanho[i]);
            
            tempo0 = System.nanoTime();
            ordenacao.bubbleSort();
            tempo1 = System.nanoTime();
            System.out.format("Bubble Sort: ordenado em %s milissegundos",(tempo1-tempo0)/1000000);
            System.out.println("");
            
            tempo0 = System.nanoTime();
            ordenacao.selectionSort();
            tempo1 = System.nanoTime();
            System.out.format("Selection Sort: ordenado em %s milissegundos",(tempo1-tempo0)/1000000);
            System.out.println("");
            
            tempo0 = System.nanoTime();
            ordenacao.insertionSort();
            tempo1 = System.nanoTime();
            System.out.format("Insertion Sort: ordenado em %s milissegundos",(tempo1-tempo0)/1000000);
            System.out.println("");
            
            tempo0 = System.nanoTime();
            ordenacao.sortMerge();
            tempo1 = System.nanoTime();
            System.out.format("Merge Sort: ordenado em %s milissegundos",(tempo1-tempo0)/1000000);
            System.out.println("");
            
            tempo0 = System.nanoTime();
            ordenacao.sortQuick();
            tempo1 = System.nanoTime();
            System.out.format("Quick Sort: ordenado em %s milissegundos",(tempo1-tempo0)/1000000);
            
            System.out.println("");
            System.out.println("");
            i++;
            
        }
        
        i=0;
        //ordem decrescente
        while(i<vetTamanho.length){
            
            System.out.println("Vetor ordenado em ordem decrescente de tamanho "+vetTamanho[i]);
            Ordenacao ordenacao = new Ordenacao(vetTamanho[i]);
            
            ordenacao.bubbleSortDescrescente();
            ordenacao.copyVetor();
            
            tempo0 = System.nanoTime();
            ordenacao.bubbleSort();
            tempo1 = System.nanoTime();
            System.out.format("Bubble Sort: ordenado em %s milissegundos",((tempo1-tempo0)/1000000));
            System.out.println("");
            
            ordenacao.vetorOriginal();
            
            tempo0 = System.nanoTime();
            ordenacao.selectionSort();
            tempo1 = System.nanoTime();
            System.out.format("Selection Sort: ordenado em %s milissegundos",((tempo1-tempo0)/1000000));
            System.out.println("");
            
            ordenacao.vetorOriginal();
            
            tempo0 = System.nanoTime();
            ordenacao.insertionSort();
            tempo1 = System.nanoTime();
            System.out.format("Insertion Sort: ordenado em %s milissegundos",((tempo1-tempo0)/1000000));
            System.out.println("");
            
            ordenacao.vetorOriginal();
            
            tempo0 = System.nanoTime();
            ordenacao.sortMerge();
            tempo1 = System.nanoTime();
            System.out.format("Merge Sort: ordenado em %s milissegundos",((tempo1-tempo0)/1000000));
            System.out.println("");
            
            ordenacao.vetorOriginal();
            
            tempo0 = System.nanoTime();
            ordenacao.sortQuick();
            tempo1 = System.nanoTime();
            System.out.format("Quick Sort: ordenado em %s milissegundos",((tempo1-tempo0)/1000000));
            
            System.out.println("");
            System.out.println("");
            i++;
            
        }
        
        
        System.out.println("");
    }  
}
