#include <iostream> 
#include <string>

int main(){
    std::string word = "world";
    std::string guess;
    std::string correctly_guessed = "-----";
    int tries = 0;

    while (guess != word){
        std::cout << "Enter your guess: ";
        std::getline(std::cin, guess);

        // if guess = word
        if (guess == word){
            break;
        }
        else{
            // checking for all the letters that are in the same position as in the correct word's
            for (int i=0; i<word.length(); i++){
                if (guess[i] == word[i]){
                    correctly_guessed[i] = word[i];
                }
            }
            
            // checking for all letters that are within the correct word but in a different index (not creating a separate for loop would result in duplicates when there are 2 occurences of 1 letter)
            for (int i=0; i<word.length(); i++){
                if (word.find(guess[i]) != std::string::npos && correctly_guessed.find(guess[i]) == std::string::npos){
                    std::cout << "Letter " << guess[i] << " is somewhere else within the word" << std::endl;
                }
            }
        }
        std::cout << correctly_guessed << std::endl;
        tries ++;
        
    }
    std::cout << "You won!!" << std::endl;
    std::cout << "It took you " << tries << " tries";
    return 0;
}
