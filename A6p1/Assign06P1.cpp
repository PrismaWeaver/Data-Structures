#include "llcpInt.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void SeedRand();
int  BoundedRandomInt(int lowerBound, int upperBound);
bool hasDup(const int a[], int used);
void ShowArray(const int a[], int size);
void DebugShowCase(int whichCase, int totalCasesToDo,
                   const int caseValues[], int caseSize);

int main()
{
   int testCasesToDo = 900000,
       testCasesDone = 0,
       loSize = 1,
       hiSize = 9,
       loValue = 0,
       hiValue = 15;
   int numInts,
       used0,
       intCount,
       newInt;
   int *intArr0 = 0;
   Node *head1 = 0;
   bool caseStatus = true,
        callStatus;

   cout << "================================" << endl;
   if ( ! listHasDupRecur(head1) )
      cout << "passed test on empty list" << endl;
   else
   {
      cout << "failed test on empty list..." << endl;
      cout << "================================" << endl;
      exit(EXIT_FAILURE);
   }

   // SeedRand(); // disabled for reproducible result

   do
   {
      ++testCasesDone;
      numInts = BoundedRandomInt(loSize, hiSize);
      intArr0 = new int [numInts];

      used0 = 0;
      for (intCount = 0; intCount < numInts; ++intCount)
      {
         newInt = BoundedRandomInt(loValue, hiValue);
         intArr0[used0++] = newInt;
         InsertAsTail(head1, newInt);
      }
	  
      caseStatus = hasDup(intArr0, used0);

      // DebugShowCase(testCasesDone, testCasesToDo, intArr0, used0);

      if ( (callStatus = listHasDupRecur(head1)) != caseStatus)
      {
         cout << "Status-check error ..." << endl;
         cout << "test_case: ";
         ShowArray(intArr0, used0);
         cout << "expected: " << ((caseStatus) ? "true" : "false") << endl;
         cout << "returned: " << ((callStatus) ? "true" : "false") << endl;
         exit(EXIT_FAILURE);
      }

      if (testCasesDone < 21 || testCasesDone % 30000 == 0)
      {
         cout << "================================" << endl;
         clog << "testing case " << testCasesDone
              << " of " << testCasesToDo << endl;
         clog << "================================" << endl;
         cout << "test case " << testCasesDone
              << " of " << testCasesToDo << endl;
         ShowArray(intArr0, used0);
         cout << "expected: " << ((caseStatus) ? "true" : "false") << endl;
         cout << "returned: " << ((callStatus) ? "true" : "false") << endl;
      }

      ListClear(head1, 1);
      delete [] intArr0;
      intArr0 = 0;
   }
   while (testCasesDone < testCasesToDo);
   cout << "================================" << endl;
   cout << "test program terminated normally" << endl;
   cout << "================================" << endl;

   return EXIT_SUCCESS;
}

/////////////////////////////////////////////////////////////////////
// Function to seed the random number generator
// PRE:  none
// POST: The random number generator has been seeded.
/////////////////////////////////////////////////////////////////////
void SeedRand()
{
   srand( (unsigned) time(NULL) );
}

/////////////////////////////////////////////////////////////////////
// Function to generate a random integer between
// lowerBound and upperBound (inclusive)
// PRE:  lowerBound is a positive integer.
//       upperBound is a positive integer.
//       upperBound is larger than lowerBound
//       The random number generator has been seeded.
// POST: A random integer between lowerBound and upperBound
//       has been returned.
/////////////////////////////////////////////////////////////////////
int BoundedRandomInt(int lowerBound, int upperBound)
{
   return ( rand() % (upperBound - lowerBound + 1) ) + lowerBound;
}

void ShowArray(const int a[], int size)
{
   for (int i = 0; i < size; ++i)
      cout << a[i] << "  ";
   cout << endl;
}

void DebugShowCase(int whichCase, int totalCasesToDo,
                   const int caseValues[], int caseSize)
{
   cout << "test case " << whichCase
        << " of " << totalCasesToDo << endl;
   cout << "given list: ";
   ShowArray(caseValues, caseSize);
}

bool hasDup(const int a[], int used)
{
   int usedLessOne = used - 1;
   for (int i = 0; i < usedLessOne; ++i)
      for (int j = i + 1; j < used; ++j)
         if (a[i] == a[j]) return true;
   return false;         
}
