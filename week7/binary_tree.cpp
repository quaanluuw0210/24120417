#include<iostream>
#include<vector>
#include<stack>
#include<queue>
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
vector<int> NLR(NODE* pRoot)// Duyet pre-order
{
	stack<NODE*> node;
	vector<int> data;
	NODE* temp = pRoot;
	while (temp != NULL || !node.empty())
	{
		if (temp != NULL)
		{
			data.push_back(temp->key);
			if (temp->p_right != NULL)
			{
				node.push(temp->p_right);
			}
			if (temp->p_left == NULL)
			{
				if (!node.empty())
				{
					temp = node.top();
					node.pop();
				}
				else
				{
					temp = NULL;
				}
			}
			else
			{

				temp = temp->p_left;
			}
		}
	}
	return data;
}

vector<int> LNR(NODE* pRoot) // Duyet in-order, khong su ly duoc truong hop chi co cay con o ben phai
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
vector<int> LRN(NODE* pRoot) // post_order
{
	stack<NODE*> node;
	vector<int>data;
	NODE* temp = pRoot;
	while (temp != NULL || !node.empty())
	{
		while (temp != NULL)
		{
			data.push_back(temp->key);
			node.push(temp);
			temp = temp->p_right;
		}
		temp = node.top();
		node.pop();
		temp = temp->p_left;
	}
	int t = data.size();
	vector<int> post_order;
	for (int i = 0; i < t; i++)
	{
		post_order.push_back(data[t - 1 - i]);
	}
	return post_order;
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
		if(!level_data.empty())
		data.push_back(level_data);
	}
	return data;
}
int countNode(NODE* pRoot)
{
	stack<NODE*> node;
	int count = 0;
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
			count++;
			temp = temp->p_right;
		}
	}
	return count;
}
int sumNode(NODE* pRoot)
{
	stack<NODE*> node;
	int sum = 0;
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
			sum = sum + temp->key;
			temp = temp->p_right;
		}
	}
	return sum;
}
int heightNode(NODE* pRoot, int value)
{
	vector<vector<int>>hight_node;
	hight_node = LevelOrder(pRoot);
	int size_row = hight_node.size();
	for (int i = 0; i < size_row; i++)
	{
		int size_col = hight_node[i].size();
		for (int y = 0; y < size_col; y++)
		{
			if (hight_node[i][y] == value)
			{
				return size_row - i - 1;
			}
		}
	}
	return -1;
}
int Level(NODE* pRoot, NODE* p)
{
	vector<vector<int>>level_node;
	level_node = LevelOrder(pRoot);
	int size_row = level_node.size();
	for (int i = 0; i < size_row; i++)
	{
		int size_col = level_node[i].size();
		for (int y = 0; y < size_col; y++)
		{
			if (level_node[i][y] == p->key)
			{
				return i;
			}
		}
	}
	return -1;
}
int countLeaf(NODE* pRoot)//Ap dung pre_order
{
	stack<NODE*>node;
	NODE* temp = pRoot;
	int number_leaf=0;
	while (temp != NULL || !node.empty())
	{
		while (temp != NULL)
		{
			node.push(temp);
			temp = temp->p_left;
		}
		temp = node.top();
		if (temp->p_left == nullptr && temp->p_right == nullptr)
		{
			number_leaf++;
		}
		node.pop();
		temp = temp->p_right;
	}
	return number_leaf;
}

void insert(NODE* root, int data)
{
	NODE* newleaf = createNode(data);
	NODE* temp = root;
	NODE* pre = NULL;
	while (temp != NULL)
	{
		pre = temp;
		if (temp->key < data)
		{
			temp = temp->p_right;
		}
		else
		{
			temp = temp->p_left;
		}
	}
	if (pre != NULL)
	{
		if (pre->key < data)
		{
			pre->p_right = newleaf;
		}
		else
		{
			pre->p_left = newleaf;
		}
	}
}