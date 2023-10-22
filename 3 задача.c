#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <limits.h>
#include <math.h>
#include <stdint.h>
int
main(int argc, char *argv[])
{
    int fd = open(argv[1], O_RDWR);
    struct stat buf;
    fstat(fd, &buf);
    int size = 8 * buf.st_size; //в битах
    double m = sqrt(size);
    if (m != ((int) m)) {
        fprintf(stderr, "bad file\n");
        exit(1);
    }
    int k = (int) m; //число бит в строке
    int n = k/8; //число байт в строке
    for (int i = 0; i < k; i++) {
        lseek(fd, (i*k + i)/ 8, SEEK_SET);
        uint8_t c;
        read(fd, &c, 1);
        c |= (1 << (i*k + i) % 8);
        lseek(fd, -1, SEEK_CUR);
        write(fd, &c, 1);
    }
    close(fd);
    return 0;
}
