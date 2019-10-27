/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:58:59 by valeriiamur       #+#    #+#             */
/*   Updated: 2019/10/27 03:10:31 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.Class.hpp"

#include <ncurses.h>
#include <iostream>
#include <string>

int main(void)
{
    // Window *screen = new Window;
    Game    *game = new Game;

    // delete screen;
    delete game;

    return (0);
}
