#include "test.h"
#include <iostream>

int main()
{
    FallingObject pingponglabda(60.0, 9.81);

    std::cout << "GetFalltime:" << pingponglabda.GetFallTime() << std::endl;
    std::cout << "sebesseg a felenel:" << pingponglabda.GetSpeed(pingponglabda.GetFallTime() / 2) << std::endl;
        std::cout << "magassag a felenel:" << pingponglabda.GetHeight(pingponglabda.GetFallTime() / 2) << std::endl;
    return 0;
}