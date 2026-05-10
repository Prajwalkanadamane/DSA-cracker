#include <iostream>
using namespace std;

void selectionSort(int arr[],int n){

    for (int i = 0; i<n-1; i++){
        int smallestIndex = i; //Start with the first element and assume it is the smallest.
        for (int j=i+1; j<n; j++){ //Scan the rest of the array to find the smallest element.
            if (arr[j] < arr[smallestIndex]){
                smallestIndex = j;
            }
        }
        swap(arr[i], arr[smallestIndex]); //Swap this smallest element with the first element.
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

    selectionSort(arr,n);
    printArray(arr,n);
    
    return 0;
}