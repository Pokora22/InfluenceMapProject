#include "utils.h"
#include "Player.h"
#include <iostream>

// Constructor.
Player::Player() :
m_statPoints(0)
{
	
	std::string className;
		className = "mage";
    m_speed = 200;
	// Load textures.
	m_textureIDs[static_cast<int>(ANIMATION_STATE::WALK_UP)] = TextureManager::AddTexture( "G:\\Dokumenty\\WIT\\C++\\InfluenceMapDemo\\spr_" + className + "_walk_up.png");
	m_textureIDs[static_cast<int>(ANIMATION_STATE::WALK_DOWN)] = TextureManager::AddTexture( "G:\\Dokumenty\\WIT\\C++\\InfluenceMapDemo\\spr_" + className + "_walk_down.png");
	m_textureIDs[static_cast<int>(ANIMATION_STATE::WALK_RIGHT)] = TextureManager::AddTexture( "G:\\Dokumenty\\WIT\\C++\\InfluenceMapDemo\\spr_" + className + "_walk_right.png");
	m_textureIDs[static_cast<int>(ANIMATION_STATE::WALK_LEFT)] = TextureManager::AddTexture("G:\\Dokumenty\\WIT\\C++\\InfluenceMapDemo\\spr_" + className + "_walk_left.png");
	m_textureIDs[static_cast<int>(ANIMATION_STATE::IDLE_UP)] = TextureManager::AddTexture("G:\\Dokumenty\\WIT\\C++\\InfluenceMapDemo\\spr_" + className + "_idle_up.png");
	m_textureIDs[static_cast<int>(ANIMATION_STATE::IDLE_DOWN)] = TextureManager::AddTexture( "G:\\Dokumenty\\WIT\\C++\\InfluenceMapDemo\\spr_" + className + "_idle_down.png");
	m_textureIDs[static_cast<int>(ANIMATION_STATE::IDLE_RIGHT)] = TextureManager::AddTexture( "G:\\Dokumenty\\WIT\\C++\\InfluenceMapDemo\\spr_" + className + "_idle_right.png");
	m_textureIDs[static_cast<int>(ANIMATION_STATE::IDLE_LEFT)] = TextureManager::AddTexture( "G:\\Dokumenty\\WIT\\C++\\InfluenceMapDemo\\spr_" + className + "_idle_left.png");

	// Set initial sprite.
	SetSprite(TextureManager::GetTexture(m_textureIDs[static_cast<int>(ANIMATION_STATE::WALK_UP)]), false, 8, 12);
	m_currentTextureIndex = static_cast<int>(ANIMATION_STATE::WALK_UP);

    std::shared_ptr<SpriteComponent> spriteCmpt = GetComponent<SpriteComponent>();
    spriteCmpt->setOrigin(sf::Vector2f(13.f, 18.f));

//	m_sprite.setOrigin(sf::Vector2f(13.f, 18.f));

//    std::shared_ptr<TransformComponent> transformCmpt = GetComponent<TransformComponent>();
//    std::cout << "(Player.cpp)(Constructor)Transform: " << transformCmpt << std::endl;
}

// Updates the player object.
void Player::Update(float timeDelta)
{
    m_timeDelta = timeDelta;
	// Calculate movement speed based on the timeDelta since the last update.
	sf::Vector2f previousPosition = m_position;
	m_velocity = sf::Vector2f(0,0);

	// Calculate where the current movement will put us.
	if (Input::IsKeyPressed(Input::KEY::KEY_LEFT))
	{
		// Set movement speed.
		m_velocity.x = -m_speed * timeDelta;
	}
	else if (Input::IsKeyPressed(Input::KEY::KEY_RIGHT))
	{
		// Set movement speed.
        m_velocity.x = m_speed * timeDelta;
	}

	if (Input::IsKeyPressed(Input::KEY::KEY_UP))
	{
		// Set movement speed
        m_velocity.y = -m_speed * timeDelta;
	}
	else if (Input::IsKeyPressed(Input::KEY::KEY_DOWN))
	{
		// Set movement speed.
        m_velocity.y = m_speed * timeDelta;
	}

	m_position += m_velocity;

	Entity::Update(timeDelta);

	// update the sprite position
	SetPosition(m_position);
}

// Returns the player's class.
PLAYER_CLASS Player::GetClass() const
{
    return m_class;
}



// Set the player's health.
void Player::SetHealth(int healthValue)
{
	m_health = healthValue;

	if (m_health > m_maxHealth)
	{
		m_health = m_maxHealth;
	}
}
