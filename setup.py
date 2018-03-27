from distutils.core import setup, Extension
import os

ext_devapi = Extension("mmeadc01b.devapi",
                sources=["src/devapi_wrap.c",
                        "src/devapi/dev_mmeadc01b_adc_read.c",
                        "src/devapi/dev_mmeadc01b_adc_write.c",
                        "src/devapi/dev_mmeadc01b_clear_dma_buf_status.c",
                        "src/devapi/dev_mmeadc01b_dac_read.c",
                        "src/devapi/dev_mmeadc01b_dac_write.c",
                        "src/devapi/dev_mmeadc01b_get_clk_src.c",
                        "src/devapi/dev_mmeadc01b_get_meta.c",
                        "src/devapi/dev_mmeadc01b_lmk_write.c",
                        "src/devapi/dev_mmeadc01b_mmap_dma_buf.c",
                        "src/devapi/dev_mmeadc01b_read.c",
                        "src/devapi/dev_mmeadc01b_register_interrupt_callback.c",
                        "src/devapi/dev_mmeadc01b_user_i2c_read.c",
                        "src/devapi/dev_mmeadc01b_user_i2c_write.c",
                        "src/devapi/dev_mmeadc01b_util.c",
                        "src/devapi/dev_mmeadc01b_write.c"],
                include_dirs=["src/devapi", "src/mmeadc01b", "src/upciedev"])

setup(name="mmeadc01b",
                version="1.0",
                description="MMEADC01B Library",
                author="Hirokazu Maesaka",
                author_email="maesaka@spring8.or.jp",
                url="http://xfel.riken.jp/",
                packages=["mmeadc01b"],
                package_dir={"mmeadc01b":"src"},
                ext_modules = [ext_devapi])

