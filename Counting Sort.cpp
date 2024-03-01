#include <iostream>
#define MAX 255



int* fill(int* array, int i) {
    for (int j = 0; j < i; j++) {
        array[j] = 1 + rand() % 50;
    }
    return array;
}

void dlt(int* array) {
    delete[] array; 
    array = nullptr;
}

int* memory(int n) {
    return new int[n]; 
}

void countSort(int array[], int size) {
    int output[MAX];
    int count[MAX];
    int max = array[0];

    
    for (int i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }


    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

    for (int i = 1; i <= max; i++){
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--){
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }


    for (int i = 0; i < size; i++){
        array[i] = output[i];
    }
}

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main(){
    int n = 10;
    int* array{ new int[n] };

    array = memory(n);

    fill(array, n);
    std::cout << "Dynamic array:" << std::endl;
    printArray(array, n);
    
    countSort(array, n);


    std::cout << "After couning sorting:" << std::endl;
    printArray(array, n);
}

