/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntity.Class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriiamuradian <valeriiamuradian@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:58:44 by valeriiamur       #+#    #+#             */
/*   Updated: 2019/10/26 16:56:16 by valeriiamur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEntity.Class.hpp"

GameEntity::GameEntity()
{
    return;
}

GameEntity::GameEntity(std::string gameObj)
{
    this->_gameObj = gameObj;
    this->_hit = false;
    return;
}

GameEntity::~GameEntity()
{
    return;
}

GameEntity::GameEntity(const GameEntity &src)
{
    *this = src;
    return ;
}

GameEntity &GameEntity::operator=(const GameEntity &rhs)
{
	if (this != &rhs)
	{
		this->_gameObj = rhs._gameObj;
		this->current_x = rhs.current_x;
		this->current_y = rhs.current_y;
	}
	return (*this);
}

void GameEntity::moveleft(int max)
{
	if (this->current_x > 1  && this->current_x < max)
		this->current_x--;
}

void GameEntity::moveright(int max)
{
	if (this->current_x + gameObj.length() <= (max - gameObj.length() + 1))
		this->current_x++;
}

void GameEntity::moveup(int max)
{
	if (this->current_y > 1 && this->current_y < max)
		this->current_y--;
}

void GameEntity::movedown(int max)
{
	if (this->current_y <= max + 1)
		this->current_y++;
}