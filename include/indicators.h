#ifndef __INDICATORS_H__
#define __INDICATORS_H__

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

namespace indicator
{
    struct Data
    {
        // Data in CSV files have date, open price, high price, low price, close price, adjusted close price, and volume
        // Open, high, low, close, and adjusted are floats
        std::string date;
        double open = 0.0f;
        double high = 0.0f;
        double low = 0.0f;
        double close = 0.0f;
        double adjustedClose = 0.0f;
        unsigned long volume = 0;

        friend std::ostream& operator<< (std::ostream& out, Data& d)
        {
            out << d.date << " " << d.open << " " << d.high << " " << d.low << " " << d.close << " " << d.adjustedClose << " " << d.volume << "\n";

            return out;
        }
    };

    std::vector<Data> importData(std::string fileName);

    class MA // Moving Averages
    {
    public:
        bool simpleMA(std::string fileName); // Simple moving avg
        bool weightedMA(std::string fileName); // Weighted moving avg
        bool exponentialMA(std::string fileName); // Exponential moving avg
    };

    class Volatility
    {
    public:
        bool bollinger(std::string fileName); // Bollinger bands
        bool donchian(std::string fileName); // Donchian channels
        bool keltner(std::string fileName); // Keltner channels
    };

    class Oscillator
    {
    public:
        bool rsi(std::string fileName); // relative strength index
        bool stochastic(std::string fileName); // stochastic oscillator
        bool tsi(std::string fileName); // true strength index
        bool ultimate(std::string fileName); // ultimate oscillator
    };
}


#endif // __INDICATORS_H__