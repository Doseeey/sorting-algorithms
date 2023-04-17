#ifndef Merge_H
#define Merge_H

#include "movie.h"
#include <vector>
#include "mergeSort.cpp"

void mergeSort(std::vector<Movie>& arr, int left, int right);
void merge(std::vector<Movie>& arr, int left, int middle, int right);

#endif