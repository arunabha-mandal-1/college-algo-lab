// insertion sort
#include <stdio.h>
#include <time.h>

void display(int* arr, int size){
    int i = 0;
    for(; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int* arr, int pos1, int pos2){
    int temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

void insertion_sort(int* arr, int size){
    int i=1, j=0, comps=0, swaps=0;
    display(arr, size);
    for(; i<size; i++){
        int key = arr[i];
        j = i-1;
        comps += 1;
        while(j>=0 && key<arr[j]){
            swaps += 1;
            comps += 1;
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        display(arr, size);
    }
    printf("Total number of comparisons : %d\n", comps);
    printf("Total number of swapping operations : %d\n", swaps);
}

int main(){
    int arr[] = {5, 4, 3, 2, 1, 1, 1};
    int size = sizeof(arr)/sizeof(arr[0]);

    clock_t t = clock();
    insertion_sort(arr, size);
    t = clock() - t;

    int time_taken = (double)(t/CLOCKS_PER_SEC);
    printf("Time taken : %f s\n", time_taken);
    return 0;
}