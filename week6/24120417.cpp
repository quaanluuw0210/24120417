#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
using namespace std;
struct Company
{
	string name = "";
	string profit_tax = "";
	string address = "";
};
struct HashTable
{
	Company Hash[2000];
};
vector<Company> readCompanyList(string file_name)
{
	fstream mxt;
	mxt.open(file_name, ios::in);
	vector<Company> group_cp;
	if (mxt.is_open())
	{
		string company_data;
		getline(mxt, company_data);
		while (getline(mxt, company_data))
		{
			Company cp;
			int i = 0;
			while (i < company_data.length() && company_data[i] != '|')
			{
				cp.name = cp.name + company_data[i];
				i++;
			}
			i++;
			while (i < company_data.length() && company_data[i] != '|')
			{
				cp.profit_tax = cp.profit_tax + company_data[i];
				i++;
			}
			i++;
			while (i < company_data.length() && company_data[i] != '\0')
			{
				cp.address = cp.address + company_data[i];
				i++;
			}
			group_cp.push_back(cp);
		}
		return group_cp;
	}
	return group_cp;
}
long long mod_2000(long long n)
{
	while (n >= 2000)
	{
		n = n - 2000;
	}
	return n;
}
long long hashString(string company_name)
{
	int i = 0;
	string s = "";
	if (company_name.length() <= 20)
	{
		s = company_name;
	}
	else
	{
		int t = company_name.length() - 20;
		while (t < company_name.length())
		{
			s = s + company_name[t];
			t++;
		}
	}
	long long key = 0;
	long long mod = 1;
	long long p_mod = 1;
	while (i < s.length())
	{
		long long ascii = s[i];
		long long s_mod = mod_2000(s[i]);
		p_mod = mod_2000(31) * p_mod;
		p_mod = mod_2000(p_mod);
		mod = p_mod * s_mod;
		mod = mod_2000(mod);
		key = key + mod;
		i++;
	}
	key = mod_2000(key);
	return key;
}
HashTable *createHashTable(vector<Company> list_company)
{
	int size_list_company = list_company.size();
	int i = 0;
	HashTable *company_data = new HashTable;
	while (i < size_list_company)
	{
		long long key = hashString(list_company[i].name);
		if (company_data->Hash[key].name == "")
		{
			company_data->Hash[key].name = list_company[i].name;
			company_data->Hash[key].address = list_company[i].address;
			company_data->Hash[key].profit_tax = list_company[i].profit_tax;
		}
		else
		{
			int step = 0;
			int origin_key = key;
			while (company_data->Hash[key].name != "" && step < 2000)
			{
				key = origin_key + step;
				key = mod_2000(key);
				step++;
			}
			if(step<200)
			{
			company_data->Hash[key].name = list_company[i].name;
			company_data->Hash[key].address = list_company[i].address;
			company_data->Hash[key].profit_tax = list_company[i].profit_tax;
			}
		}
		i++;
	}
	return company_data;
}
Company *search(HashTable *hash_table, string company_name)
{

	long long key = hashString(company_name);
	int step = 0;
	int origin_key = key;
	Company *cop = new Company;
	while (step < 2000 && hash_table->Hash[key].name != company_name)
	{
		key = origin_key + step;
		key = mod_2000(key);
		step++;
	}
	if (step >= 2000)
	{
		return NULL;
	}
	else
	{
		if (hash_table->Hash[key].name == company_name)
		{
			cop->name = hash_table->Hash[key].name;
			cop->address = hash_table->Hash[key].address;
			cop->profit_tax = hash_table->Hash[key].profit_tax;
		}
	}
	return cop;
}
void insert(HashTable *hash_table, Company company)
{
	long long key=hashString(company.name);
	int step=0;
	long long origin_key=key;
	while(step<2000&&hash_table->Hash[key].name!="")
	{
		key=origin_key+step;
		key=mod_2000(key);
		step++;
	}
	if(step<2000)
	{
		hash_table->Hash[key].name=company.name;
		hash_table->Hash[key].address=company.address;
		hash_table->Hash[key].profit_tax=company.profit_tax;
	}
}
int main(int argc, char *argv[])
{
	string input_file;
	string output_file;
	string mst_file;
	if (argc != 4)
	{
		cerr << "Error";
		return 0;
	}
	for (int i = 0; i < argc; i++)
	{
		if (strcmp("input.txt", argv[i]) == 0)
		{
			input_file = "input.txt";
		}
		else if (strcmp("output.txt", argv[i]) == 0)
		{
			output_file = "output.txt";
		}
		else if (strcmp("MST.txt", argv[i]) == 0)
		{
			mst_file = "MST.txt";
		}
	}

	vector<Company> List_company;
	List_company = readCompanyList(mst_file);
	HashTable *List_company_key = createHashTable(List_company);
	fstream input;
	fstream output;
	input.open(input_file, ios::in);
	if (input.is_open())
	{
		output.open(output_file, ios::app);
		output.close();
		output.open(output_file, ios::out);
		if (output.is_open())
		{
			string cop_name;
			while (getline(input, cop_name))
			{
				Company*cop_info=search(List_company_key,cop_name);
				if(cop_info!=NULL)
				{
					output<<cop_info->name<<"|"<<cop_info->profit_tax<<"|"<<cop_info->address<<endl;
				}
			}
			output.close();
		}
		input.close();
	}
	return 0;
}