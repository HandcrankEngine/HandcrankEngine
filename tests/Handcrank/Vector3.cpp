#include <iostream>
#include <stdexcept>
#include <string>

#include <assert.h>

#include "Handcrank/Vector3.hpp"

using namespace Handcrank;

int main()
{

    {
        // Create Vector3
        auto a = Vector3(1, 2, 3);

        assert(a.x == 1);
        assert(a.y == 2);
        assert(a.z == 3);

        std::cout << ".";
    }
    {
        // Copy a Vector3
        auto a = Vector3(1, 2, 3);
        auto b = Vector3(a);

        assert(b.x == 1);
        assert(b.y == 2);
        assert(b.z == 3);

        std::cout << ".";
    }

    {
        // Add two Vector3 structs
        Vector3 a = Vector3(1, 2, 3);
        Vector3 b = Vector3(3, 4, 5);
        auto c = a + b;

        assert(c.x == 4);
        assert(c.y == 6);
        assert(c.z == 8);

        std::cout << ".";
    }

    {
        // Subtract two Vector3 structs
        Vector3 a = Vector3(1, 2, 3);
        Vector3 b = Vector3(3, 4, 5);
        auto c = a - b;

        assert(c.x == -2);
        assert(c.y == -2);
        assert(c.z == -2);

        std::cout << ".";
    }

    {
        // Divide Vector3 struct by int
        Vector3 a = Vector3(1, 2, 3);
        auto b = a / 2;

        assert(b.x == 0.5f);
        assert(b.y == 1);
        assert(b.z == 1.5f);

        std::cout << ".";
    }

    {
        // Divide Vector3 struct by 0
        Vector3 a = Vector3(1, 2, 3);

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
        // Multiply Vector3 struct by int
        Vector3 a = Vector3(1, 2, 3);
        auto b = a * 2;

        assert(b.x == 2);
        assert(b.y == 4);
        assert(b.z == 6);

        std::cout << ".";
    }

    {
        // Lerp between two Vector2 structs with t 0
        Vector3 a = Vector3(1, 2, 3);
        Vector3 b = Vector3(3, 4, 5);
        auto c = Vector3::Lerp(a, b, 0);

        assert(c.x == 1);
        assert(c.y == 2);
        assert(c.z == 3);

        std::cout << ".";
    }

    {
        // Lerp between two Vector2 structs with t 0.5
        Vector3 a = Vector3(1, 2, 3);
        Vector3 b = Vector3(3, 4, 5);
        auto c = Vector3::Lerp(a, b, 0.5);

        assert(c.x == 2);
        assert(c.y == 3);
        assert(c.z == 4);

        std::cout << ".";
    }

    {
        // Lerp between two Vector2 structs with t 1
        Vector3 a = Vector3(1, 2, 3);
        Vector3 b = Vector3(3, 4, 5);
        auto c = Vector3::Lerp(a, b, 1);

        assert(c.x == 3);
        assert(c.y == 4);
        assert(c.z == 5);

        std::cout << ".";
    }

    {
        // Lerp between two Vector2 structs with t 1.5
        Vector3 a = Vector3(1, 2, 3);
        Vector3 b = Vector3(3, 4, 5);
        auto c = Vector3::LerpUnclamped(a, b, 1.5);

        assert(c.x == 4);
        assert(c.y == 5);
        assert(c.z == 6);

        std::cout << ".";
    }

    {
        // Convert to SDL_FPoint
        Vector3 a = Vector3(1, 2, 3);
        SDL_FPoint b = a.ToFPoint();

        assert(typeid(SDL_FPoint) == typeid(b));

        assert(b.x == a.x);
        assert(b.y == a.y);

        std::cout << ".";
    }

    {
        // Create from SDL_FPoint
        SDL_FPoint a = {1, 2};
        Vector3 b = Vector3(a);

        assert(typeid(Vector3) == typeid(b));

        assert(b.x == a.x);
        assert(b.y == a.y);

        std::cout << ".";
    }

    {
        // Convert to SDL_FRect
        Vector3 a = Vector3(1, 2, 3);
        SDL_FRect b = a.ToFRect();

        assert(typeid(SDL_FRect) == typeid(b));

        assert(b.x == a.x);
        assert(b.y == a.y);

        std::cout << ".";
    }

    {
        // Create from SDL_FRect
        SDL_FRect a = {1, 2};
        Vector3 b = Vector3(a);

        assert(typeid(Vector3) == typeid(b));

        assert(b.x == a.x);
        assert(b.y == a.y);

        std::cout << ".";
    }

    return 0;
}
