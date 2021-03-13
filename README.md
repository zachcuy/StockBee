# C++ Financial Market Screener API

The purpose of this code is to provide an interface for data analysts to grab financial market data easily using C++.

### Why C++ over Python?

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