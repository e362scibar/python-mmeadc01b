import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import time
import mmeadc01b

dev = mmeadc01b.Device()
dev.open("/dev/mmeadc01bs10")
dev.wfm_init()
dev.wfm_start()
time.sleep(0.5)
dev.wfm_stop_soft()
time.sleep(0.5)
print("intr",dev.get_interrupt_status())
tbt = dev.get_tbt_data()
print(tbt)
dev.clear_dma_buf_status()
dev.wfm_terminate()
dev.close()

