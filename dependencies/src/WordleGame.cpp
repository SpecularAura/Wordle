#include "WordleGame.h"

WordleGame::WordleGame(std::string_view str) : 
                no_of_tries{0}, is_end{false}, answer{str}, lines_to_delete{0}{}

WordleGame::WordleGame():no_of_tries{0}, is_end{false}, lines_to_delete{0}
{
    std::vector<std::string> words;
    std::string str{};
    std::ifstream inf{"NewWordleList.txt"};

    if( !inf )
    {
        std::cerr<< "Could not open NewWordleList.txt";
    }

    while(inf)
    {
        inf >> str;
        words.push_back(str);
    }
    std::mt19937 mt{ static_cast<unsigned int>(
		std::chrono::steady_clock::now().time_since_epoch().count()
		) };
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, 2310); // distribution in range [1, 6]
    std::ofstream outfr{"TestFile.txt"};
    str = words[dist(mt)];
    outfr << str;
    word_list = words;
    answer = str;
}

/* std::string WordleGame::GenrateRandom()
{
    std::vector<std::string> words;
    std::string str{};
    std::ifstream inf{"NewWordleList.txt"};

    if( !inf )
    {
        std::cerr<< "Could not open NewWordleList.txt";
    }

    while(inf)
    {
        inf >> str;
        words.push_back(str);
    }
    std::mt19937 mt{ static_cast<unsigned int>(
		std::chrono::steady_clock::now().time_since_epoch().count()
		) };
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, 2310); // distribution in range [1, 6]
    std::ofstream outfr{"TestFile.txt"};
    int random_no = dist(mt);
    outfr << words[random_no];
    return words[random_no];
} */
void WordleGame::GameLoop()
{
    while(!is_end)
    {

        if (Input())
        {
            continue;
        }
        WordLocInit();
        no_of_tries++;
        WordLoop();
        EndCheck();
    }
}

Error WordleGame::FaultyInput()
{
    auto it = std::find(word_list.cbegin(), word_list.cend(), input);
    if(input.length() != wordsize::wordsize)
    {
        lines_to_delete++;
        return Error::WordLimit;
    }
    else if(it == word_list.cend())
    {
        lines_to_delete++;
        return Error::NotInList;
    }
    else
    {
        return Error::NoError;
    }
}

void WordleGame::WordLocInit()
{
    for(int i=lines_to_delete; i>0; i--)
    {
        std::cout<<"\033[A\33[2K\r";
    }
    lines_to_delete = 0;
}
bool WordleGame::Input()
{
    std::cin>>input;
    std::cout<<"\033[A\33[2K\r";
    Error message = FaultyInput();
    switch (message)
    {
    case Error::NoError:
        return false;
        break;
    case Error::WordLimit:
        std::cout<<"ENTER THE CORRECT WORD SIZE\n";
        return true;
    case Error::RepeatWord:
        std::cout<<"YOU HAVE ALREADY ENTERED A WORD\n";
        return true;
    case Error::NotInList:
        std::cout<<"NOT IN WORD LIST\n";
        return true;
    default:
        return true;
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