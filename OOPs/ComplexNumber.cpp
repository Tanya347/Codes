class ComplexNumbers {
    // Complete this class
    int r;
    int c;
    
    public:
    ComplexNumbers(int r, int c) {
        this -> r = r;
        this -> c = c;
    }
    
    void print();
    void plus(ComplexNumbers const &);
    void multiply(ComplexNumbers const &);
};

void ComplexNumbers :: print() {
    cout<<r<<" + i"<<c;
}

void ComplexNumbers :: plus(ComplexNumbers const &f2) {
    r = r + f2.r;
    c = c + f2.c;
}

void ComplexNumbers :: multiply(ComplexNumbers const &f2) {
	int real = r*f2.r - c*f2.c;
    int imaginary = r*f2.c + c*f2.r;
    r = real;
    c = imaginary;
}
