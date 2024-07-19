#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
       int n = s.size() - 1;
       char p = ' ';
       int l;
       for (int i = n; i >= 0; i--) {
           if (s[i] != p) {
               l = i;
               break;
           }
       }
       int count = 0;
       for (int i = l; i >= 0; i--) {
           if (s[i] == p)
               break;
           count++;
       }
       return count;
    }
};

int main() {
    Solution solution;
    string s;

   cout << "Enter a string: ";
    getline(cin, s);

    int length = solution.lengthOfLastWord(s);
    cout << "Length of the last word: " << length << endl;

    return 0;
}
