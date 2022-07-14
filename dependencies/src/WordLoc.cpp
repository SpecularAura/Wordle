#include "WordLoc.h"

WordLoc::WordLoc(int initval) : yellowcount{0}, chpos{'\0'}
{
    for(auto it = find.begin(); it != find.end(); it++)
    {
        *it = initval;
    }
}

void WordLoc::SetFindChar(char ch)
{
    chpos = ch;
}

void WordLoc::LetterPos(const std::string& str, char ch)
{
    SetFindChar(ch);
    for(int i=0; i < str.size(); i++) 
    {
        if(str[i] == ch)
        {
            find[i] = i;
        }
    }
}

void WordLoc::SetYellow(const WordLoc& wordloc)
{
    int notfoundcount{ static_cast<int>(std::count(find.begin(), find.end(), -1))};
    int lettercount{static_cast<int>(find.size()) - notfoundcount};
    int correctpos{0};
    for (int i = 0; i < find.size(); i++)
    {
        if (find[i] == wordloc.find[i] && find[i] != -1)
        {
            correctpos++;
        }
        
    }
    yellowcount = lettercount - correctpos;
}

bool WordLoc::ShowYellow(int j) 
{
    bool isyellow;
    bool infind;
    for(auto element : find)
    {
        if (element != -1)
        {
            infind = true;
        }
    }
    isyellow = infind && static_cast<bool>(yellowcount);
    UpdateYellow();
    return isyellow;
}

void WordLoc::UpdateYellow()
{
    yellowcount = yellowcount - 1;
}
WordLoc::~WordLoc()
{
    
}