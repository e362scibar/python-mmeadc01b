import os

class Error(Exception):
    """Exception class for MMEADC01B errors"""
    datafile = "errordata.txt"
    data = None
    def __init__(self, code):
        self.code = code
    def __str__(self):
        try:
            val = "%s %d" % (self.data[self.code], self.code)
        except KeyError:
            val = "UNKNOWN %d" % self.code
        return val
    @classmethod
    def read_data(cls, path):
        cls.data = {}
        datapath = os.path.join(path, cls.datafile)
        with open(datapath) as file:
            for line in file:
                item = line.strip().split()
                if len(item) < 2 or item[0][0] == '#':
                    continue
                cls.data[int(item[1],0)] = item[0]
    @classmethod
    def code(cls, arg):
        try:
            key = list(cls.data.keys())[list(cls.data.values()).index(arg)]
        except (IndexError, ValueError):
            raise ValueError("%s is not in the error list." % arg)
        return key

