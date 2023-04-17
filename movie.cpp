#include "movie.h"

//Default constructor
Movie::Movie() {
    title = "Template Value";
    rating = 0;
}

Movie::Movie(std::string movieName, int movieRating) {
    title = movieName;
    rating = movieRating;
}

int Movie::get_rating() {
    return rating;
}

std::string Movie::get_title() {
    return title;
}

void Movie::print_data() {
    printf("Movie title: %s Rating: %d\n", title.c_str(), rating);
}
