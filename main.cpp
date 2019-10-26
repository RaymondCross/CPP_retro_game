/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriiamuradian <valeriiamuradian@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:58:59 by valeriiamur       #+#    #+#             */
/*   Updated: 2019/10/26 15:39:20 by valeriiamur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Window.Class.hpp"

#include <ncurses.h>
#include <iostream>
#include <string>

int main(void)
{
    Window *screen = new Window;
    sleep( 3 );

    delete screen;

    return (0);
}