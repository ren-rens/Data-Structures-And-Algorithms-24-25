#include <iostream>
#include <vector>

int partition(std::vector<int>& arr, int low, int high) {
	int pivotIndex = std::rand() % (high - low + 1) + low;
	std::swap(arr[pivotIndex], arr[high]);

	int pivot = arr[high];
	int i = low;

	for (int j = low; j < high; j++) {
		if (arr[j] <= pivot) {
			std::swap(arr[i], arr[j]);
			i++;
		}
	}
	std::swap(arr[i], arr[high]);

	return i;
}

void quickSort(std::vector<int>& arr, int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}

}


int main() {
	std::vector<int> arr = { 1, 3, 0 };
	quickSort(arr, 0, arr.size() - 1);

	for (int el : arr) {
		std::cout << el;
	}
}
