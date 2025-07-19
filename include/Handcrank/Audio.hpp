// Copyright (c) Scott Doxey. All Rights Reserved. Licensed under the MIT
// License. See LICENSE in the project root for license information.

#pragma once

#include <SDL_mixer.h>

namespace Handcrank
{

inline auto PlayMusic(Mix_Music *music) -> int
{
    if (music == nullptr)
    {
        return -1;
    }

    return Mix_PlayMusic(music, -1);
}

inline auto PlaySFX(Mix_Chunk *sfx) -> int
{
    if (sfx == nullptr)
    {
        return -1;
    }

    return Mix_PlayChannel(-1, sfx, 0);
}

} // namespace Handcrank
