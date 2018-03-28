import sys
import logging

logger = logging.getLogger("log name")
hdlr = logging.FileHandler("path to log location")
formatter = logging.Formatter('%(asctime)s %(levelname)s %(message)s')
hdlr.setFormatter(formatter)
logger.addHandler(hdlr)
logger.setLevel(logging.DEBUG)


logger.info("your log message here")
logger.<your log level here>("another log message")

