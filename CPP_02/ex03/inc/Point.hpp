/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:43 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 17:59:40 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Fixed.hpp"

class Point {

private:

	const Fixed	_x;
	const Fixed	_y;

	Point & operator=(const Point & rhs);		//	Can't change const variables, so it is private
	
public:

	//	Constructors
	
	Point();
	Point(const float x, const float y);
	Point(const Fixed x, const Fixed y);
	Point(const Point & src);
	~Point();

	//	Functions

	Fixed	getX() const;
	Fixed	getY() const;
	
};

std::ostream & operator<<(std::ostream & os, const Point & rhs);

bool bsp(Point const a, Point const b, Point const c, Point const point);
bool bspArea(Point const a, Point const b, Point const c, Point const point);
