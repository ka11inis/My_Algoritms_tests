//Γραμμική Αναζήτηση  
//Linear search

//Χρονική πολυπλοκότητα 
//Time complexity 
//Best    = 1
//Average = n
//Worst   = n

#include <stdio.h>

//Η συνάρτηση linear search αναζητάει γραμμικά το χ στον πίνακα arr
//εάν υπάρχει χ τότε επιστρέφει τη θέση του αλλιώς επιστρέφει -1
//Linear function search x in arr[], if x is present then return its 
//location, otherwise return -1
int linear_search(int arr[], int n, int x){
    int i;
    for (int i=0; i<n; i++)
        if (arr[i] ==x )
            return i;
    return -1;
}

//Η βασική συνάρτηση που αρχικοποιεί τον πίνακα και επιστρέφει τη θέση
//The main function that initializes the table and return the index
int main(void){
    int arr[] = {1,2,3,4,5,6,7,8,9,10,20,30,40,50,60,70,80,90};
    int x = 10; // Το στοιχείο προς αναζήτηση
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = linear_search(arr, n, x);
    if (res != -1)
        printf("Το στοιχείο είναι στη θέση %d\n", res);
    else
        printf("Το στοιχείο δεν υπάρχει στον πίνακα\n");
}
