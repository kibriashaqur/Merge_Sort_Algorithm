#include <stdio.h>


void merge_sort(int first_number, int last_number, int needed_array[], int auxlary[]){
    if (last_number <= first_number){
        return;
    }
    int mid = (first_number + last_number) / 2;

    merge_sort(first_number, mid, needed_array, auxlary);
    merge_sort(mid + 1, last_number, needed_array, auxlary);

    int pointer_left = first_number;
    int pointer_right = mid + 1;
    int counting_loop;

    for (counting_loop = first_number; counting_loop <= last_number; counting_loop++){
        if (pointer_left == mid + 1){
            auxlary[counting_loop] = needed_array[pointer_right];
            pointer_right++;
        }
        else if (pointer_right == last_number + 1){
            auxlary[counting_loop] = needed_array[pointer_left];
            pointer_left++;
        }
        else if (needed_array[pointer_left] < needed_array[pointer_right]){
            auxlary[counting_loop] = needed_array[pointer_left];
            pointer_left++;
        }
        else{
            auxlary[counting_loop] = needed_array[pointer_right];
            pointer_right++;
        }
    }

    for(counting_loop = first_number; counting_loop <= last_number; counting_loop++){
        needed_array[counting_loop] = auxlary[counting_loop];
    }
}


int main()
{
    int needed_array[50], auxlary[50], number, iteration, swap;

    printf("***You can take maximum 50 number***\n");
    printf("Enter number of elements in the array:\n");
    scanf("%d", &number);

    printf("Enter %d integers\n", number);

    for (iteration = 0; iteration < number; iteration++){
        scanf("%d", &needed_array[iteration]);
    }

    merge_sort(0, number - 1, needed_array, auxlary);

    printf("Printing the sorted array:\n");

    for (iteration = number -1 ; iteration >= 0; iteration--){
        printf("%d\n", needed_array[iteration]);
    }

    return 0;
}

