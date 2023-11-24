#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>
#include <list>

int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

//Function which chooses a random word from a given list
std::string getRandomWord(const std::vector<std::string>& wordList) {
    //Random number generator seeding (creating the generator)
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    //Create a random index
    int randomIndex = getRandomNumber(0, wordList.size() - 1);

    return wordList[randomIndex];
}


//std::time(nullptr) = returns the time since 1970 in seconds
//static_cast<unsigned int> = because the function expects an unsigned int 
                           //we transform the result of std::time(nullptr)
                           //into unsigned integer




int main() {

    //List of 100 random words in english
    std::vector<std::string> randomWords = {
    "have", "not", "that", "you", "this", "but", "his", "from", "they", "say",
    "her", "she", "will", "one", "all", "would", "there", "their", "what", "up",
    "out", "about", "who", "get", "which", "make", "like", "time", "just", "know",
    "take", "people", "into", "year", "your", "good", "some", "could", "them", "see",
    "other", "than", "then", "now", "look", "only", "come", "its", "over", "think",
    "also", "back", "after", "work", "first", "well", "even", "want", "because", "any",
    "these", "give", "day", "most", "random", "chosen", "word", "list", "with", "longer",
    "than", "letters", "generate", "number", "min", "max", "time", "index", "return", "chosen"
    };


    std::string word = getRandomWord(randomWords);
    std::string input;
    std::vector<char> vectInit;
    std::vector<char> vectInput;
    std::vector<char> lines;
    std::vector<char> output;
    const char* lin = "_";
    const char* green = "G";
    const char* yellow = "Y";
    const char* ics = "X";

    std::cout << "Rules of the game: " << std::endl;
    std::cout << "-> Y: good letter but wrong position" << std::endl;
    std::cout << "-> G: good letter and good position" << std::endl;
    std::cout << "-> X: wrong letter" << std::endl;
    std::cout << std::endl;

    // Vector for searched word
    for (int i = 0; i < word.size(); i++) {
        vectInit.push_back(word[i]);
        lines.push_back(*lin);
    }
    std::cout << "The searched word has the following structure -> " << std::endl;
    for (int j = 0; j < lines.size(); j++) {
        std::cout << lines[j] << " ";
    }
    std::cout << std::endl;

    bool smth = true;
    while (smth) {
        bool var = true;
        //New output for every word
        std::vector<char> output;
        std::cout << "Choose a word -> " << std::endl;
        while (var) {
            std::cin >> input;
            if (input.size() == vectInit.size()) {
                var = false;
            }
            else {
                std::cout << "Try a word with the same number of letters!!!" << std::endl;
            }
        }

        // Vector input word
        for (int k = 0; k < input.size(); k++) {
            vectInput.push_back(input[k]);
        }

        // Forming the word by using X, G, Y
        for (int k = 0; k < vectInput.size(); k++) {
            bool found = false;
            for (int w = 0; w < vectInit.size(); w++) {
                if (vectInput[k] == vectInit[w] && k == w) {
                    output.push_back(*green);
                    found = true;
                }
                else if (vectInput[k] == vectInit[w] && k != w) {
                    output.push_back(*yellow);
                    found = true;
                }
            }
            if (!found) {
                output.push_back(*ics);
            }
        }


        for (int i = 0; i < output.size(); i++) {
            std::cout << output[i] << " ";
        }
        std::cout << std::endl;

        bool allLettersAreG = true;
        for (int l = 0; l < output.size(); l++) {
            if (output[l] != *green) {
                allLettersAreG = false;
                break;
            }
        }

        if (allLettersAreG) {
            std::cout << "Good job!" << std::endl;
            smth = false;
        }

        std::cout << std::endl;

        vectInput.clear();
        output.clear();
    }


    return 0;
}
