#include "equiptable.h"

Equiptable::Equiptable(int id, int name, int goldValue, int welcheHand) : Item(id, name, goldValue)
{
    this->welcheHand=welcheHand;
}
