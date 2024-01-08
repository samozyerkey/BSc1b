#include<iostream>
#include "person.h"
#include <string>
person::person(string urName, string urFavFilm) {
    name = urName;
    favFilm = urFavFilm;
}

string person::getname() {
    return name;
}
string person::getfavFilm() {
    return favFilm;
};