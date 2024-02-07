//
//  SpriteRenderer.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 07.02.24.
//

#ifndef SpriteRenderer_hpp
#define SpriteRenderer_hpp

#include <SDL2/SDL.h>
#include <SDL2_mixer/SDL_mixer.h>
#include "entt.hpp"

class SpriteRenderer
{
private:
    SDL_Renderer* renderer;
    entt::registry& registry;
    
public:
    SpriteRenderer(SDL_Renderer* renderer, entt::registry& registry);
    void render();
};

#endif /* SpriteRenderer_hpp */
