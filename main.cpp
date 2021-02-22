/*
Amy Nguyen

Poor Practices Within Program
    1. Program started with all definitions and declarations within the main file
    2. Queue should be made up of nodes instead of utilizing an array to store data
    3. Constant definitions should be at top of program
    4. Program should avoid using system functions, as it would cause issues when running the program on other os
    5. Program should use comment blocks above function definiton to give the details of the function and what it does
*/
#include "testQueue.cpp"
// main function
int main()
{
	// call your test functions here!

    testSize();     //test for size()
    testIsEmpty();  //test for isEmpty()
    testIsFull();   //test for isFull()

    testEnqueue1(); cout << endl;   //test 1 for enqueue
    testEnqueue2(); cout << endl;   //test 2 for enqueue
    testDequeue1(); cout << endl;   //test 1 for dequeue
    testDequeue2(); cout << endl;   //test 2 for dequeue
	return 0;
}


