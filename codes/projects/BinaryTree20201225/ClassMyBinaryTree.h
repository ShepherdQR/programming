#pragma once


template<typename T>
class BinaryTreeNode {
public:
	BinaryTreeNode();
	BinaryTreeNode(T iData, 
		BinaryTreeNode<T> *iChildL=nullptr,
		BinaryTreeNode<T> *iChildR = nullptr);

	BinaryTreeNode<T>* childLeft() { return _pChildL; }
	BinaryTreeNode<T>* childRight(){return _pChildR;}



private:
	T _data;
	BinaryTreeNode<T> *_pChildL;
	BinaryTreeNode<T> *_pChildR;
};



template<typename T>
class MyBinaryTree {

public:
	MyBinaryTree() :_pRoot(nullptr) {}
	~MyBinaryTree() : {DestroySubTree(_pRoot); }

	void DestroySubTree(BinaryTreeNode<T>* &ipNood);

	BinaryTreeNode<T>* ChildLeft(BinaryTreeNode<T>* &iNoodCurrent){
		return iNoodCurrent ? iNoodCurrent->childLeft : nullptr;
	}

	BinaryTreeNode<T>* ChildRight(BinaryTreeNode<T>* &iNoodCurren){
		return iNoodCurrent ? iNoodCurrent->childRight : nullptr;
	}
private:

	


	BinaryTreeNode<T> *_pRoot;





};

