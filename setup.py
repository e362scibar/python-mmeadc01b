from setuptools import setup, find_packages, Extension
import numpy as np

ext_devapi = Extension("mmeadc01b.devapi",
                sources=["src/devapi_wrap.c"],
                include_dirs=["src/devapi", "src/mmeadc01b", "src/upciedev",
                    np.get_include()],
                libraries=["mmeadc01bDevAPI"])

setup(name="mmeadc01b",
                version="1.0",
                description="MMEADC01B Library",
                author="Hirokazu Maesaka",
                author_email="maesaka@spring8.or.jp",
                url="http://xfel.riken.jp/",
                #packages=["mmeadc01b"],
                packages=find_packages(),
                #package_dir={"mmeadc01b":"src"},
                #package_data={"mmeadc01b": ["regdata.txt","errordata.txt",
                #        "bitinfo.json", "regadc.json"]},
                ext_modules = [ext_devapi]
                )

