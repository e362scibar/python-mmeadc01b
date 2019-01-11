from . import devapi
from .error import Error
from .register import Register
from .bitfield import Bitfield
import ctypes
import time
import numpy as np
import pandas as pd

NCH = 10
NFIR = 17

META = ["ADC_WFM", "IQ_WFM", "SP_WFM", "CT_L", "CT_H",
        "BPM1TBT", "BPM1FA", "BPM1SA", "BPM1SP",
        "BPM2TBT", "BPM2FA", "BPM2SA", "BPM2SP"]

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
    def read_float(self, reg, num=1):
        if self.fd is None:
            raise RuntimeError("Device not opened.")
        status, data = devapi.read_float(self.fd, reg.bar, reg.ofs, num)
        if status:
            raise Error(status)
        if num == 1:
            return data[0]
        return data
    def write_float(self, reg, data):
        if self.fd is None:
            raise RuntimeError("Device not opened.")
        if not isinstance(data, tuple):
            if isinstance(data, list):
                data = tuple(data)
            else:
                data = (data,)
        status = devapi.write_float(self.fd, reg.bar, reg.ofs, data)
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
    def start_dma_xfer(self, req_acq, idx_area):
        if self.fd is None:
            raise RuntimeError("Device not opened.")
        status = devapi.start_dma_xfer(self.fd, req_acq, idx_area)
        if status:
            raise Error(status)
    def get_ring_status(self):
        if self.fd is None:
            raise RuntimeError("Device not opened.")
        status, cmplt = devapi.get_ring_status(self.fd)
        if status:
            raise Error(status)
        return Bitfield("RING_STAT", cmplt)
    def get_meta(self):
        if self.fd is None:
            raise RuntimeError("Device not opened.")
        status, meta = devapi.get_meta(self.fd)
        if status:
            raise Error(status)
        return {key: meta[i] for i, key in enumerate(META)}
    def clear_dma_buf_status(self):
        if self.fd is None:
            raise RuntimeError("Device not opened.")
        status = devapi.clear_dma_buf_status(self.fd)
        if status:
            raise Error(status)
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

    # Interrupt methods
    def get_interrupt_status(self):
        return Bitfield("INTR", self.read(Register("INTR_STATUS")))
    def clear_interrupt_status(self, arg):
        if isinstance(arg, Bitfield) and arg.name != "INTR":
            return TypeError("Invalid Bitfield ({}).".format(arg.name))
        self.write(Register("INTR_CLR"), int(arg))
    def get_interrupt_mask(self):
        return Bitfield("INTR", self.read(Register("INTR_MASK")))
    def set_interrupt_mask(self, arg):
        if isinstance(arg, Bitfield) and arg.name != "INTR":
            return TypeError("Invalid Bitfield ({}).".format(arg.name))
        self.write(Register("INTR_MASK"), int(arg))

    # Waveform methods
    def wfm_init(self):
        self.write(Register("INTR_CLR"), 0)
        self.write(Register("INTR_CLR"), 0x3)
        self.write(Register("INTR_CLR"), 0)
        self.write(Register("INTR_MASK"), 0)
        self.mmap_dma_buf()
    def wfm_start(self):
        self.write(Register("WAVE_START"), 0)
        self.write(Register("WAVE_START"), 1)
        self.write(Register("WAVE_START"), 0)
    def wfm_stop_soft(self):
        self.write(Register("WAVE_SOFTTRG"), 0)
        self.write(Register("WAVE_SOFTTRG"), 1)
        self.write(Register("WAVE_SOFTTRG"), 0)
    def wfm_terminate(self):
        self.munmap_dma_buf()
    def wfm_get(self):
        if self.dmabuf is None:
            raise RuntimeError("DMA buffer not mmapped.")
        status, adc, iq = devapi.get_waveform(self.dmabuf)
        status, sp = devapi.get_waveform_sp(self.dmabuf)
        return adc, iq, sp
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
            coeff.reverse().extend([0]*(NFIR-len(coeff))).reverse()
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
    def get_max(self):
        ret = np.array(self.read(Register("PEAKHOLD_ADC01"), NCH), dtype=np.int)
        return ret

    # Rotator functions
    def get_rotator(self, ch):
        """ CH 0: DAC, CH 1-10: IQ """
        status, gain, phase = devapi.get_rot_coeff(self.fd, ch)
        if status:
            raise Error(status)
        return gain * np.exp(1.j * phase)
    def set_rotator(self, ch, z=1.0):
        """ CH 0: DAC, CH 1-10: IQ """
        status = devapi.set_rot_coeff(self.fd, ch, np.abs(z), np.angle(z))
        if status:
            raise Error(status)

    # BPM waveforms
    def get_tone_wfm(self):
        if self.dmabuf is None:
            raise RuntimeError("DMA buffer not mmaped.")
        status, tone = devapi.get_waveform_tone(self.dmabuf)
        return tone
    def get_sp_wfm(self):
        if self.dmabuf is None:
            raise RuntimeError("DMA buffer not mmaped.")
        status, sp = devapi.get_waveform_sp(self.dmabuf)
        return sp

    # BPM data
    def get_tbt_data(self):
        if self.dmabuf is None:
            raise RuntimeError("DMA buffer not mmaped.")
        status, data = devapi.get_tbt_data(self.dmabuf)
        ret = []
        for i in range(2):
            tmp = {}
            tmp['x'] = data[i,0,:]
            tmp['y'] = data[i,1,:]
            for j in range(4):
                tmp['v{}'.format(j+1)] = data[i,2+j,:]
            tmp['sum'] = data[i,6,:]+1.j*data[i,7,:]
            tmp['ref'] = data[i,8,:]+1.j*data[i,9,:]
            for j in range(10,16):
                tmp['rsv{}'.format(j+1)] = data[i,j,:]
            ret.append(pd.DataFrame(tmp))
        return ret
    def get_fa_data(self):
        if self.dmabuf is None:
            raise RuntimeError("DMA buffer not mmaped.")
        status, data = devapi.get_fa_data(self.dmabuf)
        ret = []
        for i in range(2):
            tmp = {}
            tmp['x'] = data[i,0,:]
            tmp['y'] = data[i,1,:]
            for j in range(4):
                tmp['v{}'.format(j+1)] = data[i,2+j,:]
            tmp['sum'] = data[i,6,:]+1.j*data[i,7,:]
            tmp['ref'] = data[i,8,:]+1.j*data[i,9,:]
            tmp['x3'] = data[i,10,:]
            tmp['y3'] = data[i,11,:]
            for j in range(12,16):
                tmp['rsv{}'.format(j+1)] = data[i,j,:]
            ret.append(pd.DataFrame(tmp))
        return ret
    def get_sa_data(self):
        if self.dmabuf is None:
            raise RuntimeError("DMA buffer not mmaped.")
        status, data = devapi.get_sa_data(self.dmabuf)
        ret = []
        for i in range(2):
            tmp = {}
            tmp['x'] = data[i,0,:]
            tmp['y'] = data[i,1,:]
            for j in range(4):
                tmp['v{}'.format(j+1)] = data[i,2+j,:]
            tmp['sum'] = data[i,6,:]+1.j*data[i,7,:]
            tmp['ref'] = data[i,8,:]+1.j*data[i,9,:]
            for j in range(4):
                tmp['x{}'.format(j+1)] = data[i,10+j*2,:]
                tmp['y{}'.format(j+1)] = data[i,11+j*2,:]
            for j in range(18,32):
                tmp['rsv{}'.format(j+1)] = data[i,j,:]
            ret.append(pd.DataFrame(tmp))
        return ret
    def get_sp_data(self):
        if self.dmabuf is None:
            raise RuntimeError("DMA buffer not mmaped.")
        status, data = devapi.get_sp_data(self.dmabuf)
        sp = []
        for i in range(2):
            mask = []
            for j in range(8):
                tmp = {}
                tmp['x'] = data[i,j,0,:]
                tmp['y'] = data[i,j,1,:]
                for k in range(4):
                    tmp['v{}'.format(k+1)] = data[i,j,2+k,:]
                tmp['sum'] = data[i,j,6,:]+1.j*data[i,j,7,:]
                mask.append(pd.DataFrame(tmp))
            sp.append(mask)
        return sp

