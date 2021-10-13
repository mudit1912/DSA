// Knuth Morris Pratt Algorithm is a type of String Matching algorithm .The time complexity of KMP is O(n)..

#include <bits/stdc++.h> 
using namespace std;
         
void lps_func(string txt, vector<int>&Lps){
    Lps[0] = 0;                   
    int len = 0;
    int i=1;
    while (i<txt.length()){
        if(txt[i]==txt[len]){   
            len++;
            Lps[i] = len;
            i++;
            continue;
        }
        else{                   
            if(len==0){         
                Lps[i] = 0;
                i++;
                continue;
            }
            else{              
                len = Lps[len-1];
                continue;
            }
        }
    }
}


void KMP(string pattern,string text){
    int n = text.length();
    int m = pattern.length();
    vector<int>Lps(m);
    
    lps_func(pattern,Lps); // This function constructs the Lps array.
    
    int i=0,j=0;
    while(i<n){
        if(pattern[j]==text[i]){i++;j++;} // If there is a match continue.
        if (j == m) { 
            cout<<i - m <<' ';   
                                  
            j = Lps[j - 1]; 
        } 
        else if (i < n && pattern[j] != text[i]) {
            if (j == 0)          
                i++;
            else
                j = Lps[j - 1];  
        }
    }
}
int main()
{
    string text = "ababcdabcb";
    string pattern = "abc";
    KMP(pattern, text);
    
    return 0; 
}
