#ifndef __YAHOOAPI_H__
#define __YAHOOAPI_H__

#include <string>
#include <vector>

namespace yAPI
{
    class Yahoo
    {
    private:
        std::string url;
        std::string prefix;
        unsigned int INTERVAL = 0;
        std::vector<std::string> stamps{ "5m", "15m", "30m", "1hr", "1d", "1wk", "1mo" }; // Strings that Yahoo Finance accepts for intervals

    public:
        Yahoo()
        {
            // Default values for the Yahoo Finance URL and Interval  
            // Default URL Template: https://query1.finance.yahoo.com/v7/finance/download/{ticker}?period1={start_time}&period2={end_time}&interval={interval}&events=history&includeAdjustedClose=true
            // Default Daily Value: 6 (Refer to stamps vector) 
            prefix = "Data/";
            url = "https://query1.finance.yahoo.com/v7/finance/download/{ticker}?period1={start_time}&period2={end_time}&interval={interval}&events=history&includeAdjustedClose=true";
            INTERVAL = 6;
        }
        
        void setInterval(const unsigned int &VALUE);
        std::string getYahooInterval(const unsigned int &num);
        bool downloadData(const std::string &url, const std::string &fileName);
        bool getData(const std::vector<std::string> &tickers, const std::string &startDate, const std::string &endDate);
        std::string fixYahooURL(const std::string &ticker, const std::string &startDate, const std::string &endDate);
        std::string fixYahooDate(std::string date);
        void resetURL();
    };
}

#endif // __YAHOOAPI_H__