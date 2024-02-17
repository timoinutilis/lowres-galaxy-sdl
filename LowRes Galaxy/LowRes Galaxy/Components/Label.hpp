//
//  Label.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 16.02.24.
//

#ifndef Label_h
#define Label_h

#include <string>
#include "../Rendering/Font.hpp"

struct Label
{
    Font* font = nullptr;
    std::string text;
    bool isHidden = false;
};

#endif /* Label_h */
