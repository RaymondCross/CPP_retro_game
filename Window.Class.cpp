/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.Class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:57:21 by valeriiamur       #+#    #+#             */
/*   Updated: 2019/10/27 05:24:00 by rcross           ###   ########.fr       */
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
    curs_set(0);
    _w = newwin(_height, _width, 0, 0); //separate window
    wtimeout(_w, 0);
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    box(_w, (int)c, (int)c);
    keypad(stdscr, TRUE);
    refresh();
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
