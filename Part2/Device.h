#pragma once 
#include <array> 
#include <iostream> 
#include <vector>
#define PI 3.14159265358979323846 
class Shape
{
public:
    Shape(double density = 1.1) : density(density){}
    virtual ~Shape(){}
    virtual double getVolume() const = 0;
    virtual double GetSurface() const = 0;
    double GetMass() const {return density * getVolume();}
    //virtual void print(std::ostream& out) const = 0;
    virtual Shape* Clone() const = 0;
private:
    double density;

};

inline std::ostream& operator << (std::ostream& out, const Shape& shape){
    //shape.print(out);
    return out;
}
 


 
class Cube:public Shape { 
public: 
    Cube(double length = 0, double width = 0, double height = 0) : 
        m_length(length), m_width(width), m_height(height)  
    { 
        
    } 
 
    double getVolume() const { return m_length * m_width * m_height; }
    double GetSurface() const override 
    { 
        return 2*(m_length * m_width + m_width * m_height + m_height * m_length);
    }
    Cube* Clone() const override {return new Cube(*this);}

    std::array<double, 3> getDimensions() const { 
        return { m_length, m_width, m_height }; 
    } 
 
    void setDimensions(double length, double width, double height) { 
        m_length = length; 
        m_width = width; 
        m_height = height; 
        
    } 
 
    void setLength(double length) { 
        m_length = length; 
        
    } 
 
    void setWidth(double width) { 
        m_width = width; 
        
    } 
 
    void setHeight(double height) { 
        m_height = height; 
        
    } 
 
    double getLength() const { return m_length; } 
    double getWidth() const { return m_width; } 
    double getHeight() const { return m_height; } 
 
private: 
    
 
    double m_length, m_width, m_height; 
}; 
 
std::ostream& operator<< (std::ostream& out, const Cube& cube) { 
    out << "Cube(" << cube.getLength() << ", " << cube.getWidth() << ", " << cube.getHeight() << ")"; 
    return out; 
} 
 
class Sphere : public Shape { 
public: 
    Sphere(double radius = 0) : m_radius(radius) { 
        calculateVolume(); 
    } 
 
    double getRadius() const { return m_radius; } 
    double getVolume() const { return m_volume; } 
    
    double GetSurface() const override
    {
        return 4* PI * m_radius *m_radius;
    }
    void setRadius(double radius) { 
        m_radius = radius; 
        calculateVolume(); 
    } 

    Sphere* Clone() const override {return new Sphere(*this);}
    
 
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
 
class Cylinder : public Shape { 
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
    Cylinder* Clone() const override {return new Cylinder(*this);}
 
    void setRadius(double radius) { 
        m_radius = radius; 
        calculateVolume(); 
    } 
 
     
    double getVolume() const { return m_volume; }

    double GetSurface() const override
    {
        return  (2* PI * m_radius * m_radius) + (2 * PI * m_radius * m_height );
    }
 
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
 
class Pyramid : public Shape { 
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

    double GetSurface() const override
    {
        double slantHeight = std::sqrt((m_baseWidth / 2) * (m_baseWidth / 2) + m_height * m_height);
        return m_baseWidth * m_baseWidth + 2 * m_baseWidth * slantHeight;


    }
    Pyramid* Clone() const override {return new Pyramid(*this);}
 
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
// ANSI escape codes for colors

class Device
{
public:
    Device* Clone() {
        Device* clone = new Device(m_Name);
        for (const auto& shape : m_Shape)
            clone->m_Shape.push_back(shape->Clone());
        for (const auto& subDevice : m_Devices)
            clone->m_Devices.push_back(subDevice->Clone());
        return clone;
    }

    Device(const std::string& name = "no name") : m_Name(name) {}
    void AddShape(const Shape& shape)
    {

        m_Shape.push_back(shape.Clone());

    }

    void AddsubDevice( Device& subDevice)
    {
        m_Devices.push_back(subDevice.Clone());
    }

    ~Device()
    {
        for (auto shape : m_Shape)
            delete shape;
        for (auto subDevice : m_Devices)
            delete subDevice;
    }

    double GetVolume() const
    {
        double volume = 0.0;
        for (const auto& shape : m_Shape)
            volume += shape->getVolume();

        for (const auto& subDevice : m_Devices)
            volume += subDevice->GetVolume();
        return volume;
    }
    double GetSurfaceArea() const
    {
        double surfaceArea = 0.0;
        for (const auto& shape : m_Shape)
            surfaceArea += shape->GetSurface();
        for (const auto& subDevice : m_Devices)
            surfaceArea += subDevice->GetSurfaceArea();
        return surfaceArea;
    }

    double GetMass() const
    {
        double mass = 0.0;
        for (const auto& shape : m_Shape)
            mass += shape->GetMass();
        for (const auto& subDevice : m_Devices)
            mass += subDevice->GetMass();
        return mass;
    }



    
private:
    std::vector<Shape*> m_Shape;
    std::vector<Device*> m_Devices;
    std::string m_Name;


};