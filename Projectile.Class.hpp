#ifndef PROJECTILE_CLASS_HPP
# define PROJECTILE_CLASS_HPP

class Projectile
{
private:

public:
	Projectile();
	Projectile(const Projectile &src);
	~Projectile();

	Projectile	&operator=(const Projectile &rhs);
};

#endif
