#include <indicators.h>
#include <numeric>

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

        if (!file.is_open())
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
                // We don't want the header
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

    // Moving Averages
    void MA::simpleMA(std::vector<Data> &dataset, const unsigned int period)
    {
        for (int i = (period - 1); i < dataset.size(); ++i)
        {
            float sum = 0;
            for (int j = i - (period - 1); j < i; ++j)
            {
                sum += dataset[j].close;
            }

            dataset[i].SMA = sum/period;
        }
    }
}