// encontra menor indice com valor > x
// caso x seja maior que todos os valores, sera retornado n

void upb(int x){
	int l=-1; //l<=x
	int r=n;  //r>x
	while(r>l+1){
		int m=(l+r)/2;
		if(v[m]<=x){
			l=m;
		} else {
			r=m;
		}
	}
	return r;
}
