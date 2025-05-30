#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>
#include<queue>
#include <algorithm>
#include <stack>
using namespace std;
vector<vector<int>> convertMatrixToList(const string& filename);
vector<vector<int>> convertListToMatrix(const string& filename);

bool isDirected(const vector<vector<int>>& adjMatrix);
int countVertices(const vector<vector<int>>& adjMatrix);
int countEdges(const vector<vector<int>>& adjMatrix);
vector<int> getIsolatedVertices(const vector<vector<int>>& adjMatrix);
bool isCompleteGraph(const vector<vector<int>>& adjMatrix);
bool isBipartite(const vector<vector<int>>& adjMatrix);
bool isCompleteBipartite(const vector<vector<int>>& adjMatrix);

vector<vector<int>> convertToUndirectedGraph(const vector<vector<int>>& adjMatrix);
vector<vector<int>> getComplementGraph(const vector<vector<int>>& adjMatrix);

vector<int> findEulerCycle(const vector<vector<int>>& adjMatrix);
vector<vector<int>> dfsSpanningTree(const vector<vector<int>>& adjMatrix, int start);
vector<vector<int>> bfsSpanningTree(const vector<vector<int>>& adjMatrix, int start);

bool isConnected(int u, int v, const vector<vector<int>>& adjMatrix);

