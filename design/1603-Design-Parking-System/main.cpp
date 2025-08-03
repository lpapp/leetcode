#include <array>
#include <iostream>

using namespace std;

class ParkingSystem {
	array<int, 3> numberOfSlots; 
public:
    ParkingSystem(int big, int medium, int small) : numberOfSlots{big, medium, small} { }
    
    bool addCar(int carType) {
        const int parkingSpaceIndex = carType - 1;
    	if (!numberOfSlots[parkingSpaceIndex]) return false;
        --numberOfSlots[parkingSpaceIndex];
        return true;
    }
};

int main()
{
	ParkingSystem parkingSystem(1, 1, 0);
	cout << parkingSystem.addCar(1) << endl;
	cout << parkingSystem.addCar(2) << endl;
	cout << parkingSystem.addCar(3) << endl;
	cout << parkingSystem.addCar(1) << endl;
	return 0;
}
