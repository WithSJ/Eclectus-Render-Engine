import ctypes
from utils import wrap_func
vector_lib = ctypes.CDLL("./vector_lib.so")

class Vector(ctypes.Structure):
    """A  3D vector used in 3D graphics for X,Y,Z """
    _fields_ = [('x',ctypes.c_float),('y',ctypes.c_float),('z',ctypes.c_float)]
    
    def __init__(self, x=0.0, y=0.0, z=0.0):
        self.x = x
        self.y = y
        self.z = z
        
        # vector_lib = vector_lib


    def __str__(self):
        return f"({self.x}, {self.y}, {self.z})"

    def dot_product(self, other):
        dot_product_func = wrap_func(vector_lib,"dot_product",ctypes.c_float,[Vector,Vector])
        return dot_product_func(self,other)

    def magnitude(self):
        magnitude_func = wrap_func(vector_lib,"magnitude",ctypes.c_float,[Vector,Vector])
        return magnitude_func(self,self)

    def normalize(self):
        normalize_func = wrap_func(vector_lib,"normalize",Vector,[Vector])
        return normalize_func(self)

    def __add__(self, other):
        _add__func = wrap_func(vector_lib,"_add_",Vector,[Vector,Vector])
        return _add__func(self,other)

    def __sub__(self, other):
        _sub__func = wrap_func(vector_lib,"_sub_",Vector,[Vector,Vector])
        return _sub__func(self,other)
        

    def __mul__(self, other):
        assert not isinstance(other, Vector)
        _mul__func = wrap_func(vector_lib,"_mul_",Vector,[Vector,ctypes.c_float])
        return _mul__func(self,other)
        

    def __rmul__(self, other):
        return self.__mul__(other)

    def __truediv__(self, other):
        assert not isinstance(other, Vector)
        _div__func = wrap_func(vector_lib,"_div_",Vector,[Vector,ctypes.c_float])
        return _div__func(self,other)
        

