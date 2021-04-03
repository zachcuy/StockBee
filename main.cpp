#include <main.h>
#include <yahooAPI.h>
#include <ticker.h>
#include <indicators.h>
#include <iostream>
#include <vector>

int main(int, char**)
{
    // Welcome and Enjoy! 


    // Create the objects we need to do all our stuff 
    yAPI::Yahoo yahoo;
    util::Ticker ticker;
    std::vector<indicator::Data> dataset;

    // Import our downloaded data
    // dataset = indicator::importData("DATA/AACG.csv");

    // Calculate SMA (14 day period)
    // indicator::MA ma;
    // ma.simpleMA(dataset, 14);

    // for (auto i : dataset)
    // {
    //     std::cout << i;
    // }

    // Defaults to Daily but there are a options like weekly and monthly
    // yahoo.setInterval(DAILY);

    // Download the data & save into csv file
    // yahoo.getData({"AAPL"}, "2020-01-01", "2021-01-01");

    // Download and create a vector of tickers to download from Yahoo Finance
    // ticker.getNASDAQTickers();

    // Get the sweet, sweet honey from Yahoo Finance!
    // yahoo.getData(ticker.getTickerList(), "2020-01-01", "2021-01-01");

    return 0;
}