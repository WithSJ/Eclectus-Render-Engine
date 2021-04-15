def wrap_func(lib,funcname,restype,argtypes):
    """ Wrapping ctypes functions"""
    func = lib.__getattr__(funcname)
    func.restype = restype
    func.argtypes = argtypes
    return func