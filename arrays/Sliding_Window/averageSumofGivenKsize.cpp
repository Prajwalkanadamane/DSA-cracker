#include<iostream>
#include<vector>
using namespace std;

void FirstApproach(vector<int>& vec, int k){

    int sum = 0;

    for (int i=0; i<k; i++){
        sum += vec[i];
    }

    int maxSum = sum;

    for (int i=k; i<vec.size(); i++){
        sum = sum - vec[i-k] + vec[i];
        maxSum = max(sum, maxSum);
    }

    cout << "MaxaverageSum is: " << (double)maxSum/k << endl;

}

void secondApproach(vector<int>& vec, int k){

    int sum = 0;

    for (int i=0; i<k; i++){
        sum += vec[i];
    } 

    int maxSum = sum;
    int l=0, r=k-1;

    while(r < vec.size()-1){

        sum = sum - vec[l];
        l++; r++;
        sum += vec[r];
        maxSum = max(maxSum, sum);
    }

    cout << "MaxaverageSum is: " << (double)maxSum/k << endl;

}

int main(){
    vector<int> vec = {1,12,-5,-6,50,3};
    int k = 4;
    // FirstApproach(vec, k);
    secondApproach(vec, k);
}