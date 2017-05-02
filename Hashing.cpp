//this program prompts the user to enter 15 words and then inserts them into a vector
//using a hashin function and class. Then prompts a search of the vector that repeats.
//written by Steffan Sampson with help from Dr. Sarner.
//May 2017
//Language: C++ (GNU GCC Compiler: C++14)
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Hashing.h"

//Constructor
//Creates a vector then fills it with the string "--"
Hashing::Hashing()
{
    for(int i=0;i<23;i++)
    {
        Mat_a.insert(Mat_a.end(), "--");
    }

    cout << "Constructing vector" << endl << endl;
}

//Hashing Function
//gets the first and last letters of the input word.
//assigns the word to a location in the vector after hashing it
//returns 0 if everything went fine, and a 1 if the word was a duplicate
int Hashing::Hasher(string word)
{
    first_letter = word[0];

    //cout << first_letter << endl;  //Test code

    last_letter = word[word.length()-1];

    //cout << last_letter << endl;  //Test code

    loc = (first_letter + last_letter) % 23;

    //cout << loc << endl;          //Test code

    vaccant = false;
    while(!vaccant)
    {
        //loops to the beginning of the vector if the end is reached during a hash
        if (loc > 22)
        {
            loc = loc - 23;
        }

        //Places the input word into its proper position
        if (!(Mat_a[loc] == word))
        {
            if (Mat_a[loc] == "--")
            {
                Mat_a[loc] = word;
                vaccant = true;
            }
            else
            {
                loc++;
            }
        }

        else
        {
            cout << "Please do not input duplicate words" << endl;
            cout << " *********Word not stored*********" << endl << endl;
            vaccant = true;
            return 1;
        }
    }
    return 0;
}

//Searching Function
//Searches the vector for the word searched for by the user and outputs the result.
void Hashing::Iterate(string item)
{
    first_letter = item[0];
    last_letter = item[item.length()-1];

    loc = (first_letter + last_letter) % 23;

    //cout << loc << endl;      //Test code

    found = false;
    while(!found)
    {

        if (loc > 22)
        {
            loc = loc - 23;
        }

        if (Mat_a[loc] == "--")
        {
            cout << item << " is not in the vector."  << endl;

            found = true;
        }

        if (Mat_a[loc] == item)
        {
            cout << item << " is in the vector " << "at location " << loc << endl;

            found = true;
        }
        else
        {
            loc++;
        }
    }

}

//Display Function
//outputs the vector created by the user.
void Hashing::Display(ostream & out) const
{
    for (int i=0; i<23; i++)
    {
        cout << i << " . " << Mat_a[i] << endl;
    }
}
