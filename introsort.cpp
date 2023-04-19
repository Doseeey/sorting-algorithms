#include "introsort.h"
#include <cmath>
#include "quickSort.h"

int partition(std::vector<Movie>& arr, int begin, int end) {
  int pivot = arr[end].get_rating();
  int i = begin - 1;
  for (int j = begin; j < end; j++) {
    if (arr[j].get_rating() <= pivot) {
      i++;
      std::swap(arr[i], arr[j]);
    }
  }
  std::swap(arr[i + 1], arr[end]);
  return i + 1;
}

void siftDown(std::vector<Movie>& arr, int start, int end) {
  int root = start;
  while (root * 2 + 1 <= end) {
    int child = root * 2 + 1;
    if (child + 1 <= end && arr[child].get_rating() < arr[child + 1].get_rating()) {
      child++;
    }
    if (arr[root].get_rating() < arr[child].get_rating()) {
      std::swap(arr[root], arr[child]);
      root = child;
    }
    else {
      return;
    }
  }
}

void makeHeap(std::vector<Movie>& arr) {
  for (int i = (arr.size() - 2) / 2; i >= 0; i--) {
    siftDown(arr, i, arr.size() - 1);
  }
}

void sortHeap(std::vector<Movie>& arr) {
  makeHeap(arr);
  for (int i = arr.size() - 1; i > 0; i--) {
    std::swap(arr[0], arr[i]);
    siftDown(arr, 0, i - 1);
  }
}

void introsortUtil(std::vector<Movie>& arr, int begin, int end, int depthLimit) {
  int size = end - begin + 1;

  // Small partition
  if (size < 16) {
    quicksort(arr, begin, end);
    return;
  }

  // Change to heapsort if zero recursion depth
  if (depthLimit == 0) {
    makeHeap(arr);
    sortHeap(arr);
    return;
  }

  // Recursive quicksort if big partition or big recursion depth
  int pivot = partition(arr, begin, end);
  introsortUtil(arr, begin, pivot - 1, depthLimit - 1);
  introsortUtil(arr, pivot + 1, end, depthLimit - 1);
}

void introsort(std::vector<Movie>& arr) {
  int depthLimit = 2 * log2(arr.size());
  introsortUtil(arr, 0, arr.size() - 1, depthLimit);
}