
class Cell: 
    def __init__(self, value: int):
        self.__value = value
        self.founded = False

    @property
    def value(self):
        return self.__value
    
    @value.setter
    def value(self, value: any):
        self.__value = value
    
    @property
    def founded(self):
        return self.founded
    
    @founded.setter
    def founed(self, founded: bool):
        if not isinstance(founded, bool):
          raise TypeError("Invalid type")
        return self.__founded  == founded
        
    def __eq__(self, other : "Cell"):
        if not isinstance(other, Cell):
            raise TypeError("Invalid type")
        return self.value == other.value
    
    def __str__(self):
        return self.value
