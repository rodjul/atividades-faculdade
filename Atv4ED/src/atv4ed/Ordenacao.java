/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package atv4ed;

import java.util.Random;

/**
 *
 * @author 31597947
 */
public class Ordenacao {
    
    private int vetor[];
    private int vetorCopy[];
    
    private int tempVetMerge[];
    
    public Ordenacao(int length){
        vetor = new int[length];
        vetorCopy = new int[length];
        randomNumber();
    }
    
    private void randomNumber(){
        Random gerador = new Random();
        for (int i = 0; i < vetor.length; i++) {
            vetor[i] = gerador.nextInt();
        }
    }
    
    
    public void bubbleSort(){
        for (int i = 0; i < vetor.length; i++) {
            for (int j = 0; j < vetor.length-1; j++) {
                if(vetor[j] > vetor[j+1]){
                    int aux = vetor[j];
                    vetor[j] = vetor[j+1];
                    vetor[j+1] = aux;
                }
            }
        }
    }
    
    public void bubbleSortDescrescente(){
        for (int i = 0; i < vetor.length; i++) {
            for (int j = 0; j < vetor.length-1; j++) {
                if(vetor[j] < vetor[j+1]){
                    int aux = vetor[j];
                    vetor[j] = vetor[j+1];
                    vetor[j+1] = aux;
                }
            }
        }
    }
    
    public void selectionSort(){
        for (int i = 0; i < vetor.length; i++) {
            int min = i;
            for (int j = i+1; j < vetor.length; j++) {
                if(vetor[j] < vetor[min])
                    min = j;
                int aux = vetor[min];
                vetor[min] = vetor[i];
                vetor[i] = aux;
            }
        }
    }
    
    public void insertionSort(){
        int j;
        for (int i = 0; i < vetor.length; i++) {
            int aux = vetor[i];
            j = i -1;
            while(j>=0 && aux<vetor[j]){
                vetor[j + 1] = vetor[j];
                j--;
            }
            vetor[j+1] = aux;
        }
        
    }
    
    /* MERGE*/
     public void sortMerge() {
        this.tempVetMerge = new int[vetor.length];
        doMergeSort(0, vetor.length - 1);
    }
 
    private void doMergeSort(int lowerIndex, int higherIndex) {
         
        if (lowerIndex < higherIndex) {
            int middle = lowerIndex + (higherIndex - lowerIndex) / 2;
            // Below step sorts the left side of the vetor
            doMergeSort(lowerIndex, middle);
            // Below step sorts the right side of the vetor
            doMergeSort(middle + 1, higherIndex);
            // Now merge both sides
            mergeParts(lowerIndex, middle, higherIndex);
        }
    }
 
    private void mergeParts(int lowerIndex, int middle, int higherIndex) {
 
        for (int i = lowerIndex; i <= higherIndex; i++) {
            tempVetMerge[i] = vetor[i];
        }
        int i = lowerIndex;
        int j = middle + 1;
        int k = lowerIndex;
        while (i <= middle && j <= higherIndex) {
            if (tempVetMerge[i] <= tempVetMerge[j]) {
                vetor[k] = tempVetMerge[i];
                i++;
            } else {
                vetor[k] = tempVetMerge[j];
                j++;
            }
            k++;
        }
        while (i <= middle) {
            vetor[k] = tempVetMerge[i];
            k++;
            i++;
        }
 
    }
    
    
    /* QUICK SORT */

    public void sortQuick() {
        quickSort(0, vetor.length - 1);
    }
 
    private void quickSort(int lowerIndex, int higherIndex) {
         
        int i = lowerIndex;
        int j = higherIndex;
        // calculate pivot number, I am taking pivot as middle index number
        int pivot = vetor[lowerIndex+(higherIndex-lowerIndex)/2];
        // Divide into two vetors
        while (i <= j) {
            /**
             * In each iteration, we will identify a number from left side which
             * is greater then the pivot value, and also we will identify a number
             * from right side which is less then the pivot value. Once the search
             * is done, then we exchange both numbers.
             */
            while (vetor[i] < pivot) {
                i++;
            }
            while (vetor[j] > pivot) {
                j--;
            }
            if (i <= j) {
                exchangeNumbers(i, j);
                //move index to next position on both sides
                i++;
                j--;
            }
        }
        // call quickSort() method recursively
        if (lowerIndex < j)
            quickSort(lowerIndex, j);
        if (i < higherIndex)
            quickSort(i, higherIndex);
    }
 
    private void exchangeNumbers(int i, int j) {
        int temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
    }
    
    
    public void copyVetor(){
        for (int i = 0; i < vetor.length; i++) {
            vetorCopy[i] = vetor[i];
        }
        
    }
    
    public void vetorOriginal(){
        for (int i = 0; i < vetorCopy.length; i++) {
            vetor[i] = vetorCopy[i];
        }
    }
    
    
   
    
    
}
