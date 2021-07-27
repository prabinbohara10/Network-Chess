#include "piece.h"

void piece::copy_to_2dvector(vector<vector<int>> &current_possible,int row,int col,int can_kill)
{
    vector<int> temp;
    temp.push_back(row);
    temp.push_back(col);
    temp.push_back(can_kill);
    current_possible.push_back(temp);
}