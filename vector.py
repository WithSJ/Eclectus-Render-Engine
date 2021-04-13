import ctypes
from utils import wrap_func

class Vector(ctypes.Structure):
    """A  3D vector used in 3D graphics for X,Y,Z """
    _fields_ = [('x',ctypes.c_float),('y',ctypes.c_float),('z',ctypes.c_float)]
    
    def __init__(self, x=0.0, y=0.0, z=0.0):
        self.x = x
        self.y = y
        self.z = z
        
        self.lib = ctypes.CDLL("./vector_lib.so")


    def __str__(self):
        return f"({self.x}, {self.y}, {self.z})"

    def dot_product(self, other):
        dot_product_func = wrap_func(self.lib,"dot_product",ctypes.c_float,[Vector,Vector])
        return dot_product_func(self,other)

    def magnitude(self):
        magnitude_func = wrap_func(self.lib,"magnitude",ctypes.c_float,[Vector,Vector])
        return magnitude_func(self,self)

    def normalize(self):
        normalize_func = wrap_func(self.lib,"normalize",Vector,[Vector])
        return normalize_func(self)

    def __add__(self, other):
        _add__func = wrap_func(self.lib,"_add_",Vector,[Vector,Vector])
        return _add__func(self,other)

    def __sub__(self, other):
        _sub__func = wrap_func(self.lib,"_sub_",Vector,[Vector,Vector])
        return _sub__func(self,other)
        

    def __mul__(self, other):
        assert not isinstance(other, Vector)
        _mul__func = wrap_func(self.lib,"_mul_",Vector,[Vector,ctypes.c_float])
        return _mul__func(self,other)
        

    def __rmul__(self, other):
        return self.__mul__(other)

    def __truediv__(self, other):
        assert not isinstance(other, Vector)
        _div__func = wrap_func(self.lib,"_div_",Vector,[Vector,ctypes.c_float])
        return _div__func(self,other)
        

if __name__ == "__main__":
    #Test cases

    v1 = Vector(ctypes.c_float(1),ctypes.c_float(-2),ctypes.c_float(-2))
    v2 = Vector(ctypes.c_float(3),ctypes.c_float(6),ctypes.c_float(9))
    

    print("Vector v1 :",v1)
    print("Vector v2 :",v2)
    
    print()
    
    print("Dot Product(v1,v1):",v1.dot_product(v1))
    print("Magnitude of v1 :", v1.magnitude())
    print("Normalize of v1 :", v1.normalize())
    
    print()
    
    print("Add v1,v2 :", v1 + v2)
    print("Sub v1,v2 :", v1 - v2)
    print("Mul v1,2 :", v1 * ctypes.c_float(2))
    print("Div v2,3 :", v2 / ctypes.c_float(3))


    print("\n## DotProduct of v1 and v2",v1,v2)
    print(v1.dot_product(v2))

    
