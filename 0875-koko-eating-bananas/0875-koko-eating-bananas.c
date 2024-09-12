#define MAX(a, b) ((a) > (b) ? (a) : (b))

int minEatingSpeed(int* piles, int pilesSize, int h) {

    int lo = 1;
    int hi = 0;
    int mid;
    int hours;

    for (int i = 0; i < pilesSize; i++) {
        hi = MAX(hi, piles[i]);
    }

    while (lo < hi) {
        mid = lo + (hi - lo) / 2;
        hours = 0;
        for (int i = 0; i < pilesSize; i++) {
            hours += (piles[i] + mid - 1 ) / mid;
        }
        if (hours <= h) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    return lo;
}