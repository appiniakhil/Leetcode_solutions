class ParkingSystem {
public:
    int bigCar,mediumCar,smallCar;
    ParkingSystem(int big, int medium, int small) {

       this->bigCar=big; 

       this->mediumCar=medium; 

       this->smallCar=small; 
    }
    
    bool addCar(int carType) {

        if(carType == 1)
        {
            if(bigCar > 0)
            {
                bigCar -= 1;

                return true;
            }
        }
        else if(carType == 2)
        {
            if(mediumCar > 0)
            {
                mediumCar -= 1;

                return true;
            }
        }
        else
        {
            if(smallCar > 0)
            {
                smallCar -= 1;

                return true;
            }
        }

        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
