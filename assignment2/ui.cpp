#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <string>


 

using namespace std; 

char input_valid(char);

int main() {

    char input;
    int num = 0;
    fstream prng, image;
    string path;

    cout << "Enter t: ";
    input = input_valid(input); // enterface 

    
    // open and writes to the prng.txt and closes it
    prng.open("prng_service.txt", ios::in | ios::out);
    prng << "run" ; 
    prng.close();

    // storing execution line for num_generator file
    string command_line1 = "g++ num_generator.cpp -o prng";
    const char* command1 = command_line1.c_str();

    cout << "Compiling file using " << command1 << endl;
    system(command1); // compiling num_generator file
    cout << "\nRunning file " << endl;
    system("./prng"); // executing file

    // opens and reads the random number then closes txt file
    prng.open("prng_service.txt", ios::in | ios::out);
    prng >> num; // stores random number in num
    prng.close();



    // opens and writes to image.txt file then closes file
    image.open("image_service.txt", ios::in | ios::out | ios::trunc);
    image << num;
    cout << "num: " << num << endl;
    image.close();

    // stores execution line for image_service file
    string command_line2 = "g++ -std=c++17 image_service.cpp -o image";
    const char* command2 = command_line2.c_str();

    cout << "Compiling file using " << command2 << endl;
    system(command2); // compiling num_generator file
    cout << "\nRunning file " << endl;
    system("./image"); // executing file

    image.open("image_service.txt", ios::in | ios::out);
    image >> path;

    cout << path << endl;



    return 0;
}

char input_valid(char letter) {
    cin >> letter;
    while (letter != 't' || cin.fail()) {
        cout << "\nInvalid input\n";
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Enter again: ";
        cin >> letter;
    }
    return letter;
}