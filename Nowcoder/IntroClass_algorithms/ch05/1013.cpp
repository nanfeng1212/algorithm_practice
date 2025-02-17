#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
        int a[8]={1,2,3,4,5,6,7,8}, n=8;
		do {
			for (int i = 0; i <= 7; i++)
				std::cout << a[i] << " ";
			std::cout << std::endl;
		}while(next_permutation(a, a + n));
	return 0;
}