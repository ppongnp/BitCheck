#include "firstpage.h"
#include "ui_firstpage.h"
#include "downloadMarket.h"
#include "downloadsummaries.h"
#include <QDebug>
#include <iostream>
#include <string>
firstPage::firstPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::firstPage)
{

    ui->setupUi(this);
    downloadMarket *api1 =  new downloadMarket(nullptr,this);
    this->api1 = api1;
    this->setWindowTitle("BITCHECK");
    this->api1->MakeRequest("https://bx.in.th/api/");
    downloadSummaries *api2 = new downloadSummaries(nullptr,this);
    this->api2 = api2;
    for(int i = 1; i < 32;i++){

        if(i == 9){
            i = 13;
        }
        if(i == 16){
            i = 17;
        }
        if(i == 18){
            i = 19;
        }
        this->api2->MakeRequest("https://bx.in.th/api/tradehistory/?pairing="+ QString::number(i) + "&date=2018-10-24");
    }
}

firstPage::~firstPage()
{
    delete ui;
}

void firstPage::onDataReceived(QJsonObject data){

    for(int i = 1 ; i < 32;i++){
        if(i == 9){
            i = 13;
        }
        if(i == 16){
            i = 17;
        }
        if(i == 18){
            i = 19;
        }
        QString s = QString::number(i);
        QJsonObject test = data.value(s).toObject();
        QJsonObject order = test.value("orderbook").toObject();
        QJsonObject bid = order.value("bids").toObject();
        QJsonObject ask = order.value("asks").toObject();

        int pairingID = test.value("pairing_id").toInt();
        QString primaryCurrency = test.value("primary_currency").toString();
        QString secondaryCurrency = test.value("secondary_currency").toString();
        double volume = test.value("volume_24hours").toDouble();
        double bids = bid.value("highbid").toDouble();
        double asks = ask.value("highbid").toDouble();
        double change = test.value("change").toDouble();
        double last = test.value("last_price").toDouble();

        coin *c = new coin(pairingID,primaryCurrency,secondaryCurrency,volume,bids,asks,change,last);

        coins.push_back(c);
    }
   updateWidget(coins.size());

}

void firstPage::onDataReceived2(QJsonObject data)
{
    QJsonObject test = data.value("data").toObject();
    QString avg = test.value("avg").toString();
    QString close = test.value("close").toString();
    QString high = test.value("high").toString();
    QString low  = test.value("low").toString();
    QString open = test.value("open").toString();
    QString volume  = test.value("volume").toString();
    summaries *c = new summaries(avg,close,high,low,open,volume);
    summary.push_back(c);
}

void firstPage::updateWidget(int size)
{
    for(int i = 1 ; i < size + 1; i++){
        bool checkMinus = false;
        bool checkchange = true;
        QString location = "C:\\Users\\User\\Documents\\c2\\Resource\\";
        location.push_back(QString::number(i));
        location.push_back(".png");
        QString first = coins[i-1]->getFirstCurrency();
        QString second = coins[i-1]->getSecondCurrency();
        QString third = "\t\t\t\t\t\t";
        QString fourth = QString::number(coins[i-1]->getLastPrice());
        for(int j = 0;j < fourth.size();j++){
            if(fourth[j] == "e"){
                fourth = scientificConvert(fourth);
            }
        }
        QString fifth = "(" + QString::number(coins[i-1]->getChange()) + "% )  ";
        for(int k = 0;k < fifth.size();k++  ){
            if(fifth[k] == "-"){
               checkMinus = true;
            }
            if(fifth[k] == "0" && fifth[k + 1] == "%"){
                checkchange = false;
            }
        }
        QString mix;
        mix.push_back(second);
        mix.push_back("/");
        mix.push_back(first);
        mix.push_back(third);
        mix.push_back(fifth);
        mix.push_back(fourth);
        QListWidgetItem *coinList = new QListWidgetItem(QIcon(location),mix);
        if(checkMinus == false){
            coinList->setForeground(Qt::darkGreen);
        }
        if(checkMinus == true){
            coinList->setForeground(Qt::red);
        }
        if(checkchange ==false){
            coinList->setForeground(Qt::gray);
        }
        coinList->setSizeHint(QSize(50,60));
        ui->listWidget->addItem(coinList);

    }

}

QString firstPage::scientificConvert(QString number)
{
    QString newValue;
    QString temp;
    int zero;
    number.remove(QRegExp("[.e-]"));

    for(int i = 0; i < number.size();i++){
        if(i = number.size() - 1){
            temp = number[i];
            zero = temp.toInt();
            for(int j = 0;j < zero - 1; j++){
                newValue.push_front("0");
            }
            number.remove(i,1);
        }
    }
    newValue.push_back(number);
    newValue.push_front("0.");
    return newValue;
}

void firstPage::on_listWidget_clicked(const QModelIndex &index)
{

    int indexNum = index.row();
    QString mix;
    QString first = summary[indexNum]->getAvg();
    QString second = summary[indexNum]->getClose();
    QString third = summary[indexNum]->getHigh();
    QString fourth = summary[indexNum]->getLow();
    QString fifth = summary[indexNum]->getOpen();
    QString sixth = summary[indexNum]->getVolume();
    QString seventh = QString::number(coins[indexNum]->getAsk());
    for(int i = 0;i < seventh.size();i++){
        if(seventh[i] == "e"){
            seventh = scientificConvert(seventh);
        }
    }
    QString last = QString::number(coins[indexNum]->getBids());
    for(int j = 0;j < last.size();j++){
        if(last[j] == "e"){
            last = scientificConvert(last);
        }
    }
    mix.push_back("AVERAGE PRICE:\t\t=\t\t");
    mix.push_back(first);
    mix.push_back("\n\n");
    mix.push_back("CLOSED PRICE:\t\t=\t\t");
    mix.push_back(second);
    mix.push_back("\n\n");
    mix.push_back("HIGHEST PRICE:\t\t=\t\t");
    mix.push_back(third);
    mix.push_back("\n\n");
    mix.push_back("LOWEST PRICE:\t\t=\t\t");
    mix.push_back(fourth);
    mix.push_back("\n\n");
    mix.push_back("OPENING PRICE:\t\t=\t\t");
    mix.push_back(fifth);
    mix.push_back("\n\n");
    mix.push_back("ASKING PRICE:\t\t=\t\t");
    mix.push_back(seventh);
    mix.push_back("\n\n");
    mix.push_back("BIDING PRICE:\t\t=\t\t");
    mix.push_back(last);
    mix.push_back("\n\n");
    mix.push_back("TOTAL VOLUME:\t\t=\t\t");
    mix.push_back(sixth);
    mix.push_back("\n");
    QMessageBox::information(this,"BITCHECK",mix);
}
