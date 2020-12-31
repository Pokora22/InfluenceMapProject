#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include "Component.hpp"
#include <SFML/Graphics.hpp>
#include "utils.h"

class TransformComponent : public Component
{
public:

    TransformComponent();
    void SetPosition(sf::Vector2f position);
    sf::Vector2f& GetPosition();

private:
    sf::Vector2f  m_position;

}; 
#endif