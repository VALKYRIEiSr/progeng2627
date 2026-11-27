#include <iostream>

void find_words(
    const std::vector<std::string>& grid,
    const std::vector<std::string>& words,
    std::vector<std::string>& solution,
    std::vector<std::string>& not_found
){
    std::vector<bool> found_tally(words.size(), false);
    std::vector<std::string> output(grid.size(), std::string(grid[0].size(), '#'));
    
    for(int y = 0; y < grid.size(); y++){
        for(int x = 0; x < grid[0].size(); x++){ //iterates through grid
            for(int i = 0; i < words.size(); i++){ //iterates through words for each location in grid
                bool found_x = false;
                bool found_y = false;
                if(found_tally[i] == false && words[i][0] == grid[y][x]){ //if first letter of the word matches and the word wasnt already found then continue with scanning the rest of the grid both vertically and horizontally
                    bool found = true;
                    if(found_y == false && words[i].size() <= grid[0].size() - x){ //if another word wasnt already found on the same location and axis and the grid has enough remaning space for this word
                        for(int l = 0; l < words[i].size(); l++){
                            if(words[i][l] != grid[y][x+l]) found = false;
                        }
                    }
                    else found = false;

                    if(found){ //update output
                                found_tally[i] = true;
                                found_x = true;
                                for(int k = 0; k < words[i].size(); k++){
                                    output[y][x+k] = words[i][k];
                                }
                            }

                    if(found_y == false && found == false && words[i].size() <= grid.size() - y){ //if another word wasnt already found on the same location and axis and the grid has enough remaning space for this word
                        found = true;
                        for(int l = 0; l < words[i].size(); l++){
                            if(words[i][l] != grid[y+l][x]) found = false;
                            
                        }
                    }
                    else found = false;

                    if(found){ //update output
                                found_tally[i] = true;
                                found_y = true;
                                for(int k = 0; k < words[i].size(); k++){
                                    output[y+k][x] = words[i][k];
                                }
                            }
                }
            }
        }
    }
    solution = output;
    for(int i = 0; i < words.size(); i++){
        if(!found_tally[i]) not_found.push_back(words[i]);
    }


}

int main(){

    std::vector<std::string> grid = {
        "xappleg",
        "dzeazkg",
        "zwazzbx",
        "dxnqzoy",
        "qyueytp",
        "pythtyg"
    };

    std::vector<std::string> words = {"peanut", "bot", "mango", "apple", "cinnamon"};
    std::vector<std::string> solution;
    std::vector<std::string> not_found;

    find_words(grid, words, solution, not_found);

    std::vector<std::string> expected_solution = {
        "#apple#",
        "##e####",
        "##a##b#",
        "##n##o#",
        "##u##t#",
        "##t####"
    };

    std::vector<std::string> expected_not_found = {"mango", "cinnamon"};

    if( (solution == expected_solution) && (not_found == expected_not_found) ){
        std::cout << "test passed" << std::endl;
    }
    else{
        std::cout << "test failed" << std::endl;
    }

    std::cout << "solution:" << std::endl;
    for(int i = 0; i < solution.size(); i++){
        std::cout << solution[i] << std::endl;
    }

    std::cout << "not found:" << std::endl;
    for(int i = 0; i < not_found.size(); i++){
        std::cout << not_found[i] << std::endl;
    }

}
