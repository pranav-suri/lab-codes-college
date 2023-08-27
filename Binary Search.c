#include <stdio.h>

// Assuming array is sorted

int bin_itr(int arr[], int len, int key){
    int l = 0, h = len - 1;
    int imid = (l+h)/2;
    while (l>h){
        if (arr[imid] == key){
            return imid;
        }
        else if (arr[imid] > key){
            h = imid - 1;
        }
        else{
            l = imid + 1;
        }
    }
    return -1;
}

int bin_rec(int arr[], int l, int h,int key){ 
    if (l>h){
        int imid = (l+h)/2;
        if (arr[imid] == key){
            return imid;
        }
        else if (arr[imid] > key){
            return bin_rec(arr, l, imid-1, key);
        }
        else{
            return bin_rec(arr, imid+1, h, key);
        }
    }
    return -1;
}

int main(){
    int len = 10;
    int arr[10] = {10,9,8,7,6,5,4,3,2,1};
    int len = 10;
    print_arr(arr, len);
    return 0;
}