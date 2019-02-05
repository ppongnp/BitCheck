#include "downloadsummaries.h"
#include "coin.h"
#include "firstpage.h"
downloadSummaries::downloadSummaries(QObject *parent,DownloaderOutputInterface* output) : QObject(parent)
{
    connect(newDownload,SIGNAL(finished(QNetworkReply*)),this,SLOT(ReadyRead(QNetworkReply*)));
    this->output = output;
}

void downloadSummaries::MakeRequest(QString request)
{
    newDownload->get(QNetworkRequest(QUrl(request)));
    
}

void downloadSummaries::ReadyRead(QNetworkReply *reply)
{
    QByteArray myData = reply->readAll();
    QJsonDocument Data = QJsonDocument::fromJson(myData);
    QJsonObject jsonObject = Data.object();
    this->output->onDataReceived2(jsonObject);
    reply->deleteLater();

}
