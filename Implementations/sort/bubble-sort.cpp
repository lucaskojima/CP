// Time Complexity: O(n^2)

	bool ok=false;
	while(!ok){
		ok=true;
		for(int i=0; i<n-1; i++){
			if(v[i]>v[i+1]){
				swap(v[i], v[i+1]);
				ok=false;
			}
		}
	}
