//
// Created by pokor on 14/12/2020.
//

#ifndef INFLUENCEMAPDEMO_TRANSFORMCOMPONENT_H
#define INFLUENCEMAPDEMO_TRANSFORMCOMPONENT_H


#include <SFML/Graphics.hpp>

class TransformComponent {
public:
    TransformComponent();
    void SetPosition(sf::Vector2f position);
    sf::Vector2f&  GetPosition();
private:
    sf::Vector2f  m_position;
};


#endif //INFLUENCEMAPDEMO_TRANSFORMCOMPONENT_H
