#ifndef __TICKER_H__
#define __TICKER_H__

// NASDAQ Symbol Directory Link: ftp://ftp.nasdaqtrader.com/symboldirectory/

#include <vector>
#include <string>

namespace util
{
    class Ticker
    {
        const std::string fileNameAppend = "tickers.txt";
        std::string fileName;
        std::string url;
        std::vector<std::string> tickers {};

    public:
        bool downloadTickers();
        bool readNASDAQTickers();
        void getNASDAQTickers();
        std::vector<std::string> getTickerList();
    };
}



#endif // __TICKER_H__