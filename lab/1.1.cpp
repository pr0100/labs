#include <iostream>
#include "Matrix.h"
using namespace std;

Matrix3x3::Matrix3x3()
{
	for (int i = 0; i < m_size; i++)
		for (int j = 0; j < m_size; j++)
			matrix[i][j] = 0;
}

int Matrix3x3::element(const int i, const int j) const
{
	return matrix[i][j];
}

void Matrix3x3::setElement(const int i, const int j, const int value)
{
	matrix[i][j] = value;
}

void Matrix3x3::fillRandomElements(const int minVal, const int maxVal)
{
	for (int i = 0; i < m_size; i++) {
		for (int j = 0; j < m_size; j++)
			matrix[i][j] = rand() % (maxVal - minVal) + minVal;
	}
}

int Matrix3x3::sumPrincipalDiag() const
{
	int sumPrin = 0;
	for (int i = 0; i < m_size; i++) {
		for (int j = 0; j < m_size; j++) {
			if (i == j)
				sumPrin += matrix[i][j];
		}
	}
	return sumPrin;
}

int Matrix3x3::sumSecondaryDiag() const
{
	int sumSec = 0;
	for (int i = 0; i < m_size; i++) {
		for (int j = 0; j < m_size; j++) {
			if (i + j == m_size - 1)
				sumSec += matrix[i][j];
		}
	}
	return sumSec;
}

int Matrix3x3::productPrincipalDiag() const
{
	int productPrin = 1;
	for (int i = 0; i < m_size; i++) {
		for (int j = 0; j < m_size; j++) {
			if (i == j)
				productPrin *= matrix[i][j];
		}
	}
	return productPrin;
}

int Matrix3x3::productSecondaryDiag() const
{
	int productSec = 1;
	for (int i = 0; i < m_size; i++) {
		for (int j = 0; j < m_size; j++) {
			if (i + j == m_size - 1)
				productSec *= matrix[i][j];
		}
	}
	return productSec;
}

int Matrix3x3::sumRow(const int iRow) const
{
	int sumRow = 0;
	for (int i = 0; i < m_size; i++) {
		if (i == iRow) {
			for (int j = 0; j < m_size; j++)
				sumRow += matrix[i][j];
		}
	}
	return sumRow;
}

int Matrix3x3::minColumn(const int iCol) const
{
	int min = matrix[0][iCol];
	for (int i = 0; i < m_size; i++) {
		for (int j = 0; j < m_size; j++) {
			if (j == iCol && matrix[i][j] < min)
				min = matrix[i][j];
		}
	}
	return min;
}

int Matrix3x3::maxColumn(const int iCol) const
{
	int max = matrix[0][iCol];
	for (int i = 0; i < m_size; i++) {
		for (int j = 0; j < m_size; j++) {
			if (j == iCol && matrix[i][j] > max)
				max = matrix[i][j];
		}
	}
	return max;
}
