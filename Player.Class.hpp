/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.Class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:57:00 by valeriiamur       #+#    #+#             */
/*   Updated: 2019/10/27 04:51:28 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_CLASS_HPP
# define PLAYER_CLASS_HPP

# include <string>
# include "GameEntity.Class.hpp"

class Player : public GameEntity
{
    private:
        int _lives;
    public:
        Player();
        Player(const Player &src);
        ~Player();

        Player  &operator=(const Player &rhs);

        int getLives();
};

#endif
