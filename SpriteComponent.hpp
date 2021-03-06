//
// Created by pokor on 29/12/2020.
//

#ifndef INFLUENCEMAPDEMO_SPRITECOMPONENT_HPP
#define INFLUENCEMAPDEMO_SPRITECOMPONENT_HPP

#include <SFML/Graphics.hpp>
#include "Component.h"

class SpriteComponent : public Component{

public:
    SpriteComponent();
    virtual void Draw(sf::RenderWindow &window, float timeDelta);
    bool SetSprite(sf::Texture& texture, bool isSmooth, int frames = 1, int frameSpeed = 0);
    sf::Sprite& GetSprite();
    int GetFrameCount() const;
    bool IsAnimated();
    void SetAnimated(bool isAnimated);
    void setPosition(sf::Vector2f position);
    void setOrigin(sf::Vector2f position);
    void setTexture(const sf::Texture &texture);
    sf::Vector2u getTextureSize() const;
private:
    void NextFrame();
private:
    //ToDo add in attributes from main object's graphics.
    float m_timeDelta;
    int m_animationSpeed;
    bool m_isAnimated;
    int m_frameCount;
    int m_currentFrame;
    int m_frameWidth;
    int m_frameHeight;
    /**
     * An aggregate of the time passed between draw calls.
     */
    sf::Sprite m_sprite;
};

#endif //INFLUENCEMAPDEMO_SPRITECOMPONENT_HPP
