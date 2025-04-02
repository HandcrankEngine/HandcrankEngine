#include <cassert>
#include <iostream>
#include <stdexcept>
#include <string>

#include "Handcrank/Vector2.hpp"

using namespace Handcrank;

auto main() -> int
{

    {
        // Create Vector2
        auto a = Vector2(1, 2);

        assert(a.x == 1);
        assert(a.y == 2);

        std::cout << ".";
    }

    {
        // Copy a Vector2
        auto a = Vector2(1, 2);
        auto b = Vector2(a);

        assert(b.x == 1);
        assert(b.y == 2);

        std::cout << ".";
    }

    {
        // Add two Vector2 structs
        Vector2 a = Vector2(1, 2);
        Vector2 b = Vector2(3, 4);
        auto c = a + b;

        assert(c.x == 4);
        assert(c.y == 6);

        std::cout << ".";
    }

    {
        // Subtract two Vector2 structs
        Vector2 a = Vector2(1, 2);
        Vector2 b = Vector2(3, 4);
        auto c = a - b;

        assert(c.x == -2);
        assert(c.y == -2);

        std::cout << ".";
    }

    {
        // Divide Vector2 struct by int
        Vector2 a = Vector2(1, 2);
        auto b = a / 2;

        assert(b.x == 0.5F);
        assert(b.y == 1);

        std::cout << ".";
    }

    {
        // Divide Vector2 struct by 0
        Vector2 a = Vector2(1, 2);

        try
        {
            auto b = a / 0;
        }
        catch (const std::invalid_argument &e)
        {
            std::string message = e.what();

            assert(message.find("divide by zero") != std::string::npos);
        }

        std::cout << ".";
    }

    {
        // Multiply Vector2 struct by int
        Vector2 a = Vector2(1, 2);
        auto b = a * 2;

        assert(b.x == 2);
        assert(b.y == 4);

        std::cout << ".";
    }

    {
        // Lerp between two Vector2 structs with t 0
        Vector2 a = Vector2(1, 2);
        Vector2 b = Vector2(3, 4);
        auto c = Vector2::Lerp(a, b, 0);

        assert(c.x == 1);
        assert(c.y == 2);

        std::cout << ".";
    }

    {
        // Lerp between two Vector2 structs with t 0.5
        Vector2 a = Vector2(1, 2);
        Vector2 b = Vector2(3, 4);
        auto c = Vector2::Lerp(a, b, 0.5);

        assert(c.x == 2);
        assert(c.y == 3);

        std::cout << ".";
    }

    {
        // Lerp between two Vector2 structs with t 1
        Vector2 a = Vector2(1, 2);
        Vector2 b = Vector2(3, 4);
        auto c = Vector2::Lerp(a, b, 1);

        assert(c.x == 3);
        assert(c.y == 4);

        std::cout << ".";
    }

    {
        // Lerp between two Vector2 structs with t 1.5
        Vector2 a = Vector2(1, 2);
        Vector2 b = Vector2(3, 4);
        auto c = Vector2::LerpUnclamped(a, b, 1.5);

        assert(c.x == 4);
        assert(c.y == 5);

        std::cout << ".";
    }

    {
        // Convert to SDL_FPoint
        Vector2 a = Vector2(1, 2);
        SDL_FPoint b = a.ToFPoint();

        assert(typeid(SDL_FPoint) == typeid(b));

        assert(b.x == a.x);
        assert(b.y == a.y);

        std::cout << ".";
    }

    {
        // Create from SDL_FPoint
        SDL_FPoint a = {1, 2};
        Vector2 b = Vector2(a);

        assert(typeid(Vector2) == typeid(b));

        assert(b.x == a.x);
        assert(b.y == a.y);

        std::cout << ".";
    }

    {
        // Convert to SDL_FRect
        Vector2 a = Vector2(1, 2);
        SDL_FRect b = a.ToFRect();

        assert(typeid(SDL_FRect) == typeid(b));

        assert(b.x == a.x);
        assert(b.y == a.y);

        std::cout << ".";
    }

    {
        // Create from SDL_FRect
        SDL_FRect a = {1, 2};
        Vector2 b = Vector2(a);

        assert(typeid(Vector2) == typeid(b));

        assert(b.x == a.x);
        assert(b.y == a.y);

        std::cout << ".";
    }

    return 0;
}
