#include<bits/stdc++.h>
using namespace std;

class heap{
    public:

    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        size = size+1;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index/2;

            if (arr[parent]  < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent; //I just moved upward. Now continue the battle from my new position.
            }else{
                return;
            }
        }
    }

    void print(){
        for (int i=1; i<=size; i++){
            cout << arr[i] << " ";
        }
    }

    void deleteheapRoot(){
        if (size == 0){
        cout << "Mothing to deltete"; 
        return;
        }    

        arr[1] = arr[size]; // put last element into first index
        size--; // remove last element

        //take root node to its correct position
        int i=1;
        while(i < size){
            int leftIdx = 2*i;
            int rightIdx = 2*i+1;

            if (leftIdx < size && arr[i] < arr[leftIdx] && arr[leftIdx] > arr[rightIdx]){ // we are checking out of bound condition so that we dont end up checking the left or right nodes for the leaf node.
                swap(arr[i], arr[leftIdx]);
                i = leftIdx;
            }else if (rightIdx < size && arr[i] < arr[rightIdx] && arr[leftIdx] < arr[rightIdx]){ // extra "&& arr[leftIdx] > arr[rightIdx]" this condition just to make sure we are swapping the root with the bigger child.
                swap(arr[i], arr[rightIdx]);
                i = rightIdx;
            }else{
                return;
            }
        }
    }
};

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i, right = 2*i+1;

    if (left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    if (largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    int size = n;
    while(size > 1){
        swap(arr[size], arr[1]);
        size--;

        heapify(arr, size, 1);
    }
}

int main(){
    // heap h;

    // h.insert(50);
    // h.insert(55);
    // h.insert(53);
    // h.insert(52);
    // h.insert(54);
    // h.print();
    // cout << endl;
    // h.deleteheapRoot();
    // h.print();

    int arr[6] = {-1, 54, 53, 52, 56, 50};

    int n = 5; // size of the array;
    
    for (int i=n/2; i>0; i--){
        heapify(arr, n, i);
    }
    cout << "Printing the array after the heapify: " << endl;
    for(int i=1; i<=n; i++){
        cout << arr[i] << " ";
    }cout << endl;
    heapSort(arr, n);
    cout << "Printing the sorted array now: " << endl;
    for(int i=1; i<=n; i++){
        cout << arr[i] << " ";
    }cout << endl;
}