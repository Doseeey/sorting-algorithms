#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include "movie.h"
#include "movie.cpp"
#include "mergeSort.h"

#define MAX_SIZE 1010295
#define SAMPLE_SIZE 10

std::vector<Movie> get_csv_data(std::string fileName, int size) {
    std::vector<Movie> data;
    std::fstream file(fileName);
    if(file.is_open()) {
        std::string line;

        for (int i = 0; i < size; i++) {
            std::getline(file, line);
            if (i != 0) {
                //Parse the line expect header line
                //Get helpful indexes
                std::size_t index = line.find(',');
                std::size_t indexLast = line.find_last_of(',');

                //Get substrings with movie name and rating
                std::string movieName = line.substr(index+1, indexLast-index-1);
                std::string rating_string = line.substr(indexLast+1);

                //Create object only if rating exists
                if (rating_string != "") {
                    int rating = std::stoi(rating_string);
                    Movie mov(movieName, rating);
                    //mov.print_data();
                    data.push_back(mov);
                }
            }
        }
    }
    return data;
};

bool validator(std::vector<Movie> arr) {
    int min = 0;
    for (auto elem : arr) {
        int rate = elem.get_rating();
        if (rate < min) {
            return false;
        } else {
             min = rate;
        } 
    }
    return true;
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

int main() {
    std::vector<Movie> data = get_csv_data("projekt2_dane.csv", MAX_SIZE);
    //mergeSort(data, 0, data.size()-1);
    quicksort(data, 0, data.size()-1);

    for (auto elem : data) {
        elem.print_data();
    }

    std::cout << validator(data);
    return 0;
}