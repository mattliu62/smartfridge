#include <string>
//#include "food.h"
#include <vector>

using namespace std;

//REPLACE ALL STD::STRING FOOD WITH OBJECT

class Fridge {
    public:
        Fridge();
        Fridge(std::string arg_name, std::string arg_brand);

        //basic fridge operations
        void openFridge();
        void closeFridge();
        void setTemp(float arg_temp);
        void checkStatus();


        //food operations
        int listFood();
        void addFood(std::string arg_Food); //food object as parameter
        void purgeFood(std::string arg_Food);
        void removeExpired();

       // int calorieSum();

        
    private:
        float temp;
        std::string name;
        std::string brand;
        bool open_close;
        std::vector<std::string>foods; //maximum capacity is 20 for now
        int foodCounter();

};


