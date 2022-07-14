#ifndef WORD_LOC_H
#define WORD_LOC_H
#include<string>
#include<array>
#include<algorithm>

namespace wordsize
{
    inline constexpr int wordsize{5};
}

class WordLoc
{
private:
    std::array<int, wordsize::wordsize> find;
    int yellow_count;
    char ch_pos;
public:
    WordLoc(int initval = -1);
    void SetFindChar(char ch);
    void LetterPos(const std::string& str, char ch);
    void SetYellow(const WordLoc& wordloc);
    bool ShowYellow(int j);
    bool operator == (const WordLoc& wordloc);
    bool operator == (char ch);
    bool operator == (int j);
    void UpdateYellow();
};
#endif