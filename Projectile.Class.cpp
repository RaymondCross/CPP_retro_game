#include "Projectile.Class.hpp"

Projectile::Projectile()
{

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
