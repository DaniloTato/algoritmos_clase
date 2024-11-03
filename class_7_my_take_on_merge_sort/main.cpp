#include <iostream>

int binary_search(std::vector<int> vec, int target){
    int low = 0;
    int high = vec.size() - 1;
    int mid = high;
    if (vec[0] == target) return 0;
    while (vec[mid] != target){
        mid = (high + low) * 0.5;
        if (mid == low) return -1;
        vec[mid] <= target ? low = mid : high = mid;
    }
    return mid;

}

struct chunk{
    std::vector<int> contents;
    chunk* merge_with(chunk other_chunk){

        int point_1 = 0;
        int point_2 = 0;
        std::vector<int> new_contents;
        while (point_1 < contents.size() && point_2 < other_chunk.contents.size()){
            if (contents[point_1] < other_chunk.contents[point_2]){
                new_contents.push_back(contents[point_1]);
                point_1++;
            }else{
                new_contents.push_back(other_chunk.contents[point_2]);
                point_2++;
            }
        }

        int diff_1 = contents.size() - point_1;
        while(diff_1){
            new_contents.push_back(contents[contents.size() - diff_1]);
            diff_1--;
        }
        int diff_2 = other_chunk.contents.size() - point_2;
        while(diff_2){
            new_contents.push_back(other_chunk.contents[other_chunk.contents.size() - diff_2]);
            diff_2--;
        }

        chunk* new_chunk = new chunk;
        new_chunk -> contents = new_contents;
        return new_chunk;
    }
};

std::vector<chunk*> merger(std::vector<chunk*> vector_of_chunks){
    std::vector<chunk*> new_vector_of_chunks;
    for(int i = 0; i < floor(vector_of_chunks.size()/2); i++){
        chunk* new_chunk = vector_of_chunks[i*2]->merge_with(*vector_of_chunks[i*2+1]);
        new_vector_of_chunks.push_back(new_chunk);
    }

    if(vector_of_chunks.size() % 2 == 1){
        new_vector_of_chunks.push_back(vector_of_chunks.back());
    }

    if(new_vector_of_chunks.size() == 1){
        return new_vector_of_chunks;
    } else return merger(new_vector_of_chunks);
}

//fun but pointless merge sort using object logic
void sort(std::vector<int> &vec){
    std::vector<chunk*> vector_of_chunks;
    for(int i = 0; i < vec.size(); i++){
        vector_of_chunks.push_back(new chunk);
        vector_of_chunks[i] -> contents = {vec[i]};
    }

    std::vector<int> new_vec = merger(vector_of_chunks)[0]->contents;

    for(auto i : new_vec){
        std::cout << i << "\n";
    }
}

int main(){
    std::vector<int> a = {1,7,3,5,4,7,8};
    sort(a);

    return 0;
}