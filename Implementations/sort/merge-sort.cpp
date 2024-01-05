void merge(int ini, int fim){
	if(ini==fim) return;
	
	int m=(ini+fim)/2;
	merge(ini, m);
	merge(m+1, fim);
	
	int l=ini, r=m+1;
	for(int i=ini; i<=fim; i++){
		if(r>fim || (l<=m && v[l]<v[r])){
			aux[i]=v[l];
			l++;
			//inv+=(r-m-1);
		} else {
			aux[i]=v[r];
			r++;
			//inv+=(m-l+1);
		}
	}
	for(int i=ini; i<=fim; i++) v[i]=aux[i];
}
