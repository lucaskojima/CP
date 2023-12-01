// encontra maior indice com valor < x
// caso x seja menor que todos os valores, sera retornado -1

void rupb(int x){
	int l=-1; //l<x
	int r=n;  //r>=x
	while(r>l+1){
		int m=(l+r)/2;
		if(v[m]<x){
			l=m;
		} else {
			r=m;
		}
	}
	return l;
}
