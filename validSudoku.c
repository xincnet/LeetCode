/*
   NO.36
   Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

   The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


   A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
 */

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) 
{
	int validRow[9][9] = {0};
	int validCol[9][9] = {0};
	int validBox[9][9] = {0};

	for (int i = 0; i < boardRowSize; i++)
	{
		for (int j = 0; j < boardColSize; j++)
		{
			if (board[i][j] != '.')
			{
				int num = board[i][j] - '0' - 1;
				int k = i / 3 + j / 3 * 3;
				if (validRow[i][num] || validCol[j][num] || validBox[k][num])
					return false;
				validRow[i][num] = validCol[j][num] = validBox[k][num] = 1;
			}
		}
	}
	return true;
}





