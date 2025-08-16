
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        this->m = board.size();
        this->n = board[0].size();
        this->arr = board;
        this->my_word = word;
        this->word_size = word.size();
        for (int i = 0; i < this->m; i++)
        {
            for (int j = 0; j < this->n; j++)
            {
                finding(i, j, 0);
            }
        }
        if (this->flag)return true;
        else return false;
    }

private:
    int m = 0;
    int n = 0;
    int word_size = 0;
    string my_word;
    vector<vector<char>> arr;
    int flag = 0;
    void finding(int i, int j, int x)
    {
        if (this->flag) return;
        if (x == this->word_size)
        {
            flag = 1;
            return;
        }
        if (i >= 0 &&
            j >= 0 &&
            i < m &&
            j < n &&
            x < word_size &&
            this->arr[i][j] == this->my_word[x])
        {
            this->arr[i][j] = 0;
            finding(i - 1, j, x + 1);
            finding(i + 1, j, x + 1);
            finding(i, j - 1, x + 1);
            finding(i, j + 1, x + 1);
            this->arr[i][j] = this->my_word[x];
        }
    }

public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        for (int i = 0; i <= size / 2; i++)
        {
            for (int j = 0; j < size - 2 * i-1; j++)
            {
                ////×óÐý90¡ã
                //int temp = matrix[i][i + j];
                //matrix[i][i + j] = matrix[j][size - 1 - i];
                //matrix[j][size - 1 - i] = matrix[size - 1 - i][size - 1 - j];
                //matrix[size - 1 - i][size - 1 - j] = matrix[size - 1 - j][i];
                //matrix[size - 1 - j][i] = temp;
                int temp = matrix[i][i + j];                             // top
                matrix[i][i + j] = matrix[size - 1 - j-i][i];                 // left -> top
                matrix[size - 1 - j-i][i] = matrix[size - 1 - i][size - 1 - j-i];     // bottom -> left
                matrix[size - 1 - i][size - 1 - j-i] = matrix[j+i][size - 1 - i];     // right -> bottom
                matrix[j+i][size - 1 - i] = temp;                             // top -> right
            }
        }
    }
};
// {1, 2, 3, 4},
// {5, 6, 7, 8},
// {9, 10,11,12},
// {13,14,15,16}



//1,2,3
//4,5,6
//7,8,9

int main() 
{
    Solution s1;
    vector<vector<int>> matrix = { {1,2,3},{4,5,6},{7,8,9 } };
    vector<vector<int>> matrix2 = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
    s1.rotate(matrix2);
    return 0;
}
