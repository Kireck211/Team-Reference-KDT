#include <bits/stdc++.h>
using namespace std;
 
vector<long long int> prime; 
void simpleSieve(long long int limit, vector<long long int> &prime)
{
    bool mark[limit+1];
    memset(mark, true, sizeof(mark));
    for (long long int p=2; p*p<limit; p++)
    {
        if (mark[p] == true)
        {
            for (long long int i=p*2; i<limit; i+=p)
                mark[i] = false;
        }
    }
    for (long long int p=2; p<limit; p++)
    {
        if (mark[p] == true)
        {
            prime.push_back(p);
        }
    }
}
void segmentedSieve(long long int n)
{
    long long int limit = floor(sqrt(n))+1; 
    simpleSieve(limit, prime); 
    long long int low  = limit;
    long long int high = 2*limit;
    while (low < n)
    {
        bool mark[limit+1];
        memset(mark, true, sizeof(mark));
        for (long long int i = 0; i < prime.size(); i++)
        {
            long long int loLim = floor(low/prime[i]) * prime[i];
            if (loLim < low)
                loLim += prime[i];
            for (long long int j=loLim; j<high; j+=prime[i])
                mark[j-low] = false;
        }
        for (long long int i = low; i<high; i++)
            if (mark[i - low] == true)
                prime.push_back(i);
        low  = low + limit;
        high = high + limit;
        if (high >= n) high = n;
    }
} 
int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n, s;
    cin>>n;
    segmentedSieve(n);
    s=prime.size();
    for(int i=0; i<s; i++)
    {
       cout<<prime[i]<<endl;
    }
    return 0;
}

// Taken from https://github.com/Aksh77/ACM-Team-Notebook