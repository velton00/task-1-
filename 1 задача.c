#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

enum
{
    first_size = 2,
    extension = 2
};
int
main(void)
{
    long long ans = 0;
    long long ans_prev = 0;
    long long *nums = calloc(first_size, sizeof(*nums));
    long long len = 0;
    long long cur;
    long long tmp;
    long long i = 0;
    while(scanf("%lld", &cur) == 1) {
        if (__builtin_saddll_overflow(ans, cur, &ans)) {
            ans = ans_prev;
            if (len < first_size) {
                nums[len] = cur;
                len++;
            } else {
                nums = realloc(nums, extension * first_size * sizeof(*nums));
                nums[len] = cur;
                len++;
            }

        }

        ans_prev = ans;
        while (i != len) {
            for (i = 0; i < len; i++) {
                if (!__builtin_saddll_overflow(ans, nums[i], &ans)) {
                       nums[i] = nums[len -1];
                       len--;
                       break;
                } else {
                    ans = ans_prev;
                }
            }
            ans_prev = ans;

        }
    }
    printf("%lld\n", ans);
    free(nums);
    return 0;
}
