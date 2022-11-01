#include "HATS.h"
#include <cmath>
#include <cassert>
#include <vector>

vector<Event> filter_memory(vector<Event> memory, float event_ts, float temp_window){
    // finds all events between [event.ts-temp_window, event.ts)
    float limit_ts = event_ts - temp_window;
    
    // Due to the way it is built we only have to find the first extreme
    // Find it using binary search
    bool found = false;
    LRBound bound = {0, (int)(memory.size() - 1)};
    int pos = 0;
    
    // Step through memeory until extreme found
    // This will be done with a binary search algorithm
    while(bound.left<=bound.right && (found == false)){
        int midpoint = floor((bound.left + bound.right)/2);
        if(memory[midpoint].ts == limit_ts){
            pos = midpoint;
            found = true;
        }else{
            if(limit_ts < memory[midpoint].ts){
                LRBound bound = {bound.left, midpoint-1};
            }else{
                LRBound bound = {midpoint+1, bound.right};
			}
        }
    }           
    //Return all events starting from that index
    // To do this in C++, a new vector will be created and initialized with all values from pos to end of memeory
    // If returning wrong, specifically missing the first event, change pos to pos - 1
    vector<Event> returnMem((memory.begin() + pos), memory.end());
    return returnMem;
}

vector<vector<int>> get_pixel_cell_partition_matrix(int width, int height, int K){
    assert ((width % K == 0) && (height % K == 0));
        int cell_width = floor(width/K);
        int cell_height = floor(height/K);

        vector<vector<int>> matrix(height, vector<int> (width, 0));
        
        for (int i = 0; i < width; i ++) {
            for (int j = 0; j < height; j ++) {
                int pixel_row = floor(i / K);
                int pixel_col = floor(j / K);
                matrix[i][j] = pixel_row*cell_width + pixel_col;
            }
        }
        
        return matrix;
}

vector<vector<float>> normalise(vector<vector<float>> histograms, int event_counter){
	
}

vector<vector<float>> compute_local_memory_time_surface(Event ev, vector<Event> filtered_memory, int R, float tau){
	
}

HATS::HATS(float temp_window, int width, int height, float delta_t, float tau, int R, int K){
	
}

void HATS::reset(){
	
}

void HATS::process(Event ev){
	
}

void HATS::process_all(vector<Event> evs){
	
}
