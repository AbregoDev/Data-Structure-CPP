#include "NodoArbol.h"
#include <iostream>

using namespace std;

class SearchTree {
   public:
      SearchTree() { root = NULL; }
      void insert(int n) { insertNode(root, n); }
      void preorder() { preorderTraversal(root); }
      void inorder() { inorderTraversal(root); }
      void postorder() { postorderTraversal(root); }
      int depth() { return _depth(root); };

   private:
      NodoArbol *root;
      void insertNode(NodoArbol *&nodo, int n);
      void preorderTraversal(NodoArbol *r);
      void inorderTraversal(NodoArbol *r);
      void postorderTraversal(NodoArbol *r);
      int _depth(NodoArbol *n);
};

void SearchTree::preorderTraversal(NodoArbol *nodo) {
   if(nodo != NULL)
   {
      cout << nodo->getDato() << ", ";
      preorderTraversal(nodo->getIzquierdo());
      preorderTraversal(nodo->getDerecho());
   }
}

void SearchTree::inorderTraversal(NodoArbol *nodo) {
   if(nodo != NULL)
   {
      inorderTraversal(nodo->getIzquierdo());
      cout << nodo->getDato() << ", ";
      inorderTraversal(nodo->getDerecho());
   }
}

void SearchTree::postorderTraversal(NodoArbol *nodo) {
   if(nodo != NULL)
   {
      postorderTraversal(nodo->getIzquierdo());
      postorderTraversal(nodo->getDerecho());
      cout << nodo->getDato() << ", ";
   }
}

void SearchTree::insertNode(NodoArbol *&node, int num) {
   if(!node) {
      node = new NodoArbol(num);
   } else if (num < node->getDato()) { 
      insertNode(node->getIzquierdo(), num);
   } else {
      insertNode(node->getDerecho(), num);
   }
}

int SearchTree::_depth(NodoArbol *n) {
   if (!n) {
      return 0;
   } else {
      int leftDepth = _depth(n->getIzquierdo());
      int rightDepth = _depth(n->getDerecho());

      if (leftDepth > rightDepth)
         return leftDepth + 1;
      else
         return rightDepth + 1;
   }
}