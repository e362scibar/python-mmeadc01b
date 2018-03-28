from . import devapi
import errno

class Device:
    def __init__(self):
        self.fd = None
        self.devfile = None
        self.dmabuf = None
    def open(devfile):
        fd = devapi.open(devfile)
    def close():
        if self.fd is None:
            raise ValueError("fd is not set.")
        devapi.close(self.fd)

