#ifndef DOWNLOADER_H
#define DOWNLOADER_H
#include <QString>
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include "downloaderoutputinterface.h"
#include <iostream>
class downloadMarket : public QObject
{
    Q_OBJECT
public:
    explicit downloadMarket(QObject *parent = nullptr,DownloaderOutputInterface* output= nullptr);
    void MakeRequest(QString request);
    DownloaderOutputInterface *output;
public slots:
    void ReadyRead(QNetworkReply *reply);
private:
    QNetworkAccessManager *newDownload = new QNetworkAccessManager(this);


};

#endif // DOWNLOADER_H
