// Copyright (c) Scott Doxey. All Rights Reserved. Licensed under the MIT
// License. See LICENSE in the project root for license information.

#pragma once

#include <SDL_mixer.h>

#include "Utilities.hpp"

namespace Handcrank
{

inline const int DEFAULT_AUDIO_FREQUENCY = 44100;
inline const int DEFAULT_AUDIO_CHUNK_SIZE = 1024;

namespace
{
bool audioLoadedForFirstTime = false;

std::unordered_map<std::string, Mix_Music *> audioMusicCache =
    std::unordered_map<std::string, Mix_Music *>();
std::unordered_map<std::string, Mix_Chunk *> audioSFXCache =
    std::unordered_map<std::string, Mix_Chunk *>();
} // namespace

inline auto ClearAudioCache() -> void
{
    for (const auto &audio : audioMusicCache)
    {
        if (audio.second != nullptr)
        {
            Mix_FreeMusic(audio.second);
        }
    }

    for (const auto &audio : audioSFXCache)
    {
        if (audio.second != nullptr)
        {
            Mix_FreeChunk(audio.second);
        }
    }

    audioMusicCache.clear();
    audioSFXCache.clear();
}

inline auto SetupAudio() -> int
{
    return Mix_OpenAudio(DEFAULT_AUDIO_FREQUENCY, MIX_DEFAULT_FORMAT, 2,
                         DEFAULT_AUDIO_CHUNK_SIZE);
}

inline auto LoadMusic(const char *path) -> Mix_Music *
{
    if (audioMusicCache.find(path) != audioMusicCache.end())
    {
        return audioMusicCache.find(path)->second;
    }

    if (!audioLoadedForFirstTime)
    {
        SetupAudio();

        audioLoadedForFirstTime = true;
    }

    auto *music = Mix_LoadMUS(path);

    if (music == nullptr)
    {
        return nullptr;
    }

    audioMusicCache.insert_or_assign(path, music);

    return music;
}

inline auto LoadMusic(const void *mem, const int size) -> Mix_Music *
{
    auto hash = MemHash(mem, size);

    if (audioMusicCache.find(hash) != audioMusicCache.end())
    {
        return audioMusicCache.find(hash)->second;
    }

    if (!audioLoadedForFirstTime)
    {
        SetupAudio();

        audioLoadedForFirstTime = true;
    }

    auto *rw = SDL_RWFromConstMem(mem, size);

    if (rw == nullptr)
    {
        return nullptr;
    }

    auto *music = Mix_LoadMUS_RW(rw, 1);

    if (music == nullptr)
    {
        return nullptr;
    }

    audioMusicCache.insert_or_assign(hash, music);

    return music;
}

} // namespace Handcrank
