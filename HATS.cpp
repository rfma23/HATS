#include "HATS.h"
#include <cmath>

vector<Event> filter_memory(vector<vector<Event>> memory, float event_ts, float temp_window){
    // finds all events between [event.ts-temp_window, event.ts)
    float limit_ts = event_ts - temp_window;
    
    // Due to the way it is built we only have to find the first extreme
    // Find it using binary search
    bool found = false;
    bound = LRBound(0, len(memory) - 1);
    
    // Step through memeory until extreme found
    while(bound.left<=bound.right && (found == false)){
        int pos = 0;
        int midpoint = floor((bound.left + bound.right)/2);
        // Not certain about using .ts for this with there being two layers of vectors
        if memory[midpoint].ts == limit_ts{
            pos = midpoint
            found = True
        }else{
			// Same as above comment
            if limit_ts < memory[midpoint].ts{
                bound = LRBound(bound.left, midpoint-1);
            }else{
                bound = LRBound(midpoint+1, bound.right);
			}
        }
    }           
    //Return all events starting from that index
    return memory[pos:]
}

vector<vector<int>> get_pixel_cell_partition_matrix(int width, int height, int K){
	
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
