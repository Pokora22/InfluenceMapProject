//
//  evilPlayer.cpp
//  AssetManagerv1
//
//  Created by Denis Flynn on 16/10/2018.
//  Copyright © 2018 Denis Flynn. All rights reserved.
//

#include "evilPlayer.hpp"
void evilPlayer::Update(float timeDelta)
{
    m_timeDelta = timeDelta;
    // Calculate movement speed based on the timeDelta since the last update.
    sf::Vector2f previousPosition = m_position;
    m_velocity = sf::Vector2f(0,0);

    int vertical = 0;
    int horizontal = 0;

    // Calculate where the current movement will put us.
    if (Input::IsKeyPressed(Input::KEY::KEY_E_LEFT))
        horizontal = -1;
    else if (Input::IsKeyPressed(Input::KEY::KEY_E_RIGHT))
        horizontal = 1;

    if (Input::IsKeyPressed(Input::KEY::KEY_E_UP))
        vertical = -1;
    else if (Input::IsKeyPressed(Input::KEY::KEY_E_DOWN))
        vertical = 1;

    m_velocity.x = horizontal * m_speed * timeDelta;
    m_velocity.y = vertical * m_speed * timeDelta;

    m_position += m_velocity;

    Entity::Update(timeDelta);

    // update the sprite position
    SetPosition(m_position);
}
