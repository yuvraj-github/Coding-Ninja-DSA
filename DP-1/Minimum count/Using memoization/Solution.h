int minCountHelper(int n, int *arr) {
    if(sqrt(n)-floor(sqrt(n)) == 0) {
        arr[n]=1;
        return arr[n];
    }
    if(n<=3) {
        arr[n] = n;
        return arr[n];
    }
    if(arr[n] != -1) {
        return arr[n];
    }
    int ans = n;
    for(int i=1; i*i<=n; i++) {
        ans = min(ans, 1+minCountHelper(n-i*i, arr));
        arr[n]=ans;
    }
    return arr[n];
}
int minCount(int n)
{
	//Write your code here
    int *arr = new int[n+1];
    for(int i=0; i<=n; i++) {
        arr[i] = -1;
    }
    return minCountHelper(n, arr);
}