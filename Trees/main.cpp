#include "SearchTree.h"

using namespace std;

void preorder(NodoArbol *nodo);
void inorder(NodoArbol *nodo);
void postorder(NodoArbol *nodo);
void visit(int data);
void insert(NodoArbol *&nodo, int num);

int main()
{
   SearchTree *tree = new SearchTree();

   tree->insert(8);
   tree->insert(10);
   tree->insert(2);
   tree->insert(5);
   tree->insert(3);
   tree->insert(9);
   tree->insert(6);
   tree->insert(11);
   tree->insert(12);
   tree->insert(7);

   cout << "En-orden: ";
   tree->inorder();
   cout << endl;

   cout << "Profundidad: " << tree->depth() << endl;
}