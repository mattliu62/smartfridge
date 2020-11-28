#include "fridge.h"
#include "food.h"


int main(){
    Fridge myFridge("Bernie Sanders", "Socialism");
    myFridge.openFridge();
    myFridge.checkTemp();
    myFridge.setTemp(90);
    myFridge.checkTemp();
    myFridge.closeFridge();
    myFridge.checkTemp();
    myFridge.checkInfo();
}