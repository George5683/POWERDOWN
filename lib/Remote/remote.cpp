#include "remote.hpp"

remote::remote(std::string brandname) : Brand(brandname) {
    // Constructor 
}

remote::~remote() {
    // Destructor 
}

std::string remote::getBrand() const {
    return Brand;
}

Samsung::Samsung() : remote("Samsung") {
    
}

Samsung::~Samsung() {
    // Destructor implementation
}

LG::LG() : remote("LG") {
    // Constructor
}

LG::~LG() {
    // Destructor implementation
}
