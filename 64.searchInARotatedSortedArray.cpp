int search(int* arr, int n, int key) {
    // Write your code here.
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] >= arr[low]){
            if(key >= arr[low] && key <= arr[mid-1]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        else{
            if(key <= arr[high] && key >= arr[mid+1]){
                low = mid + 1;
            }
            else{
                high = mid-1;
            }
        }
    }
    return -1;
}