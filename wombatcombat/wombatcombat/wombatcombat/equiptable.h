#include "item.h"

#ifndef EQUIPTABLE_H
#define EQUIPTABLE_H

class Equiptable : public Item
{
public:
    Equiptable(int id, int name, int goldValue, int welcheHand);

    void devInfoPrint()
    {
        Item::devInfoPrint();
        cout<<" welcheHand: "<<welcheHand;
    };

private:
    int welcheHand;
};

#endif // EQUIPTABLE_H
