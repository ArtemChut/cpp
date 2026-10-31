#include <iostream> 
#include <string>

int letterCount(std::string word, char letter){
    int count = 0;
    for (char let : word){
        if (let == letter) count++;
    }
    return count;
}

int main(){
    std::string word = "apple";
    std::string guess;
    std::string correctly_guessed = "-----";
    int tries = 1;



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
            
            // checking for letters in wrong spots
            for (int i=0; i<word.length(); i++){
                if (word.find(guess[i]) != std::string::npos && word[i] != guess[i]){
                    bool sameLetterCountNotUsedUp = letterCount(correctly_guessed,guess[i]) < letterCount(word,guess[i]);

                    if (sameLetterCountNotUsedUp){
                        std::cout << "Letter " << guess[i] << " is somewhere else within the word" << std::endl;
                    }
                }
            }
        }
        std::cout << correctly_guessed << std::endl;
        tries++;
        
    }
    std::cout << "You won!!" << std::endl;
    std::cout << "It took you " << tries << " tries";
    return 0;
}
