#include<iostream>

#include<process.h>

#include<conio.h>

using namespace std;

struct node {
  int data;
  struct node * left;
  struct node * right;
};
class BST {
  public: node * tree;
  BST() {
    tree = NULL;
  }
  void createTree(node ** , int item);
  void preorder(node * );
  void inorder(node * );
  void postorder(node * );
  int totalNodes(node * );
  void removeTree(node ** );
  void findsmallestNode(node * );
  void findLargestNode(node * );
  void deleteNode(int);
};
void BST::createTree(node ** tree, int item) {
  if ( * tree == NULL) {
    * tree = new node;
    ( * tree) -> data = item;
    ( * tree) -> left = NULL;
    ( * tree) -> right = NULL;
  } else {
    if (( * tree) -> data > item)
      createTree( & (( * tree) -> left), item);
    else
      createTree( & (( * tree) -> right), item);
  }
}

void BST::preorder(node * tree) {
  if (tree != NULL) {
    cout << "  " << tree -> data;
    preorder(tree -> left);
    preorder(tree -> right);
  }
}

void BST::inorder(node * tree) {
  if (tree != NULL) {
    inorder(tree -> left);
    cout << "  " << tree -> data;
    inorder(tree -> right);
  }
}

void BST::postorder(node * tree) {
  if (tree != NULL) {
    postorder(tree -> left);
    postorder(tree -> right);
    cout << "  " << tree -> data;
  }
}

int BST::totalNodes(node * tree) {
  if (tree == NULL)
    return 0;
  else
    return (totalNodes(tree -> left) + totalNodes(tree -> right) + 1);
}

void BST::removeTree(node ** tree) {
  if (( * tree) != NULL) {
    removeTree( & ( * tree) -> left);
    removeTree( & ( * tree) -> right);
    delete( * tree);
  }
}

void BST::findsmallestNode(node * tree) {
  if (tree == NULL || tree -> left == NULL)
    cout << tree -> data;
  else
    findsmallestNode(tree -> left);
}
node * find_Insucc(node * curr) {
  node * succ = curr -> right;
  if (succ != NULL) {
    while (succ -> left != NULL)
      succ = succ -> left;
  }
  return (succ);
}
void BST::findLargestNode(node * tree) {
  if (tree == NULL || tree -> right == NULL)
    cout << tree -> data;
  else
    findLargestNode(tree -> right);
}

void BST::deleteNode(int item) {
  node * curr = tree, * succ, * pred;
  int flag = 0, delcase;
  while (curr != NULL && flag != 1) {
    if (item < curr -> data) {
      pred = curr;
      curr = curr -> left;
    } else if (item > curr -> data) {
      pred = curr;
      curr = curr -> right;
    } else {
      flag = 1;
    }
  }
  if (flag == 0) {
    cout << "\n item does not exist:no deletion\n";
    getch();
  }
  if (curr -> left == NULL && curr -> right == NULL)
    delcase = 1;
  else if (curr -> left != NULL && curr -> right != NULL)
    delcase = 3;
  else
    delcase = 2;
  if (delcase == 1) {
    if (pred -> left == curr)
      pred -> left = NULL;
    else
      pred -> right = NULL;
    delete(curr);
    pred -> right;
  }
  if (delcase == 2) {
    if (pred -> left == curr) {
      if (curr -> left == NULL)
        pred -> left = curr -> right;
      else
        pred -> left = curr -> left;
    } else {
      if (curr -> left == NULL)
        pred -> right = curr -> right;
      else
        pred -> right = curr -> left;
      delete(curr);
    }
    if (delcase == 3) {
      succ = find_Insucc(curr);
      int item1 = succ -> data;
      deleteNode(item1);
      curr -> data = item1;
    }
  }
}

int main() {
  BST obj;
  int choice;
  int height = 0, total = 0, n, item;
  node ** tmp;
  while (1) {
    cout << "\n  Binary search tree common operation\n";
    cout << "1)Create Tree \n";
    cout << "2)Traversal \n";
    cout << "3)Total Nodes\n";
    cout << "4)Remove Tree\n";
    cout << "5)Insert Nodes\n";
    cout << "6)Find Smallest Nodes \n";
    cout << "7)Find Largest Node \n";
    cout << "8)Delete Node\n";
    cout << "9)Exit\n";
    cout << "Enter your choice :";
    cin >> choice;
    switch (choice) {
    case 1:
      cout << "\n Creating Tree----";
      cout << "How many nodes u want to enter :";
      cin >> n;
      for (int i = 0; i < n; i++) {
        cout << "Enter Values :";
        cin >> item;
        obj.createTree( & obj.tree, item);
      }
      break;
    case 2:
      cout << "\n Inorder Traversal  :";
      obj.inorder(obj.tree);
      cout << "\n preorder Traversal  :";
      obj.preorder(obj.tree);
      cout << "\n Postorder Traversal  :";
      obj.postorder(obj.tree);
      getch();
      break;
    case 3:
      total = obj.totalNodes(obj.tree);
      cout << "Total nodes :" << total;
      getch();
      break;
    case 4:
      obj.removeTree( & obj.tree);
      cout << "\n Tree is removed from memory";
      getch();
      break;
    case 5:
      cout << "\n Insert node in a tree \n";
      cout << "Enter value :";
      cin >> item;
      obj.createTree( & obj.tree, item);
      cout << "\nItem is inserted\n";
      getch();
      break;
    case 6:
      cout << "\n\nSmallest node is:\n";
      obj.findsmallestNode(obj.tree);
      getch();
      break;
    case 7:
      cout << "\n\nLargest node is:\n";
      obj.findLargestNode(obj.tree);
      getch();
      break;
    case 8:
      cout << "\n\n Deleting a node from a tree--\n";
      cout << "Enter value=";
      cin >> item;
      obj.deleteNode(item);
      break;
    }
  }
}
