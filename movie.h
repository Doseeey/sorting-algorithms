#ifndef Movie_H
#define Movie_H

#include <string>

class Movie {
    std::string title;
    int rating;

    public:
        Movie();
        Movie(std::string title, int rating);
        
        int get_rating();
        std::string get_title();
        void print_data();
};

#endif