//
//  UIFactory.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 19.02.24.
//

#ifndef UIFactory_hpp
#define UIFactory_hpp

#include "entt.hpp"
#include <string>

class Scene;

class UIFactory final
{
public:
    static entt::entity createImage(Scene& scene, entt::id_type cacheId, std::string frame, double x, double y);
    static entt::entity createLabel(Scene& scene, const std::string& text, double x, double y);
    static entt::entity createScrollingLabel(Scene& scene, const std::string& text, double x, double y);
    static entt::entity createMessage(Scene& scene, const std::string& text, bool autoDestroy = true);
};

#endif /* UIFactory_hpp */
