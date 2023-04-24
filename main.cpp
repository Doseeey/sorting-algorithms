#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include "movie.h"
#include "movie.cpp"
#include "mergeSort.h"
#include "quickSort.h"
#include "introsort.h"

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

double average_rating(std::vector<Movie>& arr) {
    int n = arr.size();
    int sum = 0;

    for (auto elem : arr) {
        sum += elem.get_rating();
    }

    return (double)sum/n;
}

double median_rating(std::vector<Movie>& arr) {
    int n = arr.size();

    if (n%2 == 0) {
        return (double)(arr[n/2 - 1].get_rating() + arr[n/2].get_rating()) / 2.0;
    }

    return (double)arr[n/2].get_rating();
}

int main() {
    int sizes[] = {10000, 100000, 500000, 1000000, MAX_SIZE};

    for (int i = 0; i < 5; i++) {
        std::vector<Movie> data = get_csv_data("projekt2_dane.csv", sizes[i]);

        auto start = std::chrono::high_resolution_clock::now();
        //introsort(data);
        //mergeSort(data, 0, data.size()-1);
        quicksort(data, 0, data.size()-1);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop-start);

        std::cout << "Sorting with data size: " << sizes[i] << std::endl;

        if (validator(data)) {
            std::cout << "Sorting time: " << (float)duration.count()/1000 << std::endl;
            std::cout << "Average rating: " << average_rating(data) << std::endl;
            std::cout << "Median rating: " << median_rating(data) << std::endl;
        } else {
            std::cout << "Error in validation" << std::endl;
        }

        std::cout << std::endl;
    }

    // std::vector<Movie> data = get_csv_data("projekt2_dane.csv", 10);
    // quicksort(data, 0, data.size());

    // for (auto elem : data) {
    //     elem.print_data();
    // }

}