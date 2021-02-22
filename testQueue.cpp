#include "testQueue.h"
/*
Function:
Description: 
Test Steps:
    1.
    2.
    3.
Test data:
Precondition:
Postcondition:
Expected Results:
Actual Results:
Status:
*/


/*
Function: int queue::size()
Description: utility function to return size of queue
Test Steps: 
    1.  Create new queue named test
            -queue defaults arr data member to be of size 10 and queue cap size 10
    2.  Int variable named 'qsize'is created and is assigned a value by calling the size function
    3.  Print name of tested function and size;

Test data: constructor makes an empty queue with data member arr having a size limit of 10
Precondition: queue object is created and initialized, contains 0 nodes
Postcondtion: queue object still contains 0 nodes
Expected result: queue has no nodes; 0 is returned
Actual Result: 1 is returned
Status: fail; returns incorrect value of queue size

*/
void testSize(void){
    queue* test = new queue(10);
    int qsize = test->size();
    cout << "Testing Fuction:\t size()" << endl;
    cout << "\t Results:\t " << qsize << endl;
}

/*
Function: bool queue::isEmpty()
Description: Utility function to check if the queue is empty or not
Test Steps: 
    1.  Create new queue named test
            -queue defaults arr data member to be of size 10 and queue cap size 10
    2.  Call isEmpty for test
    3.  Print name of tested function and results;

Test data: constructor makes an empty queue with data member arr having a size limit of 10
Precondition: queue object is created and initialized, contains 0 nodes
Postcondtion: queue object still contains 0 nodes
Expected result: queue is empty; 1 is returns;
Actual Result: queue is not empty; 0 is returned
Status: fail; queue is not seen as empty when there are no nodes

*/
void testIsEmpty(void){
    queue* test = new queue(10);
    cout << "Testing Funtion:\t isEmpty()" << endl;
    cout << "\t Results:\t " << test->isEmpty() <<endl;
}

/*
Function: bool queue::isFull()
Description: utility function to check if queue is full or not 
Test Steps:
    1.  Create new queue named test
            -queue defaults arr data member to be of size 10 and queue cap size 10
    2.  Call isFull for test
    3.  Print name of tested function and results;
Test data: constructor makes an empty queue with data member arr having a size limit of 10
Precondition: queue object is created and initialized, contains 0 nodes
Postcondtion: queue object still contains 0 nodes
Expected Results: queue is not full; return 0
Actual Results: queue is not full; return 0
Status: pass
*/
void testIsFull(void){
    queue* test = new queue(10);
    cout << "Testing Funtion:\t isFull()" << endl;
    cout << "\t Results:\t " << test->isFull() <<endl;

}

/*  Enqueue Case 1
Function: void queue::enqueue
Description: utitlity function to add an item to the queue
Test Steps:
    1.  Create new queue named test
            -queue defaults arr data member to be of size 10 and queue cap size 10
    2.  Print current size of queue
    3.  An int, 4, is used for enqueue when called by test
    4.  Print Results, check to see if queue size has increased
Test data:  an empty queue
Precondition:   an object queue exists and is empty
Postcondition:  queue increase in size by 1
Expected Results:   queue size increases by 1
Actual Results:     queue size is increased by 1
Status: pass
*/
void testEnqueue1(void){
    queue* test = new queue(10);
    cout << "Testing Function: enqueue()" << endl;
    cout << "\t Current: size = " << test->size()<<endl;
    test->enqueue(4);
    cout << "\t Results: size = " << test->size()<<endl;
}


/*  Enqueue Case 2
Function: void queue::enqueue
Description: utitlity function to add an item to the queue
Test Steps:
    1.  Create new queue named test
            -queue defaults arr data member to be of size 10 and queue cap size 10
    2.  Print current size of queue
    3.  An int, 4, is used for enqueue when called by test
    4.  Print current size of queue
    5.  An int, 11, it used for enqueue when called by test
Test data:  an empty queue
Precondition:   an object queue exists and is empty
Postcondition:  queue increase in size by 2
Expected Results:   queue size increases by 2
Actual Results:     queue size is increased by 2
Status: pass
*/
void testEnqueue2(void){
    queue* test = new queue(10);
    cout << "Testing Function: enqueue()" << endl;
    cout << "\t Current: size = " << test->size()<<endl;
    test->enqueue(4);
    cout << "\t Current: size = " << test->size()<<endl;
    test->enqueue(11);
    cout << "\t Results: size = " << test->size()<<endl;
}

/*  Dequeue Case 1
Function: void queue::dequeue
Description: utitlity function to remove front element of queue
Test Steps:
    1.  Create new queue named test
            -queue defaults arr data member to be of size 10 and queue cap size 10
    2.  Print current size of queue
    3.  An int, 4, is used for enqueue when called test
    4.  Print current size of queue
    5.  Test calls dequeue
    6.  Print reesults
Test data:  an empty queue
Precondition:   an object queue exists with items in the queue
Postcondition:  queue size decrease in size by 1
Expected Results:   queue size decreases by 1
Actual Results:     queue size is descreases by 1
Status: pass
*/
void testDequeue1(void){
    queue* test = new queue(10);
    cout << "Testing Function: dequeue()" << endl;
    cout << "\t Current: size = " << test->size()<<endl;
    test->enqueue(4);
    cout << "\t Current: size = " << test->size()<<endl;
    test->dequeue();
    cout << "\t Results: size = " << test->size()<<endl;
}

/*  Dequeue Case 1
Function: void queue::dequeue
Description: utitlity function to remove front element of queue
Test Steps:
    1.  Create new queue named test
            -queue defaults arr data member to be of size 10 and queue cap size 10
    2.  Print current size of queue
Test data:  an empty queue 
Precondition:   queue is empty
Postcondition:  program terminates with wrror message
Expected Results:   program terminates with error message
Actual Results:     program continues with no error message
Status: fail
*/
void testDequeue2(void){
    queue* test = new queue(10);
    cout << "Testing Function: dequeue()" << endl;
    cout << "\t Current: size = " << test->size()<<endl;
    test->dequeue();
    cout << "\t Results: size = " << test->size()<<endl;

}



