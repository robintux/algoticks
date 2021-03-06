#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "../include/timeutils.h"

const char *strp_format_1 = "%Y-%m-%d %H:%M:%S";
const char *strp_format_2 = "%Y/%m/%d %H:%M:%S";

int is_date_over_or_eq_intraday(char *date, int intraday_hour, int intraday_min)
{

    struct tm date_ts;

    if (!strptime(date, strp_format_1, &date_ts))
    {
        if (!strptime(date, strp_format_2, &date_ts))
        {
            return -1;
        }
    }

    date_ts.tm_year += 1900;

    if ((date_ts.tm_hour >= intraday_hour) == true && (date_ts.tm_min >= intraday_min) == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int is_date_after(char *date_a, char *date_b)
{

    struct tm date_a_ts;
    struct tm date_b_ts;

    time_t a_mktime;
    time_t b_mktime;

    if(!strptime(date_a, strp_format_1, &date_a_ts))
    {
        if (!strptime(date_a, strp_format_2, &date_a_ts))
        {
            return -1;
        }else{
            strptime(date_b, strp_format_2, &date_b_ts);
        }
    }else
    {
        strptime(date_b, strp_format_1, &date_b_ts);
    }


    date_a_ts.tm_year += 1900;
    date_b_ts.tm_year += 1900;

    if (date_a_ts.tm_year >= date_b_ts.tm_year){
        if (date_a_ts.tm_mon >= date_b_ts.tm_mon){
            if (date_a_ts.tm_mday >= date_b_ts.tm_mday){
                if (date_a_ts.tm_hour >= date_b_ts.tm_hour){
                    if (date_a_ts.tm_min >= date_b_ts.tm_min){
                        if (date_a_ts.tm_sec >= date_b_ts.tm_sec){

                            return true;

                        }
                    }
                }
            }
        }
    }

    return false;
}
