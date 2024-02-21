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

class Font final
{
public:
    Font(SDL_Renderer* renderer, const std::string& filepath);
    ~Font();
    
    void drawString(SDL_Renderer* renderer, const std::string& text, const int x, const int y) const;
    void drawCharacter(SDL_Renderer* renderer, char character, const int x, const int y) const;
    
private:
    SDL_Texture *texture;
};

#endif /* Font_hpp */
