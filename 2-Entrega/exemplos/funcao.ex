int main(){
	
	int meda1(int a){
		int b=2;

		int meda2(int d){
			return b*d;
		}
		return meda2(a);
	}
	int meda3(int a, int b, int c){
		return a*b, b, c;
	}

	int	d,e,f = meda3(1, 2, 3);
	write(d);
	
	
	int g = meda1(1);
	write(g);

	g = 2 + meda3(1,2,3) + meda1(5) + meda1(4);

	write(g);

}