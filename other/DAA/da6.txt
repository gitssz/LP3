#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

int deterministic_partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

int randomized_partition(std::vector<int>& arr, int low, int high) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(low, high);
    int pivot_index = dis(gen);
    std::swap(arr[pivot_index], arr[high]);
    return deterministic_partition(arr, low, high);
}

void quick_sort(std::vector<int>& arr, int low, int high, int (*pivot_selector)(std::vector<int>&, int, int)) {
    if (low < high) {
        int pivot_index = pivot_selector(arr, low, high);
        quick_sort(arr, low, pivot_index - 1, pivot_selector);
        quick_sort(arr, pivot_index + 1, high, pivot_selector);
    }
}

int main() {
    std::vector<int> arr_sizes = {100, 1000, 10000, 100000};
    for (int size : arr_sizes) {
        std::vector<int> arr(size);
        std::generate(arr.begin(), arr.end(), []() { return std::rand() % 1000 + 1; });
        std::sort(arr.begin(), arr.end(), std::greater<int>());
        
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 10; i++) {
            std::vector<int> arr_copy = arr;
            quick_sort(arr_copy, 0, arr_copy.size() - 1, deterministic_partition);
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        double deterministic_time = duration.count() / 10.0;
        
        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 10; i++) {
            std::vector<int> arr_copy = arr;
            quick_sort(arr_copy, 0, arr_copy.size() - 1, randomized_partition);
        }
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        double randomized_time = duration.count() / 10.0;
        
        std::cout << "Array size: " << size << std::endl;
        std::cout << "Deterministic time: " << deterministic_time << " microseconds" << std::endl;
        std::cout << "Randomized time: " << randomized_time << " microseconds" << std::endl;
    }
    
    return 0;
}

