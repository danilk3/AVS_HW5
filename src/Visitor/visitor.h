//
// Created by dahil on 16.12.2021.
//

#ifndef AVS_HW5_VISITOR_H
#define AVS_HW5_VISITOR_H

#include <mutex>

class Visitor {
private:
    // id of visitor.
    int id;
    // number of viewed pictures of the person.
    int number_of_viewed_pictures;

public:
    explicit Visitor(int);

    void viewPicture();

    std::string display();
};

#endif //AVS_HW5_VISITOR_H
