#include <stdio.h>
#include <stdlib.h>

// Structure to hold the result indices
typedef struct {
    int index1;
    int index2;
} Result;

// Function to find two numbers that add up to the target
Result twoSum(int* nums, int numsSize, int target) {
    Result result;
    result.index1 = -1;
    result.index2 = -1;

    // Hash map to store number and its index
    int hash[100000] = {0}; // Assuming a constraint on number range (adjust if necessary)

    for (int i = 0; i < numsSize; ++i) {
        int complement = target - nums[i];
        
        // Check if complement exists in the hash map
        if (hash[complement] != 0) {
            result.index1 = hash[complement] - 1;
            result.index2 = i;
            break;
        }
        
        // Store current number and its index in hash map
        hash[nums[i]] = i + 1;
    }

    return result;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    Result result = twoSum(nums, numsSize, target);

    if (result.index1 != -1 && result.index2 != -1) {
        printf("Indices: %d, %d\n", result.index1, result.index2);
    } else {
        printf("No two numbers add up to the target.\n");
    }

    return 0;
}

