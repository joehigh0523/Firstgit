from IQmeasurePyWrapper import *


class TESTER_SETUP:
    TESTER_IP = ""
    MODULE_GROUP = {}
    NM = 1


class IQ_CONTROL:
    def __init__(self):
        return

    def try_run_tester(self, testip, moduleGroup, numberModule, portvsg, portvsa):
        print("Hi this is try run initial tester")
        print(testip)
        print(numberModule)
        print(portvsg)
        print(portvsa)
        nm = 1
        errorStat = 0
        setIQ = IQxel()
        setIQ.LP_Init()
        setIQ.LP_InitTesterN(testip.encode('utf-8'), numberModule)
        setIQ.LP_SetTesterMode(0, moduleGroup, 1)
        setIQ.LP_SetVsg(2412e6, 0, portvsg, 0,-25)
        setIQ.LP_SetVsa(2412e6, 0, portvsa, 0, -25)