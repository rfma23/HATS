import numpy as np
import copy

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
    delta = 10**3

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
        on_event_count = on_event_count+1 if data[index][-1] == 0 else on_event_count
        off_event_count = off_event_count+1 if data[index][-1] == 0 else off_event_count
        temp_window = np.append(temp_window, data[index][-2])
        print(temp_window)

        if data[index][-2] - reference_time >= delta:
            # window completed
            total_std = np.std(temp_window)
            
            # resets
            reference_time += delta
            on_event_count_total += on_event_count
            off_event_count_total += off_event_count
            on_event_count = 0
            off_event_count = 0
            np.delete(temp_window)

    print(on_event_count_total, off_event_count_total)
    