'''
Takes csv data from a run of the track and plots it.
'''

from matplotlib import pyplot as plt
import numpy as np

file = open("C:/Users/ljiang/OneDrive - Olin College of Engineering/Desktop/Olin 2022-2023/PIE/DC-Motor-Control/recording_data_3.csv", "r")

# clean empty values and strings from the list
contents = file.read().replace(",,,", ",").replace("STOP", "").replace("\n,\n", ",").replace(",,,", ",")
values = contents.split("\n")
for i, row in enumerate(values):
    values[i] = list(filter(None, row.split(",")))
    # list is currently made of strings. convert to integers
    if i != 0:
        values[i] = [eval(i) for i in values[i]]

# remove the first row, which is the titles
titles = values.pop(0)
values = np.array(list(filter(None, values)))

fig = plt.figure(1)
ax = fig.add_subplot(1, 1, 1)
ax.plot(values[:,0], 'r', label=titles[0])
ax.plot(values[:,1], 'g', label=titles[1])
ax.plot(values[:,2], 'b', label=titles[2])
ax.plot(values[:,3], 'k', label=titles[3])

ax.set_title("Sensor Readings and Motor Speeds for Following Blob Shape")
ax.set_xlabel("Number of Arduino loops")
ax.set_ylabel("Sensor Readings and Motor Speeds")
ax.legend()


# get a small range of values. comment out to see data for entire blob shape
values = values[0:500,:]

fig = plt.figure(2)
ax = fig.add_subplot(1, 1, 1)
ax.plot(values[:,0], 'r', label=titles[0])
ax.plot(values[:,1], 'g', label=titles[1])
ax.plot(values[:,2], 'b', label=titles[2])
ax.plot(values[:,3], 'k', label=titles[3])

ax.set_title("Sensor Readings and Motor\nSpeeds for Following a Section of the Blob Shape")
ax.set_xlabel("Number of Arduino loops")
ax.set_ylabel("Sensor Readings and Motor Speeds")
ax.legend()

plt.show()