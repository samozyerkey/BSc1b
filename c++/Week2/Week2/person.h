#pragma once
#include <iostream>
using namespace std;
class person
{
private:
    string name;
    string favFilm;
public:
    person(string urName, string urFavFilm);

    string getname();
    string getfavFilm();

    void setname(string newName) {
        name = newName;
    }
    void setfavFilm(string newFilm) {
        favFilm = newFilm;
    }
    void printInfo() {
        cout << "Your name is: " << name << '\n';
        cout << "Your favourite film is: " << favFilm;
    }
};
