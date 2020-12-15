#include "fridge.h"
#include "food.h"


int main()
{
    Fridge myFridge("Davy Jones' Locker", "Sam'smug");
    Food apple("apple", "fruit", 52, 7, 10.4, 2);
    Food anime("anime", "thing", 99, 99, 99, 99);
    myFridge.openFridge();
    myFridge.addFood(apple);
    myFridge.addFood(anime);
    myFridge.listFood();
    myFridge.eatFood("apple", 50);
}