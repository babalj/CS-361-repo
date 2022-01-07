#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cstdlib>

#include <filesystem>

using namespace std;

int main() {

    fstream image;
    int num = 0;
    //string path;

    // opens and reads from image_service.txt then closes it
    image.open("image_service.txt", ios::in | ios::out);
    image >> num;
    image.close();


    // gets path of image
    string path = "/path/to/directory";
    for (const auto & entry : fs::directory_iterator(path))
        cout << entry.path() << endl;
    }   
    


    image.open("image_service.txt", ios::in | ios::out | ios::trunc);
    image << path;
    image.close();



    return 0;
}