/*
 Program Name: Exception_Handling.cpp
 Programmer: Moris Gomez
 Date: Tuesday 05/2/2024
 Version Control: 10.0
 About: Week 12, CSCI 2, Lab.
 Description:
 Write a class named TestScores. The class constructor
 should accept an array of test scores as its argument.
 The class should have a member function that returns the
 average of the test scores. If any test score in the
 array is negative or greater than 100, the class should
 throw an exception. Demonstrate the class in a program.
 */

#include <iostream>
using namespace std;

class TestScores
{
private:
    int size;
    int *ptrScores; //points to address of first value in array.
public:
    //nested class for throwing object type to catch:
    class InvalidScore
    {
        //empty class btw.
    }; //end nested class NegativeScore.
    
    //constructor:
    TestScores(int s, int *ptr) //pointer to array in main.
    {
        size = s;
        ptrScores = ptr;
    }
    
    //function #1:
    double average()
    {
        double sum = 0.0; //sumTracker.
        //loop through array:
        for (int i = 0; i < size; i++)
        {
            if(ptrScores[i] < 0 || ptrScores[i] > 100)
            {
                throw InvalidScore();
                //type of throw & catch is object.
            }
            else
            {
                sum = sum + ptrScores[i];
                //ptrScores[0] same as *ptrScores
                //ptrScores[1] same as *ptrScores
            }
        } //end loop.
        return sum/size;
    } //end function average.
}; //end class TestScores.


int main()
{
    int sizeArray = 5;
    int array[5] = {0, 80, 90, 91, 111}; //ERROR.
    TestScores s1(sizeArray, array);
        
    try
    {
        cout << "average of test scores: " << s1.average() << endl;
    } //end try.
    
    catch(TestScores::InvalidScore) //type of throw & catch is object.
    {
        cout << endl << "[ERROR] <-- Test scores cannot be negative or greater than 100 -->" << endl;
    } //end catch.
    return 0;
}
