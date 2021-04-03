#include <yahooAPI.h>
#include <curl.h>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <iostream>

namespace yAPI
{
    // Set interval state 
    void Yahoo::setInterval(const unsigned int &VALUE)
    {
        INTERVAL = VALUE;
    }

    // Get current interval state
    std::string Yahoo::getYahooInterval(const unsigned int &num)
    {
        return stamps.at(num);
    }

    // Downloads and saves data from the provided url into a file
    bool Yahoo::downloadData(const std::string &url, const std::string &fileName) 
    {
        CURL *curl;
        FILE *fp;
        CURLcode res;

        curl = curl_easy_init();

        if (curl)
        {
            fp = std::fopen(fileName.c_str(), "wb");
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
            res = curl_easy_perform(curl);

            curl_easy_cleanup(curl);
            fclose(fp);

            return true;
        }

        return false;
    }

    // Driver function to get historical data from Yahoo's financial API
    bool Yahoo::getData(const std::vector<std::string> &tickers, const std::string &startDate, const std::string &endDate)
    {
        for (std::string ticker : tickers)
        {
            std::cout << "Downloading data for {" << ticker << "}\n\\(^o^)/\n";

            // Reset URL
            resetURL();

            // Fixing URL
            fixYahooURL(ticker, startDate, endDate);

            // Download
            if (downloadData(url, prefix + ticker + ".csv"))
            {
                std::cout << "Finished downloading data for {" << ticker << "}.\n\n\n";
            }
            else
            {
                std::cerr << "ERROR: Could not download data for {" << ticker << "}. Please check the ticker.\n\n\n";
            }
        }

        return true;
    }

    // Constructs the Yahoo URL
    std::string Yahoo::fixYahooURL(const std::string &ticker, const std::string &startDate, const std::string &endDate)
    {
        // Replace ticker
        size_t startPos = url.find("{ticker}");
        if (startPos != std::string::npos)
        {
            url.replace(startPos, 8, ticker);
        }
        
        // Replace start time
        startPos = url.find("{start_time}");
        if (startPos != std::string::npos)
        {
            url.replace(startPos, 12, fixYahooDate(startDate));
        }

        // Replace end time
        startPos = url.find("{end_time}");
        if (startPos != std::string::npos)
        {
            url.replace(startPos, 10, fixYahooDate(endDate));
        }

        // Replace interval
        startPos = url.find("{interval}");
        if (startPos != std::string::npos)
        {
            url.replace(startPos, 10, getYahooInterval(INTERVAL));
        }

        return url;
    }

    // Constructs the dates into UNIX time stamps of type std::string
    std::string Yahoo::fixYahooDate(std::string date)
    {
        struct std::tm time = {0,0,0,0,0,0,0,0,0};
        std::istringstream ss(date);
        ss >> std::get_time(&time, "%Y-%m-%d");

        if (ss.fail())
        {
            std::cerr  << "ERROR: Cannot parse date (" << date <<"); Form: YYYY-MM-DD" << std::endl;
            exit(1);
        }

        time.tm_hour = 0;
        time.tm_min = 0;
        time.tm_sec = 0;

        std::time_t epoch = std::mktime(&time);

        return std::to_string(epoch);
    }

    // Resets the URL to the original. This is done every time a new ticker is uploaded.
    void Yahoo::resetURL()
    {
        url = "https://query1.finance.yahoo.com/v7/finance/download/{ticker}?period1={start_time}&period2={end_time}&interval={interval}&events=history&includeAdjustedClose=true";
    }
}