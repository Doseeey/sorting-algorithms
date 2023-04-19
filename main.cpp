#include <iostream>
#include <fstream>
#include <vector>
#include <string>
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
    std::vector<Movie> data = get_csv_data("projekt2_dane.csv", MAX_SIZE);
    //mergeSort(data, 0, data.size()-1);
    //quicksort(data, 0, data.size()-1);
    introsort(data);

    // for (auto elem : data) {
    //     elem.print_data();
    // }

    std::cout << validator(data) << std::endl;
    std::cout << average_rating(data) << std::endl;
    std::cout << median_rating(data) << std::endl;
    return 0;
}