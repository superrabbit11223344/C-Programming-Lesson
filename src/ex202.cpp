#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValid(string path, vector<string>& preferences) {
    for (int i = 0; i < path.size(); i++) {
        string s = path.substr(i, 1);
        int bookIndex = stoi(s);
        if (preferences[i][bookIndex] != '1') {
            return false;
        }
    }
    return true;
}

vector<string> result;
void backtracking(vector<int>& books, string path, vector<bool>& used, vector<string>& preferences, int index) {
    if (path.size() >= books.size()) {
        result.push_back(path);
        return ;
    }

    for (int i = 0; i < books.size(); i++) {
        if (preferences[index][i] != '1' || used[i] == true) continue;
        else {
            used[i] = true;
            backtracking(books, path + to_string(books[i]), used, preferences, index + 1);
            used[i] = false;
        }
        
    }
    return ;
}

int main() {
    int n;  // 几个人
    cin >> n;
    string k;
    vector<string> preferences;    // 每个人喜欢什么书
    for (int i = 0; i < n; i++) {
        cin >> k;
        preferences.push_back(k);
    }
    vector<int> books;  // 表示书的一种排列，即{0, 1, ..., n - 1}
    for (int i = 0; i < n; i++) {
        books.push_back(i);
    }
    
    string path;
    vector<bool> used(n, false);
    backtracking(books, path, used, preferences, 0);

    if (result.size() == 0) {
        cout << "NO" << endl;
        return 0;
    }

    cout << result.size() << endl;

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < n; j++) {
            int bookNum = int(result[i][j] - '0') + 1;
            cout << "B" << bookNum << "";
        }
        cout << endl;
    }

}