vector<int> dijkstra(int start, int end, const vector<vector<int>>& adjMatrix);
vector<int> bellmanFord(int start, int end, const vector<vector<int>>& adjMatrix);
vector<vector<int>> convertListToMatrix(const string& filename)
{
	fstream input_file;
	input_file.open(filename, ios::in);
	vector<vector<int>> List;
	if (input_file.is_open())
	{
		string str;
		getline(input_file, str);
		int number_row = stoi(str);
		List.push_back({ number_row });
		for (int i = 0; i < number_row; i++)
		{
			vector<int> row(number_row, 0);
			getline(input_file, str);
			string str_number_element = "";
			int size = 0;
			while (size < str.length() && str[size] != ' ')
			{
				str_number_element = str_number_element + str[size];
				size++;
			}
			int number_element = stoi(str_number_element);
			if (number_element == 0)
			{
				List.push_back(row);
				continue;
			}
			else if (number_element > 0)
			{
				for (int y = 0; y < number_element; y++)
				{
					size++;
					string str_pos = "";
					while (str[size] != '\0' && size < str.length() && str[size] != ' ')
					{
						str_pos = str_pos + str[size];
						size++;
					}
					int pos = stoi(str_pos);
					row[pos] = 1;
				}
			}
			List.push_back(row);
		}
		input_file.close();
		return List;
	}
	return List;
}
vector<vector<int>> convertMatrixToList(const string& filename)
{
	vector<vector<int>>matrix;
	fstream input_file;
	input_file.open(filename, ios::in);
	if (input_file.is_open())
	{
		int number_row = 0;
		input_file >> number_row;
		matrix.push_back({ number_row });
		for (int i = 0; i < number_row; i++)
		{
			vector<int>pos;
			for (int y = 0; y < number_row; y++)
			{
				int value = 0;
				input_file >> value;
				if (value != 0)
				{
					pos.push_back(y);
				}
			}
			pos.insert(pos.begin(), pos.size());
			matrix.push_back(pos);
		}
		input_file.close();
	}
	return matrix;
}
bool isDirected(const vector<vector<int>>& adjMatrix)//Ham nay can kiem tra ky lai
{
	vector<vector<int>>Matrix=adjMatrix;
	Matrix.erase(Matrix.begin());
	int row = Matrix.size();
	for (int i = 0; i < row; i++)
	{
		int column = Matrix[i].size();
		int count = 0;
		for (int y = 0; y < column; y++)
		{
			if (Matrix[i][y] == 1)
			{
				if (Matrix[y][i] == 1)
				{
					return false;
				}
			}
		}
	}
	return true;
}
void print2DVector(const vector<vector<int>>& vec)
{
	for (const auto& row : vec)
	{ // Lặp qua từng hàng
		for (int num : row)
		{                       // Lặp qua từng phần tử trong hàng
			cout << num << " "; // In ra phần tử, cách nhau bởi dấu cách
		}
		cout << endl; // Xuống dòng sau khi in một hàng
	}
}
int countVertices(const vector<vector<int>>& adjMatrix)//Ham nay can kiem tra ky lai
{
	vector<vector<int>>Matrix = adjMatrix;
	Matrix.erase(Matrix.begin());
	int row = Matrix.size();
	int number_Vertices = 0;
	for (int i = 0; i < row; i++)
	{
		int column = Matrix[i].size();
		int count = 0;
		for (int y = 0; y < column; y++)
		{
			if (Matrix[i][y] == 1)
			{
				count++;
			}
		}
		if (count != 0)
		{
			number_Vertices++;
		}
	}
	return number_Vertices;
}
int countEdges(const vector<vector<int>>& adjMatrix)// dem song gan cai doi xung no bang 0
{
	vector<vector<int>>matrix = adjMatrix;
	matrix.erase(matrix.begin());
	int row = matrix.size();
	int count = 0;
	for (int i = 0; i < row; i++)
	{
		int column = matrix[i].size();
		for (int y = 0; y < column; y++)
		{
			if (matrix[i][y] == 1)
			{
				count++;
				matrix[y][i] = 0;
			}
		}
	}
	return count;
}
vector<int> getIsolatedVertices(const vector<vector<int>>& adjMatrix)//Ham nay can kiem tra ky lai
{
	vector<int>IsoVer;
	vector<vector<int>>Matrix = adjMatrix;
	Matrix.erase(Matrix.begin());
	for (int i = 0; i < Matrix.size(); i++)
	{
		int sum = 0;
		for (int y = 0; y < Matrix[i].size(); y++)
		{
			sum = sum + Matrix[i][y] + Matrix[y][i];
		}
		if (sum == 0)
		{
			IsoVer.push_back(i);
		}
	}
	return IsoVer;
}
bool isCompleteGraph(const vector<vector<int>>& adjMatrix)//Ham nay can kiem tra ky lai
{
	vector<vector<int>>matrix = adjMatrix;
	matrix.erase(matrix.begin());
	for (int i = 0; i < matrix.size(); i++)
	{
		int sum = 0;
		for (int y = 0; y < matrix[i].size(); y++)
		{
			if (i == y)
			{
				if (matrix[i][y] == 1)
				{
					return false;
				}
			}
			sum = sum + matrix[i][y];
		}
		if (sum != matrix[i].size() - 1)
		{
			return false;
		}
	}
	return true;
}
bool isBipartite(const std::vector<std::vector<int>>& adjMatrix)
{
	queue<int>var;
	vector<int>color(adjMatrix[0][0], -1);
	vector<vector<int>>matrix = adjMatrix;
	matrix.erase(matrix.begin());
	for (int i = 0; i < matrix.size(); i++)
	{
		if (color[i] == -1)
		{
			color[i] = 0;
			var.push(i);
			while (!var.empty())
			{
				int element = var.front();
				var.pop();
				for (int y = 0; y < matrix[i].size(); y++)
				{
					if (matrix[i][y] == 1)
					{
						if (color[y] == -1)
						{
							color[y] = 1 - color[i];
							var.push(y);
						}
						else
						{
							if (color[y] == color[i])
							{
								return false;
							}
						}
					}
				}
			}
		}
	}
	return true;
}
bool isCompleteBipartite(const vector<vector<int>>& adjMatrix)
{
	queue<int>var;
	vector<int>color(adjMatrix[0][0], -1);
	vector<vector<int>>matrix = adjMatrix;
	matrix.erase(matrix.begin());
	for (int i = 0; i < matrix.size(); i++)
	{
		if (color[i] == -1)
		{
			color[i] = 0;
			var.push(i);
			while (!var.empty())
			{
				int element = var.front();
				var.pop();
				for (int y = 0; y < matrix[i].size(); y++)
				{
					if (matrix[i][y] == 1)
					{
						if (color[y] == -1)
						{
							color[y] = 1 - color[i];
							var.push(y);
						}
						else
						{
							if (color[y] == color[i])
							{
								return false;
							}
						}
					}
				}
			}
		}
	}
	vector<int>color_0;
	vector<int>color_1;
	for (int i = 0; i < color.size(); i++)
	{
		if (color[i] = 0)
		{
			color_0.push_back(i);
		}
		else
		{
			color_1.push_back(i);
		}
	}
	for (int i = 0; i < color_0.size(); i++)
	{
		for (int y = 0; y < color_1.size(); y++)
		{
			if (matrix[i][y] != -1)
			{
				return false;
			}
		}
	}
	for (int i = 0; i < color_1.size(); i++)
	{
		for (int y = 0; y < color_0.size(); y++)
		{
			if (matrix[i][y] != -1)
			{
				return false;
			}
		}
	}
	return true;
}
vector<vector<int>> convertToUndirectedGraph(const vector<vector<int>>& adjMatrix)
{
	vector<vector<int>>matrix = adjMatrix;
	matrix.erase(matrix.begin());
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int y = 0; y < matrix[i].size(); y++)
		{
			if (matrix[i][y] == 1)
			{
				matrix[y][i] = 1;
			}
		}
	}
	matrix.insert(matrix.begin(), adjMatrix[0]);
	return matrix;
}
vector<vector<int>> getComplementGraph(const vector<vector<int>>& adjMatrix)
{
	vector<vector<int>>matrix = adjMatrix;
	matrix.erase(matrix.begin());
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int y = 0; y < matrix[i].size(); y++)
		{
			if (matrix[i][y] != 1)
			{
				if(i!=y)
				matrix[i][y] = 1;
			}
		}
	}
	matrix.insert(matrix.begin(), adjMatrix[0]);
	return matrix;
}
vector<int> findEulerCycle(const vector<vector<int>>& adjMatrix)
{
	vector<vector<int>>matrix = adjMatrix;
	matrix.erase(matrix.begin());
	vector<int> eulercycle;
	int start = -1;
	if (isDirected(adjMatrix))
	{
		for (int i = 0; i < matrix.size(); i++)
		{
			int in = 0, out = 0;
			for (int y = 0; y < matrix.size(); y++)
			{
				out=out+ matrix[i][y];
				in=in + matrix[y][i];
			}
			if (in != out)
			{
				return eulercycle;
			}
			if (out > 0 && start == -1) start = i;
		}
		
	}
	else
	{
		for (int i = 0; i < matrix.size(); i++)
		{
			int degree = 0;
			for (int y = 0; y < matrix.size(); y++)
			{
				degree = degree + matrix[i][y];
			}
			if (degree % 2 != 0)
			{
				return eulercycle;
			}
			if (degree > 0 && start == -1) start = i;
		}
	}
	vector<int>ver;
	ver.push_back(start);
	bool t = isDirected(adjMatrix);
	while (!ver.empty())
	{
		int u = ver[ver.size()-1];
		bool found = 0;
		for (int i = 0; i < matrix[u].size(); i++)
		{
			
			if (matrix[u][i] == 1)
			{
				matrix[u][i]--;
				if (t==0)
				{
					matrix[i][u]--;
				}
				found = 1;
				ver.push_back(i);
				break;
			}
			
		}
		if (found == 0)
		{
			ver.pop_back();
			eulercycle.push_back(u);
		}
	}
	for (int i = 0; i < matrix.size(); ++i)
		for (int j = 0; j < matrix.size(); ++j)
			if (matrix[i][j] > 0) return {};
	reverse(eulercycle.begin(), eulercycle.end());
	return eulercycle;
}
vector<vector<int>> dfsSpanningTree(const vector<vector<int>>& adjMatrix, int start) {
	vector<vector<int>>Matrix = adjMatrix;
	Matrix.erase(Matrix.begin());
	int n = Matrix.size();
	vector<vector<int>> tree(n, vector<int>(n, 0));
	vector<bool> visited(n, false);
	stack<int> st;

	bool directed = isDirected(adjMatrix);

	st.push(start);
	visited[start] = true;

	while (!st.empty()) {
		int u = st.top();
		bool foundUnvisited = false;

		for (int v = 0; v < n; ++v) {
			if (Matrix[u][v] && !visited[v]) {
				visited[v] = true;
				tree[u][v] = 1;
				if (!directed) {
					tree[v][u] = 1;
				}
				st.push(v);
				foundUnvisited = true;
				break;
			}
		}

		if (!foundUnvisited) {
			st.pop();
		}
	}

	return tree;
}
queue<int> get_ver(const vector<vector<int>>& Matrix, int start)
{
	queue<int>ver;
	for (int y = 0; y < Matrix[start].size(); y++)
	{
		if (Matrix[start][y] == 1)
		{
			ver.push(y);
		}
	}
	return ver;
}
vector<vector<int>> bfsSpanningTree(const vector<vector<int>>& adjMatrix, int start) {
	vector<vector<int>>Matrix = adjMatrix;
	Matrix.erase(Matrix.begin());
	int n = Matrix.size();
	vector<vector<int>> tree(n, vector<int>(n, 0));
	vector<bool> visited(n, false);
	queue<int> q;

	bool directed = isDirected(adjMatrix);

	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int u = q.front(); q.pop();

		for (int v = 0; v < n; ++v) {
			if (Matrix[u][v] && !visited[v]) {
				visited[v] = true;
				tree[u][v] = 1;
				if (!directed) {
					tree[v][u] = 1; 
				}
				q.push(v);
			}
		}
	}
	return tree;
}


