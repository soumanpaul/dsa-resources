// function to calculate median of stream
void printMedian(double arr[], int n)
{
    // max heap to store the smaller half elements
    priority_queue s;
 
    // min heap to store the greater half elements
    priority_queue,greater > g;
 
    double med = arr[0];
    s.push(arr[0]);
 
    print(med)
 
    // reading elements of stream one by one
    /*  At any time we try to make heaps balanced and
        their sizes differ by at-most 1. If heaps are
        balanced,then we declare median as average of
        min_heap_right.top() and max_heap_left.top()
        If heaps are unbalanced,then median is defined
        as the top element of heap of larger size  */
    for (int i=1; i < n; i++)
    {
        double x = arr[i];
 
        // case1(left side heap has more elements)
        if (s.size() > g.size())
        {
            if (x < med)
            {
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else
                g.push(x);
 
            med = (s.top() + g.top())/2.0;
        }
 
        // case2(both heaps are balanced)
        else if (s.size()==g.size())
        {
            if (x < med)
            {
                s.push(x);
                med = (double)s.top();
            }
            else
            {
                g.push(x);
                med = (double)g.top();
            }
        }
 
        // case3(right side heap has more elements)
        else
        {
            if (x > med)
            {
                s.push(g.top());
                g.pop();
                g.push(x);
            }
            else
                s.push(x);
 
            med = (s.top() + g.top())/2.0;
        }
 
        print(med)
    }
}