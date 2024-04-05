#include "test.h"
#include <iostream>

int main()
{
    FallingObject pingponglabda(4 * 9.81, 9.81);
    std::cout << 4 * 9.81 << std::endl;
    std::cout << (3.0 / 4.0) * (4.0 * 9.81) << std::endl;
    std::cout << "GetFalltime:" << pingponglabda.GetFallTime() << std::endl;
    std::cout << "sebesseg a felenel:" << pingponglabda.GetSpeed(pingponglabda.GetFallTime() * (3.0 / 4.0)) << std::endl;
    std::cout << "magassag a felenel:" << pingponglabda.GetHeight(pingponglabda.GetFallTime() * (3.0 / 4.0)) << std::endl;
    std::cout << pingponglabda.GetHeight(pingponglabda.GetFallTime() * (0.75)) / (4 * 9.81) << std::endl;
    std::cout << 1/(pingponglabda.GetHeight(pingponglabda.GetFallTime() * (0.75)) / (4 * 9.81)) << std::endl;
    return 0;
}