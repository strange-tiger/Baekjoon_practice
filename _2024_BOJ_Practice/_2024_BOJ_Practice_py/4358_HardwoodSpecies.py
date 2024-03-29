# 4358_HardwoodSpecies.py

import sys

total = 0
species = dict()

while True :
    s = sys.stdin.readline().rstrip()
    if s == "":
        break
    total += 1
    if s in species :
            species[s] += 1
    else :
            species[s] = 1

species = dict(sorted(species.items()))
for i in species :
    num = species[i]
    per = num / total * 100
    
    print("%s %.4f" %(i, per))