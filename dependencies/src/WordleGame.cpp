#include "WordleGame.h"
#include "WordLoc.h"
WordleGame::WordleGame(std::string_view str) : 
                no_of_tries{0}, is_end{false}, answer{str}, lines_to_delete{1}

{

}

void WordleGame::GameLoop()
{
    while(is_end)
    {
        Input();
        WordLoop();
        EndCheck();
    }
}

void WordleGame::Input()
{
    std::cin>>input;
    Error message = FaultyInput();
    switch (message)
    {
    case Error::NoError:
        break;
    case Error::WordLimit:
        std::cout<<"ENTER THE CORRECT WORD SIZE\n";
        lines_to_delete++;
        break;
    case Error::RepeatWord:
        lines_to_delete++;
        std::cout<<"";
        break;
    default:
        std::cout<<"Should Not Be Here\n";
        break;
    }
}
void WordleGame::WordLoop()
{
    for(int j = 0; j < wordsize::wordsize; j++)
    {
        int cont = Contains(j);
        if (cont != -1)
        {

        }
    }
}
WordleGame::~WordleGame()
{
}
