// Time Complexity: O(n^2)
// The algorithm can only swap consecutive elements, and each swap removes at most one inversion
// In the worst case (reverse order) the number of inversions will be:
// 1+2+...+(n+1) = n*(n-1)/2 = O(n^2)

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
