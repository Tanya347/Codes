using namespace std;

void copySetBits(unsigned &x, unsigned y, unsigned l, unsigned r) {
    
    if(l < 1 || r > 32)
        return;
        

    for(int i = l; i <= r; i++) {
        
        //keep creating a mask for every ith position in the range of l and r
        int mask = 1 << (i - 1);
        
        //check if its on or off
        if(y & mask)
        
            //turn on the bit in x if it is on
            x = x | mask;
    }
    
}

int main() {
    unsigned x, y, l, r;
    cin>>x>>y>>l>>r;
    
    copySetBits(x,y,l,r);
    cout<<x;
	return 0;
}
