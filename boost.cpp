#include <iostream>
#include <string>
#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>

class Feldolgoz {
    
private:
    std::string _path;
    int _count = 0;
    
public:
    Feldolgoz(std::string filePath):_path(filePath) {}
    
    void travel(boost::filesystem::path path) {
        boost::filesystem::directory_iterator it{path}, eod;
        BOOST_FOREACH(boost::filesystem::path const& p, std::make_pair(it, eod)) {
            if (boost::filesystem::is_regular_file(p) && boost::filesystem::extension(p.string()) == ".java") {
                std::cout << p << std::endl;
                _count++;
            }
            else if(boost::filesystem::is_directory(p)) travel(p);
        }
    }
    
    std::string getPath() {
        return _path;
    }
    
    int getCount() {
        return _count;
    }
    
};

void usage(){
    std::cout << "./boost <mappa>\n";
}

int main(int argc, char** argv){
    if (argc < 2) {
        usage();
        return -1;
    }

    Feldolgoz* obj = new Feldolgoz (argv[1]);
    obj->travel(obj->getPath());
    std::cout << obj->getCount() << std::endl;
}

