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

        // Indicators //
        float SMA = 0.0f;
        float WMA = 0.0f;
        float EMA = 0.0f;

        friend std::ostream& operator<< (std::ostream& out, Data& d)
        {
            out << d.date << " " << d.open << " " << d.high << " " << d.low << " " << d.close << " " << d.adjustedClose << " " << d.volume << " " << d.SMA << "\n";

            return out;
        }
    };

    std::vector<Data> importData(std::string fileName);

    class MA // Moving Averages
    {
    public:
        void simpleMA(std::vector<Data> &dataset, const unsigned int period); // Simple moving avg
        void weightedMA(std::vector<Data> &dataset, const unsigned int period); // Weighted moving avg
        void exponentialMA(std::vector<Data> &dataset, const unsigned int period); // Exponential moving avg
    };

    class Volatility
    {
    public:
        void bollinger(std::vector<Data>); // Bollinger bands
        void donchian(std::vector<Data>); // Donchian channels
        void keltner(std::vector<Data>); // Keltner channels
    };

    class Oscillator
    {
    public:
        void rsi(std::vector<Data>); // relative strength index
        void stochastic(std::vector<Data>); // stochastic oscillator
        void tsi(std::vector<Data>); // true strength index
        void ultimate(std::vector<Data>); // ultimate oscillator
    };
}


#endif // __INDICATORS_H__