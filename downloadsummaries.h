#ifndef DOWNLOADSUMMARIES_H
#define DOWNLOADSUMMARIES_H
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include "downloaderoutputinterface.h"
#include <iostream>
#include <QObject>

class downloadSummaries : public QObject
{
    Q_OBJECT
public:
    explicit downloadSummaries(QObject *parent = nullptr,DownloaderOutputInterface* output= nullptr);
    void MakeRequest(QString request);
    DownloaderOutputInterface *output;
public slots:
    void ReadyRead(QNetworkReply *reply);
private:
    QNetworkAccessManager *newDownload = new QNetworkAccessManager(this);


};
#endif // DOWNLOADSUMMARIES_H
