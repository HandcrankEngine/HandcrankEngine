#include <assert.h>

#include "Handcrank/Vector2.hpp"

int main()
{

    {
        // Create Vector2
        auto a = Vector2(1, 2);

        assert(a.x == 1);
        assert(a.y == 2);
    }

    {
        // Copy a Vector2
        auto a = Vector2(1, 2);
        auto b = Vector2(a);

        assert(b.x == 1);
        assert(b.y == 2);
    }

    {
        // Add two Vector2 structs
        Vector2 a = Vector2(1, 2);
        Vector2 b = Vector2(3, 4);
        auto c = a + b;

        assert(c.x == 4);
        assert(c.y == 6);
    }

    {
        // Subtract two Vector2 structs
        Vector2 a = Vector2(1, 2);
        Vector2 b = Vector2(3, 4);
        auto c = a - b;

        assert(c.x == -2);
        assert(c.y == -2);
    }

    {
        // Divide two Vector2 structs
        Vector2 a = Vector2(1, 2);
        auto b = a / 2;

        assert(b.x == 0.5f);
        assert(b.y == 1);
    }

    {
        // Multiply two Vector2 structs
        Vector2 a = Vector2(1, 2);
        auto b = a * 2;

        assert(b.x == 2);
        assert(b.y == 4);
    }

    {
        // Lerp between two Vector2 structs with t 0
        Vector2 a = Vector2(1, 2);
        Vector2 b = Vector2(3, 4);
        auto c = Vector2::Lerp(a, b, 0);

        assert(c.x == 1);
        assert(c.y == 2);
    }

    {
        // Lerp between two Vector2 structs with t 0.5
        Vector2 a = Vector2(1, 2);
        Vector2 b = Vector2(3, 4);
        auto c = Vector2::Lerp(a, b, 0.5);

        assert(c.x == 2);
        assert(c.y == 3);
    }

    {
        // Lerp between two Vector2 structs with t 1
        Vector2 a = Vector2(1, 2);
        Vector2 b = Vector2(3, 4);
        auto c = Vector2::Lerp(a, b, 1);

        assert(c.x == 3);
        assert(c.y == 4);
    }

    {
        // Lerp between two Vector2 structs with t 1.5
        Vector2 a = Vector2(1, 2);
        Vector2 b = Vector2(3, 4);
        auto c = Vector2::LerpUnclamped(a, b, 1.5);

        assert(c.x == 4);
        assert(c.y == 5);
    }

    return 0;
}