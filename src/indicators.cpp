#include <indicators.h>

namespace indicator
{
    // Parses CSV data
    std::vector<Data> indicator::importData(std::string fileName)
    {
        // Data container
        std::vector<Data> dataset;

        // Open file
        std::ifstream file;
        file.open(fileName);

        if (file.is_open())
        {
            std::cerr << "Could not open file\n";
        }
        else
        {
            // Temp string to store lines
            std::string line;

            bool header = true;

            while (std::getline(file, line))
            {
                // We don't want to keep the header
                if (header)
                {
                    header = false;
                }
                else
                {
                    for (int i = 0; i < line.size(); ++i)
                    {
                        if (line[i] == ',')
                            line[i] = ' ';
                    }

                    std::stringstream ss(line);
                    Data point;

                    ss >> point.date >> point.open >> point.high >> point.low >> point.close >> point.adjustedClose >> point.volume;

                    dataset.push_back(point);                
                }
            }
        }
        
        return dataset;
    }

    // Moving averages
    bool MA::simpleMA(std::string fileName)
    {
        return true;
    }

    bool MA::weightedMA(std::string fileName)
    {
        return true;
    }

    bool MA::exponentialMA(std::string fileName)
    {
        return true;
    }

    // Volatility
    bool Volatility::bollinger(std::string fileName)
    {
        return true;
    }

    bool Volatility::donchian(std::string fileName)
    {
        return true;
    }

    bool Volatility::keltner(std::string fileName)
    {
        return true;
    }

    // Oscillators
    bool Oscillator::rsi(std::string fileName)
    {
        return true;
    }

    bool Oscillator::stochastic(std::string fileName)
    {
        return true;
    }

    bool Oscillator::tsi(std::string fileName)
    {
        return true;
    }

    bool Oscillator::ultimate(std::string fileName)
    {
        return true;
    }
}