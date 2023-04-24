#include "quickSort.h"
#include <stack>

void quicksort(std::vector<Movie>& arr, int left, int right) {
    while (left < right) {
        int pivot = arr[(left + right) / 2].get_rating();
        int i = left, j = right;
        while (i <= j) {
            while (arr[i].get_rating() < pivot)
                i++;
            while (arr[j].get_rating() > pivot)
                j--;
            if (i <= j) {
                std::swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }
        if (j - left < right - i) {
            quicksort(arr, left, j);
            left = i;
        } else {
            quicksort(arr, i, right);
            right = j;
        }
    }
}