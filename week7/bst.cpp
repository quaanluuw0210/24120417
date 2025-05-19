#include<iostream>
#include<queue>
#include<stack>
using namespace std;
struct NODE {
	int key;
	NODE* p_left;
	NODE* p_right;
};
NODE* createNode(int data)
{
	NODE* new_node = new NODE;
	new_node->p_left = nullptr;
	new_node->p_right = nullptr;
	new_node->key = data;
	return new_node;
}
vector<int> LNR(NODE* pRoot);
NODE* Search(NODE* pRoot, int x)
{
	NODE* temp = pRoot;
	while (temp != NULL)
	{
		if (temp->key < x)
		{
			temp = temp->p_right;
		}
		else if(temp->key>x)
		{ 
			temp = temp->p_left;
		}
		else
		{
			return temp;
		}
	}
	return NULL;
}
void Remove(NODE*& pRoot, int x)
{
	if (pRoot == NULL)
	{
		return;
	}
	if (pRoot->key < x)
	{
		
		Remove(pRoot->p_right, x);
	}
	else if (pRoot->key > x)
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
		else if (pRoot->p_left == NULL)
		{
			NODE*temp = pRoot->p_right;
			delete pRoot;
			pRoot = temp;
		}
		else if (pRoot->p_right == NULL)
		{
			NODE* temp = pRoot->p_left;
			delete pRoot;
			pRoot = temp;
		}
		else
		{
			NODE* temp = pRoot->p_left;
			NODE* pre = temp;
			while (temp != NULL)
			{
				pre = temp;
				temp = temp->p_right;
			}
			if (pre != NULL)
			{
				pRoot->key = pre->key;
				Remove(pRoot->p_left, pre->key);
			}
		}
		
	}
}
void Insert(NODE*& pRoot, int x)
{
	NODE* newnode = createNode(x);
	NODE* pre=NULL;
	NODE* temp = pRoot;
	while (temp != NULL)
	{
		pre = temp;
		if (temp->key < x)
		{
			temp = temp->p_right;
		}
		else if (temp->key > x)
		{
			temp = temp->p_left;
		}
		else
		{
			return;
		}
	}
	if (pre != NULL)
	{
		if (x > pre->key)
		{
			pre->p_right = newnode;
		}
		else if (x < pre->key)
		{
			pre->p_left = newnode;
		}
	}
	else
	{
		pRoot = newnode;
	}
}
NODE* createTree(int a[], int n)
{
	if (n <= 0)
	{
		return NULL;
	}
	NODE* pRoot = createNode(a[0]);
	for (int i = 1; i < n; i++)
	{
		Insert(pRoot, a[i]);
	}
	return pRoot;
}
void removeTree(NODE*& pRoot)
{
	if (pRoot == NULL)
	{
		return;
	}
	int data = pRoot->key;
	Remove(pRoot, data);
	removeTree(pRoot);
}
int Height(NODE* pRoot)
{
	queue<NODE*>node;
	node.push(pRoot);
	int hight = -1;
	while (!node.empty())
	{
		NODE* temp = node.front();
		queue<NODE*>leaf;
		while (temp != NULL)
		{
			if (temp->p_left != NULL)
			{
				leaf.push(temp->p_left);
			}
			if (temp->p_right != NULL)
			{
				leaf.push(temp->p_right);
			}
			node.pop();
			if (!node.empty())
			{
				temp = node.front();
			}
			else
			{
				temp = NULL;
			}
		}
		hight++;
		node = leaf;
	}
	return hight;
}
int countLess(NODE* pRoot, int x)
{
	if (pRoot == NULL)
	{
		return 0;
	}
	if (pRoot->key >= x)
	{
		return countLess(pRoot->p_left,x);
	}
	return 1+countLess(pRoot->p_right, x)+ countLess(pRoot->p_left, x);
}
int countGreater(NODE* pRoot, int x)
{
	if (pRoot == NULL)
	{
		return 0;
	}
	if (pRoot->key <= x)
	{
		return countGreater(pRoot->p_right, x);
	}
	return 1 + countGreater(pRoot->p_right, x) + countGreater(pRoot->p_left, x);
}
bool isBST(NODE* pRoot)//Phai duyet ca cay con chu 2 node con la chua du
{
	vector<int>in_order = LNR(pRoot);
	int i = in_order.size();
	for (int x = 0; x < i - 1; x++)
	{
		if (in_order[x] >= in_order[x + 1])
		{
			return false;
		}
	}
	return true;
}
bool isFullBST(NODE* pRoot)
{
	if (!isBST(pRoot))
	{
		return false;
	}
	stack<NODE*> node;
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
			if (temp->p_left != NULL && temp->p_right == NULL)
			{
				return false;
			}
			else if (temp->p_left == NULL && temp->p_right != NULL)
			{
				return false;
			}
			temp = temp->p_right;
		}
	}
	return true;
}
vector<int> LNR(NODE* pRoot)
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
			data.push_back(temp->key);
			temp = temp->p_right;
		}
	}
	return data;
}
vector<vector<int>> LevelOrder(NODE* pRoot)
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
