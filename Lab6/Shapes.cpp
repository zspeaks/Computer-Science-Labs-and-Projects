//
// Created by Zach on 11/7/2020.
//

#include <iostream>
#include "Shapes.h"

Shape::~Shape(){

}


void Shape2D::ShowArea() const {
    std::cout << "The area of the " << GetName2D() << " is: " << Area() << std::endl;
}

bool Shape2D::operator>(const Shape2D &rhs) const {
    if (this->Area() > rhs.Area()){
        return true;
    }
    return false;
}

bool Shape2D::operator<(const Shape2D &rhs) const {
    if (this->Area() < rhs.Area()){
        return true;
    }
    return false;
}

bool Shape2D::operator==(const Shape2D &rhs) const {
    if (this->Area() == rhs.Area()){
        return true;
    }
    return false;
}

void Shape3D::ShowVolume() const {
    std::cout << "The volume of the " << GetName3D() << " is: " << Volume() << std::endl;
}

bool Shape3D::operator>(const Shape3D &rhs) const {
    if (this->Volume() > rhs.Volume()){
        return true;
    }
    return false;
}
bool Shape3D::operator<(const Shape3D &rhs) const {
    if (this->Volume() < rhs.Volume()){
        return true;
    }
    return false;
}

bool Shape3D::operator==(const Shape3D &rhs) const {
    if (this->Volume() == rhs.Volume()){
        return true;
    }
    return false;
}

Square::Square() {
    length = 0;
}

Square::Square(float sideLength) {
    length = sideLength;
}
void Square::Scale(float scaleFactor) {
    length = length*scaleFactor;
}
void Square::Display() const {
    std::cout << "The area of the " << GetName2D() << " is : " << Area() <<std::endl;
    std::cout << "Length of a side: " << length << std::endl;
}
float Square::Area() const {
    return length*length;
}
std::string Square::GetName2D() const {
    return "Square";
}

Triangle::Triangle() {
    base = 0;
    height = 0;
}

Triangle::Triangle(float b, float h) {
    height = h;
    base = b;
}
void Triangle::Scale(float scaleFactor) {
    height = height*scaleFactor;
    base = base * scaleFactor;
}
void Triangle::Display() const {
    std::cout << "The area of the " << GetName2D() << " is : " << Area() <<std::endl;
    std::cout << "Base: " << base << std::endl;
    std::cout << "Height: " << height << std::endl;
}
float Triangle::Area() const {
    return (base*height/2);
}
std::string Triangle::GetName2D() const {
    return "Triangle";
}

Circle::Circle() {
    radius =0;
}

Circle::Circle(float r) {
    radius = r;
}
void Circle::Scale(float scaleFactor) {
    radius = radius * scaleFactor;
}
void Circle::Display() const {
    std::cout << "The area of the " << GetName2D() << " is : " << Area() <<std::endl;
    std::cout << "Radius: " << radius << std::endl;
}
float Circle::Area() const {
    return 3.14159f * radius * radius;
}
std::string Circle::GetName2D() const {
    return "Circle";
}

TriangularPyramid::TriangularPyramid() : Triangle() {
    length = 0;
}

TriangularPyramid::TriangularPyramid(float Height, float Base, float BaseHeight) : Triangle(Base, BaseHeight) {
    length = Height;
}
void TriangularPyramid::Scale(float scaleFactor) {
    length = length * scaleFactor;
    Triangle::Scale(scaleFactor);
}
void TriangularPyramid::Display() const {
    std::cout << "The volume of the " << GetName3D() << " is : " << Volume() <<std::endl;
    std::cout << "The height is: " << length  <<std::endl;
    Triangle::Display();

}
float TriangularPyramid::Volume() const {
    return length / 3 * Triangle::Area();
}
std::string TriangularPyramid::GetName3D() const {
    return "Triangular Pyramid";
}

Cylinder::Cylinder() {
    height = 0;

}

Cylinder::Cylinder(float Height, float Radius) : Circle(Radius) {
    height = Height;
}
void Cylinder::Scale(float scaleFactor) {
    height = height *scaleFactor;
    Circle::Scale(scaleFactor);
}
void Cylinder::Display() const {
    std::cout << "The volume of the " << GetName3D() << " is : " << Volume() <<std::endl;
    std::cout << "The height is: " << height  << std::endl;
    Circle::Display();
}
float Cylinder::Volume() const {
    return height * Circle::Area();
}
std::string Cylinder::GetName3D() const {
    return "Cylinder";
}

Sphere::Sphere() : Circle() {
    radius = 0;
}

Sphere::Sphere(float r) : Circle(r) {
    radius = r;
}
void Sphere::Scale(float scaleFactor) {
    radius = radius *scaleFactor;
    Circle::Scale(scaleFactor);
}
void Sphere::Display() const {
    std::cout << "The volume of the " << GetName3D() << " is : " << Volume() <<std::endl;
    Circle::Display();
}
float Sphere::Volume() const {
    return 4.0f / 3 * 3.14159f * radius * radius* radius;
}
std::string Sphere::GetName3D() const {
    return "Sphere";
}
