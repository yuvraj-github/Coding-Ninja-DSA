#include<stack>
int* stockSpan(int *price, int size)  {
	// Write your code here
    stack<int> st;
    st.push(0);
    int *s = new int(size);
    s[0] = 1;

    for(int i=1; i<size; i++) {
        while (!st.empty() && price[st.top()] < price[i])
        {
            /* code */
            st.pop();
        }
        s[i] = st.empty() ? i+1 : i-st.top();
        st.push(i);
    }
    return s;
}