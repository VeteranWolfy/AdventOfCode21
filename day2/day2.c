#include <stdio.h>

int main() {
    FILE* ptr;
    int larger = 0;
    int prev = __INT_MAX__;
    int numbers[2000];
    int i = 0;
    int a = 0;
    int b = 0;

    // Opening file in reading mode
    ptr = fopen("day2.txt", "r");

    // Test file exists
    if (NULL == ptr) {
        printf("file can't be opened \n");
    }

    // Scan for numbers
    // line by line using loop.
    while (fscanf(ptr, "%d", &numbers[i]) != EOF)
    {
        // compare previous consecutive sum of 3 to current sum of 3
        if (i == 3) { a = numbers[i-3] + numbers[i-2] + numbers[i-1]; }
        if (i > 3) {
            b = numbers[i-2] + numbers[i-1] + numbers[i];
            if (b > a) {larger ++;};
            a = b;
        }

        i++;
 
    }
 
    // Closing the file
    fclose(ptr);

    // Output result
    printf("Number of sets of three larger: %u", larger);

    return 0;
}