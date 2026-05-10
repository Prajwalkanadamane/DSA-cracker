#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void trappingRainwater(vector<int> heights){
    int n = heights.size();
    vector<int> lMax(n,0);
    vector<int> rMax(n,0);

    lMax[0] = heights[0];
    rMax[n-1] = heights[n-1];

    for (int i=1; i<n; i++){
        lMax[i] = max(lMax[i-1], heights[i]);
    }

    for (int i=n-2; i>=0; i--){
        rMax[i] = max(rMax[i+1], heights[i]);
    }

    int ans = 0;
    for (int i=0; i<n; i++){
        ans+= (min(lMax[i], rMax[i]) - heights[i]);
    }
    cout << "maximum litres of water that can be trapped: " << ans << " litres.." << endl;

}


int main(){
    
    vector<int> heights = {4, 2, 0, 3, 2, 5};
    trappingRainwater(heights);
    return 0;
}
