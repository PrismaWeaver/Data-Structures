#include <iostream>
#include <cstdlib>
#include "llcpInt.h"
using namespace std;

bool hnValDup(Node* head) {
   if (head == 0 || head->link == 0) return false;
   return hnValDupAuxRecur(head->link, head->data);
}

bool hnValDupAuxRecur(Node* head, int hnVal) {
   if (head == 0) return false;
   if (head->data == hnVal) return true;
   return hnValDupAuxRecur(head->link, hnVal);
}

bool listHasDupRecur(Node* head) {
   if (head == 0 || head->link == 0) return false;
   if (hnValDup(head)) return true;
   return (listHasDupRecur(head->link));
}

int FindListLength(Node* headPtr)
{
   int length = 0;

   while (headPtr != 0)
   {
      ++length;
      headPtr = headPtr->link;
   }

   return length;
}

bool IsSortedUp(Node* headPtr)
{
   if (headPtr == 0 || headPtr->link == 0) // empty or 1-node
      return true;
   while (headPtr->link != 0) // not at last node
   {
      if (headPtr->link->data < headPtr->data)
         return false;
      headPtr = headPtr->link;
   }
   return true;
}

void InsertAsHead(Node*& headPtr, int value)
{
   Node *newNodePtr = new Node;
   newNodePtr->data = value;
   newNodePtr->link = headPtr;
   headPtr = newNodePtr;
}

void InsertAsTail(Node*& headPtr, int value)
{
   Node *newNodePtr = new Node;
   newNodePtr->data = value;
   newNodePtr->link = 0;
   if (headPtr == 0)
      headPtr = newNodePtr;
   else
   {
      Node *cursor = headPtr;

      while (cursor->link != 0) // not at last node
         cursor = cursor->link;
      cursor->link = newNodePtr;
   }
}

void InsertSortedUp(Node*& headPtr, int value)
{
   Node *precursor = 0,
        *cursor = headPtr;

   while (cursor != 0 && cursor->data < value)
   {
      precursor = cursor;
      cursor = cursor->link;
   }

   Node *newNodePtr = new Node;
   newNodePtr->data = value;
   newNodePtr->link = cursor;
   if (cursor == headPtr)
      headPtr = newNodePtr;
   else
      precursor->link = newNodePtr;

   ///////////////////////////////////////////////////////////
   /* using-only-cursor (no precursor) version
   Node *newNodePtr = new Node;
   newNodePtr->data = value;
   //newNodePtr->link = 0;
   //if (headPtr == 0)
   //   headPtr = newNodePtr;
   //else if (headPtr->data >= value)
   //{
   //   newNodePtr->link = headPtr;
   //   headPtr = newNodePtr;
   //}
   if (headPtr == 0 || headPtr->data >= value)
   {
      newNodePtr->link = headPtr;
      headPtr = newNodePtr;
   }
   //else if (headPtr->link == 0)
   //   head->link = newNodePtr;
   else
   {
      Node *cursor = headPtr;
      while (cursor->link != 0 && cursor->link->data < value)
         cursor = cursor->link;
      //if (cursor->link != 0)
      //   newNodePtr->link = cursor->link;
      newNodePtr->link = cursor->link;
      cursor->link = newNodePtr;
   }

   ////////////////// commented lines removed //////////////////

   Node *newNodePtr = new Node;
   newNodePtr->data = value;
   if (headPtr == 0 || headPtr->data >= value)
   {
      newNodePtr->link = headPtr;
      headPtr = newNodePtr;
   }
   else
   {
      Node *cursor = headPtr;
      while (cursor->link != 0 && cursor->link->data < value)
         cursor = cursor->link;
      newNodePtr->link = cursor->link;
      cursor->link = newNodePtr;
   }
   */
   ///////////////////////////////////////////////////////////
}

bool DelFirstTargetNode(Node*& headPtr, int target)
{
   Node *precursor = 0,
        *cursor = headPtr;

   while (cursor != 0 && cursor->data != target)
   {
      precursor = cursor;
      cursor = cursor->link;
   }
   if (cursor == 0)
   {
      cout << target << " not found." << endl;
      return false;
   }
   if (cursor == headPtr) //OR precursor == 0
      headPtr = headPtr->link;
   else
      precursor->link = cursor->link;
   delete cursor;
   return true;
}

bool DelNodeBefore1stMatch(Node*& headPtr, int target)
{
   if (headPtr == 0 || headPtr->link == 0 || headPtr->data == target) return false;
   Node *cur = headPtr->link, *pre = headPtr, *prepre = 0;
   while (cur != 0 && cur->data != target)
   {
      prepre = pre;
      pre = cur;
      cur = cur->link;
   }
   if (cur == 0) return false;
   if (cur == headPtr->link)
   {
      headPtr = cur;
      delete pre;
   }
   else
   {
      prepre->link = cur;
      delete pre;
   }
   return true;
}

void ShowAll(ostream& outs, Node* headPtr)
{
   while (headPtr != 0)
   {
      outs << headPtr->data << "  ";
      headPtr = headPtr->link;
   }
   outs << endl;
}

