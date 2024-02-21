//
//  Font.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 15.02.24.
//

#include "Font.hpp"
#include <SDL2_image/SDL_image.h>

Font::Font(SDL_Renderer* renderer, const std::string& filepath)
{
    SDL_Surface* image = IMG_Load((filepath + ".png").c_str());
    texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);
}

Font::~Font()
{
    SDL_DestroyTexture(texture);
}

void Font::drawString(SDL_Renderer* renderer, const std::string& text, const int x, const int y) const
{
    int charX = x;
    for (auto character : text)
    {
        drawCharacter(renderer, character, charX, y);
        charX += 8;
    }
}

void Font::drawCharacter(SDL_Renderer* renderer, char character, const int x, const int y) const
{
    int index = static_cast<int>(character) - 32;
    if (index >= 0 && index < 64)
    {
        SDL_Rect src {(index % 16) * 8, (index / 16) * 8, 8, 8};
        SDL_Rect dst {x, y, 8, 8};
        SDL_RenderCopy(renderer, texture, &src, &dst);
    }
}
