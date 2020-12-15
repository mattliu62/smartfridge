#ifndef _FOOD_H_
#define _FOOD_H_

#include <string>
#include <iostream>
#include <json/json.h>
#include "nutrition.h"
using namespace std;

<<<<<<< HEAD
=======
//hi

class Nutrition {
    private:
        int calories; // kCal
        int protein; // g
        int carbs; // g
        int fat; // g
        int sodium; // mg
    
    public:
        virtual int getCalories();
        virtual int getProtein();
        virtual int getCarbs();
        virtual int getFat();
        virtual int getSodium();
};
>>>>>>> 576ec4051f5916378dfd176f00874c73afecacd2

class Food {
    private:
        std::string name;
        std::string category;
<<<<<<< HEAD
        Nutrition nutrition;
=======
        int nutrition;
>>>>>>> 576ec4051f5916378dfd176f00874c73afecacd2
        int expirationDate; // days
        float requiredTemp; // C
        float servings;

    public:
        Food();
        Food(std::string arg_name, std::string arg_category, 
             Json::Value arg_nutrition, int arg_expirationDate,
             float arg_requiredTemp, float arg_servings);
        ~Food();

        virtual std::string getName();
        virtual std::string getCategory();
        virtual std::string dumpNutrition();
        virtual int getExpiration();
        virtual float getTemperature();
        virtual float getServings();
};

#endif