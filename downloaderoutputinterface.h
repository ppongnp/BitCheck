#ifndef DOWNLOADEROUTPUTINTERFACE_H
#define DOWNLOADEROUTPUTINTERFACE_H
#include <QString>
#include <QJsonObject>

class DownloaderOutputInterface
{
public:
    virtual void onDataReceived(QJsonObject data) = 0;
    virtual void onDataReceived2(QJsonObject data) = 0;

};

#endif // DOWNLOADEROUTPUTINTERFACE_H
