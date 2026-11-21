#include <iostream>
#include <fstream>

// argc is the number of command line arguments
// argv is an array of C-style strings
// we'll see what this means more in detail later on

int main(int argc, char* argv[]){
    std::string file_name = argv[1];
    std::ifstream input;
    input.open(file_name);
    if(!input.is_open()){
        std::cout << "Couldnt open" << std::endl;
        return EXIT_FAILURE;
    }

    std::string tmp;
    while(input >> tmp){
        std::cout << tmp << std::endl;
    }

    input.close();

}