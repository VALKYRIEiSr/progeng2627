#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

void union_vector(const std::vector<std::string> &vin1, const std::vector<std::string> &vin2, std::vector<std::string> &vout)
{
    bool flag = false;
    for (const std::string& a : vin1)
    {
        for (const std::string& b : vin2)
        {
            if (a == b)
                flag = true;
        }
        if (!flag)
            vout.push_back(a);
        flag = false;
    }
    for (const std::string& b : vin2)
    {
        vout.push_back(b);
    }
}

void intersection_vector(const std::vector<std::string> &vin1, const std::vector<std::string> &vin2, std::vector<std::string> &vout)
{
    bool flag = false;
    for (const std::string& a : vin1)
    {
        for (const std::string& b : vin2)
        {
            if (a == b)
                flag = true;
        }
        if (flag)
            vout.push_back(a);
        flag = false;
    }
}

int main()
{

    std::ifstream infile;
    std::string tmp;

    infile.open("warehouse1.txt");

    std::vector<std::string> w1;

    if (!infile.is_open())
    {
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    while (infile >> tmp)
    {
        w1.push_back(tmp);
        // instead of printing the values
        // as in the example above
        // first we store them in a vector
    }

    infile.close();

    infile.open("warehouse2.txt");

    std::vector<std::string> w2;

    if (!infile.is_open())
    {
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    while (infile >> tmp)
    {
        w2.push_back(tmp);
    }

    infile.close();

    std::vector<std::string> combination;
    std::vector<std::string> intersection;

    union_vector(w1, w1, combination);
    intersection_vector(w1, w2, intersection);

    std::ofstream outfile;
    outfile.open("union.txt");

    if (!outfile.is_open())
    {
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    for(const std::string& x : combination){
        outfile << x << std::endl;
    }

    outfile.close();

    outfile.open("intersection.txt");

    if (!outfile.is_open())
    {
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    for(const std::string& x : intersection){
        outfile << x << std::endl;
    }
    
    outfile.close();

}