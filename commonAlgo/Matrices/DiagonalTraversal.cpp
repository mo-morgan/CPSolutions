#include <stdio.h>

int main()
{
    int x[3][3] = {1, 2, 3,
                   4, 5, 6,
                   7, 8, 9};
    int n = 3;
    for (int slice = 0; slice < 2 * n - 1; ++slice) {
        printf("Slice %d: ", slice);
        int z = (slice < n) ? 0 : slice - n + 1;
        for (int j = z; j <= slice - z; ++j) {
            printf("%d ", x[j][slice - j]);
        }
        printf("\n");
    }
    return 0;
}