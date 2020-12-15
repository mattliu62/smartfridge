using namespace std;
#include <string>
#include "fridge.h"
#include <vector>
#include <iostream>

class Food {
    public:
        Food(std::string arg_name, std::string arg_type, int arg_calories,
        int arg_shelf_Life, int arg_sugar, int arg_sodium, int remainder);
        int printNutrition();
        int getCalories();
        int getShelfLife();
        int remainder();
        void getFoodInfo();
    //    void eatFood(Food &item);

    private:
        std::string brand;
        std::string name;
        std::string type;
        int calories;
        int shelf_Life;
        int sugar;
        int sodium;
        void setCalories(int percent);

}
