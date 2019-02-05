#ifndef FIRSTPAGE_H
#define FIRSTPAGE_H
#include "coin.h"
#include "summaries.h"
#include <QMainWindow>
#include <QJsonDocument>
#include <QJsonArray>
#include <Qdebug>
#include <QJsonValue>
#include <QJsonObject>
#include "downloadMarket.h"
#include <QVector>
#include <QMessageBox>
#include "downloadsummaries.h"
#include "downloaderoutputinterface.h"
namespace Ui {
class firstPage;
}

class firstPage : public QMainWindow,public DownloaderOutputInterface
{
    Q_OBJECT

public:
    explicit firstPage(QWidget *parent = 0);
    ~firstPage();
    void onDataReceived(QJsonObject data);
    void onDataReceived2(QJsonObject data);
    void updateWidget(int size);
    QString scientificConvert (QString number);
    QVector<coin*> coins;
    QVector<summaries*> summary;

private slots:
    void on_listWidget_clicked(const QModelIndex &index);

private:
    Ui::firstPage *ui;
    downloadMarket *api1;
    downloadSummaries *api2;

};

#endif // FIRSTPAGE_H
