#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cstdlib>

 
using namespace std; 


int main() {
    srand(time(NULL));

    string input;
    int rand_num = rand() % 5;

    fstream file;

    file.open("prng_service.txt", ios::in | ios::out);
    file >> input;
    file.close();


    file.open("prng_service.txt", ios::out | ios::trunc);
    cout << "inserting random number\n";
    file << rand_num; // writes the random num to prng.txt file

    file.close();

    return 0;
}

