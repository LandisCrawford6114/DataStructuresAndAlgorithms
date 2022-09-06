#include <stdio.h>
#include <time.h>

int main()
{
    clock_t start, end;
    double cpu_time_used;
    int ary[10];
    int search_nu = 9;
    
    start = clock();
    // Fill the array
    for (int i=0; i<10; i++) {
        ary[i] = i;
    }
    // Search for element
    for (int i=0; i<10; i++) {
        if(ary[i] == search_nu) {
            printf("Found");
            break;
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Execution time is %f \n", cpu_time_used);
    return 0;
}
