import os
import json
from operator import itemgetter

class AdcRegister:
    """ADC Register class for ADC16DX370"""
    datafile = "regadc.json"
    data = None
    def __init__(self, name, value=None):
        self.name = name
        self.reg = self.data[name]
        self.addr = int(self.reg["address"], 0)
        self.bit = self.bitdata[name]
        if value is not None:
            self.value = int(value)
        else:
            self.value = int(self.reg["default"], 0)
    def __str__(self):
        ret = []
        for b in self.bit:
            ofs = self.reg["bit"][b]["offset"]
            n = self.reg["bit"][b]["length"]
            v = self[b]
            if n > 1:
                pos = "{}..{}".format(ofs+n-1, ofs)
            else:
                pos = "{}".format(ofs)
            tmp = "{}[{}]:{:0{nbit}b}({})".format(b, pos, v, v, nbit=n)
            ret.append(tmp)
        return ", ".join(ret)
    def __repr__(self):
        return "<AdcRegister {} [{}]>".format(self.name, str(self))
    def __getitem__(self, key):
        ofs = self.reg["bit"][key]["offset"]
        n = self.reg["bit"][key]["length"]
        mask = ((1<<n)-1) << ofs
        return (self.value & mask) >> ofs
    def __setitem__(self, key, value):
        ofs = self.reg["bit"][key]["offset"]
        n = self.reg["bit"][key]["length"]
        mask = ((1<<n)-1) << ofs
        v = value & ((1<<n)-1)
        self.value &= ~(((1<<n)-1) << ofs)
        self.value |= v << ofs
    def __eq__(self, other):
        if isinstance(other, int):
            return self.value == other
        elif isinstance(other, AdcRegister):
            return self.name == other.name and self.value == other.value
        return False
    def __neq__(self, other):
        return not self == other
    def __and__(self, other):
        ret = AdcRegister(self.name, self.value)
        if isinstance(other, int):
            ret.value &= other
        elif isinstance(other, AdcRegister) and self.name == other.name:
            ret.value &= other.value
        else:
            raise TypeError
        return ret
    def __or__(self, other):
        ret = AdcRegister(self.name, self.value)
        if isinstance(other, int):
            ret.value |= other
        elif isinstance(other, AdcRegister) and self.name == other.name:
            ret.value |= other.value
        else:
            raise TypeError
        return ret
    def __xor__(self, other):
        ret = AdcRegister(self.name, self.value)
        if isinstance(other, int):
            ret.value ^= other
        elif isinstance(other, AdcRegister) and self.name == other.name:
            ret.value ^= other.value
        else:
            raise TypeError
        return ret
    def __iand__(self, other):
        if isinstance(other, int):
            self.value &= other
        elif isinstance(other, AdcRegister) and self.name == other.name:
            self.value &= other.value
        else:
            raise TypeError
        return self
    def __ior__(self, other):
        if isinstance(other, int):
            self.value |= other
        elif isinstance(other, AdcRegister) and self.name == other.name:
            self.value |= other.value
        else:
            raise TypeError
        return self
    def __ixor__(self, other):
        if isinstance(other, int):
            self.value ^= other
        elif isinstance(other, AdcRegister) and self.name == other.name:
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
        cls.bitdata = {}
        for key, val in cls.data.items():
            tmp = [(k,v["offset"]) for k,v in val["bit"].items()
                   if k is not None and (len(k) < 3 or k[:3] != "RSV")]
            tmp.sort(key=itemgetter(1))
            tmp.reverse()
            cls.bitdata[key] = [v[0] for v in tmp]

