from tkinter import *
from tkinter import ttk
from testtry import *
from IQmeasurePyWrapper import *
import subprocess
# -----create window----- #


class port_sel:
    VSAP = 0
    VSGP = 0


class Setup_t:
    #settest = TESTER_SETUP
    TC = TESTER_SETUP()
    IQC = IQ_CONTROL()
    SETPORT = IQAPI_PORT_ENUM()


class Ace_python_GUI:

    def __init__(self):
        self.Py_sample = Tk()
        self.Py_sample.title("ACE_PYTHON_SAMPLE_CODE")
        self.Py_sample.geometry("1024x800")
        self.Py_sample.maxsize(1024, 800)
        self.Py_sample.minsize(1024, 800)
        #TC = TESTER_SETUP()
        #IQC = IQ_CONTROL()
        self.List2G = ['1', '2', '3', '4', '5', '6', '7', '8', '9', '10', '11',
         '12', '13', '14']
        self.List5G = ['1', '2']
        #   frame create
        testfrm = LabelFrame(self.Py_sample,text="Output", width=1024, height=400, bg="gray60", bd=5, relief=SUNKEN)
        testfrm.pack()
        # ListBox output result
        output_frm = LabelFrame(testfrm, text="Output Meassage" ,font=("Times", 10, "normal"), bg="khaki1",
                                padx=1, pady=20)
        output_frm.place(anchor = NW)
        output_txt = Text(output_frm, width=80, height=20, wrap=WORD)
        output_txt.pack()
        #   frame create
        testfrm2 = Frame(self.Py_sample, width=1024, height=400, bg="gray80", bd=5, relief=SUNKEN)
        testfrm2.pack()
        #
        # labelframe create
        Testerip_frame = LabelFrame(testfrm2, text="TesterIP", font=("Times", 10, "normal"), bg="khaki1", padx=40,
                                    pady=5)
        Testerip_frame.place(x=5, y=10)
        self.Ip = StringVar()
        entip = Entry(Testerip_frame, width=22, textvariable=self.Ip)
        entip.pack()
        # labeframe 2
        Testerip_frame2 = LabelFrame(testfrm2, text="Select Rout", font=("Times", 10, "normal"), bg="khaki1",
                                     padx=40, pady=5)
        Testerip_frame2.place(x=260, y=10)
        # radio btn Rout 1 2 3 4
        Rout = ((1, 'Rout1'), (2, 'Rout2'), (3, 'Rout3'), (4, 'Rout4'))
        self.rout_val = IntVar()
        self.rout_val.set(0)
        #
        for value , item in Rout:
            rout_bt = Radiobutton(Testerip_frame2, text = item, variable=self.rout_val, value=value, bg='white')
            rout_bt.grid(column=value, row=0 )

        #
        Testerframe4 = LabelFrame(testfrm2, text="Select Frequency and channel", font=("Times", 10, "normal"), bg="khaki1",
                                     padx=40, pady=5)
        Testerframe4.place(x=260, y=70)

        self.cmbx4 = ttk.Combobox(Testerframe4, width=10)
        self.cmbx4.grid(column=0, row=0)
        self.cmbx4['value'] = ('2.4G', '5G')
        self.cmbx4.bind("<<select>>", self.combbpost)
        self.cmbx5 = ttk.Combobox(Testerframe4, value=self.List2G, width=10)
        self.cmbx5.grid(column=1, row=0)
       # if self.combbpost() != "5G":
          # self.cmbx5['value'] = ('1', '2', '3', '4', '5', '6', '7', '8', '9', '10', '11',
                        #           '12', '13', '14')
       # else:
            #self.cmbx5['value'] = ('3','4')
        # check btn Rout 1 2 3 4
        # self.rout1 = IntVar()
        # chk_rout1 = Checkbutton(Testerip_frame2, variable=self.rout1, width=20, text="Rout1")
        # chk_rout1.pack()
        # #
        # self.rout2 = IntVar()
        # chk_rout2 = Checkbutton(Testerip_frame2, variable=self.rout2, width=20, text="Rout2")
        # chk_rout2.pack()
        # #
        # self.rout3 = IntVar()
        # chk_rout3 = Checkbutton(Testerip_frame2, variable=self.rout3, width=20, text="Rout3")
        # chk_rout3.pack()
        # #
        # self.rout4 = IntVar()
        # chk_rout4 = Checkbutton(Testerip_frame2, variable=self.rout4, width=20, text="Rout4")
        # chk_rout4.pack()
        # labeframe 2
        Testerip_frame3 = LabelFrame(testfrm2, text="Select Port", font=("Times", 10, "normal"), bg="khaki1",
                                     padx=36, pady=5)
        Testerip_frame3.place(x=5, y=60)
        #  combo box1 for VSA Setup
        vsa_label = Label(Testerip_frame3, text='VSA PORT', width=10, bd=1, relief="solid")
        vsa_label.grid(column=0, row=0)
        self.cmbx1 = ttk.Combobox(Testerip_frame3, width=10)
        self.cmbx1.grid(column=1, row=0)
        self.cmbx1['value'] = ('PortA', 'PortB', 'PortC', 'PortD')
        #  combo bod2 for VSG Setup
        vsg_label = Label(Testerip_frame3, text='VSG PORT', width=10, bd=1, relief="solid")
        vsg_label.grid(column=0, row=1)
        self.cmbx2 = ttk.Combobox(Testerip_frame3, width=10)
        self.cmbx2.grid(column=1, row=1)
        self.cmbx2['value'] = ('PortA', 'PortB', 'PortC', 'PortD')
        #   button1 test connection
        btn1 = Button(testfrm2, width=10, height=2,
        bg="DarkOrange3", fg="black", font=("Times", 10, "normal"),
        relief="raised",text="Try_tester",
        command=lambda: Setup_t.IQC.try_run_tester(Setup_t.TC.TESTER_IP, Setup_t.TC.MODULE_GROUP, Setup_t.TC.NM, port_sel.VSGP, port_sel.VSAP))
        btn1.place(x=900, y=10)
           #button2 test connection
        btn2 = Button(testfrm2, width=10, height=2,
        bg="DarkOrange3", fg="black", font=("Times",10,"normal"),
        relief="raised", text="Setup",
        command=self.GetIP)
        btn2.place(x=900, y=60)

        subprocess.Popen(['echo', 'Try execute sub command or program'], shell=False)
        self.Py_sample.mainloop()


    def combbpost(self):
        setfreq = self.cmbx4.get()
        print(setfreq)
        if setfreq != '5G':
            tmplist = self.List2G
        else:
            tmplist = self.List5G
        self.cmbx5.config(value=tmplist)


    def GetIP(self):
        #if self.rout1.get():
       # selected_rout = self.rout_val.get()
        Setup_t.TC.MODULE_GROUP = {self.rout_val.get()}
        Setup_t.TC.TESTER_IP = self.Ip.get()
        if self.cmbx2.get() != "":
            if self.cmbx2.get() == "PortA" :
                port_sel.VSGP = Setup_t.SETPORT.PORT_1
                print("selvsgport=", port_sel.VSGP)
            elif self.cmbx2.get() == "PortB" :
                port_sel.VSGP = Setup_t.SETPORT.PORT_2
                print("selvsgport=", port_sel.VSGP)
            elif self.cmbx2.get() == "PortC":
                port_sel.VSGP = Setup_t.SETPORT.PORT_3
                print("selvsgport=", port_sel.VSGP)
            elif self.cmbx2.get() == "PortD":
                port_sel.VSGP = Setup_t.SETPORT.PORT_4
                print("selvsgport=", port_sel.VSGP)


        if self.cmbx1.get() != "":
            if self.cmbx1.get() == "PortA" :
             port_sel.VSAP = Setup_t.SETPORT.PORT_1
             print("selvsaport=", port_sel.VSAP)
            elif self.cmbx1.get() == "PortB" :
                port_sel.VSAP = Setup_t.SETPORT.PORT_2
                print("selvsaport=", port_sel.VSAP)
            elif self.cmbx1.get() == "PortC":
                port_sel.VSAP = Setup_t.SETPORT.PORT_3
                print("selvsaport=", port_sel.VSAP)
            elif self.cmbx1.get() == "PortD":
                port_sel.VSAP = Setup_t.SETPORT.PORT_4
                print("selvsaport=", port_sel.VSAP)


        print(Setup_t.TC.TESTER_IP)

# ----Start GUI---- #


Ace_python_GUI()
