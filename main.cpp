//this program prompts the user to enter 15 words and then inserts them into a vector
//using a hashin function and class. Then prompts a search of the vector that repeats.
//written by Steffan Sampson with help from Dr. Sarner.
//May 2017
//Language: C++ (GNU GCC Compiler: C++14)
#include <iostream>

using namespace std;

#include "Hashing.h"


int main(void)
{
    //Variables
    string word_input;
    string word_searched;

    int i, dupe;

    bool stop = false;

    Hashing words;

    //Quaries the user for fifteen words and checks for duplicate words.
    for(i=0;i<15;i++)
    {
        cout << "Please input 15 words to be organized, capitalization matters: " << "(" << 15 - i << " more word/s)  ";
        cin >> word_input;

        dupe = words.Hasher(word_input);

        //adjusts the counter for duplicate words
        if (dupe == 1)
        {
            i--;
            dupe = 0;
        }

    }

    //Prints out the contents of the vector showing vaccant spaces as --.
    words.Display(cout);


    //Quareis the user for a word to search for within the vector created prior.
    do
    {
        cout << endl << "Please enter a word that you would like to search for:" << endl << "(if you would like to stop searching enter -999) " << endl;
        cin >> word_searched;

        //tests if the user would like to continue
        if(word_searched == "-999")
        {
            stop = true;
        }
        else
        {
            words.Iterate(word_searched);
        }
        //stop = true;      //Test code


    } while (!stop);

    cout << endl << "Goodbye!";
    return 0;
}
