//
// Created by pokor on 29/12/2020.
//

#ifndef INFLUENCEMAPDEMO_SPRITECOMPONENT_HPP
#define INFLUENCEMAPDEMO_SPRITECOMPONENT_HPP

#include <SFML/Graphics.hpp>
#include "Component.h"

class SpriteComponent : public Component
{
public:
    SpriteComponent() {};
    virtual void Draw(sf::RenderWindow& window, float timeDelta) {};
    bool SetSprite(sf::Texture& texture, bool isSmooth, int frames =
    1, int frameSpeed = 0);
    sf::Sprite& GetSprite();
    int GetFrameCount() const;
    bool IsAnimated();
    void SetAnimated(bool isAnimated);
    void setPosition(sf::Vector2f position)
    {
        m_sprite.setPosition(position);
    }
    void setOrigin(sf::Vector2f position){
        m_sprite.setOrigin(position);
    }

    void setTexture(const sf::Texture &texture){
        this->m_sprite.setTexture(texture);
    }
private:
    void NextFrame();
private:
    //ToDo add in attributes from main object's graphics.
    sf::Sprite m_sprite;
    /**
     * An aggregate of the time passed between draw calls.
     */
    float m_timeDelta;
};

#endif //INFLUENCEMAPDEMO_SPRITECOMPONENT_HPP
