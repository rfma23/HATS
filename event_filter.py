import numpy as np
import copy
import matplotlib.pyplot as plt

if __name__ == '__main__':

    # Take in name of the file
    fname = './sampledata/0.txt'

    # Open the input file and store lines in matrix
    with open(fname) as f:
        lines = f.readlines()

    # Create the object to hold file data
    data = np.zeros(len(lines), dtype=object)
    window = copy.deepcopy(data)

    # parameters and variables
    reference_time = 0
    delta_t = 10**3

    on_event_count = 0
    off_event_count = 0
    on_event_count_total = 0
    off_event_count_total = 0

    numvars = 3
    # (on event, off event, total) <- event rates formatting
    temp_window = np.array([])
    time_series = np.array([np.zeros(numvars)])

    # Fill data object
    for index, line in enumerate(lines):
        data[index] = np.array([int(x) for x in line.strip().split(' ')])
        on_event_count = on_event_count+1 if data[index][-1] == 1 else on_event_count
        off_event_count = off_event_count+1 if data[index][-1] == 0 else off_event_count
        temp_window = np.append(temp_window, data[index][-2])

        # if time window has elapsed
        if data[index][-2] - reference_time >= delta_t:
            
            # window computations
            window_event_rate = len(temp_window)/delta_t
            on_event_rate = on_event_count/delta_t
            off_event_rate = off_event_count/delta_t
            time_series = np.append(time_series, [[on_event_rate, off_event_rate, window_event_rate]], axis=0)

            # resets
            reference_time += delta_t
            on_event_count_total += on_event_count
            off_event_count_total += off_event_count
            on_event_count = 0
            off_event_count = 0
            temp_window = np.array([])

    time_series = time_series[1:]
    print(time_series)
    x = np.arange(np.shape(time_series)[0])
    y = time_series[:, 2]
    plt.plot(x, y)
    plt.show()
    
    