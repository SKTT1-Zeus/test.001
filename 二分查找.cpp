#include<iostream>
using namespace std;

int search(int left, int right, int a[], int key)
{
	int f = -1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (a[mid] == key) {
			f = mid;
			break;
		}
		if (key < a[mid])right = mid - 1;
		if (key > a[mid])left = mid + 1;
	}
	if (f == -1)cout << "Ã»ÕÒµ½" << endl;
	else cout << f << endl;
	return 0;
}

int main() {

	int a[] = { 1, 3, 7, 12, 34, 52 ,87 };
	int key = 52;
	cin >> key;
	cout << search(0,6,a,key) << endl;;

	return 0;
}



