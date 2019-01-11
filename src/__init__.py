from .device import Device
from .register import Register
from .error import Error
from .bitfield import Bitfield
Register.read_data(__path__[0])
Error.read_data(__path__[0])
Bitfield.read_data(__path__[0])

