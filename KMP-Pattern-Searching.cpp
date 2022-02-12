//KMP (Knuth Morris Pratt) Pattern searching Algorithm

#include <bits/stdc++.h>

using namespace std;


int solve(string str1, string str2)
{
    string s = "";
    int count = 0,n,m;
    n = str1.length();
    m = str2.length();
    int lps[m],i,j=0;
    //Make one lps[] array which is longest proper prefix which is also a suffix
    
    lps[0] = 0;
    for(int i = 0;i<m;i++)
    {
           if(i==0)
            {
                    lps[i] = 0;
                    cout<<lps[i]<<"\t";
                    continue;
            }
        
        if(str2[i]==str2[j])
        {
            lps[i] = ++j;
            
        }
        else
        {
            lps[i] = 0;
            j = 0;
        }
        cout<<lps[i]<<"\t";
    }

    i = 0;
    j = 0;
    while(i<n)
    {
        if(str1[i]==str2[j])
        {
            i++;j++;
        }
        else if(str1[i]!=str2[j] && j>0)
        {
            j = lps[j-1];   // Important to remember
        }
        else if(str1[i]!=str2[j] && j==0)
            i++;

        if(j==m)
        {
            count++;
            j=lps[j-1];
        }
        

    }
    cout<<endl;
    return count;
}

int main() 
{
string s1 = "AAAAABAAABA";
string s2 = "AAAA";
cout<<solve(s1,s2);
return 0;

}