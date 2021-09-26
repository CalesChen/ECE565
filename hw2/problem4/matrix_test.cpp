#include <iostream>
#include <vector>
#include <time.h>


double calc_time(struct timespec start, struct timespec end) { 
  double start_sec = (double)start.tv_sec*1000000000.0 + (double)start.tv_nsec; 
  double end_sec = (double)end.tv_sec*1000000000.0 + (double)end.tv_nsec; 
  if (end_sec < start_sec) {  
    return 0;   
  } else {   
    return end_sec - start_sec;
  } 
}
void ijk(std::vector<std::vector<double>> & A, std::vector<std::vector<double>> & B,
        std::vector<std::vector<double>> & C){
            for(int i = 0 ; i < C.size() ; ++i){
                for(int j = 0 ; j < C.size() ; ++j){
                    for(int k = 0 ; k < B.size() ; ++k){
                        C[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
        }
void jki(std::vector<std::vector<double>> & A, std::vector<std::vector<double>> & B,
        std::vector<std::vector<double>> & C){
            for(int j = 0 ; j < C.size() ; ++j){
                for(int k = 0; k < B.size() ; ++k){
                    for(int i = 0; i < C[0].size() ; ++i){
                        C[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
        }
void ikj(std::vector<std::vector<double>> & A, std::vector<std::vector<double>> & B,
        std::vector<std::vector<double>> & C){
            for(int i = 0 ; i < C.size() ; ++i){
                for(int k = 0; k < B.size() ; ++k){
                    for(int j = 0; j < C[0].size() ; ++j){
                        C[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
        }
void ijk_tiling(std::vector<std::vector<double>> & A, std::vector<std::vector<double>> & B,
        std::vector<std::vector<double>> & C){
            int block = 64;
            for(int i = 0; i < C.size() ; i += block){
                for(int j = 0 ; j < C[0].size() ; j += block){
                    for(int i1 = i ; i1 < i + block ; ++i1){
                        for(int j1 = j ; j1 < j + block ; ++j1){
                            for(int k = 0 ; k < B.size() ; k += block){
                                for(int k1 = k ; k1 < k + block ; ++k1){
                                    C[i1][j1] += A[i1][k1] * B[k1][j1]; 
                                }
                            }
                        }
                    }
                }
            }
        }


int main(int argc, char ** argv){
    if(argc != 2){
        std::cout<<"Please use parameter:\nijk or jki or ikj or ijk_tiling."<<std::endl;
        return 1;
    }
    struct timespec start_time, end_time;

    int size = 1024;
    std::string param(argv[1]);
    std::vector<std::vector<double>> A(size, std::vector<double>(size, 1));
    std::vector<std::vector<double>> B(size, std::vector<double>(size, 1));
    std::vector<std::vector<double>> C(size, std::vector<double>(size, 1));

    clock_gettime(CLOCK_MONOTONIC, &start_time);
    if(param == "ijk"){
        ijk(A,B,C);
    }
    if(param == "jki"){
        jki(A,B,C);
    }
    if(param == "ikj"){
        ikj(A,B,C);
    }
    if(param == "ijk_tiling"){
        ijk_tiling(A,B,C);
    }
    clock_gettime(CLOCK_MONOTONIC, &end_time);
    
    double elapsed_ns = calc_time(start_time, end_time);

    //std::cout<<"The iteration type "<<param<<" "<<elapsed_ns/1000000000<<" ns.";
    printf("%s_Time = %f\n", param.c_str(), elapsed_ns/1000000000);
    return 0;
}