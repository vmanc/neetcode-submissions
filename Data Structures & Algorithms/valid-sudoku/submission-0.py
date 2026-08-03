class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = [set() for _ in range(9)]
        columns = [set() for _ in range(9)]
        boxes = [set() for _ in range(9)]
        for i in range(len(board)):
            for j in range(len(board)):
                board_value = board[i][j]
                if board_value == '.':
                    continue
                box_index = (i // 3) * 3 + j // 3
                if board_value in rows[i] or board_value in columns[j] or board_value in boxes[box_index]:
                    return False
                
                rows[i].add(board_value)
                columns[j].add(board_value)
                boxes[box_index].add(board_value)
        
        return True
                