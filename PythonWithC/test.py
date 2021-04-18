#Testing Of Modulles
import ctypes
from Engine.vector import Vector
if __name__ == "__main__":
    #Test cases
    import time
    start = time.time()
    
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

    end = time.time()
    print("\n#Time taken in Seconds :",end-start)

    
