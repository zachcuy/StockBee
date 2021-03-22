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
        std::vector<float> simpleMA(std::vector<Data> dataset, unsigned int period); // Simple moving avg
        std::vector<float> weightedMA(std::vector<Data> dataset, unsigned int period); // Weighted moving avg
        std::vector<float> exponentialMA(std::vector<Data> dataset, unsigned int period); // Exponential moving avg
    };

    class Volatility
    {
    public:
        std::vector<std::vector<float>> bollinger(std::vector<Data>); // Bollinger bands
        std::vector<std::vector<float>> donchian(std::vector<Data>); // Donchian channels
        std::vector<std::vector<float>> keltner(std::vector<Data>); // Keltner channels
    };

    class Oscillator
    {
    public:
        std::vector<float> rsi(std::vector<Data>); // relative strength index
        std::vector<float> stochastic(std::vector<Data>); // stochastic oscillator
        std::vector<float> tsi(std::vector<Data>); // true strength index
        std::vector<float> ultimate(std::vector<Data>); // ultimate oscillator
    };
}


#endif // __INDICATORS_H__