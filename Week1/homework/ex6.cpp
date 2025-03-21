#include<iostream>
using namespace std;
int  n;
//ta tạo các mảng bool và gán giá trị ban đầu bằng false
//nếu vị trí đó đã tồn tại con hậu đổi giá trị nó bằng true.Lưu ý mảng cheoduoi sẽ có index là row - col + n - 1 để đảm bảo index không âm.
//VD: Q(0; 2)->mảng cot sẽ có cot[2] = true; mảng cheoduoi có cheotren[0 + 2] = true;
//cuối cùng là cheoduoi[0 - 2 + n - 1] = true.Sau đó ta đặt con hậu ở hàng 1 vô vị trí
//(1, 3) thấy cot[1] == false nên thỏa mãn cột, cheotren[4] == false thỏa mãn, nhưng
//cheoduoi[1 - 3 + n - 1] == true vì vậy vị trí(1, 3) không thỏa mãn.
bool isSafe(bool* cot,bool *cheotren,bool *cheoduoi,int i,int j)
{
	if (cot[j] == true)
	{
		return false;
	}
	if (cheotren[i + j] == true)
	{
		return false;
	}
	if (cheoduoi[i - j + n - 1] == true)
	{
		return false;
	}
	return true;	
}
void printSolution(int* index) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			if (index[i] == j)
			{
				cout << " Q ";
			}
			else
			{
				cout << " . ";
			}
		}
		cout << endl;
	}
	cout << endl;
}
//Hàm truyền vô hang số hàng của bàn cờ, index lưu vị trí các con hậu theo cột thỏa mãn
//Các mảng bool để kiểm tra vị trí con hậu có an toàn
//Ban đầu ta gán mọi giá trị của hàng 0
//Đệ quy tới hàng 1. 
//Nếu mọi phần tử ở hàng 1 không thỏa ta có các câu lệnh để gán lại giá trị false để thử các vị trí tiếp theo
void Nqueen(int hang,int* index, bool* cot, bool* cheotren, bool* cheoduoi)
{
	if (hang == n)
	{
		printSolution(index);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (isSafe(cot, cheotren, cheoduoi, hang, i))
		{
			cot[i] = true;
			cheotren[hang + i] = true;
			cheoduoi[hang - i + n - 1] = true;
			index[hang] = i;
			Nqueen(hang + 1, index, cot, cheotren, cheoduoi);
			cot[i] = false;
			cheotren[hang + i] = false;
			cheoduoi[hang - i + n - 1] = false;
			index[hang] = -1;
		}
	}
}
int main()
{
	cin >> n;
	bool* cot = new bool[n]();
	int* index = new int[n]();
	bool* cheotren = new bool[2*n-1]();
	bool* cheoduoi = new bool[2*n-1];
	
	Nqueen(0, index, cot, cheotren, cheoduoi);
	
}
