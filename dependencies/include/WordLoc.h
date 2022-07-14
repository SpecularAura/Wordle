#ifndef WORDLOC_H
#define WORDLOC_H
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
    int yellowcount;
    char chpos;
public:
    WordLoc(int initval = -1);
    void SetFindChar(char ch);
    void LetterPos(const std::string& str, char ch);
    void SetYellow(const WordLoc& wordloc);
    bool ShowYellow(int j);
    void UpdateYellow();
    ~WordLoc();
};


#endif