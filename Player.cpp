
 #include "Player.h"
 #include <iostream>
 #include "SFML/Graphics.hpp"


Player::Player()
{
  m_Speed = 20.0f;
  m_MoveX = 0.0f;
  m_MoveY = 0.0f;
  m_Rectangle.setSize(sf::Vector2f(m_RectSizeWidth, m_RectSizeHeight));
  m_Rectangle.setFillColor(RED);
  m_Rectangle.setPosition(m_RectPositionX,m_RectPositionY);
}

void Player::draw( sf::RenderWindow& Window)
{
  Window.draw(m_Rectangle);
}

void Player::onKeyDown(sf::Keyboard::Key& KeyCode)
{
  switch(KeyCode)
  {
    case sf::Keyboard::Right:
    {
      m_MoveX += m_Speed;
    }
    break;
    case sf::Keyboard::Left:
    {
      m_MoveX += -m_Speed;
    }
    break;
    case sf::Keyboard::Up:
    {
      m_MoveY += -m_Speed;
    }
    break;
    case sf::Keyboard::Down:
    {
      m_MoveY += m_Speed;
    }
    break;
  }
}

void Player::onKeyUp(sf::Keyboard::Key& KeyCode)
{
}


void Player::update()
{
  if(m_Rectangle.getPosition().x > 600)
  {
    m_MoveX = 0;
  }
  else if(m_Rectangle.getPosition().x  < 0)
  {
    m_MoveX = 600;
  }
  else if(m_Rectangle.getPosition().y > 600)
  {
    m_MoveY = 0;
  }
  else if(m_Rectangle.getPosition().y < 0)
  {
    m_MoveY = 600;
  }

  m_Rectangle.setPosition(m_MoveX, m_MoveY);

}