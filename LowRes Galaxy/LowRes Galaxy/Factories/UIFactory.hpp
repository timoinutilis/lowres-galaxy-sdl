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

class UIFactory
{
public:
    static void createLabel(Scene& scene, const std::string& text, double x, double y);
    static void createScrollingLabel(Scene& scene, const std::string& text, double x, double y);
};

#endif /* UIFactory_hpp */
