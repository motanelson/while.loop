import tkinter as tk
import os
global rets 

rets=""



class myapps:
    def __init__(self,root:tk.Tk,title:str,backgrouds:str,foregrouds:str,types:str):
        self.root=root
        self.root.title(title)
        self.root.files=None
        self.root.configure(background=backgrouds)
        self.lists=tk.Listbox(background=backgrouds,foreground=foregrouds)
        self.lists.pack(padx=10,pady=10)
        self.entry=tk.Entry(background=backgrouds,foreground=foregrouds)
        self.entry.pack(padx=10,pady=10)
        self.button=tk.Button(background=backgrouds,foreground=foregrouds,text="ok",command=self.oks)
        self.button.pack(padx=10,pady=10)
        a=os.listdir(".")
        for b in a:
            if b.find(types)>-1:
                self.lists.insert(tk.END,b)
    def oks(self):
        global rets
        a=self.entry.get()
        if a.strip()!="":
            rets=a
            self.root.quit()
        else:
            
            try:
                self.root.files=self.lists.selection_get()
                rets=self.root.files
                
                self.root.quit()
            except:
                print("error")
                pass


def starts(title:str="save as ",backgrouds:str="black",foregrouds:str="white",types:str=".txt"):
    root=tk.Tk()
    apps=myapps(root,title,backgrouds,foregrouds,types)
    root.mainloop()
    return rets


a=starts(types=".py")
print(a)