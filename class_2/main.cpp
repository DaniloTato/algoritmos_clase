#include "include/directorio.hpp"

bool recursive_find(directory &dir, std::string &path, std::string &target){
    for(auto i: dir.files){
        if(i.name == target){
            path += "/" + dir.name;
            return true;
        }
    }

    for(auto i: dir.subdirectory){
        std::string sub_dir_path = path + "/" + dir.name;
        if(recursive_find(i, sub_dir_path, target)){
            path = sub_dir_path;
            return true;
        }
    }

    return false;
}

void find_file(directory &file_structure, std::string &path, std::string &target){
    if (recursive_find(file_structure, path, target)){
        std::cout << "File found in: " << path << "\n";
    } else{
        std::cout << "File not found." << "\n";
    }
}

int main(){
    directory sistemaDeArchivos = {
    "root",
    {
            {"archivo1.txt"},
            {"archivo2.txt"}
    },
    {
            {
                "subdir1",
                {
                    {"archivo3.txt"},
                },
                {
                    {
                        "subdir2",
                        {
                            {"target.txt"},
                            {"archivo4.txt"}
                        },
                        {}
                    }
                }
            },
            {"archivo5.txt"}
    }
    };

    std::string target = "archivooboo.txt";
    std::string path = "";
    find_file(sistemaDeArchivos, path, target);
    return 0;


}
