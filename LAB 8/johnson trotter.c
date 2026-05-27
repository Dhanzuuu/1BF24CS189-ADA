#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[10], dir[10];

    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        dir[i] = -1; // left
    }

    while (1) {
        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");

        int mobile = -1, pos = -1;

        for (int i = 0; i < n; i++) {
            int j = i + dir[i];

            if (j >= 0 && j < n && a[i] > a[j] && a[i] > mobile) {
                mobile = a[i];
                pos = i;
            }
        }

        if (pos == -1)
            break;

        int j = pos + dir[pos];

        int t = a[pos];
        a[pos] = a[j];
        a[j] = t;

        t = dir[pos];
        dir[pos] = dir[j];
        dir[j] = t;

        for (int i = 0; i < n; i++)
            if (a[i] > mobile)
                dir[i] *= -1;
    }

    return 0;
}
