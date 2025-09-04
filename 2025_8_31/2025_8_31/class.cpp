#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

class ParkingSystem {
private:
    int cb = 0;
    int cm = 0;
    int cs = 0;
public:
    ParkingSystem(int big, int medium, int small) {
        cb = big;
        cm = medium;
        cs = small;
    }

    bool addCar(int carType) {
        if (carType == 1)
        {
            if (cb == 0)return false;
            cb--;
            return true;
        }
        if (carType == 2)
        {
            if (cm == 0)return false;
            cm--;
            return true;
        }
        if (carType == 3)
        {
            if (cs == 0)return false;
            cs--;
            return true;
        }
        return false;
    }
};
