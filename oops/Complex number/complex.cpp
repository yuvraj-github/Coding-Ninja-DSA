class ComplexNumbers {
    private:
        int real;
        int imaginary;
    public:
        ComplexNumbers(int r, int im) {
            real = r;
            imaginary = im;
        }
         void print() {
            cout << real << " " << "+" << " " << "i" << imaginary << endl;
         }
         void plus(ComplexNumbers c2) {
            real = real+c2.real;
            imaginary = imaginary+c2.imaginary;           
         }
         void multiply(ComplexNumbers c2) {
            int realNumb = real * c2.real - imaginary * c2.imaginary;
            int imagNumb = real * c2.imaginary + imaginary * c2.real;
            real = realNumb;
            imaginary = imagNumb;
         }
};