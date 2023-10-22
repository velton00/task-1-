#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/file.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <time.h>
enum
{
    SHIFT = 1900,
    STEP_SP = 2
};
int
main(void)
{
    int year;
    scanf("%d",&year);
    unsigned ans = 0;
    struct tm tmp = {
        .tm_mday = 1,
        .tm_mon = 0,
        .tm_year = year - SHIFT,
        .tm_isdst = -1
    };
    unsigned special_day = 1;
    mktime(&tmp);
    while(tmp.tm_year == year - SHIFT) {
        int flag = 0;
        if (tmp.tm_wday == 0 || tmp.tm_wday == 6) {
            ans++;
            flag = 1;
        }
        if (tmp.tm_yday == special_day - 1) {
            special_day *= STEP_SP;
            if (flag == 0) {
                ans++;
            }
        }
        tmp.tm_mday++;
        tmp.tm_isdst = -1;
        mktime(&tmp);
    }
    printf("%u\n", ans);
    return 0;

}
