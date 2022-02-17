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

    // step 1 communication pipeline
    // open and writes run to the prng.txt and closes it
    prng.open("prng_service.txt", ios::in | ios::out);
    prng << "run" ; 
    prng.close();

    //storing execution line for num_generator file
    string command_line1 = "g++ num_generator.cpp -o prng";
    const char* command1 = command_line1.c_str();

    // step 2 communication pipeline
    // executing num_generator.cpp 
    cout << "Compiling file using " << command1 << endl;
    system(command1); // compiling num_generator file
    cout << "Running file " << endl;
    system("./prng"); // executing file

    // step 3 communication pipeline
    // opens and reads the random number from prng_service.txt then closes it
    prng.open("prng_service.txt", ios::in | ios::out);
    prng >> num; // stores random number in num
    prng.close();
   

    // step 4 communication pipeline
    // opens and writes the random number to image_service.txt file then closes file
    image.open("image_service.txt", ios::in | ios::out | ios::trunc);
    image << num;
    cout << "num: " << num << endl;
    image.close();


    // step 5 communication pipeline
    // stores execution line for image_service.cpp file
    string command_line2 = "g++ -std=c++17 image_service.cpp -o image";
    const char* command2 = command_line2.c_str();

    cout << "Compiling file using " << command2 << endl;
    system(command2); // compiling num_generator file
    cout << "Running file " << endl;
    system("./image"); // executing file

    // step 6 communication pipeline
    // opening image.txt and reads the contents of the image_service.txt file 
    image.open("image_service.txt", ios::in | ios::out);
    image >> path;
    image.close();

    cout << "\npath of image: \n" << path << "\n\n"; // outputs the path of the image

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