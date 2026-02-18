long long countPerfectSquaresInRange(long long L, long long R) {
    // add your code here
    long long start=ceil(sqrt(L));
    long long end=floor(sqrt(R));
    if(end<start){
        return 0;
    }
    return end-start+1;
}