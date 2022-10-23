'''
Takes csv data from a run of the track and plots it.
'''

import matplotlib as plt
import numpy as np

file = open("C:/Users/ljiang/OneDrive - Olin College of Engineering/Desktop/Olin 2022-2023/PIE/DC-Motor-Control/recording_data_3.csv", "r")

# clean empty values and strings from the list
contents = file.read().replace(",,,", ",").replace("STOP", "").replace("\n,\n", ",").replace(",,,", ",")
values = contents.split("\n")
for i, row in enumerate(values):
    values[i] = list(filter(None, row.split(",")))
values = list(filter(None, values))

print(values)
