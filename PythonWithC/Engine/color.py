import vector

class Color(vector.Vector):
    
    
    def __str__(self):
        return f"Color({self.x}, {self.y}, {self.z})"