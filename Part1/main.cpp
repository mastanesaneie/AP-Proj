#include <iostream>
#include <vector>
#include "Vector.h"
#include "VDP.h"
#include "Shape.h"
#include "Timer.h"
#include <ctime>
using namespace std;
#define SampleCount 128
#define ArrayCount 100


class largeOBJ
{
public:
    largeOBJ(int size=1)
        :data(size * 1024 * 1024)
    {
    };


private:
    std::vector<char> data;
};


int main()
{
    Vector<largeOBJ> vectorTest(ArrayCount);
    VDP<largeOBJ> VDPTest(ArrayCount);
    
    double sumOfInsertsVector = 0;
    double sumOfRemovesVector = 0;
    double sumOfInsertsVDP = 0;
    double sumOfRemovesVDP = 0;
    largeOBJ a(200);
    for (size_t i = 1; i <= SampleCount; i++)
    {
        
        Timer t;
        t.start();
        vectorTest.insert(a, 0);
        t.stop();
        sumOfInsertsVector += t.elapsedMilliseconds();

        t.start();
        vectorTest.remove(0);
        t.stop();
        sumOfRemovesVector += t.elapsedMilliseconds();

        t.start();
        VDPTest.insert(a, 0);
        t.stop();
        sumOfInsertsVDP += t.elapsedMilliseconds();

        t.start();
        VDPTest.remove(0);
        t.stop();
        sumOfRemovesVDP += t.elapsedMilliseconds();
        
    }
    

    cout << "single pointer clock(insert): " << sumOfInsertsVector/SampleCount << "ms" << endl;

    cout << "single pointer clock(Remove): " << sumOfRemovesVector/SampleCount << "ms" << endl;

    cout << "double pointer clock(insert): " << sumOfInsertsVDP / SampleCount << "ms" << endl;

    cout << "double pointer clock(Remove): " << sumOfRemovesVDP / SampleCount << "ms" << endl;


}