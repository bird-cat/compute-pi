#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "computepi.h"

#define CLOCK_ID CLOCK_MONOTONIC_RAW
#define ONE_SEC 1000000000.0

#define COMPUTE_PI_ERROR(x) (((x > M_PI) ? (x - M_PI) : (M_PI - x)) / M_PI)

int main(int argc, char const *argv[])
{
    if (argc < 2)
        return -1;

    int N = atoi(argv[1]);

    // Baseline
    printf("%lf ", COMPUTE_PI_ERROR(compute_pi_baseline(N)));

    // Leibniz
    printf("%lf ", COMPUTE_PI_ERROR(compute_pi_leibniz(N)));

    // Euler
    printf("%lf ", COMPUTE_PI_ERROR(compute_pi_euler(N)));

    // Ramanujan
    printf("%lf ", COMPUTE_PI_ERROR(compute_pi_ramanujan(N)));

    // Monte Carlo
    printf("%lf\n", COMPUTE_PI_ERROR(compute_pi_mc(N)));

    return 0;
}
