#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

int main()
{
    std::string tmp;
    std::string inputfilename;
    std::cout << "enter name of advertisment file" << std::endl;

    std::cin >> inputfilename;

    std::ifstream infile; 
    infile.open(inputfilename);

    std::vector<std::string> advertisment;

    if (!infile.is_open())
    {
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    while (infile >> tmp)
    {
        advertisment.push_back(tmp);
    }

    infile.close();

    std::cout << "enter name of meaning file" << std::endl;

    std::cin >> inputfilename;
    infile.open(inputfilename);

    std::vector<std::string> meaning;

    if (!infile.is_open())
    {
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    while (infile >> tmp)
    {
        meaning.push_back(tmp);
    }

    infile.close();

    std::string outputfilename;
    std::cout << "enter name of output file" << std::endl;

    std::cin >> outputfilename;

    std::ofstream outfile;
    outfile.open(outputfilename);

    if (!outfile.is_open())
    {
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    bool flag;
    
    for(const std::string& x : advertisment){
        flag = false;
        for (int i = 0; i < meaning.size(); i+=2){
            if(x == meaning[i]){
                outfile << meaning[i+1] << " ";
                flag = true;
            }
        }
        if(!flag) outfile << x << " ";
    }

    outfile.close();
}