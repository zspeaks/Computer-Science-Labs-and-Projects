//
// Created by Zach on 11/7/2020.
//

#ifndef LAB6_SHAPES_H
#define LAB6_SHAPES_H
#include "string"

class Shape {
public:
    virtual void Scale(float scaleFactor) = 0;
    virtual void Display() const =0;
    virtual ~Shape() = 0;
};
class Shape2D: virtual public Shape{
public:
    virtual float Area() const = 0;
    void ShowArea() const;
    virtual std::string GetName2D() const =0;
    bool operator>(const Shape2D &rhs) const;
    bool operator<(const Shape2D &rhs) const;
    bool operator==(const Shape2D &rhs) const;
};
class Shape3D: virtual public Shape{
public:
    virtual float Volume() const =0;
    void ShowVolume() const;
    virtual std::string GetName3D() const =0;
    bool operator>(const Shape3D &rhs) const;
    bool operator<(const Shape3D &rhs) const;
    bool operator==(const Shape3D &rhs) const;
};
class Square :  public Shape2D{
private:
    float length;
public:
    Square();
    Square(float sideLength);
    void Display() const override;
    void Scale(float scaleFactor) override;
    float Area() const override;
    std::string  GetName2D() const override;
};
class Triangle :  public Shape2D{
private:
    float base;
    float height;
public:
    Triangle();
    Triangle(float b, float h);
    void Display() const override;
    void Scale(float scaleFactor) override;
    float Area() const override;
    std::string  GetName2D() const override;
};
class Circle :  public Shape2D{
private:
    float radius;
public:
    Circle();
    Circle(float r);
    void Display() const override;
    void Scale(float scaleFactor) override;
    float Area() const override;
    std::string  GetName2D() const override;
};
class TriangularPyramid: public Shape3D, private Triangle{
private:
    float length;
public:
    TriangularPyramid();
    TriangularPyramid(float Base, float BaseHeight, float Height);
    void Display() const override;
    void Scale(float scaleFactor) override;
    float Volume() const override;
    std::string  GetName3D() const override;
};
class Cylinder : public Shape3D, private Circle{
private:
    float height;
public:
    Cylinder();
    Cylinder(float Radius, float Height);
    void Display() const override;
    void Scale(float scaleFactor) override;
    float Volume() const override;
    std::string  GetName3D() const override;
};
class Sphere: public Shape3D, private Circle{
private:
    float radius;
public:
    Sphere();
    Sphere(float r);
    void Display() const override;
    void Scale(float scaleFactor) override;
    float Volume() const override;
    std::string  GetName3D() const override;
};


#endif //LAB6_SHAPES_H
