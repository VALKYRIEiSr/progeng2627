#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

std::vector<unsigned long> catalan_numbers(int n)
{
    std::vector<unsigned long> Cn = {1};
    for (int x = 1; x <= n; x++)
    {
        unsigned long sum = 0;
        for (int i = 0; i < x; i++)
        {
            sum += Cn[i] * Cn[x - 1 - i];
            
        }
        Cn.push_back(sum);
    }
    return Cn;
}

int main()
{
    std::ifstream infile;
    infile.open("expressions.txt");
    if(!infile.is_open()){
        std::cout << "Couldnt open file"; 
        return EXIT_FAILURE;
    } 

    std::string tmp;
    int op_max = 0;
    std::vector<int> operators;
    std::vector<std::string> input;
    while(infile >> tmp){
        int op = 0;
        input.push_back(tmp);
        for(char x : tmp){
            if(!(x >= '0' && x <= '9')) op++;
        }
        if(op > op_max) op_max = op;
        operators.push_back(op);
    }

    infile.close();

    std::ofstream outfile;
    outfile.open("expressions_counts.txt");
    if(!outfile.is_open()){
        std::cout << "Couldnt open file"; 
        return EXIT_FAILURE;
    } 

    std::vector<unsigned long> catalan_v = catalan_numbers(op_max);

    for(int i = 0; i < operators.size(); i++){
        unsigned long catalan = catalan_v[operators[i]];
        int distance = 15;
        std::string gap;
        for(int j = 0; j < distance - input[i].size(); j++){
            gap.push_back(' ');
        }
        outfile << input[i] << gap << catalan << std::endl;
    }

    outfile.close();

}
