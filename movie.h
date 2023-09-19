/*
 * movie.h
 *
 *  Created on: 11/09/2023
 *      Author: Emiliano Gomez Gonzalez
 */

#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
using namespace std;

class Movie {
    private:
        string title;
        string filmDirector;
        int releaseYear;
        string movieGenre;

    public: 
        Movie(string,string,int,string);

};

Movie::Movie(string _title, string _filmDirector, int _releaseYear, string _movieGenre){
    title = _title;
    filmDirector = _filmDirector;
    releaseYear = _releaseYear;
    movieGenre = _movieGenre;
}






#endif