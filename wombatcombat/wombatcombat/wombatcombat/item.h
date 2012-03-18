#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <sstream>
#include "Player.h"

using namespace std;

class Item
{
    public:
        Item(int id, char *name, int goldValue);

        virtual string infoString();
        virtual void infoPrint();

        virtual void use(Player* player);

    private:
        //Atrributs
        int id; //einzigartige id für das jeweilige objekt.
        char *name; //name des items.
        int goldValue; //gibt an wie viel "Gold" oder "Geld" das item wert ist.
};

#endif // ITEM_H
