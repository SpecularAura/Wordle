#ifndef WORDLE_GAME_H
#define WORDLE_GAME_H
#include<array>
#include<string>
#include<string_view>
#include<iostream>
#include "WordLoc.h"
#include "colorfulterminal.h"

enum class Error
{
    NoError, WordLimit, RepeatWord
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
    std::array<WordLoc, wordsize::wordsize> answer_loc;
    WordLoc input_loc;
public:
    WordleGame(std::string_view str);
    void GameLoop();
    void Input();
    Error FaultyInput();
    void WordLocInit();
    void WordLoop();
    void PrintChar(Color color, char ch);
    int Contains(int j);
    void EndCheck();
};
#endif