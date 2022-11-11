#include <vector>

class PriorityQueue
{
    vector<int> pq;

public:
    bool isEmpty()
    {
        return pq.size() == 0;
    }

    int getSize()
    {
        return pq.size();
    }

    int getMin()
    {
        if (isEmpty())
        {
            return 0;
        }

        return pq[0];
    }

    void insert(int element)
    {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
            {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin()
    {
        // Write your code here       
        if (pq.size() == 0)
            return -1;
        int m = pq[0]; 

        int lastindex = pq.size() - 1;

        int temp = pq[0]; 
        pq[0] = pq[lastindex];
        pq[lastindex] = temp;

        pq.pop_back();     

        int i = 0;
        while (i < pq.size()) 
        {
            if (2 * i + 1 >= pq.size())
                break;

            else
            {
                if (2 * i + 2 >= pq.size())
                    if (pq[i] > pq[2 * i + 1])
                    {
                        int temp = pq[i];
                        pq[i] = pq[2 * i + 1];
                        pq[2 * i + 1] = temp;
                        i = 2 * i + 1;
                    }
                    else
                        break;
                else
                {

                    if (pq[i] > min(pq[2 * i + 1], pq[2 * i + 2]))

                    { 
                        if (pq[2 * i + 1] > pq[2 * i + 2])
                        {
                            int temp = pq[i];
                            pq[i] = pq[2 * i + 2];
                            pq[2 * i + 2] = temp;
                            i = 2 * i + 2;
                        }

                        else
                        {

                            int temp = pq[i];
                            pq[i] = pq[2 * i + 1];
                            pq[2 * i + 1] = temp;
                            i = 2 * i + 1;
                        }
                    }
                    else
                        break;
                }
            }
        }
        return m;
    }
};