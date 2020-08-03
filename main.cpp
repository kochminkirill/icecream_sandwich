#include <iostream>

bool isIcecreamSandwich(std::string sandwich_string)
{
    size_t length_string{ sandwich_string.length() };
    int sign{ 0 };

    if(length_string < 3)
    {
        std::cout << "Your icecream sandwich can't consist of < than 3 signs!\n";
        return false;
    }

    //got the beginning of the sandwich
    std::string beginning_string{ "" };
    int sign_beginning_string{ 0 };
    while(sandwich_string[sign_beginning_string] == sandwich_string[sign] && sign < static_cast<int>(length_string))
        beginning_string += sandwich_string[sign++];

    //case when sandwich has only filling
    if(sign == static_cast<int>(length_string))
    {
        std::cout << "Sandwich can't consist of only filling\n";
        return false;
    }

    // got the filling of the sandwich
    int start_middle_sign{ sign };
    std::string middle_string{ "" };
    while(sandwich_string[start_middle_sign] == sandwich_string[sign] && sign < static_cast<int>(length_string))
        middle_string += sandwich_string[sign++];

    //case when sandwich doesn't have ned
    if(sign == static_cast<int>(length_string))
    {
        std::cout << "Sandwich must have end!\n";
        return false;
    }

    int start_end_sign{ sign };
    //case when sandwich consists of different fillings
    if(sandwich_string[sign_beginning_string] != sandwich_string[start_end_sign])
    {
        std::cout << "sandwich must have only with one filling\n";
        return false;
    }

    //got sandwich's end
    std::string end_string{ "" };
    while(sandwich_string[start_end_sign] == sandwich_string[sign] && sign < static_cast<int>(length_string))
        end_string += sandwich_string[sign++];

    // case when sandwich's end consists of different signs
    if(sign != static_cast<int>(length_string))
    {
        std::cout << "Sandwich's end must be equal!\n";
        return false;
    }

    //case when beginning and end aren't equal
    if(beginning_string != end_string)
    {
        std::cout << "Sandwich's ends must be equal!\n";
        return false;
    }

    std::cout << "It's sandwich\n";
    return true;
}

int main()
{
    std::cout << std::boolalpha;

    //examples
    std::cout << isIcecreamSandwich("AABBBAA") << '\n';
    std::cout << isIcecreamSandwich("3&&3") << '\n';
    std::cout << isIcecreamSandwich("yyyyymmmmmmmmyyyyy") << '\n';
    std::cout << isIcecreamSandwich("hhhhhhhhmhhhhhhhh") << "\n\n";

    //aren't sandwiches
    std::cout << isIcecreamSandwich("BBBBB") << '\n';
    std::cout << isIcecreamSandwich("AAACCCAA") << '\n';
    std::cout << isIcecreamSandwich("AACDCAA") << '\n';
    std::cout << isIcecreamSandwich("A") << '\n';

    return 0;
}
