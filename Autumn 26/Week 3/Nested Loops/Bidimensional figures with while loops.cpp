#include <iostream>

int main(){
    int n;
    int c, c2;
    std::cin >> n;
    c2 = n;

    // n times we draw one row
    // note that we need a different variable
    // for the loop counter
    while(c2){

        // the following loop draws one row
        int c = n;
        while(c){
            std::cout << "*"; 
            c--;
            // there is no << std::endl
            // because we want them on the same row
        }

        std::cout << std::endl;
        c2--;
        // we go on a newline after each row

    }

}