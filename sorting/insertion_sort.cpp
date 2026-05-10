#include <iostream>
using namespace std;

void insertionSort(int arr[],int n){

    for (int i = 1; i<n-1; i++){
        int key = arr[i]; //current element
        int j = i-1; //previous element

        while (j>=0 && arr[j] > key){ //jabtak mera arr[j] > current element hai
            arr[j] = arr[j+1];// arr[j] ko aage dakelo
            j--; 
        }
        arr[j+1] = key;
    }


}

void printArray(int arr[], int n){
    for (int i=0; i<n;i++){
        cout << arr[i] << " ";
    }
    cout<<endl;
}


int main(){
    int arr[] = {1,4,3,2,5};
    int n = 5;

    insertionSort(arr,n);
    printArray(arr,n);
    
    return 0;
}
// '''j >= 0 ensures that we don’t go out of the array bounds (move left beyond index 0).
// arr[j] > key checks if the current element is greater than the key. If so, it should be moved to the right.
// arr[j + 1] = arr[j] shifts the larger element one position to the right.
// j-- moves the pointer j one step left, so we continue checking the next element on the left.'''