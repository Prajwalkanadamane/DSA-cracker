#include <iostream>
using namespace std;
#include <vector>

// int main(){
//     // pair<string, int> p = {"virat_kohli",18};
//     pair<string, pair<int, string>> p = {"virat",{18," kohli"}};
//     cout << p.first << " ";
//     cout << p.second.first;
//     cout << p.second.second << endl;
//     return 0;
// }

int main(){
    vector<pair<int,int>> vec = {{1,2}, {3,4}, {5,6}};

    vec.push_back({4,5}); //insert
    vec.emplace_back(4,5); //in-place objects create

    for (auto val:vec){
        cout << val.first << " " << val.second << endl;
    }
    return 0;
}