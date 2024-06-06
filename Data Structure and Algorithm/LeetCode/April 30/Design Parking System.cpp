class ParkingSystem{
    int Abig, Amedium, Asmall;
    public:
    ParkingSystem(int big, int medium, int small){
        Abig = big;
        Amedium = medium;
        Asmall = small;
    }

    bool addCar(int carType){
        if(carType == 1){
            if(Abig == 0){
                return false;
            }
            else{
                Abig--;
                return true;
            }
        }
        else if(carType == 2){
            if(Amedium == 0){
                return false;
            }
            else{
                Amedium--;
                return true;
            }
        }
        else if(carType == 3){
            if(Asmall == 0){
                return false;
            }
            else{
                Asmall--;
                return true;
            }
        }
        else{
            return false;
        }
    }
};