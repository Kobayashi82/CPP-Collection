/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:14:46 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 17:07:51 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//  AREA METHOD

static float ft_abs(float value) { if (value < 0) { value = -value; } return (value); }                          //  Return the absolute value of a float.

static float getArea(Point p1, Point p2, Point p3) {                                                        //  Calculate the area of a triangle. (x1(y2 − y3) + x2(y3 − y1) + x3(y1 − y2)) / 2
    float Result;
    Result = p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat())
            + p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat())
            + p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat());
    return (ft_abs(Result / 2.0));
}

bool bspArea(Point const a, Point const b, Point const c, Point const point) {
    float A = getArea(a, b, c);                                                                             //  Area of the triangle.
    float A1 = getArea(point, b, c);                                                                        //  Areas of the three triangles formed by point.
    float A2 = getArea(a, point, c);
    float A3 = getArea(a, b, point);

    return ((A1 == 0 || A2 == 0 || A3 == 0) || ft_abs(A - (A1 + A2 + A3)) <= 0.000001);                     //  Check if the sum of the areas is equal to the area of the triangle within a tolerance.
}

//  BARYCENTRIC COORDINATES

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    //  Calculate vectors from point a to points b, c, and point
    Point v0(c.getX() - a.getX(), c.getY() - a.getY());                                                     //  Vector from a to c.
    Point v1(b.getX() - a.getX(), b.getY() - a.getY());                                                     //  Vector from a to b.
    Point v2(point.getX() - a.getX(), point.getY() - a.getY());                                             //  Vector from a to point.

                                                                                                            //  Calculate dot products, this help to understand the spatial relationship between the vectors.

    float d0 = v0.getX().toFloat() * v0.getX().toFloat() + v0.getY().toFloat() * v0.getY().toFloat();       //  d0: This is the dot product of v0 with itself. This gives us the square of the length of v0. It is calculated by multiplying the x and y components of v0 by themselves and adding them together.
    float d1 = v0.getX().toFloat() * v1.getX().toFloat() + v0.getY().toFloat() * v1.getY().toFloat();       //  d1: This is the dot product between v0 and v1. It indicates how parallel or aligned these two vectors are with each other.
    float d2 = v0.getX().toFloat() * v2.getX().toFloat() + v0.getY().toFloat() * v2.getY().toFloat();       //  d2: This is the dot product between v0 and v2. Similar to d1, but comparing v0 with v2.
    float d11 = v1.getX().toFloat() * v1.getX().toFloat() + v1.getY().toFloat() * v1.getY().toFloat();      //  d11: This is the dot product of v1 with itself, giving us the square of the length of v1.
    float d12 = v1.getX().toFloat() * v2.getX().toFloat() + v1.getY().toFloat() * v2.getY().toFloat();      //  d12: This is the dot product between v1 and v2, indicating the alignment or parallelism between v1 and v2.

    //  Calculate barycentric coordinates
    float normalize = 1 / (d0 * d11 - d1 * d1);                                                             //  normalize: This is the inverse of the common denominator in the formulas for calculating barycentric coordinates.
                                                                                                            //  This value is crucial because it is used to normalize the calculations, ensuring that the barycentric coordinates sum to 1.
                                                                                                            //  It is calculated using the previously calculated dot products.

    float u = (d11 * d2 - d1 * d12) * normalize;                                                            //  u and v: These are the barycentric coordinates themselves. These values tell us how the point v2 (our point) is positioned with respect
    float v = (d0 * d12 - d1 * d2) * normalize;                                                             //  to the triangle formed by a, b, and c. They are calculated using a combination of the dot products and the normalize.
                                                                                                            //  the names u and v are variable names used by convention to calculate barycentric coordinates.
                                                                                                            
    return (u >= 0) && (v >= 0) && (u + v <= 1);                                                            //  A point is inside the triangle if (u and v are >= 0) and (u + v <= 1).
}
