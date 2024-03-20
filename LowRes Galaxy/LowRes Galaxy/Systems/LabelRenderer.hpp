//
//  LabelRenderer.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 16.02.24.
//

#ifndef LabelRenderer_hpp
#define LabelRenderer_hpp

class Scene;

class LabelRenderer final
{
public:
    LabelRenderer(Scene& scene) noexcept;
    void render() const;
    
private:
    Scene& scene;
};

#endif /* LabelRenderer_hpp */
