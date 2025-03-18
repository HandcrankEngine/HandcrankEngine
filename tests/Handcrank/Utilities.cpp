#include <iostream>

#include <assert.h>

#include "Handcrank/Utilities.hpp"

using namespace Handcrank;

int main()
{

    {
        assert(LeftPad("1", '0', 5).compare("00001") == 0);

        std::cout << ".";
    }

    {
        assert(RightPad("1", '0', 5).compare("10000") == 0);

        std::cout << ".";
    }

    {
        assert(Lerp(0, 1, 0.5) == 0.5);
        assert(Lerp(0, 10, 0.5) == 5);

        std::cout << ".";
    }

    {
        assert(InverseLerp(0, 1, 0.5) == 0.5);
        assert(InverseLerp(0, 10, 5) == 0.5);

        std::cout << ".";
    }

    {
        auto value = RandomNumberRange(-1, 1);

        assert(value >= -1);
        assert(value <= 1);

        std::cout << ".";
    }

    {
        auto value = RandomBoolean();

        assert(value == true || value == false);

        std::cout << ".";
    }

    return 0;
}
