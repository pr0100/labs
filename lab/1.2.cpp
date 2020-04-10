#include <iostream>
#include "MatrixXnX.h"

using namespace std;

MatrixXnX::MatrixXnX(const int iDim)
{
	control.setMatrix(iDim);
	this->dim = iDim;
	for (int i = 0; i < iDim; i++)
		for (int j = 0; j < iDim; j++)
			control.getMatrix()[i][j] = 0;
}

int MatrixXnX::element(const int i, const int j) const
{
	return control.getMatrix()[i][j];
}

void MatrixXnX::setElement(const int i, const int j, const int value)
{
	control.getMatrix()[i][j] = value;
}

void MatrixXnX::fillRandomElements(const int minVal, const int maxVal)
{
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++)
			control.getMatrix()[i][j] = rand() % (maxVal - minVal) + minVal;
	}
}

int MatrixXnX::sumPrincipalDiag() const
{
	int sumPrin = 0;
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			if (i == j)
				sumPrin += control.getMatrix()[i][j];
		}
	}
	return sumPrin;
}

int MatrixXnX::sumSecondaryDiag() const
{
	int sumSec = 0;
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			if (i + j == dim - 1)
				sumSec += control.getMatrix()[i][j];
		}
	}
	return sumSec;
}

int MatrixXnX::productPrincipalDiag() const
{
	int productPrin = 1;
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			if (i == j)
				productPrin *= control.getMatrix()[i][j];
		}
	}
	return productPrin;
}

int MatrixXnX::productSecondaryDiag() const
{
	int productSec = 1;
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			if (i + j == dim - 1)
				productSec *= control.getMatrix()[i][j];
		}
	}
	return productSec;
}

int MatrixXnX::sumRow(const int iRow) const
{
	int sumRow = 0;
	for (int i = 0; i < dim; i++) {
		if (i == iRow) {
			for (int j = 0; j < dim; j++)
				sumRow += control.getMatrix()[i][j];
		}
	}
	return sumRow;
}

int MatrixXnX::minColumn(const int iCol) const
{
	int min = control.getMatrix()[0][iCol];
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			if (j == iCol && control.getMatrix()[i][j] < min)
				min = control.getMatrix()[i][j];
		}
	}
	return min;
}

int MatrixXnX::maxColumn(const int iCol) const
{
	int max = control.getMatrix()[0][iCol];
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			if (j == iCol && control.getMatrix()[i][j] > max)
				max = control.getMatrix()[i][j];
		}
	}
	return max;
}