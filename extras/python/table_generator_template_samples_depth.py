import array
import os
import textwrap
import sys

def compute(index, length, depth, offset):

    ## this is for a ramp (or phasor, or sawtooth)
    output = int(index / (float(length) / float(depth)) + offset)

    return output

def generate(tablename, tablelength, tabledepth, signed = 1):
    if (tabledepth != 8) & (tabledepth != 16) & (tabledepth !=32):
        print "table depth has to be 8, 16, or 32, to be consistent with int types"
        return

    length = 2**tablelength
    depth = 2**tabledepth
    offset = -depth / 2
    filename = tablename + str(length) + '_'
    if signed == 0:
        filename += 'u'
        offset = 0
    filename += "int" + str(tabledepth) + ".h"
    tablename.upper()
    tablename += str(length)

    fout = open(os.path.expanduser(filename), "w")
    fout.write('#ifndef ' + tablename + '_H_' + '\n')
    fout.write('#define ' + tablename + '_H_' + '\n \n')
    fout.write('#if ARDUINO >= 100'+'\n')
    fout.write('#include "Arduino.h"'+'\n')
    fout.write('#else'+'\n')
    fout.write('#include "WProgram.h"'+'\n')
    fout.write('#endif'+'\n')   
    fout.write('#include <avr/pgmspace.h>'+'\n \n')
    fout.write('#define ' + tablename + '_NUM_CELLS '+ str(length)+'\n')
    fout.write('#define ' + tablename + '_SAMPLERATE '+ str(length)+'\n \n')
    outstring = 'const int'
    outstring += str(tabledepth)
    outstring += '_t __attribute__((section(".progmem.data"))) ' + tablename + '_DATA [] = {'
    try:
        for num in range(length):
            outstring += str(compute(num, length, depth, offset)) + ", "
        ##    outstring += str(int(num/(float(length) / float(depth))) + offset) + ", "  ## for saw line, or put your own generating code here
    finally:
        outstring +=  "};"
        outstring = textwrap.fill(outstring, 80)
        fout.write(outstring)
        fout.write('\n \n #endif /* ' + tablename + '_H_ */\n')
        fout.close()
        print "wrote " + filename

try:
  generate(sys.argv[1], eval(sys.argv[2]), eval(sys.argv[3]), eval(sys.argv[4]))
except:
    try:
        generate(sys.argv[1], eval(sys.argv[2]), eval(sys.argv[3]))
    except:
        print "Not enough arguments provided."
        print "Arguements should be: table name, length, depth and signed"
        print "length beeing the bit size, i.e. 10 bits is 1024 values"
        print "depth beeing the resolution, 8, 16 or 32 bits"
        print "signed (default to 1) is optionnal:"
        print "0 is an unsigned number (e.g. 0 to 255), 1 is a signed number (e.g.-128 to 127)"##
