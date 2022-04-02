#include <stdio.h>

int main() {
    FILE* ptr;
    int larger = 0;
    int prev = __INT_MAX__;
    int numbers[2000];
    int i = 0;

    // Opening file in reading mode
    ptr = fopen("day1.txt", "r");

    // Test file exists
    if (NULL == ptr) {
        printf("file can't be opened \n");
    }

    // Checking if number increase
    // line by line using loop.
    while (fscanf(ptr, "%d", &numbers[i]) != EOF)
    {
        if (numbers[i] > prev){ larger++;};
        prev = numbers[i];
        i++;
 
    }
 
    // Closing the file
    fclose(ptr);

    // Output result
    printf("Number of larger ints than prev number: %u", larger);

    return 0;
}