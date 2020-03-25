//Δυαδική Αναζήτηση  
//Binary Search

//Χρονική πολυπλοκότητα 
//Time complexity 
//Best    = 1
//Average = logn
//Worst   = logn

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

//Μέγεθος του πίνακα
//Array length
#define ARR_LEN 1000000  //1.000.000   [0..999999]

int binary_search(int arr[], int left, int right, int x){
    if (right >= left){
        int middle = left + (right - left)/2;

        //εάν βρεί το στοιχείο το επιστρέφει
        //If it find the element, it returns its
        if(arr[middle] == x) return middle;

        ///Εάν το στοιχείο είναι μικρότερο από το μεσαίο (mid) τότε
        //κάνει binary search μόνο τον αριστερό πίνακα
        //if the element is smaller than mid, then
        //it can only be present in the left subarray
        if (arr[middle] > x)
            return binary_search(arr, left, middle - 1, x);
        //Αλλιώς το στοιχείο θα είναι μεγαλύτερο από το μεσαίο (mid)
        //και κάνει binary search μόνο τον δεξιό πίνακα
        //else it can be present in the right subarray
        return binary_search(arr, middle + 1, right, x);
    }
    //Εαν δεν βρεθεί το στοιχείο τότε επιστρέφει το -1
    //If the element is not found then it returns -1
    return -1;
}

//Γεμίζει τον πίνακα με τυχαίους αριθμούς  [0..10000]
//It fills the table with random numbers
void fill_array(int* arr){
    for (int i=0; i < ARR_LEN; i++){
        arr[i] = rand() % ( ARR_LEN );
    }
}

//
int compare_two_elements(const void *p1, const void *p2){
    //printf ( "%d\n", (*(int*)p1 - *(int*)p2 ) );
    return (*(int*)p1 - *(int*)p2 );
}
//Η βασική συνάρτηση που αρχικοποιεί τον πίνακα και επιστρέφει τη θέση
//The main function that initializes the table and return the index
int main(int argc, char *argv[]){
    int arr[ARR_LEN];
    fill_array( &arr[0] );
    //int arr[] = {1,2,3,4,5,6,7,8,9,10,20,30,40,50,60,70,80,90};
    int x = rand() % ( ARR_LEN ); // Το στοιχείο προς αναζήτηση
    int n = sizeof(arr) / sizeof(arr[0]);
    
//    for(int i=0; i<ARR_LEN; i++ ){
//        printf ( "%d\n", arr[i] );
//    }
    qsort(arr, ARR_LEN, sizeof(int), compare_two_elements);

    int res = binary_search(arr, 0, n-1, x);
    

//    for(int i=0; i<ARR_LEN; i++ ){
//        printf ( "%d\n", arr[i] );
//    }
    if (res != -1)
        printf("Το στοιχείο είναι τι %d στη θέση %d\n", x,res);
    else
        printf("Το στοιχείο δεν υπάρχει στον πίνακα\n");

    return 0;
}
