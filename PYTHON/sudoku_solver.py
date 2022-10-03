


class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        assert(self.solve(board))
    
    def solve(self, board: List[List[str]])->bool:
        for r in range(len(board[0])): # solve row by row
            for c in range(len(board)):
                if board[r][c]==".": # if place vacant
                    for i in range(1,10): # try putting 1-9 numbers 1 by 1
                        if self.isValid(str(i), r, c, board): # CONSTRAIN
                            board[r][c]= str(i) # Make CHOICE
                            if self.solve(board): # solve this new Sudoku
                                return True
                            else:
                                board[r][c]="." # undo CHOICE
                    return False            
        return True # GOAL - all vacant places filled
    
            
    def isValid(self, n:str, r:int, c:int, board: List[List[str]])->bool:
        for i in range(9):
            # check row, column, particular sub box
            if board[r][i]==n or board[i][c]==n or board[3*(r//3)+(i//3)][3*(c//3)+(i%3)]==n:
                return False
        return True