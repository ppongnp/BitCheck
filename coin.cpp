#include "coin.h"


coin::coin(int pairing, QString fcurren, QString Securren, double vol, double bid, double ask, double changes, double last)
{
    pairing_id = pairing;
    firstCurrency = fcurren;
    secondCurrency = Securren;
    volume = vol;
    bidPrice = bid;
    askPrice = ask;
    change = changes;
    lastPrice = last;
}
