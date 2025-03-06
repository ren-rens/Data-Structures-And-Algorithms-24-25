#include <iostream>
#include <vector>

void countingSort(std::vector<int>& arr) {
	int size = arr.size();

	if (size == 0) {
		return;
	}

	int K = *std::max_element(arr.begin(), arr.end()) + 1;

	std::vector<int> count(K);
	std::vector<int> output(size);

	for (int i = 0; i < size; i++) {
		count[arr[i]]++;
	}

	for (int i = 1; i < K; i++) {
		count[i] += count[i - 1];
	}

	for (int i = size - 1; i >= 0; i--) {
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}

	for (int i = 0; i < size; i++) {
		arr[i] = output[i];
	}
}

int main() {
	std::vector<int> arr = { 1, 5, 2 };

	countingSort(arr);

	for (int el : arr) {
		std::cout << el;
	}
}
