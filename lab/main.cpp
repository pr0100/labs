#include <iostream>
#include "Matrix.h"
#include "MatrixXnX.h"
#include "List.h"

/*
Strelkov Stanislav
RI - 280002
*/

using namespace std;

void Matrix3x3Test()
{
	auto matrix = Matrix3x3();
	matrix.fillRandomElements(-10, 10);
	cout << "Matrix3x3:" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) 
			cout << matrix.element(i, j) << "\t";
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
		cout << "Sum of elements in " << i << " row " << matrix.sumRow(i) << endl;
	cout << endl;

	for (int i = 0; i < 3; i++)
		cout << "Minimum element in " << i << " column " << matrix.minColumn(i) <<
		"\nMaximum element in " << i << " column " << matrix.maxColumn(i) << endl;
	cout << endl;
	cout << "Sum of principle diagonal: " << matrix.sumPrincipalDiag() << endl;
	cout << "Sum of secondary diagonal: " << matrix.sumSecondaryDiag() << endl;
	cout << "Product of principle diagonal: " << matrix.productPrincipalDiag() << endl;
	cout << "Product of secondary diagonal: " << matrix.productSecondaryDiag() << endl;
	cout << endl;
}

void MatrixXnXTest(int dim)
{
	auto matrix = MatrixXnX(dim);
	matrix.fillRandomElements(-10, 10);
	cout << "Matrix" << dim << "x" << dim << ":" << endl;
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++)
			cout << matrix.element(i, j) << "\t";
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < dim; i++)
		cout << "Sum of elements in " << i << " row " << matrix.sumRow(i) << endl;
	cout << endl;

	for (int i = 0; i < dim; i++)
		cout << "Minimum element in " << i << " column " << matrix.minColumn(i) <<
		"\nMaximum element in " << i << " column " << matrix.maxColumn(i) << endl;
	cout << endl;
	cout << "Sum of principle diagonal: " << matrix.sumPrincipalDiag() << endl;
	cout << "Sum of secondary diagonal: " << matrix.sumSecondaryDiag() << endl;
	cout << "Product of principle diagonal: " << matrix.productPrincipalDiag() << endl;
	cout << "Product of secondary diagonal: " << matrix.productSecondaryDiag() << endl;
	cout << endl;
}

void ListTest()
{
	List list;
	for (int i = 0; i < 10; i++)
		list.push_back(rand() % 10);
	list.push_back(8);
	list.push_back(7);
	list.push_back(-11);
	list.push_back(5);
	list.push_back(5);
	list.push_back(3);
	cout << "Linked list with duplicates:" << endl;
	list.print();
	cout << endl;
	list.deleteDuplicates();
	cout << "Linked list without duplicates:" << endl;
	list.print();
	cout << endl;
	cout << "5th element to last:\n" << list.kthToLast(5);
}

int main()
{
	Matrix3x3Test();
	MatrixXnXTest(5);
	ListTest();
}