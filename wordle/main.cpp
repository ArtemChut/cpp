#include <iostream> 
#include <iterator>
#include <ctime> // works like random

int letterCount(std::string word, char letter){
    int count = 0;
    for (char let : word){
        if (let == letter) count++;
    }
    return count;
}

std::string words[] = {"apple", "world", "trick", "adore", "prize"};
int main(){
    srand(time(0));
    std::string word = words[rand() % std::size(words)];
    std::string guess;
    std::string correctly_guessed = "-----";
    int tries = 1;


    std::cout << "Length of a word must be " << word.length() << " characters long \n";
    std::cout << "------------------------------------------ \n";
    while (guess != word){
        input: // program jumps here if input length is incorrect
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        if (guess.length() != word.length()) goto input;

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

                    if (sameLetterCountNotUsedUp && letterCount(guess.substr(0,i+1),guess[i]) <= letterCount(word,guess[i])){
                        std::cout << "Letter " << guess[i] << " is somewhere else within the word \n";
                    }
                }
            }
        }
        std::cout << correctly_guessed << std::endl;
        tries++;
        
    }
    std::cout << "You won!! \n";
    std::cout << "It took you " << tries << " tries";
    return 0;
}