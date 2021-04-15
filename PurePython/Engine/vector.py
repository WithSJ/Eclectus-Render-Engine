import math


class Vector:
    """A three element vector used in 3D graphics for multiple purposes"""

    def __init__(self, x=0.0, y=0.0, z=0.0):
        self.x = x
        self.y = y
        self.z = z

    def __str__(self):
        return "({}, {}, {})".format(self.x, self.y, self.z)

    def dot_product(self, other):
        return self.x * other.x + self.y * other.y + self.z * other.z

    def magnitude(self):
        return math.sqrt(self.dot_product(self))

    def normalize(self):
        return self / self.magnitude()

    def __add__(self, other):
        return Vector(self.x + other.x, self.y + other.y, self.z + other.z)

    def __sub__(self, other):
        return Vector(self.x - other.x, self.y - other.y, self.z - other.z)

    def __mul__(self, other):
        assert not isinstance(other, Vector)
        return Vector(self.x * other, self.y * other, self.z * other)

    def __rmul__(self, other):
        return self.__mul__(other)

    def __truediv__(self, other):
        assert not isinstance(other, Vector)
        return Vector(self.x / other, self.y / other, self.z / other)

if __name__ == "__main__":
    import time
    start = time.time()
    
    v1 = Vector(1,-2,-2)
    v2 = Vector(3,6,9)
    

    print("Vector v1 :",v1)
    print("Vector v2 :",v2)
    
    print()
    
    print("Dot Product(v1,v1):",v1.dot_product(v1))
    print("Magnitude of v1 :", v1.magnitude())
    print("Normalize of v1 :", v1.normalize())
    
    print()
    
    print("Add v1,v2 :", v1 + v2)
    print("Sub v1,v2 :", v1 - v2)
    print("Mul v1,2 :", v1 * 2)
    print("Div v2,3 :", v2 / 3)


    print("\n## DotProduct of v1 and v2",v1,v2)
    print(v1.dot_product(v2))
    
    end = time.time()
    print("\n#Time taken in Seconds:",end-start)