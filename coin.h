#ifndef COIN_H
#define COIN_H
#include <QString>
#include <QJsonDocument>
class coin
{
public:
    coin(int pairing,QString fcurren,QString Securren,double vol,double bid,double ask,double changes,double last);
    int getPairingId(){return pairing_id;}
    QString getFirstCurrency(){return firstCurrency;}
    QString getSecondCurrency(){return secondCurrency;}
    double getVolume(){return volume;}
    double getBids(){return bidPrice;}
    double getAsk(){return askPrice;}
    double getChange(){return change;}
    double getLastPrice(){return lastPrice;}

private:
    int pairing_id;
    QString firstCurrency;
    QString secondCurrency;
    double volume;
    double bidPrice;
    double askPrice;
    double change;
    double lastPrice;

};

#endif // COIN_H
