/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:30:55 by vzurera-          #+#    #+#             */
/*   Updated: 2024/07/12 18:09:34 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main() {

    //  TRIANGLE 1
    Point a(0, 0);                  //  First point of the triangle
    Point b(5, 5);                  //  First point of the triangle
    Point c(0, 10);                 //  First point of the triangle

    Point p1(0, 10);                //  Point inside the triangle
	Point p2(1, 200);               //  Point inside the triangle

    //  TRIANGLE 2
	Point d(1367.893f, 2458.912f);  //  First point of the triangle
	Point e(10.125f, 4691.234f);    //  First point of the triangle
	Point f(5682.347f, 6913.456f);  //  First point of the triangle

	Point q1(0.569f, 8345.678f);    //  Point inside the triangle
	Point q2(2689.125f, 4691.234f); //  Point inside the triangle
    
    //  TRIANGLE 3
    Point g(0.00f, 0.00f);          //  First point of the triangle
    Point h(84.84f, 120.00f);       //  First point of the triangle
    Point i(0.00f, 240.00f);        //  First point of the triangle
    
	Point r1(0.00f, 42.42f);        //  Point inside the triangle
    Point r2(42.42f, 60.10f);       //  Point inside the triangle

	std::cout << std::endl << " ======================================" << std::endl << std::endl
			  << BR " Although the " G "subject" BR " mentions the name " Y "BSP" BR ", at no point is it required to use " Y "Binary Space" << std::endl
              << " Partitioning" BR " for this project, which is complicated and beyond the scope of this exercise," << std::endl
              << " from my point of view." << std::endl << std::endl
              << " However, I have implemented two methods to solve the exercise, which requires determining if" << std::endl
              << " a point is inside a triangle, defined by 3 points." << std::endl << std::endl
              << " The methods used are " Y "Area Method" BR " and " Y "Barycentric Coordinate" BR "." << std::endl << std::endl
              << Y " Area Method" BR " involves calculating the areas of sub-triangles formed with the point in" << std::endl
              << " question and comparing them with the area of the original triangle." << std::endl << std::endl
              << Y " Barycentric Coordinates" BR " determines whether a point is inside a triangle by expressing the point" << std::endl
              << " as a weighted sum of the triangle's vertices." << std::endl << std::endl
              << " Both methods are effective, but the " Y "Barycentric Coordinates" BR " provide additional information" << std::endl
              << " about the relative position of the point within the triangle." NC << std::endl << std::endl;
    {
    	std::cout <<   " ======================================" << std::endl
				  << G "                BSP AREA               " NC << std::endl
				  <<   " ======================================" << std::endl << std::endl;

        std::cout << G " Calculate if a " Y "point" G " is inside a triangle using the " Y "Area Method" G " method:" << std::endl << std::endl;

        std::cout << std::endl << Y "[TRIANGLE 1]	" B << a << ", " << b << ", " << c << std::endl;
        std::cout << C "		" << p1 << (bspArea(a, b, c, p1) ? G "\t\t\t\tis inside the triangle" : RD "\t\t\t\tis outside the triangle") << NC << std::endl;
        std::cout << C "		" << p2 << (bspArea(a, b, c, p2) ? G "\t\t\t\tis inside the triangle" : RD "\t\t\t\tis outside the triangle") << NC << std::endl << std::endl;

        std::cout << std::endl << Y "[TRIANGLE 2]	" B << d << ", " << e << ", " << f << std::endl;
        std::cout << C "		" << q1 << (bspArea(d, e, f, q1) ? G "\t\tis inside the triangle" : RD "\t\tis outside the triangle") << NC << std::endl;
        std::cout << C "		" << q2 << (bspArea(d, e, f, q2) ? G "\t\tis inside the triangle" : RD "\t\tis outside the triangle") << NC << std::endl << std::endl;

        std::cout << std::endl << Y "[TRIANGLE 3]	" B << g << ", " << h << ", " << i << std::endl;
        std::cout << C "		" << r1 << (bspArea(g, h, i, r1) ? G "\t\t\tis inside the triangle" : RD "\t\t\tis outside the triangle") << NC << std::endl;
        std::cout << C "		" << r2 << (bspArea(g, h, i, r2) ? G "\t\tis inside the triangle" : RD "\t\tis outside the triangle") << NC << std::endl << std::endl << std::endl;
    } {        
    	std::cout <<   " ======================================" << std::endl
				  << G "      BSP BARYCENTRIC COORDINATES      " NC << std::endl
				  <<   " ======================================" << std::endl << std::endl;

        std::cout << G " Calculate if a " Y "point" G " is inside a triangle using the " Y "Barycentric Coordinates" G " method:" << std::endl << std::endl;

        std::cout << std::endl << Y "[TRIANGLE 1]	" B << a << ", " << b << ", " << c << std::endl;
        std::cout << C "		" << p1 << (bsp(a, b, c, p1) ? G "\t\t\t\tis inside the triangle" : RD "\t\t\t\tis outside the triangle") << NC << std::endl;
        std::cout << C "		" << p2 << (bsp(a, b, c, p2) ? G "\t\t\t\tis inside the triangle" : RD "\t\t\t\tis outside the triangle") << NC << std::endl << std::endl;


        std::cout << std::endl << Y "[TRIANGLE 2]	" B << d << ", " << e << ", " << f << std::endl;
        std::cout << C "		" << q1 << (bsp(d, e, f, q1) ? G "\t\tis inside the triangle" : RD "\t\tis outside the triangle") << NC << std::endl;
        std::cout << C "		" << q2 << (bsp(d, e, f, q2) ? G "\t\tis inside the triangle" : RD "\t\t outside the triangle") << NC << std::endl << std::endl;

        std::cout << std::endl << Y "[TRIANGLE 3]	" B << g << ", " << h << ", " << i << std::endl;
        std::cout << C "		" << r1 << (bsp(g, h, i, r1) ? G "\t\t\tis inside the triangle" : RD "\t\t\tis outside the triangle") << NC << std::endl;
        std::cout << C "		" << r2 << (bsp(g, h, i, r2) ? G "\t\tis inside the triangle" : RD "\t\tis outside the triangle") << NC << std::endl;
    }
	std::cout << std::endl << " =======================================" << std::endl << std::endl;
}
