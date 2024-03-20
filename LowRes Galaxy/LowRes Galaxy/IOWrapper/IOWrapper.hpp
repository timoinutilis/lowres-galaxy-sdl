//
//  IOWrapper.hpp
//  LowRes Galaxy ZERO
//
//  Created by Timo Kloss on 20.03.24.
//

#ifndef IOWrapper_hpp
#define IOWrapper_hpp

#include <string>

struct SDL_Window;
struct SDL_Renderer;

class IOWrapper
{
public:
    IOWrapper();
    ~IOWrapper();
    
    void initVideo(const std::string& title, const int width, const int height, const int defaultWindowScale);
    void initAudio(const int frequency, const int channels);
    
    SDL_Renderer* getRenderer();
    
private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
};

#endif /* IOWrapper_hpp */
