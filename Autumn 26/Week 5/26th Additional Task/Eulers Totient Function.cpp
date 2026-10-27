#include <iostream>
#include <vector>

int gcd(int a, int b){
    int largest, smallest, remainder;
    a > b? (largest = a, smallest = b): (smallest = a, largest = b);
    do{
        remainder = largest % smallest;
        largest = smallest;
        smallest = remainder;
    } while(remainder != 0);
    return largest;
}

int eulers_totient(int n){
    int phi = 0;
    for(int i = 1; i < n; i++){
        if(gcd(n, i) == 1) phi++;
    }
    return phi;
}

int totient_sum(int n, int &depth){
    int sum = 0; depth = 0;
    do{
        n = eulers_totient (n);
        sum += n; 
        depth ++;
    } while(n != 1);
    return sum;
}

int peak(int a, int b, int& depth_lower, int& depth_peak, int& depth_upper){
    int peak_strength = 0, peak_strength_max = 0, peak = 0;
    int h = 0;
    std::vector<int> depth(b-a+1);
    for(int i = a; i <= b; i++){
        totient_sum(i, depth[i-a]);
    }
    for(h = 1; h < b-a; h++){
        peak_strength = (depth[h] - depth[h-1] + depth[h] - depth[h+1]) / 2;
        if (peak_strength > peak_strength_max){
            peak_strength_max = peak_strength; 
            peak = h;
        } 
    }
    depth_lower = depth[peak - 1];
    depth_peak = depth[peak];
    depth_upper = depth[peak +1];
    if(peak_strength_max == 0) return -1;
    return peak + a;
}

int main(){
    int a, b, depth_lower, depth_peak, depth_upper;
    std::cin >> a >> b;
    std::cout << std::endl << peak(a, b, depth_lower, depth_peak, depth_upper) << " " << depth_peak << std::endl;
}