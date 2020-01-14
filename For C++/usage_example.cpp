#include <iostream>
using namespace std;

#define PRIORITY_QUEUE

#ifdef PRIORITY_QUEUE
#include "priority_queue_list.hpp"
int main(int argc, char const *argv[])
{
    PriorityQueue<> pq; //default holds int data type
    pq.push(12);
    pq.push(13);
    pq.push(1);

    while (!pq.isEmpty()) {
        cout << pq.top() << endl;
        pq.pop();
    }
    return 0;
}
#endif

#ifdef DOUBLY_LIST
#include "list_doubly.hpp"
int main(int argc, char const *argv[])
{
    ListDoubly<char> myList;
    
    myList.pushBack('A');
    myList.pushBack('B');
    myList.pushBack('C');
    myList.pushBack('D');

    myList.pushFront('W');
    myList.pushFront('X');
    myList.pushFront('Y');
    myList.pushFront('Z');

    cout << myList.size() << endl;

    myList.popBack();
    myList.popFront();

    myList.insert('G', 2);

    cout << myList.size() << endl;

    while (!myList.isEmpty()) {
        cout << myList.front();
        myList.popFront();
    }
    cout << endl << myList.size() << endl;
    printf("\n");
    return 0;
}
#endif

#ifdef STACK_ARRAY
#include "stack_array.hpp"
int main()
{
    StackArray<100, double> mystc;
    mystc.push(2.32);
    mystc.push(3.30);
    mystc.push(9.1);
    mystc.pop();
    cout << mystc.top() << endl;
    return 0;
}
#endif

#ifdef STACK_LIST
#include "stack_list.hpp"
int main(int argc, char const *argv[])
{
    Stack<double> mystc;
    mystc.push(2.3);
    mystc.push(3.34);
    mystc.push(9.1);
    mystc.pop();
    cout << mystc.top() << endl;
    cout << mystc._size << endl;
    return 0;
}
#endif

#ifdef QUEUE_ARRAY
#include "queue_array.hpp"
int main(int argc, char const *argv[])
{
    QueueArray<100, char> myq;
    myq.push('X');
    myq.push('A');
    myq.push('K');
    myq.push('U');
    myq.pop();

    while (!myq.isEmpty()) {
        cout << myq.front() << endl;
        myq.pop();
    }
    return 0;
}
#endif

#ifdef QUEUE_LIST
#include "queue_list.hpp"
int main(int argc, char const *argv[])
{
    char str[23];
    Queue<int> myq;
    
    int n = 3;
    while (n--) {
        int xx;
        scanf("%d", &xx);
        myq.push(xx);
    }

    while (!myq.isEmpty()) {
        printf("%d\n", myq.front());
        myq.pop();
    }
    return 0;
}
#endif