/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.Class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriiamuradian <valeriiamuradian@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:54:45 by valeriiamur       #+#    #+#             */
/*   Updated: 2019/10/26 15:46:08 by valeriiamur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_CLASS_HPP
# define WINDOW_CLASS_HPP

#include <ncurses.h>
#include <iostream>
#include <string>
#include <unistd.h>

class Window
{
    public:
    
        Window();
        ~Window();

        int getWidth();
        int getHeight();
        WINDOW *getWin();
    
    private:
        int _width;
        int _height;
        WINDOW *_w;
};

#endif