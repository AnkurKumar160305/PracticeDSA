
// Template Fixed Size Sliding Window
// choose appropiate data structure according to the problem
int size = size of array
int k = window_size
int i = 0;
int j = 0;
while(j < size){
    // Prior calculation at each : j

    // reach to the window size
    if(j-i+1 < k){
        j++;
    } 
    // once reached the window size
    else if(j-i+1 == k){
        do calculation to get eligible candidate for answer

        remove calculation for i^th element
        //Slide the window
        i++;
        j++;
    }
}