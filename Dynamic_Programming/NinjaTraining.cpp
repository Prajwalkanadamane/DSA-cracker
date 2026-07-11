#include<iostream>
#include<vector>
using namespace std;

int ninjaTraining(int day, int last, vector<vector<int>>& points, vector<vector<int>>& DP){

    if (day == 0){

        int maxi = 0;
        for (int task = 0; task < 3; task++){
            if (task != last) maxi = max(maxi, points[0][task]);
        }
        return maxi;
    }

    if (DP[day][last] != -1) return DP[day][last];

    int maxi = 0;

    for (int task = 0; task < 3; task++){
        if (task != last){
            int point = points[day][task] + ninjaTraining(day-1, task, points, DP);
            maxi = max(maxi, point);
        }
    }
    return DP[day][last] = maxi;

}

int main(){

    vector<vector<int>> points = {{10, 11, 19},{4, 13, 7},{1, 8, 13}};  

    vector<vector<int>> DP(points.size(), vector<int>(4, -1));

    cout << "Maximum points obtaining path is: " << ninjaTraining(points.size()-1, 3, points, DP) << endl;                            
    
    return 0;
}