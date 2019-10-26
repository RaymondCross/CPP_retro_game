/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.Class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriiamuradian <valeriiamuradian@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:57:21 by valeriiamur       #+#    #+#             */
/*   Updated: 2019/10/26 15:56:33 by valeriiamur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Window.Class.hpp"
#include <ncurses.h>
#include <iostream>
#include <string>
#include <time.h>
#include <unistd.h>

Window::Window()
{
    char c = '*'; //for borders

    initscr(); //init
    cbreak(); //one char at a time
    noecho(); // suppress the automatic echoing of typed characters
    getmaxyx(stdscr, _height, _width); //get the size od the win
    _w = newwin(_height, _width, 0, 0); //separate window
    refresh();
    wtimeout(_w, 0);
    box(_w, (int)c, (int)c);
    wrefresh(_w);
}

Window::~Window()
{
    endwin();
    return ;
}

int Window::getWidth()
{ 
    return _width; 
}

int Window::getHeight()          
{ 
    return _height; 
}

WINDOW *Window::getWin()
{ 
    return _w; 
}
