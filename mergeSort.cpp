#include "mergeSort.h"

void merge(std::vector<Movie>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;
 
    std::vector<Movie> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[middle + 1 + j];
    }
 
    int i = 0;
    int j = 0;
    int k = left;
 
    while (i < n1 && j < n2) {
        if (L[i].get_rating() <= R[j].get_rating()) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(std::vector<Movie>& arr, int left, int right) {
    if (left >= right) {
        return;
    }

    int middle = (left + right) / 2;
    mergeSort(arr, left, middle);
    mergeSort(arr, middle + 1, right);
    merge(arr, left, middle, right);
}