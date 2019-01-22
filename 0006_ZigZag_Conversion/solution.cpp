class Solution {
public:
    string convert(string s, int numRows) {
        char** matrix = new char*[numRows];
        
        for (int i = 0; i < numRows; i++)
        {
            matrix[i] = new char[s.size() + 1];
            fill_n(matrix[i], s.size() + 1, '\0');
        }
        
        int* idx = new int[numRows];
        fill_n(idx, numRows, 0);
        int row = 0;
        int d = 1;
        if (numRows == 1)
            d = 0;
        for (int i = 0; i < s.size(); i++)
        {
            matrix[row][idx[row]++] = s[i];
            row += d;
            if (row == 0 || row == numRows - 1)
                d = -d;
        }
        string ans = "";
        for (int i = 0; i < numRows; i++)
            ans += matrix[i];
        for (int i = 0; i < numRows; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
        delete[] idx;
        return ans;
    }
};
