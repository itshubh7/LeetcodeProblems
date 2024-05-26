int maxProfit(int* arr, int n) {
    int profit=0;
    int buy=arr[0];
    for(int i=1; i<n; i++)
    {
       if(buy>arr[i])
           buy=arr[i];
        if(profit<arr[i]-buy)
            profit=arr[i]-buy;
    }
    return profit;
}