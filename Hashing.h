//this program prompts the user to enter 15 words and then inserts them into a vector
//using a hashin function and class. Then prompts a search of the vector that repeats.
//written by Steffan Sampson with help from Dr. Sarner.
//May 2017
//Language: C++ (GNU GCC Compiler: C++14)

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef HASHING
#define HASHING

class Hashing
{
    public:
//****Function Memebers****

    //Constructor
    Hashing(void);
    /* Constructs an empty vector of 23 elements, fills the vector with '--' initially */

    //Hashing function
    int Hasher(string word);
    /* Hashes the string input by the user and outputs a numeric value for its placement:
    ((first_letter) +  (last_letter)) % 23 */

    //Search function
    void Iterate(string item);
    /* Returns if a word is in the vector */

    //Display function
    void Display(ostream & out) const;
    /* Displays the contents of the vector of hashed values */

    private:
//****Data Members****
    int loc;

    string word, item;
    //string empty_slot = "--";
    char first_letter, last_letter;

    bool vaccant = false;
    bool found = false;

    vector <string> Mat_a;

};

#endif // HASHING
