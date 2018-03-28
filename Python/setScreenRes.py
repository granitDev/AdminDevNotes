import sys
import win32api
from pywintypes import DEVMODEType
import logging

print("\nsetScreenRes started...")

logger = logging.getLogger("Set Screen Resolution")
hdlr = logging.FileHandler("c:\epic\other_scripts\setScreenRes.log")
formatter = logging.Formatter('%(asctime)s %(levelname)s %(message)s')
hdlr.setFormatter(formatter)
logger.addHandler(hdlr)
logger.setLevel(logging.DEBUG)


resolution_list = [[3840,2160], [2556,1440], [1920,1080], [1680,1050], [1600,1024], [1600,900]]

depth = 32
response = -2
resItem = 0
attempts = 10

while response != 0 and attempts != 0:
    width = resolution_list[resItem][0]
    height = resolution_list[resItem][1]
    
    mode1 = win32api.EnumDisplaySettings()
    mode1.PelsWidth = width
    mode1.PelsHeight = height
    mode1.BitsPerPel = depth

    response = win32api.ChangeDisplaySettings(mode1, 0)
    
    outcome = "failed"
    if response == 0:
        outcome = "success"
    
    message = "trying resolution %d x %d....%s code: %d" % (width, height, outcome, response)
    logger.info(message)
    print(message)
    
    resItem += 1
    attempts -= 1
