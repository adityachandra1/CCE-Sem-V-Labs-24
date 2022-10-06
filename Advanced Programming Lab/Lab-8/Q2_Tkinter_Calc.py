from tkinter import *

calc = Tk()
calc.geometry("330x360")
calc.title("Calculator")
calcLabel = Label(calc, text="Calculator", bg='White',font=("Courier New", 30, 'bold'))
calcLabel.pack(side=TOP)
calc.config(background='dark slate grey')

textin = StringVar()
operator = ""


def clickbut(number):  # lambda:clickbut(1)
    global operator
    operator = operator+str(number)
    textin.set(operator)


def equlbut():
    global operator
    add = str(eval(operator))
    textin.set(add)
    operator = ''


def clrbut():
    textin.set('')


metext = Entry(calc, font=("Courier New", 20, 'bold'),
               textvar=textin, width=50, bd=5, bg='powder blue')
metext.pack()

but1 = Button(calc, bg='white', font =("Courier New", 20, 'bold'), command=lambda: clickbut(1), text="1")
but1.place(x=10, y=100)

but2 = Button(calc, bg='white', font =("Courier New", 20, 'bold'), command=lambda: clickbut(2), text="2")
but2.place(x=10, y=170)

but3 = Button(calc, bg='white', font =("Courier New", 20, 'bold'), command=lambda: clickbut(3), text="3")
but3.place(x=10, y=240)

but4 = Button(calc, bg='white', font =("Courier New", 20, 'bold'), command=lambda: clickbut(4), text="4")
but4.place(x=75, y=100)

but5 = Button(calc, bg='white', font =("Courier New", 20, 'bold'), command=lambda: clickbut(5), text="5")
but5.place(x=75, y=170)

but6 = Button(calc, bg='white', font =("Courier New", 20, 'bold'), command=lambda: clickbut(6), text="6")
but6.place(x=75, y=240)

but7 = Button(calc, bg='white', font =("Courier New", 20, 'bold'), command=lambda: clickbut(7), text="7")
but7.place(x=140, y=100)

but8 = Button(calc, bg='white', font =("Courier New", 20, 'bold'), command=lambda: clickbut(8), text="8")
but8.place(x=140, y=170)

but9 = Button(calc, bg='white', font =("Courier New", 20, 'bold'), command=lambda: clickbut(9), text="9")
but9.place(x=140, y=240)

but0 = Button(calc, bg='white', font =("Courier New", 20, 'bold'), command=lambda: clickbut(0), text="0")
but0.place(x=10, y=310)

butdot = Button(calc, bg='white', font =("Courier New", 20, 'bold'), command=lambda: clickbut("."), text=".")
butdot.place(x=75, y=310)

butpl = Button(calc, bg='white', text="+", font =("Courier New", 20, 'bold'), command=lambda: clickbut("+"))
butpl.place(x=205, y=100)

butsub = Button(calc, bg='white', text="-", font =("Courier New", 20, 'bold'), command=lambda: clickbut("-"))
butsub.place(x=205, y=170)

butml = Button(calc, bg='white', text="*", font =("Courier New", 20, 'bold'), command=lambda: clickbut("*"))
butml.place(x=205, y=240)

butdiv = Button(calc, bg='white', text="/", font =("Courier New", 20, 'bold'), command=lambda: clickbut("/"))
butdiv.place(x=205, y=310)

butmod = Button(calc, bg='white', font =("Courier New", 20, 'bold'), command=lambda: clickbut("%"), text="%")
butmod.place(x=140, y=310)

butclear = Button(calc, bg='red', font =("Courier New", 20, 'bold'), text="CE", command=clrbut)
butclear.place(x=270, y=100)

butequal = Button(calc, bg='green', font =("Courier New", 20, 'bold'), command=equlbut, text="=")
butequal.place(x=270, y=200)
calc.mainloop()
