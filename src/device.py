from . import devapi
from .error import Error
from .register import Register
import ctypes
import time
import numpy as np

NCH = 10
NFIR = 32

class Device:
    """ MMEADC01B Device class """
    clk_src = {"EXT":0, "RTM0":1, "RTM1":2, "INT":3}
    def __init__(self):
        self.fd = None
        self.devfile = None
        self.dmabuf = None
        self.dmadone = False
    def __del__(self):
        try:
            self.close()
        except:
            pass

    # DevAPI Methods
    def open(self, devfile):
        self.devfile = devfile
        self.fd = devapi.open(devfile)
        #self.clear_dma_buf_status()
        #self.mmap_dma_buf()
    def close(self):
        if self.fd is None:
            raise RuntimeError("Device not opened.")
        if self.dmabuf is not None:
            self.munmap_dma_buf()
        devapi.close(self.fd)
        self.fd = None
        self.devfile = None
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
        if not isinstance(data, tuple):
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
        if not isinstance(data, tuple):
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
        if not isinstance(data, tuple):
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
        if not isinstance(data, tuple):
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
        if not isinstance(data, tuple):
            if isinstance(data, list):
                data = tuple(data)
            else:
                data = (data,)
        status = devapi.user_i2c_write(self.fd, slv, ofs, data)
        if status:
            raise Error(status)
    def mmap_dma_buf(self):
        if self.fd is None:
            raise RuntimeError("Device not opened.")
        status, buf = devapi.mmap_dma_buf(self.fd)
        if all(buf):
            self.dmabuf = buf
        if status:
            raise Error(status)
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
    def register_interrupt_callback(self):
        if self.fd is None:
            raise RuntimeError("Device not opened.")
        status = devapi.register_interrupt_callback(self.fd)
        if status:
            raise Error(status)
    def unregister_interrupt_callback(self):
        if self.fd is None:
            raise RuntimeError("Device not opened.")
        status = devapi.unregister_interrupt_callback(self.fd)
        if status:
            raise Error(status)
    def get_interrupt_status(self):
        return devapi.get_interrupt_status()
    def reset_interrupt_status(self):
        devapi.reset_interrupt_status()
    def set_clk_src(self, src):
        if self.fd is None:
            raise RuntimeError("Device not opened.")
        if not isinstance(src, int):
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
        return list(self.clk_src.keys())[list(self.clk_src.values()).index(src)]

    # Waveform methods
    def wfm_init(self):
        self.write(Register("INTR_CLR"), 0)
        self.write(Register("INTR_CLR"), 0x3)
        self.write(Register("INTR_CLR"), 0)
        self.write(Register("INTR_MASK"), 0)
        self.reset_interrupt_status()
        self.register_interrupt_callback()
        self.mmap_dma_buf()
    def wfm_start(self):
        self.reset_interrupt_status()
        self.write(Register("WAVE_START"), 0)
        self.write(Register("WAVE_START"), 1)
        self.write(Register("WAVE_START"), 0)
    def wfm_stop_soft(self):
        self.write(Register("WAVE_SOFTTRG"), 0)
        self.write(Register("WAVE_SOFTTRG"), 1)
        self.write(Register("WAVE_SOFTTRG"), 0)
    def wfm_terminate(self):
        self.munmap_dma_buf()
        self.unregister_interrupt_callback()
    def wfm_get(self):
        if self.dmabuf is None:
            raise RuntimeError("DMA buffer not mmapped.")
        #if not self.get_interrupt_status()[0]:
        #    time.sleep(0.1)
        #    if not self.get_interrupt_status()[0]:
        #        raise TimeoutError("Waveform timeout")
        status, adc, iq = devapi.get_waveform(self.dmabuf)
        return adc, iq
    def wfm_enable(self):
        self.clear_dma_buf_status()
    def get_wfm_sample_step(self):
        return self.read(Register("WAVE_SMPL_STEP"))
    def set_wfm_sample_step(self, step):
        if step not in range(65536):
            raise ValueError("Too large step.")
        self.write(Register("WAVE_SMPL_STEP"), step)

    # Utility methods
    def jesd204b_reset(self):
        self.write(Register("JESD204B_RST"), 1)
        time.sleep(0.01)
        self.write(Register("JESD204B_RST"), 0)

    # FIR filter methods
    def get_fir_sw_all(self):
        ret = self.read(Register("FIR_ON"))
        return [bool((ret>>i)&1) for i in range(NCH)]
    def get_fir_sw(self, ch):
        return self.get_fir_sw_all()[ch]
    def set_fir_sw_all(self, on=True):
        val = 0
        if on:
            for i in range(NCH):
                val |= (1<<i)
        self.write(Register("FIR_ON"), val)
    def set_fir_sw(self, ch, on=True):
        ret = self.get_fir_sw_all()
        ret[ch] = 1 if on else 0
        val = 0
        for i in len(ret):
            val |= (1<<i) if ret[i] else 0
        self.write(Register("FIR_ON"), val)
    def get_fir_coeff(self, ch):
        if ch not in range(NCH):
            raise ValueError("Channel")
        self.write(Register("FIR_COEFF_CHSEL"), ch)
        fir = []
        for i in range(NFIR):
            ret = self.read(Register("FIR_COEFF_{:02d}".format(i)))
            fir.append(np.int16(ret) / 2**14)
        return fir
    def set_fir_coeff(self, ch, coeff=[1]):
        if ch not in range(NCH):
            raise ValueError("Channel")
        if len(coeff) < NFIR:
            coeff.extend([0]*(NFIR-len(coeff)))
        for i in range(NFIR):
            ival = coeff[i]*2**14
            if ival > 0x7fff:
                val = 0x7fff
            elif ival < -0x10000:
                val = -0x10000
            else:
                val = int(ival)
            self.write(Register("FIR_COEFF_{:02d}".format(i)), val)
        self.write(Register("FIR_COEFF_CHSEL"), ch)
        self.write(Register("FIR_COEFF_UPD"), 1)
        time.sleep(0.001)
        self.write(Register("FIR_COEFF_UPD"), 0)

    # IIR filter methods
    def get_iir_coeff(self):
        return self.read(Register("IQ_IIR_COEFF")) / 2**24
    def set_iir_coeff(self, coeff=1.0e-3):
        self.write(Register("IQ_IIR_COEFF"), int(coeff*2**24))
    def get_iir_sw_all(self):
        ret = self.read(Register("IQ_IIR_ON"))
        return [bool((ret>>i)&1) for i in range(NCH)]
    def get_iir_sw(self, ch):
        return self.get_iir_sw_all()[ch]
    def set_iir_sw_all(self, on=True):
        val = 0
        if on:
            for i in range(NCH):
                val |= (1<<i)
        self.write(Register("IQ_IIR_ON"), val)
    def set_iir_sw(self, ch, on=True):
        ret = self.get_iir_sw_all()
        ret[ch] = 1 if on else 0
        val = 0
        for i in len(ret):
            val |= (1<<i) if ret[i] else 0
        self.write(Register("IQ_IIR_ON"), val)

    # Realtime monitor
    def get_iq(self):
        ret = np.array(self.read(Register("MON_IQ01"), NCH), dtype=np.int)
        I = (ret&0xffff).astype('int16') / 32768.
        Q = ((ret>>16)&0xffff).astype('int16') / 32768.
        return I + 1.j * Q

    # Rotator functions
    def get_rotator(self, ch='IQ01'):
        reg_a = self.read(Register(ch+"_ROT_A"))
        reg_b = self.read(Register(ch+"_ROT_B"))
        reg_c = self.read(Register(ch+"_ROT_C"))
        reg = np.array([reg_a, reg_b, reg_c], dtype=np.int16).astype(np.float)
        return (reg[0] + 0.5j * (reg[2] - reg[1])) / 0x1000
    def set_rotator(self, ch='IQ01', z=1.0):
        reg_a = np.clip(np.around(np.real(z) * 0x1000), -0x8000, 0x7fff)
        reg_b = np.clip(np.around(-np.imag(z) * 0x1000), -0x8000, 0x7fff)
        reg_c = np.clip(np.around(np.imag(z) * 0x1000), -0x8000, 0x7fff)
        self.write(Register(ch+"_ROT_A"), int(reg_a)&0xffff)
        self.write(Register(ch+"_ROT_B"), int(reg_b)&0xffff)
        self.write(Register(ch+"_ROT_C"), int(reg_c)&0xffff)

