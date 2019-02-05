#ifndef SUMMARIES_H
#define SUMMARIES_H
#include <QVector>
#include <QString>

class summaries
{
public:
    summaries(QString avgs,QString closed,QString highs,QString lows,QString opens,QString vol);
    QString getAvg(){return avg;}
    QString getClose(){return close;}
    QString getHigh(){return high;}
    QString getLow(){return low;}
    QString getOpen(){return open;}
    QString getVolume(){return volume;}

private:
    QString avg;
    QString close;
    QString high;
    QString low;
    QString open;
    QString volume;

};

#endif
