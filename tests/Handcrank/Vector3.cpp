#include <assert.h>

#include "Handcrank/Vector3.hpp"

int main()
{

    {
        // Create Vector3
        auto a = Vector3(1, 2, 3);

        assert(a.x == 1);
        assert(a.y == 2);
        assert(a.z == 3);
    }
    {
        // Copy a Vector3
        auto a = Vector3(1, 2, 3);
        auto b = Vector3(a);

        assert(b.x == 1);
        assert(b.y == 2);
        assert(b.z == 3);
    }

    {
        // Add two Vector3 structs
        Vector3 a = Vector3(1, 2, 3);
        Vector3 b = Vector3(3, 4, 5);
        auto c = a + b;

        assert(c.x == 4);
        assert(c.y == 6);
        assert(c.z == 8);
    }

    {
        // Subtract two Vector3 structs
        Vector3 a = Vector3(1, 2, 3);
        Vector3 b = Vector3(3, 4, 5);
        auto c = a - b;

        assert(c.x == -2);
        assert(c.y == -2);
        assert(c.z == -2);
    }

    {
        // Divide Vector3 struct by int
        Vector3 a = Vector3(1, 2, 3);
        auto b = a / 2;

        assert(b.x == 0.5f);
        assert(b.y == 1);
        assert(b.z == 1.5f);
    }

    {
        // Multiply Vector3 struct by int
        Vector3 a = Vector3(1, 2, 3);
        auto b = a * 2;

        assert(b.x == 2);
        assert(b.y == 4);
        assert(b.z == 6);
    }

    {
        // Lerp between two Vector2 structs with t 0
        Vector3 a = Vector3(1, 2, 3);
        Vector3 b = Vector3(3, 4, 5);
        auto c = Vector3::Lerp(a, b, 0);

        assert(c.x == 1);
        assert(c.y == 2);
        assert(c.z == 3);
    }

    {
        // Lerp between two Vector2 structs with t 0.5
        Vector3 a = Vector3(1, 2, 3);
        Vector3 b = Vector3(3, 4, 5);
        auto c = Vector3::Lerp(a, b, 0.5);

        assert(c.x == 2);
        assert(c.y == 3);
        assert(c.z == 4);
    }

    {
        // Lerp between two Vector2 structs with t 1
        Vector3 a = Vector3(1, 2, 3);
        Vector3 b = Vector3(3, 4, 5);
        auto c = Vector3::Lerp(a, b, 1);

        assert(c.x == 3);
        assert(c.y == 4);
        assert(c.z == 5);
    }

    {
        // Lerp between two Vector2 structs with t 1.5
        Vector3 a = Vector3(1, 2, 3);
        Vector3 b = Vector3(3, 4, 5);
        auto c = Vector3::LerpUnclamped(a, b, 1.5);

        assert(c.x == 4);
        assert(c.y == 5);
        assert(c.z == 6);
    }

    return 0;
}
