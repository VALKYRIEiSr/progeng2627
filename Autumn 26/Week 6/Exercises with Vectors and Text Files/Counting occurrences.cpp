#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

int main()
{

    std::ifstream infile;
    std::string tmp;

    infile.open("text.txt");

    std::vector<std::string> text;

    if (!infile.is_open())
    {
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    while (infile >> tmp)
    {
        text.push_back(tmp);
    }

    infile.close();

    infile.open("words.txt");

    std::vector<std::string> words;

    if (!infile.is_open())
    {
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    while (infile >> tmp)
    {
        words.push_back(tmp);
    }

    infile.close();

    std::vector<int> count(words.size());
    
    for(const std::string& x : text){
        for(int i = 0; i < words.size(); i++){
            if (x == words[i]) count[i]++;
        }
    }

    std::ofstream outfile;
    outfile.open("counting.txt");

    if (!outfile.is_open())
    {
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    for(int i = 0; i < words.size(); i++){
        outfile << words[i] << ": " << count[i] << std::endl;
    }

    outfile.close();

}