#ifndef _NUTRITION_H_
#define _NUTRITION_H_

#include <string>
#include <iostream>
#include <json/json.h>
using namespace std;

class Nutrition {
    private:
        int calories; // kCal
        int protein; // g
        int carbs; // g
        int fat; // g
        int sodium; // mg
    
    public:
        Nutrition();
        Nutrition(int cal, int protein, int carbs, int fat, int sodium);
        ~Nutrition();
        virtual int getCalories();
        virtual int getProtein();
        virtual int getCarbs();
        virtual int getFat();
        virtual int getSodium();
};
#endif