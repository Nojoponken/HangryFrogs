// #include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
using namespace std;

int main()
{
    std::ifstream ifs{"./path.txt"};
    vector<sf::Vector2f> path{};

    while (true)
    {
        float x{};
        float y{};

        ifs >> x;
        ifs >> y;

        if (ifs.eof())
            break;

        path.push_back(sf::Vector2f{x, y});
    }

    /*     vector<string> numbers{};

        copy(std::istream_iterator<std::string>(ifs),
             std::istream_iterator<std::string>(),
             back_inserter(numbers));

        vector<sf::Vector2f> path{};
        for (long unsigned int i{}; i < numbers.size(); ++i)
        {
            float x{stof(numbers.at(i))};
            float y{stof(numbers.at(i + 1))};

            path.push_back({x, y});
            if (i + 1 < numbers.size())
            {
                i += 1;
            }
        }
     */
    for (auto word : path)
    {
        cout << word.x << " , " << word.y << endl;
    }
}
