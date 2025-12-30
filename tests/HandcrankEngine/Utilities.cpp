#include <cassert>
#include <iostream>

#include "HandcrankEngine/Utilities.hpp"

#include "../images/sdl_logo.h"

using namespace HandcrankEngine;

auto main(int argc, char *argv[]) -> int
{

    {
        auto result = TryParseInt("1");

        assert(result == true);

        std::cout << ".";
    }

    {
        int value;

        auto result = TryParseInt("1", value);

        assert(result == true);
        assert(value == 1);

        std::cout << ".";
    }

    {
        int value;

        auto result = TryParseInt("2test", value);

        assert(result == true);
        assert(value == 2);

        std::cout << ".";
    }

    {
        auto result = TryParseInt("2test");

        assert(result == true);

        std::cout << ".";
    }

    {
        int value;

        auto result = TryParseInt("test", value);

        assert(result == false);

        std::cout << ".";
    }

    {
        auto result = TryParseInt("test");

        assert(result == false);

        std::cout << ".";
    }

    {
        assert(LeftPad("1", '0', 5) == "00001");

        std::cout << ".";
    }

    {
        assert(RightPad("1", '0', 5) == "10000");

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

    {
        class ThisIsATestForTesting
        {
        };

        ThisIsATestForTesting temp;

        auto value = GetClassNameSimple(temp);

        assert(value == "ThisIsATestForTesting");

        std::cout << ".";
    }

    {
        auto value = MemHash(images_sdl_logo_png, images_sdl_logo_png_len);

#ifdef __APPLE__
        assert(value == 16443477445022879210U);
#elif __linux__
        assert(value == 7456648896600017335U);
#else
        assert(("Unknown platform", false));
#endif

        std::cout << ".";
    }

    return 0;
}
