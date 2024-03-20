//
//  SpriteRenderer.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 07.02.24.
//

#ifndef SpriteRenderer_hpp
#define SpriteRenderer_hpp

class Scene;

class SpriteRenderer final
{
public:
    SpriteRenderer(Scene& scene) noexcept;
    void render() const;
    
private:
    Scene& scene;
};

#endif /* SpriteRenderer_hpp */
