#include <iostream>

void countingSort(int arr[], int size) {
    // Find the maximum element to determine the range
    int maxElement = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }

    // Create a count array to store the count of each element
    const int range = maxElement + 1;
    int* count = new int[range]();

    // Count the occurrences of each element in the input array
    for (int i = 0; i < size; ++i) {
        count[arr[i]]++;
    }

    // Update the count array to store the actual position of each element
    for (int i = 1; i < range; ++i) {
        count[i] += count[i - 1];
    }

    // Create a temporary array to store the sorted result
    int* output = new int[size];

    // Build the sorted array
    for (int i = size - 1; i >= 0; --i) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted array back to the original array
    for (int i = 0; i < size; ++i) {
        arr[i] = output[i];
    }

    // Free dynamically allocated memory
    delete[] count;
    delete[] output;
}

int main() {
    int arr[] = {4, 2, 1, 5, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }

    countingSort(arr, size);

    std::cout << "\nSorted array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
