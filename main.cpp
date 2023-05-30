#include <iostream>
#include <vector>

using namespace std;

class Matrix {
private:
    vector<vector<int>> matrix;
public:
    Matrix(vector<vector<int>> m) : matrix(m) {}

    Matrix operator+(const Matrix& other) const {
        vector<vector<int>> result(matrix.size(), vector<int>(matrix[0].size()));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                result[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }
        return Matrix(result);
    }

    Matrix operator-(const Matrix& other) const {
        vector<vector<int>> result(matrix.size(), vector<int>(matrix[0].size()));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                result[i][j] = matrix[i][j] - other.matrix[i][j];
            }
        }
        return Matrix(result);
    }

    Matrix operator*(const Matrix& other) const {
        vector<vector<int>> result(matrix.size(), vector<int>(other.matrix[0].size()));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < other.matrix[0].size(); j++) {
                for (int k = 0; k < matrix[0].size(); k++) {
                    result[i][j] += matrix[i][k] * other.matrix[k][j];
                }
            }
        }
        return Matrix(result);
    }

    void print() const {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void printRow(int row) const {
        for (int i = 0; i < matrix[row].size(); i++) {
            cout << matrix[row][i] << " ";
        }
        cout << endl;
    }

    void printColumn(int column) const {
        for (int i = 0; i < matrix.size(); i++) {
            cout << matrix[i][column] << endl;
        }
    }

    void printMainDiagonal() const {
        for (int i = 0; i < matrix.size(); i++) {
            cout << matrix[i][i] << " ";
        }
        cout << endl;
    }

    void printSecondaryDiagonal() const {
        for (int i = 0; i < matrix.size(); i++) {
            cout << matrix[i][matrix.size() - 1 - i] << " ";
        }
        cout << endl;
    }
};

int main() {
    vector<vector<int>> m1 = {{4, 8, 5}, {7, 5, 6}, {7, 8, 9}};
    vector<vector<int>> m2 = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    Matrix matrix1(m1);
    Matrix matrix2(m2);

    cout << "Matrix 1:" << endl;
    matrix1.print();
    cout << endl;

    cout << "Matrix 2:" << endl;
    matrix2.print();
    cout << endl;

    cout << "Matrix 1 + Matrix 2:" << endl;
    (matrix1 + matrix2).print();
    cout << endl;

    cout << "Matrix 1 - Matrix 2:" << endl;
    (matrix1 - matrix2).print();
    cout << endl;

    cout << "Matrix 1 * Matrix 2:" << endl;
    (matrix1 * matrix2).print();
    cout << endl;

    cout << "Row 1 of Matrix 1:" << endl;
    matrix1.printRow(1);
    cout << endl;

    cout << "Column 2 of Matrix 2:" << endl;
    matrix2.printColumn(2);
    cout << endl;

    cout << "Main diagonal of Matrix 1:" << endl;
    matrix1.printMainDiagonal();
    cout << endl;

    cout << "Secondary diagonal of Matrix 2:" << endl;
    matrix2.printSecondaryDiagonal();
    cout << endl;

    return 0;
}