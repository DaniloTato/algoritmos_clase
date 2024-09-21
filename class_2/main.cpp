#include "include/directorio.hpp"

bool recursive_find(directory &dir, std::string &path, std::string &target){
    for(auto i: dir.commands){
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

command access(std::string path, directory base){

    while(path.front() == ' '){
        path.erase(path.begin());
    }

    std::string subdir_to_search;
    int num_of_spaces = 0;
    for (int i = 0; i < path.size(); i++){
        char ch = path[i];
        if (ch == ' '){
            while(path[i + num_of_spaces] == ' '){
                num_of_spaces++;
            }
            break;
        } else{
            subdir_to_search += ch;
        }
    }

    int n_crop = subdir_to_search.size() + num_of_spaces;

    if (n_crop >= 0 && n_crop<= path.length()) {
        path.erase(0, n_crop);
    }

    std::vector<directory> sub_dirs = base.subdirectory;
    for (auto i:sub_dirs){
        if(i.name == subdir_to_search){
            if (path == "" || path == subdir_to_search) return i.commands[0];
            else return access(path, i);
        }
    }

    command not_found;
    not_found.name = "not_found.cmm";
    return not_found;
}

int main(){
        directory _console_commands = {
        "root",
        {
            {"root.txt"}
        },
        {
            {
                "rpg",
                {
                    {"rpg.cmm"}
                },
                {
                    {
                        "fight",
                        {
                            {"normal_fight.cmm"}
                        },
                        {
                            {   "sub3",
                                {
                                    {"sub"},
                                }
                            }
                        }
                    }
                }
            },

            {
                "mag_os",
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
            }
        }
    };

    // std::string target = "lolol.txt";
    // std::string path = "";
    // find_file(sistemaDeArchivos, path, target);
    std::cout << access("rpg", _console_commands).name << "\n";
    return 0;


}
