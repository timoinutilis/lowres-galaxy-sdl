//
//  UISelectable.hpp
//  LowRes Galaxy
//
//  Created by Timo Kloss on 31.03.24.
//

#ifndef UISelectable_h
#define UISelectable_h

enum class UISelectableStatus
{
    normal,
    selected,
    pressed
}

struct UISelectable final
{
    UISelectableStatus status;
};

#endif /* UISelectable_h */
