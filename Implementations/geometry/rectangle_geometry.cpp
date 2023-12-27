// (x1, y1) -> bottom left
// (x2, y2) -> top right
// increasing x moves right
// uncreasing y moves up
struct rect{
	int x1, y1, x2, y2;
	int area() {return (x2-x1)*(y2-y1);}
};

bool itc(rect a, rect b){
	if(a.x2<=b.x1 || a.x1>=b.x2 || a.y2<=b.y1 || a.y1>=b.y2) return false;
	return true;
}

int itc_area(rect a, rect b){
	int x=max(min(a.x2, b.x2)-max(a.x1, b.x1), 0);
	int y=max(min(a.y2, b.y2)-max(a.y1, b.y1), 0);
	return x*y;
}
