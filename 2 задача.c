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

enum
{
    first_size = 2,
    extension = 2
};
int
cmp(const void *a, const void *b)
{
    long long a = *(long long*) a;
    long long b = *(long long*) b;
    if (a > b) {
        return -1;
    } else if (a < b){
        return 1;
    }
    return 0;
}
int
main(int argc, char *argv[])
{
    long long *nums = calloc(first_size, sizeof(*nums));
    char *ep = NULL;
    for(long long i = 1, i < argc, i++) {
        if (i < first_size) {
            nums[i-1] = strtoll(argv[i], &ep, 17);
        } else {
            nums = realloc(num, extension * first_size * sizeof(*nums));
            nums[i-1] = strtoll(argv[i], &ep, 17);
        }
    }
    qsort(nums, argc - 1, sizeof(*nums), cmp);
    for (long long i = 0 , i < argc -1, i++) {
        printf("%lld\n", nums[i]);
    }
    free(nums);
    return 0

}
