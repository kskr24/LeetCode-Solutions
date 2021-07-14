class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int n=arr.size();

    int l=-1,r=n,mid;
    while(r>l+1){
        mid=(l+r)/2;
        if(arr[mid]<=x)
            l=mid;
        else
            r=mid;
    }
    //remove elements that are equal to n
    //while(l>=0&&arr[l]==m)
    //    l--;
    //Slide the window as per need
    while(k&&(l>-1||r<n)){
        if(r==n || (l>=0 && abs(x-arr[l])<=abs(arr[r]-x))){
            l--;
            k--;
        }
        else{
            r++;
            k--;
        }
    }
    vector<int>res;
    for(int j=l+1;j<r;j++){
        res.push_back(arr[j]);
    }
        return res;
    }
};
