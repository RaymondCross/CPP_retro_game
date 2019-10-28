#include "Projectile.Class.hpp"

Projectile::Projectile()
{
}

Projectile::Projectile(char	gameobj, int y, int x) : GameEntity(gameobj, y, x)
{
	if (gameobj == '>')
		this->player_proj = true;
	else
		this->player_proj = false;
}

Projectile::Projectile(const Projectile &src)
{
	*this = src;
}

Projectile::~Projectile()
{
}

Projectile	&Projectile::operator=(const Projectile &rhs)
{
	if (this != &rhs)
	{
		;
	}
	return *this;
}
