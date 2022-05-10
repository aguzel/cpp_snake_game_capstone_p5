#ifndef METAGAME_H
#define METAGAME_H

#include "SDL.h"
#include <string>
#include <iostream>

class MetaGame
{
public:
    MetaGame() : platformUsed(std::string())
    {
        platformUsed = getPlatform();
    }

    /**
     * Sets the user's system platfrom to the private variable platformUsed.
     * Returns the platform as a std::string.
     */
    std::string getPlatform();
    void printPlatform();

private:
    std::string platformUsed;
};

std::string MetaGame::getPlatform()
{
    const char *platform = SDL_GetPlatform();
    std::string p(platform);
    platformUsed = p;
    return platformUsed;
};

void MetaGame::printPlatform()
{
    if (platformUsed != "")
        std::cout << "Platform Detected: " << platformUsed << "\n";
    else
        std::cout << "No System Platform Detected." << "\n";
}

#endif