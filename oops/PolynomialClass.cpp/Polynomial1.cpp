class Polynomial {
    public:
    
    int *degCoeff;      // Name of your array (Don't change this)
    
    // Complete the class
    int capacity;
    
    //default constructor
    public:
    Polynomial(){
        capacity=5;
        degCoeff=new int[5];
        for(int i=0;i<capacity;i++)
            degCoeff[i]=0;
    }
    
    //copy constructor
    Polynomial(Polynomial const &p)
    {
    	degCoeff=new int[p.capacity];
        
        for(int i=0;i<p.capacity;i++)
            degCoeff[i]=p.degCoeff[i];
        
        capacity=p.capacity;
    }
    
    //set coefficient
    void setCoefficient(int degree , int coeff)
    {
        if(degree>=capacity)
        {
            int *newdegCoeff=new int[2*capacity];
            
            for(int i=0;i<capacity;i++)
                newdegCoeff[i]=degCoeff[i];
            
            for(int i=capacity;i<2*capacity;i++)
                newdegCoeff[i]=0;
            
            delete [] degCoeff;
            degCoeff=newdegCoeff;
            capacity=capacity*2;
            setCoefficient(degree,coeff);
        }
            
        else
            degCoeff[degree]=coeff;
    }
    
    // +
    
    Polynomial operator+(Polynomial &p)
    {
        Polynomial result;
        int i;
        for(i=0;i<capacity && i<p.capacity;i++)
        {
            if(degCoeff[i]!=0 || p.degCoeff[i]!=0)
            	result.setCoefficient(i,degCoeff[i]+p.degCoeff[i]);
        }
        while(i<capacity)
        {
            if(degCoeff[i]!=0)
                result.setCoefficient(i,degCoeff[i]);
            i++;
        }
        while(i<p.capacity)
        {
            if(p.degCoeff[i]!=0)
                result.setCoefficient(i,p.degCoeff[i]);
            i++;
        } 
            
        return result;
        
    }
    
    // -
    
    Polynomial operator-(Polynomial &p)
    {
        Polynomial result;
        int i;
        for(i=0;i<capacity && i<p.capacity;i++)
        {
            if(degCoeff[i]!=0 || p.degCoeff[i]!=0)
            	result.setCoefficient(i,degCoeff[i]-p.degCoeff[i]);
        }

        while(i<capacity)
        {
            if(degCoeff[i]!=0)
                result.setCoefficient(i,degCoeff[i]);
            i++;
        }
        while(i<p.capacity)
        {
            if(p.degCoeff[i]!=0)
                result.setCoefficient(i,0-p.degCoeff[i]);
            i++;
        }
        return result;
    }
    
    // *
    
    Polynomial operator*(Polynomial &p)
        
    {
        Polynomial result;
        for(int i=0;i<capacity;i++)
        {
            for(int j=0;j<p.capacity;j++)
            {
                if(degCoeff[i]!=0 && p.degCoeff[j]!=0)
                {
					if(i+j<result.capacity)
                        result.setCoefficient(i+j,result.degCoeff[i+j]+degCoeff[i]*p.degCoeff[j]);
                    else
                        result.setCoefficient(i+j,degCoeff[i]*p.degCoeff[j]);
                }
            		
            }
            
        }
        return result;
        
    }
    
    void operator=(Polynomial const &p)
    {
    	degCoeff=new int[p.capacity];
        
        for(int i=0;i<p.capacity;i++)
            degCoeff[i]=p.degCoeff[i];
        
        capacity=p.capacity;
          
    }
    
    void print()
    {
        for(int i=0;i<capacity;i++)
        {
            if(degCoeff[i]!=0)
				cout<<degCoeff[i]<<"x"<<i<<" ";
        }
        cout<<endl;
    }
};

