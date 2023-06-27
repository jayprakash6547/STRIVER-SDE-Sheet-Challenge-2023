int singleNonDuplicate(vector<int>& arr)
{
	int left=0,right=arr.size()-2;
	while(left<=right){
		int mid=(left+right)/2;
		if(arr[mid]==arr[mid^1]){
			left=mid+1;
		}else{
			right =mid-1;
		}
	}
	return arr[left];
}


