#define MOD 1000000007

int** palindromePairs(char** words, int wordsSize, int* returnSize, int** returnColumnSizes) {
    long long hashF[wordsSize], hashR[wordsSize], mul[301];
    long long forwardHash, reverseHash;
    int **ans, *cols, ansSize = 0, i, j, len[wordsSize];
    mul[0] = 1;
    for (i = 1; i <= 300; ++i) mul[i] = (mul[i-1] * 31) % MOD;
    for (i = 0; i < wordsSize; ++i) {
        len[i] = strlen(words[i]);
        ansSize += len[i];
        hashF[i] = 0;
        hashR[i] = 0;
        for (j = 0; j < len[i]; ++j) {
            hashF[i] = (hashF[i] * 31) % MOD;
            hashF[i] = (hashF[i] + words[i][j]) % MOD;
            hashR[i] = (hashR[i] + words[i][j] * mul[j]) % MOD;
        }
    }
    ans = (int**) malloc(2 * ansSize * sizeof(int*));
    cols = (int*) malloc(2 * ansSize * sizeof(int));
    ansSize = 0;
    for (i = 0; i < wordsSize - 1; ++i) {
        for (j = i + 1; j < wordsSize; ++j) {
            forwardHash = (hashF[i] * mul[len[j]]) % MOD;
            forwardHash = (forwardHash + hashF[j]) % MOD;
            reverseHash = (hashR[j] * mul[len[i]]) % MOD;
            reverseHash = (reverseHash + hashR[i]) % MOD;
            if (forwardHash == reverseHash) {
                ans[ansSize] = (int*) malloc(2 * sizeof(int));
                ans[ansSize][0] = i;
                ans[ansSize][1] = j;
                cols[ansSize++] = 2;
            }
            forwardHash = (hashF[j] * mul[len[i]]) % MOD;
            forwardHash = (forwardHash + hashF[i]) % MOD;
            reverseHash = (hashR[i] * mul[len[j]]) % MOD;
            reverseHash = (reverseHash + hashR[j]) % MOD;
            if (forwardHash == reverseHash) {
                ans[ansSize] = (int*) malloc(2 * sizeof(int));
                ans[ansSize][0] = j;
                ans[ansSize][1] = i;
                cols[ansSize++] = 2;
            }
        }
    }
    *returnSize = ansSize;
    *returnColumnSizes = cols;
    return ans;
}