void FindMinMax(Node* headPtr, int& minValue, int& maxValue)
{
   if (headPtr == 0)
   {
      cerr << "FindMinMax() attempted on empty list" << endl;
      cerr << "Minimum and maximum values not set" << endl;
   }
   else
   {
      minValue = maxValue = headPtr->data;
      while (headPtr->link != 0)
      {
         headPtr = headPtr->link;
         if (headPtr->data < minValue)
            minValue = headPtr->data;
         else if (headPtr->data > maxValue)
            maxValue = headPtr->data;
      }
   }
}

double FindAverage(Node* headPtr)
{
   if (headPtr == 0)
   {
      cerr << "FindAverage() attempted on empty list" << endl;
      cerr << "An arbitrary zero value is returned" << endl;
      return 0.0;
   }
   else
   {
      int sum = 0,
          count = 0;

      while (headPtr != 0)
      {
         ++count;
         sum += headPtr->data;
         headPtr = headPtr->link;
      }

      return double(sum) / count;
   }
}

void ListClear(Node*& headPtr, int noMsg)
{
   int count = 0;

   Node *cursor = headPtr;
   while (headPtr != 0)
   {
      headPtr = headPtr->link;
      delete cursor;
      cursor = headPtr;
      ++count;
   }
   if (noMsg) return;
   clog << "Dynamic memory for " << count << " nodes freed"
        << endl;
}

// definition of FormUniquePairs of Assignment 5 Part 1
void FormUniquePairs(Node* head)
{
   if (head == 0) return;
   Node *leadPtr = head,       // leader-of-pair pointer (NEARER to head)
        *traiPtr = 0,          // trailer-of-pair pointer
        *p1Ptr = 0,            // primary-probe pointer (search for 1st match)
        *pp1Ptr = 0,           // pre-primary-probe pointer
        *p2Ptr = 0,            // 2ndary-probe-pointer (search for further matches)
        *pp2Ptr = 0,           // pre-2ndary-probe pointer
        *match1Link = 0;       // 1st-matching-node's link
   int leadData;               // leader-of-pair's data
   while (leadPtr != 0)
   {
      leadData = leadPtr->data;
      pp1Ptr = leadPtr;
      p1Ptr = pp1Ptr->link;
      while (p1Ptr != 0 && p1Ptr->data != leadData)
      {
         pp1Ptr = p1Ptr;
         p1Ptr = p1Ptr->link;
      }
      if (p1Ptr == 0) // no match found
      {
         traiPtr = new Node;
         traiPtr->data = leadData;
         traiPtr->link = leadPtr->link;
         leadPtr->link = traiPtr;

         leadPtr = traiPtr->link;
      }
      else // 1st match found
      {
         if (p1Ptr == leadPtr->link) // 1st match found next to leader-of-pair
         {
            traiPtr = p1Ptr;
            // set up for 2ndary probe
            pp2Ptr = traiPtr;
            p2Ptr = pp2Ptr->link;
         }
         else // match not found next to leader-of-pair
         {
            // detach matched node & make it trailer-of-pair
            match1Link = p1Ptr->link;
            pp1Ptr->link = match1Link;
            p1Ptr->link = leadPtr->link;
            traiPtr = p1Ptr;
            leadPtr->link = traiPtr;
            // set up for 2ndary probe (avoiding unnecessary re-visits)
            pp2Ptr = pp1Ptr;
            p2Ptr = match1Link;
         }
         // do 2ndary probe (delete any further matches)
         while (p2Ptr != 0)
         {
            if (p2Ptr->data != leadData)
            {
               pp2Ptr = p2Ptr;
               p2Ptr = p2Ptr->link;
            }
            else
            {
               pp2Ptr->link = p2Ptr->link;
               delete p2Ptr;
               p2Ptr = pp2Ptr->link;
            }
         }
         // set up for next primary probe
         leadPtr = traiPtr->link;
      }
   }
}

/* modified (rem bool and pbRef) Liu Yiqian's soln
void MakeDistinctPairs(Node* headPtr)
{
   if ( headPtr == 0 )
      return;
   else
   {
      if ( headPtr->link == 0)
      {
         Node *nodePtr = new Node;
         nodePtr->data = headPtr->data;
         nodePtr->link = 0;
         headPtr->link = nodePtr;
         return;
      }
      else
      {
        Node *cur = headPtr;
        while ( cur != 0)
         {
            Node *pair = cur, *pre = cur, *target = cur->link;
            while ( target != 0 )
            {
               if ( target->data != cur->data )
               {
                  pre = target;
                  target = target->link;
               }
               else
               {
                  if ( pair == cur )
                  {
                     pair = target;
                     pre->link = target->link;
                     target = pre->link;
                  }
                  else
                  {
                     pre->link = target->link;
                     delete target;
                     target = pre->link;
                  }
               }

            }
            if ( pair == cur )
            {
               Node *nodePtr = new Node;
               nodePtr->data = cur->data;
               nodePtr->link = cur->link;
               cur->link = nodePtr;
            }
            else
            {
               pair->link = cur->link;
               cur->link = pair;
            }
            cur = cur->link->link;
         }
         return;
        }
   }
}
*/
