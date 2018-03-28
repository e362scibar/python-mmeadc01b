from . import devapi

class Device:
    def __init__(self):
        self.fd = None
        self.devfile = None
        self.dmabuf = None
    def open(devfile):
        fd = devapi.open(devfile)
    def close():
        if self.fd is None:
            raise RuntimeError("Device not opened.")
        devapi.close(self.fd)
    def read():
        if self.fd is None:
            raise RuntimeError("Device not opened.")
        status = devapi.dev_mmeadc01b_read(self.fd, bar, ofs, num);

