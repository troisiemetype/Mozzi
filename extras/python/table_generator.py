import array
import os
import textwrap
import math
import sys

def computeRamp(index, length, depth):

    ## this is for a ramp (or phasor, or sawtooth)
    output = int(index / (float(length) / float(depth)) - depth / 2)

    return output

def computeSine(index, length, depth):
    ##pos is the ratio between current index and total length
    pos = (float(index) / length)
    angle = pos * 360
    angle = math.radians(angle)
    value = sine(angle)
    output = int(value * depth * 0.999999 / 2)

    return output

def computeSquare(index, length, depth, iterations):
    pos = (float(index) / length)
    angle = pos * 360
    angle = math.radians(angle)
    value = 0.0
    for i in range(1, iterations):
        if (i % 2) == 0:
            continue
        value += sine(angle * i) / i
    output = int(value * depth * 0.999999 / 2)
    return output

def computeMamelle(index, length, depth, iterations):
    pos = (float(index) / length)
    angle = pos * 360
    angle = math.radians(angle)
    value = 0.0
    sign = 1
    for i in range(1, iterations):
        if (i % 2) == 0:
            continue
        value += sign * sine(angle * i) / i
        sign *= -1
    output = int(value * depth * 0.999999 / 2)
    return output

def computeSpikes(index, length, depth, iterations):
    pos = (float(index) / length)
    angle = pos * 360
    angle = math.radians(angle)
    value = 0.0
    sign = 1
    for i in range(1, iterations):
        if (i % 2) == 0:
            continue
        value += sign * sine(angle * i)
        sign *= -1
    output = int(value * depth * 0.999999 / 2)
    return output

def computeTriangle(index, length, depth, iterations):
    pos = (float(index) / length)
    angle = pos * 360
    angle = math.radians(angle)
    value = 0.0
    sign = 1
    for i in range(1, iterations):
        if (i % 2) == 0:
            continue
        value += sign * sine(angle * i) / i**2

        sign *= -1
    output = int(value * depth * 0.999999 / 2)
    return output

def computeSawtooth(index, length, depth, iterations):
    pos = (float(index) / length)
    angle = pos * 360
    angle = math.radians(angle)
    value = 0.0
    sign = 1
    for i in range(1, iterations):
        value += sign * sine(angle * i) / i
        sign *= -1
    output = int(value * depth * 0.999999 / 2)
    return output

def compute(index, length, depth, iterations):
    pos = (float(index) / length)
    angle = pos * 360
    angle = math.radians(angle)
    value = 0.0
    sign = 1
    for i in range(1, iterations):
        if ((i % 2) == 0):
            continue
        value += sign * sine(angle * i) / i**0.5
        sign *= -1

    output = int(value * depth * 0.35 / 2)
    return output


def sine(angle):
    value = math.sin(angle)

    return value


def generate(tablename, tablelength, tabledepth, signed = 1):
    if (tabledepth != 8) & (tabledepth != 16) & (tabledepth !=32):
        print "table depth has to be 8, 16, or 32, to be consistant with int types"
        return

    length = 2**tablelength
    depth = 2**tabledepth
    offset = 0
    filename = tablename + str(length) + '_'
    if signed == 0:
        filename += 'u'
        offset = depth / 2
    filename += "int" + str(tabledepth) + ".h"
    tablename = tablename.upper()
    tablename += str(length)

    fout = open(os.path.expanduser(filename), "w")
    try:
        outstring = ''
        for num in range(length):
            outstring += str(compute(num, length, depth, 35) + offset) + '\n'
##            outstring += str(computeSawtooth(num, length, depth, 40) + offset) + ", " + '\n'
##            outstring += str(computeTriangle(num, length, depth, 15) + offset) + ", " + '\n'
##            outstring += str(computeSquare(num, length, depth, 42) + offset) + ", "
##            outstring += str(computeSine(num, length, depth) + offset) + ", "
        ##    outstring += str(int(num/(float(length) / float(depth))) + offset) + ", "  ## for saw line, or put your own generating code here
    finally:
        fout.write(outstring)
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
