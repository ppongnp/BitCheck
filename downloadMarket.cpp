#include "downloadMarket.h"
#include "coin.h"
downloadMarket::downloadMarket(QObject *parent,DownloaderOutputInterface* output) : QObject(parent)
{
    connect(newDownload,SIGNAL(finished(QNetworkReply*)),this,SLOT(ReadyRead(QNetworkReply*)));
    this->output = output;
}

void downloadMarket::MakeRequest(QString request)
{
    newDownload->get(QNetworkRequest(QUrl(request)));
}

void downloadMarket::ReadyRead(QNetworkReply *reply)
{
    QByteArray myData = reply->readAll();
    QJsonDocument Data = QJsonDocument::fromJson(myData);
    QJsonObject jsonObject = Data.object();
    this->output->onDataReceived(jsonObject);
    reply->deleteLater();


}


