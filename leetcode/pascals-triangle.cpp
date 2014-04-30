/**
 * Given numRows, generate the first numRows of Pascal's triangle.
 *
 * For example, given numRows = 5,
 * Return
 *
 * [
 * [1],
 * [1,1],
 * [1,2,1],
 * [1,3,3,1],
 * [1,4,6,4,1]
 * ]
 */

class Solution {
public:
    vector<vector<int> > generate (int numRows) {
        vector<vector<int> > triangle;

        if (numRows > 0) {
            triangle.push_back (vector<int> (1, 1) );

            if (numRows > 1) {
                triangle.push_back (vector<int> (2, 1) );

                // for each row
                for (int j = 3; j <= numRows; ++j) {
                    vector<int> aRow;

                    // for each number in row j
                    for (int i = 0; i < j; ++i) {
                        if (i == 0 || i == j - 1) {
                            aRow.push_back (1);
                        } else {
                            aRow.push_back (triangle[j - 2][i - 1] + triangle[j - 2][i]);
                        }
                    }
                    triangle.push_back (aRow);
                }
            }
        }

        return triangle;
    }
};
