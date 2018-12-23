int maxSum = A[0];
        int sum = A[0];
        for(int i = 1; i<n; ++i)
        {
            if(sum < 0) // no positive gain for following numbers
                sum = 0;
            sum += A[i];
            if(sum > maxSum)
                maxSum = sum;
        }
        