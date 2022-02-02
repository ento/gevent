import sys

import gevent

import mxcsr


daz_enabled = mxcsr.daz_enabled()
ftz_enabled = mxcsr.ftz_enabled()

print(f"{daz_enabled=}")
print(f"{ftz_enabled=}")

if daz_enabled or ftz_enabled:
    print("Did not expect DAZ nor FTZ to be enabled.")
    sys.exit(1)
