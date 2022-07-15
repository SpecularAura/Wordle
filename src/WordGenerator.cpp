#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include <chrono> // for std::chrono functions
#include <random>

class Timer
{
private:
	// Type aliases to make accessing nested type easier
	using clock_type = std::chrono::steady_clock;
	using second_type = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_type> m_beg { clock_type::now() };

public:
	void reset()
	{
		m_beg = clock_type::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<second_type>(clock_type::now() - m_beg).count();
	}
};

int main()
{
    Timer t;
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
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, 2310); // distribution in range [1, 6]
    std::ofstream outfr{"TestFile.txt"};
    outfr << words[dist(mt)];
    std::cout<<"Word Generated";
    return 0;
}