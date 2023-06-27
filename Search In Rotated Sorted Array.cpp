int search(int* arr, int n, int key) {
    int left=0,right=n-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(arr[mid]==key)return mid;
        if(arr[left]<=arr[mid]){
            if(key>=arr[left] && key<arr[mid]){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        else if(arr[left]>=arr[mid]){
            if(key>arr[mid]&&key<=arr[right]){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
    }
    return -1;
}