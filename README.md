# StockBee: C++ & Python Financial Market Screener API

The purpose of this code is to provide an interface for data analysts to grab financial market data easily using C++ or Python.

---
# C++ Version

### Why C++ and Python?

While Python is a great language that I enjoy using, I found that the static analysis of data on top of grabbing data is incredibly slow. The difference between grabbing all NASDAQ data using this C++ program takes about 2.5 minutes on my very old, very slow DELL laptop. My Python script (found in this same repo) takes about 13.5 minutes to complete.

### Moving Forward

I plan on including a complete library that implements pattern recognition for fundamental technical analysis of stocks.

### Build tools used:

Visual Studio Code (Editor)
CMake (Build System)
VCPKG (Libraries/Dependencies)
Git with Github (Source Control)

### Libraries Used

STL
LIBCURL

---

### How to use:

1) Create a yAPI::Yahoo object

2) Create a util::Ticker object

3) Call Ticker::getNASDAQTickers to populate a vector filled with NASDAQ tickers

4) Call Yahoo::getData to download all the data for each ticker!

5) The fun times have come and we can now begin to perform some analysis on all this sweet, sweet data!

## Notes

1: If you want to keep the list of NASDAQ tickers, then comment out the file in ticker.cpp that deletes the file.

2: If you want to use your own list of tickers, then you can simply create your own std::vector<std::string> and pass it to Yahoo::getData

---
# Python Version

This project is a WIP and is a stock screener developed in Python3. I started this project because I became interested in modeling market movements which seemed to be a great way for me to further practice and develop my data analytics skills.

I am normally a C/C++ developer but have used Python in the past to create simpler scripts for data wrangling (United Nations - World Health Org data sets) and visualization; this project has taught me the beauty of Python for scripting.

### Features List:
    1) Autonomous execution of script per market day end
    2) Filter tickers based on a variety of cases
    3) Group based on filters
    4) Consolidate into single Excel file for easy usage

Output: Multiple Excel files - n+1 files (one for each ticker analyzed and the single consolidated file)

Note: The purpose of grouping into filters is so that the user can manage different patterns easily and develop their trading strategies accordingly. It will streamline the charting process for retail traders and is a free, simpler alternative to paid services available online!

