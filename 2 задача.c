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
int
cmp(const void *a, const void *b)
{
    long long a_new = *(long long*) a;
    long long b_new = *(long long*) b;
    if (a_new > b_new) {
        return -1;
    } else if (a_new < b_new){
        return 1;
    } 
    return 0;
}
int
main(int argc, char *argv[])
{
    long long nums[argc - 1];
    char *ep = NULL;
    for(long long i = 1; i < argc; i++) {
       nums[i-1] = strtoll(argv[i], &ep, 17);
    }
    qsort(nums, argc - 1, sizeof(*nums), cmp);
    for (long long i = 0; i < argc -1; i++) {
        printf("%lld\n", nums[i]);
    }
    return 0;
    
}
