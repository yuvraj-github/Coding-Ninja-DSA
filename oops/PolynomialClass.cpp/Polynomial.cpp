
class Polynomial
{
public:
    int *degCoeff; // Name of your array (Don't change this)
    int capacity;
    Polynomial()
    {
        degCoeff = new int[5];
        capacity = 5;
        for (int i = 0; i < capacity; i++)
        {
            degCoeff[i] = 0;
        }
    }
    Polynomial(int capacity)
    {
        this->degCoeff = new int[capacity];
        this->capacity = capacity;
    }
    void setCoefficient(int degree, int coefficient)
    {
        if (degree > capacity - 1)
        {
            int newCapacity = degree + 1;
            int *newDegCoeff = new int[newCapacity];
            for (int i = 0; i < newCapacity; i++)
            {
                newDegCoeff[i] = 0;
            }
            for (int i = 0; i < capacity; i++)
            {
                newDegCoeff[i] = degCoeff[i];
            }
            newDegCoeff[degree] = coefficient;
            delete[] degCoeff;
            degCoeff = newDegCoeff;
            capacity = newCapacity;
        }
        else
        {
            degCoeff[degree] = coefficient;
        }
    }
    Polynomial operator+(Polynomial const &p2)
    {
        int newCapacity = max(capacity, p2.capacity);
        Polynomial p3(newCapacity);
        for (int i = 0; i < newCapacity; i++)
        {
            if (i < capacity && i < p2.capacity)
            {
                p3.degCoeff[i] = degCoeff[i] + p2.degCoeff[i];
            }
            else if (i < capacity)
            {
                p3.degCoeff[i] = degCoeff[i];
            }
            else
            {
                p3.degCoeff[i] = p2.degCoeff[i];
            }
        }
        return p3;
    }
    Polynomial operator-(Polynomial const &p2)
    {
        int newCapcity = max(capacity, p2.capacity);
        Polynomial p3(newCapcity);
        for (int i = 0; i < newCapcity; i++)
        {
            if (i < capacity && i < p2.capacity)
            {
                p3.degCoeff[i] = degCoeff[i] - p2.degCoeff[i];
            }
            else if (i < capacity)
            {
                p3.degCoeff[i] = degCoeff[i];
            }
            else
            {
                p3.degCoeff[i] = p2.degCoeff[i];
            }
        }
        return p3;
    }
    Polynomial(Polynomial const &p)
    {
        for (int i = 0; i < p.capacity; i++)
        {
            degCoeff[i] = p.degCoeff[i];
        }
        capacity = p.capacity;
    }
    void operator=(Polynomial const &p)
    {
        for (int i = 0; i < p.capacity; i++)
        {
            degCoeff[i] = p.degCoeff[i];
        }
        capacity = p.capacity;
    }
    Polynomial operator*(Polynomial const &p) {
        int newCapcity = capacity+p.capacity;
        Polynomial p3(newCapcity);
        for(int i=0; i<capacity; i++) {
            for(int j=0; j<p.capacity; j++) {
                p3.degCoeff[i+j] += degCoeff[i]*p.degCoeff[j];
            }
        }
        return p3;
    }
    void print()
    {
        for (int i = 0; i < capacity; i++)
        {
            if (degCoeff[i] != 0)
            {
                cout << degCoeff[i] << "x" << i << " ";
            }
        }
        cout << endl;
    }
};