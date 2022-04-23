//Nathaniel Wainwright
//Banker's Algorithm

#include <iostream>
#include <vector>
#include <fstream>


int main(){

    const int processes = 5;
    const int resources = 3;

//File Input

    std::ifstream in;
    in.open("input.txt");

    //Declairing Matirixes
    int alloc[processes][resources];
    int max[processes][resources];
    int avail[resources];

    //Data inserted into allocation matrix
    for (int i=0; i<processes; ++i){
        
        for(int j=0; j<resources; ++j){
            in>>alloc[i][j];
        }
    }

    //Data inserted into max matrix
    for (int i=0; i<processes; ++i){
        for(int j=0; j<resources; ++j){
            in>>max[i][j];
        }
    }
    
    //Data inserted into available resources matrix
    for(int i=0; i<resources; ++i){
        in>>avail[i];
    }

    in.close();

    int fin[processes],  seq[processes], index=0;

    //Setting fin values to 0
    for(int i=0; i<processes; ++i){
        fin[i]=0;
    }

    //Storing needed resources
    int need[processes][resources];
   
    for(int i=0; i<processes; ++i){
        
        for(int j=0; j<resources; ++j){
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    for(int p=0; p<processes; ++p){
        
        for(int i=0; i<processes; ++i){
           
            if(fin[i]==0){
                
                int mark = 0;

                //Check if requested resources are available
                for(int j=0; j<resources; ++j){
                    if(need[i][j] > avail[j]){
                        mark = 1;
                        break;
                    }
                }

                
                if(mark ==0){
                    seq[index++] = i;

                    for(int q=0; q<resources; ++q){
                        avail[q] += alloc[i][q];
                        fin[i] = 1;
                    }
                }

            }
        }
    }

    int mark = 1;

//Unsafe
    for(int i=0; i<resources; ++i){
        if(fin[i]==0){
            mark = 0;
            std::cout<< "Sequence is not safe";
            break;

        }
    }

//Safe
    if(mark==1){
        std::cout<< "The Sequence is safe" <<std::endl;

        for(int i=0; i<processes; ++i){
            std::cout<<" P"<<seq[i]<<"->";
        }
           
         std::cout<<" P"<<seq[processes -1]<<std::endl;

        
    }

    return(0);
}