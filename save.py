import tkinter as tk
from tkinter import filedialog


a=filedialog.asksaveasfile(mode="w",confirmoverwrite=True,defaultextension="txt")
print(a.name)

a.write("hello world...")

a.close()