#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <filesystem> 
 

using namespace std;
namespace fs = std::filesystem;

int main() {

    fstream image;
    int num = 0;
    string photo;

    // opens and reads from image_service.txt then closes it
    image.open("image_service.txt", ios::in | ios::out);
    image >> num;
    image.close();


    // gets path of image
    vector <string> file_paths;
    string path = "./images";
    for (const auto & entry : fs::directory_iterator(path)) {
        cout << entry.path() << endl;
        file_paths.push_back(entry.path());
    }   


    photo = "/Users/josephbabal/Desktop/Winter_2022/cs_361/software_engr_I/assignments/CS-361-repo/assignment2/"+ file_paths[num];
    cout << photo << endl;

    


    image.open("image_service.txt", ios::in | ios::out | ios::trunc);
    image << photo;
    image.close();




    return 0;
}