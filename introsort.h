#ifndef Introsort_H
#define Introsort_H

#include "movie.h"
#include <vector>
#include "introsort.cpp"

//For quicksort
int partition(std::vector<Movie>& arr, int begin, int end);


//For heapsort
void siftDown(std::vector<Movie>& arr, int start, int end);
void makeHeap(std::vector<Movie>& arr);
void sortHeap(std::vector<Movie>& arr);

void introsortUtil(std::vector<Movie>& arr, int begin, int end, int depthLimit);
void introsort(std::vector<Movie>& arr);

#endif