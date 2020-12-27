

#include"ClassMyBinaryTree.h"

template<typename T>
BinaryTreeNode<T>::BinaryTreeNode():_pChildL(nullptr), _pChildR(nullptr){
}

template<typename T>
BinaryTreeNode<T>::BinaryTreeNode(T iData,
	BinaryTreeNode<T> *iChildL,
	BinaryTreeNode<T> *iChildR): _data(iData),_pChildL(iChildL), _pChildR(iChildR) {
}


template<typename T>
void MyBinaryTree<T>::DestroySubTree(BinaryTreeNode<T>* &ipNood){
	if (ipNood) {
		DestroySubTree(ipNood->ChildLeft);
		DestroySubTree(ipNood->ChildRight);
		delete ipNood;
		ipNood = nullptr;
	}
}