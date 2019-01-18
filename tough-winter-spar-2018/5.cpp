#include<bits/stdc++.h>
using namespace std;



map<string,string>mp;
char mpn[12];
int test;
int n,m;
string s1,s2;
string arr[12];
string x,y;
char c;

map<char,int>mpn1;
void computeLPSArray(string pat, int M, int* lps);

// Prints occurrences of txt[] in pat[]
int KMPSearch(string pat, string txt,int* lps,int pos)
{
    int co=0;
    int M = pat.size();
    int N = txt.size();





    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while (i < N)
    {
        if (pat[j] == mpn[(mpn1[txt[i]]+pos)%12])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            return 1;
        }

        // mismatch after j matches
        else if (i < N && pat[j] != mpn[(mpn1[txt[i]]+pos)%12])
        {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return 0;
}

// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(string pat, int M, int* lps)
{
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0)
            {
                len = lps[len - 1];

                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}





int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    mp["A"]="A";
    mp["A#"]="H";
    mp["B"]="B";
    mp["C"]="C";
    mp["C#"]="I";
    mp["D"]="D";
    mp["D#"]="J";
    mp["E"]="E";
    mp["F"]="F";
    mp["F#"]="K";
    mp["G"]="G";
    mp["G#"]="L";
    int i=0;
    for(auto x:mp)
    {
        char c=x.second[0];
        mpn[i]=c;
        mpn1[c]=i;
        i++;
    }
    cin>>test;
    for(int cs=1; cs<=test; cs++)
    {

        cin>>n>>m;
        x="";

       char C;
        for(int i=0; i<n; i++)
        {
            cin>>s1;
            x+=mp[s1];
          //  x+=z;

        }
        // cout<<x<<endl;


        y="";
        for(int i=0; i<m; i++)
        {
            cin>>s2;
            y+=mp[s2];


        }
        //  cout<<y<<endl;

        int lps[y.size()];
        computeLPSArray(y, y.size(), lps);
        int ok=0;
        for(int i=0; i<12; i++)
        {
            // cout<<arr[i]<<endl;
            int num=KMPSearch(y,x,lps,i);
            if(num>0)
            {
                ok=1;
                break;
            }
        }
        if(ok)
        {
            printf("Case %d: yes\n",cs);
        }
        else
        {
            printf("Case %d: no\n",cs);
        }
    }


}
