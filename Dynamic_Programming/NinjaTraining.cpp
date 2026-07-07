#include<iostream>
#include<vector>
using namespace std;

int ninjaTraining(int day, int last, vector<vector<int>>& points){

    if (day == 0){

        int maxi = 0;
        for (int task = 0; task < 3; task++){
            if (task != last) maxi = max(maxi, points[0][task]);
        }
        return maxi;
    }

    int maxi = 0;

    for (int task = 0; task < 3; task++){
        if (task != last){
            int point = points[day][task] + ninjaTraining(day-1, task, points);
            maxi = max(maxi, point);
        }
    }
    return DP[day][last] = maxi;

}

int main(){

    vector<vector<int>> points = {{10, 11, 19},{4, 13, 7},{1, 8, 13}};  

    cout << "Maximum points obtaining path is: " << ninjaTraining(points.size()-1, 3, points) << endl;                            
    
    return 0;
}