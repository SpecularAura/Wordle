#ifndef WORDLE_GAME_H
#define WORDLE_GAME_H
#include<array>
#include<string>
#include<string_view>
#include<fstream>
#include<chrono>
#include<random>
#include<vector>
#include<iostream>
#include "WordLoc.h"
//#include "colorfulterminal.h"

enum class Error
{
    NoError, WordLimit, RepeatWord, NotInList
};

enum class Color
{
    Green, Yellow, Grey
};

class WordleGame
{
private:
    int lines_to_delete, no_of_tries;
    bool is_end;
    std::string answer, input;
    std::vector<std::string> input_history;
    std::array<WordLoc, wordsize::wordsize> answer_loc;
    WordLoc input_loc;
    std::vector<std::string> word_list;
public:
    WordleGame();
    WordleGame(std::string_view str);
    void GameLoop();
    bool Input();
    void UpdateInputHistory();
    Error FaultyInput();
    void WordLocInit();
    void WordLoop();
    void PrintChar(Color color, char ch);
    int Contains(int j);
    void EndCheck();    
};
#endif