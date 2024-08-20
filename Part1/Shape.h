#pragma once 
#include <array> 
#include <iostream> 
 
#define PI 3.14159265358979323846 
class Shape
{
public:
    Shape(){}
    ~Shape(){}
    virtual double getVolume() { return -1; }
private:

};


 
class Cube:public Shape { 
public: 
    Cube(double length = 0, double width = 0, double height = 0) : 
        m_length(length), m_width(width), m_height(height)  
    { 
        calculateVolume(); 
    } 
 
    double getVolume() const { return m_volume; } 
     
    std::array<double, 3> getDimensions() const { 
        return { m_length, m_width, m_height }; 
    } 
 
    void setDimensions(double length, double width, double height) { 
        m_length = length; 
        m_width = width; 
        m_height = height; 
        calculateVolume(); 
    } 
 
    void setLength(double length) { 
        m_length = length; 
        calculateVolume(); 
    } 
 
    void setWidth(double width) { 
        m_width = width; 
        calculateVolume(); 
    } 
 
    void setHeight(double height) { 
        m_height = height; 
        calculateVolume(); 
    } 
 
    double getLength() const { return m_length; } 
    double getWidth() const { return m_width; } 
    double getHeight() const { return m_height; } 
 
private: 
    void calculateVolume() { 
        m_volume = m_length * m_width * m_height; 
    } 
 
    double m_length, m_width, m_height, m_volume; 
}; 
 
std::ostream& operator<< (std::ostream& out, const Cube& cube) { 
    out << "Cube(" << cube.getLength() << ", " << cube.getWidth() << ", " << cube.getHeight() << ")"; 
    return out; 
} 
 
class Sphere { 
public: 
    Sphere(double radius = 0) : m_radius(radius) { 
        calculateVolume(); 
    } 
 
    double getRadius() const { return m_radius; } 
    double getVolume() const { return m_volume; } 
 
    void setRadius(double radius) { 
        m_radius = radius; 
        calculateVolume(); 
    } 
 
private: 
    void calculateVolume() { 
        m_volume = (4.0 / 3.0) * PI * m_radius * m_radius * m_radius; 
    } 
 
    double m_radius, m_volume; 
}; 
 
std::ostream& operator<< (std::ostream& out, const Sphere& sphere) { 
    out << "Sphere(" << sphere.getRadius() << ")"; 
    return out; 
} 
 
class Cylinder { 
public: 
    Cylinder(double height = 0, double radius = 0) : 
        m_height(height), m_radius(radius)  
    { 
        calculateVolume(); 
    } 
 
    double getHeight() const { return m_height; } 
    double getRadius() const { return m_radius; } 
 
    void setHeight(double height) { 
        m_height = height; 
        calculateVolume(); 
    } 
 
    void setRadius(double radius) { 
        m_radius = radius; 
        calculateVolume(); 
    } 
 
    double getVolume() const { return m_volume; } 
 
private: 
    void calculateVolume() { 
        m_volume = PI * m_radius * m_radius * m_height; 
    } 
 
    double m_height, m_radius, m_volume; 
}; 
 
std::ostream& operator<< (std::ostream& out, const Cylinder& cylinder) { 
    out << "Cylinder(" << cylinder.getHeight() << ", " << cylinder.getRadius() << ")"; 
    return out; 
} 
 
class Pyramid { 
public: 
    Pyramid(double height = 0, double baseWidth = 0) : 
        m_height(height), m_baseWidth(baseWidth)  
    { 
        calculateVolume(); 
    } 
 
    double getHeight() const { return m_height; } 
    double getBaseWidth() const { return m_baseWidth; } 
 
    void setHeight(double height) { 
        m_height = height; 
        calculateVolume(); 
    } 
 
    void setBaseWidth(double baseWidth) { 
        m_baseWidth = baseWidth; 
        calculateVolume(); 
    } 
 
    double getVolume() const { return m_volume; } 
 
private: 
    void calculateVolume() { 
        m_volume = (m_baseWidth * m_baseWidth * m_height) / 3.0; 
    } 
 
    double m_height, m_baseWidth, m_volume; 
}; 
 
std::ostream& operator<< (std::ostream& out, const Pyramid& pyramid) { 
    out << "Pyramid(" << pyramid.getHeight() << ", " << pyramid.getBaseWidth() << ")"; 
    return out; 
}