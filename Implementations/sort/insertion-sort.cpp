// Time Complexity: O(n^2)

    for(int i=1; i<n; i++){
        for(int j=i; j>0; j--){
            if(v[j]<v[j-1]){
                swap(v[j], v[j-1]);
            } else {
                break;
            }
        }
    }
