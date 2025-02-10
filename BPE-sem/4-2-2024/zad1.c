#include <stdio.h>
//1-4-7
void sortArr(int nums[], int n) {
    int temp;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(nums[i] > nums[j]) {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
}
void countSameNums(int nums[], int n){
    int counter, index;
    int max = 0;
    for(int i = 0; i < n; i++){
        counter = 0;
        for(int j = i + 1; j < n; j++){
            if(nums[i] == nums[j]){
                counter++;
            } else {
                break;
            }
        }
        if(counter > max){
            index = i;
            max = counter;
        }
    }
    printf("The longest consecutive sequence length is %d\n", max + 1);
    printf("The starting index is %d\n", index);
}

int main() {
    int n;
    printf("Enter the length: ");
    scanf("%d", &n);
    int nums[n];
    for(int i = 0; i < n; i++) {
        int temp;
        printf("N%d: ", i + 1);
        scanf("%d", &temp);
        nums[i] = temp;
    }

    sortArr(nums, n);
    countSameNums(nums,n);

    return 0;
}
