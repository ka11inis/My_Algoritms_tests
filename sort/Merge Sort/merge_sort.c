//Ταξινόμηση με συγχώνευση  --  Αλγόριθμος Merge sort 
//Merge Sort

//Χρονική πολυπλοκότητα 
//Time complexity 
//Best    = nlogn
//Average = nlogn
//Worst   = nlogn

#include <stdio.h>
#include <stdlib.h>
//Μέγεθος του πίνακα
//Array length
#define ARR_LENGTH  1000000 //1.000.000   [0..999999]

//H συνάρτηση merge ενώνει τους δύο υποπίνακες σε έναν ταξινομημένο πίνακα
//The merge function joins two sub-tables into a sorted table
void merge(int arr[], int lo, int middle, int hi){
    //Αρχικοποίηση του πινάκα
    //Initialization of the table
    int i,j,k;
    int left_size = middle - lo + 1;
    int right_size = hi - middle;
    int left[left_size], right[right_size];
    
    //Αντιγραφή των δεδομένων σε προσωρινούς πίνακες
    //Copy the data to temporary tables
    for (i=0; i<left_size; i++)
        left[i] = arr[lo + i];
    for (j=0; j<right_size; j++)
        right[j] = arr[middle + 1 + j];
    
    i=0; j=0; k=lo;
    
    //ένωση των πινάκων
    //join the tables
    while(i<left_size && j<right_size){
        if (left[i] <= right[j]){
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    //Αντιγραφή των υπόλοιπων στοιχείων (άν υπάρχουν)
    //Copy the rest of the data (if there are any)
    while(i < left_size){
        arr[k] = left[i];
        i++;
        k++;
    }

    //Αντιγραφή των υπόλοιπων στοιχείων (άν υπάρχουν)
    //Copy the rest of the data (if there are any)
    while(j < right_size){
        arr[k] = right[j];
        j++;
        k++;
    }
}

//Χωρίζει έναν πίνακα σε δύο υποπίνακες και τρέχει αναδρομικά 
//The merge_sort splits one table into to subtables and runs retroactively
//[1,2,3,4,5,6] -->  [1,2,3] [4,5,6] --> [1] [2,3] [4] [5,6]
void merge_sort(int arr[], int lo, int hi){
    if (lo < hi){
        int middle = lo+(hi-lo)/2;

        merge_sort(arr, lo, middle);
        merge_sort(arr, middle+1, hi);

        merge(arr, lo, middle, hi);
    }
}

//Εκτυπώνει τον πίνακα
//It prints the table
void print_array(int* arr){
    for (int i=0; i<ARR_LENGTH; i++)
        printf("%d\n", arr[i]);
}

//Γεμίζει τον πίνακα με τυχαίους αριθμούς
//It fills the table with random numbers
void fill_array(int* arr){
    for (int i=0; i<ARR_LENGTH; i++)
        arr[i] = rand() % (10000); // 0..10000 - 1
}

int main(int argc, char *argv){
    int arr[ARR_LENGTH];
    fill_array( &arr[0] );
    //print_array(arr);  //Εκτυπώνει πριν την ταξινόμηση
    merge_sort(arr, 0, ARR_LENGTH-1 );
    print_array(arr);    //Εκτυπώνει μετά την ταξινόμηση
}
