import os
import json

class Bitfield:
    """Bit Field class for MMEADC01B"""
    datafile = "bitinfo.json"
    data = None
    rdata = None
    def __init__(self, name, value=0):
        self.name = name
        self.tag = self.data[name]
        self.ofs = self.rdata[name]
        self.value = int(value)
    def __str__(self):
        tmp = ["{}({}):{}".format(tag, i, self[i])
                for i,tag in enumerate(self.tag) if tag is not None]
        return ", ".join(tmp)
    def __repr__(self):
        return "<Bitfield {} [{}]>".format(self.name, str(self))
    def __getitem__(self, key):
        if type(key) is int and self.tag[key] is not None:
            i = key
        else:
            i = self.ofs[key]
        return (self.value >> i) & 1
    def __setitem__(self, key, value):
        if type(key) is int and self.tag[key] is not None:
            i = key
        else:
            i = self.ofs[key]
        if value:
            self.value |= 1 << i
        else:
            self.value &= ~(1 << i)
    def __eq__(self, other):
        if isinstance(other, int):
            return self.value == other
        elif isinstance(other, Bitfield):
            return self.name == other.name and self.value == other.value
        return False
    def __neq__(self, other):
        return not self == other
    def __and__(self, other):
        ret = Bitfield(self.name, self.value)
        if isinstance(other, int):
            ret.value &= other
        elif isinstance(other, Bitfield) and self.name == other.name:
            ret.value &= other.value
        else:
            raise TypeError
        return ret
    def __or__(self, other):
        ret = Bitfield(self.name, self.value)
        if isinstance(other, int):
            ret.value |= other
        elif isinstance(other, Bitfield) and self.name == other.name:
            ret.value |= other.value
        else:
            raise TypeError
        return ret
    def __xor__(self, other):
        ret = Bitfield(self.name, self.value)
        if isinstance(other, int):
            ret.value ^= other
        elif isinstance(other, Bitfield) and self.name == other.name:
            ret.value ^= other.value
        else:
            raise TypeError
        return ret
    def __iand__(self, other):
        if isinstance(other, int):
            self.value &= other
        elif isinstance(other, Bitfield) and self.name == other.name:
            self.value &= other.value
        else:
            raise TypeError
        return self
    def __ior__(self, other):
        if isinstance(other, int):
            self.value |= other
        elif isinstance(other, Bitfield) and self.name == other.name:
            self.value |= other.value
        else:
            raise TypeError
        return self
    def __ixor__(self, other):
        if isinstance(other, int):
            self.value ^= other
        elif isinstance(other, Bitfield) and self.name == other.name:
            self.value ^= other.value
        else:
            raise TypeError
        return self
    def __invert__(self):
        return Bitfield(self.name, ~self.value)
    def __int__(self):
        return self.value
    @classmethod
    def read_data(cls, path):
        datapath = os.path.join(path, cls.datafile)
        with open(datapath) as f:
            cls.data = json.load(f)
        cls.rdata = {key:{tag:i for i,tag in enumerate(cls.data[key])
                        if tag is not None} for key in cls.data.keys()}

