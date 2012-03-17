#ifndef ITEM_H
#define ITEM_H

#include <iostream>
using namespace std;

class Item
{
    public:
        //Methods
        Item(int id, int name, int goldValue);

        //gibt an wie viel "Gold" oder "Geld" das item wert ist.
        void devInfoPrint();

    private:
        //Atrributs
        int id; //einzigartige id für das jeweilige objekt.
        int name; //name des items.
        int goldValue; //gibt an wie viel "Gold" oder "Geld" das item wert ist.
};

#endif // ITEM_H
