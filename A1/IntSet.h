#ifndef INT_SET_H
#define INT_SET_H

#include <iostream>

class IntSet {
public:
   static const int MAX_SIZE = 10;
   IntSet(); 
   int size() const; 
   bool isEmpty() const; 
   bool contains(int anInt) const; 
   bool isSubsetOf(const IntSet& otherIntSet) const; 
   void DumpData(std::ostream& out) const; 
   IntSet unionWith(const IntSet& otherIntSet) const; 
   IntSet intersect(const IntSet& otherIntSet) const; 
   IntSet subtract(const IntSet& otherIntSet) const;  
   void reset(); 
   bool add(int anInt); 
   bool remove(int anInt); 

private:
   int data[MAX_SIZE]; 
   int used; 
};

bool equal(const IntSet& is1, const IntSet& is2); 

#endif
