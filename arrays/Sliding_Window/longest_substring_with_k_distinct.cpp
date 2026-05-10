#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int kDistinctChar(string &s, int k)
{
    
    unordered_map<int, int> map;
    int left = 0, right = 0, maxC = 0;

    for (right = 0; right < s.size(); right++)
    {

        map[s[right]]++;

        if (map.size() > k)
        {
            map[s[left]]--;
            if (map[s[left]] == 0){

                map.erase(s[left]);
            }
                
            left++;
        }

        if (map.size() <= k)
        {
            maxC = max(maxC, right - left + 1);
        }
    }
    return maxC;
}

int main()
{

    string s = "aababbcaacc";
    int k = 2;

    int a = kDistinctChar(s, k);
    cout << a;

    return 0;
}