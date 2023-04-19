#include "quickSort.h"
#include <stack>

void quicksort(std::vector<Movie>& arr, int low, int high) {
    std::stack<std::pair<int, int>> s;
    s.push(std::make_pair(low, high));
    while(!s.empty()) {
        int left = s.top().first;
        int right = s.top().second;
        s.pop();

        if (left < right) {
            Movie pivot = arr[right];
            int i = left - 1;

            for (int j = left; j < right; j++) {
                if (arr[j].get_rating() < pivot.get_rating()) {
                    i++;
                    std::swap(arr[i], arr[j]);
                }
            }
            std::swap(arr[i + 1], arr[right]);
            int mid = i + 1;
            s.push(std::make_pair(left, mid - 1));
            s.push(std::make_pair(mid + 1, right));
        }
    }
}


// int partition(std::vector<Movie>& arr, int low, int high) {
//     Movie pivot = arr[high];
//     int i = low - 1;

//     for (int j = low; j < high; j++) {
//         if (arr[j].get_rating() < pivot.get_rating()) {
//             i++;
//             std::swap(arr[i], arr[j]);
//         }
//     }
//     std::swap(arr[i + 1], arr[high]);

//     return i + 1;
// }

// void quicksort(std::vector<Movie>& arr, int low, int high) {
//     if (low < high) {
//         int pivot = partition(arr, low, high);
//         quicksort(arr, low, pivot - 1);
//         quicksort(arr, pivot + 1, high);
//     }
// }