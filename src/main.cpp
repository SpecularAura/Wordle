#include"WordleGame.h"
#include"WordLoc.h"
#include<iostream>
#include<fstream>
#include<string>
int main()
{
    // std::ifstream inf{"TestFile.txt"};
    // std::string t;
    // inf >> t;
    WordleGame Game{};
    Game.GameLoop();
}