/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntity.Class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriiamuradian <valeriiamuradian@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:57:11 by valeriiamur       #+#    #+#             */
/*   Updated: 2019/10/26 17:02:44 by valeriiamur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEENTITY_CLASS_HPP
# define GAMEENTITY_CLASS_HPP

//this is a base class for the rest
class GameEntity
{
    protected:
        std::string _gameObj;
        bool _hit;
        int current_y;
	    int current_x;
        

    public:
        //constructors and destructors
        GameEntity();
        GameEntity(const GameEntity &src);
        GameEntity(std::string gameObj);
        virtual ~GameEntity();

        //move
        void moveleft(int max);
        void moveright(int max);
        void moveup(int max);
        void movedown(int max);

};

#endif