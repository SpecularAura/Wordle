#include "WordleGame.h"
#include <cstdio>

WordleGame::WordleGame(std::string_view str) : 
                no_of_tries{0}, is_end{false}, answer{str}, lines_to_delete{1}

{
}

void WordleGame::GameLoop()
{
    while(!is_end)
    {
        Input();
        WordLocInit();
        no_of_tries++;
        WordLoop();
        EndCheck();
    }
}

Error WordleGame::FaultyInput()
{
    if(input.length() != wordsize::wordsize)
    {
        lines_to_delete++;
        return Error::WordLimit;
    }
    else
    {
        return Error::NoError;
    }
}

void WordleGame::WordLocInit()
{
    //for(int i=lines_to_delete; i>0; i--)
    //{
        printf("\033[A\33[2K\r");
    //}
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
        break;
    case Error::RepeatWord:
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
            answer_loc[j] = answer_loc[cont];
        }
        else
        {
            //answer_loc[j].SetFindChar(input[j]);
            //input_loc.SetFindChar(input[j]);
            answer_loc[j].LetterPos(answer, input[j]);
            input_loc.LetterPos(input, input[j]);
            answer_loc[j].SetYellow(input_loc);
        }

        if(answer_loc[j] == j)
        {
            PrintChar(Color::Green, input[j]);
        }
        else if(answer_loc[j].ShowYellow(j))
        {
            PrintChar(Color::Yellow, input[j]);
        }
        else
        {
            PrintChar(Color::Grey, input[j]);
        }

    }
}

int WordleGame::Contains(int j)
{
    for(int i=0; i<j; i++)
    {
        if(answer_loc[i] == input[j])
        {
            return i;
        }
    }
    return -1;
}

void WordleGame::PrintChar(Color color, char ch)
{
    switch (color)
    {
    case Color::Green:
        green_disp(ch);
        break;
    
    case Color::Grey:
        grey_disp(ch);
        break;
    case Color::Yellow:
        yellow_disp(ch);
        break;
    default:
        std::cout<<"Should Not Be Here\n";
        break;
    }
}

void WordleGame::EndCheck()
{
    std::cout<<"\n";

    if(answer == input)
    {
        std::cout<<"Your score :"<<no_of_tries<< "/6";
        is_end = true;
    }
    else if(no_of_tries == 6)
    {
        std::cout<<"The word was "<<answer;
        is_end = true;
    }

}