//
//  Font.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 15.02.24.
//

#ifndef Font_hpp
#define Font_hpp

#include <SDL2/SDL.h>
#include <string>

class Font
{
public:
    Font(SDL_Renderer* renderer, const std::string& filepath);
    ~Font();
    
    void drawString(SDL_Renderer* renderer, const std::string& text, const int x, const int y);
    void drawCharacter(SDL_Renderer* renderer, char character, const int x, const int y);
    
private:
    SDL_Texture *texture;
};

#endif /* Font_hpp */
