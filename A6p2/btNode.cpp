#include "btNode.h"

void bst_insert(btNode* &bst_root, int insInt) {
   if (bst_root == 0) bst_root = create_node(insInt);
   btNode* ref = bst_root;
   btNode* pRef = bst_root;
   while (ref != 0) {
      if (ref->data > insInt) {
         if (ref->left != 0) {
            pRef = ref;
            ref = ref->left;
         }
         else {
            ref-> left = create_node(insInt);
            return;
         }
      }
      else if (ref->data < insInt) {
         if (ref->right != 0) {
            pRef = ref;
            ref = ref->right;
         }
         else {
            ref-> right = create_node(insInt);
            return;
         }
      }
      else {
         ref->data = insInt;
         return;
      }
   }
   
}

btNode* create_node(int data) {
   btNode* newNode = new btNode;
   newNode->data = data;
   newNode->left = newNode->right = 0;
   return newNode;
}

bool bst_remove(btNode* &bst_root, int data) {
   if (bst_root == 0) return false;
   if (bst_root->data > data) return bst_remove(bst_root->left, data);
   if (bst_root->data < data) return bst_remove(bst_root->right, data);
   if (bst_root->data == data) {
      if (bst_root->right == 0 || bst_root->left == 0) {
         btNode* old_bst_root = bst_root;
         if (bst_root->right == 0) bst_root = bst_root->left;
         else bst_root = bst_root->right;
         delete old_bst_root;
         return true;
      }
      else {
         bst_remove_max(bst_root->left, bst_root->data);
         return true;
      }
   }
   return false;
}

void bst_remove_max(btNode* &bst_root, int &data) {
   if (bst_root->right != 0) bst_remove_max(bst_root->right, data);
   else {
      data = bst_root->data;
      btNode* old_bst_root = bst_root;
      bst_root = bst_root->left;
      delete old_bst_root;
   }
}

void portToArrayInOrder(btNode* bst_root, int* portArray)
{
   if (bst_root == 0) return;
   int portIndex = 0;
   portToArrayInOrderAux(bst_root, portArray, portIndex);
}

void portToArrayInOrderAux(btNode* bst_root, int* portArray, int& portIndex)
{
   if (bst_root == 0) return;
   portToArrayInOrderAux(bst_root->left, portArray, portIndex);
   portArray[portIndex++] = bst_root->data;
   portToArrayInOrderAux(bst_root->right, portArray, portIndex);
}

void tree_clear(btNode*& root)
{
   if (root == 0) return;
   tree_clear(root->left);
   tree_clear(root->right);
   delete root;
   root = 0;
}

int bst_size(btNode* bst_root)
{
   if (bst_root == 0) return 0;
   return 1 + bst_size(bst_root->left) + bst_size(bst_root->right);
}