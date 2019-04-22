from . import devapi
from .error import Error
from .register import Register
from .bitfield import Bitfield
from .adcreg import AdcRegister
import ctypes
import time
import numpy as np
import pandas as pd

NCH = 10
NFIR = 17
NBPM = 2
NSPMASK = 4
LENSP = 4096
NSPAREA = 4
NFIRCOD = 20
NFIRTBT = 15
NTONE = 4
NFIRTONE = 20

META = ["ADC_WFM", "IQ_WFM", "SP_WFM", "CT_L", "CT_H",
        "BPM1TBT", "BPM1FA", "BPM1SA", "BPM1SP",
        "BPM2TBT", "BPM2FA", "BPM2SA", "BPM2SP"]

CODMODE = ["TBT", "FA", "SA"]

DMA_REQ_WFM = 1
DMA_REQ_TONE = [1<<4, 1<<5]
DMA_REQ_TBT = [1<<8, 1<<16]
DMA_REQ_FA = [1<<9, 1<<17]
DMA_REQ_SA = [1<<10, 1<<18]
DMA_REQ_SP = [[1<<(i+11) for i in range(NSPAREA)], [1<<(i+19) for i in range(NSPAREA)]]

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
    def adc_read(self, id_adc, reg):
        if self.fd is None:
            raise RuntimeError("Device not opened.")
        if isinstance(reg, AdcRegister):
            r = AdcRegister(reg.name)
        else:
            r = AdcRegister(reg)
        status, data = devapi.adc_read(self.fd, id_adc, r.addr, r.reg["length"])
        if status:
            raise Error(status)
        r.value = 0
        for i in range(r.reg["length"]):
            r.value |= data[i] << (i*8)
        return r
    def adc_write(self, id_adc, reg, data=None):
        if self.fd is None:
            raise RuntimeError("Device not opened.")
        if isinstance(reg, AdcRegister):
            r = AdcRegister(reg.name, reg.value)
        else:
            r = AdcRegister(reg, data)
        tmp = [(r.value>>(i*8))&0xFF for i in range(r.reg["length"])]
        status = devapi.adc_write(self.fd, id_adc, r.addr, tuple(tmp))
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
        meta = self.get_meta()
        self.start_dma_xfer(DMA_REQ_WFM, meta["ADC_WFM"]["idx_latest"])
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
            raise ValueError("Invalid channel. {}".format(ch))
        self.write(Register("FIR_COEFF_CHSEL"), ch)
        fir = []
        for i in range(NFIR):
            ret = self.read(Register("FIR_COEFF_{:02d}".format(i)))
            fir.append(np.int16(ret) / 2**14)
        return fir
    def set_fir_coeff(self, ch, coeff=[1]):
        if ch not in range(NCH):
            raise ValueError("Invalid channel. {}".format(ch))
        if len(coeff) < NFIR:
            coeff.reverse().extend([0]*(NFIR-len(coeff))).reverse()
        for i in range(NFIR):
            ival = coeff[i]*2**14
            if ival > 0x7fff:
                val = 0x7fff
            elif ival < -0x8000:
                val = -0x8000
            else:
                val = int(round(ival))
            self.write(Register("FIR_COEFF_{:02d}".format(i)), val&0xFFFF)
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
        #status, gain, phase = devapi.get_rot_coeff(self.fd, ch)
        if ch == 0: # DAC
            gain = self.read(Register("DAC_OUT_ROT_GAIN")) & 0xffff
            gain /= 0x1000
            phase = self.read(Register("DAC_OUT_ROT_THETA")) & 0xffff
            phase *= np.pi / 0x10000
        else: # IQ
            if (ch-1) not in range(NCH):
                raise ValueError("Invalid channel. {}".format(ch))
            elem = {}
            for k in ("A", "B", "C"):
                elem[k] = self.read(Register("IQ{:02d}_ROT_{}".format(ch, k))) & 0x3ffff
                if elem[k] >= 0x20000:
                    elem[k] -= 0x40000
                elem[k] /= 0x4000
            gain = np.sqrt(elem["A"]**2 - elem["B"]*elem["C"])
            phase = np.arctan2((elem["C"]-elem["B"])/2., elem["A"])
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
        meta = self.get_meta()
        bit = ["CT_L", "CT_H"]
        for i in range(2):
            idx = meta[bit[i]]["idx_latest"]
            self.start_dma_xfer(DMA_REQ_TONE[i], idx)
        status, data = devapi.get_waveform_tone(self.dmabuf)
        if status:
            raise Error(status)
        return data
    def get_sp_wfm(self):
        if self.dmabuf is None:
            raise RuntimeError("DMA buffer not mmaped.")
        status, sp = devapi.get_waveform_sp(self.dmabuf)
        return sp

    # BPM data
    def get_tbt_data(self):
        if self.dmabuf is None:
            raise RuntimeError("DMA buffer not mmaped.")
        ret = []
        meta = self.get_meta()
        for i in range(NBPM):
            idx = meta["BPM{}TBT".format(i+1)]["idx_latest"]
            self.start_dma_xfer(DMA_REQ_TBT[i], idx)
            status, data = devapi.get_tbt_data(self.dmabuf, i)
            tmp = {}
            tmp['x'] = data[0,:] / 2.**20
            tmp['y'] = data[1,:] / 2.**20
            for j in range(4):
                tmp['v{}'.format(j+1)] = data[2+j,:] / 2.**21
            tmp['sum'] = (data[6,:] + 1.j*data[7,:]) / 2.**23
            tmp['ref'] = (data[8,:] + 1.j*data[9,:]) / 2.**21
            #for j in range(10,16):
            #    tmp['rsv{}'.format(j+1)] = data[j,:]
            ret.append(pd.DataFrame(tmp))
        return ret
    def get_fa_data(self):
        if self.dmabuf is None:
            raise RuntimeError("DMA buffer not mmaped.")
        ret = []
        meta = self.get_meta()
        for i in range(NBPM):
            idx = meta["BPM{}FA".format(i+1)]["idx_latest"]
            self.start_dma_xfer(DMA_REQ_FA[i], idx)
            status, data = devapi.get_fa_data(self.dmabuf, i)
            tmp = {}
            tmp['x'] = data[0,:] / 2.**20
            tmp['y'] = data[1,:] / 2.**20
            for j in range(4):
                tmp['v{}'.format(j+1)] = data[2+j,:] / 2.**21
            tmp['sum'] = (data[6,:] + 1.j*data[7,:]) / 2.**23
            tmp['ref'] = (data[8,:] + 1.j*data[9,:]) / 2.**21
            tmp['x3'] = data[10,:] / 2.**20
            tmp['y3'] = data[11,:] / 2.**20
            #for j in range(12,16):
            #    tmp['rsv{}'.format(j+1)] = data[j,:]
            ret.append(pd.DataFrame(tmp))
        return ret
    def get_sa_data(self):
        if self.dmabuf is None:
            raise RuntimeError("DMA buffer not mmaped.")
        ret = []
        meta = self.get_meta()
        for i in range(NBPM):
            idx = meta["BPM{}SA".format(i+1)]["idx_latest"]
            self.start_dma_xfer(DMA_REQ_SA[i], idx)
            status, data = devapi.get_sa_data(self.dmabuf, i)
            tmp = {}
            tmp['x'] = data[0,:] / 2.**20
            tmp['y'] = data[1,:] / 2.**20
            for j in range(4):
                tmp['v{}'.format(j+1)] = data[2+j,:] / 2.**21
            tmp['sum'] = (data[6,:] + 1.j*data[7,:]) / 2.**23
            tmp['ref'] = (data[8,:] + 1.j*data[9,:]) / 2.**21
            for j in range(4):
                tmp['x{}'.format(j+1)] = data[10+j*2,:] / 2.**20
                tmp['y{}'.format(j+1)] = data[11+j*2,:] / 2.**20
            #for j in range(18,32):
            #    tmp['rsv{}'.format(j+1)] = data[j,:]
            ret.append(pd.DataFrame(tmp))
        return ret
    def get_sp_data(self):
        if self.dmabuf is None:
            raise RuntimeError("DMA buffer not mmaped.")
        sp = []
        meta = self.get_meta()
        for i in range(NBPM):
            idx = meta["BPM{}SP".format(i+1)]["idx_latest"]
            area = []
            for j in range(NSPAREA):
                self.start_dma_xfer(DMA_REQ_SP[i][j], idx)
                status, data = devapi.get_sp_data(self.dmabuf, i, j)
                mask = []
                for k in range(NSPMASK):
                    tmp = {}
                    tmp['x'] = data[k,0,:] / 2.**20
                    tmp['y'] = data[k,1,:] / 2.**20
                    for l in range(4):
                        tmp['v{}'.format(l+1)] = data[k,2+l,:] / 2.**21
                    tmp['sum'] = (data[k,6,:] + 1.j*data[k,7,:]) / 2.**23
                    mask.append(pd.DataFrame(tmp))
                area.append(mask)
            mask = []
            for j in range(NSPMASK):
                tmp = [area[k][j] for k in range(NSPAREA)]
                mask.append(pd.concat(tmp, ignore_index=True))
            sp.append(mask)
        return sp

    # COD FIR Filter
    def get_cod_fir_coeff(self, mode="SA"):
        fir = []
        if mode in ("FA", "SA"):
            n = NFIRCOD
        elif mode == "TBT":
            n = NFIRTBT
        else:
            raise TypeError("Invalid mode. {}".format(mode))
        for i in range(n):
            ret = self.read(Register("COD_FIR_COEFF_{:02d}".format(i)))
            fir.append(np.int16(ret) / 2**14)
        return fir
    def set_cod_fir_coeff(self, mode="SA", ch=0, coeff=[1]):
        if ch not in range(NCH):
            raise ValueError("Invalid channel. {}".format(ch))
        if mode == "SA":
            n = NFIRCOD
            strsel = 2
        elif mode == "FA":
            n = NFIRCOD
            strsel = 1
        elif mode == "TBT":
            n = NFIRTBT
            strsel = 0
        else:
            raise TypeError("Invalid mode. {}".format(mode))
        if len(coeff) < n:
            coeff.reverse().extend([0]*(n-len(coeff))).reverse()
        for i in range(n):
            ival = coeff[i]*2**14
            if ival > 0x7fff:
                val = 0x7fff
            elif ival < -0x8000:
                val = -0x8000
            else:
                val = int(round(ival))
            self.write(Register("COD_FIR_COEFF_{:02d}".format(i)), val&0xFFFF)
        self.write(Register("COD_FIR_COEFF_CHSEL"), ch)
        self.write(Register("COD_FIR_COEFF_STRSEL"), strsel)
        self.write(Register("COD_FIR_COEFF_UPD"), 1)
        time.sleep(0.001)
        self.write(Register("COD_FIR_COEFF_UPD"), 0)
    def get_cod_fir_sw(self):
        return Bitfield("COD_FIR", self.read(Register("COD_FIR_ON")))
    def set_cod_fir_sw(self, arg):
        if isinstance(arg, Bitfield) and arg.name != "COD_FIR":
            return TypeError("Invalid Bitfield ({}).".format(arg.name))
        self.write(Register("COD_FIR_ON"), int(arg))

    # SP Mode
    def get_sp_mask(self, ch, idx):
        if ch not in range(NBPM):
            raise ValueError("Invalid channel. {}".format(ch))
        if idx not in range(NSPMASK):
            raise ValueError("Invalid mask index. {}".format(idx))
        ret = (self.read(Register("SP_BPM{}_MASK{}".format(ch+1,idx+1)), LENSP//32))
        mask = np.array([(i>>j)&1 for i in ret for j in range(32)], np.uint8)
        return mask
    def set_sp_mask(self, ch, idx, mask):
        if ch not in range(NBPM):
            raise ValueError("Invalid channel. {}".format(ch))
        if idx not in range(NSPMASK):
            raise ValueError("Invalid mask index. {}".format(idx))
        if len(mask) > LENSP:
            raise ValueError("Mask too long. {}".format(len(mask)))
        arg = [0] * (LENSP//32)
        for i,j in enumerate(mask):
            arg[i//32] |= int(j!=0)<<(i%32)
        self.write(Register("SP_BPM{}_MASK{}".format(ch+1,idx+1)), arg)
    def get_rev_clk_src(self):
        ret = self.read(Register("SP_REV_INIT_TRIG"))
        return Bitfield("DIO", ret)
    def set_rev_clk_src(self, arg):
        if isinstance(arg, Bitfield) and arg.name != "DIO":
            return TypeError("Invalid Bitfield ({}).".format(arg.name))
        self.write(Register("SP_REV_INIT_TRIG"), int(arg))
    def get_sp_wfm_sel(self):
        return self.read(Register("SP_WAVE_MASK_SEL"))
    def set_sp_wfm_sel(self, idx):
        if idx not in range(NSPMASK):
            raise ValueError("Invalid mask index. {}".format(idx))
        self.write(Register("SP_WAVE_MASK_SEL"), idx)
    def get_sp_debug(self):
        period = self.read(Register("REV_PERIOD"))
        dout = self.read(Register("REV_OUT"))
        return period, dout
    def set_sp_debug(self, period, dout):
        self.write(Register("REV_PERIOD"), period)
        self.write(Register("REV_OUT"), dout)

    # Cal. Tone
    def get_tone_nco(self, ch, fiq=508.58e6*5./28.):
        if ch not in range(NTONE):
            raise ValueError("Invalid channel. {}".format(ch))
        ret = self.read(Register("TONE_NCO_{}_FREQ".format(ch+1)))
        if ret > 0x7FFFFFFF:
            ret -= 2**32
        return fiq * ret / 2**32
    def set_tone_nco(self, ch, freq, fiq=508.58e6*5./28.):
        if ch not in range(NTONE):
            raise ValueError("Invalid channel. {}".format(ch))
        if freq > fiq*0.5 or freq < -fiq*0.5:
            raise ValueError("Invalid frequency. {}".format(freq))
        val = round(freq / fiq * 2**32)
        if val < 0:
            val += 2**32
        self.write(Register("TONE_NCO_{}_FREQ".format(ch+1)), val)
    def get_tone_fir_coeff(self):
        fir = []
        for i in range(NFIRTONE):
            ret = self.read(Register("TONE_FIR_COEFF_{:02d}".format(i)))
            fir.append(np.int16(ret) / 2**14)
        return fir
    def set_tone_fir_coeff(self, ch=0, coeff=[1]):
        if ch not in range(NTONE*2):
            raise ValueError("Invalid channel. {}".format(ch))
        if len(coeff) < NFIRTONE:
            coeff.reverse().extend([0]*(NFIRTONE-len(coeff))).reverse()
        for i in range(NFIRTONE):
            ival = coeff[i]*2**14
            if ival > 0x7fff:
                val = 0x7fff
            elif ival < -0x8000:
                val = -0x8000
            else:
                val = int(round(ival))
            self.write(Register("TONE_FIR_COEFF_{:02d}".format(i)), val&0xFFFF)
        self.write(Register("TONE_FIR_CH_SEL"), ch)
        self.write(Register("TONE_FIR_UPD"), 1)
        time.sleep(0.001)
        self.write(Register("TONE_FIR_UPD"), 0)
    def get_tone_fir_sw(self):
        ret = self.read(Register("TONE_FIR_ON"))
        return bool(ret&1), bool((ret>>1)&1)
    def set_tone_fir_sw(self, on1, on2):
        val = 0
        if on1:
            val |= 1
        if on2:
            val |= 2
        self.write(Register("TONE_FIR_ON"), val)
    def get_tone_sw(self):
        ret = []
        for i in range(2):
            ret.append(self.read(Register("TONE_TX_CTRL_{}".format(i+1))))
        return bool(ret[0]), bool(ret[1])
    def set_tone_sw(self, on1, on2):
        val = [0,0]
        if on1:
            val[0] = 1
        if on2:
            val[1] = 1
        for i in range(2):
            self.write(Register("TONE_TX_CTRL_{}".format(i+1)), val[i])
    def get_tone_ch_sel(self):
        ''' 0: cyclic, 1: CH1(6), 2: CH2(7), 3: CH3(8), 4: CH4(9), 5: CH5(10)'''
        ret = []
        for i in range(2):
            ret.append(self.read(Register("TONE_CH_SEL_{}".format(i+1))))
        return ret[0], ret[1]
    def set_tone_ch_sel(self, ch1, ch2):
        if ch1 < 0 or ch1 > 5:
            raise ValueError("Invalid channel 1. {}".format(ch1))
        if ch2 < 0 or ch2 > 5:
            raise ValueError("Invalid channel 2. {}".format(ch2))
        val = [ch1, ch2]
        for i in range(2):
            self.write(Register("TONE_CH_SEL_{}".format(i+1)), val[i])
    def get_tone_time(self):
        '''channel switching interval (float) [sec]'''
        ret = self.read(Register("TONE_TRANS_TIME"))
        return ret / 10.
    def set_tone_time(self, t):
        '''channel switching interval (float) [sec]'''
        if t < 0.1 or t > 1.5:
            raise ValueError("Invalid time (0.1 - 1.5). {}".format(t))
        val = round(t * 10.)
        self.write(Register("TONE_TRANS_TIME"), val)

