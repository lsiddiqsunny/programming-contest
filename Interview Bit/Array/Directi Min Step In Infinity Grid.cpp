

int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    
    int stepCount = 0; 
  
    // finding steps for each 
    // consecutive point in the sequence 
    for (int i = 0; i < A.size()-1; i++) { 
        stepCount += max(abs(A[i]-A[i+1]),abs(B[i]-B[i+1]));
    } 
  
    return stepCount; 
    
}
