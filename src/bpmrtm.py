from .device import Device
from .register import Register
import time

NBPM = 2
NCH = 4

CLKSEL = {0: {0: "Front1", 1: "RFB1"},
          1: {0: "Front1", 1: "RFB1", 2: "Front2", 3: "RFB1"},
          4: {0: "Front1", 1: "RFB1", 2: "Front2", 3: "RFB1"},
          5: {0: "Front2", 1: "RFB2"}}
CALREFSEL = {0: "RFB", 1: "Front"}

ADDR = 0x10
REG_ATT = 0x00
REG_ATTCAL = 0x10
REG_CALOUT = 0x20
REG_CALFREQ = 0x30
REG_CLKSEL = {0: 0x50, 1: 0x52, 4: 0x53, 5: 0x51}
REG_CALREFSEL = 0x40

# check BPM number
def check_bpm(bpm):
    if bpm not in range(2):
        raise ValueError("BPM No.")

# Check channel number
def check_ch(ch):
    if ch not in range(4):
        raise ValueError("Channel")

# Attenuator index to dB
def att_index2db(iatt):
    return 31.5-0.5*iatt

# Attenuator dB to index
def att_db2index(att):
    return 63-int(att*2)

# Check attenuator value
def check_att(att):
    if att_db2index(att) not in range(64):
        raise ValueError("ATT")

class BPMRTM:
    """ BPM RTM class """
    def __init__(self, dev):
        if not isinstance(dev, Device):
            raise TypeError("Invalid device type.")
        self.dev = dev
    def get_att(self, bpm, ch):
        check_bpm(bpm)
        check_ch(ch)
        att = []
        for i in range(2):
            val = self.dev.user_i2c_read(ADDR, REG_ATT+bpm*8+ch*2+i)
            att.append(att_index2db(val))
            time.sleep(0.01)
        return tuple(att)
    def set_att(self, bpm, ch, att1=31.5, att2=31.5):
        check_bpm(bpm)
        check_ch(ch)
        check_att(att1)
        check_att(att2)
        self.dev.user_i2c_write(ADDR, REG_ATT+bpm*8+ch*2, att_db2index(att1))
        time.sleep(0.01)
        self.dev.user_i2c_write(ADDR, REG_ATT+bpm*8+ch*2+1, att_db2index(att2))
        time.sleep(0.01)
    def get_att_cal(self, ch):
        check_ch(ch)
        att = []
        for i in range(2):
            val = self.dev.user_i2c_read(ADDR, REG_ATTCAL+ch*2+i)
            att.append(att_index2db(val))
            time.sleep(0.01)
        return tuple(att)
    def set_att_cal(self, ch, att1=31.5, att2=31.5):
        check_ch(ch)
        check_att(att1)
        check_att(att2)
        self.dev.user_i2c_write(ADDR, REG_ATTCAL+ch*2, att_db2index(att1))
        time.sleep(0.01)
        self.dev.user_i2c_write(ADDR, REG_ATTCAL+ch*2+1, att_db2index(att2))
        time.sleep(0.01)
    def get_cal_out(self, ch):
        check_ch(ch)
        val = self.dev.user_i2c_read(ADDR, REG_CALOUT+ch)
        time.sleep(0.01)
        return bool(val)
    def set_cal_out(self, ch, out=False):
        check_ch(ch)
        if out:
            val = 1
        else:
            val = 0
        val = self.dev.user_i2c_write(ADDR, REG_CALOUT+ch,val)
        time.sleep(0.1)
    def get_cal_freq(self, ch):
        check_ch(ch)
        val = self.dev.user_i2c_read(ADDR, REG_CALFREQ+ch, 4)
        time.sleep(0.01)
        return val[0]*0x1000000 + val[1]*0x10000 + val[2]*0x100 + val[3]
    def set_cal_freq(self, ch, freq=508580000):
        check_ch(ch)
        ifreq = int(freq)
        val = []
        for i in range(4):
            val.append((ifreq>>(8*(3-i)))&0xff)
        self.dev.user_i2c_write(ADDR, REG_CALFREQ+ch, val)
        time.sleep(0.1)
    def get_clk_sel(self, ch):
        val = self.dev.user_i2c_read(ADDR, REG_CLKSEL[ch])
        return CLKSEL[ch][val]
    def set_clk_sel(self, ch, arg):
        val = [k for k,v in CLKSEL[ch].items() if v == arg]
        if val:
            self.dev.user_i2c_write(ADDR, REG_CLKSEL[ch], val[0])
        else:
            raise NameError
    def get_cal_ref_sel(self):
        val = self.dev.user_i2c_read(ADDR, REG_CALREFSEL)
        return CALREFSEL[val]
    def set_cal_ref_sel(self, ch, arg):
        val = [k for k,v in CALREFSEL.items() if v == arg]
        if val:
            self.dev.user_i2c_write(ADDR, REG_CALREFSEL, val[0])
        else:
            raise NameError

