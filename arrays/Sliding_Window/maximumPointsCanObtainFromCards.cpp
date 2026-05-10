#include<iostream>
#include<vector>

using namespace std;

void maximumPoints(vector<int>& vec, int k){
    int last = vec.size()-1;   
    int points = 0;
    int right = k-1;
    
    for (int i=0; i<k; i++){
        points+= vec[i];
    }
    int newP = points;

    for (int i=last; i>=last-k+1; i--){
        // newpoints = max(newpoints, );?
        points -= vec[right];
        points += vec[i];
        newP = max(newP, points);
        right--;
    }

    cout << "maxpoint: " << newP;

}

int main(){
        
    vector<int> vec = {6, 2, 3, 4, 7, 2, 1, 7, 1};
    int k = 4;
    maximumPoints(vec,k);
}
