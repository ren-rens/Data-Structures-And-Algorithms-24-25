#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, size_t left, size_t mid, size_t right, std::vector<int>& buffer) {
    size_t leftIdx = left;
    size_t rightIdx = mid;
    size_t index = 0;

    while (leftIdx < mid && rightIdx < right) {
        if (arr[leftIdx] <= arr[rightIdx]) {
            buffer[index++] = arr[leftIdx++];
        }
        else {
            buffer[index++] = arr[rightIdx++];
        }
    }

    while (leftIdx < mid) {
        buffer[index++] = arr[leftIdx++];
    }

    while (rightIdx < right) {
        buffer[index++] = arr[rightIdx++];
    }

    for (size_t i = 0; i < index; i++) {
        arr[left + i] = buffer[i];
    }
}

void _mergeSort(std::vector<int>& arr, int left, int right, std::vector<int>& buffer) {
	if (right - left <= 1) {
		return;
	}

	size_t mid = left + (right - left) / 2;

	_mergeSort(arr, left, mid, buffer);
	_mergeSort(arr, mid, right, buffer);
	merge(arr, left, mid, right, buffer);
}

void mergeSort(std::vector<int>& arr) {
	if (arr.size() <= 1) {
		return;
	}

	std::vector<int> buffer(arr.size());
	_mergeSort(arr, 0, arr.size(), buffer);
}

int main() {
	std::vector<int> arr = { 1, 3, 2};

	mergeSort(arr);

	for (int& el : arr) {
		std::cout << el;
	}
}
