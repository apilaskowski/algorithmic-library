#include <iostream>
#include <algorithm>
using namespace std;

int kmp(string text, string pattern) {

    // Step 0. Should not be empty string
    if( text.size() == 0 || pattern.size() == 0)
        return -1;

    // Step 1. Compute failure function
    int failure[pattern.size()];
    std::fill( failure, failure+pattern.size(), -1);

    for(int r=1, l=-1; r<pattern.size(); r++) {

        while( l != -1 && pattern[l+1] != pattern[r])
            l = failure[l];

        // assert( l == -1 || pattern[l+1] == pattern[r]);
        if( pattern[l+1] == pattern[r])
            failure[r] = ++l;
    }

    // Step 2. Search pattern
    int suffix = -1;
    for(int i=0; i<text.size(); i++) {

        while( suffix != -1 && text[i] != pattern[suffix+1])
            suffix = failure[suffix];

        if( text[i] == pattern[suffix+1])
            suffix++;

        if( suffix == pattern.size()-1)
            return i - suffix;
    }
    return -1;
}

int main() {
    cout << kmp("aaaaaaaaab", "ab") << endl;
    cout << kmp("aaaaaaaaaa", "aa") << endl;

    return 0;
}
