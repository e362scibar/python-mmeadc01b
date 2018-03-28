import os

class Register:
    """Register class for MMEADC01B"""
    datafile = "regdata.txt"
    data = None
    def __init__(self, name):
        self.name = name
        self.bar = self.data[self.name][0]
        self.ofs = self.data[self.name][1]
    def __str__(self):
        return "%s BAR%d 0x%d" % (self.name, self.bar, self.ofs)
    @classmethod
    def read_data(cls, path):
        cls.data = {}
        datapath = os.path.join(path, cls.datafile)
        with open(datapath) as f:
            for line in f:
                item = line.strip().split()
                if len(item) < 2 or item[0][0] == '#':
                    continue
                cls.data[item[0]] = (int(item[1]), int(item[2]))

