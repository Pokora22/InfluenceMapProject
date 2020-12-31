

#ifndef Component_hpp
#define Component_hpp

#include <SFML/Graphics.hpp>
class Component
{
public:
    Component();
    virtual void Update(float timeDelta) {};
};
#include <stdio.h>

#endif /* Component_hpp */
