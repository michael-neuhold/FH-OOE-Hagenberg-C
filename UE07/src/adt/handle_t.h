//
// Created by Michael Neuhold on 01.12.19.
//

#ifndef ADT_HANDLE_T_H
#define ADT_HANDLE_T_H


class handle_t {

public:
    handle_t(int index);
    int getIdentifier() const;

private:
    int identifier{0};

};


#endif //ADT_HANDLE_T_H
