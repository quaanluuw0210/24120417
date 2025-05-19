#include<iostream>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
struct NODE {
	int key;
	NODE* p_left;
	NODE* p_right;
	int height;
};
int getHight(NODE* root);
int upHight(NODE* root);

NODE* createNode(int data)
{
	NODE* new_NODE = new NODE;
	new_NODE->key = data;
	new_NODE->height = 0;
	new_NODE->p_left = NULL;
	new_NODE->p_right = NULL;
	return new_NODE;
}
void rotateRight(NODE*& root)
{
	NODE* left_child = root->p_left;
	if (left_child == NULL)
	{
		return;
	}
	root->p_left = left_child->p_right;
	left_child->p_right = root;
	root->height = upHight(root);
	left_child->height = upHight(left_child);
	root = left_child;
}
void rotateLeft(NODE*& root)
{
	NODE* right_child = root->p_right;
	if (right_child == NULL)
	{
		return;
	}
	root->p_right = right_child->p_left;
	right_child->p_left = root;
	root->height = upHight(root);
	right_child->height = upHight(right_child);
	root = right_child;
}
int getHight(NODE* root)
{
	if (root == NULL)
	{
		return -1;
	}
	return root->height;
}
int upHight(NODE* root)
{
	if (root == NULL)
	{
		return -1;
	}
	int hight_left = getHight(root->p_left);
	int hight_right = getHight(root->p_right);
	if (hight_left >= hight_right)
	{
		return hight_left + 1;
	}
	return hight_right + 1;
}
void Insert(NODE*& pRoot, int x)
{
	if (pRoot == NULL)
	{
		NODE* newnode = createNode(x);
		pRoot = newnode;
		return;
	}
	if (pRoot->key < x)
	{
		Insert(pRoot->p_right, x);
	}
	else if (pRoot->key > x)
	{
		Insert(pRoot->p_left, x);
	}
	else
	{
		return;
	}
	pRoot->height = upHight(pRoot);
	int balance = getHight(pRoot->p_left) - getHight(pRoot->p_right);
	if (balance > 1)
	{
		int balance_LX = getHight(pRoot->p_left->p_right) - getHight(pRoot->p_left->p_left);
		if (balance_LX > 0)
		{
			rotateLeft(pRoot->p_left);
			rotateRight(pRoot);
		}
		else
		{
			rotateRight(pRoot);
		}
	}
	else if (balance < -1)
	{

		int balance_RX = getHight(pRoot->p_right->p_left) - getHight(pRoot->p_right->p_right);
		if (balance_RX > 0)
		{
			rotateRight(pRoot->p_right);
			rotateLeft(pRoot);
		}
		else
		{
			rotateLeft(pRoot);
		}
	}
}
void Remove(NODE*& pRoot, int x)
{
	if (pRoot == NULL) return;
	if (x > pRoot->key)
	{
		Remove(pRoot->p_right, x);
	}
	else if (x < pRoot->key)
	{
		Remove(pRoot->p_left, x);
	}
	else
	{
		if (pRoot->p_left == NULL && pRoot->p_right == NULL)
		{
			delete pRoot;
			pRoot = NULL;
		}
		else if (pRoot->p_left == NULL && pRoot->p_right != NULL)
		{
			NODE* temp = pRoot->p_right;
			delete pRoot;
			pRoot = temp;
		}
		else if (pRoot->p_left != NULL && pRoot->p_right == NULL)
		{
			NODE* temp = pRoot->p_left;
			delete pRoot;
			pRoot = temp;
		}
		else if (pRoot->p_left != NULL && pRoot->p_right != NULL)
		{
			NODE* temp = pRoot->p_left;
			while (temp->p_right != NULL)
			{
				temp = temp->p_right;
			}
			pRoot->key = temp->key;
			Remove(pRoot->p_left, temp->key);
		}
	}
		if (pRoot == NULL)
		{
			return;
		}
		pRoot->height = upHight(pRoot);
		int balance = getHight(pRoot->p_left) - getHight(pRoot->p_right);
		if (balance > 1)
		{
			int balance_LX = getHight(pRoot->p_left->p_right) - getHight(pRoot->p_left->p_left);
			if (balance_LX > 0)
			{
				rotateLeft(pRoot->p_left);

			}
			rotateRight(pRoot);
		}
		else if (balance < -1)
		{

			int balance_RX = getHight(pRoot->p_right->p_left) - getHight(pRoot->p_right->p_right);
			if (balance_RX > 0)
			{
				rotateRight(pRoot->p_right);


			}
			rotateLeft(pRoot);
		}
	
}
vector<vector<int>> LevelOrder(NODE* pRoot)// ham nay chua on, co ve dang duyet du vai level khong co node
{
	queue<NODE*>node;
	vector<vector<int>>data;
	node.push(pRoot);
	NODE* temp = pRoot;
	int i = 0;
	while (temp != NULL || !node.empty())
	{
		queue<NODE*>child_node;
		vector<int> level_data;
		if (node.empty())
		{
			temp = NULL;
		}
		else
		{
			NODE* temp = node.front();
		}
		NODE* temp2;
		if (node.empty())
		{
			temp2 = NULL;
		}
		else
		{
			temp2 = node.front();
		}
		while (temp2 != NULL)
		{
			level_data.push_back(temp2->key);
			if (temp2->p_left != NULL)
			{
				child_node.push(temp2->p_left);
			}
			if (temp2->p_right != NULL)
			{
				child_node.push(temp2->p_right);
			}
			node.pop();
			if (node.empty())
			{
				temp2 = NULL;
			}
			else
			{
				temp2 = node.front();
			}
		}
		i++;
		node = child_node;
		if (!level_data.empty())
			data.push_back(level_data);
	}
	return data;
}
bool isAVL(NODE* pRoot)
{
		stack<NODE*> node;
		vector<int> data;
		NODE* temp = pRoot;
		if (temp != NULL)
		{
			while (temp != NULL || !node.empty())
			{
				while (temp != NULL)
				{
					node.push(temp);
					temp = temp->p_left;
				}
				temp = node.top();
				node.pop();
				int balance = getHight(temp->p_left) - getHight(temp->p_right);
				balance = abs(balance);
				if (balance>1)
				{
					return false;
				}
				temp = temp->p_right;
			}
		}
		return true;
}
