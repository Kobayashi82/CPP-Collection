/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:51 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 18:00:04 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//	Constructors

Point::Point() : _x(Fixed(0)), _y(Fixed(0)) {}
Point::Point(const Fixed px, const Fixed py) : _x(px), _y(py) {}
Point::Point(const float px, const float py) : _x(Fixed(px)), _y(Fixed(py)) {}
Point::Point(const Point & src) : _x(src._x), _y(src._y) {}
Point::~Point() { }

//	Functions

Fixed Point::getX() const { return (_x); }
Fixed Point::getY() const { return (_y); }

// Overloads

Point & Point::operator=(const Point & rhs) { (void) rhs; return (*this); }				//	Can't change const variables, so do nothing here

std::ostream & operator<<(std::ostream & os, const Point & rhs) { os << "Point: (" << rhs.getX().toFloat() << ", " << rhs.getY().toFloat() << ")"; return (os); }
	