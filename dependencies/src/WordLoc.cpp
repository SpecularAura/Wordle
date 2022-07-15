#include "WordLoc.h"

WordLoc::WordLoc(int initval) : yellow_count{0}, ch_pos{'\0'}
{
    for(auto it = find.begin(); it != find.end(); it++)
    {
        *it = initval;
    }
}

void WordLoc::SetFindChar(char ch)
{
    ch_pos = ch;
}

void WordLoc::LetterPos(const std::string& str, char ch)
{
    SetFindChar(ch);
    for(int i=0; i < str.length(); i++) 
    {
        if(str[i] == ch)
        {
            find[i] = i;
        }
        else
        {
            find[i] = -1;
        }
    }
}

void WordLoc::SetYellow(const WordLoc& wordloc)
{
    int answerlettercount{0};
    int correctpos{0};
    for (int i = 0; i < find.size(); i++)
    {
        if (find[i] == wordloc.find[i] && find[i] != -1)
        {
            correctpos++;
        }
        if (find[i] != -1)
        {
            answerlettercount++;
        }
        
    }
    yellow_count = answerlettercount - correctpos;
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
    isyellow = infind && static_cast<bool>(yellow_count);
    UpdateYellow();
    return isyellow;
}

bool WordLoc::operator == (const WordLoc& wordloc)
{
    return (ch_pos == wordloc.ch_pos);
}

bool WordLoc::operator == (char ch)
{
    return (ch_pos == ch);
}

bool WordLoc::operator == (int j)
{
    return (find[j] == j);
}
void WordLoc::UpdateYellow()
{
    if(yellow_count != 0)
    {
        yellow_count = yellow_count - 1;
    }
}

std::ostream& operator << (std::ostream& out, const WordLoc& wordloc)
{
    for(int i = 0; i < wordloc.find.size(); i++)
    {
        out<<wordloc.find[i]<<" ";
    }
    out<<"\n";
    return out;
}