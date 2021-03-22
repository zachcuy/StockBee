#include <ticker.h>
#include <curl.h>
#include <stdio.h>
#include <fstream>
#include <iostream>

namespace util
{
    // Downloads NASDAQ Tickers
    bool Ticker::downloadTickers()
    {
        // NASDAQ Symbol Directory Link: ftp://ftp.nasdaqtrader.com/symboldirectory/

        CURL *curl;
        FILE* fp;
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

    // Read the NASDAQ tickers from the downloaded file
    bool Ticker::readNASDAQTickers()
    {
        std::ifstream file;
        std::string line = "";
        file.open(fileName);

        // Loop through the ticker file and clean it out then push onto our vector
        while (std::getline(file, line))
        {
            size_t position = line.find_first_of("|");

            try
            {
                tickers.push_back(line.substr(0, line.find_first_of("|")));
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }

        // Clear out the timestamp that is appended to the end of the NASDAQ data and the table headers
        tickers.pop_back();
        tickers.erase(tickers.begin());

        // Closing file before cleaning up
        file.close();
        
        // Delete the ticker list file (comment out if you wanna keep it)
        //std::remove(fileName.c_str());

        return true;
    }

    // Driver function to get all active tickers on NASDAQ and fill a vector with it
    void Ticker::getNASDAQTickers()
    {
        // Set up URL for NASDAQ
        url = "ftp://ftp.nasdaqtrader.com/symboldirectory/nasdaqlisted.txt";

        // Set up output file for NASDAQ
        fileName = "NASDAQ" + fileNameAppend;

        // Download ticker list from NASDAQ and save to txt file
        downloadTickers();

        // Read ticker list file and populate ticker vector
        readNASDAQTickers();
    }
    
    std::vector<std::string> Ticker::getTickerList() 
    {
        return tickers;
    }
}