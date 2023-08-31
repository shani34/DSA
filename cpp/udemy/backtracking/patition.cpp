#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(const string& s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void backtrack(vector<vector<string> >& result, vector<string>& current, const string& s, int start) {
    if (start == s.length()) {
        result.push_back(current);
        return;
    }

    for (int end = start; end < s.length(); end++) {
        if (isPalindrome(s, start, end)) {
            current.push_back(s.substr(start, end - start + 1));
            backtrack(result, current, s, end + 1);
            current.pop_back();
        }
    }
}

vector<vector<string> > partition(string s) {
    vector<vector<string> > result;
    vector<string> current;
    backtrack(result, current, s, 0);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j];
        }
        cout<<endl;
    }

    return result;
}

int main() {
    string s ;
    cin>>s;
    vector<vector<string> > result = partition(s);

    // for (const vector<string>& partition : result) {
    //     cout << "[";
    //     for (int i = 0; i < partition.size(); i++) {
    //         cout << "\"" << partition[i] << "\"";
    //         if (i < partition.size() - 1) {
    //             cout << ",";
    //         }
    //     }
    //     cout << "]" << endl;
    // }
 
    return 0;
}
