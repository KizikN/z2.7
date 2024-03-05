//Определить число элементов k-ого уровня.

#include<iostream>
using namespace std;

int k = 0;
bool check = false;

struct TREE
{
	int  d;           
	TREE* left;
	TREE* right;
};

TREE* search(TREE*, int);
void    add(TREE*&, int);
void print_tree(TREE*);
void    print_tree_level(TREE*, int);

void main()
{
	int b[] = { 20, 10, 8, 12, 30, 25, 34, 22 };
	cout << "k = ";
	cin >> k;
	TREE* top = NULL;

	for (int i = 0; i < 8; i++)
		add(top, b[i]); 

	cout << " tree 1" << endl;
	print_tree(top);  
	cout << endl << endl;
	print_tree_level(top, 0);
	if (!check)
		cout << "No elements of " << k << " level.\n";
}

TREE* search(TREE* top, int d)
{
	TREE* pv = top, * ppv = top;
	while (pv)
	{
		ppv = pv;
		if (d < pv->d)
			pv = pv->left;
		else
			pv = pv->right;
	}
	return ppv;
}

void add(TREE*& top, int d)
{
	TREE* pnew = new TREE;  
	pnew->d = d;
	pnew->left = NULL;
	pnew->right = NULL;
	if (!top)
		top = pnew;
	else
	{
		TREE* ppv;
		ppv = search(top, d); 
		if (d < ppv->d)
			ppv->left = pnew;
		
		else
			ppv->right = pnew;
	}
}

void print_tree(TREE* top)
{
	if (top)
	{
		print_tree(top->left);
		cout << top->d << "  ";
		print_tree(top->right);
	}
}

void print_tree_level(TREE* top, int level)
{
	if (top && level <= k)
	{
		print_tree_level(top->left, level + 1);
		
		/*for (int i = 0; i < level; i++)
			cout << "    ";*/

		if (level == k)
		{
			cout << top->d << endl;
			check = true;
		}

		print_tree_level(top->right, level + 1);
	}

}