#ifndef __MAIN_H__
#define __MAIN_H__

#define CURL_STATICLIB // Required to build with curl as static library  

enum Interval
{
    FIVEMIN,
    FIFTEENMIN,
    THIRTYMIN,
    HOURLY,
    DAILY,
    WEEKLY,
    MONTHLY
};

#endif // __MAIN_H__