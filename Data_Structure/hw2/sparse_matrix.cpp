// 4109061012
#include <cstdlib>
#include <iostream>

using namespace std;


class Matrix;

class MatrixTerm{
	friend class Matrix;
	private:
		int row, col, value;
};

class Matrix {
	public:
		Matrix(int r, int c, int t) {
			rows = r;
			cols = c;
			terms = (r*c > t) ? t : r*c;
			mat_arr = new MatrixTerm[t];
		}

		Matrix Transpose();
		Matrix Add(Matrix &b);
		Matrix Multiply(Matrix &b);

		int Determinant();
		Matrix Adjoint();
		Matrix Inverse();
		Matrix Cofactor();

		// Others added by myself
		void input();
		void show();
		void print_MatrixArray();
		Matrix operator+(Matrix &b) {return Add(b);}
		Matrix operator*(Matrix &b) {return Multiply(b);}
		Matrix operator*(int b) {Matrix c = *this; for(int i=0; i<terms; i++) c.mat_arr[i].value *= b; return c;}
		Matrix operator/(int b) {Matrix c = *this; for(int i=0; i<terms; i++) c.mat_arr[i].value /= b; return c;}

	private:
		int rows, cols, terms;
		MatrixTerm *mat_arr;
};


Matrix Matrix::Transpose() {
	// Fast transpose
	Matrix Tmat(cols, rows, terms);

	// row_size
	int *row_size = new int[cols];
	for(int i=0; i<cols; i++) row_size[i] = 0;
	for(int i=0; i<terms; i++) row_size[mat_arr[i].col]++;

	// row_start
	int *row_start = new int[cols];
	row_start[0] = 0;
	for(int i=1; i<cols; i++) row_start[i] = row_start[i-1] + row_size[i-1];

	// Transpose
	for(int i=0; i<terms; i++) {
		Tmat.mat_arr[row_start[mat_arr[i].col]].row = mat_arr[i].col;
		Tmat.mat_arr[row_start[mat_arr[i].col]].col = mat_arr[i].row;
		Tmat.mat_arr[row_start[mat_arr[i].col]].value = mat_arr[i].value;
		row_start[mat_arr[i].col] += 1;
	}
	delete [] row_size;
	delete [] row_start;

	return Tmat;
}

Matrix Matrix::Add(Matrix &b) {
	if((cols != b.cols) || (rows != b.rows)) {
		printf("Dimensions of *this and b are not the same.\n");
		throw;
	}

	if(terms == 0) return b;
	else if(b.terms == 0) return *this;

	// Terms
	int new_terms = cols * rows;
	if(terms+b.terms < new_terms) new_terms = terms + b.terms;

	// Create new one
	int *new_row = new int[new_terms];
	int *new_col = new int[new_terms];
	int *new_value = new int[new_terms];

	int i = 0, j = 0, t = 0;
	for(int r=0; r<rows; r++) {
		for(int c=0; c<cols; c++) {
			new_row[t] = r;
			new_col[t] = c;
			new_value[t] = 0;
			if(r == mat_arr[i].row && c == mat_arr[i].col) {
				new_value[t] += mat_arr[i].value;
				i++;
			}
			if(r == b.mat_arr[j].row && c == b.mat_arr[j].col) {
				new_value[t] += b.mat_arr[j].value;
				j++;
			}
			if(new_value[t] != 0) t++;
		}
	} 

	// New Matrix
	Matrix new_mat(rows, cols, t);
	for(int i=0; i<t; i++) {
		new_mat.mat_arr[i].row = new_row[i];
		new_mat.mat_arr[i].col = new_col[i];
		new_mat.mat_arr[i].value = new_value[i];
	}

	delete [] new_row;
	delete [] new_col;
	delete [] new_value;

	return new_mat;
}

