#pragma once

#include <algorithm>

#include <SDL.h>

namespace Handcrank
{

struct Vector2
{
    float x;
    float y;

    Vector2() : x(0), y(0) {}
    Vector2(const float x, const float y) : x(x), y(y) {}
    explicit Vector2(const SDL_FPoint point) : x(point.x), y(point.y) {}
    explicit Vector2(const SDL_FRect rect) : x(rect.x), y(rect.y) {}

    Vector2 operator+(const Vector2 &other) const
    {
        return Vector2(x + other.x, y + other.y);
    }

    Vector2 operator-(const Vector2 &other) const
    {
        return Vector2(x - other.x, y - other.y);
    }

    Vector2 operator*(const float number) const
    {
        return Vector2(x * number, y * number);
    }

    Vector2 operator/(const float number) const
    {
        if (number == 0)
        {
            throw std::invalid_argument("Can't divide by zero.\n");
        }

        return Vector2(x / number, y / number);
    }

    static Vector2 Lerp(const Vector2 &start, const Vector2 &destination,
                        const float t)
    {
        return LerpUnclamped(start, destination, std::clamp<float>(t, 0, 1));
    }

    static Vector2 LerpUnclamped(const Vector2 &start,
                                 const Vector2 &destination, const float t)
    {
        auto newPosition = Vector2(start);

        newPosition.x += (destination.x - start.x) * t;
        newPosition.y += (destination.y - start.y) * t;

        return newPosition;
    }

    SDL_FPoint ToFPoint() const { return {x, y}; }

    SDL_FRect ToFRect() const { return {x, y}; }
};

} // namespace Handcrank
