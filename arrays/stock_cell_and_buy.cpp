// // Brute force(Big O(n^2))

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int stock(vector<int> &prices){

//     int maxP = 0;
//     int current_price = 0;
//     int n = prices.size();

//     for(int i=0; i<n; i++){
//         for (int j=i+1; j<n; j++){
//             current_price = prices[j] - prices[i];
//             maxP = max(maxP, current_price);
//             if (maxP == current_price){
     
//             }
//         }
//     }
//     return maxP;
// }



// int main(){
//     vector<int> prices= {7, 1, 5, 3, 6, 4};

//     cout << "majority element is: " << stock(prices);

//     return 0;
// }

// // Big O(n)

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <climits>
// using namespace std;

// int stock(vector<int> &prices){

//     int maxP = 0;
//     int minV = INT_MAX;
//     int current_price = 0;
//     int n = prices.size();

//     for(int i=0; i<n; i++){

//         minV = min( minV,prices[i]);
//         maxP = max(maxP, prices[i] - minV);
        
//     }p
//     return maxP;
// }



// int main(){
//     vector<int> prices= {7, 1, 5, 3, 6, 4};

//     cout << "max profit is: " << stock(prices);

//     return 0;
// }


// or Big O(n)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int stock(vector<int> &prices){

    int maxP = 0;
    int bestBuy = prices[0];
    int current_price = 0;
    int n = prices.size();

    for(int i=1; i<n; i++){
        if (prices[i]>bestBuy){
            maxP = max(maxP,prices[i]-bestBuy);
        }
        bestBuy = min(bestBuy,prices[i]);
    }      
    return maxP;
}



int main(){
    vector<int> prices= {7, 1, 5, 3, 6, 4};

    cout << "max profit is: " << stock(prices);

    return 0;
}