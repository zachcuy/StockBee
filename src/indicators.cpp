#include <indicators.h>


namespace indicator
{
    void cleanData(std::string fileName) 
    {
        std::fstream file;
        std::fstream cleanFile;
        cleanFile.open(fileName + "CLEAN.csv");
        file.open(fileName + ".csv");

        std::string line;

        // replace commas with space
        while (std::getline(file, line))
        {
            for (int i = 0; i < 6; ++i)
            {
                size_t pos = line.find(",");
                std::cout << pos << " ";
                line.replace(pos, 1, " ");
            }
            cleanFile << line;
        }

        file.close();
    }

    // Moving averages
    bool MA::simpleMA(std::string fileName) 
    {
        std::fstream file;
        file.open(fileName);
        
        cleanData(fileName);
        

        file.close();
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