#include <vector>
#include <string>
#include <map>
using namespace std;

#ifndef _ALLOC_
#define _ALLOC_

class Allocator{
    private:
        vector<bool> memory;
        // check here for availability
        // if we release memory we just remove from the table not from the memory.
        map<string, pair<int,int>> table; 
        int MAX_SIZE;
    public:
        Allocator(int max_size){
            this->MAX_SIZE = max_size;
            this->memory.resize(this->MAX_SIZE);
        }
        // Request for a contiguous block of memory
        // request takes o(limit - base)
        bool request(string processName, int base, int limit){
            if(limit >= this->MAX_SIZE || base < 0){
                return false;
            }
            // 1.check avaliablility
            // 2.if so, assign this piece of memory
            for(auto p: table){
                string PName = p.first;
                int PBase = p.second.first;
                int PLimit = p.second.second;

                if(PName == processName){
                    return false;
                }
                if((base >= PBase || base <= PBase) || (base >= PLimit || base <= PLimit)){
                    return false;
                }
            }

            for(int i = base; i <= limit; ++i){
                this->memory[i] = true;
            }

            return true;
        }
        // Release of a contiguous block of memory
        bool release(string processName){
            return table.erase(processName);
        }
        // Report the regions of free and allocated memory
        void rebort(){

        }
};

#endif
