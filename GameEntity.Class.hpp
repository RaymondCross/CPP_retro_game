/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntity.Class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:57:11 by valeriiamur       #+#    #+#             */
/*   Updated: 2019/10/27 14:20:02 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEENTITY_CLASS_HPP
# define GAMEENTITY_CLASS_HPP

#include <string>

//this is a base class for the rest
class GameEntity
{
    protected:
        char    _gameObj;
        bool _hit;//???
        int _current_y;
	    int _current_x;
        int _HP;

    public:
        //constructors and destructors
        GameEntity();
        GameEntity(const GameEntity &src);
        GameEntity(char gameObj);
        virtual ~GameEntity();

        GameEntity &operator=(const GameEntity &rhs);
        //move
        void moveleft(int max);
        void moveright(int max);
        void moveup(int max);
        void movedown(int max);

        char    getObj();
        int getX();
        int getY();
        int getHP();

        void    setX(int x);
        void    setY(int y);

        // void    takeDamage();
        virtual void    fire() = 0;
};

#endif
