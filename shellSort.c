#include <stdio.h>

/* shellsort: sort v[0]...v[n-1] into increasing order */

int shellsort(int v[], int n)
{
    int gap, i, j, temp;

    for (gap = n/2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i ++) {
            for (j = i - gap; j>= 0 && v[j]> v[j+gap]; j -= gap) {
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
            //printf("%d\n",v[j]);
        }
    }
    for (i = 0; i < n; i++) {
        //printf("%d ", v[i]);
    }
    //printf("\n");
    return v[7];

}

int test_function(int val){
    val = val +1;
    //printf("%d\n",val);
    return val;

}

int main(){
    int arr[]={5,3,6,2,6,9,8};
    //printf("%p",arr);
    shellsort(arr,7);
    for (int i = 0; i < 7; i++) {
        printf("%d ", arr[i]);
    }
    //int test = 5;
    //test_function(test);
    //printf("%d\n",test_function(test));
    //printf("%d\n",newList);
    //return 1;
}
