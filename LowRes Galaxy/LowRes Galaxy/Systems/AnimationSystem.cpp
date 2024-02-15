//
//  AnimationSystem.cpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 14.02.24.
//

#include "AnimationSystem.hpp"
#include "entt.hpp"
#include "../Scenes/Scene.hpp"
#include "../Components/Animation.hpp"
#include "../Components/Sprite.hpp"

void AnimationSystem::update(Scene* scene)
{
    const auto view = scene->getRegistry().view<Animation, Sprite>();
    for (auto entity : view)
    {
        auto& animation = view.get<Animation>(entity);
        auto& sprite = view.get<Sprite>(entity);
        
        sprite.frame = animation.frames[animation.frameIndex];
        if (++animation.tick >= animation.frameTicks)
        {
            if (animation.frameIndex < animation.frames.size() - 1)
            {
                ++animation.frameIndex;
            }
            else if (animation.destroyAfterEnd)
            {
                scene->getRegistry().destroy(entity);
            }
            else
            {
                animation.frameIndex = 0;
            }
            animation.tick = 0;
        }
        
    }
}
