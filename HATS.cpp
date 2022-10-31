#include "HATS.h"

vector<Event> filter_memory(vector<vector<Event>> memory, float event_ts, float temp_window){

}

vector<vector<int>> get_pixel_cell_partition_matrix(int width, int height, int K){
	
}

vector<vector<float>> normalise(vector<vector<float>> histograms, int event_counter){
	
}

vector<vector<float>> compute_local_memory_time_surface(Event ev, vector<Event> filtered_memory, int R, float tau){
	
}

HATS(float temp_window, int width, int height, float delta_t, float tau, int R, int K){
	
}

void reset(){
	
}

void process(Event ev){
	
}

void process_all(vector<Event> evs){
	
}
