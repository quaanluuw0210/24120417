#include<iostream>
#include<string>
#include<fstream>
#include <Windows.h>
#include <time.h>
#include"Sorting.h"
#include<chrono>
using namespace std;
using namespace std::chrono;
int main(int argc, char* argv[])
{
	char argothims[50];
	char source[100];
	char destination[100];
	double count = 0;
	if (argc != 7)
	{
		cerr << "Errol !";
		return 0;
	}
	for (int i = 0; i < argc; i++) {
		 

		if (strcmp(argv[i], "-a") == 0 && (i + 1 < argc)) {
			strcpy_s(argothims, argv[i + 1]);
		}
		else if (strcmp(argv[i], "-i") == 0 && (i + 1 < argc)) {
			strcpy_s(source, argv[i + 1]);
		}
		else if (strcmp(argv[i], "-o") == 0 && (i + 1 < argc)) {
			strcpy_s(destination, argv[i + 1]); 
		}
	}
	fstream fs;
	fs.open(source, ios::in);
	int n;
	fs >> n;
	int* nums = new int[n];
	for (int i = 0; i < n; i++)
	{
		fs >> nums[i];
	}
	auto start = high_resolution_clock::now();
	if (strcmp(argothims, "selection_sort") == 0)
	{
		
		selection_sort(nums, n);
		
	}
	else if (strcmp(argothims, "insertion_sort") == 0)
	{
		
		insertion_sort(nums, n);
		
	}
	else if (strcmp(argothims, "bubble_sort") == 0)
	{
		
		bubble_sort(nums, n);
		
	}
	else if (strcmp(argothims, "heap_sort") == 0)
	{
		
		heap_sort(nums, n);
		
	}
	else if (strcmp(argothims, "shaker_sort") == 0)
	{
		
		shaker_sort(nums, n);
		
	}
	else if (strcmp(argothims, "shell_sort") == 0)
	{
		
		shell_sort(nums, n);
		
	}
	else if (strcmp(argothims, "quick_sort") == 0)
	{
		quicksort(nums,0,n-1); 
	}
	else if (strcmp(argothims, "merge_sort") == 0)
	{
		merge_sort(nums, 0,n-1);
	}
	else if (strcmp(argothims, "counting_sort") == 0)
	{
		counting_sort(nums, n);
	}
	else if (strcmp(argothims, "radix_sort") == 0)
	{
		radix_sort(nums, n);
	}
	else
	{
		flashsort(nums, n);
	}
	fs.close();
	fs.open(destination, ios::out);
	for (int i = 0; i < n; i++)
	{
		fs << nums[i] << " ";
	}
	fs.close();
	delete[]nums;
}