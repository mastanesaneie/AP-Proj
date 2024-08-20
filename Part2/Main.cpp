#include <iostream>
#include "DeviceNew.h"

int main() {
    Device d("Main Device");
    {
        Cube cube(4.5, 3.0, 2.1);
        Sphere sphere(5.1);
        Cylinder cylinder(3.0, 1.3);
        Pyramid pyramid(2.0, 0.5);

        //d.AddShape(cube);
        d.AddShape(sphere);
        d.AddShape(cylinder);
        d.AddShape(pyramid);

    }
    {
        Device subDevice("subDevice0");
        Cube smallCube(1.0, 1.0, 0.7);
        Sphere smallsphere(0.8);

        subDevice.AddShape(smallCube);
        subDevice.AddShape(smallsphere);
        d.AddsubDevice(subDevice);
    }
    {
        Device subDevice("subDevice1");
        d.AddsubDevice(subDevice);
    }
    std::cout << d.GetMass() << '\n';
    std::cout << d.GetSurfaceArea() << '\n';
    std::cout << d.GetVolume() << '\n';

    return 0;

}