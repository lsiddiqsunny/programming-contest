//
//  main.cpp
//  CodeForces,281
//
//  Created by james porcelli on 12/3/14.
//  Copyright (c) 2014 james porcelli. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main(int argc, const char * argv[])
{
    int n, m;
    scanf("%d", &n);

    set<int> nums;

    vector<int> a;
    for(int i = 0 ; i < n; i++){
        int x;
        scanf("%d", &x);
        a.push_back(x);
        nums.insert(x);
    }

    scanf("%d", &m);
    vector<int> b;
    for(int i = 0; i < m; i++){
        int x;
        scanf("%d", &x);
        b.push_back(x);
        nums.insert(x);
    }

    int bd, ba, bb, d, sb, sa;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    bd = -1;

    nums.insert(0);
    vector<int> alld(nums.begin(), nums.end());

    for(int i = 0; i < alld.size(); i++){
        d = alld[i];

        int am = upper_bound(a.begin(), a.end(), d) - a.begin();
        int bm = upper_bound(b.begin(), b.end(), d) - b.begin();

        sa = am*2 + (n-am)*3;
        sb = bm*2 + (m-bm)*3;

        int dif = sa-sb;

        if(bd == -1 || dif > bd){
            bd = dif;
            ba = sa;
            bb = sb;

        }else if(dif == bd && sa > ba){
            ba = sa;
            bb = sb;
        }
    }


    printf("%d:%d\n", ba, bb);

    return 0;
}
