vector<int> Solution::plusOne(vector<int> &A) {
    vector<int>B,ans;
    int carry=1;
    for(int i=A.size()-1;i>=0;i--){
        if(A[i]==9 and carry==1){
            B.push_back(0);
            carry=1;
        }
        else if(carry==1){
            B.push_back(A[i]+1);
            carry=0;
        }
        else B.push_back(A[i]);
    }
    if(carry){
        B.push_back(1);
    }
    reverse(B.begin(),B.end());
    int ok=0;
    
    for(int i=0;i<B.size();i++){
        if(B[i]==0 and ok==0){
            continue;
        }
        ok=1;
        ans.push_back(B[i]);
    }
    return ans;
}

