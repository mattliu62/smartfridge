#include <string>
#include "food.h"
#include <vector>

using namespace std;

class Fridge {
    public:
        Fridge();
        Fridge(std::string arg_name, std::string arg_brand);
        void openFridge();
        void closeFridge();
        void adjustTemp(float arg_temp);
        void checkInfo();
        float checkTemp();

        int CountFood();
        int listFood();
        void addFood(Food arg_Food); //food object as parameter
        void purgeFood(Food arg_Food);
        void removeExpired();

        int calorieSum();

        
    private:
        float temp;
        std::string name;
        std::string brand;
        bool open_close;
        std::vector<Food *> * foods;
        int foodCounter();

};


