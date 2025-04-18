#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct NODE {
	int key;
	NODE* p_next;
};
struct Stack {
	NODE* top;
};
NODE* createNode(int key)
{
	NODE* newnode = new NODE();
	newnode->key = key;
	newnode->p_next = NULL;
	return newnode;
}
Stack* initializeStack()
{
	Stack* s = new Stack();
	s->top = NULL;
	return s;
}
void push(Stack* s, int key)
{
	NODE* new_node = createNode(key);
	if (s->top == NULL)
	{
		s->top = new_node;
		return;
	}
	new_node->p_next = s->top;
	s->top = new_node;
	return;

}
int pop(Stack* s)
{
	if (s->top == NULL)
	{
		return -1;
	}
	NODE* temp = s->top->p_next;
	int key = s->top->key;
	if (temp == NULL)
	{
		delete s->top;
		s->top = NULL;
	}
	else
	{
		delete s->top;
		s->top = temp;
	}
	return key;
}
int size(Stack* s)
{
	NODE* t = s->top;
	int size = 0;
	while (t != NULL)
	{
		size++;
		t = t->p_next;
	}
	return size;
}
bool isEmpty(Stack* s)
{
	if (s->top == NULL)
	{
		return true;
	}
	return false;
}
int find_function(char* str)
{

	int i = 0;
	char* func = new char[100];
	while (str[i] != ' ' && str[i] != '\0')
	{
		func[i] = str[i];
		i++;
	}
	func[i] = '\0';
	if (strcmp(func, "push") == 0)
	{
		delete []func;
		return 1;
	}
	if (strcmp(func, "pop") == 0)
	{
		delete []func;
		return 2;
	}
	if (strcmp(func, "init") == 0)
	{
		delete []func;
		return 3;
	}
	if (strcmp(func, "size") == 0)
	{
		delete[]func;
		return 4;

	}
	delete []func;
	return -1;
}
int main()
{
	fstream fs, fo;
	fs.open("input.txt", ios::in);
	fo.open("output.txt", ios::out);
	fo.close();
	if (fs.is_open())
	{
		fo.open("output.txt", ios::app);
		char* str = new char[1000];
		str[0] = '\0';
		while (!fs.eof()) {
			
			if(strcmp(str,"init")!=0)
			fs.getline(str, 1000);
			if (strcmp(str, "init") != 0)
			{
				break;
			}
			Stack* newstack = initializeStack();
			fo << "EMPTY" << "\n";
			string Stack_val;
			while (!fs.eof())
			{
				fs.getline(str, 1000);
				int func = find_function(str);
				if (func == 1)
				{
					int y = 0;
					char* so = new char[100];
					while (str[y] != ' ')
					{
						y++;
					}
					int t = 0;
					while (str[y] != '\0')
					{
						so[t] = str[y];
						t++; y++;
					}

					int n = atoi(so);
					delete[]so;
					Stack_val = Stack_val + to_string(n) + " ";
					Stack_val.erase(Stack_val.length() - 1, 1);
					fo << Stack_val << "\n";
					Stack_val = Stack_val + " ";
					push(newstack, n);
				}
				if (func == 2)
				{

					pop(newstack);
					if (isEmpty(newstack))
					{
						fo << "EMPTY" << "\n";
					}
					else
					{
						int size = Stack_val.length();
						if (size >= 3)
						{
							int t = size -2;
							if (t >= 0) {
								Stack_val.erase(Stack_val.length() - 1, 1);
								while (Stack_val[t] != ' ')
								{
									Stack_val.erase(Stack_val.length() - 1, 1);
									t--;
								}
								Stack_val.erase(Stack_val.length() - 1, 1);
								fo << Stack_val << "\n";
								Stack_val = Stack_val + " ";
							}
						}

					}
				}
				else if (func == 3)
				{
					break;
				}
				else if (func == 4)
				{
					int size_s = size(newstack);
					fo << size_s << '\n';
				}
				
			}
		}
		delete[]str;
		fo.close();
		fs.close();
	}
}