bool isConnected(int u, int v, const vector<vector<int>>& adjMatrix)
{
	vector<vector<int>>Matrix = adjMatrix;
	Matrix.erase(Matrix.begin());
	int n = Matrix.size();
	vector<bool> visited(n, false);
	queue<int> q;

	q.push(u);
	visited[u] = true;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		if (curr == v) return true;

		for (int i = 0; i < n; ++i) {
			if (Matrix[curr][i] != 0 && !visited[i]) {
				visited[i] = true;
				q.push(i);
			}
		}
	}
	return false;
}
const int INF = 1000000000;

vector<int> dijkstra(int start, int end, const vector<vector<int>>& adjMatrix) {

	vector<vector<int>>Matrix = adjMatrix;
	Matrix.erase(Matrix.begin());
	int n = Matrix.size();
	vector<int> dist(n, INF);
	vector<int> prev(n, -1);
	vector<bool> visited(n, false);
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

		if (visited[u])
			continue;
		visited[u] = true;

		for (int v = 0; v < n; ++v) {
			if (Matrix[u][v] > 0) {
				int weight = Matrix[u][v];
				if (dist[u] + weight < dist[v]) {
					dist[v] = dist[u] + weight;
					prev[v] = u;
					pq.push({ dist[v], v });
				}
			}
		}
	}
	vector<int> path;
	if (dist[end] == INF)
		return path; 

	for (int at = end; at != -1; at = prev[at])
		path.push_back(at);
	reverse(path.begin(), path.end());
	return path;
}
vector<int> bellmanFord(int start, int end, const vector<vector<int>>& adjMatrix) {

	vector<vector<int>>Matrix = adjMatrix;
	Matrix.erase(Matrix.begin());
	int n = Matrix.size();
	vector<int> dist(n, INF);   
	vector<int> prev(n, -1);   

	dist[start] = 0;

	for (int k = 0; k < n - 1; ++k) {
		for (int u = 0; u < n; ++u) {
			for (int v = 0; v < n; ++v) {
				if (Matrix[u][v] != 0 && dist[u] != INF) {
					if (dist[u] + Matrix[u][v] < dist[v]) {
						dist[v] = dist[u] + Matrix[u][v];
						prev[v] = u;
					}
				}
			}
		}
	}
	vector<int> path;
	if (dist[end] == INF) return path;
	for (int at = end; at != -1; at = prev[at])
		path.push_back(at);
	for (int i = 0; i < path.size() / 2; ++i)
		swap(path[i], path[path.size() - 1 - i]);
	return path;
}
