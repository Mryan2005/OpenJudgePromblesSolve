#include<bits/stdc++.h>
using namespace std;
array<string, 60> stu;
int main() {
    int n;
    string standard;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        cin >> stu[i];
    }
    cin >> standard;
    for(int i = 0, j = 0, k = 0; i < n; ++i) {
        int flag = 0;
        for(; standard[j] != '['; ++j, ++k) {
            if(standard[j] <= 'z' && standard[j] >= 'a' && (standard[j] == stu[i][k] || standard[j] == stu[i][k]+32));
            else if(standard[j] <= 'Z' && standard[j] >= 'A' && (standard[j] == stu[i][k]-32 || standard[j] == stu[i][k]));
            else goto out;
        }
        for(j += 1; standard[j] != ']'; ++j) {
            if(standard[j] <= 'z' && standard[j] >= 'a' && (standard[j] == stu[i][k] || standard[j] == stu[i][k]+32)) flag = 1;
            else if(standard[j] <= 'Z' && standard[j] >= 'A' && (standard[j] == stu[i][k]-32 || standard[j] == stu[i][k])) flag = 1;
            else if(standard[j] == stu[i][k])flag = 1;
        }
        if(flag == 0 || ++k > stu[i].size()) goto out;
        for(j += 1; j < standard.size(); ++j, ++k) {
            if(standard[j] <= 'z' && standard[j] >= 'a' && (standard[j] == stu[i][k] || standard[j] == stu[i][k]+32));
            else if(standard[j] <= 'Z' && standard[j] >= 'A' && (standard[j] == stu[i][k]-32 || standard[j] == stu[i][k]));
            else goto out;
        }
        cout << i+1 << " " << stu[i] << endl;
        out:;
        k = j = 0;
    }

}