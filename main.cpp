#include <iostream>
#include "BinarySearchTree.h"
using namespace std;
int main() {
    int a[] = {10,8,6,21,87,56,4,0,11,3,22,7,5,34,1,2,9};
    BinarySearchTree<int> tree;
    for(int i=0;i<17;++i) tree.insert(a[i]);
    cout<<endl;
    cout << "find 2 is "<<(tree.find(2)? "true":"false") <<endl;
    tree.remove(2);
    cout<< "after delete 2,find 2 is "<<(tree.find(2)? "true":"false") <<endl;
    return 0;
}