Matrix Matrix::Multiply(Matrix &b) {
	if(cols != b.rows) {
		printf("Matrix *this and Matrix b are not multiply able.\n");
		throw;
	}

	Matrix trans_b = b.Transpose();

	// row_start
	int *row_start1 = new int[rows+1];  // this Matrix
	int *row_start2 = new int[b.cols+1];  // trans_b Matrix
	for(int i=0; i<=rows; i++) row_start1[i] = terms;
	for(int i=0; i<=b.cols; i++) row_start2[i] = b.terms;

	int j = 0;
	for(int i=0; i<terms; i++) {
		while(mat_arr[i].row >= j) {
			row_start1[j] = i;
			j++;
		}
	}
	j = 0;
	for(int i=0; i<trans_b.terms; i++) {
		while(trans_b.mat_arr[i].row >= j) {
			row_start2[j] = i;
			j++;
		}
	}

	// mult & sum
	int *new_row = new int[rows * b.cols];
	int *new_col = new int[rows * b.cols];
	int *new_value = new int[rows * b.cols];
	int d_term = 0;
	for(int r=0; r<rows; r++) {
		for(int c=0; c<b.cols; c++) {
			// Get value of Matrix d [row = i, col = j]
			new_row[d_term] = r;
			new_col[d_term] = c;
			new_value[d_term] = 0;
			for(int i=row_start1[r]; i<row_start1[r+1]; i++) {
				for(int j=row_start2[c]; j<row_start2[c+1]; j++) {
					if(mat_arr[i].col == trans_b.mat_arr[j].col) {
						new_value[d_term] += mat_arr[i].value * trans_b.mat_arr[j].value;
						break;
					}
				}
			}
			if(new_value[d_term] != 0) d_term++;
		}
	}

	// New Matrix
	Matrix d(rows, b.cols, d_term);
	for(int i=0; i<d_term; i++) {
		d.mat_arr[i].row = new_row[i];
		d.mat_arr[i].col = new_col[i];
		d.mat_arr[i].value = new_value[i];
	}
	delete [] row_start1;
	delete [] row_start2;
	delete [] new_row;
	delete [] new_col;
	delete [] new_value;

	return d;
}

int Matrix::Determinant() {
	if(rows != cols) {
		printf("This matrix doesn't have determinant.\n");
		throw;
	}

	if(rows == 1) {
		if(terms == 0) return 0;
		else return mat_arr[0].value;
	}
	else {
		int det = 0;
		for(int i=0; mat_arr[i].row == 0; i++) {
			int a = ((mat_arr[i].row + mat_arr[i].col)%2 == 0) ? 1 : -1;
			int *new_row = new int[terms-1];
			int *new_col = new int[terms-1];
			int *new_value = new int[terms-1];
			int t = 0;
			for(int j=0; j<terms; j++) {
				if(mat_arr[j].row > 0 && mat_arr[j].col != mat_arr[i].col) {
					new_row[t] = mat_arr[j].row - 1;  // row
					new_col[t] = (mat_arr[j].col > mat_arr[i].col) ? mat_arr[j].col - 1 : mat_arr[j].col;  // col
					new_value[t] = mat_arr[j].value;  // value
					t++;
				}
			}
			
			Matrix tmp(rows-1, cols-1, t);
			for(int j=0; j<t; j++) {
				tmp.mat_arr[j].row = new_row[j];
				tmp.mat_arr[j].col = new_col[j];
				tmp.mat_arr[j].value = new_value[j];
			}
			delete [] new_row;
			delete [] new_col;
			delete [] new_value;
			
			det += a * mat_arr[i].value * tmp.Determinant();
		}
		return det;
	}
}

Matrix Matrix::Cofactor() {
	if(rows != cols) {
		printf("This matrix doesn't have cofactor.\n");
		throw;
	}

	int cof_t = 0;
	int *cof_row = new int[rows*cols];
	int *cof_col = new int[rows*cols];
	int *cof_value = new int[rows*cols];
	for(int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
			// Generate minor M_ij
			int minor_t = 0;
			int *minor_row = new int[(rows-1)*(cols-1)];
			int *minor_col = new int[(rows-1)*(cols-1)];
			int *minor_value = new int[(rows-1)*(cols-1)];
			for(int t=0; t<terms; t++) {
				if(mat_arr[t].row != i && mat_arr[t].col != j) {
					minor_row[minor_t] = (mat_arr[t].row > i) ? mat_arr[t].row - 1 : mat_arr[t].row;  // row
					minor_col[minor_t] = (mat_arr[t].col > j) ? mat_arr[t].col - 1 : mat_arr[t].col;  // col
					minor_value[minor_t] = mat_arr[t].value;  // value
					minor_t++;
				}
			}
			Matrix *minor = new Matrix(rows-1, cols-1, minor_t);
			for(int t=0; t<minor_t; t++) {
				minor->mat_arr[t].row = minor_row[t];
				minor->mat_arr[t].col = minor_col[t];
				minor->mat_arr[t].value = minor_value[t];
			}
			delete [] minor_row;
			delete [] minor_col;
			delete [] minor_value;
			
			// Get C_ij
			int c = ((i + j)%2 == 0) ? minor->Determinant() : (-1) * minor->Determinant();
			if(c != 0) {
				cof_row[cof_t] = i;
				cof_col[cof_t] = j;
				cof_value[cof_t] = c;
				cof_t++;
			}
			delete minor;
		}
	}

	// Cofactor Matrix
	Matrix cofactor(rows, cols, cof_t);
	for(int t=0; t<cof_t; t++) {
		cofactor.mat_arr[t].row = cof_row[t];
		cofactor.mat_arr[t].col = cof_col[t];
		cofactor.mat_arr[t].value = cof_value[t];
	}
	delete [] cof_row;
	delete [] cof_col;
	delete [] cof_value;

	return cofactor;
}

