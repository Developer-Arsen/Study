class MemoryGame:
    def __init__(self, boardSize: int):
        self.matrix = []

        if boardSize % 2 != 0:
            raise ValueError("Give even number")
        
        for i in range(boardSize):
            row = []
            for j in range(boardSize):
                row.append("*")
            self.matrix.append(row) 
            

    def startGame(self):
        print("hello")

    def drawBoard(self):
        for i in range(len(self.matrix)):
            
            for j in range(len(self.matrix)):
                print(self.matrix[i][j], end=" ")
            print()

    def updateBoard(self):
        pass



a = MemoryGame(4)
a.drawBoard()
