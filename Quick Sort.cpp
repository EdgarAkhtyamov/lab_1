#include <iostream>
#include <random>

void swap(int* x, int* y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

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

int partition(int arr[], int low, int high){
	int pivot_index = low + rand() % (high - low + 1);
	int pivot = arr[pivot_index];
	swap(&arr[pivot_index], &arr[high]);

	int x = (low - 1);

	for (int y = low; y <= high - 1; y++) {

		if (arr[y] < pivot) {
			x++;
			swap(&arr[x], &arr[y]);
		}
	}
	swap(&arr[x + 1], &arr[high]);
	return (x + 1);
}

void quickSort(int arr[], int low, int high){
	if (low < high) {
		int array_partition = partition(arr, low, high);

		quickSort(arr, low, array_partition - 1);
		quickSort(arr, array_partition + 1, high);
	}
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main()
{
	srand(time(NULL));
	int n = 10;

	int* array{ new int[n] };
	array = memory(n);

	fill(array, n);
	std::cout << "Dynamic array:" << std::endl;
	printArray(array, n);
	
	int size = sizeof(array);

	quickSort(array, 0, size - 1);
	std::cout << "Sorted array by quick sort: ";
	printArray(array, size);

	dlt(array);
	

	return 0;
}

