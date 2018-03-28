from . import devapi
from .error import Error
import ctypes

class Device:
    """ MMEADC01B Device class """
    clk_src = {"EXT":0, "RTM0":1, "RTM1":2, "INT":3}
    def __init__(self):
        self.fd = None
        self.devfile = None
        self.dmabuf = None
    def open(self, devfile):
        fd = devapi.open(devfile)
        self.mmap_dma_buf()
    def close(self):
        if self.fd is None:
            raise RuntimeError("Device not opened.")
        if self.dmabuf is not None:
            self.munmap_dma_buf()
        devapi.close(self.fd)
    def read(self, reg, num=1):
        if self.fd is None:
            raise RuntimeError("Device not opened.")
        status, data = devapi.read(self.fd, reg.bar, reg.ofs, num)
        if status:
            raise Error(status)
        if num == 1:
            return data[0]
        return data
    def write(self, reg, data):
        if self.fd is None:
            raise RuntimeError("Device not opened.")
        if !isinstance(data, tuple):
            if isinstance(data, list):
                data = tuple(data)
            else:
                data = (data,)
        status = devapi.write(self.fd, reg.bar, reg.ofs, data)
        if status:
            raise Error(status)
    def adc_read(self, id_adc, addr, num=1):
        if self.fd is None:
            raise RuntimeError("Device not opened.")
        status, data = devapi.adc_read(self.fd, id_adc, addr, num)
        if status:
            raise Error(status)
        if num == 1:
            return data[0]
        return data
    def adc_write(self, id_adc, addr, data):
        if self.fd is None:
            raise RuntimeError("Device not opened.")
        if !isinstance(data, tuple):
            if isinstance(data, list):
                data = tuple(data)
            else:
                data = (data,)
        status = devapi.adc_write(self.fd, id_adc, addr, data)
        if status:
            raise Error(status)
    def dac_read(self, addr, num=1):
        if self.fd is None:
            raise RuntimeError("Device not opened.")
        status, data = devapi.dac_read(self.fd, addr, num)
        if status:
            raise Error(status)
        if num == 1:
            return data[0]
        return data
    def dac_write(self, addr, data):
        if self.fd is None:
            raise RuntimeError("Device not opened.")
        if !isinstance(data, tuple):
            if isinstance(data, list):
                data = tuple(data)
            else:
                data = (data,)
        status = devapi.dac_write(self.fd, addr, data)
        if status:
            raise Error(status)
    def lmk_write(self, addr, data):
        if self.fd is None:
            raise RuntimeError("Device not opened.")
        if !isinstance(data, tuple):
            if isinstance(data, list):
                data = tuple(data)
            else:
                data = (data,)
        status = devapi.lmk_write(self.fd, addr, data)
        if status:
            raise Error(status)
    def user_i2c_read(self, slv, ofs, num=1):
        if self.fd is None:
            raise RuntimeError("Device not opened.")
        status, data = devapi.user_i2c_read(self.fd, slv, ofs, num)
        if status:
            raise Error(status)
        if num == 1:
            return data[0]
        return data
    def user_i2c_write(self, slv, ofs, data):
        if self.fd is None:
            raise RuntimeError("Device not opened.")
        if !isinstance(data, tuple):
            if isinstance(data, list):
                data = tuple(data)
            else:
                data = (data,)
        status = devapi.dac_write(self.fd, addr, data)
        if status:
            raise Error(status)
    def mmap_dma_buf(self):
        if self.fd is None:
            raise RuntimeError("Device not opened.")
        status, buf = devapi.mmap_dma_buf(self.fd)
        if status:
            raise Error(status)
        self.dmabuf = buf
    def munmap_dma_buf(self):
        if self.fd is None:
            raise RuntimeError("Device not opened.")
        if self.dmabuf is None:
            raise RuntimeError("DMA buffer not mmapped.")
        status = devapi.munmap_dma_buf(self.fd, self.dmabuf)
        if status:
            raise Error(status)
        self.dmabuf = None
    def get_meta(self):
        if self.fd is None:
            raise RuntimeError("Device not opened.")
        status, adc, iq = devapi.get_meta(self.fd)
        if status:
            raise Error(status)
        return adc, iq
    def clear_dma_buf_status(self):
        if self.fd is None:
            raise RuntimeError("Device not opened.")
        status = devapi.clear_dma_buf_status(self.fd)
        if status:
            raise Error(status)
    def register_interrupt_callback(self, callback):
        if self.fd is None:
            raise RuntimeError("Device not opened.")
        functype = ctypes.CFUNCTYPE(None, ctypes.c_int)
        status = devapi.register_interrupt_callback(self.fd, functype(callback))
        if status:
            raise Error(status)
    def unregister_interrupt_callback(self):
        if self.fd is None:
            raise RuntimeError("Device not opened.")
        status = devapi.unregister_interrupt_callback(self.fd)
        if status:
            raise Error(status)
    def set_clk_src(self, src):
        if self.fd is None:
            raise RuntimeError("Device not opened.")
        if !isinstance(src, int):
            src = self.clk_src[src]
        status = devapi.set_clk_src(self.fd, src)
        if status:
            raise Error(status)
    def get_clk_src(self):
        if self.fd is None:
            raise RuntimeError("Device not opened.")
        status, src = devapi.get_clk_src(self.fd)
        if status:
            raise Error(status)
        return list(self.clk_src.keys())[list(delf.clk_src.values()).index(src)]


