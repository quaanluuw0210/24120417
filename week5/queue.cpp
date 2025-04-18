#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct NODE {
	int key;
	NODE* p_next;
};
struct Queue {
	NODE* head;
	NODE* tail;
};
NODE* createNode(int key)
{
	NODE* newnode = new NODE;
	newnode->p_next = NULL;
	newnode->key = key;
	return newnode;
}
Queue* initializeQueue()
{
	Queue* q = new Queue();
	q->head = NULL;
	q->tail = NULL;
	return q;
}
void enqueue(Queue* q, int key)
{
	NODE* newnode_TQ = createNode(key);
	if (q->head == NULL)
	{
		q->head = newnode_TQ;
		q->tail = newnode_TQ;
	}
	else
	{
		q->tail->p_next = newnode_TQ;
		q->tail = newnode_TQ;
	}
}
int dequeue(Queue* q)
{
	if (q->head == NULL)
	{
		return -1;
	}
	int val;
	NODE* temp = q->head;
	val = temp->key;
	if (temp->p_next == NULL)
	{
		delete temp;
		q->head = NULL;
		q->tail = NULL;
	}
	else
	{
		q->head = temp->p_next;
		delete temp;
	}
	return val;
}
int size(Queue *q)
{
	int size_q= 0;
	NODE* t = q->head;
	while (t != NULL)
	{
		size_q++;
		t = t->p_next;
	}
	return size_q;
}
bool isEmpty(Queue* q)
{
	if (q->head == NULL)
	{
		return true;
	}
	return false;
}
int tim_lenh(char* lenh)
{
	int i = 0;
	char* ma_lenh = new char[100];
	while (lenh[i] != '\0' && lenh[i] != ' ')
	{
		ma_lenh[i] = lenh[i];
		i++;
	}
	ma_lenh[i] = '\0';
	if (strcmp(ma_lenh, "init")==0)
	{
		return 1;
	}
	else if (strcmp(ma_lenh, "enqueue")==0)
	{
		return 2;
	}
	else if (strcmp(ma_lenh, "dequeue")==0)
	{
		return 3;
	}
	else if (strcmp(ma_lenh, "size"))
	{
		return 4;
	}
	return -1;
}
int main()
{
	fstream fi;
	fstream fo;
	fo.open("output.txt", ios::out);
	fo.close();
	fi.open("input.txt", ios::in);
	fo.open("output.txt", ios::app);
	if (fi.is_open())
	{
		char* lenh = new char[1000];
		lenh[0] = '\0';
		while (!fi.eof())
		{
			if (strcmp(lenh, "init") != 0)
			{
				fi.getline(lenh, 1000);
				fo << "EMPTY\n";
			}
			Queue* q = initializeQueue();
			if (strcmp(lenh, "init") != 0)
			{
				break;
			}
			while (!fi.eof())
			{
			
				fi.getline(lenh, 1000);
				int ma_lenh = tim_lenh(lenh);
				if (ma_lenh == 1)
				{
					fo << "EMPTY" << "\n";
					break;
				}
				else if (ma_lenh == 2)
				{
					char* so = new char[10];
					int i = 0;
					while (lenh[i] != ' ' && lenh[i] != '\0')
					{
						i++;
					}
					i = i + 1;
					int t = 0;
					while (lenh[i] != '\0')
					{
						so[t] = lenh[i];
						t++; i++;
					}
					so[t] = '\0';
					int key = atoi(so);
					delete[]so;
					enqueue(q, key);
					NODE* temp = q->head;
					while (temp != NULL)
					{
						fo << temp->key;
						if (temp->p_next != NULL)
						{
							fo << " ";
						}
						temp = temp->p_next;
					}
					fo << '\n';
				}
				else if(ma_lenh==3)
				{
					dequeue(q);
					if (isEmpty(q))
					{
						fo << "EMPTY" << "\n";
					}
					else
					{
						NODE* temp = q->head;
						while (temp != NULL)
						{
							fo << temp->key;
							if (temp->p_next != NULL)
							{
								fo << " ";
							}
							temp = temp->p_next;
						}
						fo << '\n';
						
					}
				}
				else if (ma_lenh == 4)
				{
					int size_q = size(q);
					fo << size_q << "\n";
				}
			}
		}
		
	}
	fo.close();
	fi.close();
}