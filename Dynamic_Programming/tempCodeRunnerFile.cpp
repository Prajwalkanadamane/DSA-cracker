

int main(){

    string a = "adebc";
    string b = "dcadb";

    int n = a.size();
    int m = b.size();
    vector<vector<int>> DP(n, vector<int>(m, -1));

    cout << "Longest common substring is of lenght: " << f (n-1, m-1, a, b) << endl;
    cout << "Longest common substring is of lenght: " << f2 (n-1, m-1, a, b, DP)<< endl;
    cout << "Longest common substring is of lenght: " << f3 (a, b)<< endl;

    return 0;
}
