#include <iostream>
#include <random>



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

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void BubbleSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++){
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}


int main() {
	srand(time(NULL));
	int n = 10;

	int* array{new int[n]};
	array = memory(n);

	fill(array, n);
	std::cout << "Dynamic array:" << std::endl;
	printArray(array, n);

	BubbleSort(array, n);

	std::cout << "After bubble sorting:" << std::endl;
	printArray(array, n);

	dlt(array);

	return 0;
}