Matrix Matrix::Adjoint() {
	if(rows != cols) {
		printf("This matrix doesn't have adjoint.\n");
		throw;
	}
	Matrix cof = Cofactor();
	return cof.Transpose();
}

Matrix Matrix::Inverse() {
	if(rows != cols) {
		printf("This matrix doesn't have inverse.\n");
		throw;
	}
	int det = this->Determinant();
	if(det == 0) {
		printf("This matrix doesn't have inverse.\n");
		throw;
	}
	Matrix adj = this->Adjoint();
	return adj / det;
}

void Matrix::show() {
	int print_term = 0;
	printf("\n");
	for(int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
			if((mat_arr[print_term].row == i) && (mat_arr[print_term].col == j)) {
				printf("%4d ", mat_arr[print_term].value);
				print_term++;
			}
			else {
				printf("   0 ");
			}
		}
		printf("\n");
	}
	printf("\n");
}

void Matrix::print_MatrixArray() {
	printf("\n");
	for(int i=0; i<terms; i++) {
		printf("Value:%3d, (row, col) = (%2d, %2d) \n", mat_arr[i].value, mat_arr[i].row, mat_arr[i].col);
	}
}

void Matrix::input() {
	bool allow_input = true;
	printf("\nPlease input the terms of matrix (row col value):\n");
	for(int i=0; i<terms; i++) {
		printf("matrix array[%d]: ", i);
		scanf("%d %d %d", &mat_arr[i].row, &mat_arr[i].col, &mat_arr[i].value);
		if(mat_arr[i].row >= rows || mat_arr[i].col >= cols) {
			printf("Warning! You must let (row < %d) and (col < %d).\n", rows, cols);
			i--;
		}
		if((i > 0) && (mat_arr[i].row <= mat_arr[i-1].row && mat_arr[i].col <= mat_arr[i-1].col)) {
			printf("Matrix Error! Inputs must follow the order, restart your input please.\n");
			allow_input = false;
			break;
		}
	}
	if(!allow_input) this->input();
}


int main() {
	// Set Matrix A
	int rows, cols, terms;
	printf(">> Setting Matrix A:\n");
	printf("Please enter the size of Mat A (rows cols terms): ");
	scanf("%d %d %d", &rows, &cols, &terms);
	Matrix a(rows, cols, terms);
	a.input();
	printf("Mat A:\n");
	a.show();

	if(rows == cols) {
		// Det
		printf("\nDet(Mat A) = %d\n\n", a.Determinant());

		// Adj
		printf("Adj(Mat A):\n");
		Matrix c = a.Adjoint();
		c.show();

		// Inv
		printf("Inverse(Mat A):\n");
		c = a.Inverse();
		c.show();
	}

	// Set Matrix B
	printf(">> Setting Matrix B:\n");
	printf("Please enter the size of Mat B (rows cols terms): ");
	scanf("%d %d %d", &rows, &cols, &terms);
	Matrix b(rows, cols, terms);
	b.input();
	printf("Mat B:\n");
	b.show();

	// // Add
	// printf("Mat A + Mat B:\n");
	// Matrix d = a + b;
	// d.show();

	// Mult
	printf("Mat A * Mat B:\n");
	Matrix d = a * b;
	d.show();

	return 0;
}
