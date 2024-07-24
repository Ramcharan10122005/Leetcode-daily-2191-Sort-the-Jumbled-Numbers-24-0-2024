typedef struct {
    int original_index;
    int mapped_value;
} Pair;

int mappedNumber(int num, int* mapping) {
    char s[12];
    snprintf(s, sizeof(s), "%d", num);  // Convert num to string
    for (int i = 0; s[i] != '\0'; i++) {
        s[i] = '0' + mapping[s[i] - '0'];  // Map each digit
    }
    return atoi(s);  // Convert the modified string back to an integer
}

int comparePairs(const void* a, const void* b) {
    Pair* pairA = (Pair*)a;
    Pair* pairB = (Pair*)b;
    if (pairA->mapped_value == pairB->mapped_value) {
        return pairA->original_index - pairB->original_index;  // Sort by original index if mapped values are equal
    }
    return pairA->mapped_value - pairB->mapped_value;  // Otherwise, sort by mapped value
}

int* sortJumbled(int* mapping, int mappingSize, int* nums, int numsSize, int* returnSize) {
    Pair* pairs = (Pair*)malloc(numsSize * sizeof(Pair));
    for (int i = 0; i < numsSize; i++) {
        pairs[i].original_index = i;
        pairs[i].mapped_value = mappedNumber(nums[i], mapping);
    }
    qsort(pairs, numsSize, sizeof(Pair), comparePairs);
    int* ans = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        ans[i] = nums[pairs[i].original_index];
    }
    *returnSize = numsSize;
    free(pairs);
    return ans;
}
