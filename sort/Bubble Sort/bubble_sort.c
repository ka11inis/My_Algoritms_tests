//Ταξινόμηση φυσαλίδας 
//Bubble Sort

//Χρονική πολυπλοκότητα 
//Time complexity 
//Best    = n
//Average = n^2
//Worst   = n^2

#include <stdio.h>
//Η συνάρτηση swap παίρνει 2 μεταβλητές και της αντιμεταθέτει 
//In the swap function, two variables are swapped
//[..,5, .. ,2,..]  -->  [..,2, .. ,5,..]
void swap(int *i, int *j){
    int tmp = *i;
    *i = *j;
    *j = tmp;
}

//o αλγόριθμος φυσαλίδας
//Bubble sort
void bubbleSort(int arr[], int size){
    for ( int i=0; i<size - 1;  i++ )
        for ( int j=0; j<size-i-1; j++ )
            if ( arr[j] > arr[j+1] )
                swap( &arr[j], &arr[j+1] );
}

//h main sunartisi poy elegxh to programma
int main(int argc, const char* argv[]) {
    //Αρχικοποίηση του πινάκα
    //Initialization of the table
    int arr[] = {2,324,435,435,456,5647,3452,432,324,3425,43,5,5,343,23};
    //Βρίσκει το μέγεθος του πίνακα
    //Finds the size of the table 
    int size = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, size);

    //Η for εκτυπώνει τον πίνακα
    //Print the table
    for (int i =0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

