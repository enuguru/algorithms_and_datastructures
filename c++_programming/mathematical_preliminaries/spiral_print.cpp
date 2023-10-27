#include <iostream>
using namespace std;

#define R 4
#define C 5

void spiralPrint(int arr[R][C]) {
    int i, startRow = 0, startCol = 0, endRow = R, endCol = C;

    while (startRow < endRow && startCol < endCol) {
        // Print the first row
        for (i = startCol; i < endCol; i++) {
            cout << arr[startRow][i] << " ";
        }
        startRow++;

        // Print the last column
        for (i = startRow; i < endRow; i++) {
            cout << arr[i][endCol - 1] << " ";
        }
        endCol--;

        // Print the last row if it's not the same as the first
        if (startRow < endRow) {
            for (i = endCol - 1; i >= startCol; i--) {
                cout << arr[endRow - 1][i] << " ";
            }
            endRow--;
        }

        // Print the first column if it's not the same as the last
        if (startCol < endCol) {
            for (i = endRow - 1; i >= startRow; i--) {
                cout << arr[i][startCol] << " ";
            }
            startCol++;
        }
    }
}

int main() {
    int arr[R][C] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20}
    };

    spiralPrint(arr);
    return 0;
}
