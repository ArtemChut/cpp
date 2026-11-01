#include <iostream> 
#include <iterator>
#include <fstream>
#include <vector>
#include <string>
#include <ctime> // works like random

int letterCount(std::string word, char letter){
    int count = 0;
    for (char let : word){
        if (let == letter) count++;
    }
    return count;
}

int main(){
    //opening a file with 5 letter words inside  
    std::ifstream file("5letterWords.txt");

    if (!file)
    {
        std::cout << "File couldn't be located";
        return 1;
    }

    // saving 5 letter words to a vector
    std::vector<std::string> words;
    std::string temp;

    while (std::getline(file, temp))
    {
        words.push_back(temp);
    }
    file.close();


    srand(time(0));

    std::string word = words[rand() % words.size()];
    std::string guess;
    std::string correctly_guessed = "-----";
    int tries = 1;


    std::cout << "Length of a word must be " << word.length() << " characters long \n";
    std::cout << "Enter 'stop' if you want to give up \n";
    std::cout << "|----------------------------------------| \n";
    while (guess != word){
        input: // program jumps here if input length is incorrect
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        if (guess == "stop") goto givenUp;
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

    givenUp:
    std::cout << "The word was '" << word << "'";
    return 0;
}
