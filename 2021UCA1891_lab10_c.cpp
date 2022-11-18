/*"I have done this assignment on my own. I have not copied any code from
another student or any online source. I understand if my code is found
similar to somebody else's code, my case can be sent to the Disciplinary
committee of the institute for appropriate action."*/

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int main()
{
    int flag = 0; // FLAG TO CHECK IF PATTERN IS FOUND
    string text;
    getline(cin, text);
    string pattern;
    getline(cin, pattern);
    int n = text.size();
    int m = pattern.size();
    vector<int> preprocess(m + 1); // PREPROCESS ARRAY
    // MAKING PREPROCESS ARRAY
    int i = 0, j = -1;
    preprocess[i] = j;
    while (i < m)
    {
        while (j >= 0 && pattern[i] != pattern[j])
            j = preprocess[j];
        i++;
        j++;
        preprocess[i] = j;
    }
    // for (int i = 0; i < m+1; i++)
    // {
    //     cout << preprocess[i] << " ";
    // }
    // cout << endl;

    // KMP algorithm
    i=0;
    j=0;
    while (i < n)
    {
        while (j >= 0 && text[i] != pattern[j])

            j = preprocess[j];
        i++;
        j++;
        if (j == m)
        {
            flag=1;
            cout<<"Found at index:"<<i-j<<endl;
            j = preprocess[j];
        }
    }
    if (flag == 0)
    {
        cout << "Not exist";
    }
    return 0;
}