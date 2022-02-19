import sys
import os


def createCppClass(args):
    filename=args[1].capitalize()
    if(os.path.exists(f'include/{filename}.h')):
        print("Header file already exist - please change the name of your file and continue.")
        return
    f= open(f"include/{filename}.h","w+")
    f.write("#pragma once\n\n")
    f.write(f"class {filename}"+"{")
    f.write("\n\t\n")
    f.write("};")
    f.close()
    print(f'Header file include/{filename}.h created')
    source=open(f"src/{filename}.cpp","w+")
    source.write(f'#include "{filename}.h"'+"\n")
    source.write("")
    print(f'Source file src/{filename}.cpp created')
    source.close()
if __name__=='__main__':
    #print(sys.argv)
    if(len(sys.argv) > 1):
        if(sys.argv[1]):
            createCppClass(sys.argv)


    else:
        print("Provide file name first")